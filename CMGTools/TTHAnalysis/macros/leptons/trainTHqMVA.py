#!/usr/bin/env python
# @(#)root/tmva $Id$
import sys, os
import optparse
import ROOT
from ROOT import TMVA

TREENAME = 'ttHLepTreeProducerBase'

VARIABLES = [ ## Mar 20 presentation
  ("nJet25"       ,('nJet25',          lambda ev: ev.nJet25, 'I')),
  ("etaFwdJet25"  ,('etaFwdJet25',     lambda ev: ev.etaFwdJet25, 'F')),
  ("fwdJetEtaGap" ,('fwdJetEtaGap',    lambda ev: ev.fwdJetEtaGap, 'F')),
  ("htJet25"      ,('htJet25',         lambda ev: ev.htJet25, 'F')),
  ("nBJetMedium25",('nBJetMedium25',   lambda ev: ev.nBJetMedium25, 'I')),
  ("deltaPhill"   ,('abs(deltaPhill)', lambda ev: abs(ev.deltaPhill), 'F')),
  ("LepGood2_pt"  ,('LepGood2_pt',     lambda ev: ev.LepGood2_pt, 'F')),
  ("charge"       ,('LepGood1_charge', lambda ev: ev.LepGood1_charge, 'I'))
]

# VARIABLES = [ ## All, by ranking
#   ("nJet25"       ,('nJet25',          lambda ev: ev.nJet25, 'I')),
#   ("etaFwdJet25"  ,('etaFwdJet25',     lambda ev: ev.etaFwdJet25, 'F')),
#   ("fwdJetEtaGap" ,('fwdJetEtaGap',    lambda ev: ev.fwdJetEtaGap, 'F')),
#   ("htJet25"      ,('htJet25',         lambda ev: ev.htJet25, 'F')),
#   # ("maxEtaJet25"  ,('maxEtaJet25',     lambda ev: ev.maxEtaJet25, 'F')),
#   # ("dEtaFwdJetb"  ,('dEtaFwdJetb',     lambda ev: ev.dEtaFwdJetb, 'F')),
#   # ("nJet25Eta2"   ,('nJet25Eta2',      lambda ev: ev.nJet25Eta2, 'I')),
#   ("nBJetMedium25",('nBJetMedium25',   lambda ev: ev.nBJetMedium25, 'I')),
#   # ("nJet25Ctrl"   ,('nJet25Ctrl',      lambda ev: ev.nJet25Ctrl, 'I')),
#   ("deltaPhill"   ,('abs(deltaPhill)', lambda ev: abs(ev.deltaPhill), 'F')),
#   ("LepGood2_pt"  ,('LepGood2_pt',     lambda ev: ev.LepGood2_pt, 'F')),
#   ("charge"       ,('LepGood1_charge', lambda ev: ev.LepGood1_charge, 'I'))
# ]

# VARIABLES = [
#   ("charge"       ,('LepGood1_charge', lambda ev: ev.LepGood1_charge, 'I')),
#   ("deltaPhill"   ,('abs(deltaPhill)', lambda ev: abs(ev.deltaPhill), 'F')),
#   ("fwdJetEtaGap" ,('fwdJetEtaGap',    lambda ev: ev.fwdJetEtaGap, 'F')),
#   ("maxEtaJet25"  ,('maxEtaJet25',     lambda ev: ev.maxEtaJet25, 'F')),
#   ("nBJetMedium25",('nBJetMedium25',   lambda ev: ev.nBJetMedium25, 'I')),
#   ("htJet25"      ,('htJet25',         lambda ev: ev.htJet25, 'F')),
#   ("nJet25Ctrl"  ,('nJet25Ctrl',     lambda ev: ev.nJet25Ctrl, 'I')),
#   ("LepGood2_pt"  ,('LepGood2_pt',     lambda ev: ev.LepGood2_pt, 'F')),
#   ("dEtaFwdJetb"  ,('dEtaFwdJetb',     lambda ev: ev.dEtaFwdJetb, 'F')),
#   ("nJet25Eta2"   ,('nJet25Eta2',      lambda ev: ev.nJet25Eta2, 'I')),
#   ("nJet25"       ,('nJet25',          lambda ev: ev.nJet25, 'I')),
#   # ("deltaPhiTopH"  ,('deltaPhiTopH',   lambda ev: ev.deltaPhiTopH, 'F')),
#   ("nJet25NonB"  ,('nJet25NonB',   lambda ev: ev.nJet25NonB, 'I')),
#   ("etaFwdJet25"  ,('etaFwdJet25',     lambda ev: ev.etaFwdJet25, 'F'))
# ]

