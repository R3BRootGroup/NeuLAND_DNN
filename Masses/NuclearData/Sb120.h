Nucleus Sb120()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb120");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(120);
    ThisNuc.SetLifeTime("min",15.89);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.47564);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,1.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,15.89,"min");
    
    return ThisNuc;
}
