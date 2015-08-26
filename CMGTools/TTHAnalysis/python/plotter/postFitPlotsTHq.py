#!/usr/bin/env python
import ROOT
ROOT.gROOT.SetBatch(True)

from math import sqrt
from os.path import dirname,basename
import os
import CMGTools.TTHAnalysis.plotter.mcPlots as mcP
from CMGTools.TTHAnalysis.plotter.mcAnalysis import MCAnalysis
from CMGTools.TTHAnalysis.plotter.tree2yield import PlotSpec

mergeMap = {
	"tHq_WW" : "tHq",
	"tHq_tt" : "tHq",
	"tHW_WW" : "tHW",
	"tHW_tt" : "tHW",
	"tHWW"   : "tHq",
	"tHtt"   : "tHq",
	"WtHWW"  : "tHW",
	"WtHtt"  : "tHW",
	"ttH"    : "ttX",
	"ttW"    : "ttX",
	"ttZ"    : "ttX",
	"ttG"     : "ttG",
	"ttGStar" : "ttG",
	"VV"     : "VVO",
	"Others" : "VVO"
}

nameChangeL3 = {
	"tHWW"   : "tHq_WW",
	"tHtt"   : "tHq_tt",
	"WtHWW"  : "tHW_WW",
	"WtHtt"  : "tHW_tt",
	"Fakes"  : "Fakes",
	"Others" : "Others",
	"VV"     : "VV",
	"Data"   : "Data",
	"ttZ"   : "ttZ",
	"ttW"   : "ttW",
	"ttH"   : "ttH"
}

rank = {
	'WWqq'       : 0,
	'VV'         : 0,
	'WZ'         : 1,
	'Others'     : 1,
	'ttGStar'    : 2,
	'ttG'        : 3,
	'ttZ'        : 4,
	'ttW'        : 5,
	'ttH'        : 6,
	'RareSM'     : 7,
	'QF_data'    : 8,
	'FR_data'    : 9,
	'Fakes'      : 9,
	'tHW_tt'     : 100,
	'WtHtt'      : 100,
	'tHW_WW'     : 101,
	'WtHWW'      : 101,
	'tHq_tt'     : 102,
	'tHtt'       : 102,
	'tHq_WW'     : 103,
	'tHWW'       : 103,
	'background' : 1001,
	'signal'     : 1002,
	'data'       : 1003
}

def doTinyCmsPrelimCustom(textLeft="_default_",textRight="_default_",hasExpo=False,textSize=0.04,lumi=None, xoffs=0):
	from mcPlots import doSpam
	global options
	if textLeft  == "_default_": textLeft  = options.lspam
	if textRight == "_default_": textRight = options.rspam
	if lumi      == None       : lumi      = options.lumi
	if textLeft not in ['', None]:
		if textLeft.startswith('CMS Preliminary'):
			textLeftRight = textLeft[len('CMS Preliminary'):]
			## new CMS Prelim style
			doSpam('CMS',         (.28 if hasExpo else .17)+xoffs,      .953, .60+xoffs,       .995, align=12, textSize=textSize, textFont=62)
			doSpam('Preliminary', (.28 if hasExpo else .17)+xoffs+0.071,.945, .60+xoffs+0.071, .995, align=12, textSize=textSize, textFont=52)
			# doSpam(textLeftRight, (.28 if hasExpo else .17)+xoffs+0.24, .953, .60+xoffs+0.28,  .995, align=12, textSize=textSize, textFont=42)
			doSpam(textLeftRight, .22, .85, .50, .89, align=12, textSize=0.05, textFont=42)
		else:
			doSpam(textLeft, (.28 if hasExpo else .17)+xoffs, .955, .60+xoffs, .995, align=12, textSize=textSize)
	if textRight not in ['', None]:
		if "%(lumi)" in textRight:
			textRight = textRight % { 'lumi':lumi }
		doSpam(textRight,.68+xoffs+0.015, .953, .99+xoffs+0.015, .995, align=32, textSize=textSize)

