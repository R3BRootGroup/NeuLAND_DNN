void GenerateUseNEBULA()
{
    // Re-initialize the Inputs-class:
    R3BInputClass* Inputs = new R3BInputClass();
    Inputs->DisableErrorPrinting();
    Inputs->LinkFile("../InputFiles/InputsFile.txt");
    Inputs->ReadFile();
    
    // Obtain the Output Path:
    Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    
    // Check if all went well:
    if (Inputs->ContainsNoErrors()==kTRUE)
    {
        // Then, recreate a .txt-file:
        std::ofstream TheFile ("../InputFiles/NEBULA_Presence.txt", std::ofstream::out);
        
        // And write to it:
        if (UseNEBULA==kTRUE) {TheFile << "1";}
        else                  {TheFile << "0";}
        
        // Then, close up:
        TheFile.close();
    }
    else
    {
        // Then, print where it went wrong:
        Inputs->PrintAllErrors();
    }
}
