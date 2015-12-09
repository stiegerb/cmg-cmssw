#include "ttHFinalSelector.h"
#include <iostream>
#include "../fakeRate.cc"


void ttHFinalSelector::SetCommonSelection(TString sel){
   fCommonSelection = TCut(sel);
   fUseEventlist = kTRUE;
}

void ttHFinalSelector::SetOutputFile(TString filename){
   fOutputFile = TFile::Open(filename, "recreate");
}

Bool_t ttHFinalSelector::LoadFakerate(const std::string htype,
                                      TString filename,
                                      TString hname){
   fApplyFakerate = kTRUE;
   return loadFRHisto(htype, filename, hname);
}

void ttHFinalSelector::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   fOutputFile->cd();

   // Define the final tree
   fFinalTree = new TTree("finalTree", "Tree of final selected events");

   fFinalTree->Branch("run"           ,&fTrun           ,"run/I");
   fFinalTree->Branch("lumi"          ,&fTlumi          ,"lumi/I");
   fFinalTree->Branch("evt"           ,&fTevt           ,"evt/I");
   fFinalTree->Branch("isData"        ,&fTisData        ,"isData/I");
   fFinalTree->Branch("nJet25"        ,&fTnJet25        ,"nJet25/I");
   fFinalTree->Branch("nBJetLoose25"  ,&fTnBJetLoose25  ,"nBJetLoose25/I");
   fFinalTree->Branch("nBJetMedium25" ,&fTnBJetMedium25 ,"nBJetMedium25/I");
   fFinalTree->Branch("htJet25"       ,&fThtJet25       ,"htJet25/F");
   fFinalTree->Branch("met_pt"        ,&fTmet_pt        ,"met_pt/F");
   fFinalTree->Branch("nLepGood"      ,&fTnLepGood      ,"nLepGood/I");
   fFinalTree->Branch("LepGood_pt"    , fTLepGood_pt    ,"LepGood_pt[nLepGood]/F");
   fFinalTree->Branch("LepGood_eta"   , fTLepGood_eta   ,"LepGood_eta[nLepGood]/F");
   fFinalTree->Branch("LepGood_pdgId" , fTLepGood_pdgId ,"LepGood_pdgId[nLepGood]/I");

   fFinalTree->Branch("Weight"        ,&fTWeight        ,"Weight/F");
   fFinalTree->Branch("FRWeight"      ,&fTFRWeight      ,"FRWeight/F");
   fFinalTree->Branch("EvCat"         ,&fTEvCat         ,"EvCat/I");

}

void ttHFinalSelector::ResetTree()
{
   fTrun            = -99;
   fTlumi           = -99;
   fTevt            = -99;
   fTisData         = -99;
   fTWeight         = -99.99;
   fTFRWeight       = -99.99;
   fTEvCat          = -99;

   fTnJet25         = -99;
   fTnBJetLoose25   = -99;
   fTnBJetMedium25  = -99;

   fThtJet25        = -99.99;
   fTmet_pt         = -99.99;

   fTnLepGood       = -99;
   for (int i = 0; i < 8; ++i){
      fTLepGood_pt[i]    = -99.99;
      fTLepGood_eta[i]   = -99.99;
      fTLepGood_pdgId[i] = -99;
   }
}

Bool_t ttHFinalSelector::Process(Long64_t entry)
{
   if (fVerbose > 0 && entry%100 == 0) {
      printf("\r [ %6lld ]", entry);
      std::cout << std::flush;
   }

   // Reset all the tree variables
   ResetTree();

   // Load only selected branches
   b_run           -> GetEntry(entry);
   b_lumi          -> GetEntry(entry);
   b_evt           -> GetEntry(entry);
   b_isData        -> GetEntry(entry);
   b_nJet25        -> GetEntry(entry);
   b_nBJetLoose25  -> GetEntry(entry);
   b_nBJetMedium25 -> GetEntry(entry);
   b_htJet25       -> GetEntry(entry);
   b_met_pt        -> GetEntry(entry);
   b_nLepGood      -> GetEntry(entry);
   b_LepGood_pt    -> GetEntry(entry);
   b_LepGood_eta   -> GetEntry(entry);
   b_LepGood_pdgId -> GetEntry(entry);
   b_LepGood_mvaTTH-> GetEntry(entry);

   if(!isData){
      b_puWeight   -> GetEntry(entry);
   }

   // Load all the branches
   // GetEntry(entry, 1);

   // Copied branches
   fTrun            = run;
   fTlumi           = lumi;
   fTevt            = evt;
   fTisData         = isData;
   fTnJet25         = nJet25;
   fTnBJetLoose25   = nBJetLoose25;
   fTnBJetMedium25  = nBJetMedium25;
   fThtJet25        = htJet25;
   fTmet_pt         = met_pt;

   fTEvCat = 1;
   fTnLepGood = nLepGood;
   for(int ilep = 0; ilep < nLepGood; ++ilep){
      fTLepGood_pt[ilep]     = LepGood_pt[ilep];
      fTLepGood_eta[ilep]    = LepGood_eta[ilep];
      fTLepGood_pdgId[ilep]  = LepGood_pdgId[ilep];
      fTEvCat *= LepGood_pdgId[ilep];
   }

   // Custom branches
   fTWeight = 1.0;
   if(!isData) fTWeight = puWeight; // Note: not filled for data

   fTFRWeight = 1.0;
   if(fApplyFakerate){
      Float_t WP = 0.65;
      if(QF_el){
         fTFRWeight = chargeFlipWeight_2lss(LepGood_pt[0], LepGood_eta[0], LepGood_pdgId[0],
                                            LepGood_pt[1], LepGood_eta[1], LepGood_pdgId[1]);
      }
      else if(FR_el && FR_mu){
         // fTFRWeight = fakeRateWeight_2lss(LepGood_pt[0], LepGood_eta[0], LepGood_pdgId[0], LepGood_mvaTTH[0],
         //                                  LepGood_pt[1], LepGood_eta[1], LepGood_pdgId[1], LepGood_mvaTTH[1], WP);
         fTFRWeight = fakeRateWeight_2lssBCat(LepGood_pt[0], LepGood_eta[0], LepGood_pdgId[0], LepGood_mvaTTH[0],
                                              LepGood_pt[1], LepGood_eta[1], LepGood_pdgId[1], LepGood_mvaTTH[1], WP,
                                              nBJetMedium25, 1.0, 1.0, 1.0, 1.0);
      }
   }

   fFinalTree->Fill();
   return kTRUE;
}

void ttHFinalSelector::Terminate()
{
   // Write the output tree
   fOutputFile->cd();
   fFinalTree->Write(fFinalTree->GetName(), TObject::kOverwrite);
   if(fVerbose > 0){
      std::cout << "ttHFinalSelector wrote output file "
                << fOutputFile->GetName() << std::endl;
   }
   fOutputFile->Write();
   fOutputFile->Close();
}

void ttHFinalSelector::Init(TTree *tree)
{
   ttHSelectorBase::Init(tree);

   if(fUseEventlist){
      if(fVerbose > 1){
         std::cout << "Setting common selection: "
                   << fCommonSelection << std::endl;
      }
      Long64_t nsel = fChain->Draw(">>cutlist", fCommonSelection);
      fEventlist = (TEventList*)gDirectory->Get("cutlist");
      fEventlist->SetDirectory(0);
      fChain->SetEventList(fEventlist); // todo, TEntryList or TEventList?

      if(fVerbose > 0){
         std::cout << " Cut reduced number of events from "
                   << fChain->GetEntries()
                   << " to " << nsel << std::endl;
      }
   }
}

