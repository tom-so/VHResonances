from Utils import *

import tdrstyle_all
tdrstyle_all.writeExtraText = True
tdrstyle_all.extraText  = "Work in progress"

colors = {"ele_ID_kincut":                  (ROOT.kBlack,ROOT.kDot),
          "ele_ID_MVA_loose_iso":           (ROOT.kRed+1,ROOT.kFullCircle),
          "ele_ID_MVA_loose_noIso":         (ROOT.kAzure+10,ROOT.kFullTriangleUp),
          "ele_ID_HEEP":                    (ROOT.kGray,ROOT.kFullTriangleDown),
          "ele_ID_veto":                    (ROOT.kRed,ROOT.kOpenCircle),
          "ele_ID_veto_noIso":              (ROOT.kOrange+1,ROOT.kFullCross),
          "ele_ID_loose":                   (ROOT.kAzure+1,ROOT.kOpenSquare),
          "ele_ID_loose_noIso":             (ROOT.kGreen+2,ROOT.kFullSquare),
          "ele_ID_medium":                  (ROOT.kGreen+1,ROOT.kDot),
          "ele_ID_medium_noIso":            (ROOT.kBlue+1,ROOT.kFullDiamond),
          "ele_ID_tight":                   (ROOT.kMagenta,ROOT.kDot),
          "ele_ID_tight_noIso":             (ROOT.kOrange,ROOT.kDot),

          "muon_ID_kincut":                 (ROOT.kBlack,ROOT.kDot),
          "muon_ID_CutBasedIdLoose":        (ROOT.kGreen+1,ROOT.kFullTriangleUp),
          "muon_ID_CutBasedIdMedium":       (ROOT.kAzure+10,ROOT.kDot),
          "muon_ID_CutBasedIdMediumPrompt": (ROOT.kGray,ROOT.kDot),
          "muon_ID_CutBasedIdTight":        (ROOT.kOrange+1,ROOT.kDot),
          "muon_ID_CutBasedIdGlobalHighPt": (ROOT.kRed+1,ROOT.kFullTriangleDown),
          "muon_ID_CutBasedIdTrkHighPt":    (ROOT.kOrange-2,ROOT.kFullCircle),
          "muon_ID_MvaLoose":               (ROOT.kGreen,ROOT.kDot),
          "muon_ID_MvaMedium":              (ROOT.kAzure+1,ROOT.kDot),
          "muon_ID_MvaTight":               (ROOT.kMagenta,ROOT.kDot),
          "muon_ID_TkIsoLoose":             (ROOT.kBlue+1,ROOT.kDot),
          "muon_ID_TkIsoTight":             (ROOT.kRed,ROOT.kDot),

}

