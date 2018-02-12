/*
 * AliFemtoDreamCascadeCuts.h
 *
 *  Created on: Jan 11, 2018
 *      Author: gu74req
 */

#ifndef ALIFEMTODREAMCASCADECUTS_H_
#define ALIFEMTODREAMCASCADECUTS_H_
#include "Rtypes.h"
#include "TList.h"
#include "AliFemtoDreamCascade.h"
#include "AliFemtoDreamCascadeHist.h"
#include "AliFemtoDreamv0MCHist.h"
#include "AliFemtoDreamTrackCuts.h"
class AliFemtoDreamCascadeCuts {
 public:
  AliFemtoDreamCascadeCuts();
  virtual ~AliFemtoDreamCascadeCuts();
  static AliFemtoDreamCascadeCuts *XiCuts(bool isMC,bool contribSplitting);
  void Setv0Negcuts(AliFemtoDreamTrackCuts *cuts){fNegCuts=cuts;};
  void Setv0PosCuts(AliFemtoDreamTrackCuts *cuts){fPosCuts=cuts;};
  void SetBachCuts(AliFemtoDreamTrackCuts *cuts){fBachCuts=cuts;};
  void SetIsMonteCarlo(bool isMC){fMCData=isMC;};
  bool GetIsMonteCarlo() {return fMCData;};
  void SetContributionSplitting(bool contrSplit){
    fContribSplitting=contrSplit;};
  void SetXiMassRange(double mass,double width){
    fcutXiMass=true;fXiMass=mass;fXiMassWidth=width;};
  void SetXiCharge(int charge){fcutXiCharge=true;fXiCharge=charge;}
  void SetCutXiDaughterDCA(double maxDCA){
    fcutDCAXiDaug=true;fMaxDCAXiDaug=maxDCA;};
  void SetCutXiMinDistBachToPrimVtx(double minDist){
    fcutMinDistVtxBach=true;fMinDistVtxBach=minDist;};
  void SetCutXiCPA(double cpa){fcutCPAXi=true;fCPAXi=cpa;};
  void SetCutXiTransverseRadius(double minRad,double maxRad){
    fcutXiTransRadius=true;fMinXiTransRadius=minRad;fMaxXiTransRadius=maxRad;}
  void Setv0MassRange(double mass,double width){
    fcutv0Mass=true;fv0Mass=mass;fv0Width=width;}
  void SetCutv0MaxDaughterDCA(double maxDCA){
    fcutv0MaxDCADaug=true;fv0MaxDCADaug=maxDCA;}
  void SetCutv0CPA(double CPA){
    fcutCPAv0=true;fCPAv0=CPA;}
  void SetCutv0TransverseRadius(double minRad,double maxRad){
    fcutv0TransRadius=true;fMinv0TransRadius=minRad;fMaxv0TransRadius=maxRad;}
  void SetCutv0MinDistToPrimVtx(double minDist){
    fcutv0MinDistVtx=true;fv0MinDistVtx=minDist;}
  void SetCutv0MinDaugDistToPrimVtx(double minDist){
    fcutv0DaugMinDistVtx=true;fv0DaugMinDistVtx=minDist;};
  TString ClassName()const{return "AliFemtoDreamCascadeCuts";};
  void Init();
  bool isSelected(AliFemtoDreamCascade *casc);
  void BookQA(AliFemtoDreamCascade *casc);
  void BookMCQA(AliFemtoDreamCascade *casc);
  TList *GetQAHists() {return fHistList;};
  TList *GetMCQAHists() {return fMCHistList;};
 private:
  AliFemtoDreamCascadeHist *fHist;
  AliFemtoDreamv0MCHist *fMCHist;
  AliFemtoDreamTrackCuts *fNegCuts;
  AliFemtoDreamTrackCuts *fPosCuts;
  AliFemtoDreamTrackCuts *fBachCuts;
  TList *fHistList;
  TList *fMCHistList;
  bool fMCData;
  bool fContribSplitting;
  bool fcutXiMass;
  double fXiMass;
  double fXiMassWidth;
  bool fcutXiCharge;
  int fXiCharge;
  bool fcutDCAXiDaug;
  double fMaxDCAXiDaug;
  bool fcutMinDistVtxBach;
  double fMinDistVtxBach;
  bool fcutCPAXi;
  double fCPAXi;
  bool fcutXiTransRadius;
  double fMinXiTransRadius;
  double fMaxXiTransRadius;
  bool fcutv0Mass;
  double fv0Mass;
  double fv0Width;
  bool fcutv0MaxDCADaug;
  double fv0MaxDCADaug;
  bool fcutCPAv0;
  double fCPAv0;
  bool fcutv0TransRadius;
  double fMinv0TransRadius;
  double fMaxv0TransRadius;
  bool fcutv0MinDistVtx;
  double fv0MinDistVtx;
  bool fcutv0DaugMinDistVtx;
  double fv0DaugMinDistVtx;

  ClassDef(AliFemtoDreamCascadeCuts,1)
};

#endif /* ALIFEMTODREAMCASCADECUTS_H_ */
