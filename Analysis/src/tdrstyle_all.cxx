#include "tdrstyle_all.hpp"

using namespace std;

//////////////////////////////////////////
// New CMS Style from 2014              //
// https://ghm.web.cern.ch/ghm/plots/   //
// Merged all macros into one           //
//////////////////////////////////////////

float cmsTextFont   = 61;  // default is helvetic-bold
TString cmsText     = "CMS";
bool writeExtraText = true;//false;
TString extraText   = "Preliminary";
TString extraText2   = ""; // For Simulation Preliminary on two lines
float extraTextFont = 52;  // default is helvetica-italics
float lumiTextSize     = 0.6;
float lumiTextOffset   = 0.2;
float cmsTextSize      = 0.75;
float cmsTextOffset    = 0.1;  // only used in outOfFrame version
float relPosX    = 0.045;
float relPosY    = 0.035;
float relExtraDY = 1.2;
float extraOverCmsTextSize  = 0.76;

TString lumi_13TeV = "41.53 fb^{-1}";
TString lumi_8TeV  = "19.7 fb^{-1}";
TString lumi_7TeV  = "5.1 fb^{-1}";
TString lumi_sqrtS = "";
bool drawLogo      = false;
bool kSquare = true;
bool kRectangular = false;


void CMSOff() { cmsText = ""; }
void ExtraTextOff() { writeExtraText = false;}
void SetYear(TString year) {lumi_13TeV  = year;}

void ForThesis(){
  CMSOff();
  ExtraTextOff();
}

void SetSimulation() {
  writeExtraText = true;
  extraText2 = extraText;
  extraText  = "Simulation";
}

void WIP(bool isSimulation){
  writeExtraText = true;
  extraText = "Work in progress";
  if (isSimulation) SetSimulation();
}


// tdrGrid: Turns the grid lines on (true) or off (false)
void tdrGrid(bool gridOn) {
  TStyle *tdrStyle = (TStyle*)gROOT->FindObject("tdrStyle"); assert(tdrStyle);
  tdrStyle->SetPadGridX(gridOn);
  tdrStyle->SetPadGridY(gridOn);
}

// fixOverlay: Redraws the axis
void fixOverlay() {
  gPad->RedrawAxis();
}

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
  // tdrStyle->SetErrorMarker(20);
  //tdrStyle->SetErrorX(0.);

  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

  // For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->SetHatchesLineWidth(5);
  tdrStyle->SetHatchesSpacing(0.05);

  tdrStyle->cd();

}

////////////////
// CMS_lumi.C //
////////////////