def doTinyCmsCustom(textLeft="_default_",textRight="_default_",hasExpo=False,textSize=0.04,lumi=None, xoffs=0):
	from mcPlots import doSpam
	global options
	if textLeft  == "_default_": textLeft  = options.lspam
	if textRight == "_default_": textRight = options.rspam
	if lumi      == None       : lumi      = options.lumi
	if textLeft not in ['', None]:
		if textLeft.startswith('CMS'):
			textLeftRight = textLeft[len('CMS'):]
			## new CMS Prelim style
			doSpam('CMS',         (.28 if hasExpo else .17)+xoffs,      .953, .60+xoffs,       .995, align=12, textSize=textSize, textFont=62)
			# doSpam(textLeftRight, (.28 if hasExpo else .17)+xoffs+0.24, .953, .60+xoffs+0.28,  .995, align=12, textSize=textSize, textFont=42)
			doSpam(textLeftRight, .22, .85, .50, .89, align=12, textSize=0.05, textFont=42)
		else:
			doSpam(textLeft, (.28 if hasExpo else .17)+xoffs, .955, .60+xoffs, .995, align=12, textSize=textSize)
	if textRight not in ['', None]:
		if "%(lumi)" in textRight:
			textRight = textRight % { 'lumi':lumi }
		doSpam(textRight,.68+xoffs+0.015, .953, .99+xoffs+0.015, .995, align=32, textSize=textSize)


AXISLABEL = 'tHq classifier'

