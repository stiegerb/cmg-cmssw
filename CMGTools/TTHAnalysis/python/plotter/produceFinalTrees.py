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

from treeSlimmer import slimAndSkim

usage="usage: %prog [options] mca.txt cuts.txt branches.txt \nrun with --help to get list of options"
parser = OptionParser(usage=usage)
addPlotMakerOptions(parser)
(options, args) = parser.parse_args()

## Some default options (too lazy to give them on the command line)
options.tree = 'treeProducerSusyMultilepton'
options.lumi = 0.83231

def getBranches(fname):
	branchdefs = []
	with open(fname, 'r') as branchfile:
		for line in branchfile:
			line = line.strip()
			if not len(line) or line.startswith('#'): continue
			br, form = line.split(':',1)
			br, form = br.strip(), form.strip()
			branchdefs.append((br,form))

	return branchdefs

try:
    print "Processing %s" % args[1]
    mca      = MCAnalysis(args[0], options)
    evcuts   = CutsFile(args[1], options)
    branches = [f for b,f in getBranches(args[2])]

    print " applying the following cuts:", evcuts.allCuts()

    print " "
    print " will keep the following branches:", branches

except IndexError:
    print "Please provide at least three arguments"
    parser.print_help()
    sys.exit(1)


## Collect input files:
filestoprocess = {}
for proc in mca.listProcesses():
	filestoprocess.setdefault(proc, [])
	for comp in mca._allData[proc]:
		filestoprocess[proc].append(comp.getTree().GetCurrentFile().GetName())

## Skim and slim the trees
for proc, files in filestoprocess.iteritems():
	print "... processing", proc
	slimAndSkim(files, evcuts.allCuts(), branches, 'finalTrees/%s_final.root'%proc, treeloc='tree')

print 50*'%'
print "ALL DONE"
print 50*'%'
