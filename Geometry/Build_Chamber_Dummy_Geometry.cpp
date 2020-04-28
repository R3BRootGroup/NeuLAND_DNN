// Include C++ headers:
#include <iomanip>
#include <iostream>

// include ROOT headers:
#include "TGeoManager.h"
#include "TMath.h"

// Define the main function:
void Build_Chamber_Dummy_Geometry()
{
  // This function creates a geometry file for the R3B vacuum chamber behind
  //the GLAD magnet. The geometry is not exact, just a simple volume that we can
  // use until the real chamber is implemented.
    
  // Written by C. A. Douma, for the R3B Collaboration.
  
  // ===========================================================================
  // Before we do anything: Draw the global positioning parameters from
  // our inputs-file:
  R3BInputClass* Inputs = new R3BInputClass();
  Inputs->DisableErrorPrinting();
  Inputs->LinkFile("../InputFiles/InputsFile.txt");
  Inputs->ReadFile();  
  
  // Now we get our parameters:
  Double_t X_position = Inputs->GetInputDouble("Vacuum_Chamber_center_x_position","cm");
  Double_t Y_position = Inputs->GetInputDouble("Vacuum_Chamber_center_y_position","cm");
  Double_t Z_position = Inputs->GetInputDouble("Vacuum_Chamber_center_z_position","cm");
  
  Double_t Rotation_X = Inputs->GetInputDouble("Vacuum_Chamber_x_rotation_angle","deg");
  Double_t Rotation_Y = Inputs->GetInputDouble("Vacuum_Chamber_y_rotation_angle","deg");
  Double_t Rotation_Z = Inputs->GetInputDouble("Vacuum_Chamber_z_rotation_angle","deg");
  
  // Tag for different building types:
  Int_t Chamber_Exists = 1;
  
  // Define the file name:
  TString geoFileName = Inputs->GetInputString("TheOutputPath") + Inputs->GetInputString("Vacuum_Chamber_Geometry_FileName");
  
  // NOTE: Shift the variables, so we can use zero as default in inputs:
  Z_position = Z_position + 571.0 + 45.0 + 37.0;;
  Rotation_Y = Rotation_Y - 14.0;
  X_position = X_position - 147.0 - 0.0;
  
  Double_t TheZshift = 18.0;
  Double_t TheThickness = Inputs->GetInputDouble("TARGET_Thickness","cm");
  Int_t SteelColor = kRed;
  Int_t VacuumColor = kGreen;
  Int_t NeutronWindowColor = kBlue-1;
  Int_t KaptonColor = kOrange+1;
  Int_t DetectorColor = kYellow;
  
  // Next: declare the geometry parameters that we need:
  TGeoRotation *fGlobalRot = new TGeoRotation();
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
  Double_t fZ = 1550.;
  Bool_t fLocalTrans = kFALSE;
  Bool_t fLabTrans = kTRUE;
  
  // Define the global positioning transformation:
  fGlobalTrans->SetTranslation(0.0,0.0,0.0);

  // Coonect to the FAIR medium file:
  FairGeoLoader*    geoLoad = new FairGeoLoader("TGeo","FairGeoLoader");
  FairGeoInterface* geoFace = geoLoad->getGeoInterface();
  TString geoPath = gSystem->Getenv("VMCWORKDIR");
  TString medFile = geoPath + "/geometry/media_r3b.geo";
  geoFace->setMediaFile(medFile);
  geoFace->readMedia();
  gGeoMan = gGeoManager;
  FairGeoMedia*   geoMedia = geoFace->getMedia();
  FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

  // Get pointers to the media we need:
  FairGeoMedium* mAl = geoMedia->getMedium("aluminium");
  if ( ! mAl ) Fatal("Main","FairMedium aluminium not found");
  geoBuild->createMedium(mAl);
  TGeoMedium* pMedAl = gGeoMan->GetMedium("aluminium");
  if ( ! pMedAl ) Fatal("Main", "Medium aluminium not found");
  
  FairGeoMedium* mVac = geoMedia->getMedium("vacuum");
  if ( ! mVac ) Fatal("Main","FairMedium vacuum not found");
  geoBuild->createMedium(mVac);
  TGeoMedium* pMedVac = gGeoMan->GetMedium("vacuum");
  if ( ! pMedVac ) Fatal("Main", "Medium vacuum not found");
  
  FairGeoMedium* mSS = geoMedia->getMedium("Steel");
  if ( ! mSS ) Fatal("Main","FairMedium Steel not found");
  geoBuild->createMedium(mSS);
  TGeoMedium* pMedSS = gGeoMan->GetMedium("Steel");
  if ( ! pMedSS ) Fatal("Main", "Medium Steel not found");
  
  FairGeoMedium* mKap = geoMedia->getMedium("kapton");
  if ( ! mKap ) Fatal("Main","FairMedium kapton not found");
  geoBuild->createMedium(mKap);
  TGeoMedium* pMedKap = gGeoMan->GetMedium("kapton");
  if ( ! pMedKap ) Fatal("Main", "Medium kapton not found");
  
  FairGeoMedium* mBC408 = geoMedia->getMedium("BC408");
  if ( ! mBC408 ) Fatal("Main", "FairMedium BC408 not found");
  geoBuild->createMedium(mBC408);
  TGeoMedium* pMed37 = gGeoMan->GetMedium("BC408");
  if ( ! pMed37 ) Fatal("Main", "Medium BC408 not found");
  
  FairGeoMedium* mTof = geoMedia->getMedium("plasticForTOF");
  if ( ! mTof ) Fatal("Main", "FairMedium plasticForTOF not found");
  geoBuild->createMedium(mTof);
  TGeoMedium* pMed34 = gGeoMan->GetMedium("plasticForTOF");
  if ( ! pMed34 ) Fatal("Main", "Medium plasticForTOF not found");
  
  FairGeoMedium* mLead = geoMedia->getMedium("lead");
  if ( ! mLead ) Fatal("Main", "FairMedium lead not found");
  geoBuild->createMedium(mLead);
  TGeoMedium* pMedLead = gGeoMan->GetMedium("lead");
  if ( ! pMedLead ) Fatal("Main", "Medium lead not found");
  
  // Create the top-volume:
  gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("CHAMBERgeom");
  TGeoVolume* top = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(top);

  // ======================================================================================
  // Now we can build our actual geometry:
  Double_t thick = 5.0; // reasonable
  Double_t nDiam = 140.0; // From drawings.
  Double_t PipeDiam = 50.0; // from drawings!
  Double_t PipeLength = 650.0; // reasonable
  
  if (Chamber_Exists==4) {PipeDiam = PipeDiam - thick;}
  
  // Build the basic rotation & translation blocks we need:
  TGeoRotation* zeroRotation = new TGeoRotation("zeroRotation");
  zeroRotation->RotateX(0.0);
  zeroRotation->RotateY(0.0);
  zeroRotation->RotateZ(0.0);
  TGeoCombiTrans* zerotransf = new TGeoCombiTrans("zerotransf",0.0,0.0,0.0,zeroRotation);
  zerotransf->RegisterYourself();
  
  // Build the vacuum chamber basic outline:
  TGeoVolume* box1 = gGeoManager->MakeBox("box1",pMedSS,532.38/2.0,171.6/2.0,260.32/2.0); box1->SetLineColor(SteelColor); // overall vac. chamber box.
  TGeoVolume* box5 = gGeoManager->MakeBox("box5",pMedVac,532.38/2.0,171.6/2.0-thick,260.32/2.0); box5->SetLineColor(VacuumColor); // overall vac. chamber content.
  TGeoVolume* box6 = gGeoManager->MakeBox("box6",pMedVac,532.38/2.0+10.0,171.6/2.0-thick,260.32/2.0+10.0); box6->SetLineColor(VacuumColor); // overall vac. chamber content for subtraction.
  
  // Build the cutoff-boxes:
  TGeoVolume* box2 = gGeoManager->MakeBox("box2",pMedSS,191.9/2.0,10.0+171.6/2.0,191.9/2.0); box2->SetLineColor(SteelColor);// Neutron window cutoff.
  TGeoVolume* box3 = gGeoManager->MakeBox("box3",pMedSS,395.5/2.0,10.0+171.6/2.0,395.5/2.0); box3->SetLineColor(SteelColor);// proton window cutoff.
  TGeoVolume* box4 = gGeoManager->MakeBox("box4",pMedSS,111.9/2.0,10.0+171.6/2.0,111.9/2.0); box4->SetLineColor(SteelColor);// third cutoff.
  
  // Build the wall plates:
  TGeoVolume* boxw2 = gGeoManager->MakeBox("boxw2",pMedSS,191.9/2.0-thick/4.0,171.6/2.0,thick/2.0); boxw2->SetLineColor(SteelColor); // Neutron window plate.
  TGeoVolume* boxw3 = gGeoManager->MakeBox("boxw3",pMedSS,395.5/2.0-thick/4.0,171.6/2.0,thick/2.0); boxw3->SetLineColor(SteelColor); // Pipe window plate.
  TGeoVolume* boxw4 = gGeoManager->MakeBox("boxw4",pMedSS,111.9/2.0+thick/4.0,171.6/2.0,thick/2.0); boxw4->SetLineColor(SteelColor); // third plate.
  TGeoVolume* boxw5 = gGeoManager->MakeBox("boxw5",pMedSS,468.2/2.0+thick/1.0,171.6/2.0,thick/2.0); boxw5->SetLineColor(SteelColor); // bottom plate
  TGeoVolume* boxw6 = gGeoManager->MakeBox("boxw6",pMedSS,213.9/2.0+thick/4.0,171.6/2.0,thick/2.0); boxw6->SetLineColor(SteelColor); // vertical plate
  TGeoVolume* boxw7 = gGeoManager->MakeBox("boxw7",pMedSS,thick/2.0,171.6/2.0,5.5); boxw7->SetLineColor(SteelColor); // very small auxillary plate
  
  // Build the windows:
  TGeoVolume* nSubt = gGeoManager->MakeTube("nSubt",pMedSS,0.0,nDiam/2.0,thick/2.0+10.0); nSubt->SetLineColor(NeutronWindowColor); // neutron window for the subtraction:
  TGeoVolume* nWindow = gGeoManager->MakeTube("nWindow",pMedSS,0.0,nDiam/2.0,0.4/2.0); nWindow->SetLineColor(NeutronWindowColor); // neutron window
  TGeoVolume* GladSubt = gGeoManager->MakeBox("GladSubt",pMedSS,468.2/2.0+thick/1.0,50.0,20.0); GladSubt->SetLineColor(SteelColor); // bottom plate glad aperture subtraction:
  TGeoVolume* GladVac = gGeoManager->MakeBox("GladVac",pMedVac,468.2/2.0+thick/1.0,50.0,thick/2.0); GladVac->SetLineColor(VacuumColor); // bottom plate glad aperture vacuum
  
  // Build the pipe:
  TGeoVolume* PipeGap = gGeoManager->MakeTube("PipeGap",pMedSS,0.0,PipeDiam/2.0,50.0); PipeGap->SetLineColor(SteelColor); // Subtrction of the vacuum chamber pipe.
  TGeoVolume* Pipe = gGeoManager->MakeTube("Pipe",pMedSS,PipeDiam/2.0-thick,PipeDiam/2.0,PipeLength/1.0); PipeGap->SetLineColor(SteelColor); // the pipe itself.
  TGeoVolume* PipeVac = gGeoManager->MakeTube("PipeVac",pMedVac,0.0,PipeDiam/2.0-thick,PipeLength/1.0); PipeGap->SetLineColor(VacuumColor); // pipe content.
  TGeoVolume* boxps = gGeoManager->MakeBox("boxps",pMedSS,2000.0,171.6/2.0,2000.0); PipeGap->SetLineColor(SteelColor); // subtraction of the pipe inside the chamber.
  TGeoVolume* Flange = gGeoManager->MakeTube("Flange",pMedKap,0.0,PipeDiam/2.0,PipeLength/1.0+0.2); Flange->SetLineColor(KaptonColor); // kapton flange of the pipe
  TGeoVolume* FlangeSubt = gGeoManager->MakeTube("FlangeSubt",pMedKap,0.0,PipeDiam,PipeLength/1.0); FlangeSubt->SetLineColor(KaptonColor);// subtraction of one of the two flanges.
  
  // Build dummies of the tracking system for the proton branch of the spectrometer (Inside the chamber!)
  TGeoVolume* X1 = gGeoManager->MakeBox("X1",pMedKap,173.5/2.0,160.0/2.0,6.0/2.0); X1->SetLineColor(DetectorColor); // X1 kapton detector.
  TGeoVolume* Y1 = gGeoManager->MakeBox("Y1",pMedAl,227.6/2.0,160.0/2.0,6.0/2.0); Y1->SetLineColor(DetectorColor); // Y1 Aluminium detector
  TGeoVolume* X2 = gGeoManager->MakeBox("X2",pMedAl,232.0/2.0,160.0/2.0,6.0/2.0); X2->SetLineColor(DetectorColor); // X2 Aluminium detector
  TGeoVolume* Y2 = gGeoManager->MakeBox("Y2",pMedAl,249.2/2.0,160.0/2.0,6.0/2.0); Y2->SetLineColor(DetectorColor); // Y2 Aluminium detector
  TGeoVolume* Pscint = gGeoManager->MakeBox("Pscint",pMed37,260.0/2.0,160.0/2.0,17.0/2.0); Pscint->SetLineColor(DetectorColor); // Proton scintillator wall
  
  // Build dummies for the MFI inbeam-detector and the TOF-wall:
  TGeoVolume* TOF = gGeoManager->MakeBox("TOF",pMed34,200.0/2.0,200.0/2.0,1.6/2.0); TOF->SetLineColor(DetectorColor); // 16 mm thick TOF wall.
  TGeoVolume* MFI = gGeoManager->MakeBox("MFI",pMed34,PipeDiam/2.0,PipeDiam/2.0,0.02/2.0); MFI->SetLineColor(DetectorColor); // 200 micrometer MFI
  
  // Build the GLAD vacuum content & Vacuum beamline:
  TGeoVolume* G1 = gGeoManager->MakeBox("G1",pMedVac,468.2/2.0,45.0,468.2/2.0); G1->SetLineColor(VacuumColor); // GLAD aperature vac. content.
  TGeoVolume* G2 = gGeoManager->MakeBox("G2",pMedVac,1000.0/2.0,1000.0/2.0,1000.0/2.0); G2->SetLineColor(VacuumColor); // subtraction box for G1.
  TGeoVolume* G3 = gGeoManager->MakeBox("G3",pMedVac,20.0,45.0,300.0); G3->SetLineColor(VacuumColor); // GLAD entrace Vacuum.
  TGeoVolume* Beam = gGeoManager->MakeTube("Beam",pMedVac,0.0,8.0,300.0); Beam->SetLineColor(VacuumColor); // Beam Vacuum content.
  TGeoVolume* Target = gGeoManager->MakeBox("Target",pMedVac,12.0,12.0,2.0+TheThickness); Target->SetLineColor(VacuumColor); // Target subtraction box.
  TGeoVolume* PSP = gGeoManager->MakeBox("PSP",pMedVac,12.0,12.0,1.0); PSP->SetLineColor(VacuumColor); // PSP subtraction box.
  
  // Build proton shield:
  TGeoVolume* Pshield = gGeoManager->MakeBox("Pshield",pMedLead,30.0,150.0,400.0); // Proton shield.
  Pshield->SetLineColor(DetectorColor);
  
  // Rotate basic boxes & add them to the subtraction box:

  // transform box 2:  
  TGeoRotation* rot2 = new TGeoRotation("rot2");
  rot2->RotateX(0.0);
  rot2->RotateY(14.0);
  rot2->RotateZ(0.0);
  TGeoCombiTrans* transf2 = new TGeoCombiTrans("transf2",200.05,0.0,196.30,rot2);
  transf2->RegisterYourself();
  
  // transform box 3:  
  TGeoRotation* rot3 = new TGeoRotation("rot3");
  rot3->RotateX(0.0);
  rot3->RotateY(-24.0);
  rot3->RotateZ(0.0);
  TGeoCombiTrans* transf3 = new TGeoCombiTrans("transf3",-165.97,0.0,230.38,rot3);
  transf3->RegisterYourself();
  
  // transform box 4:  
  TGeoRotation* rot4 = new TGeoRotation("rot4");
  rot4->RotateX(0.0);
  rot4->RotateY(-35.0);
  rot4->RotateZ(0.0);
  TGeoCombiTrans* transf4 = new TGeoCombiTrans("transf4",-279.93,0.0,-116.42,rot4);
  transf4->RegisterYourself();
  
  // Transform the plates:
  
  // transform box 2:
  TGeoRotation* rotw2 = new TGeoRotation("rotw2");
  rotw2->RotateX(0.0);
  rotw2->RotateY(14.0);
  rotw2->RotateZ(0.0);
  TGeoCombiTrans* transfw2 = new TGeoCombiTrans("transfw2",173.0+2.0*(thick/2.0)*TMath::Cos(TMath::Pi()*14.0/180.0),0.0,106.7-2.0*(thick/2.0)*TMath::Sin(TMath::Pi()*14.0/180.0),rotw2);
  transfw2->RegisterYourself();
  
  // transform box 3:  
  TGeoRotation* rotw3 = new TGeoRotation("rotw3");
  rotw3->RotateX(0.0);
  rotw3->RotateY(-24.0);
  rotw3->RotateZ(0.0);
  TGeoCombiTrans* transfw3 = new TGeoCombiTrans("transfw3",-85.54-2.0*(thick/2.0)*TMath::Cos(TMath::Pi()*24.0/180.0),0.0,49.73-2.0*(thick/2.0)*TMath::Sin(TMath::Pi()*24.0/180.0),rotw3);
  transfw3->RegisterYourself();
  
  // transform box 4:  
  TGeoRotation* rotw4 = new TGeoRotation("rotw4");
  rotw4->RotateX(0.0);
  rotw4->RotateY(55.0);
  rotw4->RotateZ(0.0);
  TGeoCombiTrans* transfw4 = new TGeoCombiTrans("transfw4",-0.0-233.3-2.0*(thick/2.0)*TMath::Cos(TMath::Pi()*55.0/180.0),0.0,-81.65-2.0*(thick/2.0)*TMath::Sin(TMath::Pi()*55.0/180.0),rotw4);
  transfw4->RegisterYourself();
  
  // transform box 5:  
  TGeoRotation* rotw5 = new TGeoRotation("rotw5");
  rotw5->RotateX(0.0);
  rotw5->RotateY(0.0);
  rotw5->RotateZ(0.0);
  TGeoCombiTrans* transfw5 = new TGeoCombiTrans("transfw5",32.09,0.0,-260.32/2.0-thick/2.0,rotw5);
  transfw5->RegisterYourself();
  
  // transform box 6:  
  TGeoRotation* rotw6 = new TGeoRotation("rotw6");
  rotw6->RotateX(0.0);
  rotw6->RotateY(90.0);
  rotw6->RotateZ(0.0);
  TGeoCombiTrans* transfw6 = new TGeoCombiTrans("transfw6",532.38/2.0+thick/2.0,0.0,-23.21+thick/4.0,rotw6);
  transfw6->RegisterYourself();
  
  // transform windows:
  
  // transform neutron window:
  TGeoRotation* rotnw = new TGeoRotation("rotnw");
  rotnw->RotateX(0.0);
  rotnw->RotateY(0.0);
  rotnw->RotateZ(0.0);
  TGeoCombiTrans* transfnw = new TGeoCombiTrans("transfnw",0.0,0.0,-1.0*(thick-0.4)/2.0,rotnw);
  transfnw->RegisterYourself();
  
  // transform the pipe attributes:
  
  // transform the pipe gap (and the rest...):
  TGeoRotation* rotpg = new TGeoRotation("rotpg");
  rotpg->RotateX(0.0);
  rotpg->RotateY(20.0);
  rotpg->RotateZ(0.0);
  TGeoCombiTrans* transfpg = new TGeoCombiTrans("transfpg",140.79,0.0,0.0,rotpg);
  transfpg->RegisterYourself();
  
  // transform the subtraction plate at the bottom:
  TGeoRotation* rotpp = new TGeoRotation("rotpp");
  rotpp->RotateX(0.0);
  rotpp->RotateY(0.0);
  rotpp->RotateZ(0.0);
  TGeoCombiTrans* transfpp = new TGeoCombiTrans("transfpp",0.0,0.0,-2000.0001-0.5*thick,rotpp);
  transfpp->RegisterYourself();
  
  // Now subtract the basic boxes from the original box:
  TGeoCompositeShape* BasicChamber_shape = new TGeoCompositeShape("BasicChamber_shape","box1-box6-box2:transf2-box3:transf3-box4:transf4");
  TGeoVolume* BasicChamber = new TGeoVolume("BasicChamber",BasicChamber_shape,pMedSS);
  BasicChamber->SetLineColor(SteelColor);
  
  // Same for the vacuum content of the chamber:
  TGeoCompositeShape* BasicChamber_Content = new TGeoCompositeShape("BasicChamber_Content","box5-box2:transf2-box3:transf3-box4:transf4");
  TGeoVolume* BasicChamber_Vac = new TGeoVolume("BasicChamber_Vac",BasicChamber_Content,pMedVac);
  BasicChamber_Vac->SetLineColor(VacuumColor);
  
  // Build the neutron wall:
  TGeoCompositeShape* NeutronWall_Shape = new TGeoCompositeShape("NeutronWall_Shape","boxw2-nSubt:transfnw");
  TGeoVolume* NeutronWall = new TGeoVolume("NeutronWall",NeutronWall_Shape,pMedSS);
  NeutronWall->SetLineColor(SteelColor);
  
  // build the pipe wall:
  TGeoVolume* PipeWall;
  if (Chamber_Exists==4)
  {
    TGeoCompositeShape* PipeWall_Shape = new TGeoCompositeShape("PipeWall_Shape","boxw3-PipeGap:transfpg-boxps:transfpp"); // +Pipe:transfpg
    PipeWall = new TGeoVolume("PipeWall",PipeWall_Shape,pMedSS); 
    PipeWall->SetLineColor(SteelColor);
  }
  else
  {
    TGeoCompositeShape* PipeWall_Shape = new TGeoCompositeShape("PipeWall_Shape","boxw3-PipeGap:transfpg+Pipe:transfpg-boxps:transfpp"); // +Pipe:transfpg
    PipeWall = new TGeoVolume("PipeWall",PipeWall_Shape,pMedSS);
    PipeWall->SetLineColor(SteelColor);
  }
  
  // Build the pipe vacuum content:
  TGeoCompositeShape* PipeContent_Shape = new TGeoCompositeShape("PipeContent_Shape","PipeVac:transfpg-boxps:transfpp");
  TGeoVolume* PipeContent = new TGeoVolume("PipeContent",PipeContent_Shape,pMedVac);
  PipeContent->SetLineColor(VacuumColor);
  
  // Build the GLAD plate:
  TGeoCompositeShape* GladPlate_Shape = new TGeoCompositeShape("GladPlate_Shape","boxw5-GladSubt");
  TGeoVolume* GladPlate = new TGeoVolume("GladPlate",GladPlate_Shape,pMedSS);
  GladPlate->SetLineColor(SteelColor);
  
  // Build the Flange:
  TGeoCompositeShape* Flange_Shape = new TGeoCompositeShape("Flange_Shape","Flange:transfpg-FlangeSubt:transfpg-boxps:transfpp");
  TGeoVolume* TheFlange = new TGeoVolume("TheFlange",Flange_Shape,pMedKap);
  TheFlange->SetLineColor(KaptonColor);
  
  // Build the proton tracking system:
  Double_t Shift_From_Target = 0.0;
  TGeoCombiTrans* transfpscint = new TGeoCombiTrans("transfpscint",0.0,0.0,-17.0/2.0+Shift_From_Target,zeroRotation);
  TGeoCombiTrans* transfY2 = new TGeoCombiTrans("transfY2",0.0,0.0,-17.0-6.0/2.0+Shift_From_Target,zeroRotation);
  TGeoCombiTrans* transfX2 = new TGeoCombiTrans("transfX2",0.0,0.0,-17.0-6.0-6.0/2.0+Shift_From_Target,zeroRotation);
  TGeoCombiTrans* transfY1 = new TGeoCombiTrans("transfY1",0.0,0.0,-17.0-6.0-6.0-81.0+6.0/2.0+50.7+Shift_From_Target,zeroRotation);
  TGeoCombiTrans* transfX1 = new TGeoCombiTrans("transfX1",0.0,0.0,-17.0-6.0-6.0-81.0+6.0/2.0+Shift_From_Target,zeroRotation);
  
  transfpscint->RegisterYourself();
  transfX1->RegisterYourself();
  transfY1->RegisterYourself();
  transfX2->RegisterYourself();
  transfY2->RegisterYourself();
  
  TGeoVolume* Ptrack = new TGeoVolumeAssembly("Ptrack");
  Ptrack->AddNode(X1,1,transfX1);
  Ptrack->AddNode(Y1,1,transfY1);
  Ptrack->AddNode(X2,1,transfX2);
  Ptrack->AddNode(Y2,1,transfY2);
  Ptrack->AddNode(Pscint,1,transfpscint);
  Ptrack->SetLineColor(DetectorColor);
  
  TGeoRotation* rotptrack = new TGeoRotation("rotptrack");
  rotptrack->RotateX(0.0);
  rotptrack->RotateY(-39.5+14.0);
  rotptrack->RotateZ(0.0);
  TGeoCombiTrans* transfptrack = new TGeoCombiTrans("transfptrack",-140.0,0.0,18.0,rotptrack);
  transfptrack->RegisterYourself();
  
  // Build the fragment tracking system:
  TGeoRotation* rotftrack = new TGeoRotation("rotftrack");
  rotftrack->RotateX(0.0);
  rotftrack->RotateY(-4.0);
  rotftrack->RotateZ(0.0);
  TGeoCombiTrans* transfFtrack = new TGeoCombiTrans("transfFtrack",39.1,0.0,95.0,rotftrack);
  transfFtrack->RegisterYourself();
  
  TGeoVolume* Ftrack = new TGeoVolumeAssembly("Ftrack");
  Ftrack->AddNode(MFI,1,new TGeoCombiTrans(0.0,0.0,-20.0,zeroRotation));
  //Ftrack->AddNode(TOF,1,new TGeoCombiTrans(0.0,0.0,PipeLength+80.0,zeroRotation));
  Ftrack->SetLineColor(DetectorColor);
  
  TGeoRotation* rotaux = new TGeoRotation("rotaux");
  rotaux->RotateX(0.0);
  rotaux->RotateY(-4.0);
  rotaux->RotateZ(0.0);
  TGeoCombiTrans* transfaux = new TGeoCombiTrans("transfaux",39.1+20.0*TMath::Sin(4.0*TMath::Pi()/180.0),0.0,95.0-20.0*TMath::Cos(4.0*TMath::Pi()/180.0),rotaux);
  transfaux->RegisterYourself();
  
  // subtract the content of the chamber from the vacuum:
  TGeoCompositeShape* BasicChamber_Content_Subt = new TGeoCompositeShape("BasicChamber_Content_Subt","box5-box2:transf2-box3:transf3-box4:transf4-((X1:transfX1+Y1:transfY1+X2:transfX2+Y2:transfY2+Pscint:transfpscint):transfptrack)-(MFI:transfaux)");
  TGeoVolume* BasicChamber_Vac_Subt = new TGeoVolume("BasicChamber_Vac_Subt",BasicChamber_Content_Subt,pMedVac);
  BasicChamber_Vac_Subt->SetLineColor(VacuumColor);
  
  // Build the GLAD vacuum content:
  TGeoRotation* rotg1 = new TGeoRotation("rotg1");
  rotg1->RotateX(0.0);
  rotg1->RotateY(40.0);
  rotg1->RotateZ(0.0);
  TGeoCombiTrans* transfg1 = new TGeoCombiTrans("transfg1",-545.65,0.0,-172.47+15.0,rotg1);
  transfg1->RegisterYourself();
  
  TGeoRotation* rotg2 = new TGeoRotation("rotg2");
  rotg2->RotateX(0.0);
  rotg2->RotateY(-40.0);
  rotg2->RotateZ(0.0);
  TGeoCombiTrans* transfg2 = new TGeoCombiTrans("transfg2",545.65,0.0,-172.47+15.0,rotg2);
  transfg2->RegisterYourself();
  
  TGeoRotation* rotg3 = new TGeoRotation("rotg3");
  rotg3->RotateX(0.0);
  rotg3->RotateY(-18.0);
  rotg3->RotateZ(0.0);
  TGeoCombiTrans* transfg3 = new TGeoCombiTrans("transfg3",-604.55,0.0,64.74,rotg3);
  transfg3->RegisterYourself();
  
  TGeoRotation* rotg4 = new TGeoRotation("rotg4");
  rotg4->RotateX(0.0);
  rotg4->RotateY(18.5);
  rotg4->RotateZ(0.0);
  TGeoCombiTrans* transfg4 = new TGeoCombiTrans("transfg4",604.55,0.0,64.74,rotg4);
  transfg4->RegisterYourself();
  
  TGeoRotation* rotg5 = new TGeoRotation("rotg5");
  rotg5->RotateX(-4.0);
  rotg5->RotateY(0.0);
  rotg5->RotateZ(0.0);
  TGeoCombiTrans* transfg5 = new TGeoCombiTrans("transfg5",0.0,520.0,-500.0,rotg5);
  transfg5->RegisterYourself();
  
  TGeoRotation* rotg6 = new TGeoRotation("rotg6");
  rotg6->RotateX(4.0);
  rotg6->RotateY(0.0);
  rotg6->RotateZ(0.0);
  TGeoCombiTrans* transfg6 = new TGeoCombiTrans("transfg6",0.0,-520.0,-500.0,rotg6);
  transfg6->RegisterYourself();
  
  TGeoCombiTrans* transfv1 = new TGeoCombiTrans("transfv1",32.09-12.5,0.0,-364.26-thick,zeroRotation);
  TGeoCombiTrans* transfv2 = new TGeoCombiTrans("transfv2",32.09-12.5,0.0,-364.26-28.0-thick,zeroRotation);
  TGeoCombiTrans* transfv3 = new TGeoCombiTrans("transfv3",-1.0+32.1-12.5,0.0,-450.0,zeroRotation);
  TGeoCombiTrans* transfv4 = new TGeoCombiTrans("transfv4",-1.0+32.1-12.5,0.0,-1070.0,zeroRotation);
  
  transfv1->RegisterYourself();
  transfv2->RegisterYourself();
  transfv3->RegisterYourself();
  transfv4->RegisterYourself();
  
  TGeoRotation* rot14 = new TGeoRotation("rot14");
  rot14->RotateX(0.0);
  rot14->RotateY(14.0);
  rot14->RotateZ(0.0);
  TGeoCombiTrans* psp32 = new TGeoCombiTrans("psp32",17.0,0.0,-541.8-37.0,rot14); // z=-537.5
  psp32->RegisterYourself();
  
  TGeoCompositeShape* GLAD_shape = new TGeoCompositeShape("GLAD_shape","(G1-G2:transfg1-G2:transfg2):transfv1-(G2:transfg5+G2:transfg6)-(PSP:psp32)");
  TGeoVolume* GLAD_Vac = new TGeoVolume("GLAD_Vac",GLAD_shape,pMedVac); GLAD_Vac->SetLineColor(VacuumColor);
  TGeoCompositeShape* GLAD_shape2 = new TGeoCompositeShape("GLAD_shape2","(G1-G2:transfg3-G2:transfg4):transfv2-(G2:transfg5+G2:transfg6)-(PSP:psp32)");
  TGeoVolume* GLAD_Vac2 = new TGeoVolume("GLAD_Vac2",GLAD_shape2,pMedVac); GLAD_Vac2->SetLineColor(VacuumColor);
  TGeoCompositeShape* GLAD_shape3 = new TGeoCompositeShape("GLAD_shape3","(G3:transfv3)-(G2:transfg5+G2:transfg6+G2:transfv4)-(PSP:psp32)");
  TGeoVolume* GLAD_Vac3 = new TGeoVolume("GLAD_Vac3",GLAD_shape3,pMedVac); GLAD_Vac3->SetLineColor(VacuumColor);
  
  TGeoVolume* Gvac = new TGeoVolumeAssembly("Gvac");
  Gvac->AddNode(GLAD_Vac,1,zerotransf);
  Gvac->AddNode(GLAD_Vac2,1,zerotransf);
  Gvac->AddNode(GLAD_Vac3,1,zerotransf);
  Gvac->SetLineColor(VacuumColor);
  
  // Build the beamline from vacuum:
  TGeoCombiTrans* zshift = new TGeoCombiTrans("zshift",0.0,0.0,-100.0,zeroRotation);
  TGeoCombiTrans* targ = new TGeoCombiTrans("targ",0.0,0.0,TheZshift-37.0,zeroRotation);
  TGeoCombiTrans* psp1 = new TGeoCombiTrans("psp1",0.0,0.0,-221.0-37.0,zeroRotation);
  TGeoCombiTrans* psp2 = new TGeoCombiTrans("psp2",0.0,0.0,-89.0-37.0,zeroRotation);
  TGeoCombiTrans* psp3 = new TGeoCombiTrans("psp3",0.0,0.0,94.1-37.0,zeroRotation);
  zshift->RegisterYourself();
  targ->RegisterYourself();
  psp1->RegisterYourself();
  psp2->RegisterYourself();
  psp3->RegisterYourself();
  
  TGeoCompositeShape* BeamLineS = new TGeoCompositeShape("BeamLineS","(Beam:zshift)-(Target:targ)-(PSP:psp1)-(PSP:psp2)-(PSP:psp3)");
  TGeoVolume* BeamLine = new TGeoVolume("BeamLine",BeamLineS,pMedVac);
  BeamLine->SetLineColor(VacuumColor);
  
  TGeoRotation* rotbeam = new TGeoRotation("rotbeam");
  rotbeam->RotateX(0.0);
  rotbeam->RotateY(14.0);
  rotbeam->RotateZ(0.0);
  TGeoCombiTrans* transfbeam = new TGeoCombiTrans("transfbeam",-6.0,0.0,-633.0,rotbeam);
  transfbeam->RegisterYourself();
  
  TGeoRotation* rotshield = new TGeoRotation("rotshield");
  rotshield->RotateX(0.0);
  rotshield->RotateY(5.0);
  rotshield->RotateZ(0.0);
  TGeoCombiTrans* transfshield = new TGeoCombiTrans("transfshield",115.0,0.0,750.0,rotshield);
  transfshield->RegisterYourself();
  
  // Build the full assembly:
  TGeoVolume* Full = new TGeoVolumeAssembly("FULL");
  if (Chamber_Exists!=2)
  {
    // This if-statement is just for cosmetics. In real simulations, one should always add all elements!  
    Full->AddNode(BasicChamber,1,zerotransf); // Bottom & top plate
    Full->AddNode(BasicChamber_Vac_Subt,1,zerotransf); // Vacuum content
    Full->AddNode(GladVac,1,transfw5); // Horizontal wall vacuum
  }
  Full->AddNode(GladPlate,1,transfw5); // Horizontal wall
  Full->AddNode(boxw6,1,transfw6); // Vertical Wall
  Full->AddNode(NeutronWall,1,transfw2); // Neutron Wall
  Full->AddNode(nWindow,1,transfw2); // Neutron Window
  Full->AddNode(PipeWall,1,transfw3); // Pipe wall
  if (Chamber_Exists!=4) {Full->AddNode(PipeContent,1,transfw3);} // Pipe Content
  Full->AddNode(boxw4,1,transfw4); // Third wall.
  Full->AddNode(boxw7,1,new TGeoCombiTrans(-266.19-thick/2.0,0.0,-34.8,zeroRotation)); // Auxillary wall.
  Full->AddNode(TheFlange,1,transfw3); // Adding the end flange of the pipe.
  Full->AddNode(Ptrack,1,transfptrack); // Proton tracking system
  Full->AddNode(Ftrack,1,transfFtrack); // Fragment tracking system: MFI & TOF wall
  Full->AddNode(Gvac,1,zerotransf); // GLAD vacuum content
  Full->AddNode(BeamLine,1,transfbeam); // vacuum content of the beam line (target is cut out)
  
  if (Chamber_Exists==3)
  {
    Full->AddNode(Pshield,1,transfshield); // Proton shield.
  }
  
  // Create global transformations & add the assembly to the top:
  TGeoRotation* G_Rotation = new TGeoRotation();
  G_Rotation->RotateX(Rotation_X);
  G_Rotation->RotateY(Rotation_Y);
  G_Rotation->RotateZ(Rotation_Z);
  top->AddNode(Full,1,new TGeoCombiTrans(X_position,Y_position,Z_position,G_Rotation));

  // neutron window:
  // 4 mm stainless steel thick
  // 2 mm capton at the end of the vacuum pipe.
  
  // ======================================================================================
  // Finish our geometry & Write to a file:
  gGeoMan->CloseGeometry();
  gGeoMan->CheckOverlaps(0.001);
  gGeoMan->PrintOverlaps();
  gGeoMan->Test();
  TFile* geoFile = new TFile(geoFileName, "RECREATE");
  top->Write();
  geoFile->Close();

  // Done!
}
