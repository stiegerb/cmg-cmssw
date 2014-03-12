#!/usr/bin/env python
# @(#)root/tmva $Id$

import sys, os
import optparse
import ROOT
from ROOT import TMVA

# VARLIST = ['charge', 'deltaPhill', 'fwdJetEtaGap', 'maxEtaJet25','nBJetMedium25', 'htJet25']
FRIENDDIR = "/data/stiegerb/TTHTrees/Friends/THqFriends_Mar10/"
TREENAME = 'ttHLepTreeProducerBase'

def eventSelectionString():
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
    selection += "&& (LepGood1_charge*LepGood2_charge > 0)"
    ## low mass veto
    selection += "&& (minMllAFAS > 12)"
    ## lepton mva cut: ## need to remove this cut to have fake rate estimates for LD
    selection += "&& (min(LepGood1_mva,LepGood2_mva) > 0.7)"
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
    return selection

def pathToTag(path, default):
	return (path.split(os.sep))[-3] if (path.split(os.sep))[-2] == 'ttHLepTreeProducerBase' else default

def getTreeFromFile(treename, filename):
	file = ROOT.TFile.Open(filename, 'READ')
	try:
		tree = file.Get(treename)
	except ReferenceError:
		print "File", filename, "not found!"
		exit(-1)
	try:
		name = tree.GetName()
	except ReferenceError:
		print "Failed to find tree", treename, "in file", filename
		exit(-1)
	return tree


def main():
    usage = "%prog [options] file_with_sig_tree file_with_bg_tree"
    parser = optparse.OptionParser(usage)
    parser.add_option('-o', '--outputFile', dest='outputFile',
    	               default='THq_MVA.root', type='string',
    	               help='Outputfile')
    parser.add_option('-v', '--verbose', dest='verbose',
    	               default=1, type='int',
    	               help='Verbose level [default %default]')
    parser.add_option('-t', '--treeDir', dest='treeDir',
    	               default='trees/', type='string',
    	               help='Input directory for ttH trees [default %default]')
    (opt, args) = parser.parse_args()

    if len(args) < 2:
        parser.print_help()

    treeloc = os.path.join(opt.treeDir, r'%s', TREENAME, TREENAME+'_tree.root')

    # --- Extract trees
    sgtree = getTreeFromFile(TREENAME, treeloc % args[0])
    bgtrees = []
    for tag in args[1:]:
    	bgtrees.append(getTreeFromFile(TREENAME, treeloc%tag))

    outputFile = ROOT.TFile( opt.outputFile, 'RECREATE' )

    factory_options = "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification"
    factory = TMVA.Factory( "TMVAClassification", outputFile,
                            factory_options )
    factory.SetVerbose( opt.verbose )

    # --- Define input variables
    factory.AddVariable( "charge := LepGood1_charge", 'F')
    factory.AddVariable( "deltaPhill := abs(deltaPhill)", 'F')
    factory.AddVariable( "fwdJetEtaGap := fwdJetEtaGap", 'F')
    factory.AddVariable( "dEtaFwdJetb", 'F')
    factory.AddVariable( "maxEtaJet25", 'F')
    factory.AddVariable( "nJet25Eta2", 'F')
    factory.AddVariable( "nBJetMedium25", 'F')
    factory.AddVariable( "htJet25", 'F')
    factory.AddVariable( "nJet25", 'F')

    # factory.AddSpectator( "", 'F')

    # --- Add friends
    for tree, tag in zip([sgtree]+bgtrees, args):
    	tree.AddFriend('THq/t', "%sTHqFriend_%s.root" % (FRIENDDIR,tag) )

    # --- Add trees to factory
    sgweight, bgweight = 1.0, 1.0
    factory.AddSignalTree(    sgtree, sgweight)
    for bgtree in bgtrees:
	    factory.AddBackgroundTree(bgtree, bgweight)
    factory.SetWeightExpression("puWeight")

    # --- Event selection
    print 40*'#'
    print "Selecting events with:\n %s" % eventSelectionString()
    print 40*'#'
    cutSg = ROOT.TCut(eventSelectionString())
    cutBg = ROOT.TCut(eventSelectionString())
    factory.PrepareTrainingAndTestTree(cutSg, cutBg, "")

    factory.BookMethod(TMVA.Types.kLD, "LD", "!H:!V:VarTransform=None")

    # Boosted Decision Trees with gradient boosting?
    BDTGopt = "!H:!V:NTrees=200:BoostType=Grad:Shrinkage=0.10:!UseBaggedGrad:nCuts=2000:nEventsMin=100:NNodesMax=9:UseNvars=9:PruneStrength=5:PruneMethod=CostComplexity:MaxDepth=8"
    BDTGopt += ":CreateMVAPdfs" # Create Rarity distribution
    factory.BookMethod(TMVA.Types.kBDT, "BDTG", BDTGopt);

    # Train MVAs
    factory.TrainAllMethods()

    # Test MVAs
    factory.TestAllMethods()

    # Evaluate MVAs
    factory.EvaluateAllMethods()

    # Save the output.
    outputFile.Close()

    print "=== wrote root file %s" % opt.outputFile
    print "=== TMVAClassification is done!"

    # ROOT.gROOT.SetMacroPath( "./" )
    # ROOT.gROOT.Macro       ( "./TMVAlogon.C" )
    # ROOT.gROOT.LoadMacro   ( "./TMVAGui.C" )

    # # open the GUI for the result macros
    # ROOT.gROOT.ProcessLine( "TMVAGui(\"%s\")" % opt.outputFile )
    exit(0)


if __name__ == '__main__':
	main()