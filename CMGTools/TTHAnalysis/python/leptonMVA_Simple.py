########################################################################################################
## USAGE:
## from leptonMVA_Simple import LeptonMVA, MyLepton
## import os
## mva = LeptonMVA("%s/src/CMGTools/TTHAnalysis/data/leptonMVA/%%s_BDTG.weights.xml" % os.environ['CMSSW_BASE'], True)
##
## # lep = MyLepton(pdgId,pt,eta,neuRelIso,chRelIso,jetDR,jetPtRatio,jetBTag,sip3d,mcMatchId,mcMatchAny)
##
## lep = MyLepton(-13, 64.3446121216, 0.8945723, 0.0, 0.012851196445, 0.00820131423107, 0.780341625461, 0.202988564968, 0.0648346675078, 6, 1)
## lep.logdxy = -9.24381218368
## lep.logdz = -9.84448451618
##
# pdgId,     pt,    eta,    phi, mcMatchId, mcMtchAny,     sip3d, neuRelIso,  chRelIso,     jetDR,  jetPtRat,   jetBTag,  log|dxy|,   log|dz|,     mvaID, innerHits,       mva
#    11,  21.93,  -0.67,  -0.19,         6,         1,     1.284,     0.052,     0.137,     0.011,     0.814,     0.298,    -5.529,    -5.485,     0.990,         0,     0.617
## lep = MyLepton(-11, 21.93, -0.67, 0.052, 0.137, 0.011, 0.814, 0.298, 1.284, 6, 1)
## lep.mvaId = 0.990
## lep.innerHits = 0
##
## mva(lep)   #--> 0.78107895471576905
## mva(lep,1) #--> 0.72581076250777521
## mva(lep,2) #--> 0.67887270443628123
########################################################################################################

from array import array
from glob import glob
from math import *
import os.path
from CMGTools.RootTools.utils.DeltaR import deltaR,deltaPhi

import os, ROOT
if "/smearer_cc.so" not in ROOT.gSystem.GetLibraries():
    ROOT.gROOT.ProcessLine(".L %s/src/CMGTools/TTHAnalysis/python/plotter/smearer.cc+" % os.environ['CMSSW_BASE']);
if "/mcCorrections_cc.so" not in ROOT.gSystem.GetLibraries():
    ROOT.gROOT.ProcessLine(".L %s/src/CMGTools/TTHAnalysis/python/plotter/mcCorrections.cc+" % os.environ['CMSSW_BASE']);


class MVAVar:
    def __init__(self,name,func,corrfunc=None):
        self.name = name
        self.var  = array('f',[0.])
        self.func = func
        self.corrfunc = corrfunc
    def set(self,lep,ncorr): ## apply correction ncorr times
        self.var[0] = self.func(lep)
        if self.corrfunc:
            for i in range(ncorr):
                self.var[0] = self.corrfunc(self.var[0], lep.pdgId,lep.pt,lep.eta,lep.mcMatchId,lep.mcMatchAny)
class MVATool:
    def __init__(self,name,xml,vars):
        self.name = name
        self.reader = ROOT.TMVA.Reader("Silent")
        self.vars  = vars
        for v in vars:  self.reader.AddVariable(v.name,v.var)
        #print "Would like to load %s from %s! " % (name,xml)
        self.reader.BookMVA(name,xml)
    def __call__(self,lep,ncorr): ## apply correction ncorr times
        for s in self.vars:  s.set(lep,ncorr)
        return self.reader.EvaluateMVA(self.name)
class CategorizedMVA:
    def __init__(self,catMvaPairs):
        self.catMvaPairs = catMvaPairs
    def __call__(self,lep,ncorr):
        for c,m in self.catMvaPairs:
            if c(lep): return m(lep,ncorr)
        return -99.

_CommonVars = [
    MVAVar("neuRelIso := relIso - chargedIso/pt",lambda x: x.neuRelIso),
    MVAVar("chRelIso := chargedIso/pt",          lambda x: x.chRelIso),
    MVAVar("jetDR_in := min(dr_in,0.5)",         lambda x: x.jetDR, corrfunc=ROOT.correctJetDRMC),
    MVAVar("jetPtRatio_in := min(ptf_in,1.5)",   lambda x: x.jetPtRatio, corrfunc=ROOT.correctJetPtRatioMC),
    MVAVar("jetBTagCSV_in := max(CSV_in,0)",     lambda x: x.jetBTag),
    MVAVar("sip3d",                              lambda x: x.sip3D, corrfunc=ROOT.scaleSip3dMC),
]

