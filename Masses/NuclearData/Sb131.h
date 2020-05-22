Nucleus Sb131()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb131");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(131);
    ThisNuc.SetLifeTime("min",23.03);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.392552);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kFALSE); ThisNuc.SetLevelLifeTime(Key,23.03,"min");
    
    return ThisNuc;
}