XSECS = {'TTJetsLep' :  23.64,
         'TTJetsSem' :  98.65,
         'TTJetsHad' : 102.9,
         'TTJets'    : 225.2}

def eventSelectionString(includeSidebands=False, looseSecondLepton=False):
    selection = ""

    ## mumu, emu, ee channels:
    selection += "("
    selection += "   (abs(LepGood1_pdgId) == 13"
    selection +=      "&& abs(LepGood2_pdgId) == 13)"
    selection += "||"
    selection +=   "(  ( abs(LepGood1_pdgId) != abs(LepGood2_pdgId) )"
    selection +=   "&& ( abs(LepGood1_pdgId) == 13 ||"
    selection +=    "(LepGood1_convVeto > 0 && LepGood1_innerHits == 0) )"
    selection +=   "&& ( abs(LepGood2_pdgId) == 13 ||"
    selection +=    "(LepGood2_convVeto > 0 && LepGood2_innerHits == 0) )  )"
    selection += "||"
    selection += "   (abs(LepGood1_pdgId) == 11 && abs(LepGood2_pdgId) == 11"
    selection +=   "&& LepGood1_innerHits == 0 && LepGood2_innerHits == 0"
    selection +=   "&& LepGood1_convVeto>0 && LepGood2_convVeto>0  )"
    selection += "   )   "

    ## Veto third lepton
    selection += "&& (nLepGood == 2 || LepGood3_mva < 0.35)"

    ## 20/20 selection
    selection += "&& (LepGood1_pt>20 && LepGood2_pt>20)"

    ## 20/10 selection
    # selection += "&& (LepGood1_pt>20 && LepGood2_pt>10)"

    ## same-sign charge
    ## need to remove this (at least for E/E, E/Mu data samples)
    ## to have charge misid estimates
    if not includeSidebands:
        selection += "&& (LepGood1_charge*LepGood2_charge > 0)"
    ## low mass veto
    selection += "&& (minMllAFAS > 12)"
    ## lepton mva cut:
    ## need to remove this cut to have fake rate estimates for LD
    if not includeSidebands:
        if looseSecondLepton: ## Include one non-isolated lepton:
            selection += "&& (max(LepGood1_mva,LepGood2_mva) > 0.7)"
        else: ## Both leptons isolated:
            # selection += "&& (min(LepGood1_mva,LepGood2_mva) > 0.9)"
            selection += "&& (min(LepGood1_mva,LepGood2_mva) > 0.7)"
    ## tight-charge:
    selection += "&& (LepGood1_tightCharge && LepGood2_tightCharge)"

    #### Dec 2 selection (2 j, 1 fwd j):
    ## 2 jets:
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
    # > 1 non btagged jet :
    # selection += "&&(nJet25NonB>1)"

    return selection

def getNGeneratedEvents(treedir, tag):
    skimReportLoc = os.path.join(treedir, tag,
                   'skimAnalyzerCount','SkimReport.txt')
    nevents = -1
    try:
        with open(skimReportLoc, 'r') as f:
            for line in f:
                try:
                    if ( line.split()[0] == 'All' and
                         line.split()[1] == 'Events' ):
                        nevents = int(line.split()[2])
                except IndexError:
                    continue
            return nevents
    except IOError:
        print "File not found:", skimReportLoc
        return -1

