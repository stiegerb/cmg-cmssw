#! /usr/bin/env python
import sys, os
import ROOT

ROOT.gROOT.SetBatch(1)

PLOTS = {
'lep2pt':         ( 'LepGood2_pt',       16, 20,  100),
'fwdJetEtaGap':   ( 'fwdJetEtaGap',      16,  0,   4 ),
'charge':         ( 'LepGood1_charge',    3,-1.5,1.5 ),
'deltaPhill':     ( 'abs(deltaPhill)',   10,  0, 3.14),
'nBJetMedium25':  ( 'nBJetMedium25',      4,  0,   4 ),
'nJet25':         ( 'nJet25',             5,  2,   7 ),
'htJet25':        ( 'htJet25',           20,100, 1000),
'etaFwdJet25':    ( 'etaFwdJet25',       16,  1,   5 )
}

OUTPUTDIR = 'compareplots/'
os.system('mkdir -p %s' % OUTPUTDIR)


treedir1 = sys.argv[1]
treedir2 = sys.argv[2]
print "Input dirs are", treedir1, treedir2

# frienddir1 = 'THqFriends_Nov10/'
frienddir1 = 'THqFriends_Nov4/'
frienddir2 = 'THqFriends_Mar19/'

eventsel = '(abs(LepGood1_pdgId) == 13 && abs(LepGood2_pdgId) == 13) && (nLepGood == 2 || LepGood3_mva < 0.35) && (LepGood1_pt>20 && LepGood2_pt>20) && (LepGood1_charge*LepGood2_charge > 0) && (minMllAFAS > 12) && (min(LepGood1_mva,LepGood2_mva) > 0.7) && LepGood1_tightCharge && LepGood2_tightCharge'
# eventsel = '(abs(LepGood1_pdgId) == 13 && abs(LepGood2_pdgId) == 13) && (nLepGood == 2 || LepGood3_mva < 0.35) && (LepGood1_pt>20 && LepGood2_pt>20) && (LepGood1_charge*LepGood2_charge > 0) && (minMllAFAS > 12) && (min(LepGood1_mva,LepGood2_mva) > 0.7) && LepGood1_tightCharge && LepGood2_tightCharge && nJet25Ctrl>0&&nJet25Eta1>0&&nBJetLoose25>0'




listdir1 = os.listdir(treedir1)
listdir2 = os.listdir(treedir2)

datasets = []

for item in list(set(listdir1).intersection(listdir2)):
	# if not "JE" in item:
	datasets.append(item)

try:
	if sys.argv[3] in datasets:
		datasets = [sys.argv[3]]
	else:
		print "Invalid dataset name", sys.argv[3]
		exit(-1)
except IndexError:
	pass

print "Will process these datasets:", datasets

def process(sample, treedir, frienddir):
	filename = os.path.join(treedir,sample,'ttHLepTreeProducerBase/ttHLepTreeProducerBase_tree.root')
	if not os.path.exists(filename):
		print filename,'not found, skipping'
		return

	print 'Processing', filename
	os.system('mkdir -p %s/%s' % (OUTPUTDIR, sample))

	tfile = ROOT.TFile.Open(filename)
	tree = tfile.Get("ttHLepTreeProducerBase")

	friend_file = os.path.join(frienddir, "THqFriend_%s.root"%sample)
	tree.AddFriend("THq/t", friend_file),

	tree.Draw(">>elist",eventsel)
	elist = ROOT.gDirectory.Get("elist")
	tree.SetEventList(elist)

	for plotname, plotspecs in PLOTS.iteritems():
		plotvar, nbins, xmin, xmax = plotspecs
		htemp = ROOT.TH1D("h_%s"%plotname,plotname,nbins,xmin,xmax)
		tree.Draw("%s>>h_%s"%(plotvar,plotname))
		cv = ROOT.TCanvas("cv_%s"%plotvar, "CV", 800,800)
		htemp.Draw('hist')
		cv.SaveAs("%s/%s/%s_%s_%s.pdf"%(OUTPUTDIR, sample, sample, plotname, treedir.replace('/','')))

	# tree.SetScanField(0)
	# tree.Scan("evt:Jet1_pt:Jet1_btagCSV:Jet2_pt:Jet2_btagCSV:Jet3_pt:Jet3_btagCSV:Jet4_pt:Jet4_btagCSV:nBJetLoose25:nBJetMedium25","evt<70000")

	# print tree.GetEntries()

for sample in datasets:
	process(sample, treedir1, frienddir1)
	process(sample, treedir2, frienddir2)
	# break