options = None
if __name__ == "__main__":
	from optparse import OptionParser
	usage="%prog [options] mcaplot.txt mcafit.txt infile.root mlfile.root channel"
	parser = OptionParser(usage=usage)
	mcP.addPlotMakerOptions(parser)
	parser.add_option("--outDir", dest="outDir", type="string",
					  default="postFitPlots/",
					  help="Output directory for postfit plots");
	(options, args) = parser.parse_args()
	options.path = "trees3/"
	options.lumi = 19.7
	options.poisson = True

	options.lspam = 'CMS'

	try: os.makedirs(options.outDir)
	except OSError: pass

	os.system("cp /afs/cern.ch/user/s/stiegerb/www/index.php "+os.path.dirname(options.outDir))

	mca_merged = MCAnalysis(args[0], options, dryRunning=True) ## for the merged processes
	mca_indivi = MCAnalysis(args[1], options, dryRunning=True) ## for the individual processes
	channel = args[4]

	# var     = args[3];
	var = "x" if not channel == 'l3' else "hLikelihood"

	if channel not in args[2] and channel != 'l3':
		print 30*'#'
		print "Input file correct?!"
		print 30*'#'

	infile = ROOT.TFile(args[2])
	datahistname = "_data" if not channel == 'l3' else "_Data"
	hdata  = infile.Get(var+datahistname)
	## Cosmetics
	hdata.SetMarkerSize(1.6)

	mlfile  = ROOT.TFile(args[3])

	ROOT.gROOT.ProcessLine(".x /afs/cern.ch/user/g/gpetrucc/cpp/tdrstyle.cc(0)")
	ROOT.gROOT.ForceStyle(False)
	ROOT.gStyle.SetErrorX(0.5)
	ROOT.gStyle.SetOptStat(0)
	ROOT.gStyle.SetPaperSize(20.,25.)

	ymax = -1
	for MLD in ["prefit", "fit_b", "fit_s"]:
		plots  = {'data' : hdata}
		mldir  = mlfile.GetDirectory("shapes_"+MLD);
		try:
			mldirname = mldir.GetName()
		except ReferenceError:
			print "Could not find directory shapes_%s in %s" %(MLD, args[3])
			exit(-1)

		outfile = ROOT.TFile(os.path.join(options.outDir, "%s_%s.root" % (MLD, channel)), "RECREATE")
		processes = mca_indivi.listBackgrounds() + mca_indivi.listSignals()

		stack = ROOT.THStack("%s_stack_%s"%(var,MLD),"")

		if options.poisson:
			pdata = mcP.getDataPoissonErrors(hdata, False, False)
			hdata.poissonGraph = pdata ## attach it so it doesn't get deleted

		for process in processes:
			pout = mergeMap[process] if process in mergeMap else process

			# Get the pre-fit histogram (for the color etc.)
			hist = infile.Get("%s_%s" % (var,process))
			if not hist:
				print "Missing %s_%s for %s" % (var,process, process)
				continue
			hist = hist.Clone(var+"_"+process)
			hist.SetDirectory(0)

			## Cosmetics
			if channel == 'l3':
				color = mca_indivi.getProcessOption(process,
													'FillColor',
													hist.GetLineColor())
				hist.SetFillColor(color)
				hist.SetFillStyle(1001)
				hist.SetLineColor(ROOT.kBlack)
				hist.SetLineWidth(1)

			# Get the post-fit shape
			if not channel == 'l3':
				h_postfit = mldir.Get("%s/%s" % (channel,process))
			else:
				h_postfit = mldir.Get("%s/%s" % (channel,nameChangeL3[process]))
			if not h_postfit:
				if hist.Integral() > 0 and process not in mergeMap:
					print "Could not find post-fit shape for %s" % process
					raise RuntimeError
				continue

			# Set the bin-content and error from the post-fit
			for b in xrange(1, hist.GetNbinsX()+1):
				hist.SetBinContent(b, h_postfit.GetBinContent(b))
				hist.SetBinError(b, h_postfit.GetBinError(b))

			if pout in plots:
				plots[pout].Add(hist)
			else:
				plots[pout] = hist
				hist.SetName(var+"_"+pout)
				stack.Add(hist)

		htot         = hdata.Clone(var+"_total")
		htot_postfit = mldir.Get(channel+"/total")
		hbkg         = hdata.Clone(var+"_total_background")
		hbkg_postfit = mldir.Get(channel+"/total_background")

		for b in xrange(1, hdata.GetNbinsX()+1):
			htot.SetBinContent(b , htot_postfit.GetBinContent(b))
			htot.SetBinError(b   , htot_postfit.GetBinError(b))
			hbkg.SetBinContent(b , hbkg_postfit.GetBinContent(b))
			hbkg.SetBinError(b   , hbkg_postfit.GetBinError(b))

		for hist in plots.values() + [htot]:
			outfile.WriteTObject(hist)

		if MLD == 'prefit':
			ymax = 1.8*max(htot.GetMaximum(), hdata.GetMaximum())
		htot.GetYaxis().SetRangeUser(0, ymax)

		## Cosmetics
		htot.GetXaxis().SetTitle(AXISLABEL)
		htot.GetXaxis().SetNdivisions(510)
		htot.GetYaxis().SetNdivisions(510)
		htot.GetXaxis().SetTitleOffset(1.0)
		htot.GetYaxis().SetTitle('Events/Bin')
		htot.GetYaxis().SetTitleOffset(1.25)
		htot.GetYaxis().SetTitleSize(0.06)

		## Prepare split screen
		c1 = ROOT.TCanvas("c1%s"%MLD, "c1", 600, 750); c1.Draw()
		c1.SetWindowSize(600 + (600 - c1.GetWw()), (750 + (750 - c1.GetWh())));
		p1 = ROOT.TPad("pad1","pad1",0,0.29,1,0.99);
		p1.SetTopMargin(0.06);
		p1.SetBottomMargin(0.03);
		p1.Draw();
		p2 = ROOT.TPad("pad2","pad2",0,0,1,0.31);
		p2.SetTopMargin(0);
		p2.SetBottomMargin(0.3);
		p2.SetFillStyle(0);
		p2.Draw();
		p1.cd();

		## Draw absolute prediction in top frame
		htot.Draw("HIST")
		stack.Draw("HIST F SAME")

		if options.poisson:
			hdata.poissonGraph.Draw("PZ")
		else:
			hdata.Draw("E SAME")

		htot.Draw("AXIS SAME")

		## Do the legend
		if MLD == 'fit_b':
			mcP.doLegend(plots, mca_merged, textSize=0.042,
						 cutoff=0.01, noSignal=True)
		else:
			mcP.doLegend(plots, mca_merged, textSize=0.042,
						 cutoff=0.01)
		lspam = options.lspam
		if channel == 'em':
			lspam += r"e^{#pm}#mu^{#pm} channel"
		if channel == 'mm':
			lspam += r"#mu^{#pm}#mu^{#pm} channel"
		if channel == 'l3':
			lspam += "3-lepton channel"
			# lspam += "#{mathcal lll} channel"

		doTinyCmsCustom(hasExpo = False,
		                textSize=(0.055), xoffs=-0.03,
		                textLeft = lspam, textRight = options.rspam,
		                lumi = options.lumi)

		## Do the ratio plot
		## Draw relative prediction in the bottom frame
		p2.cd()
		rdata,rnorm,rnorm2,rline = mcP.doRatioHists(PlotSpec(var,var,"",{}),plots,
													htot, htot,
													maxRange=options.maxRatioRange,
													fitRatio=options.fitRatio)

		## Save the plots
		c1.cd()
		c1.Print(os.path.join(options.outDir, '%s_%s.png' % (channel,MLD)))
		c1.Print(os.path.join(options.outDir, '%s_%s.pdf' % (channel,MLD)))
		c1.Print(os.path.join(options.outDir, '%s_%s.C'   % (channel,MLD)))
		del c1

		outfile.Close()

		## Save the postfit yields also
		dump = open("%s/%s_%s.txt" % (options.outDir,channel,MLD), "w")
		pyields = {
			"background" : [0,0],
			"signal"     : [0,0],
			"data"       : [plots["data"].Integral(), plots["data"].Integral()]
		}
		argset =  mlfile.Get("norm_"+MLD)

		for proc in processes:
			# pout = mergeMap[proc] if proc in mergeMap else proc
			pout = proc
			if pout not in pyields:
				pyields[pout] = [0,0]
			if channel == 'l3':
				rvar = argset.find("%s/%s" % (channel,nameChangeL3[proc]))
			else:
				rvar = argset.find("%s/%s" % (channel,proc))
			if not rvar:
				print 'Did not find rvar for %s/%s' % (channel, proc)
				continue
			pyields[pout][0] += rvar.getVal()
			pyields[pout][1] += rvar.getError()**2
			if not mca_indivi.isSignal(pout):
				pyields["background"][0] += rvar.getVal()
				pyields["background"][1] += rvar.getError()**2
			else:
				pyields["signal"][0] += rvar.getVal()
				pyields["signal"][1] += rvar.getError()**2

		for p in pyields.iterkeys():
			pyields[p][1] = sqrt(pyields[p][1])

		maxlen = max([len(mca_indivi.getProcessOption(p,'Label',p))
					  for p in mca_indivi.listSignals(allProcs=True) +
							   mca_indivi.listBackgrounds(allProcs=True)]+[7])
		fmt    = "%%-%ds %%6.2f \pm %%5.2f\n" % (maxlen+1)

		all_processes =  mca_indivi.listSignals(allProcs=True)
		all_processes += mca_indivi.listBackgrounds(allProcs=True)
		all_processes += ["background","signal","data"]

		for p in sorted(all_processes, key=lambda x:rank[x]):
			if p not in pyields: continue
			if p in ["background","data"]:
				dump.write(("-"*(maxlen+45))+"\n");
			dump.write(fmt % ( mca_indivi.getProcessOption(p,'Label',p)
								 if p not in ["background","signal","data"] else p.upper(),
							   pyields[p][0],
							   pyields[p][1]))

		dump.close()



