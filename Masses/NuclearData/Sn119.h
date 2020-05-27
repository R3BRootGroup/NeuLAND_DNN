Nucleus Sn119()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn119");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(119);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.0859);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.499449);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
