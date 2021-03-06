/*****************************************************************************
* Project: RooFit                                                           *
*                                                                           *
* This code was autogenerated by RooClassFactory                            *
*****************************************************************************/

#pragma once

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

class PolinomialExponent_3p : public RooAbsPdf {
public:
  PolinomialExponent_3p() {} ;
  PolinomialExponent_3p(const char *name, const char *title, RooAbsReal& _x, RooAbsReal& _e1, RooAbsReal& _e2, RooAbsReal& _e3);
  PolinomialExponent_3p(const PolinomialExponent_3p& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new PolinomialExponent_3p(*this,newname); }
  inline virtual ~PolinomialExponent_3p() { }

  /*
  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
  Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;
  */

protected:

  RooRealProxy x;
  RooRealProxy e1;
  RooRealProxy e2;
  RooRealProxy e3;

  Double_t evaluate() const ;

private:

  ClassDef(PolinomialExponent_3p,2)  // PDF of dijet function with 4 free parameters
};
