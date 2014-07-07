#!/bin/bash

chan=$1

thqfriend="THqFriends_Mar19"
thqmva="THqMVA_Mar20"

options="-U presel_thq -j 8 -f -l 19.6 -G -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root -P trees/ -W puWeight*Eff_2lep"

echo " options string:"
echo " ${options}"
# python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U presel_thq
# python makeTHqCardsCounting.py -c ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt systsTHqCounting.txt
python makeTHqCardsShape.py -c ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt THq_SimpleLH 10,0,1 systsTHq.txt
