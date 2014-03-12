#!/usr/bin/env python
import CMGTools.TTHAnalysis.treeReAnalyzer as tRA
from CMGTools.RootTools.utils.DeltaR import deltaPhi, deltaR
from glob import glob
import os.path
import os, ROOT
from math import ceil

class THqLDProducer(tRA.Module):
    def __init__(self,name,booker,wfile):
        tRA.Module.__init__(self, name, booker)
        self.wfile = wfile
    def endJob(self):
        self.inputfile.Close()

    def beginJob(self):
        ## List of variables used in discriminator
        # self.varlist = ['charge', 'deltaPhill', 'fwdJetEtaGap', 'maxEtaJet25','nBJetMedium25','nJet25Eta2'] ## Dec2
        self.varlist = ['charge', 'deltaPhill', 'fwdJetEtaGap', 'maxEtaJet25','nBJetMedium25', 'htJet25']
        # self.varlist = ['charge', 'deltaPhill', 'maxEtaJet25','nBJetMedium25']

        ## Can modify exact way they are evaluated here:
        self.evalvar_dict = {'charge':'LepGood1_charge', 'deltaPhill':'abs(deltaPhill)', 'deltaPhiTopH':'abs(deltaPhiTopH)'}

        ## Open LD weights file here
        ## Should contain two histograms: background shape, signal shape
        self.sig_hists = {}
        self.bg_hists  = {}
        self.inputfile = ROOT.TFile(self.wfile, 'READ')
        for var in self.varlist:
            self.sig_hists[var] = self.inputfile.Get(var+"_signal")
            self.bg_hists[var]  = self.inputfile.Get(var+"_background")

        self.t = tRA.PyTree(self.book("TTree","t","t"))
        self.t.branch("ld","F")

    def selectEvent(self, event):
        selection = ""

        ## mumu:
        selection += "("
        selection += "   (abs(LepGood1_pdgId) == 13 && abs(LepGood2_pdgId) == 13)"

        selection += "||"

        ## emu:
        selection += "(  (abs(LepGood1_pdgId) != abs(LepGood2_pdgId) ) && ( abs(LepGood1_pdgId) == 13 || (LepGood1_convVeto > 0 && LepGood1_innerHits == 0) ) && ( abs(LepGood2_pdgId) == 13 || (LepGood2_convVeto > 0 && LepGood2_innerHits == 0) )  )"

        selection += "||"

        ## ee:
        selection += "(  abs(LepGood1_pdgId) == 11 && abs(LepGood2_pdgId) == 11 && LepGood1_innerHits == 0 && LepGood2_innerHits == 0 && LepGood1_convVeto>0 && LepGood2_convVeto>0  )"
        selection += "   )   "

        ## Veto third lepton
        selection += "&& (nLepGood == 2 || LepGood3_mva < 0.35)"
        ## 20/20 selection
        selection += "&& (LepGood1_pt>20 && LepGood2_pt>20)"
        ## same-sign charge ## need to remove this (at least for E/E, E/Mu data samples) to have charge misid estimates
        # selection += "&& (LepGood1_charge*LepGood2_charge > 0)"
        ## low mass veto
        selection += "&& (minMllAFAS > 12)"
        ## lepton mva cut: ## need to remove this cut to have fake rate estimates for LD
        # selection += "&& (min(LepGood1_mva,LepGood2_mva) > 0.7)"
        ## tight-charge:
        selection += "&& (LepGood1_tightCharge && LepGood2_tightCharge)"

        #### Dec 2 selection (2 j, 1 fwdj):
        # ## 2 jets:
        # selection += "&& (nJet25>1)"
        # # 1 jet with eta>1 :
        # selection += "&& (nJet25Eta1>0)"

        #### Jan 21 selection (1 ctrl j, 1 fwd j, 1 loose b)
        ## 2 jets:
        selection += "&& (nJet25Ctrl>0)"
        # 1 jet with eta>1 :
        selection += "&& (nJet25Eta1>0)"
        # > 0b :
        selection += "&&(nBJetLoose25>0)"
        return event.eval(selection)>0

    def analyze(self,event):
        ld = -1.0
        ## Apply event selection first:
        if self.selectEvent(event):

            ## Evaluate the normalized value of this event for each variable for signal and background
            ld_sig, ld_bg = 1.0, 1.0
            # vars_to_print = []
            for var in self.varlist:
                try:
                    evalvar = self.evalvar_dict[var]
                except KeyError:
                    evalvar = var
                varvalue = event.eval(evalvar)
                # vars_to_print.append((var, varvalue))
                sig_hist = self.sig_hists[var]
                ld_sig *= sig_hist.GetBinContent(sig_hist.FindBin(varvalue))

                # if sig_hist.GetBinContent(sig_hist.FindBin(varvalue)) < 0.01:
                #     print var, varvalue

                bg_hist = self.bg_hists[var]
                ld_bg *= bg_hist.GetBinContent(bg_hist.FindBin(varvalue))

            ld = ld_sig / (ld_sig+ld_bg) if (ld_sig+ld_bg)>0 else 0.

            # if ld > -0.5 and ld < 0.2:
            #     print '-----', ld
            #     for name,value in vars_to_print: print name, value

        setattr(self.t, "ld", ld)
        self.t.fill()

