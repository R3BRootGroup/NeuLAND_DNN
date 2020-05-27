Nucleus Sn123()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn123");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(123);
    ThisNuc.SetLifeTime("day",129.2);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.467243);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,5.5,"-",kTRUE); ThisNuc.SetLevelLifeTime(Key,129.2,"day");
    
    return ThisNuc;
}
