Nucleus Sb127()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb127");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(127);
    ThisNuc.SetLifeTime("day",3.85);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.43982);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,3.85,"day");
    
    return ThisNuc;
}
