#! /usr/bin/env python

import ROOT
import sys
import os
from optparse import OptionParser

from CMGTools.TTHAnalysis.plotter.cutsFile import CutsFile
from CMGTools.TTHAnalysis.plotter.mcPlots import addPlotMakerOptions
from CMGTools.TTHAnalysis.plotter.mcAnalysis import MCAnalysis

#FIXME
usage = """
usage: %prog [options] mca.txt cuts.txt branches.txt
run with --help to get list of options
"""
parser = OptionParser(usage=usage)
addPlotMakerOptions(parser)
(options, args) = parser.parse_args()

OUTDIR = 'ttHFinalTrees/out/'
os.system('mkdir -p %s' %OUTDIR)


## Load the TSelector
try:
    ROOT.gSystem.Load('ttHFinalTrees/ttHFinalSelector_C.so')
    from ROOT import ttHFinalSelector
except ImportError:
    print "ERROR: failed to load shared object library"
    sys.exit(-1)

## Some default options (too lazy to give them on the command line)
options.tree = 'treeProducerSusyMultilepton'
options.lumi = 0.83231

try:
    print "Processing %s" % args[1]
    mca      = MCAnalysis(args[0], options)
    evcuts   = CutsFile(args[1], options)

    print " applying the following cuts:", evcuts.allCuts()

except IndexError:
    print "Please provide at least two arguments"
    parser.print_help()
    sys.exit(1)


## Collect input files:
trees = {}
for proc in mca.listProcesses():
    trees.setdefault(proc, [])
    for comp in mca._allData[proc]:
        trees[proc].append(comp.getTree())

## Run the selector on the trees
for proc, tree in trees.iteritems():
    print "... processing", proc
    sel = ttHFinalSelector()
    sel.SetCommonSelection(evcuts.allCuts())
    sel.SetOutputFile(os.path.join(OUTDIR, '%s.root'%proc))
    tree[0].Process(sel)
    print '  %s done' % proc

    # break


print 50*'%'
print "ALL DONE"
print 50*'%'
