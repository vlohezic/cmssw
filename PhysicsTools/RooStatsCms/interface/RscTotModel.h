#ifndef __RscTotModel__
#define __RscTotModel__

/// RscTotModel: An analysis resumed

/**
\class RscTotModel
$Revision: 1.3 $
$Date: 2009/04/15 11:10:45 $
\author G. Schott (gregory.Schott<at>cern.ch), Danilo Piparo - Universitaet Karlsruhe
**/

#if (defined (STANDALONE) or defined (__CINT__) )
   #include "RscCompModel.h"
#else
   #include "PhysicsTools/RooStatsCms/interface/RscCompModel.h"
#endif

#include "RooExtendPdf.h"
#include "RooStringVar.h"

class RscTotModel : public RscAbsPdfBuilder {

public:
  RscTotModel(TString theName);
  ~RscTotModel();

  RooAbsPdf* getExtendedBkgPdf();
  RooAbsPdf* getExtendedSigPdf();

  RooArgList* getVars();
  RooRealVar* getVar(TString varName);
  RooArgList* getConstraints();

  RooFormulaVar* getSigYield();
  RooFormulaVar* getBkgYield();

  //DP might be useful
  const char* getName(){return _name.Data();};

  void readDataCard();
  void writeDataCard(ostream& out);
  
private:
  TString _name;

  RooStringVar variablesString;

  RooArgList* theConstraints;
  RooArgList* theVars;

  RscCompModel* bkgModel;
  RscCompModel* sigModel;

  RooExtendPdf* sigExtendedPdf;
  RooExtendPdf* bkgExtendedPdf;

  void buildPdf();
  void buildVars();
  void buildConstraints();

  #ifndef SWIG
  #endif /*SWIG */
//For Cint
#if (defined (STANDALONE) or defined (__CINT__) )
ClassDef(RscTotModel,1)
#endif
};

#endif
// Automatically converted from the standalone version Wed Apr 15 11:36:34 2009
