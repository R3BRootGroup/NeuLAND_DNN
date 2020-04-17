void R3BTradMethClass::SetDetector(TString const str)
{
    // Allows one to switch detectors. However, one can only 
    // do this before the inputs are loaded:
    if (Inputs==0)
    {
        ThisDetector = str;
    }
}
