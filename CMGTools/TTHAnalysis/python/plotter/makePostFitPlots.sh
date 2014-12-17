#!/bin/bash
dir="postFitPlots"
python postFitPlotsTHq.py mca-2lss-data_thq_forplotting.txt mca-2lss-data_thq.txt ${dir}/mm.input.root ${dir}/mlfit.root mm
python postFitPlotsTHq.py mca-2lss-data_thq_forplotting.txt mca-2lss-data_thq.txt ${dir}/em.input.root ${dir}/mlfit.root em
python postFitPlotsTHq.py mca-3l-data_thq_forplotting.txt mca-3l-data_thq.txt ${dir}/Likelihood_histos_withFakes_PreviousHistograms_8September.root ${dir}/mlfit.root l3

