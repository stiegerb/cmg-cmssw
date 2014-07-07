#!/usr/bin/env python
from CMGTools.TTHAnalysis.plotter.mcAnalysis import (MCAnalysis,
                      addMCAnalysisOptions)
from CMGTools.TTHAnalysis.plotter.tree2yield import CutsFile, mergeReports
import os, re, sys
import pickle

def parseComment(line):
    if re.match("\s*#.*", line): ## remove full line comments
        return ""
    return re.sub("#.*","",line).strip() ## remove trailing comments


from optparse import OptionParser
parser = OptionParser(usage="%prog [options] mc.txt cuts.txt systs.txt")
parser.add_option("-v", "--verbose", dest="verbose", default=1, type="int",
                  help="Verbose level [default %default]")
parser.add_option("-c", "--cache", dest="cache", action="store_true",
                  help="Read report from cache")
addMCAnalysisOptions(parser)

(options, args) = parser.parse_args()

options.weight = True
options.final  = True

from os.path import basename
truebinname = os.path.basename(args[1]).strip(".txt") ## ??
binname = 'mm'
if 'em' in truebinname.split('_'): binname = 'em'
if 'ee' in truebinname.split('_'): binname = 'ee'

mca = MCAnalysis(args[0],options)
cachefilename = ".%s.cache"%truebinname
if not options.cache: ## produce the reports
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
    print ">>> Running MCAnalysis getYields >>>"
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
    cuts = CutsFile(args[1],options)
    report = mca.getYields(cuts)
    cachefile = open(cachefilename, 'w')
    pickle.dump(report, cachefile, pickle.HIGHEST_PROTOCOL)
    cachefile.close()
else: ## read the report from cache
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>"
    print ">>> Reading from cache! >>> (%s)" % cachefilename
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>"
    cachefile = open(cachefilename, 'r')
    report = pickle.load(cachefile)
    cachefile.close()

procs = []; iproc = {}
for i,s in enumerate(mca.listSignals()):
    procs.append(s); iproc[s] = i-len(mca.listSignals())+1
for i,b in enumerate(mca.listBackgrounds()):
    procs.append(b); iproc[b] = i+1
allyields = mergeReports([y for x,y in report.iteritems()])
if 'data' not in report:
    report['data'] = allyields

systs = {}
systsEnv = {}
for sysfile in args[2:]:
    for line in open(sysfile, 'r'):
        ## Remove comments and empty lines
        line = parseComment(line)
        if len(line)==0: continue

        field = [_.strip() for _ in line.split(':')]
        if len(field) < 4:
            print "Ignoring bad line in %s: %s" %(sysfile, line)
            continue

        ## Parse fields
        (name, procmap, binmap, amount) = field[:4]
        if re.match(binmap,truebinname) == None: continue

        elif len(field) == 4 or field[4] == "lnN":
            if name not in systs: systs[name] = []
            systs[name].append((re.compile(procmap),amount))
        elif field[4] in ["envelop", "shapeOnly",
                          "templates","alternateShapeOnly"]:
            if name not in systs: systsEnv[name] = []
            systsEnv[name].append((re.compile(procmap),amount,field[4]))
        else:
            raise RuntimeError, "Unknown systematic type %s" % field[4]

        if options.verbose>1:
            try:
                print (" %25s : %16s : %10s : %5.3f" %
                       (name, procmap, binmap, float(amount)))
            except ValueError:
                print (" %25s : %16s : %10s : %s" %
                       (name, procmap, binmap, amount))


    if options.verbose>0:
        print ">>> Loaded %d systematics" % len(systs)
        print ">>> Loaded %d envelop systematics" % len(systsEnv)

# from pprint import pprint
# print pprint(systs)

# exit()
for name in systs.keys():
    effmap = {}
    for p in procs:
        effect = "-"
        for (procmap,amount) in systs[name]:
            if re.match(procmap, p): effect = amount
        effmap[p] = effect
    systs[name] = effmap

print "## Datacard for cut file %s:"%args[1]
print 140*'-'
print 'bin         ', binname
print 'observation ', report['data'][-1][1][0]
klen = max([7, len(binname)]+[len(p) for p in procs])
kpatt = " %%%ds "  % klen
fpatt = " %%%d.%df " % (klen,3)
print 140*'-'
print 'bin                     '," ".join([kpatt % binname  for p in procs])
print 'process                 '," ".join([kpatt % p        for p in procs])
print 'process                 '," ".join([kpatt % iproc[p] for p in procs])
rates = [fpatt % report[p][-1][1][0] for p in procs]
print 'rate                    '," ".join(rates)
print 140*'-'
for name,effmap in sorted(systs.iteritems()):
    print '%-20s lnN' % name," ".join([kpatt % effmap[p]   for p in procs])
print 140*'-'
