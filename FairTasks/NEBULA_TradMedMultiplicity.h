// This header contains the functions to determine the
// multiplicity of the traditional method reconstruction
// using D. Kresans method for multi neutron simulations.
// ==> It uses the traditional cuts.

// Function to read the calibration files:
void R3B_TradMed_NeutronTracker::ReadNEBULACalibrationFile()
{
    // Reset the boolian tag:
    UseNEBULACalibrationCuts = kFALSE;
    
    // Obtain the filename:
    TString FileName = Inputs->GetInputString("TheOutputPath");
    FileName = FileName + "/NEBULA_CutsFile.txt";
    
    // Declare an ifstream to read the file:
    ifstream ThisFile;
  
    // Begin by determining the size of the file:
    Int_t NLines = 0;
    std::string ThisLine;
    ThisFile.open(FileName.Data());
  
    if (!(ThisFile.is_open()))
    {
        std::cout << "### NEUTRON TRACKER ERROR: No NEBULA calibration file found!\n\n";
        UseNEBULACalibrationCuts = kFALSE;
    }
    else
    { 
        while (std::getline(ThisFile,ThisLine)) {NLines = NLines + 1;}
      
        // See if the file is suitable for our situation:
        if (MaxMultiplicity==(NLines-1))
        {
            // Then, we are OK. so generate the array that holds the cuts:
            fNEBCuts = new Double_t[MaxMultiplicity];
      
            // Close and re-open the file:
            ThisFile.close();
            ThisFile.open(FileName.Data());
      
            // Read from the file:
            ThisFile >> fNEBKappa;
      
            for (Int_t kE = 0; kE<MaxMultiplicity; ++kE)
            {
                // Move to the next line:
                std::getline(ThisFile,ThisLine);
          
                // read the next number:
                ThisFile >> fNEBCuts[kE];
            }
      
            // Next, close the file again:
            ThisFile.close();
      
            // give some output:
            cout << "-I- R3B_TradMed_NeutronTracker: Max. NEBULA Multiplicity = " << MaxMultiplicity << "\n"
                 << "                               NEBULA Kappa             = " << fNEBKappa << "\n";
     
            for (Int_t kE = 0; kE<MaxMultiplicity; ++kE)
            {
                cout << "                               NEBULA fCuts[" << kE << "]          = " << fNEBCuts[kE] << "\n";
            }
      
            cout << "\n";
       
            // done.
            UseNEBULACalibrationCuts = kTRUE;
        }
        else
        {
            cout << "### ERROR: R3B_TradMed_NeutronTracker: The file holding the NEBULA calibration-cuts does not correspond to the current max. multiplicity in the Inputs-file!\n\n";
        }
    }
}

