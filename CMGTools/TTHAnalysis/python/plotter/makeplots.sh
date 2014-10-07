#!/bin/bash

date=$1
chan=$2

outdir="/afs/cern.ch/work/s/stiegerb/TTHFrameWork/plots/${date}/${chan}/"

echo "-------------------------------------------"
echo "Storing output in ${outdir}"

thqfriend="THqFriends_Mar19"
thqmva="THqMVA_Mar20"
sffriends="trees/0_SFs_v2"

common="-j 8 -f -l 19.6 -G -P trees/  --print pdf "
friends="--FMC sf/t ${sffriends}/sfFriend_{cname}.root -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root"

weight="-W puWeight*Eff_2lep*SF_btag*SF_LepMVATight_2l*SF_LepTightCharge_2l*SF_trig2l"

options="${common} ${friends} ${weight}"

echo "  options are:"
echo ${options}
echo "-------------------------------------------"

python mcPlots.py ${options} --print-dir ${outdir}/norm/ mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt        -U presel_thq --xp data --plotmode norm
python mcPlots.py ${options} --print-dir ${outdir}       mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt bins/THq_LD_plots.txt        -U presel_thq --xp data
python mcPlots.py ${options} --print-dir ${outdir}       mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt bins/THq_LD_inputs_plots.txt -U presel_thq --showRatio --fitRatio 1

echo "-------------------------------------------"

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/norm/ --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_mm.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_mm.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/mm/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_mm.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/norm/ --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_em.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_em.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/em/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_em.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/norm/ --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_ee.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data --plotmode norm
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_ee.txt bins/THq_LD_plots.txt        -W 'puWeight*Eff_2lep' -U presel_thq --xp data
# python mcPlots.py -j 8 -f -l 19.6 -F THq/t THqFriends_Mar19/THqFriend_{cname}.root -F THqMVA/t THqMVA_Mar20/THqMVA_{cname}.root --print-dir ~/work/TTHFrameWork/plots/Jul3/ee/      --print pdf --path trees/ mca-2lss-data_thq.txt bins/2lss_thq_ee.txt bins/THq_LD_inputs_plots.txt -W 'puWeight*Eff_2lep' -U presel_thq --showRatio --fitRatio 1