_MuonVars = [
    MVAVar("dxy := log(abs(dxy))",lambda x: x.logdxy, corrfunc=ROOT.scaleDxyMC),
    MVAVar("dz  := log(abs(dz))", lambda x: x.logdz,  corrfunc=ROOT.scaleDzMC),
]

_ElectronVars = [
    MVAVar("mvaId",    lambda x: x.mvaId),
    MVAVar("innerHits",lambda x: x.innerHits),
]

class MyLepton():
    def __init__(self,pdgId,pt,eta,neuRelIso,chRelIso,jetDR,jetPtRatio,jetBTag,sip3d,mcMatchId,mcMatchAny):
        self.pdgId      = pdgId
        self.pt         = pt
        self.eta        = eta
        self.neuRelIso  = neuRelIso
        self.chRelIso   = chRelIso
        self.jetDR      = jetDR
        self.jetPtRatio = jetPtRatio
        self.jetBTag    = jetBTag
        self.sip3D      = sip3d
        self.mcMatchId  = mcMatchId
        self.mcMatchAny = mcMatchAny
    def pdgId     (self):
        return self.pdgId
    def pt        (self):
        return self.pt
    def eta       (self):
        return self.eta


class LeptonMVA:
    def __init__(self, basepath, isMC):
        global _CommonVars, _ElectronVars
        self._isMC = isMC
        self.mu = CategorizedMVA([
            ( lambda x: x.pt <= 15 and abs(x.eta) <  1.5 , MVATool("BDTG",basepath%"mu_pteta_low_b", _CommonVars+_MuonVars) ),
            ( lambda x: x.pt <= 15 and abs(x.eta) >= 1.5 , MVATool("BDTG",basepath%"mu_pteta_low_e", _CommonVars+_MuonVars) ),
            ( lambda x: x.pt >  15 and abs(x.eta) <  1.5 , MVATool("BDTG",basepath%"mu_pteta_high_b",_CommonVars+_MuonVars) ),
            ( lambda x: x.pt >  15 and abs(x.eta) >= 1.5 , MVATool("BDTG",basepath%"mu_pteta_high_e",_CommonVars+_MuonVars) ),
        ])
        self.el = CategorizedMVA([
            ( lambda x: x.pt <= 10 and abs(x.eta) <  0.8                           , MVATool("BDTG",basepath%"el_pteta_low_cb", _CommonVars+_ElectronVars) ),
            ( lambda x: x.pt <= 10 and abs(x.eta) >= 0.8 and abs(x.eta) <  1.479 , MVATool("BDTG",basepath%"el_pteta_low_fb", _CommonVars+_ElectronVars) ),
            ( lambda x: x.pt <= 10 and abs(x.eta) >= 1.479                         , MVATool("BDTG",basepath%"el_pteta_low_ec", _CommonVars+_ElectronVars) ),
            ( lambda x: x.pt >  10 and abs(x.eta) <  0.8                           , MVATool("BDTG",basepath%"el_pteta_high_cb",_CommonVars+_ElectronVars) ),
            ( lambda x: x.pt >  10 and abs(x.eta) >= 0.8 and abs(x.eta) <  1.479 , MVATool("BDTG",basepath%"el_pteta_high_fb",_CommonVars+_ElectronVars) ),
            ( lambda x: x.pt >  10 and abs(x.eta) >= 1.479                         , MVATool("BDTG",basepath%"el_pteta_high_ec",_CommonVars+_ElectronVars) ),
        ])
    def __call__(self,lep,ncorr=0):
        if   abs(lep.pdgId) == 11: return self.el(lep,ncorr)
        elif abs(lep.pdgId) == 13: return self.mu(lep,ncorr)
        else: return -99
    def addMVA(self,lep):
        if self._isMC:
            lep.mvaValue      = self(lep,1)
            lep.mvaNoCorr     = self(lep,0)
            lep.mvaDoubleCorr = self(lep,2)
        else:
            lep.mvaValue = self(lep,0)