void
CMS_lumi( TPad* pad, int iPeriod, int iPosX ){
  bool outOfFrame    = false;
  if( iPosX/10==0 )outOfFrame = true;
  int alignY_=3;
  int alignX_=2;
  if( iPosX/10==0 ) alignX_=1;
  if( iPosX==0    ) alignX_=1;
  if( iPosX==0    ) alignY_=1;
  if( iPosX/10==1 ) alignX_=1;
  if( iPosX/10==2 ) alignX_=2;
  if( iPosX/10==3 ) alignX_=3;
  //if( iPosX == 0  ) relPosX = 0.12;
  if( iPosX == 0  ) relPosX = pad->GetLeftMargin();
  int align_ = 10*alignX_ + alignY_;

  float H = pad->GetWh();
  float W = pad->GetWw();
  float l = pad->GetLeftMargin();
  float t = pad->GetTopMargin();
  float r = pad->GetRightMargin();
  float b = pad->GetBottomMargin();
  //  float e = 0.025;

  pad->cd();

  TString lumiText;
  if( iPeriod==1 ){
    lumiText += lumi_7TeV;
    lumiText += " (7 TeV)";
  } else if ( iPeriod==2 ){
    lumiText += lumi_8TeV;
    lumiText += " (8 TeV)";
  } else if( iPeriod==3 ){
    lumiText = lumi_8TeV;
    lumiText += " (8 TeV)";
    lumiText += " + ";
    lumiText += lumi_7TeV;
    lumiText += " (7 TeV)";
  } else if ( iPeriod==4 ){
    lumiText += lumi_13TeV;
    lumiText += " (13 TeV)";
  } else if ( iPeriod==7 ){
    if( outOfFrame ) lumiText += "#scale[0.85]{";
    lumiText += lumi_13TeV;
    lumiText += " (13 TeV)";
    lumiText += " + ";
    lumiText += lumi_8TeV;
    lumiText += " (8 TeV)";
    lumiText += " + ";
    lumiText += lumi_7TeV;
    lumiText += " (7 TeV)";
    if( outOfFrame) lumiText += "}";
  } else if ( iPeriod==12 ){
    lumiText += "8 TeV";
  } else if ( iPeriod==0 ){
    lumiText += lumi_sqrtS;
  }

  // cout << lumiText << endl;

  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);

  float extraTextSize = extraOverCmsTextSize*cmsTextSize;

  latex.SetTextFont(42);
  latex.SetTextAlign(31);
  latex.SetTextSize(lumiTextSize*t);
  latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);

  if( outOfFrame ){
    latex.SetTextFont(cmsTextFont);
    latex.SetTextAlign(11);
    latex.SetTextSize(cmsTextSize*t);
    latex.DrawLatex(l,1-t+lumiTextOffset*t,cmsText);
  }

  pad->cd();

  float posX_=0;
  if( iPosX%10<=1 ){
    posX_ =   l + relPosX*(1-l-r);
  } else if( iPosX%10==2 ) {
    posX_ =  l + 0.5*(1-l-r);
  } else if( iPosX%10==3 ){
    posX_ =  1-r - relPosX*(1-l-r);
  }
  float posY_ = 1-t - relPosY*(1-t-b);
  if( !outOfFrame ){
    if( drawLogo ){
      posX_ =   l + 0.045*(1-l-r)*W/H;
      posY_ = 1-t - 0.045*(1-t-b);
      float xl_0 = posX_;
      float yl_0 = posY_ - 0.15;
      float xl_1 = posX_ + 0.15*H/W;
      float yl_1 = posY_;
      TASImage* CMS_logo = new TASImage("CMS-BW-label.png");
      TPad* pad_logo = new TPad("logo","logo", xl_0, yl_0, xl_1, yl_1 );
      pad_logo->Draw();
      pad_logo->cd();
      CMS_logo->Draw("X");
      pad_logo->Modified();
      pad->cd();
    } else{
      latex.SetTextFont(cmsTextFont);
      latex.SetTextSize(cmsTextSize*t);
      latex.SetTextAlign(align_);
      latex.DrawLatex(posX_, posY_, cmsText);
      if( writeExtraText ){
        latex.SetTextFont(extraTextFont);
        latex.SetTextAlign(align_);
        latex.SetTextSize(extraTextSize*t);
        latex.DrawLatex(posX_, posY_- relExtraDY*cmsTextSize*t, extraText);
        if (extraText2!="") // For Simulation Preliminary
        latex.DrawLatex(posX_, posY_-relExtraDY*cmsTextSize*t - relExtraDY*extraTextSize*t, extraText2);
      }
    }
  } else if( writeExtraText ){
    if( iPosX==0){
      posX_ =   l +  relPosX*(1-l-r);
      posY_ =   1-t+lumiTextOffset*t;
    }
    latex.SetTextFont(extraTextFont);
    latex.SetTextSize(extraTextSize*t);
    latex.SetTextAlign(align_);
    latex.DrawLatex(posX_, posY_, extraText);
  }
  return;
}


// Give the macro an empty histogram for h->Draw("AXIS");
// Create h after calling setTDRStyle to get all the settings right
TCanvas* tdrCanvas(const char* canvName, double x_min, double x_max, double y_min, double y_max, const char* nameXaxis, const char* nameYaxis, bool square, int iPeriod, int iPos) {

  setTDRStyle();

  //writeExtraText = true;       // if extra text
  //extraText  = "Preliminary";  // default extra text is "Preliminary"
  //lumi_8TeV  = "19.5 fb^{-1}"; // default is "19.7 fb^{-1}"
  //lumi_7TeV  = "5.0 fb^{-1}";  // default is "5.1 fb^{-1}"

  //int iPeriod = 3;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV

  // second parameter in example_plot is iPos, which drives the position of the CMS logo in the plot
  // iPos=11 : top-left, left-aligned
  // iPos=33 : top-right, right-aligned
  // iPos=22 : center, centered
  // iPos=0  : out of frame (in exceptional cases)
  // mode generally :
  //   iPos = 10*(alignement 1/2/3) + position (1/2/3 = left/center/right)


  //  if( iPos==0 ) relPosX = 0.12;

  int W = (square ? 600 : 800);
  int H = (square ? 600 : 600);

  //
  // Simple example of macro: plot with CMS name and lumi text
  //  (this script does not pretend to work in all configurations)
  // iPeriod = 1*(0/1 7 TeV) + 2*(0/1 8 TeV)  + 4*(0/1 13 TeV)
  // For instance:
  //               iPeriod = 3 means: 7 TeV + 8 TeV
  //               iPeriod = 7 means: 7 TeV + 8 TeV + 13 TeV
  // Initiated by: Gautier Hamel de Monchenault (Saclay)
  //
  int W_ref = (square ? 600 : 800);
  int H_ref = (square ? 600 : 600);

  // references for T, B, L, R
  float T = (square ? 0.07*H_ref : 0.08*H_ref);
  float B = (square ? 0.13*H_ref : 0.12*H_ref);
  float L = (square ? 0.15*W_ref : 0.12*W_ref);
  float R = (square ? 0.05*W_ref : 0.04*W_ref);

  TCanvas *canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetLeftMargin( L/W );
  canv->SetRightMargin( R/W );
  canv->SetTopMargin( T/H );
  canv->SetBottomMargin( B/H );
  // FOR JEC plots, prefer to keep ticks on both sides
  //canv->SetTickx(0);
  //canv->SetTicky(0);

  // assert(h);
  TH1F *h = canv->DrawFrame(x_min,y_min,x_max,y_max);
  h->GetYaxis()->SetTitleOffset(square ? 1.25 : 1);
  h->GetXaxis()->SetTitleOffset(square ? 1.0 : 0.9);
  h->GetXaxis()->SetTitle(nameXaxis);
  h->GetYaxis()->SetTitle(nameYaxis);
  h->Draw("AXIS");

  // writing the lumi information and the CMS "logo"
  CMS_lumi( canv, iPeriod, iPos );

  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();

  return canv;
}


