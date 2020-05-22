Nucleus Sn124()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn124");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(124);
    ThisNuc.SetLifeTime("year",1.2e21);
    ThisNuc.SetAbundance("Dimless",0.0579);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.467421);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1.2e21,"year");
    
    return ThisNuc;
}
