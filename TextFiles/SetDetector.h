void R3BTextFileGenerator::SetDetector(TString const TheDetector)
{
    // Specifies which detector we are dealing with.
    ThisDetector = "NeuLAND";
    
    if ((Inputs!=0)&&(Inputs!=nullptr))
    {
        if (Inputs->IsLinked()==kTRUE)
        {
            Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
            
            if (UseNEBULA==kTRUE)
            {
                if (TheDetector=="NEBULA")
                {
                    ThisDetector = "NEBULA";
                }
            }
        }
    }
}
