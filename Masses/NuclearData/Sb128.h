Nucleus Sb128()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb128");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(128);
    ThisNuc.SetLifeTime("hour",9.05);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.42078);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,8.0,"-",kTRUE); ThisNuc.SetLevelLifeTime(Key,9.05,"hour");
    
    return ThisNuc;
}
