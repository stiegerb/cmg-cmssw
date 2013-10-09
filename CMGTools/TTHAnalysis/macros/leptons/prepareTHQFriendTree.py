#!/usr/bin/env python
import CMGTools.TTHAnalysis.treeReAnalyzer as tRA
from CMGTools.RootTools.utils.DeltaR import deltaPhi
from glob import glob
import os.path
import os, ROOT
from math import ceil

class THqTreeProducer(tRA.Module):
    def __init__(self,name,booker):
        tRA.Module.__init__(self,name,booker)
    def beginJob(self):
        self.t = tRA.PyTree(self.book("TTree","t","t"))
        self.t.branch("maxEtaJet25","F")
        self.t.branch("nJet25Eta1","I")
        self.t.branch("nJet25Eta2","I")
        self.t.branch("deltaPhill","F")     ## delta phi between the first two leptons
        self.t.branch("fwdJetEtaGap","F")   ## delta eta between most fwd jet and next object (lepton/jet)
        # self.t.branch("dEtaFwdJetb","F")  ## delta eta between most fwd jet and b jet
        self.t.branch("dEtaFwdJetLep1","F") ## delta eta between most fwd jet and lepton 1
        self.t.branch("dEtaFwdJetLep2","F") ## delta eta between most fwd jet and lepton 2

    def analyze(self,event):
        leps  = tRA.Collection(event,"LepGood","nLepGood",8)
        jets  = tRA.Collection(event,"Jet","nJet25",8)
        fjets = tRA.Collection(event,"FwdJet","nJet25Fwd",8)



        ## find the most forward jet
        maxeta25 = 0
        njet25eta1 = 0
        njet25eta2 = 0
        fwdJet = None
        for j in fjets:
            if j.pt > 25:
                if abs(j.eta) > 1.0: njet25eta1 += 1
                if abs(j.eta) > 2.0: njet25eta2 += 1
                if abs(j.eta) > maxeta25:
                    maxeta25 = abs(j.eta)
                    fwdJet = j

        for j in jets:
            if j.pt > 25:
                if abs(j.eta) > 1.0: njet25eta1 += 1
                if abs(j.eta) > 2.0: njet25eta2 += 1
                if abs(j.eta) > maxeta25:
                    maxeta25 = abs(j.eta)
                    fwdJet = j

        etagap = 20
        gaplep1 = 20
        gaplep2 = 20
        if fwdJet is not None:
            for o in fjets:
                gap = abs(fwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap
            for o in jets:
                gap = abs(fwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap
            for o in leps:
                gap = abs(fwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap

            if len(leps) > 0:
                gaplep1 = abs(fwdJet.eta - leps[0].eta)

            if len(leps) > 1:
                gaplep2 = abs(fwdJet.eta - leps[1].eta)

        deltaPhill = -10.
        if len(leps) > 1:
            deltaPhill = deltaPhi(leps[0].phi, leps[1].phi)

        setattr(self.t, "maxEtaJet25",    maxeta25)
        setattr(self.t, "nJet25Eta1",     njet25eta1)
        setattr(self.t, "nJet25Eta2",     njet25eta2)
        setattr(self.t, "deltaPhill",     deltaPhill)
        setattr(self.t, "fwdJetEtaGap",   etagap)
        setattr(self.t, "dEtaFwdJetLep1", gaplep1)
        setattr(self.t, "dEtaFwdJetLep2", gaplep2)

        self.t.fill()

import os, itertools
from sys import argv
if len(argv) < 2: print "Usage: %s <TREE_DIR>" % argv[0]
jobs = []

## OUTPUT
outdir = argv[2]
if not outdir.endswith('/'): outdir += '/'
if not os.path.exists(outdir): os.mkdir(outdir)

for D in glob(argv[1]+"/*"):
    fname = D+"/ttHLepTreeProducerBase/ttHLepTreeProducerBase_tree.root"
    if os.path.exists(fname):
        short = os.path.basename(D)
        f = ROOT.TFile.Open(fname);
        t = f.Get("ttHLepTreeProducerBase")
        entries = t.GetEntries()
        f.Close()
        chunk = 500000.
        if entries < chunk:
            print "  ",os.path.basename(D)," single chunk"
            jobs.append((short,fname,outdir+"THqFriend_%s.root" % short,xrange(entries)))
        else:
            nchunk = int(ceil(entries/chunk))
            print "  ",os.path.basename(D)," %d chunks" % nchunk
            for i in xrange(nchunk):
                r = xrange(int(i*chunk),min(int((i+1)*chunk),entries))
                jobs.append((short+"_chunk%d" % i, fname, outdir+"THqFriend_%s.chunk%d.root" % (short,i),r))
print "\n"
print "I have %d taks to process" % len(jobs)
print "Output directory is:", outdir

maintimer = ROOT.TStopwatch()
def _runIt(args):
    (name,fin,fout,evrange) = args
    timer = ROOT.TStopwatch()
    fb = ROOT.TFile(fin)
    tb = fb.Get("ttHLepTreeProducerBase")
    nev = tb.GetEntries()
    print "==== %s starting (%d entries) ====" % (name, nev)
    booker = tRA.Booker(fout)
    el = tRA.EventLoop([ THqTreeProducer("THq",booker,), ])
    el.loop([tb], eventRange=evrange)
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

