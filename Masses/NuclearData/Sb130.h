Nucleus Sb130()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb130");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(130);
    ThisNuc.SetLifeTime("min",39.5);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.39736);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,8.0,"-",kFALSE); ThisNuc.SetLevelLifeTime(Key,39.5,"min");
    
    return ThisNuc;
}
