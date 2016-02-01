#!/bin/bash

if [[ "$HOSTNAME" == "cmsphys10" ]]; then
#    T="/data1/p/peruzzi/TREES_74X_140116_MiniIso_tauClean_Mor16lepMVA";
    T="/data/p/peruzzi/skim_2lss_3l_TREES_74X_140116_MiniIso_tauClean_Mor16lepMVA";
    J=8;
else
    T="/afs/cern.ch/work/p/peruzzi/tthtrees/TREES_74X_140116_MiniIso_tauClean_Mor16lepMVA";
    J=4;
fi

SCENARIO=""
if echo "X$1" | grep -q "scenario"; then SCENARIO="$1"; shift; fi
if [[ "X$1" == "X" ]]; then echo "Provide luminosity!"; exit; fi
LUMI="$1"; shift
echo "Normalizing to ${LUMI}/fb";
OPTIONS=" -P $T --tree treeProducerSusyMultilepton --neg --s2v -j $J -l ${LUMI} -f --asimov "
if [[ "$SCENARIO" != "" ]]; then
    test -d cards/$SCENARIO || mkdir -p cards/$SCENARIO
    OPTIONS="${OPTIONS} --od cards/$SCENARIO --project $SCENARIO ";
else
    OPTIONS="${OPTIONS} --od cards/new ";
fi
SYSTS="ttH-multilepton/systsEnv.txt"
BLoose=" -E BLoose "
BTight=" -E BTight "
ZeroTau=" -E 0tau "
OneTau=" -E 1tau "

OPTIONS="${OPTIONS} --Fs {P}/2_recleaner_v4_vetoCSVM --Fs {P}/4_kinMVA_trainMarcoJan27_v1_fix_reliso_conept"
OPTIONS="${OPTIONS} --mcc ttH-multilepton/lepchoice-ttH-FO.txt --mcc ttH-multilepton/ttH_2lss3l_triggerdefs.txt -W puw(nTrueInt)"
OPTIONS="${OPTIONS} --asimov --xp data --xp '.*data.*'" # safety!

if [[ "$1" == "" || "$1" == "2lss" ]]; then
    OPT_2L="${OPTIONS} "

    POS=" -A alwaystrue positive LepGood1_charge>0 "
    NEG=" -A alwaystrue negative LepGood1_charge<0 "
    for X in 2lss_{mm,ee,em}; do 
        echo $X;
	FLAV=" -E ${X} "
	python makeShapeCards.py ttH-multilepton/mca-2lss-mc.txt ttH-multilepton/2lss_tight.txt 'ttH_MVAto1D_6_2lss(kinMVA_2lss_ttbar,kinMVA_2lss_ttV,LepGood1_pdgId,LepGood2_pdgId)' '6,0.5,6.5' $SYSTS $OPT_2L -o ${X}_BLoose_0Tau_pos $POS $BLoose $FLAV $ZeroTau;
        python makeShapeCards.py ttH-multilepton/mca-2lss-mc.txt ttH-multilepton/2lss_tight.txt 'ttH_MVAto1D_6_2lss(kinMVA_2lss_ttbar,kinMVA_2lss_ttV,LepGood1_pdgId,LepGood2_pdgId)' '6,0.5,6.5' $SYSTS $OPT_2L -o ${X}_BLoose_0Tau_neg $NEG $BLoose $FLAV $ZeroTau;
        python makeShapeCards.py ttH-multilepton/mca-2lss-mc.txt ttH-multilepton/2lss_tight.txt 'ttH_MVAto1D_6_2lss(kinMVA_2lss_ttbar,kinMVA_2lss_ttV,LepGood1_pdgId,LepGood2_pdgId)' '6,0.5,6.5' $SYSTS $OPT_2L -o ${X}_BTight_0Tau_pos $POS $BTight $FLAV $ZeroTau;
        python makeShapeCards.py ttH-multilepton/mca-2lss-mc.txt ttH-multilepton/2lss_tight.txt 'ttH_MVAto1D_6_2lss(kinMVA_2lss_ttbar,kinMVA_2lss_ttV,LepGood1_pdgId,LepGood2_pdgId)' '6,0.5,6.5' $SYSTS $OPT_2L -o ${X}_BTight_0Tau_neg $NEG $BTight $FLAV $ZeroTau;
    done

    python makeShapeCards.py ttH-multilepton/mca-2lss-mc.txt ttH-multilepton/2lss_tight.txt 'ttH_MVAto1D_6_2lss(kinMVA_2lss_ttbar,kinMVA_2lss_ttV,LepGood1_pdgId,LepGood2_pdgId)' '6,0.5,6.5' $SYSTS $OPT_2L -o ${X}_Tau $OneTau;

    echo "Done at $(date)"

fi

if [[ "$1" == "" || "$1" == "3l" ]]; then
    OPT_3L="${OPTIONS} "
    POS=" -A alwaystrue positive (LepGood1_charge+LepGood2_charge+LepGood3_charge)>0 "
    NEG=" -A alwaystrue negative (LepGood1_charge+LepGood2_charge+LepGood3_charge)<0 "

    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BLoose_pos $POS $BLoose;
    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BLoose_neg $NEG $BLoose;
    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BTight_pos $POS $BTight;
    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BTight_neg $NEG $BTight;

# with 3l+1tau
#    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BLoose_0Tau_pos $POS $BLoose $ZeroTau;
#    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BLoose_0Tau_neg $NEG $BLoose $ZeroTau;
#    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BTight_0Tau_pos $POS $BTight $ZeroTau;
#    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_BTight_0Tau_neg $NEG $BTight $ZeroTau;
#    python makeShapeCards.py ttH-multilepton/mca-3l-mc.txt ttH-multilepton/3l_tight.txt 'ttH_MVAto1D_6_3l(kinMVA_3l_ttbar,kinMVA_3l_ttV)' '6,0.5,6.5' $SYSTS $OPT_3L -o 3l_Tau $OneTau;

   echo "Done at $(date)"
fi

