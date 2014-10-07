#!/usr/bin/env python
from CMGTools.TTHAnalysis.plotter.mcAnalysis import (MCAnalysis,
                      addMCAnalysisOptions)
from CMGTools.TTHAnalysis.plotter.tree2yield import CutsFile, mergePlots
import re, sys, os
import pickle
import ROOT
import os.path

def parseComment(line):
    if re.match("\s*#.*", line): ## remove full line comments
        return ""
    return re.sub("#.*","",line).strip() ## remove trailing comments


from optparse import OptionParser
usage="%prog [options] mc.txt cuts.txt var bins systs.txt "
parser = OptionParser(usage=usage)
addMCAnalysisOptions(parser)
parser.add_option("-o", "--out", dest="outname", type="string", default=None,
                  help="output name")
parser.add_option("--od", "--outdir", dest="outdir", type="string",
                  default=None, help="output name")
parser.add_option("-v", "--verbose", dest="verbose", default=1, type="int",
                  help="Verbose level [default %default]")
parser.add_option("--asimov", dest="asimov", action="store_true",
                  help="Asimov")
parser.add_option("-c", "--cache", dest="cache", action="store_true",
                  help="Read plots from cache")


(options, args) = parser.parse_args()
options.weight = True
options.final = True
options.allProcesses = True

truebinname = os.path.basename(args[1]).strip(".txt") ## ??
binname = 'mm'
if 'em' in truebinname.split('_'): binname = 'em'
if 'ee' in truebinname.split('_'): binname = 'ee'
outdir = options.outdir+"/" if options.outdir else ""

cachefilename = ".%s.cache.shape"%truebinname
if not options.cache: ## produce the plots
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
    print ">>> Running MCAnalysis getPlotsRaw >>>"
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
    mca = MCAnalysis(args[0],options)
    cuts = CutsFile(args[1],options)
    plots = mca.getPlotsRaw("x", args[2], args[3], cuts.allCuts(),
                                 nodata=options.asimov)
    plots_btagsyst = {}
    weightString = options.weightString
    for var in ['bUp', 'bDown', 'lUp', 'lDown']:
        options.weightString = weightString.replace('SF_btag',
                                                    'SF_btag_%s'%var)
        mcavar = MCAnalysis(args[0],options)
        plots_btagsyst['SF_btag_%s'%var] = mcavar.getPlotsRaw("x", args[2],
                                                args[3],
                                                cuts.allCuts(),
                                                nodata=options.asimov)

    cachefile = open(cachefilename, 'w')
    pickle.dump(plots, cachefile, pickle.HIGHEST_PROTOCOL)
    pickle.dump(plots_btagsyst, cachefile, pickle.HIGHEST_PROTOCOL)
    cachefile.close()
else: ## read the plots from cache
    mca = MCAnalysis(args[0],options)
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>"
    print ">>> Reading from cache! >>> (%s)" % cachefilename
    print ">>>>>>>>>>>>>>>>>>>>>>>>>>>"
    cachefile = open(cachefilename, 'r')
    plots = pickle.load(cachefile)
    plots_btagsyst = pickle.load(cachefile)
    cachefile.close()

## Blinding:
if options.asimov:
    tomerge = []
    # for process in mca.listSignals() + mca.listBackgrounds():
    for process in mca.listBackgrounds():
        if process in plots:
            tomerge.append(plots[process])
    plots['data_obs'] = mergePlots("x_data_obs", tomerge)
else:
    plots['data_obs'] = plots['data'].Clone("x_data_obs")

## Get non-zero processes and assign them a process id
allyields = dict([(p,h.Integral()) for p,h in plots.iteritems()])
processes = []; iproc = {};
for i,s in enumerate(mca.listSignals()):
    if allyields[s] == 0: continue
    processes.append(s)
    iproc[s] = i-len(mca.listSignals())+1
for i,b in enumerate(mca.listBackgrounds()):
    if allyields[b] == 0: continue
    processes.append(b)
    iproc[b] = i+1