void tdrCanvasSetAxes(TCanvas *canv, double x_min, double x_max, double y_min, double y_max) {
  ((TH1F*)(canv->GetListOfPrimitives()->FindObject("hframe")))->GetXaxis()->SetRangeUser(x_min,x_max);
  ((TH1F*)(canv->GetListOfPrimitives()->FindObject("hframe")))->GetYaxis()->SetRangeUser(y_min,y_max);
}



// Give the macro empty histograms for h->Draw("AXIS");
// Create h after calling setTDRStyle to get all the settings right
// Created by: Mikko Voutilainen (HIP)

TCanvas* tdrDiCanvas(const char* canvName, double x_min, double x_max, double y_min, double y_max, double y_min2, double y_max2,  const char* nameXaxis, const char* nameYaxis, const char* nameYaxis2, bool square, int iPeriod, int iPos) {

  setTDRStyle();

  // Reference canvas size
  // We'll add a subpad that is a fraction (1/3) of the top canvas size,
  // while keeping margins and text sizes as they were for a single pad

  int W_ref = (square ? 600 : 800);
  int H_ref = (square ? 350 : 600);

  // Set bottom pad relative height and relative margin
  float F_ref = 1./3.;
  float M_ref = 0.03;

  // Set reference margins
  float T_ref = 0.07;
  float B_ref = 0.13;
  float L = square ? 0.12: 0.15;
  float R = 0.05;

  // Calculate total canvas size and pad heights
  int W = W_ref;
  int H = H_ref * (1 + (1-T_ref-B_ref)*F_ref+M_ref);
  float Hup = H_ref * (1-B_ref);
  float Hdw = H - Hup;

  // references for T, B, L, R
  float Tup = T_ref * H_ref / Hup;
  float Tdw = M_ref * H_ref / Hdw;
  float Bup = 0.01;
  float Bdw = B_ref * H_ref / Hdw;

  TCanvas *canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetFrameLineColor(0); // fix from Anne-Laure Pequegnot
  canv->SetFrameLineWidth(0); // fix from Anne-Laure Pequegnot
  // FOR JEC plots, prefer to keep ticks on both sides
  //canv->SetTickx(0);
  //canv->SetTicky(0);

  canv->Divide(1,2);

  canv->cd(1);
  gPad->SetPad(0, Hdw / H, 1, 1);
  gPad->SetLeftMargin( L );
  gPad->SetRightMargin( R );
  gPad->SetTopMargin( Tup );
  gPad->SetBottomMargin( Bup );

  // Scale text sizes and margins to match normal size
  TH1F *hup = canv->cd(1)->DrawFrame(x_min,y_min,x_max,y_max);
  hup->GetYaxis()->SetTitleOffset((square?0.9:1.1) * Hup / H_ref);
  hup->GetXaxis()->SetTitleOffset(0.9);
  hup->SetTitleSize(hup->GetTitleSize("Y") * H_ref / Hup, "Y");
  hup->SetLabelSize(hup->GetLabelSize("Y") * H_ref / Hup, "Y");
  hup->GetYaxis()->SetTitle(nameYaxis);

  // Set tick lengths to match original
  hup->SetTickLength(hup->GetTickLength("Y") * Hup / H_ref, "Y");
  hup->SetTickLength(hup->GetTickLength("X") * H_ref / Hup, "X");

  hup->Draw("AXIS");

  // writing the lumi information and the CMS "logo"
  CMS_lumi( (TCanvas*)gPad, iPeriod, iPos );

  canv->cd(2);
  gPad->SetPad(0, 0, 1, Hdw / H);
  gPad->SetLeftMargin( L );
  gPad->SetRightMargin( R );
  gPad->SetTopMargin( Tdw );
  gPad->SetBottomMargin( Bdw );

  TH1F *hdw = canv->cd(2)->DrawFrame(x_min,y_min2,x_max,y_max2);
  // Scale text sizes and margins to match normal size
  hdw->GetYaxis()->SetTitleOffset((square?0.9:1.1) * Hdw / H_ref);
  hdw->GetXaxis()->SetTitleOffset(0.9);
  hdw->SetTitleSize(hdw->GetTitleSize("Y") * H_ref / Hdw, "Y");
  hdw->SetLabelSize(hdw->GetLabelSize("Y") * H_ref / Hdw, "Y");
  hdw->SetTitleSize(hdw->GetTitleSize("X") * H_ref / Hdw, "X");
  hdw->SetLabelSize(hdw->GetLabelSize("X") * H_ref / Hdw, "X");
  hdw->GetXaxis()->SetTitle(nameXaxis);
  hdw->GetYaxis()->SetTitle(nameYaxis2);

  // Set tick lengths to match original (these are fractions of axis length)
  hdw->SetTickLength(hdw->GetTickLength("Y") * H_ref / Hup, "Y"); //?? ok if 1/3
  hdw->SetTickLength(hdw->GetTickLength("X") * H_ref / Hdw, "X");

  // Reduce divisions to match smaller height (default n=510, optim=kTRUE)
  hdw->GetYaxis()->SetNdivisions(505);

  hdw->Draw("AXIS");

  canv->cd(0);

  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();

  return canv;
}

