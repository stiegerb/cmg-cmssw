#!/usr/bin/env python
import os, ROOT
import os, itertools, optparse
from sys import argv

signals     = ['tH(WW)q']
# backgrounds = ['ttZ','ttW','ttH']
# backgrounds = ['WWqq','ttZ','ttW','ttH','WZ']
backgrounds = ['FR_data','ttW','WZ']
# signals     = ['tH(tautau)q', 'tH(WW)q']
# backgrounds = ['WWqq','ttZ','ttW','ttH','FR_data','WZ']

def getAllKeysFromFile(dir):
    toReturn=[]
    allKeys=dir.GetListOfKeys()
    for tk in allKeys:
        k=tk.GetName()
        obj=dir.Get(k)
        if obj.InheritsFrom('TDirectory') :
            allKeysInSubdir = getAllKeysFromFile(obj)
            for kk in allKeysInSubdir : toReturn.append( k+'/'+kk )
        elif obj.InheritsFrom('TH1') :
            toReturn.append( k )
    return toReturn

def main():
    usage = "%prog [options] treedir outputdir"
    parser = optparse.OptionParser(usage)
    parser.add_option('-o', '--outputFile',  dest='outputFile',  help='Outputfile', default='THQLD_weights.root', type='string')
    parser.add_option('-p', '--doPlots',     dest='doPlots',     help='Produce plots or not', default=False, action='store_true')
    (opt, args) = parser.parse_args()

    if len(args) < 1:
        parser.print_help()

    inputfile = ROOT.TFile(args[0], 'READ')
    variables = list(set([k.split('_')[0] for k in getAllKeysFromFile(inputfile)]))

    histos_to_store = []

    for var in variables:
        signal_hist = None
        for S in signals:
            hist = inputfile.Get(var+'_'+S)
            if signal_hist == None:
                signal_hist = hist.Clone()
            else:
                signal_hist.Add(hist)

        signal_hist.Scale(1.0/signal_hist.Integral())
        signal_hist.SetLineColor(4)
        signal_hist.SetLineWidth(2)
        signal_hist.SetFillStyle(0)
        signal_hist.SetName(var+'_signal')
        histos_to_store.append(signal_hist)

        background_hist = None
        for B in backgrounds:
            hist = inputfile.Get(var+'_'+B)
            if background_hist == None:
                background_hist = hist.Clone()
            else:
                background_hist.Add(hist)
        background_hist.Scale(1.0/background_hist.Integral())
        background_hist.SetLineColor(2)
        background_hist.SetLineWidth(2)
        background_hist.SetFillStyle(0)
        background_hist.SetName(var+'_background')
        histos_to_store.append(background_hist)

        if opt.doPlots:
            maximum = max(background_hist.GetMaximum(), signal_hist.GetMaximum())
            background_hist.SetMaximum(1.2*maximum)
            signal_hist.SetMaximum(1.2*maximum)

            ROOT.gROOT.SetBatch(1)
            ROOT.gStyle.SetOptStat(0)
            ROOT.gStyle.SetOptTitle(0)
            canvas = ROOT.TCanvas('c_'+var,'c',800,800)
            canvas.cd()
            t1 = ROOT.TPad("t1","t1", 0.0, 0.10, 1.0, 1.0)
            t1.Draw()
            t1.cd()
            leg = ROOT.TLegend(0.15,0.9,0.5,0.95)
            leg.SetBorderSize(0)
            leg.SetFillStyle(0)
            leg.SetTextFont(42)
            leg.AddEntry(signal_hist,     'Signal','l')
            leg.AddEntry(background_hist, 'Background','l')
            background_hist.Draw("hist")
            signal_hist.Draw("hist same")
            leg.Draw("same")
            canvas.SaveAs('THQLD_weights/'+var+'.pdf')



    outputfile = ROOT.TFile(opt.outputFile, 'RECREATE')
    for hist in histos_to_store:
        hist.Write(hist.GetName())

    outputfile.Write()
    outputfile.Close()

if __name__ == '__main__':
    main()


