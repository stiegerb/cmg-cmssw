#!/usr/bin/env python
import os
import ROOT
import CMGTools.TTHAnalysis.treeReAnalyzer as tRA

from trainTHqMVA import VARIABLES, eventSelectionString
from glob import glob
# from math import ceil
from array import array

METHODS = ['BDTG', 'LD']

class THqMVAVar:
    def __init__(self,name,func):
        self.name = name
        self.var  = array('f',[0.])
        self.func = func
    def set(self,event):
        self.var[0] = self.func(event)

class THqMVAProducer(tRA.Module):
    def __init__(self,name,booker,wdir):
        tRA.Module.__init__(self, name, booker)
        self.wdir = wdir
        self.vars = []

    def addTHqVariables(self):
        for name, (formula, func, _) in VARIABLES:
            mvavar = THqMVAVar(formula, func)
            self.vars.append(mvavar)
        for mvavar in self.vars:
            self.tmvaReader.AddVariable(mvavar.name, mvavar.var)

    def endJob(self):
        pass
        # self.inputfile.Close()

    def beginJob(self):
        self.tmvaReader = ROOT.TMVA.Reader("Silent")
        self.addTHqVariables()
        self.tmvaReader.SetVerbose(True)

        self.t = tRA.PyTree(self.book("TTree","t","t"))
        for meth in METHODS:
            self.tmvaReader.BookMVA(meth, os.path.join(self.wdir,
                    "TMVAClassification_%s.weights.xml"%meth))
            self.t.branch("THq_%s"%meth,"F")

    def selectEvent(self, event):
        selection = eventSelectionString()
        return event.eval(selection)>0

    def analyze(self,event):
        vars = {}
        for meth in METHODS: vars[meth] = -10.

        ## Apply event selection first:
        if self.selectEvent(event):
            # print '---------------------'
            for mvavar in self.vars:
                mvavar.set(event)
                # print mvavar.name, mvavar.var[0]
            for meth in METHODS:
                vars[meth] = self.tmvaReader.EvaluateMVA(meth)

        for meth in METHODS:
            setattr(self.t, "THq_%s"%meth, vars[meth])
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
        entries = t.GetEntries()
        f.Close()

        print "  ",os.path.basename(D)," single chunk"
        jobs.append((short,fname,wdir,
                     outdir+"THqMVA_%s.root" % short,xrange(entries)))

        # chunk = 10000.
        # if entries < chunk:
        #     print "  ",os.path.basename(D)," single chunk"
        #     jobs.append((short,fname,wdir,
        #               outdir+"THqLD_%s.root" % short,xrange(entries)))
        # else:
        #     nchunk = int(ceil(entries/chunk))
        #     print "  ",os.path.basename(D)," %d chunks" % nchunk
        #     for i in xrange(nchunk):
        #         r = xrange(int(i*chunk),min(int((i+1)*chunk),entries))
        #         jobs.append((short+"_chunk%d" % i, fname,wdir,
        #               outdir+"THqLD_%s.chunk%d.root" % (short,i),r))

print "\n"
print "I have %d taks to process" % len(jobs)
print "Output directory is:", outdir

maintimer = ROOT.TStopwatch()
## Single callable for each job
def _runIt(args):
    (name,fin,wdir,fout,evrange) = args
    timer = ROOT.TStopwatch()
    fb = ROOT.TFile(fin)
    tb = fb.Get("ttHLepTreeProducerBase")

    # friendOpts = opt.friendTrees[:]
    for tf_tree, tf_file in opt.friendTrees:
        print 'Adding friend', tf_tree, 'from', tf_file
        tb.AddFriend(tf_tree, tf_file.format(name=name, cname=name)),

    # print tb.GetName()

    nev = tb.GetEntries()
    print "==== %s starting (%d entries) ====" % (name, nev)
    booker = tRA.Booker(fout)
    el = tRA.EventLoop([ THqMVAProducer("THqMVA",booker,wdir), ])
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
