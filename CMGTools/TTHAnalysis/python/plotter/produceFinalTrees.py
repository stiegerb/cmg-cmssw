#! /usr/bin/env python

########################################
# Slims and skims trees
#
# Original authour: Duc Bao Ta duct@nikhef.nl
########################################

import ROOT
import sys
import re
import time
from optparse import OptionParser

from CMGTools.TTHAnalysis.plotter.cutsFile import CutsFile
from CMGTools.TTHAnalysis.plotter.mcPlots import addPlotMakerOptions
from CMGTools.TTHAnalysis.plotter.mcAnalysis import MCAnalysis
from CMGTools.TTHAnalysis.plotter.tree2yield import PlotSpec

from treeSlimmer import slimAndSkim

usage="usage: %prog [options] mca.txt cuts.txt branches.txt \nrun with --help to get list of options"
parser = OptionParser(usage=usage)
addPlotMakerOptions(parser)
(options, args) = parser.parse_args()

## Some default options (too lazy to give them on the command line)
options.tree = 'treeProducerSusyMultilepton'
options.lumi = 0.83231


try:
    print "Processing %s" % args[1]
    mca    = MCAnalysis(args[0], options)
    evcuts = CutsFile(args[1], options)
    ## FIXME open branches file and extract branch definitions

except IndexError:
    print "Please provide at least three arguments"
    parser.print_help()
    sys.exit(1)


## Loop on relevant input files:
for proc in mca.listProcesses():
	print proc
	for comp in mca._allData[proc]:
		print comp.getTree().GetCurrentFile().GetName()

