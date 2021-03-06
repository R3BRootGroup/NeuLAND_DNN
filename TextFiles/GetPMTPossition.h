// Function to extract the position coordinate from a signal that is
// determined from the differences of the PMT times, taking global
// positioning of the detector into account.
Double_t R3BTextFileGenerator::GetPMTPossition(R3BSignal* ThisSignal)
{
    // Declare the Answers:

    // Begin by declaring new points & shifting. We will do exactly the reverse of the geometry
    // building file:
    Double_t xpoint = ThisSignal->GetPositionX() - NeuLAND_Center_X; 
    Double_t ypoint = ThisSignal->GetPositionY() - NeuLAND_Center_Y; 
    Double_t zpoint = ThisSignal->GetPositionZ() - NeuLAND_Front_Z - NeuLAND_TotalBarThicknessZ*((Int_t) NDoublePlanes); 
    
    // Take care of separate modules:
    Double_t nGabs_d = (Int_t) NDoublePlanes;
    nGabs_d = nGabs_d/((Int_t) NPlanesPerModule);
    nGabs_d = nGabs_d - 0.0001;
    Int_t nGabs = (Int_t) nGabs_d;
    zpoint = zpoint - 0.5*DistanceBetweenModules*((Int_t) nGabs);

    // Now, NeuLAND is in the origin. Anti-rotate:
    TVector3 pos;
    pos.SetX(xpoint);
    pos.SetY(ypoint);
    pos.SetZ(zpoint);
    
    pos.RotateZ(-1.0*NeuLAND_Rot_Z*TMath::Pi()/180.0);
    pos.RotateY(-1.0*NeuLAND_Rot_Y*TMath::Pi()/180.0);
    pos.RotateX(-1.0*NeuLAND_Rot_X*TMath::Pi()/180.0);
    
    xpoint = pos.X();
    ypoint = pos.Y();
    zpoint = pos.Z();
    
    // Now, NeuLAND is at the origin. next, shift so that z starts at zero:
    zpoint = zpoint + NeuLAND_TotalBarThicknessZ*((Int_t) NDoublePlanes);
    zpoint = zpoint + 0.5*DistanceBetweenModules*((Int_t) nGabs);
    
    // Next, extract whether we have a horizontal bar or not:
    Bool_t IsHorizontal = ThisSignal->IsHorPaddle("NeuLAND",NbarsPerPlane);
    
    // Then, make a decision:
    Double_t ThePosition = 0.0;
    if (IsHorizontal==kTRUE)  {ThePosition = xpoint;}
    if (IsHorizontal==kFALSE) {ThePosition = ypoint;}
    if (ThisDetector=="NEBULA") {ThePosition = ypoint;}
    
    // return the answer:
    return ThePosition;
}
