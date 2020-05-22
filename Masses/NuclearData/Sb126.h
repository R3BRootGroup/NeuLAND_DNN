Nucleus Sb126()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb126");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(126);
    ThisNuc.SetLifeTime("day",12.35);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.4403);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,8.0,"-",kFALSE); ThisNuc.SetLevelLifeTime(Key,12.35,"day");
    
    return ThisNuc;
}
