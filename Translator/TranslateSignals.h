void R3BNeuLANDTranslator::TranslateSignals(TClonesArray* fDigiArray, TClonesArray* fSignalArray)
{
    // This function fills the TClonesArray fSignalArray
    // by using fDigiArray. It is a simple 1-1 corespondance.
    // Both the Simulation and the Experimental markings of the
    // signals will be put to kFALSE. These markings 
    // have to be dealt with by different functions.
    Int_t nDigis = fDigiArray->GetEntries();
    
    // Decide which digis get broken:
    Bool_t* BrokenChannels = new Bool_t [nDigis];
    Double_t RandomNumber;
    
    // Loop over all digis:
    for (Int_t k = 0; k<nDigis; ++k)
    {
        // Default: channels stay alive.
        BrokenChannels[k] = kFALSE;
        
        // Only break when we want to and when we are in validation mode:
        if ((BreakChannels==kTRUE)&&(ValidationMode==kTRUE))
        {
            // Decide upon breaking:
            RandomNumber = TheGenerator->Uniform(1.0);
            if (RandomNumber<BreakProbability) {BrokenChannels[k] = kTRUE;}
        }
    }
    
    // Start translating:
    if (nDigis==0) {} // If there are no signals, it is pointless to process them!
    else 
    {
        // Declare what we need to process the information 1-by-1:
        R3BNeulandDigi* Digi;
        R3BSignal* Signal;
        TVector3 Position;
        Double_t Energy;
        Double_t Time;
        Int_t Paddle;
        Int_t SignalIndex = 0;
        
        // Next, loop over the digis:
        for (Int_t k = 0; k<nDigis; ++k)
        {
            // Decide if the digi is broken or not:
            if (BrokenChannels[k]==kFALSE)
            {
                // Then, create the new signal:
                new ((*fSignalArray)[SignalIndex]) R3BSignal();
        
                // Retrieve individual digi and signal:
                Digi = (R3BNeulandDigi*) fDigiArray->At(k);
                Signal = (R3BSignal*) fSignalArray->At(SignalIndex);
        
                // And next, retrieve digi info:
                Position = Digi->GetPosition();
                Energy = Digi->GetE();
                Time = Digi->GetT();
                Paddle = Digi->GetPaddle(); // NOTE: ranges from 1-3000!
            
                // Check that it indeed starts at 1 and ends at 3000:
                if (Paddle<=0) {cout << "### NeuLANDTranslator-Error: Paddle index was interpreted wrong!\n";}
                if (Paddle>nDoublePlanes*nPaddlesPerPlane*2) {cout << "### NeuLANDTranslator-Error: Paddle index found to be too large!\n";}
        
                // And put this into the signal:
                Signal->SetPositionX(Position.X());
                Signal->SetPositionY(Position.Y());
                Signal->SetPositionZ(Position.Z());
                Signal->SetTime(Time);
                Signal->SetEnergy(Energy);
                Signal->SetCrystalIndex(Paddle);
        
                // Set default labels:
                Signal->SetNonPrimarySim();
                Signal->SetNonPrimaryExp();
                
                // Update SignalIndex:
                SignalIndex = SignalIndex + 1;
            }
            else
            {
                if (DisplayBreaks==kTRUE)
                {
                    Digi = (R3BNeulandDigi*) fDigiArray->At(k);
                    cout << "We broke Channel " << Digi->GetPaddle() << " in event " << EventCounter << " Prob = " << BreakProbability << "\n";
                }
            }
        }
    }
    
    // delete break-array:
    delete BrokenChannels;
}
