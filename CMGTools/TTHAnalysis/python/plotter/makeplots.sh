#!/bin/bash

WHAT=$3; if [[ "$3" == "" ]]; then WHAT="PLOTS"; fi
date=$1
chan=$2


outdir="/afs/cern.ch/work/s/stiegerb/TTHFrameWork/plots/${date}/${chan}/"

echo "-------------------------------------------"
echo "Storing output in ${outdir}"

# inputs:
treedir="trees3/"
thqfriend="THqFriends_Nov10"
thqmva="THqMVA_Nov10"
sffriends="THqSFs_Nov10"

common="-j 8 -f -l 19.6 -G -P ${treedir}  --print pdf --poisson"
friends="--FMC sf/t ${sffriends}/sfFriend_{cname}.root -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root"

weight="-W puWeight*Eff_2lep*SF_btag*SF_LepMVATight_2l*SF_LepTightCharge_2l*SF_trig2l"

options="${common} ${friends} ${weight}"

echo "  options are:"
echo ${options}
echo "-------------------------------------------"


case $WHAT in
    PLOTS )
		if [[ "$2" == "mm" ]]; then
			python mcPlots.py ${options} --print-dir ${outdir}/norm/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt -U presel_thq --xp data --xp QF_data,ttG.* --plotmode norm
			python mcPlots.py ${options} --print-dir ${outdir}       mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt -U presel_thq --xp QF_data --showRatio
		else
			python mcPlots.py ${options} --print-dir ${outdir}/norm/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt -U presel_thq --xp data --plotmode norm
			python mcPlots.py ${options} --print-dir ${outdir}       mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt -U presel_thq --showRatio
		fi

		# python mcPlots.py ${options} --print-dir ${outdir}       mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_inputs_plots.txt -U presel_thq --showRatio
		# python mcPlots.py ${options} --print-dir ${outdir}/cr_njge4/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt -U presel_thq --showRatio --add-cut "presel_thq" "nJet>3" "nJet25>3"
		# python mcPlots.py ${options} --print-dir ${outdir}/cr_njge4/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_${chan}.txt bins/THq_LD_inputs_plots.txt -U presel_thq --showRatio --add-cut "presel_thq" "nJet>3" "nJet25>3"
	;;
    CRPLOTS )
		echo " producing control region plots"
		echo " nada"
	;;
esac


echo "-------------------------------------------"

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/norm/ --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_mm.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_mm.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_mm.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/norm/ --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_em.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_em.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_em.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/norm/ --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_ee.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_ee.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/      --print pdf --path trees/ mca-2lss-data_thq_forplotting.txt bins/2lss_thq_ee.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