class PlotLeptonIDEfficiency(ModuleRunnerBase):
    def __init__(self,year="2016", collection="Puppi", channel="muonchannel", isDR=True):
        ModuleRunnerBase.__init__(self,year)
        self.outdir     = self.Path_ANALYSIS+"Analysis/OtherPlots/LeptonID/"
        self.HistType   = "LeptonID"
        self.doubleID   = "_2IDs"
        self.collection = collection
        self.channel    = channel
        self.isDR       = isDR
        self.isMuon     = self.channel=="muonchannel"
        self.isEle      = self.channel=="electronchannel"
        self.IDs        = colors.keys() + [x+self.doubleID for x in colors.keys() if "muon" in x ]
        self.IDs        = list(filter(lambda x: (self.isMuon and "muon" in x) or (self.isEle and "ele" in x), self.IDs))
        self.IDs        = list(reversed(sorted(self.IDs)))
        self.MinSetIDs  = ["ID_MVA", "veto_noIso", "loose_noIso", "medium_noIso", "HEEP", "IdLoose", "HighPt"]
        # self.HistName   = "_DR12" if self.isDR else "_pt12"
        self.HistName   = "_DR12_sel" if self.isDR else "_pt12_sel"
        self.nameXaxis  = "#Delta R(l_{1},l_{2})" if isDR else "p_{T} [GeV]"
        self.nameYaxis  = "Efficiency"
        self.Xaxis_min  = 0 if self.isDR else 0
        self.Xaxis_max  = 1 if self.isDR else 5000
        self.Yaxis_min  = 0.5 if self.isEle else 0.8
        self.Yaxis_max  = 1.2 if self.isEle else 1.1
        self.histos     = {}

        self.SignalSamples.append("MC_DY")


        os.system("mkdir -p "+self.outdir)

    def LoadHistos(self):
        for sample in self.SignalSamples:
            filename = self.Path_STORAGE+self.year+"/LeptonIDStudies/"+self.collection+"/"+self.channel+"/nominal/uhh2.AnalysisModuleRunner.MC."+sample+"_"+self.year+"_noTree.root"
            if "MC_DY" in sample and self.year!="RunII": filename = filename.replace(".root","_merge.root")
            file_ = ROOT.TFile(filename)
            for ID in self.IDs:
                hname = self.HistType+"_NLeptonSel/"+ID+self.HistName
                if self.doubleID in ID: hname = hname.replace(self.doubleID, "")+self.doubleID
                self.histos[sample+ID] = file_.Get(hname).Clone(sample+ID)
                self.histos[sample+ID].SetDirectory(0)
            file_.Close()

    def NormHistos(self):
        # First add and the divide
        for ID in self.IDs:
            for sample in self.SignalSamples:
                if "MC_DY" == sample: continue
                if ID in self.histos:
                    self.histos[ID].Add(self.histos[sample+ID])
                else:
                    self.histos[ID] = self.histos[sample+ID].Clone(ID)

        if self.isMuon: h_den = self.histos["muon_ID_kincut"].Clone("h_den")
        if self.isEle: h_den = self.histos["ele_ID_kincut"].Clone("h_den")
        for ID in self.IDs:
            self.histos[ID].Divide(h_den)

        for sample in self.SignalSamples:
            if self.isMuon: h_den = self.histos[sample+"muon_ID_kincut"].Clone("h_den"+sample)
            if self.isEle: h_den = self.histos[sample+"ele_ID_kincut"].Clone("h_den"+sample)
            for ID in self.IDs:
                self.histos[sample+ID].Divide(h_den)

    def ResetCanvas(self, name):
        self.canv = tdrCanvas(name, self.Xaxis_min, self.Xaxis_max, self.Yaxis_min, self.Yaxis_max, self.nameXaxis,self.nameYaxis)
        self.leg = tdrLeg(0.40,0.70,0.95,0.89, 0.025, 42, ROOT.kBlack)
        self.leg.SetNColumns(2 if "simple" in name else 3)

    def PlotHistos(self):
        self.ResetCanvas("canv_"+self.year+self.channel+self.HistName)
        for [ID,hist] in self.histos.items():
            if "Zprime" in ID or "MC_DY" in ID: continue
            color = colors[ID.replace(self.doubleID,"")][0]
            tdrDraw(hist, "hist", colors[ID.replace(self.doubleID,"")][1], color, 2 if self.doubleID in ID else 1, color, 0, color)
            self.leg.AddEntry(hist, ID.replace("muon_","").replace("ele_","").replace("CutBasedId",""), "l")
        self.canv.SaveAs(self.outdir+self.year+"_"+self.channel+self.HistName+".pdf")

        self.ResetCanvas("canv_simple_"+self.year+self.channel+self.HistName)
        for [ID,hist] in self.histos.items():
            if "Zprime" in ID or "MC_DY" in ID: continue
            if all(not x in ID for x in self.MinSetIDs): continue
            color = colors[ID.replace(self.doubleID,"")][0]
            tdrDraw(hist, "P", colors[ID.replace(self.doubleID,"")][1], color, 2 if self.doubleID in ID else 1, color, 0, color)
            self.leg.AddEntry(hist, ID.replace("muon_","").replace("ele_","").replace("CutBasedId",""), "lp")
        self.canv.SaveAs(self.outdir+self.year+"_"+self.channel+self.HistName+"_simple.pdf")

        if True: # Used only as a xcheck
            for sample in self.SignalSamples:
                self.ResetCanvas("canv_simple_"+self.year+self.channel+self.HistName+sample)
                for ID in self.IDs:
                    if self.isMuon and not "muon" in ID: continue
                    if self.isEle and not "ele" in ID: continue
                    hist = self.histos[sample+ID]
                    if all(not x in ID for x in self.MinSetIDs): continue
                    color = colors[ID.replace(self.doubleID,"")][0]
                    tdrDraw(hist, "P", colors[ID.replace(self.doubleID,"")][1], color, 2 if self.doubleID in ID else 1, color, 0, color)
                    self.leg.AddEntry(hist, ID.replace("muon_","").replace("ele_","").replace("CutBasedId",""), "lp")
                self.canv.SaveAs(self.outdir+self.year+"_"+self.channel+"_"+sample+self.HistName+"_simple.pdf")




def main():
    years = ["2016","2017","2018", "RunII"]
    channels = ["muonchannel", "electronchannel"]
    # years = ["2016"]
    # channels = ["muonchannel"]
    for year in years:
        for channel in channels:
            for isDR in [True,False]:
            # for isDR in [True]:
                PlotSyst = PlotLeptonIDEfficiency(year=year, channel=channel, isDR=isDR)
                PlotSyst.LoadHistos()
                PlotSyst.NormHistos()
                PlotSyst.PlotHistos()


if __name__ == '__main__':
    main()
