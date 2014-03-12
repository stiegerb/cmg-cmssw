#!/usr/bin/env python
import CMGTools.TTHAnalysis.treeReAnalyzer as tRA
from CMGTools.RootTools.utils.DeltaR import deltaPhi, deltaR
from glob import glob
import os.path
import os, ROOT
from math import ceil
from operator import attrgetter

BTAGWPL = 0.244
BTAGWPM = 0.679
BTAGWPT = 0.898

BTAGWP = BTAGWPL

class THqTreeProducer(tRA.Module):
    def __init__(self,name,booker):
        tRA.Module.__init__(self,name,booker)
    def beginJob(self):
        self.t = tRA.PyTree(self.book("TTree","t","t"))
        self.t.branch("nJet25Ctrl","I")  ## njets with eta < 1
        self.t.branch("nJet25Eta1","I")  ## njets with eta > 1
        self.t.branch("nJet25Eta2","I")  ## njets with eta > 2
        self.t.branch("maxEtaJet25","F") ## maximum eta of any jet with pt > 25
        self.t.branch("etaFwdJet25","F") ## eta of hardest jet with eta > 1
        self.t.branch("deltaPhill","F")     ## delta phi between the first two leptons
        self.t.branch("deltaPhiTopH","F")   ## delta phi between the b-jet+closest lepton and other lepton + two non-bjets (i.e. between visible higgs and top decay prods)
        self.t.branch("fwdJetEtaGap","F")   ## delta eta between most fwd jet and next object (lepton/jet)
        self.t.branch("dEtaFwdJetb","F")    ## delta eta between most fwd jet and b jet
        self.t.branch("dPhiFwdJetb","F")    ## delta phi between most fwd jet and b jet
        self.t.branch("dEtaFwdJetLep1","F") ## delta eta between most fwd jet and lepton 1
        self.t.branch("dEtaFwdJetLep2","F") ## delta eta between most fwd jet and lepton 2

    def analyze(self,event):
        leps  = tRA.Collection(event,"LepGood","nLepGood",8)
        jets  = tRA.Collection(event,"Jet","nJet25",8)
        fjets = tRA.Collection(event,"FwdJet","nJet25Fwd",8)
        bjets = [j for j in jets if j.btagCSV > BTAGWP]
        bjets.sort(key=attrgetter('pt'), reverse=True)

        ## All jets with |eta| > 1 and not b-tagged
        fwdjets = [j for j in jets if (
                                abs(j.eta) > 1.0 and
                                j.pt > 25. and
                                j.btagCSV < BTAGWP)] \
                + [j for j in fjets if (
                                j.pt > 25. and
                                j.btagCSV < BTAGWP)]
        fwdjets.sort(key=attrgetter('pt'), reverse=True)

        njet25eta1 = len(fwdjets)
        hardestfwdJet = fwdjets[0] if len(fwdjets)>0 else None
        maxeta25eta1 = abs(hardestfwdJet.eta) if hardestfwdJet is not None else -1.

        njet25ctrl = len([j for j in jets    if abs(j.eta) < 1.0 and j.pt > 25.])
        njet25eta2 = len([j for j in fwdjets if abs(j.eta) > 2.0 and j.pt > 25.])

        mostfwdJet = sorted(fwdjets, key=lambda x:abs(x.eta), reverse=True)[0] if len(fwdjets) > 0 else None
        maxeta25 = abs(mostfwdJet.eta) if mostfwdJet is not None else -1.

        etagap, gaplep1, gaplep2, gapb = 20, 20, 20, 20
        dphib = -10.
        if mostfwdJet is not None:
            for o in fjets:
                gap = abs(mostfwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap
            for o in jets:
                gap = abs(mostfwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap
            for o in leps:
                gap = abs(mostfwdJet.eta - o.eta)
                if gap>0 and gap<etagap: etagap = gap

            if len(bjets) > 0:
                gapb  = abs(mostfwdJet.eta - bjets[0].eta)
                dphib = deltaPhi(mostfwdJet.phi, bjets[0].phi)

            if len(leps) > 0:
                gaplep1 = abs(mostfwdJet.eta - leps[0].eta)

            if len(leps) > 1:
                gaplep2 = abs(mostfwdJet.eta - leps[1].eta)

        deltaPhill   = -10.
        deltaPhiTopH = -10.
        if len(leps) > 1:
            deltaPhill = deltaPhi(leps[0].phi, leps[1].phi)

            nonbjets = [j for j in jets if not j.btagCSV > BTAGWP]
            if len(bjets) > 0 and len(nonbjets) > 1: ## need two leptons, one bjet and two non-bjets for this
                ## Take the phi to be the one of the b-jet and the lepton closest in deltaR
                phibl = (leps[0].p4()+bjets[0].p4()).Phi()
                otherlepindex = 1
                if deltaR(leps[1].eta, leps[1].phi, bjets[0].eta, bjets[0].phi) < deltaR(leps[0].eta, leps[0].phi, bjets[0].eta, bjets[0].phi):
                    phibl = (leps[1].p4()+bjets[0].p4()).Phi()
                    otherlepindex = 0

                # philqq = (leps[otherlepindex].p4()+nonbjets[0].p4()).Phi()
                philqq = (leps[otherlepindex].p4()+nonbjets[0].p4()+nonbjets[1].p4()).Phi()
                deltaPhiTopH = deltaPhi(phibl, philqq)

        setattr(self.t, "maxEtaJet25",    maxeta25)
        setattr(self.t, "etaFwdJet25",    maxeta25eta1)
        setattr(self.t, "nJet25Ctrl",     njet25ctrl)
        setattr(self.t, "nJet25Eta1",     njet25eta1)
        setattr(self.t, "nJet25Eta2",     njet25eta2)
        setattr(self.t, "deltaPhill",     deltaPhill)
        setattr(self.t, "deltaPhiTopH",   deltaPhiTopH)
        setattr(self.t, "fwdJetEtaGap",   etagap)
        setattr(self.t, "dEtaFwdJetLep1", gaplep1)
        setattr(self.t, "dEtaFwdJetLep2", gaplep2)
        setattr(self.t, "dEtaFwdJetb",    gapb)
        setattr(self.t, "dPhiFwdJetb",    dphib)

        self.t.fill()

import os, itertools, optparse
from sys import argv
usage = "%prog [options] treedir outputdir"
parser = optparse.OptionParser(usage)
parser.add_option('-t', '--onlyTag',  dest='onlyTag',  help='Process only samples matching this tag', default='', type='string')
(opt, args) = parser.parse_args()
if len(args) < 1:
    parser.print_help()
jobs = []

## OUTPUT
outdir = args[1]
if not outdir.endswith('/'): outdir += '/'
if not os.path.exists(outdir): os.mkdir(outdir)

for D in glob(args[0]+"/*"):
    if len(opt.onlyTag) > 0 and not opt.onlyTag in D: continue
    fname = D+"/ttHLepTreeProducerBase/ttHLepTreeProducerBase_tree.root"
    if os.path.exists(fname):
        short = os.path.basename(D)
        f = ROOT.TFile.Open(fname);
        t = f.Get("ttHLepTreeProducerBase")
        entries = t.GetEntries()
        f.Close()
        chunk = 1000000.
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
    el.loop([tb], eventRange=evrange, reportEvery=25000)
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

