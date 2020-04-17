inline void ConnectParFileToRuntimeDb(const TString parFile, FairRuntimeDb* rtdb)
{
    auto io = new FairParRootFileIo();
    io->open(parFile);
    rtdb->setFirstInput(io);
    rtdb->setOutput(io);
    rtdb->saveOutput();
}

void Read_DNN_Multiplicity(Int_t const TotalNumberOfThreads = 1)
{
    // Reads the DNN output TextFile and transmits the multiplicity to a ROOT-file.
    
    // Connect to InputsFile:
    R3BInputClass* Inputs = new R3BInputClass();
    Inputs->DisableErrorPrinting();
    Inputs->LinkFile("../InputFiles/InputsFile.txt");
    Inputs->ReadFile();
        
    // Retrieve General Inputs:
    TString TheOutputPath = Inputs->GetInputString("TheOutputPath");
    TString MCFile = TheOutputPath + Inputs->GetInputString("R3BRoot_MonteCarlo_OutputFile");
    TString ParFile = TheOutputPath + Inputs->GetInputString("R3BRoot_MonteCarlo_ParFile");
    TString VisFile = TheOutputPath + Inputs->GetInputString("R3BRoot_MonteCarlo_PlotFile");
    TString DigiFile = TheOutputPath + Inputs->GetInputString("NeuLAND_Digitizer_OutputFile");
    TString JanFile = TheOutputPath + Inputs->GetInputString("NeuLAND_Digitizer_JanMayer_Processing");
    TString SignalFile = TheOutputPath + Inputs->GetInputString("NeuLAND_SignalFile");
    TString ClusterFile = TheOutputPath + Inputs->GetInputString("NeuLAND_ClusterFile");
    TString FilteredFile = TheOutputPath + Inputs->GetInputString("NeuLAND_FilteredClusterFile");
    TString TradMedFile = TheOutputPath + Inputs->GetInputString("NeuLAND_TraditionalMethod_ReconstructionFile");
    TString ScoreFile = TheOutputPath + Inputs->GetInputString("NeuLAND_ScoringOutputFile");
    TString DNNScoreFile = TheOutputPath + Inputs->GetInputString("NeuLAND_DNNScoringOutputFile");
    TString DistFile = TheOutputPath + Inputs->GetInputString("NeuLAND_Distributions");
    TString DNNFile = TheOutputPath + Inputs->GetInputString("NeuLAND_DNN_OutputFile");
    TString FinalFile = TheOutputPath + Inputs->GetInputString("NeuLAND_Reconstruction_FinalFile");
    TString BetaFile = TheOutputPath + Inputs->GetInputString("BetaReconstruction_OutputFile");
    TString SingleFile = TheOutputPath + Inputs->GetInputString("SingleReconstruction_OutputFile");
    TString CombiFile = TheOutputPath + Inputs->GetInputString("NEBULA_Combination_OutputFile");
    Int_t nEvents = Inputs->GetInputInteger("R3BRoot_nEvents");
    Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    
    // Corrent the number of events for MT effects:
    if (TotalNumberOfThreads>1)
    {
        nEvents = nEvents/TotalNumberOfThreads;
        nEvents = nEvents*TotalNumberOfThreads;
    }
    
    // Then, execute the first macro for retrieving the signals:
    if (Inputs->ContainsNoErrors()==kTRUE)
    {
        // Activate the timer:
        TStopwatch timer;
        timer.Start();

        // Create the Master FairTask:
        FairRunAna* run = new FairRunAna();
        run->SetInputFile(SignalFile);
        run->AddFriend(ClusterFile);
        run->SetOutputFile(DNNFile);
        ConnectParFileToRuntimeDb(ParFile,run->GetRuntimeDb());
  
        // Create the reading class:
        R3BMultReader* TheMultReader = new R3BMultReader();
        TheMultReader->LinkInputClass(Inputs);
        TheMultReader->SetNevents(nEvents);
        TheMultReader->SetDetector("NeuLAND");
        
        // Add it to the Mother FairTask:
        run->AddTask(TheMultReader);
        
        if (UseNEBULA==kTRUE)
        {
            R3BMultReader* TheNEBMultReader = new R3BMultReader();
            TheNEBMultReader->LinkInputClass(Inputs);
            TheNEBMultReader->SetNevents(nEvents);
            TheNEBMultReader->SetDetector("NEBULA");
            run->AddTask(TheNEBMultReader);
        }

        // Run the FairTask:
        run->Init();
        run->Run(0,nEvents);

        // Finish the timer:
        timer.Stop();

        // Give final output:
        cout << endl;
        cout << "Macro finished succesfully!" << endl;
        cout << "Output file written: " << SignalFile << endl;
        cout << "Parameter file written: " << ParFile << endl;
        cout << "Real time: " << timer.RealTime() << "s, CPU time: " << timer.CpuTime() << "s" << endl;
        cout << endl;
    }
    else
    {
        // Then, print what has gone wrong:
        Inputs->PrintAllErrors();
    }

    // Done.
}