## Parse systematics file
systs_old = {}    # systname -> (process mask, amount)
systsEnv = {} # systname -> (process mask, amount, type)
for sysfile in args[4:]:
    for line in open(sysfile, 'r'):
        ## Remove comments and empty lines
        line = parseComment(line)
        if len(line)==0: continue

        field = [_.strip() for _ in line.split(':')]
        if len(field) < 4:
            print "Ignoring bad line in %s: %s" %(sysfile, line)
            continue

        ## Parse fields
        (name, procmask, binmask, amount) = field[:4]
        if re.match(binmask,binname) == None: continue

        ## Flat systematics
        elif len(field) == 4 or field[4] == "lnN":
            if not name in systs_old:
                systs_old[name] = [(re.compile(procmask),amount)]
            else:
                systs_old[name].append((re.compile(procmask),amount))

        ## Shape systematics
        elif field[4] in ["envelop", "shapeOnly", "envelopOnly",
                          "templates","alternateShapeOnly"]:
            systsEnv[name] = (re.compile(procmask),amount,field[4])
        else:
            raise RuntimeError, "Unknown systematic type %s" % field[4]

        if options.verbose>1:
            try:
                print (" %25s : %16s : %10s : %5.3f" %
                       (name, procmask, binmask, float(amount)))
            except ValueError:
                print (" %25s : %16s : %10s : %s" %
                       (name, procmask, binmask, amount))


    if options.verbose>0:
        print ">>> Loaded %d systematics" % len(systs_old)
        print ">>> Loaded %d envelop systematics" % len(systsEnv)

## Flat systematics
systs = {}
for name, dicts in systs_old.iteritems():
    effmap = {}
    for p in processes:
        for (procmask, amount) in dicts:
            if re.match(procmask, p):
                effect = amount
                break
        else:
            effect = "-"
        effmap[p] = effect
    systs[name] = effmap ## systs now: systname -> {process -> effect}