import os, itertools, optparse
from sys import argv
usage = "%prog [options] treedir outputdir"
parser = optparse.OptionParser(usage)
parser.add_option('-t', '--onlyTag',     dest='onlyTag',     help='Process only samples matching this tag', default='', type='string')
parser.add_option('-w', '--weightsFile', dest='weightFile',  help='File with LD weights', default='', type='string')
parser.add_option("-F", "--add-friend",  dest="friendTrees", action="append", default=[], nargs=2, help="Add a friend tree (treename, filename). Can use {name}, {cname} patterns in the treename")
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
        infile = opt.weightFile
        entries = t.GetEntries()
        f.Close()

        print "  ",os.path.basename(D)," single chunk"
        jobs.append((short,fname,infile,outdir+"THqLD_%s.root" % short,xrange(entries)))

        # chunk = 1000000.
        # if entries < chunk:
        #     print "  ",os.path.basename(D)," single chunk"
        #     jobs.append((short,fname,infile,outdir+"THqLD_%s.root" % short,xrange(entries)))
        # else:
        #     nchunk = int(ceil(entries/chunk))
        #     print "  ",os.path.basename(D)," %d chunks" % nchunk
        #     for i in xrange(nchunk):
        #         r = xrange(int(i*chunk),min(int((i+1)*chunk),entries))
        #         jobs.append((short+"_chunk%d" % i, fname,infile,outdir+"THqLD_%s.chunk%d.root" % (short,i),r))

print "\n"
print "I have %d taks to process" % len(jobs)
print "Output directory is:", outdir

maintimer = ROOT.TStopwatch()
## Single callable for each job
def _runIt(args):
    (name,fin,wfile,fout,evrange) = args
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
    el = tRA.EventLoop([ THqLDProducer("THqLD",booker,wfile), ])
    el.loop([tb], eventRange=evrange, reportEvery=10000)
    booker.done()
    fb.Close()
    time = timer.RealTime()
    print "=== %s done (%d entries, %.0f s, %.0f e/s) ====" % ( name, nev, time,(nev/time) )
    return (name,(nev,time))

from multiprocessing import Pool
pool = Pool(8)
ret  = dict(pool.map(_runIt, jobs))
fulltime = maintimer.RealTime()
totev   = sum([ev   for (ev,time) in ret.itervalues()])
tottime = sum([time for (ev,time) in ret.itervalues()])
print "Done %d tasks in %.1f min (%d entries, %.1f min)" % (len(jobs),fulltime/60.,totev,tottime/60.)