def getCrossSection(tag):
    basedir = '/afs/cern.ch/user/s/stiegerb/work/TTHFrameWork/TTHAnalysis/'
    mcafile = os.path.join(basedir,'python/plotter/mca-2lss-data_thq.txt')
    xsection = 0.0
    try:
        with open(mcafile, 'r') as f:
            for line in f:
                if line.strip() == '' or line.strip()[0] == '#': continue
                line = line.split(';')[0]
                if line.split(':')[1].strip() == tag:
                    tempxs = line.split(':')[2].strip()
                    xsection += float(eval(tempxs))
    except IOError:
        print "File not found:", mcafile
        return -1.

    if xsection == 0.0: ## didn't find it in mca file
        try:
            xsection += XSECS[tag]
        except KeyError:
            print ("Could not determine xsec for %s, aborting. Check "
                   "if it is listed in mca file: %s" % (tag,mcafile))
            exit(-1)
    return xsection

def getXsecWeight(treedir, tag):
    xsection = getCrossSection(tag)
    ngen     = getNGeneratedEvents(treedir, tag)
    print tag, xsection, ngen
    intLgen = ngen/xsection ## in /pb
    return 1000./intLgen ## scale to 1 /fb

def getTreeFromFile(treename, filename):
    file = ROOT.TFile.Open(filename, 'READ')
    try:
        tree = file.Get(treename)
    except ReferenceError:
        print "File", filename, "not found!"
        file.Close()
        exit(-1)
    try:
        name = tree.GetName()
    except ReferenceError:
        print "Failed to find tree", treename, "in file", filename
        file.Close()
        exit(-1)
    return tree

def addTHqVariables(factory):
    for name, (formula, _, vartype) in VARIABLES:
        if formula != name:
            factory.AddVariable("%s := %s" % (name, formula), vartype)
        else:
            factory.AddVariable(name, vartype)