## Shape systematics
for name, (procmask, amount, mode) in systsEnv.iteritems():
    effmap0 = {}
    effmap12 = {}
    for p in processes:
        effect, effect0, effect12 = "-", "-", "-"
        if re.match(procmask, p):
            try:
                effect = float(amount)
            except ValueError, e:
                if mode in ["templates",
                            "alternateShape",
                            "alternateShapeOnly"]:
                    effect = amount
                else: raise e

        if effect == "-" or effect == "0":
            effmap0[p]  = "-"
            effmap12[p] = "-"
            continue
        if mode in ["envelop","envelopOnly","shapeOnly"]:
            nominal = plots[p]

            if 'SF_btag' in name:
                p0up = plots_btagsyst[name+'Up'][p]
                p0dn = plots_btagsyst[name+'Down'][p]
                p0up.SetName(p0up.GetName()+"_"+name+"0Up")
                p0dn.SetName(p0dn.GetName()+"_"+name+"0Down")
                plots["%s_%s_0Up"   %(p,name)] = p0up
                plots["%s_%s_0Down" %(p,name)] = p0dn
                if options.verbose>1: print name,p,'Up',p0up.Integral()
                if options.verbose>1: print name,p,'Dn',p0dn.Integral()
                effect0 = "1"
                effect12 = "1"
                p0up.SetLineColor(ROOT.kBlue)
                p0dn.SetLineColor(ROOT.kRed)
                for h in p0up, p0dn:
                    h.SetFillStyle(0); h.SetLineWidth(1)

            elif 'StatBounding' in name:
                p0up = nominal.Clone(nominal.GetName()+"_"+name+"Up")
                p0dn = nominal.Clone(nominal.GetName()+"_"+name+"Down")
                for ibin in xrange(1, p0up.GetNbinsX()+1):
                    p0up.SetBinContent(ibin, nominal.GetBinContent(ibin) + nominal.GetBinError(ibin))
                    p0dn.SetBinContent(ibin, nominal.GetBinContent(ibin) - nominal.GetBinError(ibin))

                p0up.SetName(nominal.GetName()+"_"+name+"Up")
                p0dn.SetName(nominal.GetName()+"_"+name+"Down")
                plots["%s_%s_Up"   %(p,name)] = p0up
                plots["%s_%s_Down" %(p,name)] = p0dn
                if options.verbose>1: print name,p,'Up',p0up.Integral()
                if options.verbose>1: print name,p,'Dn',p0dn.Integral()
                effect0 = "1.0"
                effect12 = "1.0"
                p0up.SetLineColor(ROOT.kBlue)
                p0dn.SetLineColor(ROOT.kRed)
                for h in p0up, p0dn:
                    h.SetFillStyle(0); h.SetLineWidth(1)

            else:
                ## Overall scale up/down
                p0up = nominal.Clone(nominal.GetName()+"_"+name+"0Up"  )
                p0up.Scale(effect)
                p0dn = nominal.Clone(nominal.GetName()+"_"+name+"0Down")
                p0dn.Scale(1.0/effect)

                ## Shape effect to turn on towards the higher bins
                p1up = nominal.Clone(nominal.GetName()+"_"+name+"1Up"  )
                p1dn = nominal.Clone(nominal.GetName()+"_"+name+"1Down")
                ## Shape effect to reach full value in the middle range
                p2up = nominal.Clone(nominal.GetName()+"_"+name+"2Up"  )
                p2dn = nominal.Clone(nominal.GetName()+"_"+name+"2Down")

                nbin = nominal.GetNbinsX()
                xmin = nominal.GetBinCenter(1)
                xmax = nominal.GetBinCenter(nbin)
                for b in xrange(1,nbin+1):
                    # x runs from 0 to 1 over the bins
                    x = (nominal.GetBinCenter(b)-xmin)/(xmax-xmin)
                    # straight line from (0,-1) to (1,+1):
                    c1 = 2*(x-0.5)
                    # parabola through (0,-1), (0.5,1), (1,-1):
                    c2 = 1 - 8*(x-0.5)**2
                    p1up.SetBinContent(b, nominal.GetBinContent(b)*pow(effect,+c1))
                    p1dn.SetBinContent(b, nominal.GetBinContent(b)*pow(effect,-c1))
                    p2up.SetBinContent(b, nominal.GetBinContent(b)*pow(effect,+c2))
                    p2dn.SetBinContent(b, nominal.GetBinContent(b)*pow(effect,-c2))
                if mode != "shapeOnly":
                    plots["%s_%s_0Up"   %(p,name)] = p0up
                    plots["%s_%s_0Down" %(p,name)] = p0dn
                    effect0 = "1"
                plots["%s_%s_1Up"   %(p,name)] = p1up
                plots["%s_%s_1Down" %(p,name)] = p1dn
                plots["%s_%s_2Up"   %(p,name)] = p2up
                plots["%s_%s_2Down" %(p,name)] = p2dn
                effect12 = "1"
                # useful for plotting
                for h in p0up, p0dn, p1up, p1dn, p2up, p2dn:
                    h.SetFillStyle(0); h.SetLineWidth(2)
                for h in p1up, p1dn: h.SetLineColor(4)
                for h in p2up, p2dn: h.SetLineColor(2)
        elif mode in ["templates"]:
            nominal = plots[p]
            try:
                p0Up = plots["%s_%s_Up" % (p, effect)] ## effect is JES now
                p0Dn = plots["%s_%s_Dn" % (p, effect)]
            except KeyError:
                raise RuntimeError, ("Missing templates %s_%s_(Up,Dn) for %s"
                                     % (p,effect,name))
            p0Up.SetName("%s_%sUp"   % (nominal.GetName(),name))
            p0Dn.SetName("%s_%sDown" % (nominal.GetName(),name))
            plots[str(p0Up.GetName())[2:]] = p0Up
            plots[str(p0Dn.GetName())[2:]] = p0Dn
            effect0  = "1"
            effect12 = "-"
        elif mode in ["alternateShape", "alternateShapeOnly"]:
            nominal = plots[p]
            try:
                alternate = plots[effect]
            except KeyError:
                raise RuntimeError, ("Missing shape %s for %s" % (effect,name))

            alternate.SetName("%s_%sUp" % (nominal.GetName(),name))
            if mode == "alternateShapeOnly":
                alternate.Scale(nominal.Integral()/alternate.Integral())
            mirror = nominal.Clone("%s_%sDown" % (nominal.GetName(),name))
            for b in xrange(1,nominal.GetNbinsX()+1):
                y0 = nominal.GetBinContent(b)
                yA = alternate.GetBinContent(b)
                yM = y0
                if (y0 > 0 and yA > 0):
                    yM = y0*y0/yA
                elif yA == 0:
                    yM = 2*y0
                mirror.SetBinContent(b, yM)
            if mode == "alternateShapeOnly":
                # keep same normalization
                mirror.Scale(nominal.Integral()/mirror.Integral())
            else:
                # mirror normalization
                mnorm = (nominal.Integral()**2)/alternate.Integral()
                mirror.Scale(mnorm/alternate.Integral())
            plots[alternate.GetName()] = alternate
            plots[mirror.GetName()] = mirror
            effect0  = "1"
            effect12 = "-"
        effmap0[p]  = effect0
        effmap12[p] = effect12
    systsEnv[name] = (effmap0,effmap12,mode)


