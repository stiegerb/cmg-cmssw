#!/bin/bash

chan=$1
cache=$2

thqfriend="THqFriends_Mar19"
thqmva="THqMVA_Mar20"
sffriends="trees/0_SFs_v2"

# options="-j 8 -f -l 19.6 -G -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root -P trees/ -W puWeight*Eff_2lep"
common="-U presel_thq -j 8 -f -l 19.6 -G -P trees/"
friends="--FMC sf/t ${sffriends}/sfFriend_{cname}.root -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root"

weight="-W puWeight*Eff_2lep*SF_btag*SF_LepMVATight_2l*SF_LepTightCharge_2l*SF_trig2l"

# weight="-W puWeight*Eff_2lep*SF_LepMVATight_2l*SF_trig2l*SF_btag"
options="${common} ${friends} ${weight}"

echo " options string:"
echo " ${options}"

# python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U presel_thq
# python makeTHqCardsCounting.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt systsTHqCounting.txt
# python makeTHqCardsCounting.py -c ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt systsTHqCounting.txt
# python makeTHqCardsCounting.py -c --xp data ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt systsTHqCounting.txt

# python makeTHqCardsShape.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
if [[ "$2" == "" ]]; then
	python makeTHqCardsShape.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
elif [[ "$2" == "-c" ]]; then
	python makeTHqCardsShape.py -c --asimov ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
fi

# python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U presel_thq

# python makeTHqCardsShape.py -c --asimov ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
