#include "ttHFinalSelector.h"
#include <iostream>

void ttHFinalSelector::SetCommonSelection(TString sel)
{
   fCommonSelection = TCut(sel);
   fUseEventlist = kTRUE;
}

void ttHFinalSelector::SetOutputFile(TString filename)
{
   fOutputFile = TFile::Open(filename, "recreate");
}

void ttHFinalSelector::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   fOutputFile->cd();

   // Define the final tree
   fFinalTree = new TTree("finalTree", "Tree of final selected events");

   fFinalTree->Branch("run"           , &fTrun           , "run/I");
   fFinalTree->Branch("lumi"          , &fTlumi          , "lumi/I");
   fFinalTree->Branch("evt"           , &fTevt           , "evt/I");
   fFinalTree->Branch("isData"        , &fTisData        , "isData/I");
   fFinalTree->Branch("nJet25"        , &fTnJet25        , "nJet25/I");
   fFinalTree->Branch("nBJetLoose25"  , &fTnBJetLoose25  , "nBJetLoose25/I");
   fFinalTree->Branch("nBJetMedium25" , &fTnBJetMedium25 , "nBJetMedium25/I");
   fFinalTree->Branch("htJet25"       , &fThtJet25       , "htJet25/F");
   fFinalTree->Branch("met_pt"        , &fTmet_pt        , "met_pt/F");
   fFinalTree->Branch("nLepGood"      , &fTnLepGood      , "nLepGood/I");
   fFinalTree->Branch("LepGood_pt"    ,  fTLepGood_pt    , "LepGood_pt[nLepGood]/F");
   fFinalTree->Branch("LepGood_eta"   ,  fTLepGood_eta   , "LepGood_eta[nLepGood]/F");
   fFinalTree->Branch("LepGood_pdgId" ,  fTLepGood_pdgId , "LepGood_pdgId[nLepGood]/I");

   fFinalTree->Branch("Weight"        , &fTWeight        , "Weight/F");
   fFinalTree->Branch("EvCat"         , &fTEvCat         , "EvCat/I");

}

void ttHFinalSelector::ResetTree()
{
   fTrun            = -99;
   fTlumi           = -99;
   fTevt            = -99;
   fTisData         = -99;
   fTWeight         = -99.99;
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
   if (entry%500 == 0) {
      printf("\r [ %6d ]", entry);
      std::cout << std::flush;
   }

   b_run->GetEntry();
   b_lumi->GetEntry();
   b_evt->GetEntry();
   b_isData->GetEntry();
   b_nJet25->GetEntry();
   b_nBJetLoose25->GetEntry();
   b_nBJetMedium25->GetEntry();
   b_htJet25->GetEntry();
   b_met_pt->GetEntry();
   b_nLepGood->GetEntry();
   b_LepGood_pt->GetEntry();
   b_LepGood_eta->GetEntry();
   b_LepGood_pdgId->GetEntry();

   b_puWeight->GetEntry();

   // GetEntry(entry, 1);

   ResetTree();
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
   fTWeight         = puWeight;

   fFinalTree->Fill();

   return kTRUE;
}

void ttHFinalSelector::Terminate()
{
   // Write the output tree
   fOutputFile->cd();
   fFinalTree->Write(fFinalTree->GetName(), TObject::kOverwrite);
   std::cout << "ttHFinalSelector wrote output file "
             << fOutputFile->GetName() << std::endl;
   fOutputFile->Write();
   fOutputFile->Close();
}

void ttHFinalSelector::Init(TTree *tree)
{
   ttHSelectorBase::Init(tree);

   if(fUseEventlist){
      std::cout << "Setting common selection: " << fCommonSelection << std::endl;
      Long64_t nsel = fChain->Draw(">>cutlist", fCommonSelection);
      fEventlist = (TEventList*)gDirectory->Get("cutlist");
      fEventlist->SetDirectory(0);
      fChain->SetEventList(fEventlist); // todo, TEntryList or TEventList?

      std::cout << " Cut reduced number of events from " << fChain->GetEntries()
                << " to " << nsel << std::endl;
   }
}