def main():
    usage = "%prog [options] file_with_sig_tree file_with_bg_tree"
    parser = optparse.OptionParser(usage)
    parser.add_option('-o', '--outputFile', dest='outputFile',
                       default='THq_MVA.root', type='string',
                       help='Outputfile')
    parser.add_option('-v', '--verbose', dest='verbose',
                       default=1, type='int',
                       help='Verbose level [default %default]')
    parser.add_option('-w', '--weightBGs', dest='weightBGs',
                       action='store_true',
                       help='Reweight backgrounds according to \
                             their xsection? [default %default]')
    parser.add_option('-t', '--treeDir', dest='treeDir',
                       default='trees/', type='string',
                       help='Input directory for ttH trees\
                             [default %default]')
    parser.add_option('-f', '--friendDir', dest='friendDir',
                       default='THqFriends_Mar10/', type='string',
                       help='Input directory for THqFriends trees\
                             [default %default]')
    (opt, args) = parser.parse_args()

    if len(args) < 2:
        parser.print_help()

    treeloc = os.path.join(opt.treeDir, r'%s',
                           TREENAME, TREENAME+'_tree.root')

    # --- Extract trees
    sgtree = getTreeFromFile(TREENAME, treeloc % args[0])
    sigLintGen = 1./getXsecWeight(opt.treeDir, args[0])
    print '--- Integrated Luminosity of signal sample:', sigLintGen, '(/fb)'
    bgtrees = {}
    for tag in args[1:]:
        bgtrees[tag] = getTreeFromFile(TREENAME, treeloc%tag)

    outputFile = ROOT.TFile( opt.outputFile, 'RECREATE' )

    factory_options = ['!V', '!Color', 'DrawProgressBar']
    factory_options.append('Transformations=I;D;P;G,D')
    factory_options.append('!Silent')
    factory_options.append('AnalysisType=Classification')
    factory = TMVA.Factory( "TMVAClassification", outputFile,
                            ":".join(factory_options) )
    factory.SetVerbose( opt.verbose )

    # --- Define input variables
    addTHqVariables(factory)

    # --- Add friends
    sgtree.AddFriend('THq/t', os.path.join(opt.friendDir,
                                  "THqFriend_%s.root" % args[0])  )
    for tag in args[1:]:
        bgtrees[tag].AddFriend('THq/t', os.path.join(opt.friendDir,
                                  "THqFriend_%s.root" % tag)  )

    bgweights = {}
    for tag in args[1:]:
        if opt.weightBGs:
            if not tag == "TTJets":
                bgweights[tag] = sigLintGen*getXsecWeight(opt.treeDir, tag)
            else:
                ## Get the weight for TTJets from the full selection,
                ## but actually apply the loose selection to gain statistics
                ## I.e. need to multiply weight by N_tight/N_loose
                rawweight = sigLintGen*getXsecWeight(opt.treeDir, tag)
                nev_loose = float(bgtrees[tag].GetEntries(
                            eventSelectionString(looseSecondLepton=True)))
                nev_tight = float(bgtrees[tag].GetEntries(
                            eventSelectionString(looseSecondLepton=False)))
                bgweights[tag] = rawweight * nev_tight/nev_loose
        else:
            bgweights[tag] = 1.0

    print '--- Weights for background samples:'
    for tag in args[1:]:
        print tag, bgweights[tag]

    # --- Add trees to factory
    factory.AddSignalTree(sgtree, 1.0)
    for tag in args[1:]:
        factory.AddBackgroundTree(bgtrees[tag], bgweights[tag])
    factory.SetWeightExpression("puWeight")

    # --- Event selection
    cutSg = ROOT.TCut(eventSelectionString(looseSecondLepton=True))
    cutBg = ROOT.TCut(eventSelectionString(looseSecondLepton=True))
    factory.PrepareTrainingAndTestTree(cutSg, cutBg, "")

    # --- TMVA Methods
    # # Likelihood (with de-correlated variables)
    # Likelihood_options = ['H', '!V', 'TransformOutput']
    # Likelihood_options.append('VarTransform=Decorrelate')
    # Likelihood_options.append('PDFInterpol=Spline2')
    # Likelihood_options.append('NSmoothSig[0]=20')
    # Likelihood_options.append('NSmoothBkg[0]=20')
    # Likelihood_options.append('NSmoothBkg[1]=10')
    # Likelihood_options.append('NSmooth=1')
    # Likelihood_options.append('NAvEvtPerBin=1000')
    # factory.BookMethod(TMVA.Types.kLikelihood,
    #                 "LH", ':'.join(Likelihood_options))

    # Linear discriminant (same as Fisher)
    LD_options = ['!H','!V','VarTransform=None']
    factory.BookMethod(TMVA.Types.kLD, "LD", ':'.join(LD_options))

    # Boosted Decision Trees with gradient boost
    BDT_options = ['!H', '!V', 'CreateMVAPdfs']
    BDT_options.append('BoostType=Grad')
    BDT_options.append('Shrinkage=0.1')
    BDT_options.append('PruneMethod=NoPruning')
    BDT_options.append('PruneStrength=0')
    BDT_options.append('NTrees=800')
    BDT_options.append('MaxDepth=3')
    BDT_options.append('UseNvars=2')
    BDT_options.append('nCuts=100')
    BDT_options.append('NNodesMax=9') ## ?

    ## LeptonMVA configuration (Giovanni/Cristina)
    # BDT_options.append('Shrinkage=0.10')
    # BDT_options.append('!UseBaggedGrad')
    # BDT_options.append('BoostType=Grad')
    # BDT_options.append('PruneMethod=CostComplexity')
    # BDT_options.append('PruneStrength=5')
    # BDT_options.append('NTrees=200')
    # BDT_options.append('MaxDepth=8')
    # BDT_options.append('UseNvars=9')
    # BDT_options.append('nCuts=2000')
    # BDT_options.append('nEventsMin=100') ## ?
    # BDT_options.append('NNodesMax=9') ## ?
    factory.BookMethod(TMVA.Types.kBDT, "BDTG", ':'.join(BDT_options));

    # --- Train, test, evaluate
    factory.TrainAllMethods()
    factory.TestAllMethods()
    factory.EvaluateAllMethods()

    # Save the output.
    outputFile.Close()

    print "=== wrote root file %s" % opt.outputFile
    print "=== TMVAClassification is done!"

    exit(0)


if __name__ == '__main__':
    main()