inline void ConnectParFileToRuntimeDb(const TString parFile, FairRuntimeDb* rtdb)
{
    auto io = new FairParRootFileIo();
    io->open(parFile);
    rtdb->setFirstInput(io);
    rtdb->setOutput(io);
    rtdb->saveOutput();
}

void CombineReconstructions(Int_t const TotalNumberOfThreads = 1)
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
    Int_t nEvents = Inputs->GetInputInteger("R3BRoot_nEvents");
    Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    
    // Corrent the number of events for MT effects:
    if (TotalNumberOfThreads>1)
    {
        nEvents = nEvents/TotalNumberOfThreads;
        nEvents = nEvents*TotalNumberOfThreads;
    }
    
    // Then, execute the first macro for retrieving the signals:
    if ((Inputs->ContainsNoErrors()==kTRUE)&&(UseNEBULA==kTRUE))
    {
        // Activate the timer:
        TStopwatch timer;
        timer.Start();

        // Create the Master FairTask:
        FairRunAna* run = new FairRunAna();
        run->SetInputFile(SignalFile);
        run->AddFriend(ClusterFile);
        run->AddFriend(TradMedFile);
        run->AddFriend(ScoreFile);
        run->AddFriend(DNNScoreFile);
        run->AddFriend(BetaFile);
        run->AddFriend(SingleFile);
        run->SetOutputFile(CombiFile);
        ConnectParFileToRuntimeDb(ParFile,run->GetRuntimeDb());
  
        // Create the Combiners:
        R3BNEBULACombiner* Combiner_01 = new R3BNEBULACombiner();
        Combiner_01->LinkInputClass(Inputs);
        Combiner_01->SetNevents(nEvents);
        Combiner_01->SetObjects("Signals");
        Combiner_01->SetBranchName("Signals");
        Combiner_01->ReleaseMultiplicityLimit();
        run->AddTask(Combiner_01);
        
        R3BNEBULACombiner* Combiner_02 = new R3BNEBULACombiner();
        Combiner_02->LinkInputClass(Inputs);
        Combiner_02->SetNevents(nEvents);
        Combiner_02->SetObjects("Clusters");
        Combiner_02->SetBranchName("Clusters");
        Combiner_02->ReleaseMultiplicityLimit();
        run->AddTask(Combiner_02);
        
        R3BNEBULACombiner* Combiner_03 = new R3BNEBULACombiner();
        Combiner_03->LinkInputClass(Inputs);
        Combiner_03->SetNevents(nEvents);
        Combiner_03->SetObjects("Signals");
        Combiner_03->SetBranchName("PrimaryHits_TradMed_Clusters_CutsMult");
        Combiner_03->SetMultiplicityLimit();
        run->AddTask(Combiner_03);

        R3BNEBULACombiner* Combiner_04 = new R3BNEBULACombiner();
        Combiner_04->LinkInputClass(Inputs);
        Combiner_04->SetNevents(nEvents);
        Combiner_04->SetObjects("Signals");
        Combiner_04->SetBranchName("PrimaryHits_TradMed_Clusters_DNNMult");
        Combiner_04->SetMultiplicityLimit();
        run->AddTask(Combiner_04);
        
        R3BNEBULACombiner* Combiner_05 = new R3BNEBULACombiner();
        Combiner_05->LinkInputClass(Inputs);
        Combiner_05->SetNevents(nEvents);
        Combiner_05->SetObjects("Signals");
        Combiner_05->SetBranchName("PrimaryHits_TradMed_Clusters_PerfectMult");
        Combiner_05->SetMultiplicityLimit();
        run->AddTask(Combiner_05);
        
        R3BNEBULACombiner* Combiner_06 = new R3BNEBULACombiner();
        Combiner_06->LinkInputClass(Inputs);
        Combiner_06->SetNevents(nEvents);
        Combiner_06->SetObjects("Signals");
        Combiner_06->SetBranchName("PrimaryHits_ScoringPlus_Signals_CutsMult");
        Combiner_06->SetMultiplicityLimit();
        run->AddTask(Combiner_06);
        
        R3BNEBULACombiner* Combiner_07 = new R3BNEBULACombiner();
        Combiner_07->LinkInputClass(Inputs);
        Combiner_07->SetNevents(nEvents);
        Combiner_07->SetObjects("Signals");
        Combiner_07->SetBranchName("PrimaryHits_ScoringPlus_Signals_DNNMult");
        Combiner_07->SetMultiplicityLimit();
        run->AddTask(Combiner_07);
        
        R3BNEBULACombiner* Combiner_08 = new R3BNEBULACombiner();
        Combiner_08->LinkInputClass(Inputs);
        Combiner_08->SetNevents(nEvents);
        Combiner_08->SetObjects("Signals");
        Combiner_08->SetBranchName("PrimaryHits_ScoringPlus_Signals_PerfectMult");
        Combiner_08->SetMultiplicityLimit();
        run->AddTask(Combiner_08);
        
        R3BNEBULACombiner* Combiner_09 = new R3BNEBULACombiner();
        Combiner_09->LinkInputClass(Inputs);
        Combiner_09->SetNevents(nEvents);
        Combiner_09->SetObjects("Signals");
        Combiner_09->SetBranchName("PrimaryHits_ScoringPlus_Clusters_CutsMult");
        Combiner_09->SetMultiplicityLimit();
        run->AddTask(Combiner_09);
        
        R3BNEBULACombiner* Combiner_10 = new R3BNEBULACombiner();
        Combiner_10->LinkInputClass(Inputs);
        Combiner_10->SetNevents(nEvents);
        Combiner_10->SetObjects("Signals");
        Combiner_10->SetBranchName("PrimaryHits_ScoringPlus_Clusters_DNNMult");
        Combiner_10->SetMultiplicityLimit();
        run->AddTask(Combiner_10);
        
        R3BNEBULACombiner* Combiner_11 = new R3BNEBULACombiner();
        Combiner_11->LinkInputClass(Inputs);
        Combiner_11->SetNevents(nEvents);
        Combiner_11->SetObjects("Signals");
        Combiner_11->SetBranchName("PrimaryHits_ScoringPlus_Clusters_PerfectMult");
        Combiner_11->SetMultiplicityLimit();
        run->AddTask(Combiner_11);
        
        R3BNEBULACombiner* Combiner_12 = new R3BNEBULACombiner();
        Combiner_12->LinkInputClass(Inputs);
        Combiner_12->SetNevents(nEvents);
        Combiner_12->SetObjects("Signals");
        Combiner_12->SetBranchName("PrimaryHits_DNNScoringPlus");
        Combiner_12->SetMultiplicityLimit();
        run->AddTask(Combiner_12);
        
        R3BNEBULACombiner* Combiner_13 = new R3BNEBULACombiner();
        Combiner_13->LinkInputClass(Inputs);
        Combiner_13->SetNevents(nEvents);
        Combiner_13->SetObjects("Signals");
        Combiner_13->SetBranchName("PrimaryHits_DNNScoringPlus_SingleTOF");
        Combiner_13->SetMultiplicityLimit();
        run->AddTask(Combiner_13);
        
        R3BNEBULACombiner* Combiner_14 = new R3BNEBULACombiner();
        Combiner_14->LinkInputClass(Inputs);
        Combiner_14->SetNevents(nEvents);
        Combiner_14->SetObjects("Signals");
        Combiner_14->SetBranchName("PrimaryHits_DNNScoringPlus_Max");
        Combiner_14->SetMultiplicityLimit();
        run->AddTask(Combiner_14);

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
        if (UseNEBULA==kFALSE)
        {
            cout << "No problem, but without NEBULA this step should simply be skipped.\n\n";
        }
        else
        {
            // Then, print what has gone wrong:
            Inputs->PrintAllErrors();
        }
    }

    // Done.
}
