#!/usr/bin/env python
import os
import ROOT
import CMGTools.TTHAnalysis.treeReAnalyzer as tRA

from trainTHqMVA import VARIABLES, eventSelectionString
from glob import glob
from array import array

## Methods from the TMVA weights to be stored
METHODS = ['BDTG', 'LD']

## Variables for the simple linear likelihood discriminant (non TMVA)
LDVARS = ['nJet25', 'etaFwdJet25','fwdJetEtaGap', 'htJet25',
          'nBJetMedium25', 'deltaPhill', 'lep2pt', 'charge']
# LDVARS = ['charge', 'deltaPhill', 'fwdJetEtaGap', 'maxEtaJet25',
#           'nBJetMedium25', 'nJet25Eta2']

## Can modify exact way they are evaluated here:
LDVAR_DICT = {'charge':'LepGood1_charge', 'deltaPhill':'abs(deltaPhill)',
              'deltaPhiTopH':'abs(deltaPhiTopH)',
              'lep2pt':'LepGood2_pt'}

class THqMVAVar:
    def __init__(self,name,func):
        self.name = name
        self.var  = array('f',[0.])
        self.func = func
    def set(self,event):
        self.var[0] = self.func(event)

class THqMVAProducer(tRA.Module):
    def __init__(self,name,booker,wdir,wfile):
        tRA.Module.__init__(self, name, booker)
        self.wfile = wfile
        self.wdir = wdir
        self.vars = []

    def addTHqVariables(self):
        for name, (formula, func, _) in VARIABLES:
            mvavar = THqMVAVar(formula, func)
            self.vars.append(mvavar)
        for mvavar in self.vars:
            self.tmvaReader.AddVariable(mvavar.name, mvavar.var)

    def endJob(self):
        self.ld_inputfile.Close()

    def beginJob(self):
        ## TMVA Reader
        self.tmvaReader = ROOT.TMVA.Reader("Silent")
        self.addTHqVariables()
        self.tmvaReader.SetVerbose(True)

        ## Open simple LD weights file here
        ## Should contain two histograms: background shape, signal shape
        self.ld_sig_hists = {}
        self.ld_bg_hists  = {}
        self.ld_inputfile = ROOT.TFile(self.wfile, 'READ')
        for var in LDVARS:
            self.ld_sig_hists[var] = self.ld_inputfile.Get(var+"_signal")
            self.ld_bg_hists[var]  = self.ld_inputfile.Get(var+"_background")
            try:
                _ = self.ld_sig_hists[var].GetName()
                _ = self.ld_bg_hists[var].GetName()
            except ReferenceError:
                print "Failed to read histos for", var, "from", self.wfile
                exit(-1)

        self.t = tRA.PyTree(self.book("TTree","t","t"))
        self.t.branch("THq_SimpleLH","F")
        for meth in METHODS:
            self.tmvaReader.BookMVA(meth, os.path.join(self.wdir,
                    "TMVAClassification_%s.weights.xml"%meth))
            self.t.branch("THq_%s"%meth,"F")

    def selectEvent(self, event):
        selection = eventSelectionString(includeSidebands=True)
        return event.eval(selection)>0

    def analyze(self,event):
        vars = {}
        for meth in METHODS: vars[meth] = -10.
        vars['SimpleLH'] = -10.

        ## Apply event selection first:
        if self.selectEvent(event):
            ## Evaluate MVA from TMVA weights:
            for mvavar in self.vars:
                mvavar.set(event)
            for meth in METHODS:
                vars[meth] = self.tmvaReader.EvaluateMVA(meth)

            ## Calculate simple LD
            ld_sig, ld_bg = 1.0, 1.0
            for var in LDVARS:
                try:
                    evalvar = LDVAR_DICT[var]
                except KeyError:
                    evalvar = var
                varvalue = event.eval(evalvar)
                sig_hist = self.ld_sig_hists[var]
                ld_sig *= sig_hist.GetBinContent(sig_hist.FindBin(varvalue))

                bg_hist = self.ld_bg_hists[var]
                ld_bg *= bg_hist.GetBinContent(bg_hist.FindBin(varvalue))

            if (ld_sig+ld_bg)>0:
                vars['SimpleLH'] = ld_sig/(ld_sig+ld_bg)
            else:
                vars['SimpleLH'] = 0.

        for meth in METHODS:
            setattr(self.t, "THq_%s"%meth, vars[meth])

        setattr(self.t, "THq_SimpleLH", vars['SimpleLH'])
        self.t.fill()

import os, itertools, optparse
from sys import argv
usage = "%prog [options] treedir outputdir"
parser = optparse.OptionParser(usage)
parser.add_option('-t', '--onlyTag', dest='onlyTag',
                  default='', type='string',
                  help='Process only samples matching this tag')
