#include "PlotLimits.hpp"



void PlotLimits(bool doObs, bool isHbb) {

  // double plot_hi = 2800;
  const double plot_lo = 300;
  const double plot_hi = 8200;

  const double yaxis_lo = 1e-01;
  const double yaxis_hi = 5e03;

  std::map<std::string, int> colors = {
    {"2016",kViolet-9+1}, {"2017",kOrange+1}, {"2018",kCyan+1}, {"RunII",kGreen+2}, {"fullRunII", kGreen+1},
    {"NN",kOrange+1}, {"NN_1",kViolet-9+1}, {"NN_2",kCyan+1}, {"CNN",kBlue+1}, {"tau42",kBlack},
    {"btag_DeepBoosted_probHbb",kViolet-9+1}, {"tau32",kBlue+1}, {"tau21",kOrange+1},
    {"btag_DeepBoosted_H4qvsQCDp2", kOrange+1}, {"btag_DeepBoosted_H4qvsQCDp02", kYellow+1}, {"btag_DeepBoosted_H4qvsQCDpt1000", kCyan+1},
    {"btag_DeepBoosted_H4qvsQCDpt1000p2", kBlue+1}, {"btag_DeepBoosted_H4qvsQCDpt1000p02", kRed+1},
    {"btag_DeepBoosted_H4qvsQCDptdep", kRed+1},
    {"btag_DeepBoosted_H4qvsQCD",               kAzure+7},
    {"btag_DeepBoosted_H4qvsQCDmassdep",        kGreen+3},
    {"btag_DeepBoosted_H4qvsQCDmassdep_2",      kViolet-9+1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_3",      kAzure+1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_bb",     kViolet-9},
    {"btag_DeepBoosted_H4qvsQCDmassdep_cc",     kOrange+1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_gg",     kOrange-1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_cc_2",   kViolet-9-9},
    {"btag_DeepBoosted_H4qvsQCDmassdep_gg_2",   kGreen+1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_cc_3",   kCyan+1},
    {"btag_DeepBoosted_H4qvsQCDmassdep_gg_3",   kBlue+1},
  };

  TGraph* gr_theo    = new TGraphErrors(nPoints, &(MassPoints[0]), &theo_xsec[0]);
  TGraph* gr_HVT_A   = new TGraphErrors(theo_mass.size(), &(theo_mass[0]), &HVT_A_xsec[0]);
  TGraph* gr_HVT_B   = new TGraphErrors(theo_mass.size(), &(theo_mass[0]), &HVT_B_xsec[0]);
  TGraph* gr_Hbb     = new TGraphErrors(MassPoints_Hbb.size(), &(MassPoints_Hbb[0]), &expectedHbb[0]);
  TGraph* gr_Hbb0b   = new TGraphErrors(MassPoints_Hbb.size(), &(MassPoints_Hbb[0]), &expectedHbb0b[0]);
  TGraph* gr_ZeeH0b  = new TGraphErrors(ee_mass.size(), &(ee_mass[0]), &ee_xsec[0]);
  // TGraph* gr_H0lll2b = new TGraphErrors(MassPoints_Hbb.size(), &(MassPoints_Hbb[0]), &expectedH0lll2b[0]);
  // TGraph* gr_H0lll0b = new TGraphErrors(MassPoints_Hbb.size(), &(MassPoints_Hbb[0]), &expectedH0lll0b[0]);
  // TGraph* gr_Hcomb   = new TGraphErrors(MassPoints_Hbb.size(), &(MassPoints_Hbb[0]), &expectedHcomb[0]);

  gr_theo->SetLineWidth(2);
  gr_HVT_A->SetLineWidth(2);
  gr_HVT_B->SetLineWidth(2);
  gr_Hbb->SetLineWidth(2);
  gr_Hbb0b->SetLineWidth(2);
  gr_ZeeH0b->SetLineWidth(2);
  // gr_H0lll2b->SetLineWidth(2);
  // gr_H0lll0b->SetLineWidth(2);
  // gr_Hcomb->SetLineWidth(2);

  // std::string mode = "CB";
  std::string mode = "Exp_2";
  std::string Path_ANALYSIS = std::getenv("CMSSW_BASE"); Path_ANALYSIS += "/src/UHH2/VHResonances/Analysis/";
  std::string studies = "nominal";
  // std::string studies = "noSignalFlatUncertainty";

  std::string Method = "AsymptoticLimits";
  // std::string extraOptionsText = "Asimov";
  // std::string extraOptionsText = "AsimovNoSys";
  std::string extraOptionsText = "Expected";
  // std::string extraOptionsText = "ExpectedNoSys";
  std::string AnalysisDir = Path_ANALYSIS+"Limits/"+studies+"/";
  if (isHbb)  AnalysisDir = Path_ANALYSIS+"Limits/"+studies+"/Hbb/";
  // std::vector<std::string> collections = {"Puppi", kRed+1},
  std::vector<std::string> collections = {"Puppi"};
  // std::vector<std::string> channels = {"muonchannel", "electronchannel"};
  std::vector<std::string> channels = {"muonchannel", "electronchannel", "leptonchannel"};
  // std::vector<std::string> years = {"2016", "2017", "2018", "RunII", "fullRunII"};
  std::vector<std::string> years = {"RunII"};
  // std::vector<std::string> years = {"2016"};
  // std::vector<std::string> channels = {"muonchannel"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "NN", "tau21","tau31", "tau41", "tau32", "tau42", "tau43"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDp2", "btag_DeepBoosted_H4qvsQCDp02", "btag_DeepBoosted_H4qvsQCDpt1000", "btag_DeepBoosted_H4qvsQCDpt1000p2", "btag_DeepBoosted_H4qvsQCDpt1000p02"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDptdep", "btag_DeepBoosted_H4qvsQCDp02",
  // "btag_DeepBoosted_H4qvsQCDptdep_x3", "btag_DeepBoosted_H4qvsQCDptdep_x2x3", "btag_DeepBoosted_H4qvsQCDptdep_x1x3", "btag_DeepBoosted_H4qvsQCDmassdep_x3",
  // "btag_DeepBoosted_H4qvsQCDmassdep2_x3", "btag_DeepBoosted_H4qvsQCDmassdep_x2x3", "btag_DeepBoosted_H4qvsQCDmassdep_x1x3", "btag_DeepBoosted_H4qvsQCDmassdep_x1x2" };
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDmassdep_x3","btag_DeepBoosted_H4qvsQCDptdep",
  // "btag_DeepBoosted_H4qvsQCDptdep_x3", "btag_DeepBoosted_H4qvsQCDptdep_x2x3", "btag_DeepBoosted_H4qvsQCDptdep_x1x3", "btag_DeepBoosted_H4qvsQCDmassdep_x3",
  // "btag_DeepBoosted_H4qvsQCDmassdep2_x3", "btag_DeepBoosted_H4qvsQCDmassdep_x2x3", "btag_DeepBoosted_H4qvsQCDmassdep_x1x3", "btag_DeepBoosted_H4qvsQCDmassdep_x1x2" };
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDmassdep_x3"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDmassdep", "btag_DeepBoosted_H4qvsQCDmassdep_2", "btag_DeepBoosted_H4qvsQCDmassdep_3", "btag_DeepBoosted_H4qvsQCDmassdep_bb", "btag_DeepBoosted_H4qvsQCDmassdep_cc", "btag_DeepBoosted_H4qvsQCDmassdep_gg", "btag_DeepBoosted_H4qvsQCDmassdep_cc_2", "btag_DeepBoosted_H4qvsQCDmassdep_gg_2", "btag_DeepBoosted_H4qvsQCDmassdep_cc_3", "btag_DeepBoosted_H4qvsQCDmassdep_gg_3", "tau42"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDmassdep", "btag_DeepBoosted_H4qvsQCDmassdep_2", "btag_DeepBoosted_H4qvsQCDmassdep_3", "btag_DeepBoosted_H4qvsQCDmassdep_cc", "btag_DeepBoosted_H4qvsQCDmassdep_cc_2", "btag_DeepBoosted_H4qvsQCDmassdep_gg_2", "btag_DeepBoosted_H4qvsQCDmassdep_cc_3", "tau42"};
  std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDmassdep", "btag_DeepBoosted_H4qvsQCDmassdep_cc", "tau42"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDmassdep", "btag_DeepBoosted_H4qvsQCDmassdep_2", "btag_DeepBoosted_H4qvsQCDmassdep_3"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDmassdep_cc"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDmassdep_x3_3","btag_DeepBoosted_H4qvsQCDmassdep_x3"};
  // std::vector<std::string> histFolders = {"btag_DeepBoosted_H4qvsQCDmassdep_old_x3", "btag_DeepBoosted_H4qvsQCD", "btag_DeepBoosted_H4qvsQCDp2", "btag_DeepBoosted_H4qvsQCDp02", "btag_DeepBoosted_H4qvsQCDptdep_old_x3", "btag_DeepBoosted_H4qvsQCDmassdep_x3", "btag_DeepBoosted_H4qvsQCDmassdep_x2x3", "btag_DeepBoosted_H4qvsQCDmassdep_x1x3"};
  // // if (isHbb) histFolders = {"btag_DeepBoosted_HbbvsQCD", "btag_DeepBoosted_probHbb", "tau42", "tau32", "tau21" };

  std::unordered_map<std::string, std::unordered_map<std::string, std::vector<double>>> Limits;

  for (std::string year: years) {
    for (std::string collection: collections) {
      for (std::string channel: channels) {
        double BR = 0.1;
        for (std::string histFolder : histFolders) {
          std::string workingDir = year+"/"+collection+"/"+channel+"/"+histFolder+"/";

          double pbTofb = 1000.;
          // double xsec_ref_ = 0.1; // 0.1 comes from normalising the signal strenght
          double xsec_ref_ = (xsec_ref.find(histFolder) != xsec_ref.end())? xsec_ref.at(histFolder): xsec_ref.at("default_value"); // default_value = 1
          // std::cout << BR << std::endl;
          double norm = xsec_ref_*pbTofb/BR;

          Limits[workingDir]["obs"] = std::vector<double>(nPoints,  norm);
          Limits[workingDir]["xsec"] = std::vector<double>(nPoints, norm);
          Limits[workingDir]["xsecNeg1"] = std::vector<double>(nPoints, norm);
          Limits[workingDir]["xsecNeg2"] = std::vector<double>(nPoints, norm);
          Limits[workingDir]["xsecPos1"] = std::vector<double>(nPoints, norm);
          Limits[workingDir]["xsecPos2"] = std::vector<double>(nPoints, norm);
          Limits[workingDir]["expNeg1"] = std::vector<double>(nPoints, 0);
          Limits[workingDir]["expNeg2"] = std::vector<double>(nPoints, 0);
          Limits[workingDir]["expPos1"] = std::vector<double>(nPoints, 0);
          Limits[workingDir]["expPos2"] = std::vector<double>(nPoints, 0);

          // Extract values for limits from txt file TODO Implement from root file
          for (unsigned int i=0; i<MassPoints.size(); ++i) {
            std::string filename = AnalysisDir+workingDir+"/datacards/out/DataCard_"+year+"_"+collection+"_"+channel+"_"+histFolder+"_M"+std::to_string((int)MassPoints[i])+"_"+mode+"_"+extraOptionsText+"_"+Method+".out";
            std::ifstream txtfile(filename.c_str(), std::ios::in);

            std::string line;
            bool found= false;
            int count = 0;

            while (count<1000 && !found && !txtfile.eof() && !gSystem->AccessPathName(filename.c_str())) {
              getline(txtfile, line);
              if (line.find("-- AsymptoticLimits ( CLs ) --")!=std::string::npos) found=true;
              count++;
            }

            if (count<1000) { // TODO
              getline(txtfile, line);
              if (line.find("Observed")!=std::string::npos) {
                Limits[workingDir]["obs"][i]    = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);
              }
              Limits[workingDir]["xsecNeg2"][i] = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);
              Limits[workingDir]["xsecNeg1"][i] = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);
              Limits[workingDir]["xsec"][i]     = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);
              Limits[workingDir]["xsecPos1"][i] = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);
              Limits[workingDir]["xsecPos2"][i] = atof(line.substr(line.find("<")+1).c_str())*norm; getline(txtfile, line);


              Limits[workingDir]["expNeg2"][i]=Limits[workingDir]["xsec"][i]-Limits[workingDir]["xsecNeg2"][i];
              Limits[workingDir]["expNeg1"][i]=Limits[workingDir]["xsec"][i]-Limits[workingDir]["xsecNeg1"][i];
              Limits[workingDir]["expPos1"][i]=Limits[workingDir]["xsecPos1"][i]-Limits[workingDir]["xsec"][i];
              Limits[workingDir]["expPos2"][i]=Limits[workingDir]["xsecPos2"][i]-Limits[workingDir]["xsec"][i];

            }

            txtfile.close();
          }
        }
      }
    }
  }

  TString nameXaxix = "m(Z') [GeV]";
  // TString nameYaxix = "#sigma\(pp#rightarrowX\) #times Br\(Z'#rightarrowZ\(ll\) H\(WW\)\) \(fb\)";
  TString nameYaxix = "#sigma#left(pp#rightarrowX#right) #times Br#left(Z'#rightarrow ZH #right)#left(fb#right)";

  writeExtraText = true;       // if extra text
  extraText  = "Work in progress" ;//"Preliminary";
  lumi_13TeV  = TString::Format("%.1f fb^{-1}", lumi_map.at("RunII").at("lumi_fb"));

  std::unordered_map<std::string, TCanvas*> Canvas_Limits_Comparison;
  std::unordered_map<std::string, TLegend*> Legend_Limits_Comparison;

  Canvas_Limits_Comparison["all"] = tdrCanvas("c_limits_comparison_all", plot_lo, plot_hi, yaxis_lo, yaxis_hi, nameXaxix, nameYaxix);
  Legend_Limits_Comparison["all"] = tdrLeg(0.65,0.5,0.9,0.85, 0.025, 42, kBlack);

  for (auto [name,canvas]: Canvas_Limits_Comparison ) {
    canvas->SetLogy(1);
    canvas->SetGridx(1);
    canvas->SetGridy(1);
    Legend_Limits_Comparison[name]->SetFillColor(kWhite);
    Legend_Limits_Comparison[name]->SetFillStyle(1);
    Legend_Limits_Comparison[name]->SetFillStyle(0);
    tdrDraw(gr_theo,    "C", kFullDotLarge, kRed+1,    kSolid,  kRed+1);
    tdrDraw(gr_HVT_A,   "C", kFullDotLarge, kViolet-1,   kSolid,  kViolet-1);
    tdrDraw(gr_HVT_B,   "C", kFullDotLarge, kViolet-9,kSolid,  kViolet-9);
    tdrDraw(gr_Hbb,     "C", kFullDotLarge, kBlue+1,   kDotted, kBlue+1);
    tdrDraw(gr_Hbb0b,   "C", kFullDotLarge, kBlue+1,   kDashed, kBlue+1);
    tdrDraw(gr_ZeeH0b,  "C", kFullDotLarge, kBlue+1,   kDashDotted, kBlue+1);
    // tdrDraw(gr_H0lll2b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
    // tdrDraw(gr_H0lll0b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
    // tdrDraw(gr_Hcomb,   "C", kFullDotLarge, kGreen+1,  kSolid, kGreen+1);

    TLegend *leg_ExtraPlot = tdrLeg(0.45,0.7,0.60,0.85, 0.03, 42, kBlack);
    canvas->cd();
    leg_ExtraPlot->AddEntry(gr_theo,    "Prediction", "l");
    leg_ExtraPlot->AddEntry(gr_HVT_A,   "HVT model A", "l");
    leg_ExtraPlot->AddEntry(gr_HVT_B,   "HVT model B", "l");
    leg_ExtraPlot->AddEntry(gr_Hbb,     "Hbb", "l");
    leg_ExtraPlot->AddEntry(gr_Hbb0b,   "Hbb cat 0b", "l");
    leg_ExtraPlot->AddEntry(gr_ZeeH0b,  "Zee cat 0b", "l");
    // leg_ExtraPlot->AddEntry(gr_H0lll2b, "Hbb 0l2l2b", "l");
    // leg_ExtraPlot->AddEntry(gr_H0lll0b, "Hbb 0l2l0b", "l");
    // leg_ExtraPlot->AddEntry(gr_Hcomb,   "Hbb comb", "l");

    leg_ExtraPlot->Draw();
  }

  for (std::string year: years) {
    for (std::string collection: collections) {
      for (std::string channel: channels) {
        writeExtraText = true;       // if extra text
        extraText  = "Work in progress" ;//"Preliminary";
        lumi_13TeV  = TString::Format("%.1f fb^{-1}", lumi_map.at((year=="fullRunII")?"RunII":year).at("lumi_fb"));

        // TCanvas* c_xsec_modecomparison = tdrCanvas("c_xsec_modecomparison", plot_lo, plot_hi, yaxis_lo, yaxis_hi, nameXaxix, nameYaxix);
        // TCanvas* c_xsec_modecomparison = tdrCanvas("c_xsec_modecomparison", plot_lo, plot_hi, 0.01, 10.3, nameXaxix, nameYaxix);
        TCanvas* c_xsec_modecomparison = tdrCanvas("c_xsec_modecomparison", 1000, plot_hi, 0.1, 500, nameXaxix, nameYaxix);
        c_xsec_modecomparison->SetLogy(1);
        c_xsec_modecomparison->SetGridx(1);
        c_xsec_modecomparison->SetGridy(1);

        TLegend *leg_modecomparison = tdrLeg(0.45,0.65,0.9,0.85, 0.02, 42, kBlack);
        leg_modecomparison->SetFillStyle(1); leg_modecomparison->SetFillColor(kWhite);
        leg_modecomparison->SetFillStyle(0);

        tdrDraw(gr_theo,    "C", kFullDotLarge, kRed+1,    kSolid,  kRed+1);
        tdrDraw(gr_HVT_A,   "C", kFullDotLarge, kViolet-1,   kSolid,  kViolet-1);
        tdrDraw(gr_HVT_B,   "C", kFullDotLarge, kViolet-9,kSolid,  kViolet-9);
        tdrDraw(gr_Hbb,     "C", kFullDotLarge, kBlue+1,   kDotted, kBlue+1);
        tdrDraw(gr_Hbb0b,   "C", kFullDotLarge, kBlue+1,   kDashed, kBlue+1);
        tdrDraw(gr_ZeeH0b,  "C", kFullDotLarge, kBlue+1,   kDashDotted, kBlue+1);
        // tdrDraw(gr_H0lll2b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
        // tdrDraw(gr_H0lll0b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
        // tdrDraw(gr_Hcomb,   "C", kFullDotLarge, kGreen+1,  kSolid, kGreen+1);

        std::string dir_modecomparison = AnalysisDir+"/"+year+"/"+collection+"/"+channel+"/";

        TGraphAsymmErrors *g_xsec_mode_ref;

        for (std::string histFolder : histFolders) {
          std::string workingDir = year+"/"+collection+"/"+channel+"/"+histFolder+"/";

          TCanvas* c_xsec = tdrCanvas(("xsec"+workingDir).c_str(), plot_lo, plot_hi, yaxis_lo, yaxis_hi, nameXaxix, nameYaxix);
          c_xsec->SetLogy(1);
          c_xsec->SetGridx(1);
          c_xsec->SetGridy(1);
          c_xsec->cd();

          TGraph *g_obs = new TGraph(nPoints, &(MassPoints[0]), &(Limits[workingDir]["obs"][0]));
          std::vector<double> dummy(nPoints,0);
          TGraphAsymmErrors *g_xsec_1sigma = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]), &(dummy[0]), &(dummy[0]), &(Limits[workingDir]["expNeg1"][0]), &(Limits[workingDir]["expPos1"][0]));
          TGraphAsymmErrors *g_xsec_2sigma = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]), &(dummy[0]), &(dummy[0]), &(Limits[workingDir]["expNeg2"][0]), &(Limits[workingDir]["expPos2"][0]));
          TGraphAsymmErrors *g_xsec = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          TGraphAsymmErrors *g_xsec_mode = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));;
          g_xsec->SetLineWidth(2);
          g_xsec_mode->SetLineWidth(2);

          tdrDraw(g_xsec_2sigma,  "3",  20, kOrange, kSolid, kOrange, 1000, kOrange);
          tdrDraw(g_xsec_1sigma,  "3",  20, kGreen+1, kSolid, kGreen+1, 1000, kGreen+1);
          tdrDraw(g_xsec,  "L",  20, kBlack, 2, kBlack, 1000, kBlack);
          if (doObs) tdrDraw(g_obs,  "LP", kFullDotLarge, kBlack, kSolid, kBlack);
          tdrDraw(gr_theo,    "C", kFullDotLarge, kRed+1,    kSolid,  kRed+1);
          tdrDraw(gr_HVT_A,   "C", kFullDotLarge, kViolet-1,   kSolid,  kViolet-1);
          tdrDraw(gr_HVT_B,   "C", kFullDotLarge, kViolet-9,kSolid,  kViolet-9);
          tdrDraw(gr_Hbb,     "C", kFullDotLarge, kBlue+1,   kDotted, kBlue+1);
          tdrDraw(gr_Hbb0b,   "C", kFullDotLarge, kBlue+1,   kDashed, kBlue+1);
          tdrDraw(gr_ZeeH0b,  "C", kFullDotLarge, kBlue+1,   kDashDotted, kBlue+1);
          // tdrDraw(gr_H0lll2b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
          // tdrDraw(gr_H0lll0b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
          // tdrDraw(gr_Hcomb,   "C", kFullDotLarge, kGreen+1,  kSolid, kGreen+1);

          // g_obs->SetLineWidth(2);
          // g_obs->SetMarkerStyle(20);
          //g_obs->Draw("LP SAME");

          // TLegend *leg = tdrLeg(0.65,0.45,0.9,0.7, 0.03, 42, kBlack);
          TLegend *leg = tdrLeg(0.65,0.7,0.9,0.85, 0.03, 42, kBlack);
          leg->SetFillStyle(1); leg->SetFillColor(kWhite);
          leg->SetFillStyle(0);
          tdrHeader(leg,"95\% CL Upper Limit", 12);
          if (doObs) leg->AddEntry(g_obs, "Observed", "LP");
          leg->AddEntry(g_xsec, "Expected", "L");
          leg->AddEntry(g_xsec_1sigma, "68\% Expected", "CF");
          leg->AddEntry(g_xsec_2sigma, "95\% Expected", "CF");
          leg->Draw();

          // TLegend *leg_ExtraPlot = tdrLeg(0.65,0.7,0.9,0.9, 0.03, 42, kBlack);
          TLegend *leg_ExtraPlot = tdrLeg(0.45,0.7,0.60,0.85, 0.03, 42, kBlack);
          leg_ExtraPlot->AddEntry(gr_theo,    "Prediction", "l");
          leg_ExtraPlot->AddEntry(gr_HVT_A,   "HVT model A", "l");
          leg_ExtraPlot->AddEntry(gr_HVT_B,   "HVT model B", "l");
          leg_ExtraPlot->AddEntry(gr_Hbb,     "Hbb", "l");
          leg_ExtraPlot->AddEntry(gr_Hbb0b,   "Hbb cat 0b", "l");
          leg_ExtraPlot->AddEntry(gr_ZeeH0b,  "Zee cat 0b", "l");
          // leg_ExtraPlot->AddEntry(gr_H0lll2b, "Hbb 0l2l2b", "l");
          // leg_ExtraPlot->AddEntry(gr_H0lll0b, "Hbb 0l2l0b", "l");
          // leg_ExtraPlot->AddEntry(gr_Hcomb,   "Hbb comb", "l");
          leg_ExtraPlot->Draw();

          c_xsec->SaveAs((dir_modecomparison+histFolder+"/"+"UpperLimit_"+histFolder+"_"+extraOptionsText+".pdf").c_str());

          // TFile *file=new TFile(Form("UpperLimits_xsec_%s.root", background.c_str()), "RECREATE");
          // g_obs->Write("g_obs");
          // g_xsec->Write("g_xsec");
          // g_xsec_1sigma->Write("g_xsec_1sigma");
          // g_xsec_2sigma->Write("g_xsec_2sigma");
          // file->Close();
          c_xsec_modecomparison->cd();
          // if (histFolder=="btag_DeepBoosted_H4qvsQCDptdep") g_xsec_mode_ref = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          // if (histFolder=="btag_DeepBoosted_H4qvsQCDmassdep_x3") g_xsec_mode_ref = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          // if (histFolder=="btag_DeepBoosted_H4qvsQCDmassdep_x3") g_xsec_mode_ref = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          if (histFolder==histFolders[0]) g_xsec_mode_ref = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          // if (histFolder=="btag_DeepBoosted_H4qvsQCDptdep") continue;
          TGraphAsymmErrors* g_xsec_mode_scale  = new TGraphAsymmErrors(nPoints, &(MassPoints[0]), &(Limits[workingDir]["xsec"][0]));
          for (size_t i = 0; i < nPoints; i++) {
            double x_num, y_num, x_den, y_den;
            g_xsec_mode_scale->GetPoint(i,x_num, y_num);
            g_xsec_mode_ref->GetPoint(i,x_den, y_den);
            // g_xsec_mode_scale->SetPoint(i,x_num, y_num/y_den);
            g_xsec_mode_scale->SetPoint(i,x_num, y_num);
            g_xsec_mode_scale->GetPoint(i,x_num, y_num);
          }
          g_xsec_mode_scale->SetLineWidth(2);
          tdrDraw(g_xsec_mode_scale,  "L",  20, colors[histFolder], 2, colors[histFolder], 1000, colors[histFolder]);
          leg_modecomparison->AddEntry(g_xsec_mode_scale, histFolder.c_str(), "L");
          // tdrDraw(g_xsec_mode,  "L",  20, colors[histFolder], 2, colors[histFolder], 1000, colors[histFolder]);
          // leg_modecomparison->AddEntry(g_xsec_mode, histFolder.c_str(), "L");

          // if (histFolder=="btag_DeepBoosted_H4qvsQCDmassdep_x3") {
          if (histFolder==histFolders[0]) {
            Canvas_Limits_Comparison["all"]->cd();
            tdrDraw(g_xsec,  "L",  20, colors[year], (channel=="muonchannel")? kSolid: ((channel=="electronchannel")? kDotted: kDashed), colors[year], 1000, colors[year]);
            // Legend_Limits_Comparison["all"]->AddEntry(g_xsec, TString(workingDir).ReplaceAll("Puppi","").ReplaceAll("btag_DeepBoosted_H4qvsQCDmassdep_x3","").ReplaceAll("channel","").ReplaceAll("/"," "), "L");
            Legend_Limits_Comparison["all"]->AddEntry(g_xsec, TString(workingDir).ReplaceAll("Puppi","").ReplaceAll(histFolders[0],"").ReplaceAll("channel","").ReplaceAll("/"," "), "L");
          }
        }
        c_xsec_modecomparison->cd();
        // tdrDraw(gr_theo,  "C", kFullDotLarge, kRed+1, kSolid, kRed+1);
        // tdrDraw(gr_Hbb,  "C", kFullDotLarge, kBlue+1, kDotted, kBlue+1);
        // tdrDraw(gr_Hbb0b,  "C", kFullDotLarge, kBlue+1, kDashed, kBlue+1);
        // leg_modecomparison->AddEntry(gr_theo, "Prediction", "l");
        // leg_modecomparison->AddEntry(gr_Hbb, "Hbb", "l");
        // leg_modecomparison->AddEntry(gr_Hbb0b, "Hbb cat 0b", "l");
        // leg_modecomparison->Draw("");
        c_xsec_modecomparison->SaveAs((dir_modecomparison+"UpperLimit_modecomparison_"+extraOptionsText+".pdf").c_str());
      }
    }
  }
  Canvas_Limits_Comparison["all"]->cd();
  tdrDraw(gr_theo,    "C", kFullDotLarge, kRed+1,    kSolid,  kRed+1);
  tdrDraw(gr_HVT_A,   "C", kFullDotLarge, kViolet-1,   kSolid,  kViolet-1);
  tdrDraw(gr_HVT_B,   "C", kFullDotLarge, kViolet-9,kSolid,  kViolet-9);
  tdrDraw(gr_Hbb,     "C", kFullDotLarge, kBlue+1,   kDotted, kBlue+1);
  tdrDraw(gr_Hbb0b,   "C", kFullDotLarge, kBlue+1,   kDashed, kBlue+1);
  tdrDraw(gr_ZeeH0b,  "C", kFullDotLarge, kBlue+1,   kDashDotted, kBlue+1);
  // tdrDraw(gr_H0lll2b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
  // tdrDraw(gr_H0lll0b, "C", kFullDotLarge, kOrange+1, kSolid, kOrange+1);
  // tdrDraw(gr_Hcomb,   "C", kFullDotLarge, kGreen+1,  kSolid, kGreen+1);

  Legend_Limits_Comparison["all"]->AddEntry(gr_theo,    "Prediction", "l");
  Legend_Limits_Comparison["all"]->AddEntry(gr_HVT_A,   "HVT model A", "l");
  Legend_Limits_Comparison["all"]->AddEntry(gr_HVT_B,   "HVT model B", "l");
  Legend_Limits_Comparison["all"]->AddEntry(gr_Hbb,     "Hbb", "l");
  Legend_Limits_Comparison["all"]->AddEntry(gr_Hbb0b,   "Hbb cat 0b", "l");
  Legend_Limits_Comparison["all"]->AddEntry(gr_ZeeH0b,  "Zee cat 0b", "l");
  // Legend_Limits_Comparison["all"]->AddEntry(gr_H0lll2b, "Hbb 0l2l2b", "l");
  // Legend_Limits_Comparison["all"]->AddEntry(gr_H0lll0b, "Hbb 0l2l0b", "l");
  // Legend_Limits_Comparison["all"]->AddEntry(gr_Hcomb,   "Hbb comb", "l");
  Legend_Limits_Comparison["all"]->Draw("");
  Canvas_Limits_Comparison["all"]->SaveAs((AnalysisDir+"UpperLimit_comparison_"+extraOptionsText+".pdf").c_str());

  std::unordered_map<std::string, TCanvas*> Canvas_Limits_Ratio;
  std::unordered_map<std::string, TLegend*> Legend_Limits_Ratio;

  std::string collection = "Puppi";
  std::string channel = "muonchannel";
  std::string histFolder = histFolders[0];
  // std::string histFolder = "btag_DeepBoosted_H4qvsQCDmassdep_x3";
  // std::string histFolder = "btag_DeepBoosted_H4qvsQCDp2";
  // std::string histFolder = "btag_DeepBoosted_H4qvsQCDp02";
  std::string workingDir = collection+"/"+channel+"/"+histFolder+"/";
  Canvas_Limits_Ratio[workingDir] = tdrCanvas("c_limits_ratio", plot_lo, plot_hi, yaxis_lo, 5, nameXaxix, "Ratio Limits");
  Legend_Limits_Ratio[workingDir] = tdrLeg(0.65,0.5,0.9,0.85, 0.025, 42, kBlack);

  for (std::string year: years) {
    std::vector<double> ratio(nPoints,0);
    for (size_t i = 0; i < nPoints; i++) ratio[i] = Limits[year+"/"+workingDir]["xsec"][i]/Limits["RunII/"+workingDir]["xsec"][i];

    TGraph *g_ratio = new TGraph(nPoints, &(MassPoints[0]), &(ratio[0]));
    tdrDraw(g_ratio,  "L",  20, colors[year], (channel=="muonchannel")? kSolid: ((channel=="electronchannel")? kDotted: kDashed), colors[year], 1000, colors[year]);
    Legend_Limits_Ratio[workingDir]->AddEntry(g_ratio, year.c_str(), "L");
    double lumiFact = lumi_map.at("RunII").at("lumi_fb")/lumi_map.at((year=="fullRunII")?"RunII":year).at("lumi_fb");
    lumiFact = TMath::Sqrt(lumiFact);
    TLine *line=new TLine(plot_lo, lumiFact, plot_hi, lumiFact); line->SetLineStyle(kDashed); line->SetLineWidth(2); line->SetLineColor(colors[year]); line->Draw("same");
  }
  Legend_Limits_Ratio[workingDir]->Draw("");
  Canvas_Limits_Ratio[workingDir]->SaveAs((AnalysisDir+"UpperLimit_comparison_"+(TString(workingDir).ReplaceAll("/","_"))+"_"+extraOptionsText+".pdf"));


}


int main(){
  PlotLimits();
  return 0;
}