// Function to apply the calibration cuts inside the Exec-function:
Int_t R3B_TradMed_NeutronTracker::ApplyNEBULACalibrationCuts()
{
    // Declare the answer:
    Int_t TheMultiplicity = -1;
    
    // Next, check that we can actually use our cuts:
    if (UseNEBULACalibrationCuts==kTRUE)
    {
        // Begin by obtaining the total amount of clusters:
        Int_t nClusters = fArrayCluster->GetEntries();
        Double_t nClusters_d = ((Int_t) nClusters) + 0.5; // NOTE: Optimization is also done on bin centers, not on the lower part of the bins!
  
        // Next, obtain the total amount of energy:
        R3BSignalCluster* ThisCluster;
        Double_t Etotal = 0.0;
  
        for (Int_t k = 0; k<nClusters; k++) 
        {
            // Retrieve the current cluster:
            ThisCluster = (R3BSignalCluster*) fArrayCluster->At(k);
            
            // And add its energy to the total:
            Etotal = Etotal + ThisCluster->GetEnergy();
        }
        

        // We have nClusters_d and nClusters_d which hold the point in the histogram. now we need to decide
        // between which cuts we are. The cuts are defined as y = fNEBKappa*(fNEBCuts[k] - x).
        // So compute Y for 2 successive cuts and see if nClusters_d is between them.
        
        // Track the two cuts were we are between:
        Int_t LowerCutIndex = -1;
        Int_t UpperCutIndex = -1;
        
        if (nClusters_d<(-1.0*TMath::Abs(fNEBKappa)*(Etotal-fNEBCuts[0])))
        {
            // Then we are below the lowest cut:
            TheMultiplicity = 0;
            LowerCutIndex = -1;
            UpperCutIndex = 0;
        }
        else if (nClusters_d>(-1.0*TMath::Abs(fNEBKappa)*(Etotal-fNEBCuts[MaxMultiplicity-1])))
        {
            // Then we are above the highest cut:
            TheMultiplicity = MaxMultiplicity;
            LowerCutIndex = MaxMultiplicity-1;
            UpperCutIndex = -1;
        }
        else
        {
            if (MaxMultiplicity>=2)
            {
                for (Int_t Range = 1; Range<MaxMultiplicity; ++Range)
                {
                    if ((nClusters_d>(-1.0*TMath::Abs(fNEBKappa)*(Etotal-fNEBCuts[Range-1])))&&(nClusters_d<(-1.0*TMath::Abs(fNEBKappa)*(Etotal-fNEBCuts[Range]))))
                    {
                        TheMultiplicity = Range;
                        LowerCutIndex = Range-1;
                        UpperCutIndex = Range;
                    }
                }
            }
            else
            {
                std::cout << "### R3B_TradMed_NeutronTracker: SERIOUS ERROR IN APPLYING THE NEBULA CUTS!!!\n\n";
            }
        }
        
        // Next, if needed, apply a harder criterium:
        if ((TradeEff_for_Acc==kTRUE)&&(TheMultiplicity==Acc_Selected_Multiplicity))
        {
            // Then, determine if the energy differences are large enough:
            Double_t LowerDeltaE = -1.0;
            Double_t UpperDeltaE = -1.0;
            Double_t Etotal_Projected = Etotal + nClusters_d/TMath::Abs(fNEBKappa);
            
            if (LowerCutIndex>=0)
            {
                // Compute energy difference:
                LowerDeltaE = TMath::Abs(fNEBCuts[LowerCutIndex] - Etotal_Projected);
            }
            
            if (UpperCutIndex>=0)
            {
                // Compute energy difference:
                UpperDeltaE = TMath::Abs(fNEBCuts[UpperCutIndex] - Etotal_Projected);
            }
            
            // Next, decide about our cases:
            if (LowerCutIndex==-1)
            {
                // Then, we are below the lowest cut:
                if (UpperDeltaE<Acc_EnergyThreshold)
                {
                    // Then, we must modify the multiplicity:
                    TheMultiplicity = TheMultiplicity + 1;
                }
            }
            else if (UpperCutIndex==-1)
            {
                // Then, we are above the highest cut:
                if (LowerDeltaE<Acc_EnergyThreshold)
                {
                    // Then, we must modify the multiplicity:
                    TheMultiplicity = TheMultiplicity - 1;
                }
            }        
            else
            {
                // then, we are between two cuts:
                if ((UpperDeltaE<Acc_EnergyThreshold)&&(LowerDeltaE>Acc_EnergyThreshold))
                {
                    // Then, raise multiplicity:
                    TheMultiplicity = TheMultiplicity + 1;
                }
                else if ((LowerDeltaE<Acc_EnergyThreshold)&&(UpperDeltaE>Acc_EnergyThreshold))
                {
                    // Then, lower multiplicity:
                    TheMultiplicity = TheMultiplicity - 1;
                }
                else if ((UpperDeltaE<Acc_EnergyThreshold)&&(LowerDeltaE<Acc_EnergyThreshold))
                {
                    // Them we are too close to both cuts. That just does not make any sense:
                    TheMultiplicity = 0;
                }
                else
                {
                    // Then, we are far enough from both cuts. So do not change a thing.
                }
            }
        }
        
        // Adjust the special cases:
        if (nClusters==0) {TheMultiplicity = 0;}
        // NOTE: No forced Mult==1 when nClusters==1!
    }
    
    // Done. Return the answer:
    return TheMultiplicity;
}
    
