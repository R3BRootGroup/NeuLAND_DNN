void R3BTradMethClass::LinkInputClass(R3BInputClass* inp)
{
    // link an input class to this class. but only if that
    // inputsclass is linked to a file:
    
    if (inp->IsLinked()==kTRUE)
    {
        Inputs = inp;
        
        // Check whether we have a valid detector:
        if (ThisDetector!="NeuLAND")
        {
            Inputs->ReadFile();
            Bool_t UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
            
            // Currently, only NEBULA is allowed:
            if ((UseNEBULA==kTRUE)&&(ThisDetector=="NEBULA"))
            {
                // Then, do nothing.
            }
            else
            {
                // Not allowed, so put it back to NeuLAND:
                ThisDetector = "NeuLAND";
            }
        }
    }
    else
    {
        ErrorMessage("The inputs-class you offered to the ASCII-Generator was not linked to a File!");
    }
}
