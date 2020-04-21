inline void ConnectParFileToRuntimeDb(const TString parFile, FairRuntimeDb* rtdb)
{
    auto io = new FairParRootFileIo();
    io->open(parFile);
    rtdb->setFirstInput(io);
    rtdb->setOutput(io);
    rtdb->saveOutput();
}

void ApplyVETOCondition(Int_t const TotalNumberOfThreads = 1)
{
    // Converts the reconstruction results back into the original files.
    
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
    TString VETOFile = TheOutputPath + "/NeuLAND_VETO_Conditions.root";
    Int_t nEvents = Inputs->GetInputInteger("R3BRoot_nEvents");
    Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    Bool_t UseVETO = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    
    // Corrent the number of events for MT effects:
    if (TotalNumberOfThreads>1)
    {
        nEvents = nEvents/TotalNumberOfThreads;
        nEvents = nEvents*TotalNumberOfThreads;
    }
    
    // Then, execute the first macro for retrieving the signals:
    if ((Inputs->ContainsNoErrors()==kTRUE)&&(UseVETO==kTRUE))
    {
        // Activate the timer:
        TStopwatch timer;
        timer.Start();

        // Create the Master FairTask:
        FairRunAna* run = new FairRunAna();
        run->SetInputFile(SignalFile);
        run->AddFriend(FinalFile);
        run->SetOutputFile(VETOFile);
        ConnectParFileToRuntimeDb(ParFile,run->GetRuntimeDb());
  
        // Create the VETO class:
        R3BVETO* TheVETO = new R3BVETO();
        TheVETO->LinkInputClass(Inputs);
        TheVETO->SetNevents(nEvents);
        TheVETO->SetBranchName("TheNeutronTracks");
        run->AddTask(TheVETO);
        
        R3BVETO* VETO1 = new R3BVETO();
        VETO1->LinkInputClass(Inputs);
        VETO1->SetNevents(nEvents);
        VETO1->SetBranchName("NeutronTracks_TradMed_Clusters_CutsMult");
        run->AddTask(VETO1);
        
        R3BVETO* VETO2 = new R3BVETO();
        VETO2->LinkInputClass(Inputs);
        VETO2->SetNevents(nEvents);
        VETO2->SetBranchName("NeutronTracks_DNNScoringPlus_SingleTOF");
        run->AddTask(VETO2);
        
        R3BVETO* VETO3 = new R3BVETO();
        VETO3->LinkInputClass(Inputs);
        VETO3->SetNevents(nEvents);
        VETO3->SetBranchName("NeutronTracks_DNNScoringPlus");
        run->AddTask(VETO3);
        
        R3BVETO* VETO4 = new R3BVETO();
        VETO4->LinkInputClass(Inputs);
        VETO4->SetNevents(nEvents);
        VETO4->SetBranchName("NeutronTracks_ScoringPlus_Clusters_DNNMult");
        run->AddTask(VETO4);
        
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
        if (UseVETO==kTRUE)
        {
            Inputs->PrintAllErrors();
        }
        else
        {
            cout << "This macro cannot run if there is no VETO in the setup!\n\n";
        }
    }

    // Done.
}