## Create the datacard and write it to a file
myout = outdir
myyields = dict([(k,v) for (k,v) in allyields.iteritems()])
datacard = open(myout+binname+".shape.card.txt", "w");
datacard.write("## Datacard for cut file %s\n"%args[1])
datacard.write(118*'-'+'\n')
datacard.write("shapes *        * %s.input.root x_$PROCESS "
               "x_$PROCESS_$SYSTEMATIC\n" % binname)
datacard.write(118*'-'+'\n')
datacard.write('bin         %s\n' % binname)
datacard.write('observation %s\n' % myyields['data_obs'])
datacard.write(118*'-'+'\n')
klen = max([7, len(binname)]+[len(p) for p in processes])
kpatt = "%%%ds" % klen
fpatt = "%%%d.%df" % (klen,3)

headlen = 20
headlen = max([headlen] + [len(_) for _ in systs.keys()])
headlen = max([headlen] + [len(_) for _ in systsEnv.keys()])
headlen += 7
hpatt  = "%%-%ds" % headlen
hpatt2 = "%%-%ds %%%ds" % (headlen-6, 5)

columnstring = len(processes)*("%s "% (kpatt % binname))
datacard.write(hpatt%'bin'+ columnstring + '\n')
columnstring = " ".join([kpatt % p for p in processes])
datacard.write(hpatt%'process' + columnstring + '\n')
columnstring = " ".join([kpatt % iproc[p] for p in processes])
datacard.write(hpatt%'process' + columnstring + '\n')
columnstring = " ".join([fpatt % myyields[p] for p in processes])
datacard.write(hpatt%'rate' + columnstring + '\n')
datacard.write(118*'-' + '\n')
for name,effmap in sorted(systs.iteritems()):
    columnstring = " ".join([kpatt % effmap[p] for p in processes])
    datacard.write((hpatt2 % (name, 'lnN')) + columnstring + '\n')
for name,(effmap0,effmap12,mode) in sorted(systsEnv.iteritems()):
    if mode == "templates":
        columnstring = " ".join([kpatt % effmap0[p] for p in processes])
        datacard.write((hpatt2 % (name, 'shape')) + columnstring +"\n")
    if mode in ["envelop", "envelopOnly"]:
        columnstring = " ".join([kpatt % effmap0[p] for p in processes])
        datacard.write((hpatt2 % (name+"0", 'shape')) + columnstring +"\n")
    if mode in ["envelop", "shapeOnly"]:
        if "StatBounding" in name:
            columnstring = " ".join([kpatt % effmap0[p] for p in processes])
            datacard.write((hpatt2 % (name, 'shape')) + columnstring +"\n")
            continue
        columnstring = " ".join([kpatt % effmap12[p] for p in processes])
        datacard.write((hpatt2 % (name+"1", 'shape')) + columnstring +"\n")
        columnstring = " ".join([kpatt % effmap12[p] for p in processes])
        datacard.write((hpatt2 % (name+"2", 'shape')) + columnstring +"\n")

datacard.write(118*'-'+'\n')
datacard.close()

print "Wrote to",myout+binname+".shape.card.txt"

## Print the datacard to stdout
if options.verbose:
    print "#"*120
    os.system("cat %s.shape.card.txt" % (myout+binname));
    print "#"*120

## Write the histograms to a root file
import ROOT
tfile = ROOT.TFile.Open(outdir+binname+".input.root", "RECREATE")
print "Yields"
for n,h in sorted(plots.iteritems()):
    if options.verbose:
        print " %-40s ( %7.3f events )" % (h.GetName(), h.Integral())
    tfile.WriteTObject(h,h.GetName())
tfile.Close()

print "Wrote to",outdir+binname+".input.root"

