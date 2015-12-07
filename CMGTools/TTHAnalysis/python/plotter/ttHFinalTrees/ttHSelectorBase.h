//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Dec  7 13:42:30 2015 by ROOT version 6.02/05
// from TTree tree/treeProducerSusyMultilepton
// found on file: /afs/cern.ch/work/s/stiegerb/TTHTrees/13TeV/TREES_74X_121115_MiniIso_7_4_12/THQ_Hincl/treeProducerSusyMultilepton/tree.root
//////////////////////////////////////////////////////////

#ifndef ttHSelectorBase_h
#define ttHSelectorBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

class ttHSelectorBase : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         xsec;
   Float_t         puWeight;
   Int_t           nTrueInt;
   Float_t         genWeight;
   Float_t         rho;
   Float_t         rhoCN;
   Int_t           nVert;
   Int_t           nJet25;
   Int_t           nJet25a;
   Int_t           nBJetLoose25;
   Int_t           nBJetMedium25;
   Int_t           nBJetTight25;
   Int_t           nJet30;
   Int_t           nJet30a;
   Int_t           nBJetLoose30;
   Int_t           nBJetMedium30;
   Int_t           nBJetTight30;
   Int_t           nJet40;
   Int_t           nJet40a;
   Int_t           nBJetLoose40;
   Int_t           nBJetMedium40;
   Int_t           nBJetTight40;
   Int_t           nLepGood20;
   Int_t           nLepGood15;
   Int_t           nLepGood10;
   Int_t           GenSusyMScan1;
   Int_t           GenSusyMScan2;
   Int_t           GenSusyMScan3;
   Int_t           GenSusyMScan4;
   Int_t           GenSusyMGluino;
   Int_t           GenSusyMGravitino;
   Int_t           GenSusyMStop;
   Int_t           GenSusyMSbottom;
   Int_t           GenSusyMStop2;
   Int_t           GenSusyMSbottom2;
   Int_t           GenSusyMSquark;
   Int_t           GenSusyMNeutralino;
   Int_t           GenSusyMNeutralino2;
   Int_t           GenSusyMNeutralino3;
   Int_t           GenSusyMNeutralino4;
   Int_t           GenSusyMChargino;
   Int_t           GenSusyMChargino2;
   Float_t         htJet25;
   Float_t         mhtJet25;
   Float_t         htJet40j;
   Float_t         htJet40ja;
   Float_t         htJet40;
   Float_t         htJet40a;
   Float_t         mhtJet40;
   Float_t         mhtJet40a;
   Int_t           nJet25NoTau;
   Int_t           nBJetLoose25NoTau;
   Int_t           nBJetMedium25NoTau;
   Int_t           nBJetCMVALoose25;
   Int_t           nBJetCMVAMedium25;
   Int_t           nBJetCMVATight25;
   Int_t           nSoftBLoose25;
   Int_t           nSoftBMedium25;
   Int_t           nSoftBTight25;
   Int_t           nJet30NoTau;
   Int_t           nBJetLoose30NoTau;
   Int_t           nBJetMedium30NoTau;
   Int_t           nJet40NoTau;
   Int_t           nBJetLoose40NoTau;
   Int_t           nBJetMedium40NoTau;
   Int_t           nBJetCMVALoose40;
   Int_t           nBJetCMVAMedium40;
   Int_t           nBJetCMVATight40;
   Float_t         mZ1;
   Float_t         mZ1SFSS;
   Float_t         minMllSFOS;
   Float_t         maxMllSFOS;
   Float_t         minMllAFOS;
   Float_t         maxMllAFOS;
   Float_t         minMllAFSS;
   Float_t         maxMllAFSS;
   Float_t         minMllAFAS;
   Float_t         maxMllAFAS;
   Float_t         m2l;
   Float_t         minDrllAFSS;
   Float_t         maxDrllAFSS;
   Float_t         minDrllAFOS;
   Float_t         maxDrllAFOS;
   Float_t         mZ2;
   Float_t         m3l;
   Float_t         m4l;
   Float_t         pt2l;
   Float_t         pt3l;
   Float_t         pt4l;
   Float_t         ht3l;
   Float_t         ht4l;
   Int_t           q3l;
   Int_t           q4l;
   Int_t           minMWjj;
   Int_t           minMWjjPt;
   Int_t           bestMWjj;
   Int_t           bestMWjjPt;
   Int_t           bestMTopHad;
   Int_t           bestMTopHadPt;
   Int_t           GenHiggsDecayMode;
   Float_t         absIP3DAval;
   Float_t         absIP3DAerr;
   Float_t         absIP3DBval;
   Float_t         absIP3DBerr;
   Float_t         absIP3DCval;
   Float_t         absIP3DCerr;
   Float_t         absIP3DDval;
   Float_t         absIP3DDerr;
   Float_t         absIP3DApvBCval;
   Float_t         absIP3DApvBCerr;
   Float_t         absIP3DBpvACval;
   Float_t         absIP3DBpvACerr;
   Float_t         absIP3DCpvABval;
   Float_t         absIP3DCpvABerr;
   Float_t         absIP3DApvBCDval;
   Float_t         absIP3DApvBCDerr;
   Float_t         absIP3DBpvACDval;
   Float_t         absIP3DBpvACDerr;
   Float_t         absIP3DCpvABDval;
   Float_t         absIP3DCpvABDerr;
   Float_t         absIP3DDpvABCval;
   Float_t         absIP3DDpvABCerr;
   Float_t         chi2pvtrksBCbutAval;
   Float_t         chi2pvtrksBCbutAdof;
   Float_t         chi2pvtrksACbutBval;
   Float_t         chi2pvtrksACbutBdof;
   Float_t         chi2pvtrksABbutCval;
   Float_t         chi2pvtrksABbutCdof;
   Float_t         chi2pvtrksBCDbutAval;
   Float_t         chi2pvtrksBCDbutAdof;
   Float_t         chi2pvtrksACDbutBval;
   Float_t         chi2pvtrksACDbutBdof;
   Float_t         chi2pvtrksABDbutCval;
   Float_t         chi2pvtrksABDbutCdof;
   Float_t         chi2pvtrksABCbutDval;
   Float_t         chi2pvtrksABCbutDdof;
   Int_t           nRecJet40;
   Int_t           nRecJet25;
   Int_t           nRecBJetMedium40;
   Int_t           nRecBJetMedium25;
   Int_t           nRecSplitJet40;
   Int_t           nRecSplitJet25;
   Int_t           nRecSplitBJetMedium40;
   Int_t           nRecSplitBJetMedium25;
   Int_t           hbheFilterNew50ns;
   Int_t           hbheFilterNew25ns;
   Int_t           hbheFilterIso;
   Float_t         met_trkPt;
   Float_t         met_trkPhi;
   Float_t         HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_DoubleElHT;
   Float_t         HLT_DoubleElHT_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_TripleEl;
   Float_t         HLT_TripleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_MuEGHT;
   Float_t         HLT_MuEGHT_isUnprescaled;
   Float_t         HLT_MonoJet80MET90;
   Float_t         HLT_MonoJet80MET90_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu24_eta2p1_v;
   Float_t         HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu24_eta2p1_v;
   Float_t         HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu18_v;
   Float_t         HLT_BIT_HLT_IsoMu18_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu20_v;
   Float_t         HLT_BIT_HLT_IsoMu20_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu20_v;
   Float_t         HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoMu27_v;
   Float_t         HLT_BIT_HLT_IsoMu27_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_IsoTkMu27_v;
   Float_t         HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled;
   Float_t         HLT_SingleMu;
   Float_t         HLT_SingleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_DoubleMuEl;
   Float_t         HLT_DoubleMuEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v;
   Float_t         HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;
   Float_t         HLT_MonoJet80MET120;
   Float_t         HLT_MonoJet80MET120_isUnprescaled;
   Float_t         HLT_BIT_HLT_TripleMu_12_10_5_v;
   Float_t         HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;
   Float_t         HLT_TripleMu;
   Float_t         HLT_TripleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;
   Float_t         HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;
   Float_t         HLT_DoubleElMu;
   Float_t         HLT_DoubleElMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu30_TkMu11_v;
   Float_t         HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;
   Float_t         HLT_DoubleMuNoIso;
   Float_t         HLT_DoubleMuNoIso_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_v;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleMuSS;
   Float_t         HLT_DoubleMuSS_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_WP85_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v;
   Float_t         HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled;
   Float_t         HLT_SingleEl;
   Float_t         HLT_SingleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;
   Float_t         HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;
   Float_t         HLT_TripleMuA;
   Float_t         HLT_TripleMuA_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Float_t         HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Float_t         HLT_MuEG;
   Float_t         HLT_MuEG_isUnprescaled;
   Float_t         HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;
   Float_t         HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;
   Float_t         HLT_DoubleMuHT;
   Float_t         HLT_DoubleMuHT_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Float_t         HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Float_t         HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleEl;
   Float_t         HLT_DoubleEl_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;
   Float_t         HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Float_t         HLT_DoubleMu;
   Float_t         HLT_DoubleMu_isUnprescaled;
   Float_t         HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v;
   Float_t         HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled;
   Float_t         HLT_METMu5;
   Float_t         HLT_METMu5_isUnprescaled;
   Float_t         Flag_HBHENoiseIsoFilter;
   Float_t         Flag_EcalDeadCellTriggerPrimitiveFilter;
   Float_t         Flag_trkPOG_manystripclus53X;
   Float_t         Flag_ecalLaserCorrFilter;
   Float_t         Flag_trkPOG_toomanystripclus53X;
   Float_t         Flag_hcalLaserEventFilter;
   Float_t         Flag_trkPOG_logErrorTooManyClusters;
   Float_t         Flag_trkPOGFilters;
   Float_t         Flag_trackingFailureFilter;
   Float_t         Flag_CSCTightHaloFilter;
   Float_t         Flag_HBHENoiseFilter;
   Float_t         Flag_goodVertices;
   Float_t         Flag_METFilters;
   Float_t         Flag_eeBadScFilter;
   Float_t         met_pt;
   Float_t         met_eta;
   Float_t         met_phi;
   Float_t         met_mass;
   Float_t         met_sumEt;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_rawSumEt;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Float_t         met_genEta;
   Int_t           nFatJet;
   Int_t           FatJet_id[15];   //[nFatJet]
   Int_t           FatJet_puId[15];   //[nFatJet]
   Float_t         FatJet_btagCSV[15];   //[nFatJet]
   Float_t         FatJet_btagCMVA[15];   //[nFatJet]
   Float_t         FatJet_rawPt[15];   //[nFatJet]
   Float_t         FatJet_mcPt[15];   //[nFatJet]
   Int_t           FatJet_mcFlavour[15];   //[nFatJet]
   Int_t           FatJet_mcMatchId[15];   //[nFatJet]
   Float_t         FatJet_corr_JECUp[15];   //[nFatJet]
   Float_t         FatJet_corr_JECDown[15];   //[nFatJet]
   Float_t         FatJet_corr[15];   //[nFatJet]
   Float_t         FatJet_pt[15];   //[nFatJet]
   Float_t         FatJet_eta[15];   //[nFatJet]
   Float_t         FatJet_phi[15];   //[nFatJet]
   Float_t         FatJet_mass[15];   //[nFatJet]
   Float_t         FatJet_prunedMass[15];   //[nFatJet]
   Float_t         FatJet_trimmedMass[15];   //[nFatJet]
   Float_t         FatJet_filteredMass[15];   //[nFatJet]
   Float_t         FatJet_tau1[15];   //[nFatJet]
   Float_t         FatJet_tau2[15];   //[nFatJet]
   Float_t         FatJet_tau3[15];   //[nFatJet]
   Float_t         FatJet_topMass[15];   //[nFatJet]
   Float_t         FatJet_minMass[15];   //[nFatJet]
   Float_t         FatJet_nSubJets[15];   //[nFatJet]
   Int_t           nDiscLep;
   Float_t         DiscLep_mvaIdPhys14[8];   //[nDiscLep]
   Float_t         DiscLep_mvaIdSpring15[8];   //[nDiscLep]
   Float_t         DiscLep_mvaTTH[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRatiov1[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelv1[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRatiov2[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelv2[8];   //[nDiscLep]
   Float_t         DiscLep_jetBTagCSV[8];   //[nDiscLep]
   Float_t         DiscLep_jetBTagCMVA[8];   //[nDiscLep]
   Float_t         DiscLep_jetDR[8];   //[nDiscLep]
   Int_t           DiscLep_charge[8];   //[nDiscLep]
   Int_t           DiscLep_tightId[8];   //[nDiscLep]
   Int_t           DiscLep_eleCutIdCSA14_25ns_v1[8];   //[nDiscLep]
   Int_t           DiscLep_eleCutIdCSA14_50ns_v1[8];   //[nDiscLep]
   Float_t         DiscLep_dxy[8];   //[nDiscLep]
   Float_t         DiscLep_dz[8];   //[nDiscLep]
   Float_t         DiscLep_edxy[8];   //[nDiscLep]
   Float_t         DiscLep_edz[8];   //[nDiscLep]
   Float_t         DiscLep_ip3d[8];   //[nDiscLep]
   Float_t         DiscLep_sip3d[8];   //[nDiscLep]
   Int_t           DiscLep_convVeto[8];   //[nDiscLep]
   Int_t           DiscLep_lostHits[8];   //[nDiscLep]
   Float_t         DiscLep_relIso03[8];   //[nDiscLep]
   Float_t         DiscLep_relIso04[8];   //[nDiscLep]
   Float_t         DiscLep_miniRelIso[8];   //[nDiscLep]
   Float_t         DiscLep_relIsoAn04[8];   //[nDiscLep]
   Int_t           DiscLep_tightCharge[8];   //[nDiscLep]
   Int_t           DiscLep_mcMatchId[8];   //[nDiscLep]
   Int_t           DiscLep_mcMatchAny[8];   //[nDiscLep]
   Int_t           DiscLep_mcMatchTau[8];   //[nDiscLep]
   Float_t         DiscLep_mcPt[8];   //[nDiscLep]
   Int_t           DiscLep_mediumMuonId[8];   //[nDiscLep]
   Int_t           DiscLep_pdgId[8];   //[nDiscLep]
   Float_t         DiscLep_pt[8];   //[nDiscLep]
   Float_t         DiscLep_eta[8];   //[nDiscLep]
   Float_t         DiscLep_phi[8];   //[nDiscLep]
   Float_t         DiscLep_mass[8];   //[nDiscLep]
   Float_t         DiscLep_chargedHadRelIso03[8];   //[nDiscLep]
   Float_t         DiscLep_chargedHadRelIso04[8];   //[nDiscLep]
   Int_t           DiscLep_softMuonId[8];   //[nDiscLep]
   Int_t           DiscLep_pfMuonId[8];   //[nDiscLep]
   Int_t           DiscLep_eleCutId2012_full5x5[8];   //[nDiscLep]
   Int_t           DiscLep_trackerLayers[8];   //[nDiscLep]
   Int_t           DiscLep_pixelLayers[8];   //[nDiscLep]
   Int_t           DiscLep_trackerHits[8];   //[nDiscLep]
   Int_t           DiscLep_lostOuterHits[8];   //[nDiscLep]
   Float_t         DiscLep_innerTrackValidHitFraction[8];   //[nDiscLep]
   Float_t         DiscLep_innerTrackChi2[8];   //[nDiscLep]
   Float_t         DiscLep_nStations[8];   //[nDiscLep]
   Float_t         DiscLep_caloCompatibility[8];   //[nDiscLep]
   Float_t         DiscLep_globalTrackChi2[8];   //[nDiscLep]
   Float_t         DiscLep_trkKink[8];   //[nDiscLep]
   Float_t         DiscLep_segmentCompatibility[8];   //[nDiscLep]
   Float_t         DiscLep_chi2LocalPosition[8];   //[nDiscLep]
   Float_t         DiscLep_chi2LocalMomentum[8];   //[nDiscLep]
   Float_t         DiscLep_glbTrackProbability[8];   //[nDiscLep]
   Float_t         DiscLep_sigmaIEtaIEta[8];   //[nDiscLep]
   Float_t         DiscLep_dEtaScTrkIn[8];   //[nDiscLep]
   Float_t         DiscLep_dPhiScTrkIn[8];   //[nDiscLep]
   Float_t         DiscLep_hadronicOverEm[8];   //[nDiscLep]
   Float_t         DiscLep_eInvMinusPInv[8];   //[nDiscLep]
   Float_t         DiscLep_eInvMinusPInv_tkMom[8];   //[nDiscLep]
   Float_t         DiscLep_etaSc[8];   //[nDiscLep]
   Float_t         DiscLep_miniRelIsoCharged[8];   //[nDiscLep]
   Float_t         DiscLep_miniRelIsoNeutral[8];   //[nDiscLep]
   Int_t           DiscLep_hasSV[8];   //[nDiscLep]
   Float_t         DiscLep_svRedPt[8];   //[nDiscLep]
   Float_t         DiscLep_svRedM[8];   //[nDiscLep]
   Float_t         DiscLep_svLepSip3d[8];   //[nDiscLep]
   Float_t         DiscLep_svSip3d[8];   //[nDiscLep]
   Float_t         DiscLep_svNTracks[8];   //[nDiscLep]
   Float_t         DiscLep_svChi2n[8];   //[nDiscLep]
   Float_t         DiscLep_svDxy[8];   //[nDiscLep]
   Float_t         DiscLep_svMass[8];   //[nDiscLep]
   Float_t         DiscLep_svPt[8];   //[nDiscLep]
   Float_t         DiscLep_svMCMatchFraction[8];   //[nDiscLep]
   Float_t         DiscLep_svMva[8];   //[nDiscLep]
   Float_t         DiscLep_jetNDau[8];   //[nDiscLep]
   Float_t         DiscLep_jetNDauCharged[8];   //[nDiscLep]
   Float_t         DiscLep_jetNDauPV[8];   //[nDiscLep]
   Float_t         DiscLep_jetNDauNotPV[8];   //[nDiscLep]
   Float_t         DiscLep_jetmaxSignedSip3D[8];   //[nDiscLep]
   Float_t         DiscLep_jetmaxSip3D[8];   //[nDiscLep]
   Float_t         DiscLep_jetmaxSignedSip2D[8];   //[nDiscLep]
   Float_t         DiscLep_jetmaxSip2D[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelv0[8];   //[nDiscLep]
   Float_t         DiscLep_jetMass[8];   //[nDiscLep]
   Float_t         DiscLep_jetPrunedMass[8];   //[nDiscLep]
   Float_t         DiscLep_jetDecDR[8];   //[nDiscLep]
   Float_t         DiscLep_jetDecPtRel[8];   //[nDiscLep]
   Float_t         DiscLep_jetDecPtRatio[8];   //[nDiscLep]
   Float_t         DiscLep_jetDecPrunedMass[8];   //[nDiscLep]
   Float_t         DiscLep_jetDecPrunedPtRatio[8];   //[nDiscLep]
   Float_t         DiscLep_jetDec02DR[8];   //[nDiscLep]
   Float_t         DiscLep_jetDec02PtRel[8];   //[nDiscLep]
   Float_t         DiscLep_jetDec02PtRatio[8];   //[nDiscLep]
   Float_t         DiscLep_jetDec02PrunedPtRatio[8];   //[nDiscLep]
   Float_t         DiscLep_jetDec02PrunedMass[8];   //[nDiscLep]
   Float_t         DiscLep_jetRawPt[8];   //[nDiscLep]
   Float_t         DiscLep_jetCorrFactor_L1[8];   //[nDiscLep]
   Float_t         DiscLep_jetCorrFactor_L1L2[8];   //[nDiscLep]
   Float_t         DiscLep_jetCorrFactor_L1L2L3[8];   //[nDiscLep]
   Float_t         DiscLep_jetCorrFactor_L1L2L3Res[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRatio_Raw[8];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelHv2[8];   //[nDiscLep]
   Float_t         DiscLep_ecalPFClusterIso[8];   //[nDiscLep]
   Float_t         DiscLep_hcalPFClusterIso[8];   //[nDiscLep]
   Float_t         DiscLep_dr03TkSumPt[8];   //[nDiscLep]
   Float_t         DiscLep_trackIso[8];   //[nDiscLep]
   Float_t         DiscLep_jetLepAwareJEC_pt[8];   //[nDiscLep]
   Float_t         DiscLep_jetLepAwareJEC_eta[8];   //[nDiscLep]
   Float_t         DiscLep_jetLepAwareJEC_phi[8];   //[nDiscLep]
   Float_t         DiscLep_jetLepAwareJEC_energy[8];   //[nDiscLep]
   Int_t           nGenPart;
   Int_t           GenPart_motherId[27];   //[nGenPart]
   Int_t           GenPart_grandmotherId[27];   //[nGenPart]
   Int_t           GenPart_sourceId[27];   //[nGenPart]
   Float_t         GenPart_charge[27];   //[nGenPart]
   Int_t           GenPart_status[27];   //[nGenPart]
   Int_t           GenPart_pdgId[27];   //[nGenPart]
   Float_t         GenPart_pt[27];   //[nGenPart]
   Float_t         GenPart_eta[27];   //[nGenPart]
   Float_t         GenPart_phi[27];   //[nGenPart]
   Float_t         GenPart_mass[27];   //[nGenPart]
   Int_t           GenPart_motherIndex[27];   //[nGenPart]
   Int_t           nDiscJet;
   Float_t         DiscJet_area[15];   //[nDiscJet]
   Float_t         DiscJet_qgl[15];   //[nDiscJet]
   Float_t         DiscJet_ptd[15];   //[nDiscJet]
   Float_t         DiscJet_axis2[15];   //[nDiscJet]
   Int_t           DiscJet_mult[15];   //[nDiscJet]
   Int_t           DiscJet_partonId[15];   //[nDiscJet]
   Int_t           DiscJet_partonMotherId[15];   //[nDiscJet]
   Float_t         DiscJet_nLeptons[15];   //[nDiscJet]
   Int_t           DiscJet_id[15];   //[nDiscJet]
   Int_t           DiscJet_puId[15];   //[nDiscJet]
   Float_t         DiscJet_btagCSV[15];   //[nDiscJet]
   Float_t         DiscJet_btagCMVA[15];   //[nDiscJet]
   Float_t         DiscJet_rawPt[15];   //[nDiscJet]
   Float_t         DiscJet_mcPt[15];   //[nDiscJet]
   Int_t           DiscJet_mcFlavour[15];   //[nDiscJet]
   Int_t           DiscJet_mcMatchId[15];   //[nDiscJet]
   Float_t         DiscJet_corr_JECUp[15];   //[nDiscJet]
   Float_t         DiscJet_corr_JECDown[15];   //[nDiscJet]
   Float_t         DiscJet_corr[15];   //[nDiscJet]
   Float_t         DiscJet_pt[15];   //[nDiscJet]
   Float_t         DiscJet_eta[15];   //[nDiscJet]
   Float_t         DiscJet_phi[15];   //[nDiscJet]
   Float_t         DiscJet_mass[15];   //[nDiscJet]
   Int_t           DiscJet_mcMatchFlav[15];   //[nDiscJet]
   Float_t         DiscJet_charge[15];   //[nDiscJet]
   Int_t           nSV;
   Float_t         SV_pt[20];   //[nSV]
   Float_t         SV_eta[20];   //[nSV]
   Float_t         SV_phi[20];   //[nSV]
   Float_t         SV_mass[20];   //[nSV]
   Int_t           SV_charge[20];   //[nSV]
   Int_t           SV_ntracks[20];   //[nSV]
   Float_t         SV_chi2[20];   //[nSV]
   Float_t         SV_ndof[20];   //[nSV]
   Float_t         SV_dxy[20];   //[nSV]
   Float_t         SV_edxy[20];   //[nSV]
   Float_t         SV_ip3d[20];   //[nSV]
   Float_t         SV_eip3d[20];   //[nSV]
   Float_t         SV_sip3d[20];   //[nSV]
   Float_t         SV_cosTheta[20];   //[nSV]
   Float_t         SV_mva[20];   //[nSV]
   Float_t         SV_jetPt[20];   //[nSV]
   Float_t         SV_jetBTagCSV[20];   //[nSV]
   Float_t         SV_jetBTagCMVA[20];   //[nSV]
   Int_t           SV_mcMatchNTracks[20];   //[nSV]
   Int_t           SV_mcMatchNTracksHF[20];   //[nSV]
   Float_t         SV_mcMatchFraction[20];   //[nSV]
   Int_t           SV_mcFlavFirst[20];   //[nSV]
   Int_t           SV_mcFlavHeaviest[20];   //[nSV]
   Float_t         SV_maxDxyTracks[20];   //[nSV]
   Float_t         SV_secDxyTracks[20];   //[nSV]
   Float_t         SV_maxD3dTracks[20];   //[nSV]
   Float_t         SV_secD3dTracks[20];   //[nSV]
   Int_t           nLepGood;
   Float_t         LepGood_mvaIdPhys14[8];   //[nLepGood]
   Float_t         LepGood_mvaIdSpring15[8];   //[nLepGood]
   Float_t         LepGood_mvaTTH[8];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov1[8];   //[nLepGood]
   Float_t         LepGood_jetPtRelv1[8];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov2[8];   //[nLepGood]
   Float_t         LepGood_jetPtRelv2[8];   //[nLepGood]
   Float_t         LepGood_jetBTagCSV[8];   //[nLepGood]
   Float_t         LepGood_jetBTagCMVA[8];   //[nLepGood]
   Float_t         LepGood_jetDR[8];   //[nLepGood]
   Int_t           LepGood_charge[8];   //[nLepGood]
   Int_t           LepGood_tightId[8];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_25ns_v1[8];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_50ns_v1[8];   //[nLepGood]
   Float_t         LepGood_dxy[8];   //[nLepGood]
   Float_t         LepGood_dz[8];   //[nLepGood]
   Float_t         LepGood_edxy[8];   //[nLepGood]
   Float_t         LepGood_edz[8];   //[nLepGood]
   Float_t         LepGood_ip3d[8];   //[nLepGood]
   Float_t         LepGood_sip3d[8];   //[nLepGood]
   Int_t           LepGood_convVeto[8];   //[nLepGood]
   Int_t           LepGood_lostHits[8];   //[nLepGood]
   Float_t         LepGood_relIso03[8];   //[nLepGood]
   Float_t         LepGood_relIso04[8];   //[nLepGood]
   Float_t         LepGood_miniRelIso[8];   //[nLepGood]
   Float_t         LepGood_relIsoAn04[8];   //[nLepGood]
   Int_t           LepGood_tightCharge[8];   //[nLepGood]
   Int_t           LepGood_mcMatchId[8];   //[nLepGood]
   Int_t           LepGood_mcMatchAny[8];   //[nLepGood]
   Int_t           LepGood_mcMatchTau[8];   //[nLepGood]
   Float_t         LepGood_mcPt[8];   //[nLepGood]
   Int_t           LepGood_mediumMuonId[8];   //[nLepGood]
   Int_t           LepGood_pdgId[8];   //[nLepGood]
   Float_t         LepGood_pt[8];   //[nLepGood]
   Float_t         LepGood_eta[8];   //[nLepGood]
   Float_t         LepGood_phi[8];   //[nLepGood]
   Float_t         LepGood_mass[8];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso03[8];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso04[8];   //[nLepGood]
   Int_t           LepGood_softMuonId[8];   //[nLepGood]
   Int_t           LepGood_pfMuonId[8];   //[nLepGood]
   Int_t           LepGood_eleCutId2012_full5x5[8];   //[nLepGood]
   Int_t           LepGood_trackerLayers[8];   //[nLepGood]
   Int_t           LepGood_pixelLayers[8];   //[nLepGood]
   Int_t           LepGood_trackerHits[8];   //[nLepGood]
   Int_t           LepGood_lostOuterHits[8];   //[nLepGood]
   Float_t         LepGood_innerTrackValidHitFraction[8];   //[nLepGood]
   Float_t         LepGood_innerTrackChi2[8];   //[nLepGood]
   Float_t         LepGood_nStations[8];   //[nLepGood]
   Float_t         LepGood_caloCompatibility[8];   //[nLepGood]
   Float_t         LepGood_globalTrackChi2[8];   //[nLepGood]
   Float_t         LepGood_trkKink[8];   //[nLepGood]
   Float_t         LepGood_segmentCompatibility[8];   //[nLepGood]
   Float_t         LepGood_chi2LocalPosition[8];   //[nLepGood]
   Float_t         LepGood_chi2LocalMomentum[8];   //[nLepGood]
   Float_t         LepGood_glbTrackProbability[8];   //[nLepGood]
   Float_t         LepGood_sigmaIEtaIEta[8];   //[nLepGood]
   Float_t         LepGood_dEtaScTrkIn[8];   //[nLepGood]
   Float_t         LepGood_dPhiScTrkIn[8];   //[nLepGood]
   Float_t         LepGood_hadronicOverEm[8];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv[8];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv_tkMom[8];   //[nLepGood]
   Float_t         LepGood_etaSc[8];   //[nLepGood]
   Float_t         LepGood_miniRelIsoCharged[8];   //[nLepGood]
   Float_t         LepGood_miniRelIsoNeutral[8];   //[nLepGood]
   Int_t           LepGood_hasSV[8];   //[nLepGood]
   Float_t         LepGood_svRedPt[8];   //[nLepGood]
   Float_t         LepGood_svRedM[8];   //[nLepGood]
   Float_t         LepGood_svLepSip3d[8];   //[nLepGood]
   Float_t         LepGood_svSip3d[8];   //[nLepGood]
   Float_t         LepGood_svNTracks[8];   //[nLepGood]
   Float_t         LepGood_svChi2n[8];   //[nLepGood]
   Float_t         LepGood_svDxy[8];   //[nLepGood]
   Float_t         LepGood_svMass[8];   //[nLepGood]
   Float_t         LepGood_svPt[8];   //[nLepGood]
   Float_t         LepGood_svMCMatchFraction[8];   //[nLepGood]
   Float_t         LepGood_svMva[8];   //[nLepGood]
   Float_t         LepGood_jetNDau[8];   //[nLepGood]
   Float_t         LepGood_jetNDauCharged[8];   //[nLepGood]
   Float_t         LepGood_jetNDauPV[8];   //[nLepGood]
   Float_t         LepGood_jetNDauNotPV[8];   //[nLepGood]
   Float_t         LepGood_jetmaxSignedSip3D[8];   //[nLepGood]
   Float_t         LepGood_jetmaxSip3D[8];   //[nLepGood]
   Float_t         LepGood_jetmaxSignedSip2D[8];   //[nLepGood]
   Float_t         LepGood_jetmaxSip2D[8];   //[nLepGood]
   Float_t         LepGood_jetPtRelv0[8];   //[nLepGood]
   Float_t         LepGood_jetMass[8];   //[nLepGood]
   Float_t         LepGood_jetPrunedMass[8];   //[nLepGood]
   Float_t         LepGood_jetDecDR[8];   //[nLepGood]
   Float_t         LepGood_jetDecPtRel[8];   //[nLepGood]
   Float_t         LepGood_jetDecPtRatio[8];   //[nLepGood]
   Float_t         LepGood_jetDecPrunedMass[8];   //[nLepGood]
   Float_t         LepGood_jetDecPrunedPtRatio[8];   //[nLepGood]
   Float_t         LepGood_jetDec02DR[8];   //[nLepGood]
   Float_t         LepGood_jetDec02PtRel[8];   //[nLepGood]
   Float_t         LepGood_jetDec02PtRatio[8];   //[nLepGood]
   Float_t         LepGood_jetDec02PrunedPtRatio[8];   //[nLepGood]
   Float_t         LepGood_jetDec02PrunedMass[8];   //[nLepGood]
   Float_t         LepGood_jetRawPt[8];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1[8];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2[8];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3[8];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3Res[8];   //[nLepGood]
   Float_t         LepGood_jetPtRatio_Raw[8];   //[nLepGood]
   Float_t         LepGood_jetPtRelHv2[8];   //[nLepGood]
   Float_t         LepGood_ecalPFClusterIso[8];   //[nLepGood]
   Float_t         LepGood_hcalPFClusterIso[8];   //[nLepGood]
   Float_t         LepGood_dr03TkSumPt[8];   //[nLepGood]
   Float_t         LepGood_trackIso[8];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_pt[8];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_eta[8];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_phi[8];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_energy[8];   //[nLepGood]
   Int_t           nGenDHad;
   Float_t         GenDHad_charge[20];   //[nGenDHad]
   Int_t           GenDHad_status[20];   //[nGenDHad]
   Int_t           GenDHad_pdgId[20];   //[nGenDHad]
   Float_t         GenDHad_pt[20];   //[nGenDHad]
   Float_t         GenDHad_eta[20];   //[nGenDHad]
   Float_t         GenDHad_phi[20];   //[nGenDHad]
   Float_t         GenDHad_mass[20];   //[nGenDHad]
   Int_t           GenDHad_flav[20];   //[nGenDHad]
   Int_t           GenDHad_sourceId[20];   //[nGenDHad]
   Float_t         GenDHad_svMass[20];   //[nGenDHad]
   Float_t         GenDHad_svPt[20];   //[nGenDHad]
   Int_t           GenDHad_svCharge[20];   //[nGenDHad]
   Int_t           GenDHad_svNtracks[20];   //[nGenDHad]
   Float_t         GenDHad_svChi2[20];   //[nGenDHad]
   Float_t         GenDHad_svNdof[20];   //[nGenDHad]
   Float_t         GenDHad_svDxy[20];   //[nGenDHad]
   Float_t         GenDHad_svEdxy[20];   //[nGenDHad]
   Float_t         GenDHad_svIp3d[20];   //[nGenDHad]
   Float_t         GenDHad_svEip3d[20];   //[nGenDHad]
   Float_t         GenDHad_svSip3d[20];   //[nGenDHad]
   Float_t         GenDHad_svCosTheta[20];   //[nGenDHad]
   Float_t         GenDHad_svMva[20];   //[nGenDHad]
   Float_t         GenDHad_jetPt[20];   //[nGenDHad]
   Float_t         GenDHad_jetBTagCSV[20];   //[nGenDHad]
   Float_t         GenDHad_jetBTagCMVA[20];   //[nGenDHad]
   Int_t           nGenBHad;
   Float_t         GenBHad_charge[10];   //[nGenBHad]
   Int_t           GenBHad_status[10];   //[nGenBHad]
   Int_t           GenBHad_pdgId[10];   //[nGenBHad]
   Float_t         GenBHad_pt[10];   //[nGenBHad]
   Float_t         GenBHad_eta[10];   //[nGenBHad]
   Float_t         GenBHad_phi[10];   //[nGenBHad]
   Float_t         GenBHad_mass[10];   //[nGenBHad]
   Int_t           GenBHad_flav[10];   //[nGenBHad]
   Int_t           GenBHad_sourceId[10];   //[nGenBHad]
   Float_t         GenBHad_svMass[10];   //[nGenBHad]
   Float_t         GenBHad_svPt[10];   //[nGenBHad]
   Int_t           GenBHad_svCharge[10];   //[nGenBHad]
   Int_t           GenBHad_svNtracks[10];   //[nGenBHad]
   Float_t         GenBHad_svChi2[10];   //[nGenBHad]
   Float_t         GenBHad_svNdof[10];   //[nGenBHad]
   Float_t         GenBHad_svDxy[10];   //[nGenBHad]
   Float_t         GenBHad_svEdxy[10];   //[nGenBHad]
   Float_t         GenBHad_svIp3d[10];   //[nGenBHad]
   Float_t         GenBHad_svEip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svSip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svCosTheta[10];   //[nGenBHad]
   Float_t         GenBHad_svMva[10];   //[nGenBHad]
   Float_t         GenBHad_jetPt[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCSV[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCMVA[10];   //[nGenBHad]
   Int_t           nJet;
   Int_t           Jet_mcMatchFlav[15];   //[nJet]
   Float_t         Jet_charge[15];   //[nJet]
   Float_t         Jet_area[15];   //[nJet]
   Float_t         Jet_qgl[15];   //[nJet]
   Float_t         Jet_ptd[15];   //[nJet]
   Float_t         Jet_axis2[15];   //[nJet]
   Int_t           Jet_mult[15];   //[nJet]
   Int_t           Jet_partonId[15];   //[nJet]
   Int_t           Jet_partonMotherId[15];   //[nJet]
   Float_t         Jet_nLeptons[15];   //[nJet]
   Int_t           Jet_id[15];   //[nJet]
   Int_t           Jet_puId[15];   //[nJet]
   Float_t         Jet_btagCSV[15];   //[nJet]
   Float_t         Jet_btagCMVA[15];   //[nJet]
   Float_t         Jet_rawPt[15];   //[nJet]
   Float_t         Jet_mcPt[15];   //[nJet]
   Int_t           Jet_mcFlavour[15];   //[nJet]
   Int_t           Jet_mcMatchId[15];   //[nJet]
   Float_t         Jet_corr_JECUp[15];   //[nJet]
   Float_t         Jet_corr_JECDown[15];   //[nJet]
   Float_t         Jet_corr[15];   //[nJet]
   Float_t         Jet_pt[15];   //[nJet]
   Float_t         Jet_eta[15];   //[nJet]
   Float_t         Jet_phi[15];   //[nJet]
   Float_t         Jet_mass[15];   //[nJet]
   Float_t         Jet_prunedMass[15];   //[nJet]
   Int_t           Jet_mcNumPartons[15];   //[nJet]
   Int_t           Jet_mcNumLeptons[15];   //[nJet]
   Int_t           Jet_mcNumTaus[15];   //[nJet]
   Float_t         Jet_mcAnyPartonMass[15];   //[nJet]
   Int_t           Jet_nSubJets[15];   //[nJet]
   Int_t           Jet_nSubJets25[15];   //[nJet]
   Int_t           Jet_nSubJets30[15];   //[nJet]
   Int_t           Jet_nSubJets40[15];   //[nJet]
   Int_t           Jet_nSubJetsZ01[15];   //[nJet]
   Float_t         Jet_chHEF[15];   //[nJet]
   Float_t         Jet_neHEF[15];   //[nJet]
   Float_t         Jet_phEF[15];   //[nJet]
   Float_t         Jet_eEF[15];   //[nJet]
   Float_t         Jet_muEF[15];   //[nJet]
   Float_t         Jet_HFHEF[15];   //[nJet]
   Float_t         Jet_HFEMEF[15];   //[nJet]
   Int_t           Jet_chHMult[15];   //[nJet]
   Int_t           Jet_neHMult[15];   //[nJet]
   Int_t           Jet_phMult[15];   //[nJet]
   Int_t           Jet_eMult[15];   //[nJet]
   Int_t           Jet_muMult[15];   //[nJet]
   Int_t           Jet_HFHMult[15];   //[nJet]
   Int_t           Jet_HFEMMult[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3Res[15];   //[nJet]
   Int_t           nJetNoTauIdx;
   Int_t           JetNoTauIdx[10];   //[nJetNoTauIdx]
   Int_t           nLHEweight;
   Int_t           LHEweight_id[1000];   //[nLHEweight]
   Float_t         LHEweight_wgt[1000];   //[nLHEweight]
   Int_t           nTauGood;
   Int_t           TauGood_charge[8];   //[nTauGood]
   Int_t           TauGood_decayMode[8];   //[nTauGood]
   Int_t           TauGood_idDecayMode[8];   //[nTauGood]
   Int_t           TauGood_idDecayModeNewDMs[8];   //[nTauGood]
   Float_t         TauGood_dxy[8];   //[nTauGood]
   Float_t         TauGood_dz[8];   //[nTauGood]
   Int_t           TauGood_idMVA[8];   //[nTauGood]
   Int_t           TauGood_idMVANewDM[8];   //[nTauGood]
   Int_t           TauGood_idCI3hit[8];   //[nTauGood]
   Int_t           TauGood_idAntiMu[8];   //[nTauGood]
   Int_t           TauGood_idAntiE[8];   //[nTauGood]
   Float_t         TauGood_isoCI3hit[8];   //[nTauGood]
   Int_t           TauGood_mcMatchId[8];   //[nTauGood]
   Int_t           TauGood_pdgId[8];   //[nTauGood]
   Float_t         TauGood_pt[8];   //[nTauGood]
   Float_t         TauGood_eta[8];   //[nTauGood]
   Float_t         TauGood_phi[8];   //[nTauGood]
   Float_t         TauGood_mass[8];   //[nTauGood]
   Int_t           ngenLep;
   Int_t           genLep_motherId[15];   //[ngenLep]
   Int_t           genLep_grandmotherId[15];   //[ngenLep]
   Int_t           genLep_sourceId[15];   //[ngenLep]
   Float_t         genLep_charge[15];   //[ngenLep]
   Int_t           genLep_status[15];   //[ngenLep]
   Int_t           genLep_pdgId[15];   //[ngenLep]
   Float_t         genLep_pt[15];   //[ngenLep]
   Float_t         genLep_eta[15];   //[ngenLep]
   Float_t         genLep_phi[15];   //[ngenLep]
   Float_t         genLep_mass[15];   //[ngenLep]
   Int_t           genLep_motherIndex[15];   //[ngenLep]
   Int_t           ngenTau;
   Int_t           genTau_motherId[4];   //[ngenTau]
   Int_t           genTau_grandmotherId[4];   //[ngenTau]
   Int_t           genTau_sourceId[4];   //[ngenTau]
   Float_t         genTau_charge[4];   //[ngenTau]
   Int_t           genTau_status[4];   //[ngenTau]
   Int_t           genTau_pdgId[4];   //[ngenTau]
   Float_t         genTau_pt[4];   //[ngenTau]
   Float_t         genTau_eta[4];   //[ngenTau]
   Float_t         genTau_phi[4];   //[ngenTau]
   Float_t         genTau_mass[4];   //[ngenTau]
   Int_t           genTau_motherIndex[4];   //[ngenTau]
   Int_t           nGenTop;
   Int_t           GenTop_pdgId[2];   //[nGenTop]
   Float_t         GenTop_pt[2];   //[nGenTop]
   Float_t         GenTop_eta[2];   //[nGenTop]
   Float_t         GenTop_phi[2];   //[nGenTop]
   Float_t         GenTop_mass[2];   //[nGenTop]
   Float_t         GenTop_charge[2];   //[nGenTop]
   Int_t           GenTop_status[2];   //[nGenTop]
   Int_t           nLepOther;
   Float_t         LepOther_mvaIdPhys14[8];   //[nLepOther]
   Float_t         LepOther_mvaIdSpring15[8];   //[nLepOther]
   Float_t         LepOther_mvaTTH[8];   //[nLepOther]
   Float_t         LepOther_jetPtRatiov1[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelv1[8];   //[nLepOther]
   Float_t         LepOther_jetPtRatiov2[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelv2[8];   //[nLepOther]
   Float_t         LepOther_jetBTagCSV[8];   //[nLepOther]
   Float_t         LepOther_jetBTagCMVA[8];   //[nLepOther]
   Float_t         LepOther_jetDR[8];   //[nLepOther]
   Int_t           LepOther_charge[8];   //[nLepOther]
   Int_t           LepOther_tightId[8];   //[nLepOther]
   Int_t           LepOther_eleCutIdCSA14_25ns_v1[8];   //[nLepOther]
   Int_t           LepOther_eleCutIdCSA14_50ns_v1[8];   //[nLepOther]
   Float_t         LepOther_dxy[8];   //[nLepOther]
   Float_t         LepOther_dz[8];   //[nLepOther]
   Float_t         LepOther_edxy[8];   //[nLepOther]
   Float_t         LepOther_edz[8];   //[nLepOther]
   Float_t         LepOther_ip3d[8];   //[nLepOther]
   Float_t         LepOther_sip3d[8];   //[nLepOther]
   Int_t           LepOther_convVeto[8];   //[nLepOther]
   Int_t           LepOther_lostHits[8];   //[nLepOther]
   Float_t         LepOther_relIso03[8];   //[nLepOther]
   Float_t         LepOther_relIso04[8];   //[nLepOther]
   Float_t         LepOther_miniRelIso[8];   //[nLepOther]
   Float_t         LepOther_relIsoAn04[8];   //[nLepOther]
   Int_t           LepOther_tightCharge[8];   //[nLepOther]
   Int_t           LepOther_mcMatchId[8];   //[nLepOther]
   Int_t           LepOther_mcMatchAny[8];   //[nLepOther]
   Int_t           LepOther_mcMatchTau[8];   //[nLepOther]
   Float_t         LepOther_mcPt[8];   //[nLepOther]
   Int_t           LepOther_mediumMuonId[8];   //[nLepOther]
   Int_t           LepOther_pdgId[8];   //[nLepOther]
   Float_t         LepOther_pt[8];   //[nLepOther]
   Float_t         LepOther_eta[8];   //[nLepOther]
   Float_t         LepOther_phi[8];   //[nLepOther]
   Float_t         LepOther_mass[8];   //[nLepOther]
   Float_t         LepOther_chargedHadRelIso03[8];   //[nLepOther]
   Float_t         LepOther_chargedHadRelIso04[8];   //[nLepOther]
   Int_t           LepOther_softMuonId[8];   //[nLepOther]
   Int_t           LepOther_pfMuonId[8];   //[nLepOther]
   Int_t           LepOther_eleCutId2012_full5x5[8];   //[nLepOther]
   Int_t           LepOther_trackerLayers[8];   //[nLepOther]
   Int_t           LepOther_pixelLayers[8];   //[nLepOther]
   Int_t           LepOther_trackerHits[8];   //[nLepOther]
   Int_t           LepOther_lostOuterHits[8];   //[nLepOther]
   Float_t         LepOther_innerTrackValidHitFraction[8];   //[nLepOther]
   Float_t         LepOther_innerTrackChi2[8];   //[nLepOther]
   Float_t         LepOther_nStations[8];   //[nLepOther]
   Float_t         LepOther_caloCompatibility[8];   //[nLepOther]
   Float_t         LepOther_globalTrackChi2[8];   //[nLepOther]
   Float_t         LepOther_trkKink[8];   //[nLepOther]
   Float_t         LepOther_segmentCompatibility[8];   //[nLepOther]
   Float_t         LepOther_chi2LocalPosition[8];   //[nLepOther]
   Float_t         LepOther_chi2LocalMomentum[8];   //[nLepOther]
   Float_t         LepOther_glbTrackProbability[8];   //[nLepOther]
   Float_t         LepOther_sigmaIEtaIEta[8];   //[nLepOther]
   Float_t         LepOther_dEtaScTrkIn[8];   //[nLepOther]
   Float_t         LepOther_dPhiScTrkIn[8];   //[nLepOther]
   Float_t         LepOther_hadronicOverEm[8];   //[nLepOther]
   Float_t         LepOther_eInvMinusPInv[8];   //[nLepOther]
   Float_t         LepOther_eInvMinusPInv_tkMom[8];   //[nLepOther]
   Float_t         LepOther_etaSc[8];   //[nLepOther]
   Float_t         LepOther_miniRelIsoCharged[8];   //[nLepOther]
   Float_t         LepOther_miniRelIsoNeutral[8];   //[nLepOther]
   Int_t           LepOther_hasSV[8];   //[nLepOther]
   Float_t         LepOther_svRedPt[8];   //[nLepOther]
   Float_t         LepOther_svRedM[8];   //[nLepOther]
   Float_t         LepOther_svLepSip3d[8];   //[nLepOther]
   Float_t         LepOther_svSip3d[8];   //[nLepOther]
   Float_t         LepOther_svNTracks[8];   //[nLepOther]
   Float_t         LepOther_svChi2n[8];   //[nLepOther]
   Float_t         LepOther_svDxy[8];   //[nLepOther]
   Float_t         LepOther_svMass[8];   //[nLepOther]
   Float_t         LepOther_svPt[8];   //[nLepOther]
   Float_t         LepOther_svMCMatchFraction[8];   //[nLepOther]
   Float_t         LepOther_svMva[8];   //[nLepOther]
   Float_t         LepOther_jetNDau[8];   //[nLepOther]
   Float_t         LepOther_jetNDauCharged[8];   //[nLepOther]
   Float_t         LepOther_jetNDauPV[8];   //[nLepOther]
   Float_t         LepOther_jetNDauNotPV[8];   //[nLepOther]
   Float_t         LepOther_jetmaxSignedSip3D[8];   //[nLepOther]
   Float_t         LepOther_jetmaxSip3D[8];   //[nLepOther]
   Float_t         LepOther_jetmaxSignedSip2D[8];   //[nLepOther]
   Float_t         LepOther_jetmaxSip2D[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelv0[8];   //[nLepOther]
   Float_t         LepOther_jetMass[8];   //[nLepOther]
   Float_t         LepOther_jetPrunedMass[8];   //[nLepOther]
   Float_t         LepOther_jetDecDR[8];   //[nLepOther]
   Float_t         LepOther_jetDecPtRel[8];   //[nLepOther]
   Float_t         LepOther_jetDecPtRatio[8];   //[nLepOther]
   Float_t         LepOther_jetDecPrunedMass[8];   //[nLepOther]
   Float_t         LepOther_jetDecPrunedPtRatio[8];   //[nLepOther]
   Float_t         LepOther_jetDec02DR[8];   //[nLepOther]
   Float_t         LepOther_jetDec02PtRel[8];   //[nLepOther]
   Float_t         LepOther_jetDec02PtRatio[8];   //[nLepOther]
   Float_t         LepOther_jetDec02PrunedPtRatio[8];   //[nLepOther]
   Float_t         LepOther_jetDec02PrunedMass[8];   //[nLepOther]
   Float_t         LepOther_jetRawPt[8];   //[nLepOther]
   Float_t         LepOther_jetCorrFactor_L1[8];   //[nLepOther]
   Float_t         LepOther_jetCorrFactor_L1L2[8];   //[nLepOther]
   Float_t         LepOther_jetCorrFactor_L1L2L3[8];   //[nLepOther]
   Float_t         LepOther_jetCorrFactor_L1L2L3Res[8];   //[nLepOther]
   Float_t         LepOther_jetPtRatio_Raw[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelHv2[8];   //[nLepOther]
   Float_t         LepOther_ecalPFClusterIso[8];   //[nLepOther]
   Float_t         LepOther_hcalPFClusterIso[8];   //[nLepOther]
   Float_t         LepOther_dr03TkSumPt[8];   //[nLepOther]
   Float_t         LepOther_trackIso[8];   //[nLepOther]
   Float_t         LepOther_jetLepAwareJEC_pt[8];   //[nLepOther]
   Float_t         LepOther_jetLepAwareJEC_eta[8];   //[nLepOther]
   Float_t         LepOther_jetLepAwareJEC_phi[8];   //[nLepOther]
   Float_t         LepOther_jetLepAwareJEC_energy[8];   //[nLepOther]
   Int_t           ngenLepFromTau;
   Int_t           genLepFromTau_motherId[15];   //[ngenLepFromTau]
   Int_t           genLepFromTau_grandmotherId[15];   //[ngenLepFromTau]
   Int_t           genLepFromTau_sourceId[15];   //[ngenLepFromTau]
   Float_t         genLepFromTau_charge[15];   //[ngenLepFromTau]
   Int_t           genLepFromTau_status[15];   //[ngenLepFromTau]
   Int_t           genLepFromTau_pdgId[15];   //[ngenLepFromTau]
   Float_t         genLepFromTau_pt[15];   //[ngenLepFromTau]
   Float_t         genLepFromTau_eta[15];   //[ngenLepFromTau]
   Float_t         genLepFromTau_phi[15];   //[ngenLepFromTau]
   Float_t         genLepFromTau_mass[15];   //[ngenLepFromTau]
   Int_t           genLepFromTau_motherIndex[15];   //[ngenLepFromTau]
   Int_t           nJetFwd;
   Float_t         JetFwd_area[6];   //[nJetFwd]
   Float_t         JetFwd_qgl[6];   //[nJetFwd]
   Float_t         JetFwd_ptd[6];   //[nJetFwd]
   Float_t         JetFwd_axis2[6];   //[nJetFwd]
   Int_t           JetFwd_mult[6];   //[nJetFwd]
   Int_t           JetFwd_partonId[6];   //[nJetFwd]
   Int_t           JetFwd_partonMotherId[6];   //[nJetFwd]
   Float_t         JetFwd_nLeptons[6];   //[nJetFwd]
   Int_t           JetFwd_id[6];   //[nJetFwd]
   Int_t           JetFwd_puId[6];   //[nJetFwd]
   Float_t         JetFwd_btagCSV[6];   //[nJetFwd]
   Float_t         JetFwd_btagCMVA[6];   //[nJetFwd]
   Float_t         JetFwd_rawPt[6];   //[nJetFwd]
   Float_t         JetFwd_mcPt[6];   //[nJetFwd]
   Int_t           JetFwd_mcFlavour[6];   //[nJetFwd]
   Int_t           JetFwd_mcMatchId[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JECUp[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JECDown[6];   //[nJetFwd]
   Float_t         JetFwd_corr[6];   //[nJetFwd]
   Float_t         JetFwd_pt[6];   //[nJetFwd]
   Float_t         JetFwd_eta[6];   //[nJetFwd]
   Float_t         JetFwd_phi[6];   //[nJetFwd]
   Float_t         JetFwd_mass[6];   //[nJetFwd]
   Int_t           JetFwd_mcMatchFlav[6];   //[nJetFwd]
   Float_t         JetFwd_charge[6];   //[nJetFwd]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoCN;   //!
   TBranch        *b_nVert;   //!
   TBranch        *b_nJet25;   //!
   TBranch        *b_nJet25a;   //!
   TBranch        *b_nBJetLoose25;   //!
   TBranch        *b_nBJetMedium25;   //!
   TBranch        *b_nBJetTight25;   //!
   TBranch        *b_nJet30;   //!
   TBranch        *b_nJet30a;   //!
   TBranch        *b_nBJetLoose30;   //!
   TBranch        *b_nBJetMedium30;   //!
   TBranch        *b_nBJetTight30;   //!
   TBranch        *b_nJet40;   //!
   TBranch        *b_nJet40a;   //!
   TBranch        *b_nBJetLoose40;   //!
   TBranch        *b_nBJetMedium40;   //!
   TBranch        *b_nBJetTight40;   //!
   TBranch        *b_nLepGood20;   //!
   TBranch        *b_nLepGood15;   //!
   TBranch        *b_nLepGood10;   //!
   TBranch        *b_GenSusyMScan1;   //!
   TBranch        *b_GenSusyMScan2;   //!
   TBranch        *b_GenSusyMScan3;   //!
   TBranch        *b_GenSusyMScan4;   //!
   TBranch        *b_GenSusyMGluino;   //!
   TBranch        *b_GenSusyMGravitino;   //!
   TBranch        *b_GenSusyMStop;   //!
   TBranch        *b_GenSusyMSbottom;   //!
   TBranch        *b_GenSusyMStop2;   //!
   TBranch        *b_GenSusyMSbottom2;   //!
   TBranch        *b_GenSusyMSquark;   //!
   TBranch        *b_GenSusyMNeutralino;   //!
   TBranch        *b_GenSusyMNeutralino2;   //!
   TBranch        *b_GenSusyMNeutralino3;   //!
   TBranch        *b_GenSusyMNeutralino4;   //!
   TBranch        *b_GenSusyMChargino;   //!
   TBranch        *b_GenSusyMChargino2;   //!
   TBranch        *b_htJet25;   //!
   TBranch        *b_mhtJet25;   //!
   TBranch        *b_htJet40j;   //!
   TBranch        *b_htJet40ja;   //!
   TBranch        *b_htJet40;   //!
   TBranch        *b_htJet40a;   //!
   TBranch        *b_mhtJet40;   //!
   TBranch        *b_mhtJet40a;   //!
   TBranch        *b_nJet25NoTau;   //!
   TBranch        *b_nBJetLoose25NoTau;   //!
   TBranch        *b_nBJetMedium25NoTau;   //!
   TBranch        *b_nBJetCMVALoose25;   //!
   TBranch        *b_nBJetCMVAMedium25;   //!
   TBranch        *b_nBJetCMVATight25;   //!
   TBranch        *b_nSoftBLoose25;   //!
   TBranch        *b_nSoftBMedium25;   //!
   TBranch        *b_nSoftBTight25;   //!
   TBranch        *b_nJet30NoTau;   //!
   TBranch        *b_nBJetLoose30NoTau;   //!
   TBranch        *b_nBJetMedium30NoTau;   //!
   TBranch        *b_nJet40NoTau;   //!
   TBranch        *b_nBJetLoose40NoTau;   //!
   TBranch        *b_nBJetMedium40NoTau;   //!
   TBranch        *b_nBJetCMVALoose40;   //!
   TBranch        *b_nBJetCMVAMedium40;   //!
   TBranch        *b_nBJetCMVATight40;   //!
   TBranch        *b_mZ1;   //!
   TBranch        *b_mZ1SFSS;   //!
   TBranch        *b_minMllSFOS;   //!
   TBranch        *b_maxMllSFOS;   //!
   TBranch        *b_minMllAFOS;   //!
   TBranch        *b_maxMllAFOS;   //!
   TBranch        *b_minMllAFSS;   //!
   TBranch        *b_maxMllAFSS;   //!
   TBranch        *b_minMllAFAS;   //!
   TBranch        *b_maxMllAFAS;   //!
   TBranch        *b_m2l;   //!
   TBranch        *b_minDrllAFSS;   //!
   TBranch        *b_maxDrllAFSS;   //!
   TBranch        *b_minDrllAFOS;   //!
   TBranch        *b_maxDrllAFOS;   //!
   TBranch        *b_mZ2;   //!
   TBranch        *b_m3l;   //!
   TBranch        *b_m4l;   //!
   TBranch        *b_pt2l;   //!
   TBranch        *b_pt3l;   //!
   TBranch        *b_pt4l;   //!
   TBranch        *b_ht3l;   //!
   TBranch        *b_ht4l;   //!
   TBranch        *b_q3l;   //!
   TBranch        *b_q4l;   //!
   TBranch        *b_minMWjj;   //!
   TBranch        *b_minMWjjPt;   //!
   TBranch        *b_bestMWjj;   //!
   TBranch        *b_bestMWjjPt;   //!
   TBranch        *b_bestMTopHad;   //!
   TBranch        *b_bestMTopHadPt;   //!
   TBranch        *b_GenHiggsDecayMode;   //!
   TBranch        *b_absIP3DAval;   //!
   TBranch        *b_absIP3DAerr;   //!
   TBranch        *b_absIP3DBval;   //!
   TBranch        *b_absIP3DBerr;   //!
   TBranch        *b_absIP3DCval;   //!
   TBranch        *b_absIP3DCerr;   //!
   TBranch        *b_absIP3DDval;   //!
   TBranch        *b_absIP3DDerr;   //!
   TBranch        *b_absIP3DApvBCval;   //!
   TBranch        *b_absIP3DApvBCerr;   //!
   TBranch        *b_absIP3DBpvACval;   //!
   TBranch        *b_absIP3DBpvACerr;   //!
   TBranch        *b_absIP3DCpvABval;   //!
   TBranch        *b_absIP3DCpvABerr;   //!
   TBranch        *b_absIP3DApvBCDval;   //!
   TBranch        *b_absIP3DApvBCDerr;   //!
   TBranch        *b_absIP3DBpvACDval;   //!
   TBranch        *b_absIP3DBpvACDerr;   //!
   TBranch        *b_absIP3DCpvABDval;   //!
   TBranch        *b_absIP3DCpvABDerr;   //!
   TBranch        *b_absIP3DDpvABCval;   //!
   TBranch        *b_absIP3DDpvABCerr;   //!
   TBranch        *b_chi2pvtrksBCbutAval;   //!
   TBranch        *b_chi2pvtrksBCbutAdof;   //!
   TBranch        *b_chi2pvtrksACbutBval;   //!
   TBranch        *b_chi2pvtrksACbutBdof;   //!
   TBranch        *b_chi2pvtrksABbutCval;   //!
   TBranch        *b_chi2pvtrksABbutCdof;   //!
   TBranch        *b_chi2pvtrksBCDbutAval;   //!
   TBranch        *b_chi2pvtrksBCDbutAdof;   //!
   TBranch        *b_chi2pvtrksACDbutBval;   //!
   TBranch        *b_chi2pvtrksACDbutBdof;   //!
   TBranch        *b_chi2pvtrksABDbutCval;   //!
   TBranch        *b_chi2pvtrksABDbutCdof;   //!
   TBranch        *b_chi2pvtrksABCbutDval;   //!
   TBranch        *b_chi2pvtrksABCbutDdof;   //!
   TBranch        *b_nRecJet40;   //!
   TBranch        *b_nRecJet25;   //!
   TBranch        *b_nRecBJetMedium40;   //!
   TBranch        *b_nRecBJetMedium25;   //!
   TBranch        *b_nRecSplitJet40;   //!
   TBranch        *b_nRecSplitJet25;   //!
   TBranch        *b_nRecSplitBJetMedium40;   //!
   TBranch        *b_nRecSplitBJetMedium25;   //!
   TBranch        *b_hbheFilterNew50ns;   //!
   TBranch        *b_hbheFilterNew25ns;   //!
   TBranch        *b_hbheFilterIso;   //!
   TBranch        *b_met_trkPt;   //!
   TBranch        *b_met_trkPhi;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleElHT;   //!
   TBranch        *b_HLT_DoubleElHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleEl;   //!
   TBranch        *b_HLT_TripleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_MuEGHT;   //!
   TBranch        *b_HLT_MuEGHT_isUnprescaled;   //!
   TBranch        *b_HLT_MonoJet80MET90;   //!
   TBranch        *b_HLT_MonoJet80MET90_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled;   //!
   TBranch        *b_HLT_SingleMu;   //!
   TBranch        *b_HLT_SingleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuEl;   //!
   TBranch        *b_HLT_DoubleMuEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_MonoJet80MET120;   //!
   TBranch        *b_HLT_MonoJet80MET120_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleMu;   //!
   TBranch        *b_HLT_TripleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleElMu;   //!
   TBranch        *b_HLT_DoubleElMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuNoIso;   //!
   TBranch        *b_HLT_DoubleMuNoIso_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuSS;   //!
   TBranch        *b_HLT_DoubleMuSS_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WP85_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_SingleEl;   //!
   TBranch        *b_HLT_SingleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;   //!
   TBranch        *b_HLT_TripleMuA;   //!
   TBranch        *b_HLT_TripleMuA_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_MuEG;   //!
   TBranch        *b_HLT_MuEG_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMuHT;   //!
   TBranch        *b_HLT_DoubleMuHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleEl;   //!
   TBranch        *b_HLT_DoubleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_DoubleMu;   //!
   TBranch        *b_HLT_DoubleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled;   //!
   TBranch        *b_HLT_METMu5;   //!
   TBranch        *b_HLT_METMu5_isUnprescaled;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_eta;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_mass;   //!
   TBranch        *b_met_sumEt;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_rawSumEt;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_met_genEta;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_id;   //!
   TBranch        *b_FatJet_puId;   //!
   TBranch        *b_FatJet_btagCSV;   //!
   TBranch        *b_FatJet_btagCMVA;   //!
   TBranch        *b_FatJet_rawPt;   //!
   TBranch        *b_FatJet_mcPt;   //!
   TBranch        *b_FatJet_mcFlavour;   //!
   TBranch        *b_FatJet_mcMatchId;   //!
   TBranch        *b_FatJet_corr_JECUp;   //!
   TBranch        *b_FatJet_corr_JECDown;   //!
   TBranch        *b_FatJet_corr;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_prunedMass;   //!
   TBranch        *b_FatJet_trimmedMass;   //!
   TBranch        *b_FatJet_filteredMass;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_topMass;   //!
   TBranch        *b_FatJet_minMass;   //!
   TBranch        *b_FatJet_nSubJets;   //!
   TBranch        *b_nDiscLep;   //!
   TBranch        *b_DiscLep_mvaIdPhys14;   //!
   TBranch        *b_DiscLep_mvaIdSpring15;   //!
   TBranch        *b_DiscLep_mvaTTH;   //!
   TBranch        *b_DiscLep_jetPtRatiov1;   //!
   TBranch        *b_DiscLep_jetPtRelv1;   //!
   TBranch        *b_DiscLep_jetPtRatiov2;   //!
   TBranch        *b_DiscLep_jetPtRelv2;   //!
   TBranch        *b_DiscLep_jetBTagCSV;   //!
   TBranch        *b_DiscLep_jetBTagCMVA;   //!
   TBranch        *b_DiscLep_jetDR;   //!
   TBranch        *b_DiscLep_charge;   //!
   TBranch        *b_DiscLep_tightId;   //!
   TBranch        *b_DiscLep_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_DiscLep_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_DiscLep_dxy;   //!
   TBranch        *b_DiscLep_dz;   //!
   TBranch        *b_DiscLep_edxy;   //!
   TBranch        *b_DiscLep_edz;   //!
   TBranch        *b_DiscLep_ip3d;   //!
   TBranch        *b_DiscLep_sip3d;   //!
   TBranch        *b_DiscLep_convVeto;   //!
   TBranch        *b_DiscLep_lostHits;   //!
   TBranch        *b_DiscLep_relIso03;   //!
   TBranch        *b_DiscLep_relIso04;   //!
   TBranch        *b_DiscLep_miniRelIso;   //!
   TBranch        *b_DiscLep_relIsoAn04;   //!
   TBranch        *b_DiscLep_tightCharge;   //!
   TBranch        *b_DiscLep_mcMatchId;   //!
   TBranch        *b_DiscLep_mcMatchAny;   //!
   TBranch        *b_DiscLep_mcMatchTau;   //!
   TBranch        *b_DiscLep_mcPt;   //!
   TBranch        *b_DiscLep_mediumMuonId;   //!
   TBranch        *b_DiscLep_pdgId;   //!
   TBranch        *b_DiscLep_pt;   //!
   TBranch        *b_DiscLep_eta;   //!
   TBranch        *b_DiscLep_phi;   //!
   TBranch        *b_DiscLep_mass;   //!
   TBranch        *b_DiscLep_chargedHadRelIso03;   //!
   TBranch        *b_DiscLep_chargedHadRelIso04;   //!
   TBranch        *b_DiscLep_softMuonId;   //!
   TBranch        *b_DiscLep_pfMuonId;   //!
   TBranch        *b_DiscLep_eleCutId2012_full5x5;   //!
   TBranch        *b_DiscLep_trackerLayers;   //!
   TBranch        *b_DiscLep_pixelLayers;   //!
   TBranch        *b_DiscLep_trackerHits;   //!
   TBranch        *b_DiscLep_lostOuterHits;   //!
   TBranch        *b_DiscLep_innerTrackValidHitFraction;   //!
   TBranch        *b_DiscLep_innerTrackChi2;   //!
   TBranch        *b_DiscLep_nStations;   //!
   TBranch        *b_DiscLep_caloCompatibility;   //!
   TBranch        *b_DiscLep_globalTrackChi2;   //!
   TBranch        *b_DiscLep_trkKink;   //!
   TBranch        *b_DiscLep_segmentCompatibility;   //!
   TBranch        *b_DiscLep_chi2LocalPosition;   //!
   TBranch        *b_DiscLep_chi2LocalMomentum;   //!
   TBranch        *b_DiscLep_glbTrackProbability;   //!
   TBranch        *b_DiscLep_sigmaIEtaIEta;   //!
   TBranch        *b_DiscLep_dEtaScTrkIn;   //!
   TBranch        *b_DiscLep_dPhiScTrkIn;   //!
   TBranch        *b_DiscLep_hadronicOverEm;   //!
   TBranch        *b_DiscLep_eInvMinusPInv;   //!
   TBranch        *b_DiscLep_eInvMinusPInv_tkMom;   //!
   TBranch        *b_DiscLep_etaSc;   //!
   TBranch        *b_DiscLep_miniRelIsoCharged;   //!
   TBranch        *b_DiscLep_miniRelIsoNeutral;   //!
   TBranch        *b_DiscLep_hasSV;   //!
   TBranch        *b_DiscLep_svRedPt;   //!
   TBranch        *b_DiscLep_svRedM;   //!
   TBranch        *b_DiscLep_svLepSip3d;   //!
   TBranch        *b_DiscLep_svSip3d;   //!
   TBranch        *b_DiscLep_svNTracks;   //!
   TBranch        *b_DiscLep_svChi2n;   //!
   TBranch        *b_DiscLep_svDxy;   //!
   TBranch        *b_DiscLep_svMass;   //!
   TBranch        *b_DiscLep_svPt;   //!
   TBranch        *b_DiscLep_svMCMatchFraction;   //!
   TBranch        *b_DiscLep_svMva;   //!
   TBranch        *b_DiscLep_jetNDau;   //!
   TBranch        *b_DiscLep_jetNDauCharged;   //!
   TBranch        *b_DiscLep_jetNDauPV;   //!
   TBranch        *b_DiscLep_jetNDauNotPV;   //!
   TBranch        *b_DiscLep_jetmaxSignedSip3D;   //!
   TBranch        *b_DiscLep_jetmaxSip3D;   //!
   TBranch        *b_DiscLep_jetmaxSignedSip2D;   //!
   TBranch        *b_DiscLep_jetmaxSip2D;   //!
   TBranch        *b_DiscLep_jetPtRelv0;   //!
   TBranch        *b_DiscLep_jetMass;   //!
   TBranch        *b_DiscLep_jetPrunedMass;   //!
   TBranch        *b_DiscLep_jetDecDR;   //!
   TBranch        *b_DiscLep_jetDecPtRel;   //!
   TBranch        *b_DiscLep_jetDecPtRatio;   //!
   TBranch        *b_DiscLep_jetDecPrunedMass;   //!
   TBranch        *b_DiscLep_jetDecPrunedPtRatio;   //!
   TBranch        *b_DiscLep_jetDec02DR;   //!
   TBranch        *b_DiscLep_jetDec02PtRel;   //!
   TBranch        *b_DiscLep_jetDec02PtRatio;   //!
   TBranch        *b_DiscLep_jetDec02PrunedPtRatio;   //!
   TBranch        *b_DiscLep_jetDec02PrunedMass;   //!
   TBranch        *b_DiscLep_jetRawPt;   //!
   TBranch        *b_DiscLep_jetCorrFactor_L1;   //!
   TBranch        *b_DiscLep_jetCorrFactor_L1L2;   //!
   TBranch        *b_DiscLep_jetCorrFactor_L1L2L3;   //!
   TBranch        *b_DiscLep_jetCorrFactor_L1L2L3Res;   //!
   TBranch        *b_DiscLep_jetPtRatio_Raw;   //!
   TBranch        *b_DiscLep_jetPtRelHv2;   //!
   TBranch        *b_DiscLep_ecalPFClusterIso;   //!
   TBranch        *b_DiscLep_hcalPFClusterIso;   //!
   TBranch        *b_DiscLep_dr03TkSumPt;   //!
   TBranch        *b_DiscLep_trackIso;   //!
   TBranch        *b_DiscLep_jetLepAwareJEC_pt;   //!
   TBranch        *b_DiscLep_jetLepAwareJEC_eta;   //!
   TBranch        *b_DiscLep_jetLepAwareJEC_phi;   //!
   TBranch        *b_DiscLep_jetLepAwareJEC_energy;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_motherId;   //!
   TBranch        *b_GenPart_grandmotherId;   //!
   TBranch        *b_GenPart_sourceId;   //!
   TBranch        *b_GenPart_charge;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_motherIndex;   //!
   TBranch        *b_nDiscJet;   //!
   TBranch        *b_DiscJet_area;   //!
   TBranch        *b_DiscJet_qgl;   //!
   TBranch        *b_DiscJet_ptd;   //!
   TBranch        *b_DiscJet_axis2;   //!
   TBranch        *b_DiscJet_mult;   //!
   TBranch        *b_DiscJet_partonId;   //!
   TBranch        *b_DiscJet_partonMotherId;   //!
   TBranch        *b_DiscJet_nLeptons;   //!
   TBranch        *b_DiscJet_id;   //!
   TBranch        *b_DiscJet_puId;   //!
   TBranch        *b_DiscJet_btagCSV;   //!
   TBranch        *b_DiscJet_btagCMVA;   //!
   TBranch        *b_DiscJet_rawPt;   //!
   TBranch        *b_DiscJet_mcPt;   //!
   TBranch        *b_DiscJet_mcFlavour;   //!
   TBranch        *b_DiscJet_mcMatchId;   //!
   TBranch        *b_DiscJet_corr_JECUp;   //!
   TBranch        *b_DiscJet_corr_JECDown;   //!
   TBranch        *b_DiscJet_corr;   //!
   TBranch        *b_DiscJet_pt;   //!
   TBranch        *b_DiscJet_eta;   //!
   TBranch        *b_DiscJet_phi;   //!
   TBranch        *b_DiscJet_mass;   //!
   TBranch        *b_DiscJet_mcMatchFlav;   //!
   TBranch        *b_DiscJet_charge;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_charge;   //!
   TBranch        *b_SV_ntracks;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_dxy;   //!
   TBranch        *b_SV_edxy;   //!
   TBranch        *b_SV_ip3d;   //!
   TBranch        *b_SV_eip3d;   //!
   TBranch        *b_SV_sip3d;   //!
   TBranch        *b_SV_cosTheta;   //!
   TBranch        *b_SV_mva;   //!
   TBranch        *b_SV_jetPt;   //!
   TBranch        *b_SV_jetBTagCSV;   //!
   TBranch        *b_SV_jetBTagCMVA;   //!
   TBranch        *b_SV_mcMatchNTracks;   //!
   TBranch        *b_SV_mcMatchNTracksHF;   //!
   TBranch        *b_SV_mcMatchFraction;   //!
   TBranch        *b_SV_mcFlavFirst;   //!
   TBranch        *b_SV_mcFlavHeaviest;   //!
   TBranch        *b_SV_maxDxyTracks;   //!
   TBranch        *b_SV_secDxyTracks;   //!
   TBranch        *b_SV_maxD3dTracks;   //!
   TBranch        *b_SV_secD3dTracks;   //!
   TBranch        *b_nLepGood;   //!
   TBranch        *b_LepGood_mvaIdPhys14;   //!
   TBranch        *b_LepGood_mvaIdSpring15;   //!
   TBranch        *b_LepGood_mvaTTH;   //!
   TBranch        *b_LepGood_jetPtRatiov1;   //!
   TBranch        *b_LepGood_jetPtRelv1;   //!
   TBranch        *b_LepGood_jetPtRatiov2;   //!
   TBranch        *b_LepGood_jetPtRelv2;   //!
   TBranch        *b_LepGood_jetBTagCSV;   //!
   TBranch        *b_LepGood_jetBTagCMVA;   //!
   TBranch        *b_LepGood_jetDR;   //!
   TBranch        *b_LepGood_charge;   //!
   TBranch        *b_LepGood_tightId;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_LepGood_dxy;   //!
   TBranch        *b_LepGood_dz;   //!
   TBranch        *b_LepGood_edxy;   //!
   TBranch        *b_LepGood_edz;   //!
   TBranch        *b_LepGood_ip3d;   //!
   TBranch        *b_LepGood_sip3d;   //!
   TBranch        *b_LepGood_convVeto;   //!
   TBranch        *b_LepGood_lostHits;   //!
   TBranch        *b_LepGood_relIso03;   //!
   TBranch        *b_LepGood_relIso04;   //!
   TBranch        *b_LepGood_miniRelIso;   //!
   TBranch        *b_LepGood_relIsoAn04;   //!
   TBranch        *b_LepGood_tightCharge;   //!
   TBranch        *b_LepGood_mcMatchId;   //!
   TBranch        *b_LepGood_mcMatchAny;   //!
   TBranch        *b_LepGood_mcMatchTau;   //!
   TBranch        *b_LepGood_mcPt;   //!
   TBranch        *b_LepGood_mediumMuonId;   //!
   TBranch        *b_LepGood_pdgId;   //!
   TBranch        *b_LepGood_pt;   //!
   TBranch        *b_LepGood_eta;   //!
   TBranch        *b_LepGood_phi;   //!
   TBranch        *b_LepGood_mass;   //!
   TBranch        *b_LepGood_chargedHadRelIso03;   //!
   TBranch        *b_LepGood_chargedHadRelIso04;   //!
   TBranch        *b_LepGood_softMuonId;   //!
   TBranch        *b_LepGood_pfMuonId;   //!
   TBranch        *b_LepGood_eleCutId2012_full5x5;   //!
   TBranch        *b_LepGood_trackerLayers;   //!
   TBranch        *b_LepGood_pixelLayers;   //!
   TBranch        *b_LepGood_trackerHits;   //!
   TBranch        *b_LepGood_lostOuterHits;   //!
   TBranch        *b_LepGood_innerTrackValidHitFraction;   //!
   TBranch        *b_LepGood_innerTrackChi2;   //!
   TBranch        *b_LepGood_nStations;   //!
   TBranch        *b_LepGood_caloCompatibility;   //!
   TBranch        *b_LepGood_globalTrackChi2;   //!
   TBranch        *b_LepGood_trkKink;   //!
   TBranch        *b_LepGood_segmentCompatibility;   //!
   TBranch        *b_LepGood_chi2LocalPosition;   //!
   TBranch        *b_LepGood_chi2LocalMomentum;   //!
   TBranch        *b_LepGood_glbTrackProbability;   //!
   TBranch        *b_LepGood_sigmaIEtaIEta;   //!
   TBranch        *b_LepGood_dEtaScTrkIn;   //!
   TBranch        *b_LepGood_dPhiScTrkIn;   //!
   TBranch        *b_LepGood_hadronicOverEm;   //!
   TBranch        *b_LepGood_eInvMinusPInv;   //!
   TBranch        *b_LepGood_eInvMinusPInv_tkMom;   //!
   TBranch        *b_LepGood_etaSc;   //!
   TBranch        *b_LepGood_miniRelIsoCharged;   //!
   TBranch        *b_LepGood_miniRelIsoNeutral;   //!
   TBranch        *b_LepGood_hasSV;   //!
   TBranch        *b_LepGood_svRedPt;   //!
   TBranch        *b_LepGood_svRedM;   //!
   TBranch        *b_LepGood_svLepSip3d;   //!
   TBranch        *b_LepGood_svSip3d;   //!
   TBranch        *b_LepGood_svNTracks;   //!
   TBranch        *b_LepGood_svChi2n;   //!
   TBranch        *b_LepGood_svDxy;   //!
   TBranch        *b_LepGood_svMass;   //!
   TBranch        *b_LepGood_svPt;   //!
   TBranch        *b_LepGood_svMCMatchFraction;   //!
   TBranch        *b_LepGood_svMva;   //!
   TBranch        *b_LepGood_jetNDau;   //!
   TBranch        *b_LepGood_jetNDauCharged;   //!
   TBranch        *b_LepGood_jetNDauPV;   //!
   TBranch        *b_LepGood_jetNDauNotPV;   //!
   TBranch        *b_LepGood_jetmaxSignedSip3D;   //!
   TBranch        *b_LepGood_jetmaxSip3D;   //!
   TBranch        *b_LepGood_jetmaxSignedSip2D;   //!
   TBranch        *b_LepGood_jetmaxSip2D;   //!
   TBranch        *b_LepGood_jetPtRelv0;   //!
   TBranch        *b_LepGood_jetMass;   //!
   TBranch        *b_LepGood_jetPrunedMass;   //!
   TBranch        *b_LepGood_jetDecDR;   //!
   TBranch        *b_LepGood_jetDecPtRel;   //!
   TBranch        *b_LepGood_jetDecPtRatio;   //!
   TBranch        *b_LepGood_jetDecPrunedMass;   //!
   TBranch        *b_LepGood_jetDecPrunedPtRatio;   //!
   TBranch        *b_LepGood_jetDec02DR;   //!
   TBranch        *b_LepGood_jetDec02PtRel;   //!
   TBranch        *b_LepGood_jetDec02PtRatio;   //!
   TBranch        *b_LepGood_jetDec02PrunedPtRatio;   //!
   TBranch        *b_LepGood_jetDec02PrunedMass;   //!
   TBranch        *b_LepGood_jetRawPt;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3Res;   //!
   TBranch        *b_LepGood_jetPtRatio_Raw;   //!
   TBranch        *b_LepGood_jetPtRelHv2;   //!
   TBranch        *b_LepGood_ecalPFClusterIso;   //!
   TBranch        *b_LepGood_hcalPFClusterIso;   //!
   TBranch        *b_LepGood_dr03TkSumPt;   //!
   TBranch        *b_LepGood_trackIso;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_pt;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_eta;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_phi;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_energy;   //!
   TBranch        *b_nGenDHad;   //!
   TBranch        *b_GenDHad_charge;   //!
   TBranch        *b_GenDHad_status;   //!
   TBranch        *b_GenDHad_pdgId;   //!
   TBranch        *b_GenDHad_pt;   //!
   TBranch        *b_GenDHad_eta;   //!
   TBranch        *b_GenDHad_phi;   //!
   TBranch        *b_GenDHad_mass;   //!
   TBranch        *b_GenDHad_flav;   //!
   TBranch        *b_GenDHad_sourceId;   //!
   TBranch        *b_GenDHad_svMass;   //!
   TBranch        *b_GenDHad_svPt;   //!
   TBranch        *b_GenDHad_svCharge;   //!
   TBranch        *b_GenDHad_svNtracks;   //!
   TBranch        *b_GenDHad_svChi2;   //!
   TBranch        *b_GenDHad_svNdof;   //!
   TBranch        *b_GenDHad_svDxy;   //!
   TBranch        *b_GenDHad_svEdxy;   //!
   TBranch        *b_GenDHad_svIp3d;   //!
   TBranch        *b_GenDHad_svEip3d;   //!
   TBranch        *b_GenDHad_svSip3d;   //!
   TBranch        *b_GenDHad_svCosTheta;   //!
   TBranch        *b_GenDHad_svMva;   //!
   TBranch        *b_GenDHad_jetPt;   //!
   TBranch        *b_GenDHad_jetBTagCSV;   //!
   TBranch        *b_GenDHad_jetBTagCMVA;   //!
   TBranch        *b_nGenBHad;   //!
   TBranch        *b_GenBHad_charge;   //!
   TBranch        *b_GenBHad_status;   //!
   TBranch        *b_GenBHad_pdgId;   //!
   TBranch        *b_GenBHad_pt;   //!
   TBranch        *b_GenBHad_eta;   //!
   TBranch        *b_GenBHad_phi;   //!
   TBranch        *b_GenBHad_mass;   //!
   TBranch        *b_GenBHad_flav;   //!
   TBranch        *b_GenBHad_sourceId;   //!
   TBranch        *b_GenBHad_svMass;   //!
   TBranch        *b_GenBHad_svPt;   //!
   TBranch        *b_GenBHad_svCharge;   //!
   TBranch        *b_GenBHad_svNtracks;   //!
   TBranch        *b_GenBHad_svChi2;   //!
   TBranch        *b_GenBHad_svNdof;   //!
   TBranch        *b_GenBHad_svDxy;   //!
   TBranch        *b_GenBHad_svEdxy;   //!
   TBranch        *b_GenBHad_svIp3d;   //!
   TBranch        *b_GenBHad_svEip3d;   //!
   TBranch        *b_GenBHad_svSip3d;   //!
   TBranch        *b_GenBHad_svCosTheta;   //!
   TBranch        *b_GenBHad_svMva;   //!
   TBranch        *b_GenBHad_jetPt;   //!
   TBranch        *b_GenBHad_jetBTagCSV;   //!
   TBranch        *b_GenBHad_jetBTagCMVA;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_mcMatchFlav;   //!
   TBranch        *b_Jet_charge;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_ptd;   //!
   TBranch        *b_Jet_axis2;   //!
   TBranch        *b_Jet_mult;   //!
   TBranch        *b_Jet_partonId;   //!
   TBranch        *b_Jet_partonMotherId;   //!
   TBranch        *b_Jet_nLeptons;   //!
   TBranch        *b_Jet_id;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_rawPt;   //!
   TBranch        *b_Jet_mcPt;   //!
   TBranch        *b_Jet_mcFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_corr_JECUp;   //!
   TBranch        *b_Jet_corr_JECDown;   //!
   TBranch        *b_Jet_corr;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_prunedMass;   //!
   TBranch        *b_Jet_mcNumPartons;   //!
   TBranch        *b_Jet_mcNumLeptons;   //!
   TBranch        *b_Jet_mcNumTaus;   //!
   TBranch        *b_Jet_mcAnyPartonMass;   //!
   TBranch        *b_Jet_nSubJets;   //!
   TBranch        *b_Jet_nSubJets25;   //!
   TBranch        *b_Jet_nSubJets30;   //!
   TBranch        *b_Jet_nSubJets40;   //!
   TBranch        *b_Jet_nSubJetsZ01;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_phEF;   //!
   TBranch        *b_Jet_eEF;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_HFHEF;   //!
   TBranch        *b_Jet_HFEMEF;   //!
   TBranch        *b_Jet_chHMult;   //!
   TBranch        *b_Jet_neHMult;   //!
   TBranch        *b_Jet_phMult;   //!
   TBranch        *b_Jet_eMult;   //!
   TBranch        *b_Jet_muMult;   //!
   TBranch        *b_Jet_HFHMult;   //!
   TBranch        *b_Jet_HFEMMult;   //!
   TBranch        *b_Jet_CorrFactor_L1;   //!
   TBranch        *b_Jet_CorrFactor_L1L2;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nJetNoTauIdx;   //!
   TBranch        *b_JetNoTauIdx;   //!
   TBranch        *b_nLHEweight;   //!
   TBranch        *b_LHEweight_id;   //!
   TBranch        *b_LHEweight_wgt;   //!
   TBranch        *b_nTauGood;   //!
   TBranch        *b_TauGood_charge;   //!
   TBranch        *b_TauGood_decayMode;   //!
   TBranch        *b_TauGood_idDecayMode;   //!
   TBranch        *b_TauGood_idDecayModeNewDMs;   //!
   TBranch        *b_TauGood_dxy;   //!
   TBranch        *b_TauGood_dz;   //!
   TBranch        *b_TauGood_idMVA;   //!
   TBranch        *b_TauGood_idMVANewDM;   //!
   TBranch        *b_TauGood_idCI3hit;   //!
   TBranch        *b_TauGood_idAntiMu;   //!
   TBranch        *b_TauGood_idAntiE;   //!
   TBranch        *b_TauGood_isoCI3hit;   //!
   TBranch        *b_TauGood_mcMatchId;   //!
   TBranch        *b_TauGood_pdgId;   //!
   TBranch        *b_TauGood_pt;   //!
   TBranch        *b_TauGood_eta;   //!
   TBranch        *b_TauGood_phi;   //!
   TBranch        *b_TauGood_mass;   //!
   TBranch        *b_ngenLep;   //!
   TBranch        *b_genLep_motherId;   //!
   TBranch        *b_genLep_grandmotherId;   //!
   TBranch        *b_genLep_sourceId;   //!
   TBranch        *b_genLep_charge;   //!
   TBranch        *b_genLep_status;   //!
   TBranch        *b_genLep_pdgId;   //!
   TBranch        *b_genLep_pt;   //!
   TBranch        *b_genLep_eta;   //!
   TBranch        *b_genLep_phi;   //!
   TBranch        *b_genLep_mass;   //!
   TBranch        *b_genLep_motherIndex;   //!
   TBranch        *b_ngenTau;   //!
   TBranch        *b_genTau_motherId;   //!
   TBranch        *b_genTau_grandmotherId;   //!
   TBranch        *b_genTau_sourceId;   //!
   TBranch        *b_genTau_charge;   //!
   TBranch        *b_genTau_status;   //!
   TBranch        *b_genTau_pdgId;   //!
   TBranch        *b_genTau_pt;   //!
   TBranch        *b_genTau_eta;   //!
   TBranch        *b_genTau_phi;   //!
   TBranch        *b_genTau_mass;   //!
   TBranch        *b_genTau_motherIndex;   //!
   TBranch        *b_nGenTop;   //!
   TBranch        *b_GenTop_pdgId;   //!
   TBranch        *b_GenTop_pt;   //!
   TBranch        *b_GenTop_eta;   //!
   TBranch        *b_GenTop_phi;   //!
   TBranch        *b_GenTop_mass;   //!
   TBranch        *b_GenTop_charge;   //!
   TBranch        *b_GenTop_status;   //!
   TBranch        *b_nLepOther;   //!
   TBranch        *b_LepOther_mvaIdPhys14;   //!
   TBranch        *b_LepOther_mvaIdSpring15;   //!
   TBranch        *b_LepOther_mvaTTH;   //!
   TBranch        *b_LepOther_jetPtRatiov1;   //!
   TBranch        *b_LepOther_jetPtRelv1;   //!
   TBranch        *b_LepOther_jetPtRatiov2;   //!
   TBranch        *b_LepOther_jetPtRelv2;   //!
   TBranch        *b_LepOther_jetBTagCSV;   //!
   TBranch        *b_LepOther_jetBTagCMVA;   //!
   TBranch        *b_LepOther_jetDR;   //!
   TBranch        *b_LepOther_charge;   //!
   TBranch        *b_LepOther_tightId;   //!
   TBranch        *b_LepOther_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_LepOther_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_LepOther_dxy;   //!
   TBranch        *b_LepOther_dz;   //!
   TBranch        *b_LepOther_edxy;   //!
   TBranch        *b_LepOther_edz;   //!
   TBranch        *b_LepOther_ip3d;   //!
   TBranch        *b_LepOther_sip3d;   //!
   TBranch        *b_LepOther_convVeto;   //!
   TBranch        *b_LepOther_lostHits;   //!
   TBranch        *b_LepOther_relIso03;   //!
   TBranch        *b_LepOther_relIso04;   //!
   TBranch        *b_LepOther_miniRelIso;   //!
   TBranch        *b_LepOther_relIsoAn04;   //!
   TBranch        *b_LepOther_tightCharge;   //!
   TBranch        *b_LepOther_mcMatchId;   //!
   TBranch        *b_LepOther_mcMatchAny;   //!
   TBranch        *b_LepOther_mcMatchTau;   //!
   TBranch        *b_LepOther_mcPt;   //!
   TBranch        *b_LepOther_mediumMuonId;   //!
   TBranch        *b_LepOther_pdgId;   //!
   TBranch        *b_LepOther_pt;   //!
   TBranch        *b_LepOther_eta;   //!
   TBranch        *b_LepOther_phi;   //!
   TBranch        *b_LepOther_mass;   //!
   TBranch        *b_LepOther_chargedHadRelIso03;   //!
   TBranch        *b_LepOther_chargedHadRelIso04;   //!
   TBranch        *b_LepOther_softMuonId;   //!
   TBranch        *b_LepOther_pfMuonId;   //!
   TBranch        *b_LepOther_eleCutId2012_full5x5;   //!
   TBranch        *b_LepOther_trackerLayers;   //!
   TBranch        *b_LepOther_pixelLayers;   //!
   TBranch        *b_LepOther_trackerHits;   //!
   TBranch        *b_LepOther_lostOuterHits;   //!
   TBranch        *b_LepOther_innerTrackValidHitFraction;   //!
   TBranch        *b_LepOther_innerTrackChi2;   //!
   TBranch        *b_LepOther_nStations;   //!
   TBranch        *b_LepOther_caloCompatibility;   //!
   TBranch        *b_LepOther_globalTrackChi2;   //!
   TBranch        *b_LepOther_trkKink;   //!
   TBranch        *b_LepOther_segmentCompatibility;   //!
   TBranch        *b_LepOther_chi2LocalPosition;   //!
   TBranch        *b_LepOther_chi2LocalMomentum;   //!
   TBranch        *b_LepOther_glbTrackProbability;   //!
   TBranch        *b_LepOther_sigmaIEtaIEta;   //!
   TBranch        *b_LepOther_dEtaScTrkIn;   //!
   TBranch        *b_LepOther_dPhiScTrkIn;   //!
   TBranch        *b_LepOther_hadronicOverEm;   //!
   TBranch        *b_LepOther_eInvMinusPInv;   //!
   TBranch        *b_LepOther_eInvMinusPInv_tkMom;   //!
   TBranch        *b_LepOther_etaSc;   //!
   TBranch        *b_LepOther_miniRelIsoCharged;   //!
   TBranch        *b_LepOther_miniRelIsoNeutral;   //!
   TBranch        *b_LepOther_hasSV;   //!
   TBranch        *b_LepOther_svRedPt;   //!
   TBranch        *b_LepOther_svRedM;   //!
   TBranch        *b_LepOther_svLepSip3d;   //!
   TBranch        *b_LepOther_svSip3d;   //!
   TBranch        *b_LepOther_svNTracks;   //!
   TBranch        *b_LepOther_svChi2n;   //!
   TBranch        *b_LepOther_svDxy;   //!
   TBranch        *b_LepOther_svMass;   //!
   TBranch        *b_LepOther_svPt;   //!
   TBranch        *b_LepOther_svMCMatchFraction;   //!
   TBranch        *b_LepOther_svMva;   //!
   TBranch        *b_LepOther_jetNDau;   //!
   TBranch        *b_LepOther_jetNDauCharged;   //!
   TBranch        *b_LepOther_jetNDauPV;   //!
   TBranch        *b_LepOther_jetNDauNotPV;   //!
   TBranch        *b_LepOther_jetmaxSignedSip3D;   //!
   TBranch        *b_LepOther_jetmaxSip3D;   //!
   TBranch        *b_LepOther_jetmaxSignedSip2D;   //!
   TBranch        *b_LepOther_jetmaxSip2D;   //!
   TBranch        *b_LepOther_jetPtRelv0;   //!
   TBranch        *b_LepOther_jetMass;   //!
   TBranch        *b_LepOther_jetPrunedMass;   //!
   TBranch        *b_LepOther_jetDecDR;   //!
   TBranch        *b_LepOther_jetDecPtRel;   //!
   TBranch        *b_LepOther_jetDecPtRatio;   //!
   TBranch        *b_LepOther_jetDecPrunedMass;   //!
   TBranch        *b_LepOther_jetDecPrunedPtRatio;   //!
   TBranch        *b_LepOther_jetDec02DR;   //!
   TBranch        *b_LepOther_jetDec02PtRel;   //!
   TBranch        *b_LepOther_jetDec02PtRatio;   //!
   TBranch        *b_LepOther_jetDec02PrunedPtRatio;   //!
   TBranch        *b_LepOther_jetDec02PrunedMass;   //!
   TBranch        *b_LepOther_jetRawPt;   //!
   TBranch        *b_LepOther_jetCorrFactor_L1;   //!
   TBranch        *b_LepOther_jetCorrFactor_L1L2;   //!
   TBranch        *b_LepOther_jetCorrFactor_L1L2L3;   //!
   TBranch        *b_LepOther_jetCorrFactor_L1L2L3Res;   //!
   TBranch        *b_LepOther_jetPtRatio_Raw;   //!
   TBranch        *b_LepOther_jetPtRelHv2;   //!
   TBranch        *b_LepOther_ecalPFClusterIso;   //!
   TBranch        *b_LepOther_hcalPFClusterIso;   //!
   TBranch        *b_LepOther_dr03TkSumPt;   //!
   TBranch        *b_LepOther_trackIso;   //!
   TBranch        *b_LepOther_jetLepAwareJEC_pt;   //!
   TBranch        *b_LepOther_jetLepAwareJEC_eta;   //!
   TBranch        *b_LepOther_jetLepAwareJEC_phi;   //!
   TBranch        *b_LepOther_jetLepAwareJEC_energy;   //!
   TBranch        *b_ngenLepFromTau;   //!
   TBranch        *b_genLepFromTau_motherId;   //!
   TBranch        *b_genLepFromTau_grandmotherId;   //!
   TBranch        *b_genLepFromTau_sourceId;   //!
   TBranch        *b_genLepFromTau_charge;   //!
   TBranch        *b_genLepFromTau_status;   //!
   TBranch        *b_genLepFromTau_pdgId;   //!
   TBranch        *b_genLepFromTau_pt;   //!
   TBranch        *b_genLepFromTau_eta;   //!
   TBranch        *b_genLepFromTau_phi;   //!
   TBranch        *b_genLepFromTau_mass;   //!
   TBranch        *b_genLepFromTau_motherIndex;   //!
   TBranch        *b_nJetFwd;   //!
   TBranch        *b_JetFwd_area;   //!
   TBranch        *b_JetFwd_qgl;   //!
   TBranch        *b_JetFwd_ptd;   //!
   TBranch        *b_JetFwd_axis2;   //!
   TBranch        *b_JetFwd_mult;   //!
   TBranch        *b_JetFwd_partonId;   //!
   TBranch        *b_JetFwd_partonMotherId;   //!
   TBranch        *b_JetFwd_nLeptons;   //!
   TBranch        *b_JetFwd_id;   //!
   TBranch        *b_JetFwd_puId;   //!
   TBranch        *b_JetFwd_btagCSV;   //!
   TBranch        *b_JetFwd_btagCMVA;   //!
   TBranch        *b_JetFwd_rawPt;   //!
   TBranch        *b_JetFwd_mcPt;   //!
   TBranch        *b_JetFwd_mcFlavour;   //!
   TBranch        *b_JetFwd_mcMatchId;   //!
   TBranch        *b_JetFwd_corr_JECUp;   //!
   TBranch        *b_JetFwd_corr_JECDown;   //!
   TBranch        *b_JetFwd_corr;   //!
   TBranch        *b_JetFwd_pt;   //!
   TBranch        *b_JetFwd_eta;   //!
   TBranch        *b_JetFwd_phi;   //!
   TBranch        *b_JetFwd_mass;   //!
   TBranch        *b_JetFwd_mcMatchFlav;   //!
   TBranch        *b_JetFwd_charge;   //!

   ttHSelectorBase(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~ttHSelectorBase() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   // ClassDef(ttHSelectorBase,0);
};

#endif

#ifdef ttHSelectorBase_cxx
void ttHSelectorBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoCN", &rhoCN, &b_rhoCN);
   fChain->SetBranchAddress("nVert", &nVert, &b_nVert);
   fChain->SetBranchAddress("nJet25", &nJet25, &b_nJet25);
   fChain->SetBranchAddress("nJet25a", &nJet25a, &b_nJet25a);
   fChain->SetBranchAddress("nBJetLoose25", &nBJetLoose25, &b_nBJetLoose25);
   fChain->SetBranchAddress("nBJetMedium25", &nBJetMedium25, &b_nBJetMedium25);
   fChain->SetBranchAddress("nBJetTight25", &nBJetTight25, &b_nBJetTight25);
   fChain->SetBranchAddress("nJet30", &nJet30, &b_nJet30);
   fChain->SetBranchAddress("nJet30a", &nJet30a, &b_nJet30a);
   fChain->SetBranchAddress("nBJetLoose30", &nBJetLoose30, &b_nBJetLoose30);
   fChain->SetBranchAddress("nBJetMedium30", &nBJetMedium30, &b_nBJetMedium30);
   fChain->SetBranchAddress("nBJetTight30", &nBJetTight30, &b_nBJetTight30);
   fChain->SetBranchAddress("nJet40", &nJet40, &b_nJet40);
   fChain->SetBranchAddress("nJet40a", &nJet40a, &b_nJet40a);
   fChain->SetBranchAddress("nBJetLoose40", &nBJetLoose40, &b_nBJetLoose40);
   fChain->SetBranchAddress("nBJetMedium40", &nBJetMedium40, &b_nBJetMedium40);
   fChain->SetBranchAddress("nBJetTight40", &nBJetTight40, &b_nBJetTight40);
   fChain->SetBranchAddress("nLepGood20", &nLepGood20, &b_nLepGood20);
   fChain->SetBranchAddress("nLepGood15", &nLepGood15, &b_nLepGood15);
   fChain->SetBranchAddress("nLepGood10", &nLepGood10, &b_nLepGood10);
   fChain->SetBranchAddress("GenSusyMScan1", &GenSusyMScan1, &b_GenSusyMScan1);
   fChain->SetBranchAddress("GenSusyMScan2", &GenSusyMScan2, &b_GenSusyMScan2);
   fChain->SetBranchAddress("GenSusyMScan3", &GenSusyMScan3, &b_GenSusyMScan3);
   fChain->SetBranchAddress("GenSusyMScan4", &GenSusyMScan4, &b_GenSusyMScan4);
   fChain->SetBranchAddress("GenSusyMGluino", &GenSusyMGluino, &b_GenSusyMGluino);
   fChain->SetBranchAddress("GenSusyMGravitino", &GenSusyMGravitino, &b_GenSusyMGravitino);
   fChain->SetBranchAddress("GenSusyMStop", &GenSusyMStop, &b_GenSusyMStop);
   fChain->SetBranchAddress("GenSusyMSbottom", &GenSusyMSbottom, &b_GenSusyMSbottom);
   fChain->SetBranchAddress("GenSusyMStop2", &GenSusyMStop2, &b_GenSusyMStop2);
   fChain->SetBranchAddress("GenSusyMSbottom2", &GenSusyMSbottom2, &b_GenSusyMSbottom2);
   fChain->SetBranchAddress("GenSusyMSquark", &GenSusyMSquark, &b_GenSusyMSquark);
   fChain->SetBranchAddress("GenSusyMNeutralino", &GenSusyMNeutralino, &b_GenSusyMNeutralino);
   fChain->SetBranchAddress("GenSusyMNeutralino2", &GenSusyMNeutralino2, &b_GenSusyMNeutralino2);
   fChain->SetBranchAddress("GenSusyMNeutralino3", &GenSusyMNeutralino3, &b_GenSusyMNeutralino3);
   fChain->SetBranchAddress("GenSusyMNeutralino4", &GenSusyMNeutralino4, &b_GenSusyMNeutralino4);
   fChain->SetBranchAddress("GenSusyMChargino", &GenSusyMChargino, &b_GenSusyMChargino);
   fChain->SetBranchAddress("GenSusyMChargino2", &GenSusyMChargino2, &b_GenSusyMChargino2);
   fChain->SetBranchAddress("htJet25", &htJet25, &b_htJet25);
   fChain->SetBranchAddress("mhtJet25", &mhtJet25, &b_mhtJet25);
   fChain->SetBranchAddress("htJet40j", &htJet40j, &b_htJet40j);
   fChain->SetBranchAddress("htJet40ja", &htJet40ja, &b_htJet40ja);
   fChain->SetBranchAddress("htJet40", &htJet40, &b_htJet40);
   fChain->SetBranchAddress("htJet40a", &htJet40a, &b_htJet40a);
   fChain->SetBranchAddress("mhtJet40", &mhtJet40, &b_mhtJet40);
   fChain->SetBranchAddress("mhtJet40a", &mhtJet40a, &b_mhtJet40a);
   fChain->SetBranchAddress("nJet25NoTau", &nJet25NoTau, &b_nJet25NoTau);
   fChain->SetBranchAddress("nBJetLoose25NoTau", &nBJetLoose25NoTau, &b_nBJetLoose25NoTau);
   fChain->SetBranchAddress("nBJetMedium25NoTau", &nBJetMedium25NoTau, &b_nBJetMedium25NoTau);
   fChain->SetBranchAddress("nBJetCMVALoose25", &nBJetCMVALoose25, &b_nBJetCMVALoose25);
   fChain->SetBranchAddress("nBJetCMVAMedium25", &nBJetCMVAMedium25, &b_nBJetCMVAMedium25);
   fChain->SetBranchAddress("nBJetCMVATight25", &nBJetCMVATight25, &b_nBJetCMVATight25);
   fChain->SetBranchAddress("nSoftBLoose25", &nSoftBLoose25, &b_nSoftBLoose25);
   fChain->SetBranchAddress("nSoftBMedium25", &nSoftBMedium25, &b_nSoftBMedium25);
   fChain->SetBranchAddress("nSoftBTight25", &nSoftBTight25, &b_nSoftBTight25);
   fChain->SetBranchAddress("nJet30NoTau", &nJet30NoTau, &b_nJet30NoTau);
   fChain->SetBranchAddress("nBJetLoose30NoTau", &nBJetLoose30NoTau, &b_nBJetLoose30NoTau);
   fChain->SetBranchAddress("nBJetMedium30NoTau", &nBJetMedium30NoTau, &b_nBJetMedium30NoTau);
   fChain->SetBranchAddress("nJet40NoTau", &nJet40NoTau, &b_nJet40NoTau);
   fChain->SetBranchAddress("nBJetLoose40NoTau", &nBJetLoose40NoTau, &b_nBJetLoose40NoTau);
   fChain->SetBranchAddress("nBJetMedium40NoTau", &nBJetMedium40NoTau, &b_nBJetMedium40NoTau);
   fChain->SetBranchAddress("nBJetCMVALoose40", &nBJetCMVALoose40, &b_nBJetCMVALoose40);
   fChain->SetBranchAddress("nBJetCMVAMedium40", &nBJetCMVAMedium40, &b_nBJetCMVAMedium40);
   fChain->SetBranchAddress("nBJetCMVATight40", &nBJetCMVATight40, &b_nBJetCMVATight40);
   fChain->SetBranchAddress("mZ1", &mZ1, &b_mZ1);
   fChain->SetBranchAddress("mZ1SFSS", &mZ1SFSS, &b_mZ1SFSS);
   fChain->SetBranchAddress("minMllSFOS", &minMllSFOS, &b_minMllSFOS);
   fChain->SetBranchAddress("maxMllSFOS", &maxMllSFOS, &b_maxMllSFOS);
   fChain->SetBranchAddress("minMllAFOS", &minMllAFOS, &b_minMllAFOS);
   fChain->SetBranchAddress("maxMllAFOS", &maxMllAFOS, &b_maxMllAFOS);
   fChain->SetBranchAddress("minMllAFSS", &minMllAFSS, &b_minMllAFSS);
   fChain->SetBranchAddress("maxMllAFSS", &maxMllAFSS, &b_maxMllAFSS);
   fChain->SetBranchAddress("minMllAFAS", &minMllAFAS, &b_minMllAFAS);
   fChain->SetBranchAddress("maxMllAFAS", &maxMllAFAS, &b_maxMllAFAS);
   fChain->SetBranchAddress("m2l", &m2l, &b_m2l);
   fChain->SetBranchAddress("minDrllAFSS", &minDrllAFSS, &b_minDrllAFSS);
   fChain->SetBranchAddress("maxDrllAFSS", &maxDrllAFSS, &b_maxDrllAFSS);
   fChain->SetBranchAddress("minDrllAFOS", &minDrllAFOS, &b_minDrllAFOS);
   fChain->SetBranchAddress("maxDrllAFOS", &maxDrllAFOS, &b_maxDrllAFOS);
   fChain->SetBranchAddress("mZ2", &mZ2, &b_mZ2);
   fChain->SetBranchAddress("m3l", &m3l, &b_m3l);
   fChain->SetBranchAddress("m4l", &m4l, &b_m4l);
   fChain->SetBranchAddress("pt2l", &pt2l, &b_pt2l);
   fChain->SetBranchAddress("pt3l", &pt3l, &b_pt3l);
   fChain->SetBranchAddress("pt4l", &pt4l, &b_pt4l);
   fChain->SetBranchAddress("ht3l", &ht3l, &b_ht3l);
   fChain->SetBranchAddress("ht4l", &ht4l, &b_ht4l);
   fChain->SetBranchAddress("q3l", &q3l, &b_q3l);
   fChain->SetBranchAddress("q4l", &q4l, &b_q4l);
   fChain->SetBranchAddress("minMWjj", &minMWjj, &b_minMWjj);
   fChain->SetBranchAddress("minMWjjPt", &minMWjjPt, &b_minMWjjPt);
   fChain->SetBranchAddress("bestMWjj", &bestMWjj, &b_bestMWjj);
   fChain->SetBranchAddress("bestMWjjPt", &bestMWjjPt, &b_bestMWjjPt);
   fChain->SetBranchAddress("bestMTopHad", &bestMTopHad, &b_bestMTopHad);
   fChain->SetBranchAddress("bestMTopHadPt", &bestMTopHadPt, &b_bestMTopHadPt);
   fChain->SetBranchAddress("GenHiggsDecayMode", &GenHiggsDecayMode, &b_GenHiggsDecayMode);
   fChain->SetBranchAddress("absIP3DAval", &absIP3DAval, &b_absIP3DAval);
   fChain->SetBranchAddress("absIP3DAerr", &absIP3DAerr, &b_absIP3DAerr);
   fChain->SetBranchAddress("absIP3DBval", &absIP3DBval, &b_absIP3DBval);
   fChain->SetBranchAddress("absIP3DBerr", &absIP3DBerr, &b_absIP3DBerr);
   fChain->SetBranchAddress("absIP3DCval", &absIP3DCval, &b_absIP3DCval);
   fChain->SetBranchAddress("absIP3DCerr", &absIP3DCerr, &b_absIP3DCerr);
   fChain->SetBranchAddress("absIP3DDval", &absIP3DDval, &b_absIP3DDval);
   fChain->SetBranchAddress("absIP3DDerr", &absIP3DDerr, &b_absIP3DDerr);
   fChain->SetBranchAddress("absIP3DApvBCval", &absIP3DApvBCval, &b_absIP3DApvBCval);
   fChain->SetBranchAddress("absIP3DApvBCerr", &absIP3DApvBCerr, &b_absIP3DApvBCerr);
   fChain->SetBranchAddress("absIP3DBpvACval", &absIP3DBpvACval, &b_absIP3DBpvACval);
   fChain->SetBranchAddress("absIP3DBpvACerr", &absIP3DBpvACerr, &b_absIP3DBpvACerr);
   fChain->SetBranchAddress("absIP3DCpvABval", &absIP3DCpvABval, &b_absIP3DCpvABval);
   fChain->SetBranchAddress("absIP3DCpvABerr", &absIP3DCpvABerr, &b_absIP3DCpvABerr);
   fChain->SetBranchAddress("absIP3DApvBCDval", &absIP3DApvBCDval, &b_absIP3DApvBCDval);
   fChain->SetBranchAddress("absIP3DApvBCDerr", &absIP3DApvBCDerr, &b_absIP3DApvBCDerr);
   fChain->SetBranchAddress("absIP3DBpvACDval", &absIP3DBpvACDval, &b_absIP3DBpvACDval);
   fChain->SetBranchAddress("absIP3DBpvACDerr", &absIP3DBpvACDerr, &b_absIP3DBpvACDerr);
   fChain->SetBranchAddress("absIP3DCpvABDval", &absIP3DCpvABDval, &b_absIP3DCpvABDval);
   fChain->SetBranchAddress("absIP3DCpvABDerr", &absIP3DCpvABDerr, &b_absIP3DCpvABDerr);
   fChain->SetBranchAddress("absIP3DDpvABCval", &absIP3DDpvABCval, &b_absIP3DDpvABCval);
   fChain->SetBranchAddress("absIP3DDpvABCerr", &absIP3DDpvABCerr, &b_absIP3DDpvABCerr);
   fChain->SetBranchAddress("chi2pvtrksBCbutAval", &chi2pvtrksBCbutAval, &b_chi2pvtrksBCbutAval);
   fChain->SetBranchAddress("chi2pvtrksBCbutAdof", &chi2pvtrksBCbutAdof, &b_chi2pvtrksBCbutAdof);
   fChain->SetBranchAddress("chi2pvtrksACbutBval", &chi2pvtrksACbutBval, &b_chi2pvtrksACbutBval);
   fChain->SetBranchAddress("chi2pvtrksACbutBdof", &chi2pvtrksACbutBdof, &b_chi2pvtrksACbutBdof);
   fChain->SetBranchAddress("chi2pvtrksABbutCval", &chi2pvtrksABbutCval, &b_chi2pvtrksABbutCval);
   fChain->SetBranchAddress("chi2pvtrksABbutCdof", &chi2pvtrksABbutCdof, &b_chi2pvtrksABbutCdof);
   fChain->SetBranchAddress("chi2pvtrksBCDbutAval", &chi2pvtrksBCDbutAval, &b_chi2pvtrksBCDbutAval);
   fChain->SetBranchAddress("chi2pvtrksBCDbutAdof", &chi2pvtrksBCDbutAdof, &b_chi2pvtrksBCDbutAdof);
   fChain->SetBranchAddress("chi2pvtrksACDbutBval", &chi2pvtrksACDbutBval, &b_chi2pvtrksACDbutBval);
   fChain->SetBranchAddress("chi2pvtrksACDbutBdof", &chi2pvtrksACDbutBdof, &b_chi2pvtrksACDbutBdof);
   fChain->SetBranchAddress("chi2pvtrksABDbutCval", &chi2pvtrksABDbutCval, &b_chi2pvtrksABDbutCval);
   fChain->SetBranchAddress("chi2pvtrksABDbutCdof", &chi2pvtrksABDbutCdof, &b_chi2pvtrksABDbutCdof);
   fChain->SetBranchAddress("chi2pvtrksABCbutDval", &chi2pvtrksABCbutDval, &b_chi2pvtrksABCbutDval);
   fChain->SetBranchAddress("chi2pvtrksABCbutDdof", &chi2pvtrksABCbutDdof, &b_chi2pvtrksABCbutDdof);
   fChain->SetBranchAddress("nRecJet40", &nRecJet40, &b_nRecJet40);
   fChain->SetBranchAddress("nRecJet25", &nRecJet25, &b_nRecJet25);
   fChain->SetBranchAddress("nRecBJetMedium40", &nRecBJetMedium40, &b_nRecBJetMedium40);
   fChain->SetBranchAddress("nRecBJetMedium25", &nRecBJetMedium25, &b_nRecBJetMedium25);
   fChain->SetBranchAddress("nRecSplitJet40", &nRecSplitJet40, &b_nRecSplitJet40);
   fChain->SetBranchAddress("nRecSplitJet25", &nRecSplitJet25, &b_nRecSplitJet25);
   fChain->SetBranchAddress("nRecSplitBJetMedium40", &nRecSplitBJetMedium40, &b_nRecSplitBJetMedium40);
   fChain->SetBranchAddress("nRecSplitBJetMedium25", &nRecSplitBJetMedium25, &b_nRecSplitBJetMedium25);
   fChain->SetBranchAddress("hbheFilterNew50ns", &hbheFilterNew50ns, &b_hbheFilterNew50ns);
   fChain->SetBranchAddress("hbheFilterNew25ns", &hbheFilterNew25ns, &b_hbheFilterNew25ns);
   fChain->SetBranchAddress("hbheFilterIso", &hbheFilterIso, &b_hbheFilterIso);
   fChain->SetBranchAddress("met_trkPt", &met_trkPt, &b_met_trkPt);
   fChain->SetBranchAddress("met_trkPhi", &met_trkPhi, &b_met_trkPhi);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleElHT", &HLT_DoubleElHT, &b_HLT_DoubleElHT);
   fChain->SetBranchAddress("HLT_DoubleElHT_isUnprescaled", &HLT_DoubleElHT_isUnprescaled, &b_HLT_DoubleElHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleEl", &HLT_TripleEl, &b_HLT_TripleEl);
   fChain->SetBranchAddress("HLT_TripleEl_isUnprescaled", &HLT_TripleEl_isUnprescaled, &b_HLT_TripleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MuEGHT", &HLT_MuEGHT, &b_HLT_MuEGHT);
   fChain->SetBranchAddress("HLT_MuEGHT_isUnprescaled", &HLT_MuEGHT_isUnprescaled, &b_HLT_MuEGHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_MonoJet80MET90", &HLT_MonoJet80MET90, &b_HLT_MonoJet80MET90);
   fChain->SetBranchAddress("HLT_MonoJet80MET90_isUnprescaled", &HLT_MonoJet80MET90_isUnprescaled, &b_HLT_MonoJet80MET90_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_eta2p1_v", &HLT_BIT_HLT_IsoMu24_eta2p1_v, &b_HLT_BIT_HLT_IsoMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled", &HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu24_eta2p1_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu24_eta2p1_v", &HLT_BIT_HLT_IsoTkMu24_eta2p1_v, &b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu24_eta2p1_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v", &HLT_BIT_HLT_IsoMu18_v, &b_HLT_BIT_HLT_IsoMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v_isUnprescaled", &HLT_BIT_HLT_IsoMu18_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu18_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v", &HLT_BIT_HLT_IsoMu20_v, &b_HLT_BIT_HLT_IsoMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v", &HLT_BIT_HLT_IsoTkMu20_v, &b_HLT_BIT_HLT_IsoTkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v", &HLT_BIT_HLT_IsoMu27_v, &b_HLT_BIT_HLT_IsoMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v_isUnprescaled", &HLT_BIT_HLT_IsoMu27_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu27_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v", &HLT_BIT_HLT_IsoTkMu27_v, &b_HLT_BIT_HLT_IsoTkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu27_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_SingleMu", &HLT_SingleMu, &b_HLT_SingleMu);
   fChain->SetBranchAddress("HLT_SingleMu_isUnprescaled", &HLT_SingleMu_isUnprescaled, &b_HLT_SingleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuEl", &HLT_DoubleMuEl, &b_HLT_DoubleMuEl);
   fChain->SetBranchAddress("HLT_DoubleMuEl_isUnprescaled", &HLT_DoubleMuEl_isUnprescaled, &b_HLT_DoubleMuEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MonoJet80MET120", &HLT_MonoJet80MET120, &b_HLT_MonoJet80MET120);
   fChain->SetBranchAddress("HLT_MonoJet80MET120_isUnprescaled", &HLT_MonoJet80MET120_isUnprescaled, &b_HLT_MonoJet80MET120_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v", &HLT_BIT_HLT_TripleMu_12_10_5_v, &b_HLT_BIT_HLT_TripleMu_12_10_5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled", &HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled, &b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleMu", &HLT_TripleMu, &b_HLT_TripleMu);
   fChain->SetBranchAddress("HLT_TripleMu_isUnprescaled", &HLT_TripleMu_isUnprescaled, &b_HLT_TripleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleElMu", &HLT_DoubleElMu, &b_HLT_DoubleElMu);
   fChain->SetBranchAddress("HLT_DoubleElMu_isUnprescaled", &HLT_DoubleElMu_isUnprescaled, &b_HLT_DoubleElMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v", &HLT_BIT_HLT_Mu30_TkMu11_v, &b_HLT_BIT_HLT_Mu30_TkMu11_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled", &HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled, &b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso", &HLT_DoubleMuNoIso, &b_HLT_DoubleMuNoIso);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso_isUnprescaled", &HLT_DoubleMuNoIso_isUnprescaled, &b_HLT_DoubleMuNoIso_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuSS", &HLT_DoubleMuSS, &b_HLT_DoubleMuSS);
   fChain->SetBranchAddress("HLT_DoubleMuSS_isUnprescaled", &HLT_DoubleMuSS_isUnprescaled, &b_HLT_DoubleMuSS_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele32_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WP85_Gsf_v", &HLT_BIT_HLT_Ele27_WP85_Gsf_v, &b_HLT_BIT_HLT_Ele27_WP85_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_WP85_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_eta2p1_WP75_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele32_eta2p1_WP75_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_SingleEl", &HLT_SingleEl, &b_HLT_SingleEl);
   fChain->SetBranchAddress("HLT_SingleEl_isUnprescaled", &HLT_SingleEl_isUnprescaled, &b_HLT_SingleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_TripleMuA", &HLT_TripleMuA, &b_HLT_TripleMuA);
   fChain->SetBranchAddress("HLT_TripleMuA_isUnprescaled", &HLT_TripleMuA_isUnprescaled, &b_HLT_TripleMuA_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_MuEG", &HLT_MuEG, &b_HLT_MuEG);
   fChain->SetBranchAddress("HLT_MuEG_isUnprescaled", &HLT_MuEG_isUnprescaled, &b_HLT_MuEG_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMuHT", &HLT_DoubleMuHT, &b_HLT_DoubleMuHT);
   fChain->SetBranchAddress("HLT_DoubleMuHT_isUnprescaled", &HLT_DoubleMuHT_isUnprescaled, &b_HLT_DoubleMuHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleEl", &HLT_DoubleEl, &b_HLT_DoubleEl);
   fChain->SetBranchAddress("HLT_DoubleEl_isUnprescaled", &HLT_DoubleEl_isUnprescaled, &b_HLT_DoubleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_DoubleMu", &HLT_DoubleMu, &b_HLT_DoubleMu);
   fChain->SetBranchAddress("HLT_DoubleMu_isUnprescaled", &HLT_DoubleMu_isUnprescaled, &b_HLT_DoubleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v", &HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v, &b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled", &HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET120_NoiseCleaned_Mu5_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_METMu5", &HLT_METMu5, &b_HLT_METMu5);
   fChain->SetBranchAddress("HLT_METMu5_isUnprescaled", &HLT_METMu5_isUnprescaled, &b_HLT_METMu5_isUnprescaled);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_mass", &met_mass, &b_met_mass);
   fChain->SetBranchAddress("met_sumEt", &met_sumEt, &b_met_sumEt);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_rawSumEt", &met_rawSumEt, &b_met_rawSumEt);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("met_genEta", &met_genEta, &b_met_genEta);
   fChain->SetBranchAddress("nFatJet", &nFatJet, &b_nFatJet);
   fChain->SetBranchAddress("FatJet_id", FatJet_id, &b_FatJet_id);
   fChain->SetBranchAddress("FatJet_puId", FatJet_puId, &b_FatJet_puId);
   fChain->SetBranchAddress("FatJet_btagCSV", FatJet_btagCSV, &b_FatJet_btagCSV);
   fChain->SetBranchAddress("FatJet_btagCMVA", FatJet_btagCMVA, &b_FatJet_btagCMVA);
   fChain->SetBranchAddress("FatJet_rawPt", FatJet_rawPt, &b_FatJet_rawPt);
   fChain->SetBranchAddress("FatJet_mcPt", FatJet_mcPt, &b_FatJet_mcPt);
   fChain->SetBranchAddress("FatJet_mcFlavour", FatJet_mcFlavour, &b_FatJet_mcFlavour);
   fChain->SetBranchAddress("FatJet_mcMatchId", FatJet_mcMatchId, &b_FatJet_mcMatchId);
   fChain->SetBranchAddress("FatJet_corr_JECUp", FatJet_corr_JECUp, &b_FatJet_corr_JECUp);
   fChain->SetBranchAddress("FatJet_corr_JECDown", FatJet_corr_JECDown, &b_FatJet_corr_JECDown);
   fChain->SetBranchAddress("FatJet_corr", FatJet_corr, &b_FatJet_corr);
   fChain->SetBranchAddress("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   fChain->SetBranchAddress("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   fChain->SetBranchAddress("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   fChain->SetBranchAddress("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   fChain->SetBranchAddress("FatJet_prunedMass", FatJet_prunedMass, &b_FatJet_prunedMass);
   fChain->SetBranchAddress("FatJet_trimmedMass", FatJet_trimmedMass, &b_FatJet_trimmedMass);
   fChain->SetBranchAddress("FatJet_filteredMass", FatJet_filteredMass, &b_FatJet_filteredMass);
   fChain->SetBranchAddress("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   fChain->SetBranchAddress("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   fChain->SetBranchAddress("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   fChain->SetBranchAddress("FatJet_topMass", FatJet_topMass, &b_FatJet_topMass);
   fChain->SetBranchAddress("FatJet_minMass", FatJet_minMass, &b_FatJet_minMass);
   fChain->SetBranchAddress("FatJet_nSubJets", FatJet_nSubJets, &b_FatJet_nSubJets);
   fChain->SetBranchAddress("nDiscLep", &nDiscLep, &b_nDiscLep);
   fChain->SetBranchAddress("DiscLep_mvaIdPhys14", &DiscLep_mvaIdPhys14, &b_DiscLep_mvaIdPhys14);
   fChain->SetBranchAddress("DiscLep_mvaIdSpring15", &DiscLep_mvaIdSpring15, &b_DiscLep_mvaIdSpring15);
   fChain->SetBranchAddress("DiscLep_mvaTTH", &DiscLep_mvaTTH, &b_DiscLep_mvaTTH);
   fChain->SetBranchAddress("DiscLep_jetPtRatiov1", &DiscLep_jetPtRatiov1, &b_DiscLep_jetPtRatiov1);
   fChain->SetBranchAddress("DiscLep_jetPtRelv1", &DiscLep_jetPtRelv1, &b_DiscLep_jetPtRelv1);
   fChain->SetBranchAddress("DiscLep_jetPtRatiov2", &DiscLep_jetPtRatiov2, &b_DiscLep_jetPtRatiov2);
   fChain->SetBranchAddress("DiscLep_jetPtRelv2", &DiscLep_jetPtRelv2, &b_DiscLep_jetPtRelv2);
   fChain->SetBranchAddress("DiscLep_jetBTagCSV", &DiscLep_jetBTagCSV, &b_DiscLep_jetBTagCSV);
   fChain->SetBranchAddress("DiscLep_jetBTagCMVA", &DiscLep_jetBTagCMVA, &b_DiscLep_jetBTagCMVA);
   fChain->SetBranchAddress("DiscLep_jetDR", &DiscLep_jetDR, &b_DiscLep_jetDR);
   fChain->SetBranchAddress("DiscLep_charge", &DiscLep_charge, &b_DiscLep_charge);
   fChain->SetBranchAddress("DiscLep_tightId", &DiscLep_tightId, &b_DiscLep_tightId);
   fChain->SetBranchAddress("DiscLep_eleCutIdCSA14_25ns_v1", &DiscLep_eleCutIdCSA14_25ns_v1, &b_DiscLep_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("DiscLep_eleCutIdCSA14_50ns_v1", &DiscLep_eleCutIdCSA14_50ns_v1, &b_DiscLep_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("DiscLep_dxy", &DiscLep_dxy, &b_DiscLep_dxy);
   fChain->SetBranchAddress("DiscLep_dz", &DiscLep_dz, &b_DiscLep_dz);
   fChain->SetBranchAddress("DiscLep_edxy", &DiscLep_edxy, &b_DiscLep_edxy);
   fChain->SetBranchAddress("DiscLep_edz", &DiscLep_edz, &b_DiscLep_edz);
   fChain->SetBranchAddress("DiscLep_ip3d", &DiscLep_ip3d, &b_DiscLep_ip3d);
   fChain->SetBranchAddress("DiscLep_sip3d", &DiscLep_sip3d, &b_DiscLep_sip3d);
   fChain->SetBranchAddress("DiscLep_convVeto", &DiscLep_convVeto, &b_DiscLep_convVeto);
   fChain->SetBranchAddress("DiscLep_lostHits", &DiscLep_lostHits, &b_DiscLep_lostHits);
   fChain->SetBranchAddress("DiscLep_relIso03", &DiscLep_relIso03, &b_DiscLep_relIso03);
   fChain->SetBranchAddress("DiscLep_relIso04", &DiscLep_relIso04, &b_DiscLep_relIso04);
   fChain->SetBranchAddress("DiscLep_miniRelIso", &DiscLep_miniRelIso, &b_DiscLep_miniRelIso);
   fChain->SetBranchAddress("DiscLep_relIsoAn04", &DiscLep_relIsoAn04, &b_DiscLep_relIsoAn04);
   fChain->SetBranchAddress("DiscLep_tightCharge", &DiscLep_tightCharge, &b_DiscLep_tightCharge);
   fChain->SetBranchAddress("DiscLep_mcMatchId", &DiscLep_mcMatchId, &b_DiscLep_mcMatchId);
   fChain->SetBranchAddress("DiscLep_mcMatchAny", &DiscLep_mcMatchAny, &b_DiscLep_mcMatchAny);
   fChain->SetBranchAddress("DiscLep_mcMatchTau", &DiscLep_mcMatchTau, &b_DiscLep_mcMatchTau);
   fChain->SetBranchAddress("DiscLep_mcPt", &DiscLep_mcPt, &b_DiscLep_mcPt);
   fChain->SetBranchAddress("DiscLep_mediumMuonId", &DiscLep_mediumMuonId, &b_DiscLep_mediumMuonId);
   fChain->SetBranchAddress("DiscLep_pdgId", &DiscLep_pdgId, &b_DiscLep_pdgId);
   fChain->SetBranchAddress("DiscLep_pt", &DiscLep_pt, &b_DiscLep_pt);
   fChain->SetBranchAddress("DiscLep_eta", &DiscLep_eta, &b_DiscLep_eta);
   fChain->SetBranchAddress("DiscLep_phi", &DiscLep_phi, &b_DiscLep_phi);
   fChain->SetBranchAddress("DiscLep_mass", &DiscLep_mass, &b_DiscLep_mass);
   fChain->SetBranchAddress("DiscLep_chargedHadRelIso03", &DiscLep_chargedHadRelIso03, &b_DiscLep_chargedHadRelIso03);
   fChain->SetBranchAddress("DiscLep_chargedHadRelIso04", &DiscLep_chargedHadRelIso04, &b_DiscLep_chargedHadRelIso04);
   fChain->SetBranchAddress("DiscLep_softMuonId", &DiscLep_softMuonId, &b_DiscLep_softMuonId);
   fChain->SetBranchAddress("DiscLep_pfMuonId", &DiscLep_pfMuonId, &b_DiscLep_pfMuonId);
   fChain->SetBranchAddress("DiscLep_eleCutId2012_full5x5", &DiscLep_eleCutId2012_full5x5, &b_DiscLep_eleCutId2012_full5x5);
   fChain->SetBranchAddress("DiscLep_trackerLayers", &DiscLep_trackerLayers, &b_DiscLep_trackerLayers);
   fChain->SetBranchAddress("DiscLep_pixelLayers", &DiscLep_pixelLayers, &b_DiscLep_pixelLayers);
   fChain->SetBranchAddress("DiscLep_trackerHits", &DiscLep_trackerHits, &b_DiscLep_trackerHits);
   fChain->SetBranchAddress("DiscLep_lostOuterHits", &DiscLep_lostOuterHits, &b_DiscLep_lostOuterHits);
   fChain->SetBranchAddress("DiscLep_innerTrackValidHitFraction", &DiscLep_innerTrackValidHitFraction, &b_DiscLep_innerTrackValidHitFraction);
   fChain->SetBranchAddress("DiscLep_innerTrackChi2", &DiscLep_innerTrackChi2, &b_DiscLep_innerTrackChi2);
   fChain->SetBranchAddress("DiscLep_nStations", &DiscLep_nStations, &b_DiscLep_nStations);
   fChain->SetBranchAddress("DiscLep_caloCompatibility", &DiscLep_caloCompatibility, &b_DiscLep_caloCompatibility);
   fChain->SetBranchAddress("DiscLep_globalTrackChi2", &DiscLep_globalTrackChi2, &b_DiscLep_globalTrackChi2);
   fChain->SetBranchAddress("DiscLep_trkKink", &DiscLep_trkKink, &b_DiscLep_trkKink);
   fChain->SetBranchAddress("DiscLep_segmentCompatibility", &DiscLep_segmentCompatibility, &b_DiscLep_segmentCompatibility);
   fChain->SetBranchAddress("DiscLep_chi2LocalPosition", &DiscLep_chi2LocalPosition, &b_DiscLep_chi2LocalPosition);
   fChain->SetBranchAddress("DiscLep_chi2LocalMomentum", &DiscLep_chi2LocalMomentum, &b_DiscLep_chi2LocalMomentum);
   fChain->SetBranchAddress("DiscLep_glbTrackProbability", &DiscLep_glbTrackProbability, &b_DiscLep_glbTrackProbability);
   fChain->SetBranchAddress("DiscLep_sigmaIEtaIEta", &DiscLep_sigmaIEtaIEta, &b_DiscLep_sigmaIEtaIEta);
   fChain->SetBranchAddress("DiscLep_dEtaScTrkIn", &DiscLep_dEtaScTrkIn, &b_DiscLep_dEtaScTrkIn);
   fChain->SetBranchAddress("DiscLep_dPhiScTrkIn", &DiscLep_dPhiScTrkIn, &b_DiscLep_dPhiScTrkIn);
   fChain->SetBranchAddress("DiscLep_hadronicOverEm", &DiscLep_hadronicOverEm, &b_DiscLep_hadronicOverEm);
   fChain->SetBranchAddress("DiscLep_eInvMinusPInv", &DiscLep_eInvMinusPInv, &b_DiscLep_eInvMinusPInv);
   fChain->SetBranchAddress("DiscLep_eInvMinusPInv_tkMom", &DiscLep_eInvMinusPInv_tkMom, &b_DiscLep_eInvMinusPInv_tkMom);
   fChain->SetBranchAddress("DiscLep_etaSc", &DiscLep_etaSc, &b_DiscLep_etaSc);
   fChain->SetBranchAddress("DiscLep_miniRelIsoCharged", &DiscLep_miniRelIsoCharged, &b_DiscLep_miniRelIsoCharged);
   fChain->SetBranchAddress("DiscLep_miniRelIsoNeutral", &DiscLep_miniRelIsoNeutral, &b_DiscLep_miniRelIsoNeutral);
   fChain->SetBranchAddress("DiscLep_hasSV", &DiscLep_hasSV, &b_DiscLep_hasSV);
   fChain->SetBranchAddress("DiscLep_svRedPt", &DiscLep_svRedPt, &b_DiscLep_svRedPt);
   fChain->SetBranchAddress("DiscLep_svRedM", &DiscLep_svRedM, &b_DiscLep_svRedM);
   fChain->SetBranchAddress("DiscLep_svLepSip3d", &DiscLep_svLepSip3d, &b_DiscLep_svLepSip3d);
   fChain->SetBranchAddress("DiscLep_svSip3d", &DiscLep_svSip3d, &b_DiscLep_svSip3d);
   fChain->SetBranchAddress("DiscLep_svNTracks", &DiscLep_svNTracks, &b_DiscLep_svNTracks);
   fChain->SetBranchAddress("DiscLep_svChi2n", &DiscLep_svChi2n, &b_DiscLep_svChi2n);
   fChain->SetBranchAddress("DiscLep_svDxy", &DiscLep_svDxy, &b_DiscLep_svDxy);
   fChain->SetBranchAddress("DiscLep_svMass", &DiscLep_svMass, &b_DiscLep_svMass);
   fChain->SetBranchAddress("DiscLep_svPt", &DiscLep_svPt, &b_DiscLep_svPt);
   fChain->SetBranchAddress("DiscLep_svMCMatchFraction", &DiscLep_svMCMatchFraction, &b_DiscLep_svMCMatchFraction);
   fChain->SetBranchAddress("DiscLep_svMva", &DiscLep_svMva, &b_DiscLep_svMva);
   fChain->SetBranchAddress("DiscLep_jetNDau", &DiscLep_jetNDau, &b_DiscLep_jetNDau);
   fChain->SetBranchAddress("DiscLep_jetNDauCharged", &DiscLep_jetNDauCharged, &b_DiscLep_jetNDauCharged);
   fChain->SetBranchAddress("DiscLep_jetNDauPV", &DiscLep_jetNDauPV, &b_DiscLep_jetNDauPV);
   fChain->SetBranchAddress("DiscLep_jetNDauNotPV", &DiscLep_jetNDauNotPV, &b_DiscLep_jetNDauNotPV);
   fChain->SetBranchAddress("DiscLep_jetmaxSignedSip3D", &DiscLep_jetmaxSignedSip3D, &b_DiscLep_jetmaxSignedSip3D);
   fChain->SetBranchAddress("DiscLep_jetmaxSip3D", &DiscLep_jetmaxSip3D, &b_DiscLep_jetmaxSip3D);
   fChain->SetBranchAddress("DiscLep_jetmaxSignedSip2D", &DiscLep_jetmaxSignedSip2D, &b_DiscLep_jetmaxSignedSip2D);
   fChain->SetBranchAddress("DiscLep_jetmaxSip2D", &DiscLep_jetmaxSip2D, &b_DiscLep_jetmaxSip2D);
   fChain->SetBranchAddress("DiscLep_jetPtRelv0", &DiscLep_jetPtRelv0, &b_DiscLep_jetPtRelv0);
   fChain->SetBranchAddress("DiscLep_jetMass", &DiscLep_jetMass, &b_DiscLep_jetMass);
   fChain->SetBranchAddress("DiscLep_jetPrunedMass", &DiscLep_jetPrunedMass, &b_DiscLep_jetPrunedMass);
   fChain->SetBranchAddress("DiscLep_jetDecDR", &DiscLep_jetDecDR, &b_DiscLep_jetDecDR);
   fChain->SetBranchAddress("DiscLep_jetDecPtRel", &DiscLep_jetDecPtRel, &b_DiscLep_jetDecPtRel);
   fChain->SetBranchAddress("DiscLep_jetDecPtRatio", &DiscLep_jetDecPtRatio, &b_DiscLep_jetDecPtRatio);
   fChain->SetBranchAddress("DiscLep_jetDecPrunedMass", &DiscLep_jetDecPrunedMass, &b_DiscLep_jetDecPrunedMass);
   fChain->SetBranchAddress("DiscLep_jetDecPrunedPtRatio", &DiscLep_jetDecPrunedPtRatio, &b_DiscLep_jetDecPrunedPtRatio);
   fChain->SetBranchAddress("DiscLep_jetDec02DR", &DiscLep_jetDec02DR, &b_DiscLep_jetDec02DR);
   fChain->SetBranchAddress("DiscLep_jetDec02PtRel", &DiscLep_jetDec02PtRel, &b_DiscLep_jetDec02PtRel);
   fChain->SetBranchAddress("DiscLep_jetDec02PtRatio", &DiscLep_jetDec02PtRatio, &b_DiscLep_jetDec02PtRatio);
   fChain->SetBranchAddress("DiscLep_jetDec02PrunedPtRatio", &DiscLep_jetDec02PrunedPtRatio, &b_DiscLep_jetDec02PrunedPtRatio);
   fChain->SetBranchAddress("DiscLep_jetDec02PrunedMass", &DiscLep_jetDec02PrunedMass, &b_DiscLep_jetDec02PrunedMass);
   fChain->SetBranchAddress("DiscLep_jetRawPt", &DiscLep_jetRawPt, &b_DiscLep_jetRawPt);
   fChain->SetBranchAddress("DiscLep_jetCorrFactor_L1", &DiscLep_jetCorrFactor_L1, &b_DiscLep_jetCorrFactor_L1);
   fChain->SetBranchAddress("DiscLep_jetCorrFactor_L1L2", &DiscLep_jetCorrFactor_L1L2, &b_DiscLep_jetCorrFactor_L1L2);
   fChain->SetBranchAddress("DiscLep_jetCorrFactor_L1L2L3", &DiscLep_jetCorrFactor_L1L2L3, &b_DiscLep_jetCorrFactor_L1L2L3);
   fChain->SetBranchAddress("DiscLep_jetCorrFactor_L1L2L3Res", &DiscLep_jetCorrFactor_L1L2L3Res, &b_DiscLep_jetCorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("DiscLep_jetPtRatio_Raw", &DiscLep_jetPtRatio_Raw, &b_DiscLep_jetPtRatio_Raw);
   fChain->SetBranchAddress("DiscLep_jetPtRelHv2", &DiscLep_jetPtRelHv2, &b_DiscLep_jetPtRelHv2);
   fChain->SetBranchAddress("DiscLep_ecalPFClusterIso", &DiscLep_ecalPFClusterIso, &b_DiscLep_ecalPFClusterIso);
   fChain->SetBranchAddress("DiscLep_hcalPFClusterIso", &DiscLep_hcalPFClusterIso, &b_DiscLep_hcalPFClusterIso);
   fChain->SetBranchAddress("DiscLep_dr03TkSumPt", &DiscLep_dr03TkSumPt, &b_DiscLep_dr03TkSumPt);
   fChain->SetBranchAddress("DiscLep_trackIso", &DiscLep_trackIso, &b_DiscLep_trackIso);
   fChain->SetBranchAddress("DiscLep_jetLepAwareJEC_pt", &DiscLep_jetLepAwareJEC_pt, &b_DiscLep_jetLepAwareJEC_pt);
   fChain->SetBranchAddress("DiscLep_jetLepAwareJEC_eta", &DiscLep_jetLepAwareJEC_eta, &b_DiscLep_jetLepAwareJEC_eta);
   fChain->SetBranchAddress("DiscLep_jetLepAwareJEC_phi", &DiscLep_jetLepAwareJEC_phi, &b_DiscLep_jetLepAwareJEC_phi);
   fChain->SetBranchAddress("DiscLep_jetLepAwareJEC_energy", &DiscLep_jetLepAwareJEC_energy, &b_DiscLep_jetLepAwareJEC_energy);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_motherId", GenPart_motherId, &b_GenPart_motherId);
   fChain->SetBranchAddress("GenPart_grandmotherId", GenPart_grandmotherId, &b_GenPart_grandmotherId);
   fChain->SetBranchAddress("GenPart_sourceId", GenPart_sourceId, &b_GenPart_sourceId);
   fChain->SetBranchAddress("GenPart_charge", GenPart_charge, &b_GenPart_charge);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_motherIndex", GenPart_motherIndex, &b_GenPart_motherIndex);
   fChain->SetBranchAddress("nDiscJet", &nDiscJet, &b_nDiscJet);
   fChain->SetBranchAddress("DiscJet_area", DiscJet_area, &b_DiscJet_area);
   fChain->SetBranchAddress("DiscJet_qgl", DiscJet_qgl, &b_DiscJet_qgl);
   fChain->SetBranchAddress("DiscJet_ptd", DiscJet_ptd, &b_DiscJet_ptd);
   fChain->SetBranchAddress("DiscJet_axis2", DiscJet_axis2, &b_DiscJet_axis2);
   fChain->SetBranchAddress("DiscJet_mult", DiscJet_mult, &b_DiscJet_mult);
   fChain->SetBranchAddress("DiscJet_partonId", DiscJet_partonId, &b_DiscJet_partonId);
   fChain->SetBranchAddress("DiscJet_partonMotherId", DiscJet_partonMotherId, &b_DiscJet_partonMotherId);
   fChain->SetBranchAddress("DiscJet_nLeptons", DiscJet_nLeptons, &b_DiscJet_nLeptons);
   fChain->SetBranchAddress("DiscJet_id", DiscJet_id, &b_DiscJet_id);
   fChain->SetBranchAddress("DiscJet_puId", DiscJet_puId, &b_DiscJet_puId);
   fChain->SetBranchAddress("DiscJet_btagCSV", DiscJet_btagCSV, &b_DiscJet_btagCSV);
   fChain->SetBranchAddress("DiscJet_btagCMVA", DiscJet_btagCMVA, &b_DiscJet_btagCMVA);
   fChain->SetBranchAddress("DiscJet_rawPt", DiscJet_rawPt, &b_DiscJet_rawPt);
   fChain->SetBranchAddress("DiscJet_mcPt", DiscJet_mcPt, &b_DiscJet_mcPt);
   fChain->SetBranchAddress("DiscJet_mcFlavour", DiscJet_mcFlavour, &b_DiscJet_mcFlavour);
   fChain->SetBranchAddress("DiscJet_mcMatchId", DiscJet_mcMatchId, &b_DiscJet_mcMatchId);
   fChain->SetBranchAddress("DiscJet_corr_JECUp", DiscJet_corr_JECUp, &b_DiscJet_corr_JECUp);
   fChain->SetBranchAddress("DiscJet_corr_JECDown", DiscJet_corr_JECDown, &b_DiscJet_corr_JECDown);
   fChain->SetBranchAddress("DiscJet_corr", DiscJet_corr, &b_DiscJet_corr);
   fChain->SetBranchAddress("DiscJet_pt", DiscJet_pt, &b_DiscJet_pt);
   fChain->SetBranchAddress("DiscJet_eta", DiscJet_eta, &b_DiscJet_eta);
   fChain->SetBranchAddress("DiscJet_phi", DiscJet_phi, &b_DiscJet_phi);
   fChain->SetBranchAddress("DiscJet_mass", DiscJet_mass, &b_DiscJet_mass);
   fChain->SetBranchAddress("DiscJet_mcMatchFlav", DiscJet_mcMatchFlav, &b_DiscJet_mcMatchFlav);
   fChain->SetBranchAddress("DiscJet_charge", DiscJet_charge, &b_DiscJet_charge);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_charge", SV_charge, &b_SV_charge);
   fChain->SetBranchAddress("SV_ntracks", SV_ntracks, &b_SV_ntracks);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_dxy", SV_dxy, &b_SV_dxy);
   fChain->SetBranchAddress("SV_edxy", SV_edxy, &b_SV_edxy);
   fChain->SetBranchAddress("SV_ip3d", SV_ip3d, &b_SV_ip3d);
   fChain->SetBranchAddress("SV_eip3d", SV_eip3d, &b_SV_eip3d);
   fChain->SetBranchAddress("SV_sip3d", SV_sip3d, &b_SV_sip3d);
   fChain->SetBranchAddress("SV_cosTheta", SV_cosTheta, &b_SV_cosTheta);
   fChain->SetBranchAddress("SV_mva", SV_mva, &b_SV_mva);
   fChain->SetBranchAddress("SV_jetPt", SV_jetPt, &b_SV_jetPt);
   fChain->SetBranchAddress("SV_jetBTagCSV", SV_jetBTagCSV, &b_SV_jetBTagCSV);
   fChain->SetBranchAddress("SV_jetBTagCMVA", SV_jetBTagCMVA, &b_SV_jetBTagCMVA);
   fChain->SetBranchAddress("SV_mcMatchNTracks", SV_mcMatchNTracks, &b_SV_mcMatchNTracks);
   fChain->SetBranchAddress("SV_mcMatchNTracksHF", SV_mcMatchNTracksHF, &b_SV_mcMatchNTracksHF);
   fChain->SetBranchAddress("SV_mcMatchFraction", SV_mcMatchFraction, &b_SV_mcMatchFraction);
   fChain->SetBranchAddress("SV_mcFlavFirst", SV_mcFlavFirst, &b_SV_mcFlavFirst);
   fChain->SetBranchAddress("SV_mcFlavHeaviest", SV_mcFlavHeaviest, &b_SV_mcFlavHeaviest);
   fChain->SetBranchAddress("SV_maxDxyTracks", SV_maxDxyTracks, &b_SV_maxDxyTracks);
   fChain->SetBranchAddress("SV_secDxyTracks", SV_secDxyTracks, &b_SV_secDxyTracks);
   fChain->SetBranchAddress("SV_maxD3dTracks", SV_maxD3dTracks, &b_SV_maxD3dTracks);
   fChain->SetBranchAddress("SV_secD3dTracks", SV_secD3dTracks, &b_SV_secD3dTracks);
   fChain->SetBranchAddress("nLepGood", &nLepGood, &b_nLepGood);
   fChain->SetBranchAddress("LepGood_mvaIdPhys14", LepGood_mvaIdPhys14, &b_LepGood_mvaIdPhys14);
   fChain->SetBranchAddress("LepGood_mvaIdSpring15", LepGood_mvaIdSpring15, &b_LepGood_mvaIdSpring15);
   fChain->SetBranchAddress("LepGood_mvaTTH", LepGood_mvaTTH, &b_LepGood_mvaTTH);
   fChain->SetBranchAddress("LepGood_jetPtRatiov1", LepGood_jetPtRatiov1, &b_LepGood_jetPtRatiov1);
   fChain->SetBranchAddress("LepGood_jetPtRelv1", LepGood_jetPtRelv1, &b_LepGood_jetPtRelv1);
   fChain->SetBranchAddress("LepGood_jetPtRatiov2", LepGood_jetPtRatiov2, &b_LepGood_jetPtRatiov2);
   fChain->SetBranchAddress("LepGood_jetPtRelv2", LepGood_jetPtRelv2, &b_LepGood_jetPtRelv2);
   fChain->SetBranchAddress("LepGood_jetBTagCSV", LepGood_jetBTagCSV, &b_LepGood_jetBTagCSV);
   fChain->SetBranchAddress("LepGood_jetBTagCMVA", LepGood_jetBTagCMVA, &b_LepGood_jetBTagCMVA);
   fChain->SetBranchAddress("LepGood_jetDR", LepGood_jetDR, &b_LepGood_jetDR);
   fChain->SetBranchAddress("LepGood_charge", LepGood_charge, &b_LepGood_charge);
   fChain->SetBranchAddress("LepGood_tightId", LepGood_tightId, &b_LepGood_tightId);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_25ns_v1", LepGood_eleCutIdCSA14_25ns_v1, &b_LepGood_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_50ns_v1", LepGood_eleCutIdCSA14_50ns_v1, &b_LepGood_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("LepGood_dxy", LepGood_dxy, &b_LepGood_dxy);
   fChain->SetBranchAddress("LepGood_dz", LepGood_dz, &b_LepGood_dz);
   fChain->SetBranchAddress("LepGood_edxy", LepGood_edxy, &b_LepGood_edxy);
   fChain->SetBranchAddress("LepGood_edz", LepGood_edz, &b_LepGood_edz);
   fChain->SetBranchAddress("LepGood_ip3d", LepGood_ip3d, &b_LepGood_ip3d);
   fChain->SetBranchAddress("LepGood_sip3d", LepGood_sip3d, &b_LepGood_sip3d);
   fChain->SetBranchAddress("LepGood_convVeto", LepGood_convVeto, &b_LepGood_convVeto);
   fChain->SetBranchAddress("LepGood_lostHits", LepGood_lostHits, &b_LepGood_lostHits);
   fChain->SetBranchAddress("LepGood_relIso03", LepGood_relIso03, &b_LepGood_relIso03);
   fChain->SetBranchAddress("LepGood_relIso04", LepGood_relIso04, &b_LepGood_relIso04);
   fChain->SetBranchAddress("LepGood_miniRelIso", LepGood_miniRelIso, &b_LepGood_miniRelIso);
   fChain->SetBranchAddress("LepGood_relIsoAn04", LepGood_relIsoAn04, &b_LepGood_relIsoAn04);
   fChain->SetBranchAddress("LepGood_tightCharge", LepGood_tightCharge, &b_LepGood_tightCharge);
   fChain->SetBranchAddress("LepGood_mcMatchId", LepGood_mcMatchId, &b_LepGood_mcMatchId);
   fChain->SetBranchAddress("LepGood_mcMatchAny", LepGood_mcMatchAny, &b_LepGood_mcMatchAny);
   fChain->SetBranchAddress("LepGood_mcMatchTau", LepGood_mcMatchTau, &b_LepGood_mcMatchTau);
   fChain->SetBranchAddress("LepGood_mcPt", LepGood_mcPt, &b_LepGood_mcPt);
   fChain->SetBranchAddress("LepGood_mediumMuonId", LepGood_mediumMuonId, &b_LepGood_mediumMuonId);
   fChain->SetBranchAddress("LepGood_pdgId", LepGood_pdgId, &b_LepGood_pdgId);
   fChain->SetBranchAddress("LepGood_pt", LepGood_pt, &b_LepGood_pt);
   fChain->SetBranchAddress("LepGood_eta", LepGood_eta, &b_LepGood_eta);
   fChain->SetBranchAddress("LepGood_phi", LepGood_phi, &b_LepGood_phi);
   fChain->SetBranchAddress("LepGood_mass", LepGood_mass, &b_LepGood_mass);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso03", LepGood_chargedHadRelIso03, &b_LepGood_chargedHadRelIso03);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso04", LepGood_chargedHadRelIso04, &b_LepGood_chargedHadRelIso04);
   fChain->SetBranchAddress("LepGood_softMuonId", LepGood_softMuonId, &b_LepGood_softMuonId);
   fChain->SetBranchAddress("LepGood_pfMuonId", LepGood_pfMuonId, &b_LepGood_pfMuonId);
   fChain->SetBranchAddress("LepGood_eleCutId2012_full5x5", LepGood_eleCutId2012_full5x5, &b_LepGood_eleCutId2012_full5x5);
   fChain->SetBranchAddress("LepGood_trackerLayers", LepGood_trackerLayers, &b_LepGood_trackerLayers);
   fChain->SetBranchAddress("LepGood_pixelLayers", LepGood_pixelLayers, &b_LepGood_pixelLayers);
   fChain->SetBranchAddress("LepGood_trackerHits", LepGood_trackerHits, &b_LepGood_trackerHits);
   fChain->SetBranchAddress("LepGood_lostOuterHits", LepGood_lostOuterHits, &b_LepGood_lostOuterHits);
   fChain->SetBranchAddress("LepGood_innerTrackValidHitFraction", LepGood_innerTrackValidHitFraction, &b_LepGood_innerTrackValidHitFraction);
   fChain->SetBranchAddress("LepGood_innerTrackChi2", LepGood_innerTrackChi2, &b_LepGood_innerTrackChi2);
   fChain->SetBranchAddress("LepGood_nStations", LepGood_nStations, &b_LepGood_nStations);
   fChain->SetBranchAddress("LepGood_caloCompatibility", LepGood_caloCompatibility, &b_LepGood_caloCompatibility);
   fChain->SetBranchAddress("LepGood_globalTrackChi2", LepGood_globalTrackChi2, &b_LepGood_globalTrackChi2);
   fChain->SetBranchAddress("LepGood_trkKink", LepGood_trkKink, &b_LepGood_trkKink);
   fChain->SetBranchAddress("LepGood_segmentCompatibility", LepGood_segmentCompatibility, &b_LepGood_segmentCompatibility);
   fChain->SetBranchAddress("LepGood_chi2LocalPosition", LepGood_chi2LocalPosition, &b_LepGood_chi2LocalPosition);
   fChain->SetBranchAddress("LepGood_chi2LocalMomentum", LepGood_chi2LocalMomentum, &b_LepGood_chi2LocalMomentum);
   fChain->SetBranchAddress("LepGood_glbTrackProbability", LepGood_glbTrackProbability, &b_LepGood_glbTrackProbability);
   fChain->SetBranchAddress("LepGood_sigmaIEtaIEta", LepGood_sigmaIEtaIEta, &b_LepGood_sigmaIEtaIEta);
   fChain->SetBranchAddress("LepGood_dEtaScTrkIn", LepGood_dEtaScTrkIn, &b_LepGood_dEtaScTrkIn);
   fChain->SetBranchAddress("LepGood_dPhiScTrkIn", LepGood_dPhiScTrkIn, &b_LepGood_dPhiScTrkIn);
   fChain->SetBranchAddress("LepGood_hadronicOverEm", LepGood_hadronicOverEm, &b_LepGood_hadronicOverEm);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv", LepGood_eInvMinusPInv, &b_LepGood_eInvMinusPInv);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv_tkMom", LepGood_eInvMinusPInv_tkMom, &b_LepGood_eInvMinusPInv_tkMom);
   fChain->SetBranchAddress("LepGood_etaSc", LepGood_etaSc, &b_LepGood_etaSc);
   fChain->SetBranchAddress("LepGood_miniRelIsoCharged", LepGood_miniRelIsoCharged, &b_LepGood_miniRelIsoCharged);
   fChain->SetBranchAddress("LepGood_miniRelIsoNeutral", LepGood_miniRelIsoNeutral, &b_LepGood_miniRelIsoNeutral);
   fChain->SetBranchAddress("LepGood_hasSV", LepGood_hasSV, &b_LepGood_hasSV);
   fChain->SetBranchAddress("LepGood_svRedPt", LepGood_svRedPt, &b_LepGood_svRedPt);
   fChain->SetBranchAddress("LepGood_svRedM", LepGood_svRedM, &b_LepGood_svRedM);
   fChain->SetBranchAddress("LepGood_svLepSip3d", LepGood_svLepSip3d, &b_LepGood_svLepSip3d);
   fChain->SetBranchAddress("LepGood_svSip3d", LepGood_svSip3d, &b_LepGood_svSip3d);
   fChain->SetBranchAddress("LepGood_svNTracks", LepGood_svNTracks, &b_LepGood_svNTracks);
   fChain->SetBranchAddress("LepGood_svChi2n", LepGood_svChi2n, &b_LepGood_svChi2n);
   fChain->SetBranchAddress("LepGood_svDxy", LepGood_svDxy, &b_LepGood_svDxy);
   fChain->SetBranchAddress("LepGood_svMass", LepGood_svMass, &b_LepGood_svMass);
   fChain->SetBranchAddress("LepGood_svPt", LepGood_svPt, &b_LepGood_svPt);
   fChain->SetBranchAddress("LepGood_svMCMatchFraction", LepGood_svMCMatchFraction, &b_LepGood_svMCMatchFraction);
   fChain->SetBranchAddress("LepGood_svMva", LepGood_svMva, &b_LepGood_svMva);
   fChain->SetBranchAddress("LepGood_jetNDau", LepGood_jetNDau, &b_LepGood_jetNDau);
   fChain->SetBranchAddress("LepGood_jetNDauCharged", LepGood_jetNDauCharged, &b_LepGood_jetNDauCharged);
   fChain->SetBranchAddress("LepGood_jetNDauPV", LepGood_jetNDauPV, &b_LepGood_jetNDauPV);
   fChain->SetBranchAddress("LepGood_jetNDauNotPV", LepGood_jetNDauNotPV, &b_LepGood_jetNDauNotPV);
   fChain->SetBranchAddress("LepGood_jetmaxSignedSip3D", LepGood_jetmaxSignedSip3D, &b_LepGood_jetmaxSignedSip3D);
   fChain->SetBranchAddress("LepGood_jetmaxSip3D", LepGood_jetmaxSip3D, &b_LepGood_jetmaxSip3D);
   fChain->SetBranchAddress("LepGood_jetmaxSignedSip2D", LepGood_jetmaxSignedSip2D, &b_LepGood_jetmaxSignedSip2D);
   fChain->SetBranchAddress("LepGood_jetmaxSip2D", LepGood_jetmaxSip2D, &b_LepGood_jetmaxSip2D);
   fChain->SetBranchAddress("LepGood_jetPtRelv0", LepGood_jetPtRelv0, &b_LepGood_jetPtRelv0);
   fChain->SetBranchAddress("LepGood_jetMass", LepGood_jetMass, &b_LepGood_jetMass);
   fChain->SetBranchAddress("LepGood_jetPrunedMass", LepGood_jetPrunedMass, &b_LepGood_jetPrunedMass);
   fChain->SetBranchAddress("LepGood_jetDecDR", LepGood_jetDecDR, &b_LepGood_jetDecDR);
   fChain->SetBranchAddress("LepGood_jetDecPtRel", LepGood_jetDecPtRel, &b_LepGood_jetDecPtRel);
   fChain->SetBranchAddress("LepGood_jetDecPtRatio", LepGood_jetDecPtRatio, &b_LepGood_jetDecPtRatio);
   fChain->SetBranchAddress("LepGood_jetDecPrunedMass", LepGood_jetDecPrunedMass, &b_LepGood_jetDecPrunedMass);
   fChain->SetBranchAddress("LepGood_jetDecPrunedPtRatio", LepGood_jetDecPrunedPtRatio, &b_LepGood_jetDecPrunedPtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02DR", LepGood_jetDec02DR, &b_LepGood_jetDec02DR);
   fChain->SetBranchAddress("LepGood_jetDec02PtRel", LepGood_jetDec02PtRel, &b_LepGood_jetDec02PtRel);
   fChain->SetBranchAddress("LepGood_jetDec02PtRatio", LepGood_jetDec02PtRatio, &b_LepGood_jetDec02PtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02PrunedPtRatio", LepGood_jetDec02PrunedPtRatio, &b_LepGood_jetDec02PrunedPtRatio);
   fChain->SetBranchAddress("LepGood_jetDec02PrunedMass", LepGood_jetDec02PrunedMass, &b_LepGood_jetDec02PrunedMass);
   fChain->SetBranchAddress("LepGood_jetRawPt", LepGood_jetRawPt, &b_LepGood_jetRawPt);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1", LepGood_jetCorrFactor_L1, &b_LepGood_jetCorrFactor_L1);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2", LepGood_jetCorrFactor_L1L2, &b_LepGood_jetCorrFactor_L1L2);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3", LepGood_jetCorrFactor_L1L2L3, &b_LepGood_jetCorrFactor_L1L2L3);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3Res", LepGood_jetCorrFactor_L1L2L3Res, &b_LepGood_jetCorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("LepGood_jetPtRatio_Raw", LepGood_jetPtRatio_Raw, &b_LepGood_jetPtRatio_Raw);
   fChain->SetBranchAddress("LepGood_jetPtRelHv2", LepGood_jetPtRelHv2, &b_LepGood_jetPtRelHv2);
   fChain->SetBranchAddress("LepGood_ecalPFClusterIso", LepGood_ecalPFClusterIso, &b_LepGood_ecalPFClusterIso);
   fChain->SetBranchAddress("LepGood_hcalPFClusterIso", LepGood_hcalPFClusterIso, &b_LepGood_hcalPFClusterIso);
   fChain->SetBranchAddress("LepGood_dr03TkSumPt", LepGood_dr03TkSumPt, &b_LepGood_dr03TkSumPt);
   fChain->SetBranchAddress("LepGood_trackIso", LepGood_trackIso, &b_LepGood_trackIso);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_pt", LepGood_jetLepAwareJEC_pt, &b_LepGood_jetLepAwareJEC_pt);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_eta", LepGood_jetLepAwareJEC_eta, &b_LepGood_jetLepAwareJEC_eta);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_phi", LepGood_jetLepAwareJEC_phi, &b_LepGood_jetLepAwareJEC_phi);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_energy", LepGood_jetLepAwareJEC_energy, &b_LepGood_jetLepAwareJEC_energy);
   fChain->SetBranchAddress("nGenDHad", &nGenDHad, &b_nGenDHad);
   fChain->SetBranchAddress("GenDHad_charge", GenDHad_charge, &b_GenDHad_charge);
   fChain->SetBranchAddress("GenDHad_status", GenDHad_status, &b_GenDHad_status);
   fChain->SetBranchAddress("GenDHad_pdgId", GenDHad_pdgId, &b_GenDHad_pdgId);
   fChain->SetBranchAddress("GenDHad_pt", GenDHad_pt, &b_GenDHad_pt);
   fChain->SetBranchAddress("GenDHad_eta", GenDHad_eta, &b_GenDHad_eta);
   fChain->SetBranchAddress("GenDHad_phi", GenDHad_phi, &b_GenDHad_phi);
   fChain->SetBranchAddress("GenDHad_mass", GenDHad_mass, &b_GenDHad_mass);
   fChain->SetBranchAddress("GenDHad_flav", GenDHad_flav, &b_GenDHad_flav);
   fChain->SetBranchAddress("GenDHad_sourceId", GenDHad_sourceId, &b_GenDHad_sourceId);
   fChain->SetBranchAddress("GenDHad_svMass", GenDHad_svMass, &b_GenDHad_svMass);
   fChain->SetBranchAddress("GenDHad_svPt", GenDHad_svPt, &b_GenDHad_svPt);
   fChain->SetBranchAddress("GenDHad_svCharge", GenDHad_svCharge, &b_GenDHad_svCharge);
   fChain->SetBranchAddress("GenDHad_svNtracks", GenDHad_svNtracks, &b_GenDHad_svNtracks);
   fChain->SetBranchAddress("GenDHad_svChi2", GenDHad_svChi2, &b_GenDHad_svChi2);
   fChain->SetBranchAddress("GenDHad_svNdof", GenDHad_svNdof, &b_GenDHad_svNdof);
   fChain->SetBranchAddress("GenDHad_svDxy", GenDHad_svDxy, &b_GenDHad_svDxy);
   fChain->SetBranchAddress("GenDHad_svEdxy", GenDHad_svEdxy, &b_GenDHad_svEdxy);
   fChain->SetBranchAddress("GenDHad_svIp3d", GenDHad_svIp3d, &b_GenDHad_svIp3d);
   fChain->SetBranchAddress("GenDHad_svEip3d", GenDHad_svEip3d, &b_GenDHad_svEip3d);
   fChain->SetBranchAddress("GenDHad_svSip3d", GenDHad_svSip3d, &b_GenDHad_svSip3d);
   fChain->SetBranchAddress("GenDHad_svCosTheta", GenDHad_svCosTheta, &b_GenDHad_svCosTheta);
   fChain->SetBranchAddress("GenDHad_svMva", GenDHad_svMva, &b_GenDHad_svMva);
   fChain->SetBranchAddress("GenDHad_jetPt", GenDHad_jetPt, &b_GenDHad_jetPt);
   fChain->SetBranchAddress("GenDHad_jetBTagCSV", GenDHad_jetBTagCSV, &b_GenDHad_jetBTagCSV);
   fChain->SetBranchAddress("GenDHad_jetBTagCMVA", GenDHad_jetBTagCMVA, &b_GenDHad_jetBTagCMVA);
   fChain->SetBranchAddress("nGenBHad", &nGenBHad, &b_nGenBHad);
   fChain->SetBranchAddress("GenBHad_charge", GenBHad_charge, &b_GenBHad_charge);
   fChain->SetBranchAddress("GenBHad_status", GenBHad_status, &b_GenBHad_status);
   fChain->SetBranchAddress("GenBHad_pdgId", GenBHad_pdgId, &b_GenBHad_pdgId);
   fChain->SetBranchAddress("GenBHad_pt", GenBHad_pt, &b_GenBHad_pt);
   fChain->SetBranchAddress("GenBHad_eta", GenBHad_eta, &b_GenBHad_eta);
   fChain->SetBranchAddress("GenBHad_phi", GenBHad_phi, &b_GenBHad_phi);
   fChain->SetBranchAddress("GenBHad_mass", GenBHad_mass, &b_GenBHad_mass);
   fChain->SetBranchAddress("GenBHad_flav", GenBHad_flav, &b_GenBHad_flav);
   fChain->SetBranchAddress("GenBHad_sourceId", GenBHad_sourceId, &b_GenBHad_sourceId);
   fChain->SetBranchAddress("GenBHad_svMass", GenBHad_svMass, &b_GenBHad_svMass);
   fChain->SetBranchAddress("GenBHad_svPt", GenBHad_svPt, &b_GenBHad_svPt);
   fChain->SetBranchAddress("GenBHad_svCharge", GenBHad_svCharge, &b_GenBHad_svCharge);
   fChain->SetBranchAddress("GenBHad_svNtracks", GenBHad_svNtracks, &b_GenBHad_svNtracks);
   fChain->SetBranchAddress("GenBHad_svChi2", GenBHad_svChi2, &b_GenBHad_svChi2);
   fChain->SetBranchAddress("GenBHad_svNdof", GenBHad_svNdof, &b_GenBHad_svNdof);
   fChain->SetBranchAddress("GenBHad_svDxy", GenBHad_svDxy, &b_GenBHad_svDxy);
   fChain->SetBranchAddress("GenBHad_svEdxy", GenBHad_svEdxy, &b_GenBHad_svEdxy);
   fChain->SetBranchAddress("GenBHad_svIp3d", GenBHad_svIp3d, &b_GenBHad_svIp3d);
   fChain->SetBranchAddress("GenBHad_svEip3d", GenBHad_svEip3d, &b_GenBHad_svEip3d);
   fChain->SetBranchAddress("GenBHad_svSip3d", GenBHad_svSip3d, &b_GenBHad_svSip3d);
   fChain->SetBranchAddress("GenBHad_svCosTheta", GenBHad_svCosTheta, &b_GenBHad_svCosTheta);
   fChain->SetBranchAddress("GenBHad_svMva", GenBHad_svMva, &b_GenBHad_svMva);
   fChain->SetBranchAddress("GenBHad_jetPt", GenBHad_jetPt, &b_GenBHad_jetPt);
   fChain->SetBranchAddress("GenBHad_jetBTagCSV", GenBHad_jetBTagCSV, &b_GenBHad_jetBTagCSV);
   fChain->SetBranchAddress("GenBHad_jetBTagCMVA", GenBHad_jetBTagCMVA, &b_GenBHad_jetBTagCMVA);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_mcMatchFlav", Jet_mcMatchFlav, &b_Jet_mcMatchFlav);
   fChain->SetBranchAddress("Jet_charge", Jet_charge, &b_Jet_charge);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_ptd", Jet_ptd, &b_Jet_ptd);
   fChain->SetBranchAddress("Jet_axis2", Jet_axis2, &b_Jet_axis2);
   fChain->SetBranchAddress("Jet_mult", Jet_mult, &b_Jet_mult);
   fChain->SetBranchAddress("Jet_partonId", Jet_partonId, &b_Jet_partonId);
   fChain->SetBranchAddress("Jet_partonMotherId", Jet_partonMotherId, &b_Jet_partonMotherId);
   fChain->SetBranchAddress("Jet_nLeptons", Jet_nLeptons, &b_Jet_nLeptons);
   fChain->SetBranchAddress("Jet_id", Jet_id, &b_Jet_id);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_rawPt", Jet_rawPt, &b_Jet_rawPt);
   fChain->SetBranchAddress("Jet_mcPt", Jet_mcPt, &b_Jet_mcPt);
   fChain->SetBranchAddress("Jet_mcFlavour", Jet_mcFlavour, &b_Jet_mcFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_corr_JECUp", Jet_corr_JECUp, &b_Jet_corr_JECUp);
   fChain->SetBranchAddress("Jet_corr_JECDown", Jet_corr_JECDown, &b_Jet_corr_JECDown);
   fChain->SetBranchAddress("Jet_corr", Jet_corr, &b_Jet_corr);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_prunedMass", Jet_prunedMass, &b_Jet_prunedMass);
   fChain->SetBranchAddress("Jet_mcNumPartons", Jet_mcNumPartons, &b_Jet_mcNumPartons);
   fChain->SetBranchAddress("Jet_mcNumLeptons", Jet_mcNumLeptons, &b_Jet_mcNumLeptons);
   fChain->SetBranchAddress("Jet_mcNumTaus", Jet_mcNumTaus, &b_Jet_mcNumTaus);
   fChain->SetBranchAddress("Jet_mcAnyPartonMass", Jet_mcAnyPartonMass, &b_Jet_mcAnyPartonMass);
   fChain->SetBranchAddress("Jet_nSubJets", Jet_nSubJets, &b_Jet_nSubJets);
   fChain->SetBranchAddress("Jet_nSubJets25", Jet_nSubJets25, &b_Jet_nSubJets25);
   fChain->SetBranchAddress("Jet_nSubJets30", Jet_nSubJets30, &b_Jet_nSubJets30);
   fChain->SetBranchAddress("Jet_nSubJets40", Jet_nSubJets40, &b_Jet_nSubJets40);
   fChain->SetBranchAddress("Jet_nSubJetsZ01", Jet_nSubJetsZ01, &b_Jet_nSubJetsZ01);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_phEF", Jet_phEF, &b_Jet_phEF);
   fChain->SetBranchAddress("Jet_eEF", Jet_eEF, &b_Jet_eEF);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_HFHEF", Jet_HFHEF, &b_Jet_HFHEF);
   fChain->SetBranchAddress("Jet_HFEMEF", Jet_HFEMEF, &b_Jet_HFEMEF);
   fChain->SetBranchAddress("Jet_chHMult", Jet_chHMult, &b_Jet_chHMult);
   fChain->SetBranchAddress("Jet_neHMult", Jet_neHMult, &b_Jet_neHMult);
   fChain->SetBranchAddress("Jet_phMult", Jet_phMult, &b_Jet_phMult);
   fChain->SetBranchAddress("Jet_eMult", Jet_eMult, &b_Jet_eMult);
   fChain->SetBranchAddress("Jet_muMult", Jet_muMult, &b_Jet_muMult);
   fChain->SetBranchAddress("Jet_HFHMult", Jet_HFHMult, &b_Jet_HFHMult);
   fChain->SetBranchAddress("Jet_HFEMMult", Jet_HFEMMult, &b_Jet_HFEMMult);
   fChain->SetBranchAddress("Jet_CorrFactor_L1", Jet_CorrFactor_L1, &b_Jet_CorrFactor_L1);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2", Jet_CorrFactor_L1L2, &b_Jet_CorrFactor_L1L2);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3", Jet_CorrFactor_L1L2L3, &b_Jet_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3Res", Jet_CorrFactor_L1L2L3Res, &b_Jet_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nJetNoTauIdx", &nJetNoTauIdx, &b_nJetNoTauIdx);
   fChain->SetBranchAddress("JetNoTauIdx", JetNoTauIdx, &b_JetNoTauIdx);
   fChain->SetBranchAddress("nLHEweight", &nLHEweight, &b_nLHEweight);
   fChain->SetBranchAddress("LHEweight_id", LHEweight_id, &b_LHEweight_id);
   fChain->SetBranchAddress("LHEweight_wgt", LHEweight_wgt, &b_LHEweight_wgt);
   fChain->SetBranchAddress("nTauGood", &nTauGood, &b_nTauGood);
   fChain->SetBranchAddress("TauGood_charge", TauGood_charge, &b_TauGood_charge);
   fChain->SetBranchAddress("TauGood_decayMode", TauGood_decayMode, &b_TauGood_decayMode);
   fChain->SetBranchAddress("TauGood_idDecayMode", TauGood_idDecayMode, &b_TauGood_idDecayMode);
   fChain->SetBranchAddress("TauGood_idDecayModeNewDMs", TauGood_idDecayModeNewDMs, &b_TauGood_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauGood_dxy", TauGood_dxy, &b_TauGood_dxy);
   fChain->SetBranchAddress("TauGood_dz", TauGood_dz, &b_TauGood_dz);
   fChain->SetBranchAddress("TauGood_idMVA", TauGood_idMVA, &b_TauGood_idMVA);
   fChain->SetBranchAddress("TauGood_idMVANewDM", TauGood_idMVANewDM, &b_TauGood_idMVANewDM);
   fChain->SetBranchAddress("TauGood_idCI3hit", TauGood_idCI3hit, &b_TauGood_idCI3hit);
   fChain->SetBranchAddress("TauGood_idAntiMu", TauGood_idAntiMu, &b_TauGood_idAntiMu);
   fChain->SetBranchAddress("TauGood_idAntiE", TauGood_idAntiE, &b_TauGood_idAntiE);
   fChain->SetBranchAddress("TauGood_isoCI3hit", TauGood_isoCI3hit, &b_TauGood_isoCI3hit);
   fChain->SetBranchAddress("TauGood_mcMatchId", TauGood_mcMatchId, &b_TauGood_mcMatchId);
   fChain->SetBranchAddress("TauGood_pdgId", TauGood_pdgId, &b_TauGood_pdgId);
   fChain->SetBranchAddress("TauGood_pt", TauGood_pt, &b_TauGood_pt);
   fChain->SetBranchAddress("TauGood_eta", TauGood_eta, &b_TauGood_eta);
   fChain->SetBranchAddress("TauGood_phi", TauGood_phi, &b_TauGood_phi);
   fChain->SetBranchAddress("TauGood_mass", TauGood_mass, &b_TauGood_mass);
   fChain->SetBranchAddress("ngenLep", &ngenLep, &b_ngenLep);
   fChain->SetBranchAddress("genLep_motherId", genLep_motherId, &b_genLep_motherId);
   fChain->SetBranchAddress("genLep_grandmotherId", genLep_grandmotherId, &b_genLep_grandmotherId);
   fChain->SetBranchAddress("genLep_sourceId", genLep_sourceId, &b_genLep_sourceId);
   fChain->SetBranchAddress("genLep_charge", genLep_charge, &b_genLep_charge);
   fChain->SetBranchAddress("genLep_status", genLep_status, &b_genLep_status);
   fChain->SetBranchAddress("genLep_pdgId", genLep_pdgId, &b_genLep_pdgId);
   fChain->SetBranchAddress("genLep_pt", genLep_pt, &b_genLep_pt);
   fChain->SetBranchAddress("genLep_eta", genLep_eta, &b_genLep_eta);
   fChain->SetBranchAddress("genLep_phi", genLep_phi, &b_genLep_phi);
   fChain->SetBranchAddress("genLep_mass", genLep_mass, &b_genLep_mass);
   fChain->SetBranchAddress("genLep_motherIndex", genLep_motherIndex, &b_genLep_motherIndex);
   fChain->SetBranchAddress("ngenTau", &ngenTau, &b_ngenTau);
   fChain->SetBranchAddress("genTau_motherId", genTau_motherId, &b_genTau_motherId);
   fChain->SetBranchAddress("genTau_grandmotherId", genTau_grandmotherId, &b_genTau_grandmotherId);
   fChain->SetBranchAddress("genTau_sourceId", genTau_sourceId, &b_genTau_sourceId);
   fChain->SetBranchAddress("genTau_charge", genTau_charge, &b_genTau_charge);
   fChain->SetBranchAddress("genTau_status", genTau_status, &b_genTau_status);
   fChain->SetBranchAddress("genTau_pdgId", genTau_pdgId, &b_genTau_pdgId);
   fChain->SetBranchAddress("genTau_pt", genTau_pt, &b_genTau_pt);
   fChain->SetBranchAddress("genTau_eta", genTau_eta, &b_genTau_eta);
   fChain->SetBranchAddress("genTau_phi", genTau_phi, &b_genTau_phi);
   fChain->SetBranchAddress("genTau_mass", genTau_mass, &b_genTau_mass);
   fChain->SetBranchAddress("genTau_motherIndex", genTau_motherIndex, &b_genTau_motherIndex);
   fChain->SetBranchAddress("nGenTop", &nGenTop, &b_nGenTop);
   fChain->SetBranchAddress("GenTop_pdgId", GenTop_pdgId, &b_GenTop_pdgId);
   fChain->SetBranchAddress("GenTop_pt", GenTop_pt, &b_GenTop_pt);
   fChain->SetBranchAddress("GenTop_eta", GenTop_eta, &b_GenTop_eta);
   fChain->SetBranchAddress("GenTop_phi", GenTop_phi, &b_GenTop_phi);
   fChain->SetBranchAddress("GenTop_mass", GenTop_mass, &b_GenTop_mass);
   fChain->SetBranchAddress("GenTop_charge", GenTop_charge, &b_GenTop_charge);
   fChain->SetBranchAddress("GenTop_status", GenTop_status, &b_GenTop_status);
   fChain->SetBranchAddress("nLepOther", &nLepOther, &b_nLepOther);
   fChain->SetBranchAddress("LepOther_mvaIdPhys14", LepOther_mvaIdPhys14, &b_LepOther_mvaIdPhys14);
   fChain->SetBranchAddress("LepOther_mvaIdSpring15", LepOther_mvaIdSpring15, &b_LepOther_mvaIdSpring15);
   fChain->SetBranchAddress("LepOther_mvaTTH", LepOther_mvaTTH, &b_LepOther_mvaTTH);
   fChain->SetBranchAddress("LepOther_jetPtRatiov1", LepOther_jetPtRatiov1, &b_LepOther_jetPtRatiov1);
   fChain->SetBranchAddress("LepOther_jetPtRelv1", LepOther_jetPtRelv1, &b_LepOther_jetPtRelv1);
   fChain->SetBranchAddress("LepOther_jetPtRatiov2", LepOther_jetPtRatiov2, &b_LepOther_jetPtRatiov2);
   fChain->SetBranchAddress("LepOther_jetPtRelv2", LepOther_jetPtRelv2, &b_LepOther_jetPtRelv2);
   fChain->SetBranchAddress("LepOther_jetBTagCSV", LepOther_jetBTagCSV, &b_LepOther_jetBTagCSV);
   fChain->SetBranchAddress("LepOther_jetBTagCMVA", LepOther_jetBTagCMVA, &b_LepOther_jetBTagCMVA);
   fChain->SetBranchAddress("LepOther_jetDR", LepOther_jetDR, &b_LepOther_jetDR);
   fChain->SetBranchAddress("LepOther_charge", LepOther_charge, &b_LepOther_charge);
   fChain->SetBranchAddress("LepOther_tightId", LepOther_tightId, &b_LepOther_tightId);
   fChain->SetBranchAddress("LepOther_eleCutIdCSA14_25ns_v1", LepOther_eleCutIdCSA14_25ns_v1, &b_LepOther_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("LepOther_eleCutIdCSA14_50ns_v1", LepOther_eleCutIdCSA14_50ns_v1, &b_LepOther_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("LepOther_dxy", LepOther_dxy, &b_LepOther_dxy);
   fChain->SetBranchAddress("LepOther_dz", LepOther_dz, &b_LepOther_dz);
   fChain->SetBranchAddress("LepOther_edxy", LepOther_edxy, &b_LepOther_edxy);
   fChain->SetBranchAddress("LepOther_edz", LepOther_edz, &b_LepOther_edz);
   fChain->SetBranchAddress("LepOther_ip3d", LepOther_ip3d, &b_LepOther_ip3d);
   fChain->SetBranchAddress("LepOther_sip3d", LepOther_sip3d, &b_LepOther_sip3d);
   fChain->SetBranchAddress("LepOther_convVeto", LepOther_convVeto, &b_LepOther_convVeto);
   fChain->SetBranchAddress("LepOther_lostHits", LepOther_lostHits, &b_LepOther_lostHits);
   fChain->SetBranchAddress("LepOther_relIso03", LepOther_relIso03, &b_LepOther_relIso03);
   fChain->SetBranchAddress("LepOther_relIso04", LepOther_relIso04, &b_LepOther_relIso04);
   fChain->SetBranchAddress("LepOther_miniRelIso", LepOther_miniRelIso, &b_LepOther_miniRelIso);
   fChain->SetBranchAddress("LepOther_relIsoAn04", LepOther_relIsoAn04, &b_LepOther_relIsoAn04);
   fChain->SetBranchAddress("LepOther_tightCharge", LepOther_tightCharge, &b_LepOther_tightCharge);
   fChain->SetBranchAddress("LepOther_mcMatchId", LepOther_mcMatchId, &b_LepOther_mcMatchId);
   fChain->SetBranchAddress("LepOther_mcMatchAny", LepOther_mcMatchAny, &b_LepOther_mcMatchAny);
   fChain->SetBranchAddress("LepOther_mcMatchTau", LepOther_mcMatchTau, &b_LepOther_mcMatchTau);
   fChain->SetBranchAddress("LepOther_mcPt", LepOther_mcPt, &b_LepOther_mcPt);
   fChain->SetBranchAddress("LepOther_mediumMuonId", LepOther_mediumMuonId, &b_LepOther_mediumMuonId);
   fChain->SetBranchAddress("LepOther_pdgId", LepOther_pdgId, &b_LepOther_pdgId);
   fChain->SetBranchAddress("LepOther_pt", LepOther_pt, &b_LepOther_pt);
   fChain->SetBranchAddress("LepOther_eta", LepOther_eta, &b_LepOther_eta);
   fChain->SetBranchAddress("LepOther_phi", LepOther_phi, &b_LepOther_phi);
   fChain->SetBranchAddress("LepOther_mass", LepOther_mass, &b_LepOther_mass);
   fChain->SetBranchAddress("LepOther_chargedHadRelIso03", LepOther_chargedHadRelIso03, &b_LepOther_chargedHadRelIso03);
   fChain->SetBranchAddress("LepOther_chargedHadRelIso04", LepOther_chargedHadRelIso04, &b_LepOther_chargedHadRelIso04);
   fChain->SetBranchAddress("LepOther_softMuonId", LepOther_softMuonId, &b_LepOther_softMuonId);
   fChain->SetBranchAddress("LepOther_pfMuonId", LepOther_pfMuonId, &b_LepOther_pfMuonId);
   fChain->SetBranchAddress("LepOther_eleCutId2012_full5x5", LepOther_eleCutId2012_full5x5, &b_LepOther_eleCutId2012_full5x5);
   fChain->SetBranchAddress("LepOther_trackerLayers", LepOther_trackerLayers, &b_LepOther_trackerLayers);
   fChain->SetBranchAddress("LepOther_pixelLayers", LepOther_pixelLayers, &b_LepOther_pixelLayers);
   fChain->SetBranchAddress("LepOther_trackerHits", LepOther_trackerHits, &b_LepOther_trackerHits);
   fChain->SetBranchAddress("LepOther_lostOuterHits", LepOther_lostOuterHits, &b_LepOther_lostOuterHits);
   fChain->SetBranchAddress("LepOther_innerTrackValidHitFraction", LepOther_innerTrackValidHitFraction, &b_LepOther_innerTrackValidHitFraction);
   fChain->SetBranchAddress("LepOther_innerTrackChi2", LepOther_innerTrackChi2, &b_LepOther_innerTrackChi2);
   fChain->SetBranchAddress("LepOther_nStations", LepOther_nStations, &b_LepOther_nStations);
   fChain->SetBranchAddress("LepOther_caloCompatibility", LepOther_caloCompatibility, &b_LepOther_caloCompatibility);
   fChain->SetBranchAddress("LepOther_globalTrackChi2", LepOther_globalTrackChi2, &b_LepOther_globalTrackChi2);
   fChain->SetBranchAddress("LepOther_trkKink", LepOther_trkKink, &b_LepOther_trkKink);
   fChain->SetBranchAddress("LepOther_segmentCompatibility", LepOther_segmentCompatibility, &b_LepOther_segmentCompatibility);
   fChain->SetBranchAddress("LepOther_chi2LocalPosition", LepOther_chi2LocalPosition, &b_LepOther_chi2LocalPosition);
   fChain->SetBranchAddress("LepOther_chi2LocalMomentum", LepOther_chi2LocalMomentum, &b_LepOther_chi2LocalMomentum);
   fChain->SetBranchAddress("LepOther_glbTrackProbability", LepOther_glbTrackProbability, &b_LepOther_glbTrackProbability);
   fChain->SetBranchAddress("LepOther_sigmaIEtaIEta", LepOther_sigmaIEtaIEta, &b_LepOther_sigmaIEtaIEta);
   fChain->SetBranchAddress("LepOther_dEtaScTrkIn", LepOther_dEtaScTrkIn, &b_LepOther_dEtaScTrkIn);
   fChain->SetBranchAddress("LepOther_dPhiScTrkIn", LepOther_dPhiScTrkIn, &b_LepOther_dPhiScTrkIn);
   fChain->SetBranchAddress("LepOther_hadronicOverEm", LepOther_hadronicOverEm, &b_LepOther_hadronicOverEm);
   fChain->SetBranchAddress("LepOther_eInvMinusPInv", LepOther_eInvMinusPInv, &b_LepOther_eInvMinusPInv);
   fChain->SetBranchAddress("LepOther_eInvMinusPInv_tkMom", LepOther_eInvMinusPInv_tkMom, &b_LepOther_eInvMinusPInv_tkMom);
   fChain->SetBranchAddress("LepOther_etaSc", LepOther_etaSc, &b_LepOther_etaSc);
   fChain->SetBranchAddress("LepOther_miniRelIsoCharged", LepOther_miniRelIsoCharged, &b_LepOther_miniRelIsoCharged);
   fChain->SetBranchAddress("LepOther_miniRelIsoNeutral", LepOther_miniRelIsoNeutral, &b_LepOther_miniRelIsoNeutral);
   fChain->SetBranchAddress("LepOther_hasSV", LepOther_hasSV, &b_LepOther_hasSV);
   fChain->SetBranchAddress("LepOther_svRedPt", LepOther_svRedPt, &b_LepOther_svRedPt);
   fChain->SetBranchAddress("LepOther_svRedM", LepOther_svRedM, &b_LepOther_svRedM);
   fChain->SetBranchAddress("LepOther_svLepSip3d", LepOther_svLepSip3d, &b_LepOther_svLepSip3d);
   fChain->SetBranchAddress("LepOther_svSip3d", LepOther_svSip3d, &b_LepOther_svSip3d);
   fChain->SetBranchAddress("LepOther_svNTracks", LepOther_svNTracks, &b_LepOther_svNTracks);
   fChain->SetBranchAddress("LepOther_svChi2n", LepOther_svChi2n, &b_LepOther_svChi2n);
   fChain->SetBranchAddress("LepOther_svDxy", LepOther_svDxy, &b_LepOther_svDxy);
   fChain->SetBranchAddress("LepOther_svMass", LepOther_svMass, &b_LepOther_svMass);
   fChain->SetBranchAddress("LepOther_svPt", LepOther_svPt, &b_LepOther_svPt);
   fChain->SetBranchAddress("LepOther_svMCMatchFraction", LepOther_svMCMatchFraction, &b_LepOther_svMCMatchFraction);
   fChain->SetBranchAddress("LepOther_svMva", LepOther_svMva, &b_LepOther_svMva);
   fChain->SetBranchAddress("LepOther_jetNDau", LepOther_jetNDau, &b_LepOther_jetNDau);
   fChain->SetBranchAddress("LepOther_jetNDauCharged", LepOther_jetNDauCharged, &b_LepOther_jetNDauCharged);
   fChain->SetBranchAddress("LepOther_jetNDauPV", LepOther_jetNDauPV, &b_LepOther_jetNDauPV);
   fChain->SetBranchAddress("LepOther_jetNDauNotPV", LepOther_jetNDauNotPV, &b_LepOther_jetNDauNotPV);
   fChain->SetBranchAddress("LepOther_jetmaxSignedSip3D", LepOther_jetmaxSignedSip3D, &b_LepOther_jetmaxSignedSip3D);
   fChain->SetBranchAddress("LepOther_jetmaxSip3D", LepOther_jetmaxSip3D, &b_LepOther_jetmaxSip3D);
   fChain->SetBranchAddress("LepOther_jetmaxSignedSip2D", LepOther_jetmaxSignedSip2D, &b_LepOther_jetmaxSignedSip2D);
   fChain->SetBranchAddress("LepOther_jetmaxSip2D", LepOther_jetmaxSip2D, &b_LepOther_jetmaxSip2D);
   fChain->SetBranchAddress("LepOther_jetPtRelv0", LepOther_jetPtRelv0, &b_LepOther_jetPtRelv0);
   fChain->SetBranchAddress("LepOther_jetMass", LepOther_jetMass, &b_LepOther_jetMass);
   fChain->SetBranchAddress("LepOther_jetPrunedMass", LepOther_jetPrunedMass, &b_LepOther_jetPrunedMass);
   fChain->SetBranchAddress("LepOther_jetDecDR", LepOther_jetDecDR, &b_LepOther_jetDecDR);
   fChain->SetBranchAddress("LepOther_jetDecPtRel", LepOther_jetDecPtRel, &b_LepOther_jetDecPtRel);
   fChain->SetBranchAddress("LepOther_jetDecPtRatio", LepOther_jetDecPtRatio, &b_LepOther_jetDecPtRatio);
   fChain->SetBranchAddress("LepOther_jetDecPrunedMass", LepOther_jetDecPrunedMass, &b_LepOther_jetDecPrunedMass);
   fChain->SetBranchAddress("LepOther_jetDecPrunedPtRatio", LepOther_jetDecPrunedPtRatio, &b_LepOther_jetDecPrunedPtRatio);
   fChain->SetBranchAddress("LepOther_jetDec02DR", LepOther_jetDec02DR, &b_LepOther_jetDec02DR);
   fChain->SetBranchAddress("LepOther_jetDec02PtRel", LepOther_jetDec02PtRel, &b_LepOther_jetDec02PtRel);
   fChain->SetBranchAddress("LepOther_jetDec02PtRatio", LepOther_jetDec02PtRatio, &b_LepOther_jetDec02PtRatio);
   fChain->SetBranchAddress("LepOther_jetDec02PrunedPtRatio", LepOther_jetDec02PrunedPtRatio, &b_LepOther_jetDec02PrunedPtRatio);
   fChain->SetBranchAddress("LepOther_jetDec02PrunedMass", LepOther_jetDec02PrunedMass, &b_LepOther_jetDec02PrunedMass);
   fChain->SetBranchAddress("LepOther_jetRawPt", LepOther_jetRawPt, &b_LepOther_jetRawPt);
   fChain->SetBranchAddress("LepOther_jetCorrFactor_L1", LepOther_jetCorrFactor_L1, &b_LepOther_jetCorrFactor_L1);
   fChain->SetBranchAddress("LepOther_jetCorrFactor_L1L2", LepOther_jetCorrFactor_L1L2, &b_LepOther_jetCorrFactor_L1L2);
   fChain->SetBranchAddress("LepOther_jetCorrFactor_L1L2L3", LepOther_jetCorrFactor_L1L2L3, &b_LepOther_jetCorrFactor_L1L2L3);
   fChain->SetBranchAddress("LepOther_jetCorrFactor_L1L2L3Res", LepOther_jetCorrFactor_L1L2L3Res, &b_LepOther_jetCorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("LepOther_jetPtRatio_Raw", LepOther_jetPtRatio_Raw, &b_LepOther_jetPtRatio_Raw);
   fChain->SetBranchAddress("LepOther_jetPtRelHv2", LepOther_jetPtRelHv2, &b_LepOther_jetPtRelHv2);
   fChain->SetBranchAddress("LepOther_ecalPFClusterIso", LepOther_ecalPFClusterIso, &b_LepOther_ecalPFClusterIso);
   fChain->SetBranchAddress("LepOther_hcalPFClusterIso", LepOther_hcalPFClusterIso, &b_LepOther_hcalPFClusterIso);
   fChain->SetBranchAddress("LepOther_dr03TkSumPt", LepOther_dr03TkSumPt, &b_LepOther_dr03TkSumPt);
   fChain->SetBranchAddress("LepOther_trackIso", LepOther_trackIso, &b_LepOther_trackIso);
   fChain->SetBranchAddress("LepOther_jetLepAwareJEC_pt", LepOther_jetLepAwareJEC_pt, &b_LepOther_jetLepAwareJEC_pt);
   fChain->SetBranchAddress("LepOther_jetLepAwareJEC_eta", LepOther_jetLepAwareJEC_eta, &b_LepOther_jetLepAwareJEC_eta);
   fChain->SetBranchAddress("LepOther_jetLepAwareJEC_phi", LepOther_jetLepAwareJEC_phi, &b_LepOther_jetLepAwareJEC_phi);
   fChain->SetBranchAddress("LepOther_jetLepAwareJEC_energy", LepOther_jetLepAwareJEC_energy, &b_LepOther_jetLepAwareJEC_energy);
   fChain->SetBranchAddress("ngenLepFromTau", &ngenLepFromTau, &b_ngenLepFromTau);
   fChain->SetBranchAddress("genLepFromTau_motherId", genLepFromTau_motherId, &b_genLepFromTau_motherId);
   fChain->SetBranchAddress("genLepFromTau_grandmotherId", genLepFromTau_grandmotherId, &b_genLepFromTau_grandmotherId);
   fChain->SetBranchAddress("genLepFromTau_sourceId", genLepFromTau_sourceId, &b_genLepFromTau_sourceId);
   fChain->SetBranchAddress("genLepFromTau_charge", genLepFromTau_charge, &b_genLepFromTau_charge);
   fChain->SetBranchAddress("genLepFromTau_status", genLepFromTau_status, &b_genLepFromTau_status);
   fChain->SetBranchAddress("genLepFromTau_pdgId", genLepFromTau_pdgId, &b_genLepFromTau_pdgId);
   fChain->SetBranchAddress("genLepFromTau_pt", genLepFromTau_pt, &b_genLepFromTau_pt);
   fChain->SetBranchAddress("genLepFromTau_eta", genLepFromTau_eta, &b_genLepFromTau_eta);
   fChain->SetBranchAddress("genLepFromTau_phi", genLepFromTau_phi, &b_genLepFromTau_phi);
   fChain->SetBranchAddress("genLepFromTau_mass", genLepFromTau_mass, &b_genLepFromTau_mass);
   fChain->SetBranchAddress("genLepFromTau_motherIndex", genLepFromTau_motherIndex, &b_genLepFromTau_motherIndex);
   fChain->SetBranchAddress("nJetFwd", &nJetFwd, &b_nJetFwd);
   fChain->SetBranchAddress("JetFwd_area", JetFwd_area, &b_JetFwd_area);
   fChain->SetBranchAddress("JetFwd_qgl", JetFwd_qgl, &b_JetFwd_qgl);
   fChain->SetBranchAddress("JetFwd_ptd", JetFwd_ptd, &b_JetFwd_ptd);
   fChain->SetBranchAddress("JetFwd_axis2", JetFwd_axis2, &b_JetFwd_axis2);
   fChain->SetBranchAddress("JetFwd_mult", JetFwd_mult, &b_JetFwd_mult);
   fChain->SetBranchAddress("JetFwd_partonId", JetFwd_partonId, &b_JetFwd_partonId);
   fChain->SetBranchAddress("JetFwd_partonMotherId", JetFwd_partonMotherId, &b_JetFwd_partonMotherId);
   fChain->SetBranchAddress("JetFwd_nLeptons", JetFwd_nLeptons, &b_JetFwd_nLeptons);
   fChain->SetBranchAddress("JetFwd_id", JetFwd_id, &b_JetFwd_id);
   fChain->SetBranchAddress("JetFwd_puId", JetFwd_puId, &b_JetFwd_puId);
   fChain->SetBranchAddress("JetFwd_btagCSV", JetFwd_btagCSV, &b_JetFwd_btagCSV);
   fChain->SetBranchAddress("JetFwd_btagCMVA", JetFwd_btagCMVA, &b_JetFwd_btagCMVA);
   fChain->SetBranchAddress("JetFwd_rawPt", JetFwd_rawPt, &b_JetFwd_rawPt);
   fChain->SetBranchAddress("JetFwd_mcPt", JetFwd_mcPt, &b_JetFwd_mcPt);
   fChain->SetBranchAddress("JetFwd_mcFlavour", JetFwd_mcFlavour, &b_JetFwd_mcFlavour);
   fChain->SetBranchAddress("JetFwd_mcMatchId", JetFwd_mcMatchId, &b_JetFwd_mcMatchId);
   fChain->SetBranchAddress("JetFwd_corr_JECUp", JetFwd_corr_JECUp, &b_JetFwd_corr_JECUp);
   fChain->SetBranchAddress("JetFwd_corr_JECDown", JetFwd_corr_JECDown, &b_JetFwd_corr_JECDown);
   fChain->SetBranchAddress("JetFwd_corr", JetFwd_corr, &b_JetFwd_corr);
   fChain->SetBranchAddress("JetFwd_pt", JetFwd_pt, &b_JetFwd_pt);
   fChain->SetBranchAddress("JetFwd_eta", JetFwd_eta, &b_JetFwd_eta);
   fChain->SetBranchAddress("JetFwd_phi", JetFwd_phi, &b_JetFwd_phi);
   fChain->SetBranchAddress("JetFwd_mass", JetFwd_mass, &b_JetFwd_mass);
   fChain->SetBranchAddress("JetFwd_mcMatchFlav", JetFwd_mcMatchFlav, &b_JetFwd_mcMatchFlav);
   fChain->SetBranchAddress("JetFwd_charge", JetFwd_charge, &b_JetFwd_charge);
}

Bool_t ttHSelectorBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef ttHSelectorBase_cxx
