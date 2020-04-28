#include <iomanip>
#include <iostream>
#include "TGeoManager.h"
#include "TMath.h"

// Create Matrix Unity
TGeoRotation *fGlobalRot = new TGeoRotation();

// Create a null translation
TGeoTranslation *fGlobalTrans = new TGeoTranslation();
TGeoRotation *fRefRot = NULL;

TGeoManager*  gGeoMan = NULL;

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
Bool_t fLabTrans = kTRUE;

void TOFwall_BuildGeometry()
{
  // Retrieve inputs:
  R3BInputClass* Inputs = new R3BInputClass();
  Inputs->DisableErrorPrinting();
  Inputs->LinkFile("../InputFiles/InputsFile.txt");
  Inputs->ReadFile();  
  
  // Now we get our parameters:
  Double_t X_position = Inputs->GetInputDouble("TOFwall_center_x_position","cm");
  Double_t Y_position = Inputs->GetInputDouble("TOFwall_center_y_position","cm");
  Double_t Z_position = Inputs->GetInputDouble("TOFwall_center_z_position","cm");
  
  Double_t Rotation_X = Inputs->GetInputDouble("TOFwall_x_rotation_angle","deg");
  Double_t Rotation_Y = Inputs->GetInputDouble("TOFwall_y_rotation_angle","deg");
  Double_t Rotation_Z = Inputs->GetInputDouble("TOFwall_z_rotation_angle","deg");
  
  // Define the file name:
  TString geoFileName = Inputs->GetInputString("TheOutputPath") + Inputs->GetInputString("TOFwall_Geometry_FileName");
   
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
  FairGeoMedia*   geoMedia = geoFace->getMedia();
  FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

  FairGeoMedium* mAir      = geoMedia->getMedium("Air");
  if ( ! mAir ) Fatal("Main", "FairMedium Air not found");
  geoBuild->createMedium(mAir);
  TGeoMedium* pMed2 = gGeoMan->GetMedium("Air");
  if ( ! pMed2 ) Fatal("Main", "Medium Air not found");
  
  FairGeoMedium* mTof      = geoMedia->getMedium("plasticForTOF");
  if ( ! mTof ) Fatal("Main", "FairMedium plasticForTOF not found");
  geoBuild->createMedium(mTof);
  TGeoMedium* pMed34 = gGeoMan->GetMedium("plasticForTOF");
  if ( ! pMed34 ) Fatal("Main", "Medium plasticForTOF not found");
  // --------------------------------------------------------------------------



  // --------------   Create geometry and top volume  -------------------------
  gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("TOFgeom");
  TGeoVolume* top = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(top);
  // --------------------------------------------------------------------------



  // out-of-file geometry definition
  Double_t dx,dy,dz;
  Double_t a;
  //   Double_t thx, phx, thy, phy, thz, phz;
  Double_t z, density, w;
  Int_t nel, numed;
  
  
  
  // TRANSFORMATION MATRICES
  // Combi transformation:
  dx = -417.359574; //Justyna
  dy = 2.400000;    //Justyna
  dz = 960.777114;  //Justyna
  
  //    dx = -421.33683; //Christoph
  //    dy = 2.12;    //Christoph
  //    dz = 958.387337;  //Christoph
  
  /*    dx = -171.1;  //position directrly (15cm) after DCH2
   dy = 2.400000;
   dz = 548.95;*/
  // dz = 0.;
  /*   // Rotation:
   thx = -121.000000;    phx = 0.000000;
   thy = 90.000000;    phy = 90.000000;
   thz = -31.000000;    phz = 0.000000;*/  //this
  
  //   TGeoRotation *pMatrix3 = new TGeoRotation("",thx,phx,thy,phy,thz,phz);  //this
  TGeoRotation *gRot = new TGeoRotation();
  
  TGeoCombiTrans*
  //   pMatrix2 = new TGeoCombiTrans("", dx,dy,dz,pMatrix3);  //this
  pMatrix2 = new TGeoCombiTrans("", dx,dy,dz,gRot);  //this
  
  
  
  
  
  
  
  /* PREVIOUS!!!
   // TRANSFORMATION MATRICES
   // Combi transformation:
   dx = 419.700000;
   dy = 0.000000;
   dz = 952.400000;
   // dz = 0.;
   // Rotation:
   thx = 121.000000;    phx = 0.000000;
   thy = 90.000000;    phy = 90.000000;
   thz = 31.000000;    phz = 0.000000;
   TGeoRotation *pMatrix3 = new TGeoRotation("",thx,phx,thy,phy,thz,phz);
   TGeoCombiTrans*
   pMatrix2 = new TGeoCombiTrans("", dx,dy,dz,pMatrix3);
   */
  
  //Top Volume
  TGeoVolume* pWorld = gGeoManager->GetTopVolume();
  pWorld->SetVisLeaves(kTRUE);
  
  
  TGeoVolumeAssembly *ptof = new TGeoVolumeAssembly("TOF");
  
  
  // SHAPES, VOLUMES AND GEOMETRICAL HIERARCHY
  // Shape: TOFBox type: TGeoBBox
  dx = 94.450000;
  dy = 73.450000;
  dz = 0.500000;
  TGeoShape *pTOFBox = new TGeoBBox("TOFBox", dx,dy,dz);
  // Volume: TOFLog
  TGeoVolume*
  pTOFLog = new TGeoVolume("TOFLog",pTOFBox, pMed34);
  pTOFLog->SetVisLeaves(kTRUE);
  pTOFLog->SetLineColor(kMagenta);
  
  TGeoCombiTrans *t0 = new TGeoCombiTrans("t0");
  ptof->AddNode(pTOFLog, 0, t0);
  
  TGeoCombiTrans *tGlobal = new TGeoCombiTrans();
  tGlobal->RotateX(Rotation_X);					
  tGlobal->RotateY(Rotation_Y);					
  tGlobal->RotateZ(Rotation_Z);					
  tGlobal->SetTranslation(X_position,Y_position,Z_position);
  pWorld->AddNode(ptof, 0, tGlobal);
  
//  AddSensitiveVolume(pTOFLog);
//  fNbOfSensitiveVol+=1;
  
  
  
  // ---------------   Finish   -----------------------------------------------
  gGeoMan->CloseGeometry();
  gGeoMan->CheckOverlaps(0.001);
  gGeoMan->PrintOverlaps();
  gGeoMan->Test();

  TFile* geoFile = new TFile(geoFileName, "RECREATE");
  top->Write();
  geoFile->Close();
  // --------------------------------------------------------------------------
}
