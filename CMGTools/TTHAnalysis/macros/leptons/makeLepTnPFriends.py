#!/usr/bin/env python
import sys, os, pickle
import ROOT

from array import array
import os.path as osp

PAIRSEL = "(evSel==1&&abs(mass-91.)<20.)"
SELECTIONS = [
    ('inclusive',      PAIRSEL),
    ('singleTriggers', PAIRSEL+"&&passSingle"),
    ('doubleTriggers', PAIRSEL+"&&passDouble"),
    # ('ttbar', "(evSel>1)"),
]

LEPSEL = [
    ('e', 'abs(pdgId)==11', 'Electrons'),
    ('m', 'abs(pdgId)==13', 'Muons'),
]

PTBINS    = [10.,15.,20.,25.,30.,37.5,45.,60.,80.,100.]
ETABINS   = [0.,0.25,0.50,0.75,1.00,1.25,1.50,2.00,2.50]
NVERTBINS = [0,4,7,8,9,10,11,12,13,14,15,16,17,19,22,25,30]
BINNINGS = [
    ('pt',     PTBINS,    'p_{T} [GeV]'),
    ('abseta', ETABINS,   '|#eta|'),
    ('nVert',  NVERTBINS, 'N_{vertices}'),
]

NUMERATOR   = "passTight&&passTCharge"
DENOMINATOR = "passLoose"

INPUTS = {
    'data':[
        "DoubleEG_Run2015C_Oct05_runs_254231_254914",
        "DoubleEG_Run2015D_Oct05_runs_256630_258158",
        "DoubleEG_Run2015D_PromptV4_runs_258159_260627",
        "DoubleMuon_Run2015C_Oct05_runs_254231_254914",
        "DoubleMuon_Run2015D_Oct05_runs_256630_258158",
        "DoubleMuon_Run2015D_PromptV4_runs_258159_260627",
        "MuonEG_Run2015C_Oct05_runs_254231_254914",
        "MuonEG_Run2015D_Oct05_runs_256630_258158",
        "MuonEG_Run2015D_PromptV4_runs_258159_260627",
        "SingleElectron_Run2015C_Oct05_runs_254231_254914",
        "SingleElectron_Run2015D_Oct05_runs_256630_258158",
        "SingleElectron_Run2015D_PromptV4_runs_258159_260627",
        "SingleMuon_Run2015C_Oct05_runs_254231_254914",
        "SingleMuon_Run2015D_Oct05_runs_256630_258158",
        "SingleMuon_Run2015D_PromptV4_runs_258159_260627",
        ],
    'DY':["DYJetsToLL_M50"],
    'ttbar':[
        "TTJets_DiLepton",
        "TTJets_SingleLeptonFromTbar_ext",
        "TTJets_SingleLeptonFromTbar",
        "TTJets_SingleLeptonFromT_ext",
        "TTJets_SingleLeptonFromT",
        ],
}

class EfficiencyPlot(object):
    """Simple class for making plots comparing TEfficiency objects"""
    def __init__(self, name):
        self.name = name
        self.effs = []
        self.legentries = []
        self.plotformats = ['.pdf', '.png']
        self.xtitle = ''
        self.ytitle = 'MVA tight efficiency'
        self.tag = None
        # self.tagpos = (0.95,0.99)
        self.tagpos = (0.15,0.4)

        self.colors = [ROOT.kBlack, ROOT.kAzure+1, ROOT.kOrange+8]

    def add(self,eff,tag):
        self.effs.append(eff)
        self.legentries.append(tag)

    def show(self, outname, outdir):
        canv = ROOT.TCanvas("canv_%s"%(self.name), "efficiencies", 800, 800)
        canv.SetRightMargin(0.05)
        canv.SetTopMargin(0.05)

        rangex = (self.effs[0].GetTotalHistogram().GetXaxis().GetXmin(),
                  self.effs[0].GetTotalHistogram().GetXaxis().GetXmax())

        axes = ROOT.TH2D("axes_%s"%(self.name),"axes",
                         1, rangex[0], rangex[1], 1, 0.0, 1.0)
        axes.GetXaxis().SetTitle(self.xtitle)
        axes.GetYaxis().SetTitleOffset(1.2)
        axes.GetYaxis().SetTitle(self.ytitle)
        axes.Draw("axis")

        leg = ROOT.TLegend(.12,.15,.60,.30+0.037*max(len(self.effs)-3,0))

        leg.SetBorderSize(0)
        leg.SetFillColor(0)
        leg.SetFillStyle(0)
        leg.SetShadowColor(0)
        leg.SetTextFont(43)
        leg.SetTextSize(26)

        for eff,entry,color in zip(self.effs,self.legentries,self.colors):
            eff.SetLineColor(color)
            eff.SetLineWidth(2)
            eff.SetMarkerStyle(20)
            eff.SetMarkerSize(1.4)
            eff.SetMarkerColor(color)
            eff.Draw("PE same")
            leg.AddEntry(eff, entry, 'PL')
        leg.Draw()

        if self.tag:
            tlat = ROOT.TLatex()
            tlat.SetTextFont(43)
            tlat.SetNDC(1)
            tlat.SetTextAlign(33) # right aligned
            if self.tagpos[0] < 0.50:
                # left aligned if on the left side
                tlat.SetTextAlign(13)
            tlat.SetTextSize(26)
            tlat.DrawLatex(self.tagpos[0], self.tagpos[1], self.tag)

        for ext in self.plotformats:
            canv.SaveAs(osp.join(outdir, "%s%s"%(outname,ext)))


def projectFromTree(hist, varname, sel, tree, option=''):
    try:
        tree.Project(hist.GetName(),varname, sel, option)
        return True
    except Exception, e:
        raise e