void setNewTitle(TString name) {
  gStyle->SetOptTitle(0);
  TPaveLabel *title = new TPaveLabel(.11,.95,.35,.99,name,"brNDC");
  title->Draw();
}

void tdrDraw(TH1* h, string opt, int marker, int mcolor, int lstyle, int lcolor, int fstyle, int fcolor) {
  h->SetMarkerStyle(marker);
  h->SetMarkerColor(mcolor);
  h->SetLineStyle(lstyle);
  h->SetLineColor(lcolor==-1 ? mcolor : lcolor);
  h->SetFillStyle(fstyle);
  h->SetFillColor(fcolor);
  h->Draw((opt+" SAME").c_str());
}

void tdrDraw(TGraph* g, string opt, int marker, int mcolor, int lstyle, int lcolor, int fstyle, int fcolor) {
  g->SetMarkerStyle(marker);
  g->SetMarkerColor(mcolor);
  g->SetLineStyle(lstyle);
  g->SetLineColor(lcolor==-1 ? mcolor : lcolor);
  g->SetFillStyle(fstyle);
  g->SetFillColor(fcolor);
  g->Draw((opt+" SAME").c_str());
}

TLegend *tdrLeg(double x1, double y1, double x2, double y2, double textSize, int textFont, int textColor){
  TLegend *leg = new TLegend(x1, y1, x2, y2, "", "brNDC");
  leg->SetFillStyle(kNone);
  leg->SetBorderSize(0);
  leg->SetTextSize(textSize);
  leg->SetTextFont(textFont);
  leg->SetTextColor(textColor);
  leg->Draw();
  return leg;
}

void tdrHeader(TLegend* leg, TString legTitle, int textAlign, double textSize, int textFont, int textColor, bool isToRemove){
  TLegendEntry * header = new TLegendEntry( 0, legTitle, "h" );
  header->SetTextFont(textFont);
  header->SetTextSize(textSize);
  header->SetTextAlign(textAlign);
  header->SetTextColor(textColor);
  if (isToRemove) {
    leg->SetHeader(legTitle,"C");
    leg->GetListOfPrimitives()->Remove(leg->GetListOfPrimitives()->At(0));
    leg->GetListOfPrimitives()->AddAt(header,0);
  } else {
    leg->GetListOfPrimitives()->AddLast(header);
  }
}

//
// TCanvas *c = new TCanvas("c","gerrors",200,10,700,500);
// TH1F *h1 = c->DrawFrame(0.,0.5,5.5,3.5);
// TH1F *h2 = c->DrawFrame(1.,0.2,4.5,2.5);
// TH1F *h3 = c->DrawFrame(9.,1.5,10.5,1.5);
// TH1F *h4 = c->DrawFrame(0.1,13.5,1.5,12.5);
