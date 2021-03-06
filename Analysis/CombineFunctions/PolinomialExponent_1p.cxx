/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Landau core + exponential tail
// Andrea Malara
// 01/08/2019

#include "Riostream.h" 

#include "HiggsAnalysis/CombinedLimit/interface/PolinomialExponent_1p.hpp"
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(PolinomialExponent_1p)

PolinomialExponent_1p::PolinomialExponent_1p(const char *name, const char *title, RooAbsReal& _x, RooAbsReal& _e1) :
RooAbsPdf(name,title), x("x","x",this,_x), e1("e1","e1",this,_e1) {
}


PolinomialExponent_1p::PolinomialExponent_1p(const PolinomialExponent_1p& other, const char* name) :
RooAbsPdf(other,name), x("x",this,other.x), e1("e1",this,other.e1) {
}

Double_t PolinomialExponent_1p::evaluate() const {
  Double_t xp = x/1000.;
  Double_t result = exp(e1*xp);
  return result;
}