parser.add_option('-w', '--weightsDir', dest='weightsDir',
                  default='weights/', type='string',
                  help='Directory with MVA weight files')
parser.add_option('-f', '--ldHistoFile', dest='ldHistoFile',
                  default='THQLD_weights.root', type='string',
                  help='File with simple likelihood pdf histos')
parser.add_option('-n', '--nEvsPerChunk', dest='nEvsPerChunk',
                  default=500000, type='int',
                  help='Number of events per chunk')
parser.add_option("-F", "--add-friend", dest="friendTrees",
                  action="append", default=[], nargs=2,
                  help="Add a friend tree (treename, filename). Can use\
                  {name}, {cname} patterns in the treename")
(opt, args) = parser.parse_args()
if len(args) < 1:
    parser.print_help()

## OUTPUT
outdir = args[1]
if not outdir.endswith('/'): outdir += '/'
if not os.path.exists(outdir): os.mkdir(outdir)

## Prepare jobs:
jobs = []
for D in glob(args[0]+"/*"):
    if len(opt.onlyTag) > 0 and not opt.onlyTag in D: continue
    fname = D+"/ttHLepTreeProducerBase/ttHLepTreeProducerBase_tree.root"
    if os.path.exists(fname):
        short = os.path.basename(D)
        f = ROOT.TFile.Open(fname);
        t = f.Get("ttHLepTreeProducerBase")
        wdir = opt.weightsDir
        wfile = opt.ldHistoFile
        entries = t.GetEntries()
        f.Close()

        # print "  ",os.path.basename(D)," single chunk"
        # jobs.append((short,fname,wdir,
        #              outdir+"THqMVA_%s.root" % short,xrange(entries)))

        chunk = opt.nEvsPerChunk
        if entries < chunk:
            print "  ",os.path.basename(D)," single chunk"
            jobs.append((short,fname,wdir,wfile,
                      outdir+"THqMVA_%s.root" % short,xrange(entries)))
        else:
            nchunk = (entries//chunk)+1

            print "  ",os.path.basename(D)," %d chunks" % nchunk
            for i in xrange(nchunk):
                r = xrange(int(i*chunk),min(int((i+1)*chunk),entries))
                jobs.append((short+"_chunk%d" % i, fname,wdir,wfile,
                      outdir+"THqMVA_%s.chunk%d.root" % (short,i),r))

print "\n"
print "I have %d tasks to process" % len(jobs)
print "Output directory is:", outdir

maintimer = ROOT.TStopwatch()

## Single callable for each job
def _runIt(args):
    (name,fin,wdir,wfile,fout,evrange) = args
    timer = ROOT.TStopwatch()
    fb = ROOT.TFile(fin)
    tb = fb.Get("ttHLepTreeProducerBase")

    for tf_tree, tf_file in opt.friendTrees:
        print 'Adding friend', tf_tree, 'from', tf_file
        tag = name.split('_chunk')[0]
        tb.AddFriend(tf_tree, tf_file.format(name=tag, cname=tag)),

    nev = tb.GetEntries()
    print "==== %s starting (%d entries) ====" % (name, nev)
    booker = tRA.Booker(fout)
    el = tRA.EventLoop([ THqMVAProducer("THqMVA",booker,wdir,wfile), ])
    el.loop([tb], eventRange=evrange, reportEvery=10000)
    booker.done()
    fb.Close()
    time = timer.RealTime()
    print "=== %s done (%d entries, %.0f s, %.0f e/s) ====" % ( name,
                                           nev, time,(nev/time) )
    return (name,(nev,time))

from multiprocessing import Pool
pool = Pool(8)
ret  = dict(pool.map(_runIt, jobs))
fulltime = maintimer.RealTime()
totev   = sum([ev   for (ev,time) in ret.itervalues()])
tottime = sum([time for (ev,time) in ret.itervalues()])
print "Done %d tasks in %.1f min (%d entries, %.1f min)" % (len(jobs),
                                            fulltime/60.,totev,tottime/60.)


## For debugging:
# for (name,fin,wfile,fout,evrange) in jobs:
#     fb = ROOT.TFile(fin)
#     tb = fb.Get("ttHLepTreeProducerBase")

#     # friendOpts = opt.friendTrees[:]
#     for tf_tree, tf_file in opt.friendTrees:
#         print 'Adding friend', tf_tree, 'from', tf_file
#         tb.AddFriend(tf_tree, tf_file.format(name=name, cname=name)),

#     # print tb.GetName()

#     nev = tb.GetEntries()
#     print "==== %s starting (%d entries) ====" % (name, nev)
#     booker = tRA.Booker(fout)
#     el = tRA.EventLoop([ THqMVAProducer("THqMVA",booker,wfile), ])
#     el.loop([tb], eventRange=evrange, reportEvery=10000)
#     booker.done()
#     fb.Close()
