Nucleus Sn114()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn114");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(114);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.0066);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.522566);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
