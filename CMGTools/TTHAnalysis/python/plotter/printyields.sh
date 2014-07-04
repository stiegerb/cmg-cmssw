#!/bin/bash

chan=$1

echo "-------------------------------------------"
thqfriend="THqFriends_Mar19"
thqmva="THqMVA_Mar20"

options="-j 8 -f -l 19.6 -G -F THq/t ${thqfriend}/THqFriend_{cname}.root -F THqMVA/t ${thqmva}/THqMVA_{cname}.root -P trees/ -W puWeight*Eff_2lep"

echo "  options are:"
echo ${options}
# echo "-------------------------------------------"
# echo " pre-selection"

# python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U presel_thq
python makeTHqCardsCounting.py -c ${options} -U presel_thq mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt systsTHq.txt
echo "-------------------------------------------"
# echo " with likelihood > 0.8"
# python mcAnalysis.py ${options} mca-2lss-data_thq.txt bins/2lss_thq_${chan}.txt -U likelihood --xp data
# echo "-------------------------------------------"