def getHistoFromTree(tree, sel, bins, var="mass",
                     hname="histo",
                     titlex='', weight=''):
    histo = ROOT.TH1D(hname, "histo" , len(bins)-1, array('d', bins))
    if sel=="": sel = "1"
    sel = "(%s)" % sel
    if len(weight):
        sel = "%s*(%s)" % (sel, weight)
    projectFromTree(histo, var, sel, tree)
    histo.SetLineWidth(2)
    histo.GetXaxis().SetTitle(titlex)
    histo.Sumw2()
    histo.SetDirectory(0)
    return histo

def getEfficiency((tree, pairsel, probnum, probdenom, var, bins)):
    failedsel = '(%s)&&(%s)' % (pairsel, probdenom)
    passedsel = '(%s)&&(%s)' % (pairsel, probnum)
    hfailed = getHistoFromTree(tree,failedsel,bins,var,hname="%s_failed"%var)
    hpassed = getHistoFromTree(tree,passedsel,bins,var,hname="%s_passed"%var)

    eff = ROOT.TEfficiency(hpassed, hfailed)
    return eff

def makeEfficiencies(tree):
    result = {}
    for lep,lepsel,_ in LEPSEL:
        for name,sel in SELECTIONS:
            finalsel = '(%s)&&(%s)' % (lepsel, sel)
            for var,bins,_ in BINNINGS:
                result[(lep,name,var)] = getEfficiency((tree,
                                                 finalsel,
                                                 NUMERATOR,
                                                 DENOMINATOR,
                                                 var,bins))
    return result

def makePlots(efficiencies, options):
    ROOT.gROOT.SetBatch(1)
    ROOT.gStyle.SetOptTitle(0)
    ROOT.gStyle.SetOptStat(0)

    ptitle = {
        'data' : 'Data',
        'DY'   : 'DY MC'
    }

    seltitle = {
        'inclusive'      : 'Inclusive',
        'singleTriggers' : 'Single lepton triggers',
        'doubleTriggers' : 'Double lepton triggers',
        'ttbar'          : 'ttbar',
    }

    for lep,_,lepname in LEPSEL:
        for var,bins,xtitle in BINNINGS:

            # Compare data/MC in each binning/selection
            for selname,_ in SELECTIONS:
                if not selname == 'inclusive': continue
                plot = EfficiencyPlot('%s_%s_%s'%(lep,var,selname))
                plot.xtitle = xtitle
                plot.tag = '%s, %s'%(lepname, seltitle.get(selname, selname))

                legentries, effs_to_plot = [], []
                for pname,effs in efficiencies.iteritems():
                    plot.add(effs[(lep,selname,var)],
                             ptitle.get(pname,pname))

                plot.show('tnp_eff_%s'%(plot.name), options.outDir)

            # Compare single/double triggers:
            for pname,effs in efficiencies.iteritems():
                plot = EfficiencyPlot('%s_%s_%s'%(lep,var,pname))
                plot.xtitle = xtitle
                plot.tag = '%s, %s'%(lepname, ptitle.get(pname, pname))

                legentries, effs_to_plot = [], []
                for selname,_ in SELECTIONS:
                    plot.add(effs[(lep,selname,var)],
                             seltitle.get(selname,selname))

                plot.show('tnp_eff_%s'%(plot.name), options.outDir)

if __name__ == '__main__':
    from optparse import OptionParser
    usage = "%prog [options] tnpTreeDir"
    parser = OptionParser(usage=usage)
    parser.add_option("-m", "--maxEntries", dest="maxEntries", type="int",
                      default=-1, help="Max entries to process");
    parser.add_option("-j", "--jobs", dest="jobs", type="int",
                      default=0,
                      help="Use N threads");
    parser.add_option("-p", "--pretend", dest="pretend", action="store_true",
                      default=False,
                      help="Don't run anything");
    parser.add_option("-o", "--outDir", default="tnptrees",
                      action="store", type="string", dest="outDir",
                      help=("Output directory for tnp trees "
                            "[default: %default/]"))
    parser.add_option("-f", "--filter", default='Run2015,DYJetsToLL_M50',
                      type="string", dest="filter",
                      help=("Comma separated list of filters to apply "
                            "[default: %default/]"))
    (options, args) = parser.parse_args()

    # Make all the efficiencies
    cachefilename = "tnpefficiencies.pck"
    if not osp.isfile(cachefilename):
        efficiencies = {}
        for proc in ['data', 'DY']:
            print '... processing', proc
            # Read the files and combine trees to a chain
            chain = ROOT.TChain('fitter_tree')
            for fname in INPUTS[proc]:
                stump = '_treeProducerSusyMultilepton_tree.root'
                fpath = osp.join(args[0],
                                 '%s%s'%(fname,stump))
                if osp.isfile(fpath):
                    chain.Add(fpath)
                else:
                    print "Missing file: %s" % fpath
                    print " ... continuing without"

            # Get the efficiencies for each chain
            efficiencies[proc] = makeEfficiencies(chain)

        cachefile = open(cachefilename, 'w')
        pickle.dump(efficiencies, cachefile, pickle.HIGHEST_PROTOCOL)
        print '>>> Wrote tnp efficiencies to cache (%s)' % cachefilename
        cachefile.close()
    else:
        cachefile = open(cachefilename, 'r')
        efficiencies = pickle.load(cachefile)
        print '>>> Read tnp efficiencies from cache (%s)' % cachefilename
        cachefile.close()

    os.system('mkdir -p %s'%options.outDir)
    makePlots(efficiencies, options)



















