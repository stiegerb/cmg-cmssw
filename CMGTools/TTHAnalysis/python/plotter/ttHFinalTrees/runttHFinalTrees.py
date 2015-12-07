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
for proc in mca.listProcesses():
    comps_to_process = {}
    for comp in mca._allData[proc]:
        comps_to_process.setdefault(proc, []).append(comp)
        # comps_to_process[comp].append(comp.getTree())
        bname = os.path.basename(comp.getTree().GetCurrentFile().GetName())
        print "... adding ", bname

    for n,comp in enumerate(comps_to_process[proc]):
        sel = ttHFinalSelector()
        sel.SetCommonSelection(comp.adaptExpr(evcuts.allCuts(),cut=True))
        sel.SetOutputFile(os.path.join(OUTDIR, '%s_%d.root'%(proc,n)))
        comp.getTree().Process(sel)
        print '  %s %d done' % (proc, n)

print 50*'%'
print "ALL DONE"
print 50*'%'
