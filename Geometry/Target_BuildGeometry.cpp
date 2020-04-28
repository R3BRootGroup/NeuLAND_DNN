
#include <iomanip>
#include <iostream>
#include "TGeoManager.h"
#include "TMath.h"


// Create Matrix Unity
TGeoRotation *fGlobalRot = new TGeoRotation();

// Create a null translation
TGeoTranslation *fGlobalTrans = new TGeoTranslation();
TGeoRotation *fRefRot = NULL;

TGeoManager* gGeoMan = NULL;
//TGeoVolume* gTop;

Double_t fThetaX = 0.;
Double_t fThetaY = 0.;
Double_t fThetaZ = 0.;
Double_t fPhi   = 0.;
Double_t fTheta = 0.;
Double_t fPsi   = 0.;
Double_t fX = 0.;
Double_t fY = 0.;
Double_t fZ = 0.;
Bool_t fLocalTrans = kFALSE;
Bool_t fLabTrans = kFALSE;

void Target_BuildGeometry()
{
  // Retrieve inputs:
  R3BInputClass* Inputs = new R3BInputClass();
  Inputs->DisableErrorPrinting();
  Inputs->LinkFile("../InputFiles/InputsFile.txt");
  Inputs->ReadFile();  
  
  // Now we get our parameters:
  Double_t X_position = Inputs->GetInputDouble("TARGET_center_x_position","cm");
  Double_t Y_position = Inputs->GetInputDouble("TARGET_center_y_position","cm");
  Double_t Z_position = Inputs->GetInputDouble("TARGET_center_z_position","cm");
  
  Double_t Rotation_X = Inputs->GetInputDouble("TARGET_x_rotation_angle","deg");
  Double_t Rotation_Y = Inputs->GetInputDouble("TARGET_y_rotation_angle","deg");
  Double_t Rotation_Z = Inputs->GetInputDouble("TARGET_z_rotation_angle","deg");
  
  Double_t Thickness = Inputs->GetInputDouble("TARGET_Thickness","cm");
  Double_t Width = Inputs->GetInputDouble("TARGET_Width","cm");
  Double_t Height = Inputs->GetInputDouble("TARGET_Height","cm");
  TString Target_Material = Inputs->GetInputString("Vacuum_Material");
  
  // Define the file name:
  TString geoFileName = Inputs->GetInputString("TheOutputPath") + Inputs->GetInputString("TARGET_Geometry_FileName");
    
  fGlobalTrans->SetTranslation(0.0,0.0,0.0);

  // -------   Load media from media file   -----------------------------------
  FairGeoLoader*    geoLoad = new FairGeoLoader("TGeo","FairGeoLoader");
  FairGeoInterface* geoFace = geoLoad->getGeoInterface();
  TString geoPath = gSystem->Getenv("VMCWORKDIR");
  TString medFile = geoPath + "/geometry/media_r3b.geo";
  geoFace->setMediaFile(medFile);
  geoFace->readMedia();
  gGeoMan = gGeoManager;
  // --------------------------------------------------------------------------

  // -----------------   Get and create the required media    -----------------
  FairGeoMedia* gGeoMedia = geoFace->getMedia();
  FairGeoBuilder* gGeoBuild = geoLoad->getGeoBuilder();

  FairGeoMedium* mLead = gGeoMedia->getMedium("lead");
  if ( ! mLead ) Fatal("Main", "FairMedium lead not found");
  gGeoBuild->createMedium(mLead);
  TGeoMedium* pMedLead = gGeoMan->GetMedium("lead");
  if ( ! pMedLead ) Fatal("Main", "Medium lead not found");

  FairGeoMedium* mCH2      = gGeoMedia->getMedium("CH2");
  if ( ! mCH2 ) Fatal("Main", "FairMedium CH2 not found");
  gGeoBuild->createMedium(mCH2);
  TGeoMedium* pMed38 = gGeoMan->GetMedium("CH2");
  if ( ! pMed38 ) Fatal("Main", "Medium CH2 not found");

  FairGeoMedium* mAir      = gGeoMedia->getMedium("Air");
  if ( ! mAir ) Fatal("Main", "FairMedium Air not found");
  gGeoBuild->createMedium(mAir);
  TGeoMedium* pMed2 = gGeoMan->GetMedium("Air");
  if ( ! pMed2 ) Fatal("Main", "Medium Air not found");
 
  FairGeoMedium* mMylar      = gGeoMedia->getMedium("mylar");
  if ( ! mMylar ) Fatal("Main", "FairMedium mylar not found");
  gGeoBuild->createMedium(mMylar);
  TGeoMedium* pMed15 = gGeoMan->GetMedium("mylar");
  if ( ! pMed15 ) Fatal("Main", "Medium mylar not found");

  FairGeoMedium* mH2      = gGeoMedia->getMedium("H2");
  if ( ! mH2 ) Fatal("Main", "FairMedium H2 not found");
  gGeoBuild->createMedium(mH2);
  TGeoMedium* pMed3 = gGeoMan->GetMedium("H2");
  if ( ! pMed3 ) Fatal("Main", "Medium H2 not found");

  FairGeoMedium* mAu      = gGeoMedia->getMedium("gold");
  if ( ! mAu ) Fatal("Main", "FairMedium gold not found");
  gGeoBuild->createMedium(mAu);
  TGeoMedium* pMedAu = gGeoMan->GetMedium("gold");
  if ( ! pMedAu ) Fatal("Main", "Medium gold not found");

  FairGeoMedium* mCarbon      = gGeoMedia->getMedium("carbon");
  if ( ! mCarbon ) Fatal("Main", "FairMedium carbon not found");
  gGeoBuild->createMedium(mCarbon);
  TGeoMedium* pMedCarbon = gGeoMan->GetMedium("carbon");
  if ( ! pMedCarbon ) Fatal("Main", "Medium carbon not found");

  FairGeoMedium* mVac      = gGeoMedia->getMedium("vacuum");
  if ( ! mVac ) Fatal("Main", "FairMedium vacuum not found");
  gGeoBuild->createMedium(mVac);
  TGeoMedium* pMedVac = gGeoMan->GetMedium("vacuum");
  if ( ! pMedVac ) Fatal("Main", "Medium vacuum not found");
  // --------------------------------------------------------------------------

  // --------------   Create geometry and top volume  -------------------------
  gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("TARGETgeom");
  TGeoVolume* gTop = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(gTop);
  // --------------------------------------------------------------------------

  // Shape: World type: TGeoBBox
  TGeoVolume* pWorld = gGeoManager->GetTopVolume();
  pWorld->SetVisLeaves(kTRUE);
  
  // Material:
  TGeoMedium* pMedTarget = pMedVac;
  if (Target_Material=="Liquid_Hydrogen") {pMedTarget = pMed3;}
  if (Target_Material=="Vacuum") {pMedTarget = pMedVac;}
  if (Target_Material=="Gold") {pMedTarget = pMedAu;}
  if (Target_Material=="Lead") {pMedTarget = pMedLead;}
  if (Target_Material=="CH2") {pMedTarget = pMed38;}
  if (Target_Material=="Air") {pMedTarget = pMed2;}
  if (Target_Material=="Mylar") {pMedTarget = pMed15;}
  if (Target_Material=="Carbon") {pMedTarget = pMedCarbon;}

  // Shape: 
  TGeoShape *pLeadTarget = new TGeoBBox("TheTarget",0.5*Width,0.5*Height,0.5*Thickness);
  TGeoVolume* pleadTarget_log = new TGeoVolume("leadTarget_log",pLeadTarget, pMedTarget);
  pleadTarget_log->SetLineColor(kRed);
  pleadTarget_log->SetVisLeaves(kTRUE);
    
  TGeoVolumeAssembly *keep = new TGeoVolumeAssembly("Target");
  TGeoCombiTrans *ZeroTrans = new TGeoCombiTrans();
  keep->AddNode(pleadTarget_log, 0, ZeroTrans);
  keep->SetLineColor(kRed);

  TGeoCombiTrans *t0 = new TGeoCombiTrans();
  t0->RotateX(Rotation_X);					
  t0->RotateY(Rotation_Y);					
  t0->RotateZ(Rotation_Z);					
  t0->SetTranslation(X_position,Y_position,Z_position);
  pWorld->AddNode(keep, 0, t0);

  // ---------------   Finish   -----------------------------------------------
  gGeoMan->CloseGeometry();
  gGeoMan->CheckOverlaps(0.001);
  gGeoMan->PrintOverlaps();
  gGeoMan->Test();

  TFile* geoFile = new TFile(geoFileName, "RECREATE");
  gTop->Write();
  geoFile->Close();
  // --------------------------------------------------------------------------
}
