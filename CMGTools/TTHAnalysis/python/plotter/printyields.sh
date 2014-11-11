#!/bin/bash

WHAT=$1; if [[ "$1" == "" ]]; then WHAT="YIELDS"; fi
chan=$2
cache=$3

treedir="trees3"
thqfriend="THqFriends_Nov10"
thqmva="THqMVA_Nov10"
sffriends="THqSFs_Nov10"

# treedir="trees"
# thqfriend="THqFriends_Mar19"
# thqmva="THqMVA_Mar20"
# sffriends="trees/0_SFs_v2"

# options="-j 8 -f -l 19.6 -G -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root -P trees/ -W puWeight*Eff_2lep"
common="-U presel_thq -j 8 -f -l 19.6 -G -P ${treedir}/"
friends="--FMC sf/t ${sffriends}/sfFriend_{cname}.root -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root"

weight="-W puWeight*Eff_2lep*SF_btag*SF_LepMVATight_2l*SF_LepTightCharge_2l*SF_trig2l"

# weight="-W puWeight*Eff_2lep*SF_LepMVATight_2l*SF_trig2l*SF_btag"
options="${common} ${friends} ${weight}"

echo " options string:"
echo " ${options}"

case $WHAT in
    CARDS )
    ## Make cards:
	if [[ "$cache" == "" ]]; then
	    python makeTHqCardsShape.py --binbybin ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
	elif [[ "$cache" == "-c" ]]; then
		python makeTHqCardsShape.py --binbybin -c ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
	fi
	;;
    YIELDS )
	## Print yields:
		python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U presel_thq
	;;
esac



# python makeTHqCardsShape.py -c --asimov ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt

