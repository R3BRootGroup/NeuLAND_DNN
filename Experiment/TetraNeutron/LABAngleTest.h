Bool_t InvMass_4n::LABAngleTest(TClonesArray* TheMCTrackArray, TClonesArray* TheRecTrackArray)
{
    // Test whether for all neutron tracks, there is an MC neutron track with an angle
    // between them smaller than the threshold. MC tracks cannot be re-used.
    
    // Declare the default answer:
    Bool_t Answer = kFALSE;
    
    // If no tracks exist, we cannot run this algorithm:
    if ((TheMCTrackArray->GetEntries()>0)&&(TheRecTrackArray->GetEntries()>0))
    {
        // Begin with the declaration of an allowance-array for TheMCTrackArray. We do 
        // know for sure that TheMCTrackArray only contains neutrons, so:
        Int_t MCSize = (Int_t) TheMCTrackArray->GetEntries();
        if (MCSize>MaxMultiplicity) {MCSize = MaxMultiplicity;}
        Bool_t* MC_IsUsed = new Bool_t[MCSize];
        for (Int_t k = 0; k<MCSize; ++k) {MC_IsUsed[k] = kFALSE;}
    
        // Next, declare an array whether the neutron tracks are below the threshold:
        Int_t RecSize = (Int_t) TheRecTrackArray->GetEntries();
        if (RecSize>MaxMultiplicity) {RecSize = MaxMultiplicity;}
        Bool_t* RecTest_IsOK = new Bool_t[RecSize];
        for (Int_t k = 0; k<MCSize; ++k) {RecTest_IsOK[k] = kFALSE;}
    
        // Then, declare other stuff that we need:
        TLorentzVector* ThisRecTrack;
        TLorentzVector* ThisMCTrack;
        Double_t MCpx, MCpy, MCpz;
        Double_t Recpx, Recpy, Recpz;
        Double_t Inproduct;
        Double_t ThisLABAngle;
        Int_t MinMCIndex;
        Double_t MinLABAngle;
    
        // And make our loop. First the Rec-tracks:
        for (Int_t krec = 0; krec<RecSize; ++krec)
        {
            // Retrieve the current Rec-track:
            ThisRecTrack = (TLorentzVector*) TheRecTrackArray->At(krec);
            
            // Retrieve components:
            Recpx = ThisRecTrack->X();
            Recpy = ThisRecTrack->Y();
            Recpz = ThisRecTrack->Z();
            
            // Reset minimum:
            MinLABAngle = 1e99;
            MinMCIndex = -1;
            
            // Loop over the MC tracks:
            for (Int_t kMC = 0; kMC<MCSize; ++kMC)
            {
                // First, check whether this track was used already:
                if (MC_IsUsed[kMC]==kFALSE)
                {
                    // then, we can proceed safely. Retrieve the MC-track:
                    ThisMCTrack = (TLorentzVector*) TheMCTrackArray->At(kMC);
                    
                    // And the components:
                    MCpx = ThisMCTrack->X();
                    MCpy = ThisMCTrack->Y();
                    MCpz = ThisMCTrack->Z();
                    
                    // Next, obtain the current angle:
                    Inproduct = MCpx*Recpx + MCpy*Recpy + MCpz*Recpz;
                    Inproduct = Inproduct/TMath::Sqrt(MCpx*MCpx + MCpy*MCpy + MCpz*MCpz);
                    Inproduct = Inproduct/TMath::Sqrt(Recpx*Recpx + Recpy*Recpy + Recpz*Recpz);
                    ThisLABAngle = TMath::ACos(Inproduct);
                    ThisLABAngle = ThisLABAngle*180.0/TMath::Pi();
                    
                    // And search for the minimum:
                    if (ThisLABAngle<MinLABAngle)
                    {
                        MinMCIndex = kMC;
                        MinLABAngle = ThisLABAngle;
                    }
                    
                    // Close MC-loop:
                }
            }
        
            // Then, perform the test:
            if ((MinMCIndex<0)||(MinMCIndex>=MCSize))
            {
                // then, no min. was found because either multiplicity is zero, or all tracks
                // were used already. Anyway, the angle-test failed:
                RecTest_IsOK[krec] = kFALSE;
            }
            else
            {
                // then, we found a minimum. check if it is below the boundary:
                if (MinLABAngle<LABMaxTargetAngle)
                {
                    // then, this track passed its test:
                    RecTest_IsOK[krec] = kTRUE;
                    
                    // But then, the corresponding MC track should be blocked in future searches,
                    // because it is taken:
                    MC_IsUsed[MinMCIndex] = kTRUE;
                }
                else
                {
                    // then, we did find a minimum, but it failed the threshold,
                    // so the rec-track is marked as failure, but the MC track should
                    // stay available for future searches:
                    RecTest_IsOK[krec] = kFALSE;
                }
            }
        }
   
        // Next, we can compose the answer. Our test only passes if all Rec-tracks are OK.
        Answer = kTRUE;
    
        for (Int_t krec = 0; krec<RecSize; ++krec)
        {
            if (RecTest_IsOK[krec]==kFALSE)
            {
                Answer = kFALSE;
            }
        }
    
        // Next, delete all arrays
        delete MC_IsUsed;
        delete RecTest_IsOK;
    }
    
    // And, return the answer:
    return Answer;
}
        
