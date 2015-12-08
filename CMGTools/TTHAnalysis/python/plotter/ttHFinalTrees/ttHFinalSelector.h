#ifndef ttHFinalSelector_h
#define ttHFinalSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TCut.h>
#include <TEventList.h>

#include <string>

#include "ttHSelectorBase.C"


class ttHFinalSelector : public ttHSelectorBase {
public :
   ttHFinalSelector(TTree *tree=0) : ttHSelectorBase() {
      fUseEventlist = kFALSE;
      fApplyFakerate = kFALSE;
   }
   virtual ~ttHFinalSelector() { }

   virtual void    Begin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    Terminate();

   virtual void    ResetTree();
   virtual void    SetOutputFile(TString);
   virtual Bool_t  LoadFakerate(const std::string, TString, TString);
   virtual void    SetCommonSelection(TString sel);

   TCut fCommonSelection;
   Bool_t fUseEventlist, fApplyFakerate;
   TEventList *fEventlist;

	TFile *fOutputFile;
	TTree *fFinalTree;

   // Tree branches
   Int_t fTrun, fTlumi, fTevt, fTisData;
   Float_t fTWeight, fTFRWeight;
   Int_t fTEvCat; // multiplication of pdgIds, 11*11 = ee, 13*11 = emu, etc.

	Int_t fTnJet25;
   Int_t fTnBJetLoose25;
   Int_t fTnBJetMedium25;

   Float_t fThtJet25;
   Float_t fTmet_pt;

   Int_t fTnLepGood;
   Float_t fTLepGood_pt[8], fTLepGood_eta[8];
   Int_t fTLepGood_pdgId[8];
};

#endif
