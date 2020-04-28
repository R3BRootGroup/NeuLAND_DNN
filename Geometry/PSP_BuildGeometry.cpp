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

void PSP_BuildGeometry()
{
  // Retrieve inputs:
  R3BInputClass* Inputs = new R3BInputClass();
  Inputs->DisableErrorPrinting();
  Inputs->LinkFile("../InputFiles/InputsFile.txt");
  Inputs->ReadFile();  
  
  // Now we get our parameters:
  Double_t X_position = Inputs->GetInputDouble("PSP_center_x_position","cm");
  Double_t Y_position = Inputs->GetInputDouble("PSP_center_y_position","cm");
  Double_t Z_position = Inputs->GetInputDouble("PSP_center_z_position","cm");
  
  Double_t Rotation_X = Inputs->GetInputDouble("PSP_x_rotation_angle","deg");
  Double_t Rotation_Y = Inputs->GetInputDouble("PSP_y_rotation_angle","deg");
  Double_t Rotation_Z = Inputs->GetInputDouble("PSP_z_rotation_angle","deg");
  
  // Define the file name:
  TString geoFileName = Inputs->GetInputString("TheOutputPath") + Inputs->GetInputString("PSP_Geometry_FileName");
    
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

  FairGeoMedium* mVac      = geoMedia->getMedium("vacuum");
  if ( ! mVac ) Fatal("Main", "FairMedium vacuum not found");
  geoBuild->createMedium(mVac);
  TGeoMedium* pMed1 = gGeoMan->GetMedium("vacuum");
  if ( ! pMed1 ) Fatal("Main", "Medium vacuum not found");
  
  FairGeoMedium* mSi      = geoMedia->getMedium("silicon");
  if ( ! mSi ) Fatal("Main", "FairMedium silicon not found");
  geoBuild->createMedium(mSi);
  TGeoMedium* pMedSi = gGeoMan->GetMedium("silicon");
  if ( ! pMedSi ) Fatal("Main", "Medium silicon not found");
  // --------------------------------------------------------------------------



  // --------------   Create geometry and top volume  -------------------------
  gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("PSPgeom");
  TGeoVolume* top = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(top);
  // --------------------------------------------------------------------------



  // out-of-file geometry definition
  Double_t dx,dy,dz;
  Double_t a;
  Double_t thx, phx, thy, phy, thz, phz;
  Double_t z, density, radl, absl, w;
  Int_t nel, numed;
  
  
  //psp1
  dx = 0.0;  //pschrock s412
  dy = 0.0;
  dz = -221.0;
  
  TGeoRotation *gRot1 = new TGeoRotation();
  gRot1->RotateX(0.);
  gRot1->RotateY(0.); // s412
  gRot1->RotateZ(0.);
  
  TGeoCombiTrans* pMatrix1 = new TGeoCombiTrans("", dx,dy,dz,gRot1);
  
  
  //psp2
  dx = 0.0;  //pschrock s412
  dy = 0.0;
  dz = -89.0;
  
  TGeoRotation *gRot2 = new TGeoRotation();
  gRot2->RotateX(0.);
  gRot2->RotateY(0.); // s412
  gRot2->RotateZ(0.);
  
  TGeoCombiTrans* pMatrix2 = new TGeoCombiTrans("", dx,dy,dz,gRot2);
  
  
  //psp3
  dx = 0.00; //s412 pschrock
  dy = 0.00;
  dz = 94.1;
  
  TGeoRotation *gRot3 = new TGeoRotation();
  gRot3->RotateX(0.);
  gRot3->RotateY(0.); // s412
  gRot3->RotateZ(0.);
  
  TGeoCombiTrans* pMatrix3 = new TGeoCombiTrans("", dx,dy,dz,gRot3);
  
  
  // World definition
  TGeoVolume* pWorld = gGeoManager->GetTopVolume();
  pWorld->SetVisLeaves(kTRUE);
  
  
  TGeoVolumeAssembly *pPsp = new TGeoVolumeAssembly("PSPWorld");
  TGeoCombiTrans *t0 = new TGeoCombiTrans();
  t0->RotateX(Rotation_X);					
  t0->RotateY(Rotation_Y);					
  t0->RotateZ(Rotation_Z);					
  t0->SetTranslation(X_position,Y_position,Z_position);
  pWorld->AddNode(pPsp, 1, t0);
  
  
  // SHAPES, VOLUMES AND GEOMETRICAL HIERARCHY
  // Shape: PSPBoxWorld type: TGeoBBox
  dx = 2.5000;
  dy = 2.5000;
  dz = 0.050000;
  TGeoShape *pPSPBoxWorld = new TGeoBBox("PSPBoxWorld", dx,dy,dz);
  // Volume: PSPLogWorld
  //    TGeoVolume* pPSPLogWorld = new TGeoVolume("PSPLogWorld",pPSPBoxWorld, pMed1); //vacuum filled
  TGeoVolume* pPSP1LogWorld = new TGeoVolume("PSP1LogWorld",pPSPBoxWorld, pMed1); //vacuum filled
  TGeoVolume* pPSP2LogWorld = new TGeoVolume("PSP2LogWorld",pPSPBoxWorld, pMed1); //vacuum filled
  TGeoVolume* pPSP3LogWorld = new TGeoVolume("PSP3LogWorld",pPSPBoxWorld, pMed1); //vacuum filled
  //    pPSPLogWorld->SetVisLeaves(kTRUE);
  pPSP1LogWorld->SetVisLeaves(kTRUE);
  pPSP2LogWorld->SetVisLeaves(kTRUE);
  pPSP3LogWorld->SetVisLeaves(kTRUE);
  
  // Global positioning
  pPsp->AddNode( pPSP1LogWorld, 1, pMatrix1 ); //psp1
  pPsp->AddNode( pPSP2LogWorld, 2, pMatrix2 ); //psp2
  pPsp->AddNode( pPSP3LogWorld, 3, pMatrix3 ); //psp3
  
  // Shape: PSPBox type: TGeoBBox
  dx = 2.25000;
  dy = 2.25000;
  dz = 0.01005; //psp1 201 um, s412
  TGeoShape *pPSP1Box = new TGeoBBox("PSP1Box", dx,dy,dz);
  
  dx = 2.25000;
  dy = 2.25000;
  dz = 0.0102; //psp2 204 um, s412
  TGeoShape *pPSP2Box = new TGeoBBox("PSP2Box", dx,dy,dz);
  
  dx = 2.25000;
  dy = 2.25000;
  dz = 0.00520; //psp3 104 um, s412
  TGeoShape *pPSP3Box = new TGeoBBox("PSP3Box", dx,dy,dz);
  
  
  // Volume: PSPLog
  //create active volumes of psp's with specific thicknesses
  TGeoVolume* pPSP1Log = new TGeoVolume("PSP1Log",pPSP1Box, pMedSi);
  TGeoVolume* pPSP2Log = new TGeoVolume("PSP2Log",pPSP2Box, pMedSi);
  TGeoVolume* pPSP3Log = new TGeoVolume("PSP3Log",pPSP3Box, pMedSi);
  pPSP1Log->SetVisLeaves(kTRUE);
  pPSP2Log->SetVisLeaves(kTRUE);
  pPSP3Log->SetVisLeaves(kTRUE);
  
  pPSP1Log->SetLineColor(kMagenta);
  pPSP2Log->SetLineColor(kMagenta);
  pPSP3Log->SetLineColor(kMagenta);
  
  
  // Combi transformation:
  //"empty" matrix for placing active volumes inside vacuum box
  dx = 0.000000;
  dy = 0.000000;
  dz = 0.000000;
  // Rotation:
  thx = 90.000000;    phx = 0.000000;
  thy = 90.000000;    phy = 90.000000;
  thz = 0.000000;    phz = 0.000000;
  TGeoRotation *pMatrix7 = new TGeoRotation("",thx,phx,thy,phy,thz,phz);
  TGeoCombiTrans*
  pMatrix6 = new TGeoCombiTrans("", dx,dy,dz,pMatrix7);
  
  
  //    pPSPLogWorld->AddNode(pPSP1Log, 1, pMatrix6);
  //    pPSPLogWorld->AddNode(pPSP2Log, 2, pMatrix6);
  //    pPSPLogWorld->AddNode(pPSP3Log, 3, pMatrix6);
  pPSP1LogWorld->AddNode(pPSP1Log, 1, pMatrix6);
  pPSP2LogWorld->AddNode(pPSP2Log, 2, pMatrix6);
  pPSP3LogWorld->AddNode(pPSP3Log, 3, pMatrix6);
  
  
  // Add the sensitive part
//  AddSensitiveVolume(pPSP1Log);
//  AddSensitiveVolume(pPSP2Log);
//  AddSensitiveVolume(pPSP3Log);
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
