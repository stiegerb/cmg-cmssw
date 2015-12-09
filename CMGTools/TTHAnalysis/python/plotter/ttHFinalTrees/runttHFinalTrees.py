#! /usr/bin/env python
import sys
import os
import re

from CMGTools.TTHAnalysis.plotter.cutsFile import CutsFile
from CMGTools.TTHAnalysis.plotter.mcAnalysis import MCAnalysis

from ROOT import gROOT
gROOT.ProcessLine("gErrorIgnoreLevel = 4000;")

OUTDIR = 'ttHFinalTrees/out/'

def runFinalTrees((treefile, cuts, outname,
                   frhtype, frfileloc, frhname)):
    import ROOT
    try: ## Load the TSelector
        ROOT.gSystem.Load('ttHFinalTrees/ttHFinalSelector_C.so')
        from ROOT import ttHFinalSelector
    except ImportError:
        print "ERROR: failed to load shared object library"
        sys.exit(-1)

    print '  processing %s, from %s' % (outname, treefile)

    # Create TSelector object
    sel = ttHFinalSelector()
    sel.SetCommonSelection(cuts)
    sel.SetOutputFile(outname)

    sel.SetVerbose(10)

    # Load Fakerate histogram in case it was specified
    if frhtype and frfileloc and frhname:
        sel.LoadFakerate(frhtype, frfileloc, frhname)

    # Get tree from input file
    if 'root://' in treefile:
        ROOT.gEnv.SetValue("TFile.AsyncReading", 1)
        # suppress output about opening connections
        ROOT.gEnv.SetValue("XNet.Debug", 0)
        # suppress output about opening connections
        # ROOT.gEnv.SetValue("XrdClientDebug.kUSERDEBUG", 0)
        fb = ROOT.TXNetFile(treefile)
        # fb = ROOT.TXNetFile(treefile+"?cachesz=1024000")
        # fb = ROOT.TNetXNGFile(treefile)
    else:
        fb = ROOT.TFile.Open(treefile)
    # fb = ROOT.TFile.Open(treefile)

    # Use TTreeCache
    ROOT.TTreeCache.SetLearnEntries(1)

    tree = fb.Get('tree')
    tree.SetCacheSize(10000000)

    tree.Process(sel)
    print " read %11d bytes in %d transactions" % (fb.GetBytesRead(),
                                                   fb.GetReadCalls())
    print '  %s done' % (outname)

def main(args, options):
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
    tasks = []
    for proc in mca.listProcesses(): # processes
        comps_to_process = {}
        for comp in mca._allData[proc]: # components
            comps_to_process.setdefault(proc, []).append(comp)
            print "... adding ", os.path.basename(
                         comp.getTree().GetCurrentFile().GetName())


        for n,comp in enumerate(comps_to_process[proc]):
            htype, hname, fileloc = None, None, None
            if comp.hasOption('FakeRate'): # get fakerate info
                stream = open(comp.getOption('FakeRate')).read()
                # look for 'load-histo' line and get info
                match = re.search((r'load-histo:\s*([\w]*)\s*:\s*'
                                   '([\$\.\/\w]*)\s*:\s*([\w]*)\n'),
                                   stream, re.M)
                if not match:
                    print "ERROR: Error while parsing fake rate file"
                    continue

                htype = match.group(1)

                datadir = ("%s/src/CMGTools/TTHAnalysis/data/"
                                     % os.environ['CMSSW_BASE'])
                fileloc = match.group(2).replace('$DATA', datadir)

                hname = match.group(3)

            treefile = comp.getTree().GetCurrentFile().GetName()
            tasks.append((treefile,
                          comp.adaptExpr(evcuts.allCuts(), cut=True),
                          os.path.join(options.printDir,
                                         '%s_%d.root'%(proc,n)),
                          htype, fileloc, hname))

    print 50*'%'

    if options.jobs < 0: pass ## Dry run
    elif options.jobs > 0:
        from multiprocessing import Pool
        pool = Pool(options.jobs)
        pool.map(runFinalTrees, tasks)
    else:
        map(runFinalTrees, tasks)

    print 50*'%'
    print "ALL DONE"
    print 50*'%'


if __name__ == '__main__':
    from optparse import OptionParser
    from CMGTools.TTHAnalysis.plotter.mcPlots import addPlotMakerOptions
    #FIXME
    usage = """
    usage: %prog [options] mca.txt cuts.txt branches.txt
    run with --help to get list of options
    """
    parser = OptionParser(usage=usage)
    addPlotMakerOptions(parser)
    (options, args) = parser.parse_args()

    ## Some default options (too lazy to give them on the command line)
    options.tree = 'treeProducerSusyMultilepton'
    options.lumi = 0.83231
    if options.printDir == 'plots':
        options.printDir = 'ttHFinalTrees/out/'

    os.system('mkdir -p %s' % options.printDir)

    sys.exit(main(args, options))
