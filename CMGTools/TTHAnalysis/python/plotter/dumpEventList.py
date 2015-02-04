#!/usr/bin/env python
import os
import ROOT
from CMGTools.TTHAnalysis.plotter.tree2yield import CutsFile
from optparse import OptionParser

parser = OptionParser(usage="usage: %prog [options] rootfile \nrun with --help to get list of options")
parser.add_option("-r"    , "--run-range"  , dest="runrange"    , default=(0          , 99999999)                  , type="float"                             , nargs=2                           , help="Run range")
parser.add_option("-c"    , "--cut-file"   , dest="cutfile"     , default=None        , type="string"              , help="Cut file to apply")
parser.add_option("-C"    , "--cut"        , dest="cut"         , default=None        , type="string"              , help="Cut to apply")
parser.add_option("-T"    , "--type"       , dest="type"        , default=None        , type="string"              , help="Type of events to select")
# parser.add_option("-F"  , "--fudge"      , dest="fudge"       , default=False       , action="store_true"        , help="print -999 for missing variables")
# parser.add_option("-F"  , "--add-friend" , dest="friendTrees" , action="append"     , default=[]                 , nargs=2                                  , help="Add a friend tree (treename , filename). Can use {name} , {cname} patterns in the treename")
parser.add_option("-F"    , "--friendDir"  , dest="friendDir"   , type="string"       , default="THqFriends_Nov10/" , help="Look for friends in this dir")
parser.add_option("-t"    , "--treeDir"    , dest="treeDir"     , type="string"       , default="trees3/"          , help="Look for trees in this dir")
parser.add_option("-m"    , "--mc"         , dest="ismc"        , default=False       , action="store_true"        , help="print MC match info")
parser.add_option("--mm"  , "--more-mc"    , dest="moremc"      , default=False       , action="store_true"        , help="print more MC match info")
parser.add_option("--tau" , dest="tau"     , default=False      , action="store_true" , help="print Taus")
parser.add_option("-j"    , "--json"       , dest="json"        , default=None        , type="string"              , help="JSON file to apply")
parser.add_option("-n"    , "--maxEvents"  , dest="maxEvents"   , default=-1          , type="int"                 , help="Max events")
parser.add_option("-f"    , "--format"     , dest="fmt"         , default=None        , type="string"              , help="Print this format string")

parser.add_option("--outFile", dest="outFile", default="eventList.txt", type="string", help="Dump the event list to this file")

### CUT-file options
parser.add_option("-S", "--start-at-cut",dest="startCut",   type="string", help="Run selection starting at the cut matched by this regexp, included.")
parser.add_option("-U", "--up-to-cut",   dest="upToCut",   type="string", help="Run selection only up to the cut matched by this regexp, included.")
parser.add_option("-X", "--exclude-cut", dest="cutsToExclude", action="append", default=[], help="Cuts to exclude (regexp matching cut name), can specify multiple times.")
parser.add_option("-I", "--invert-cut",  dest="cutsToInvert",  action="append", default=[], help="Cuts to invert (regexp matching cut name), can specify multiple times.")
parser.add_option("-R", "--replace-cut", dest="cutsToReplace", action="append", default=[], nargs=3, help="Cuts to invert (regexp of old cut name, new name, new cut); can specify multiple times.")
parser.add_option("-A", "--add-cut",     dest="cutsToAdd",     action="append", default=[], nargs=3, help="Cuts to insert (regexp of cut name after which this cut should go, new name, new cut); can specify multiple times.")

(options, args) = parser.parse_args()

if options.cut and options.cutfile: raise RuntimeError, "You can't specify both a cut and a cutfile"

cut = None
if options.cutfile:
    cut = CutsFile(options.cutfile,options).allCuts()
    print "Processing %s" % options.cutfile
elif options.cut:
    cut = options.cut
    print "Processing %s" % cut

with open(options.outFile, "w") as outputfile:
    for procname in args[0].split(','):
        filename = os.path.join(options.treeDir, procname,"ttHLepTreeProducerBase","ttHLepTreeProducerBase_tree.root")
        file = ROOT.TFile.Open(filename)
        treename = "ttHLepTreeProducerBase"
        tree = file.Get(treename)

        tf_file = os.path.join(options.friendDir, "THqFriend_%s.root"%procname)
        tf = tree.AddFriend("THq/t", tf_file),

        tree.Draw(">>elist",cut)
        elist = ROOT.gDirectory.Get("elist")
        tree.SetEventList(elist)
        tree.SetScanField(0) ## scan ALL rows

        tree.GetPlayer().SetScanRedirect(True)
        tempfilename = ".treescan_temp_%s.txt" % procname
        tree.GetPlayer().SetScanFileName(tempfilename)
        tree.Scan("evt","","colsize=20")

        print "... %d events selected in %s" % (tree.GetEntries(cut), procname)

        with open(tempfilename, "r") as tempfile:
            outputfile.write("## %s \n" % procname)
            for line in tempfile:
                spline = line.split('*')
                if len(spline) != 4: continue
                try:
                    eventno = int(spline[2].strip())
                    outputfile.write(spline[2].strip())
                    outputfile.write('\n')
                except ValueError:
                    continue

        os.system('rm %s' % tempfilename)


    # print 'hello', len(output)


