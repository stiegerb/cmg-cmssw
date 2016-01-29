#!/usr/bin/env python
import sys, os
import ROOT


def cacheLocally(infile, tmpDir='/tmp'):
    tmpfile = os.path.join(tmpDir, os.path.basename(infile))

    # Copy locally if it's not there already
    if not os.path.exists(tmpfile):
        xrcmd = "xrdcp %s %s" % (infile, tmpfile)
        print " transferring to %s" % tmpDir
        os.system(xrcmd)
        print "... copied successfully"

    infile = tmpfile
    return infile

def run((infile, outfile, options)):
    if infile.startswith("root://"):
        infile = cacheLocally(infile, os.environ.get('TMPDIR', '/tmp'))

    fb = ROOT.TFile.Open(infile)
    tree = fb.Get("tree")

    try: tree.GetName()
    except ReferenceError:
        print "Error: tree not found in %s" % infile
        return False
    print "... processing %s" %infile


    from ROOT import gSystem, TChain

    ## Load the previously compiled shared object library into ROOT
    libfile = "lepTnPFriendTreeMaker_cc.so"
    print '... loading shared object library from %s'%libfile
    gSystem.Load(libfile)
    ## Load it into PyROOT (this is where the magic happens)
    from ROOT import lepTnPFriendTreeMaker

    ana = lepTnPFriendTreeMaker(tree)
    if options.maxEntries > 0:
        ana.setMaxEvents(options.maxEntries)

    ## Handle output file
    if not outfile.endswith('.root'): outfile+='.root'
    output_file = os.path.join(options.outDir, outfile)

    ## Check if it's data or MC
    isdata = 'Run2015' in os.path.basename(infile)

    ## Run the loop
    ana.RunJob(output_file, isdata)

    return True

if __name__ == '__main__':
    from optparse import OptionParser
    usage = "%prog [options] inputTree.root outputTree.root"
    parser = OptionParser(usage=usage)
    parser.add_option("-m", "--maxEntries", dest="maxEntries", type="int",
                      default=-1, help="Max entries to process");
    parser.add_option("-j", "--jobs", dest="jobs", type="int",
                      default=0,
                      help="Use N threads");
    parser.add_option("-p", "--pretend", dest="pretend", action="store_true",
                      default=False,
                      help="Don't run anything");
    # parser.add_option("-q", "--queue", dest="queue", type="string",
    #                   default=None,
    #                   help="Run jobs on lxbatch instead of locally");
    parser.add_option("-o", "--outDir", default="tnptrees",
                      action="store", type="string", dest="outDir",
                      help=("Output directory for tnp trees "
                            "[default: %default/]"))
    (options, args) = parser.parse_args()

    if len(args) != 2:
        parser.print_usage()
        sys.exit(-1)

    os.system('mkdir -p %s'%options.outDir)
    run((args[0], args[1], options))

    # if options.jobs > 0:
    #     print "Running in parallel using %d jobs" % options.jobs
    #     from multiprocessing import Pool
    #     Pool(options.jobs).map(run, tasks)
    # else:
    #     print "Running sequentially"
    #     map(run, tasks)

