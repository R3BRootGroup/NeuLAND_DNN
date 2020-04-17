void TradMed_ComputeCuts()
{
    // Boolian to actually compute cuts or just guess:
    Bool_t PerformComputation = kTRUE;
    
    // Connect to InputsFile:
    R3BInputClass* Inputs = new R3BInputClass();
    Inputs->DisableErrorPrinting();
    Inputs->LinkFile("../InputFiles/InputsFile.txt");
    Inputs->ReadFile();
    
    // Next, execute the traditional method:
    R3BTradMethClass* TradMed = new R3BTradMethClass();
    TradMed->SetDetector("NeuLAND");
    TradMed->DisableErrorPrinting();
    TradMed->LinkInputClass(Inputs);
    TradMed->LoadHistograms();
    if (PerformComputation==kFALSE) {TradMed->InitializeCuts();}
    TradMed->Optimization_IncludeZero();
    if (PerformComputation==kTRUE) {TradMed->DoMultipleOptimizations(3);}
    TradMed->SaveCuts();
    TradMed->PlotHistograms();
    TradMed->PrintMatrix();
    
    // Same for NEBULA:
    if (Inputs->GetInputBoolian("NEBULA_Include_in_SETUP")==kTRUE)
    {
        R3BTradMethClass* NEBTradMed = new R3BTradMethClass();
        NEBTradMed->SetDetector("NEBULA");
        NEBTradMed->DisableErrorPrinting();
        NEBTradMed->LinkInputClass(Inputs);
        NEBTradMed->Optimization_IncludeZero();
        NEBTradMed->LoadHistograms();
        if (PerformComputation==kFALSE) {NEBTradMed->InitializeCuts();}
        if (PerformComputation==kTRUE) {NEBTradMed->DoMultipleOptimizations(3);}
        NEBTradMed->SaveCuts();
        NEBTradMed->PlotHistograms();
        NEBTradMed->PrintMatrix();
        if (NEBTradMed->ContainsNoErrors()==kFALSE) {NEBTradMed->PrintAllErrors();}
    }
    
    // Print Errors:
    if (TradMed->ContainsNoErrors()==kFALSE)    {TradMed->PrintAllErrors();}

    // Done.
}
