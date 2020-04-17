void MergeDetectionEffFile(Int_t const TotalNumberOfThreads = 1, Bool_t const NEBULAFLAG = kFALSE)
{
    // This file merges detection efficiency files so that the
    // biasing of the TextFileGenerator can also be done in Single-thread mode:
    
    if (TotalNumberOfThreads>1)
    {
        // Begin by connecting to the InputsFile:
        R3BInputClass* Inputs = new R3BInputClass();
        Inputs->DisableErrorPrinting();
        Inputs->LinkFile("../InputFiles/InputsFile.txt");
        Inputs->ReadFile();
    
        // Retrieve the required inputs:
        TString TheOutputPath = Inputs->GetInputString("TheOutputPath");
        Int_t MaxMultiplicity = Inputs->GetInputInteger("ParticleGun_Multiplicity");
    
        // Build the proper filenames:
        TString FileNameBasis;
        if (NEBULAFLAG==kFALSE) {FileNameBasis = TheOutputPath + "/Detection_Efficiency";}
        else                    {FileNameBasis = TheOutputPath + "/NEBULA_Detection_Efficiency";}
        TString NewFileName = FileNameBasis + ".txt";
        TString CurrentFileName = "";
    
        // Declare required arrays:
        Double_t* SumArray = new Double_t[MaxMultiplicity+1];
        Double_t* ThisArray = new Double_t[MaxMultiplicity+1];
    
        for (Int_t k = 0; k<(MaxMultiplicity+1); ++k)
        {
            SumArray[k] = 0.0;
            ThisArray[k] = 0.0;
        }
    
        // Now, read all files on-by-one:
        ifstream ThisFile;
        TString st = "";
        TString kstr = "";
        TString nstr = st.Itoa(TotalNumberOfThreads,10);
        
        for (Int_t k = 0; k<TotalNumberOfThreads; ++k)
        {
            // Build the current FileName:
            kstr = st.Itoa(k,10);
            CurrentFileName = FileNameBasis + "_nT" + nstr + "_cT" + kstr + ".txt";
            
            // Open the file:
            ThisFile.open(CurrentFileName.Data());
            
            if (!(ThisFile.is_open()))
            {
                cout << "### FATAL: FILE = " << CurrentFileName << " DOES NOT EXIST!\n";
            }
            else
            {
                // Then, read from it:
                for (Int_t ii = 0; ii<(MaxMultiplicity+1); ++ii)
                {
                    ThisFile >> ThisArray[ii];
                    SumArray[ii] = SumArray[ii] + ThisArray[ii];
                }
                
                // Done. close the file:
                ThisFile.close();
            }
            
            // Finish the loop over the threads:
        }
        
        // Compute the average:
        for (Int_t k = 0; k<(MaxMultiplicity+1); ++k)
        {
            SumArray[k] = SumArray[k]/((Int_t) TotalNumberOfThreads);
        }
        
        // Write this to a new file:
        std::ofstream NewFile (NewFileName.Data(), std::ofstream::out);
        for (Int_t k = 0; k<(MaxMultiplicity+1); ++k)
        {
            NewFile << SumArray[k] << "\n";
        }
        NewFile.close();
        
        // Done.
        delete[] SumArray;
        delete[] ThisArray;
    }
}
