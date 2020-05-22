Nucleus Sb123()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb123");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(123);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.4279);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.472328);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
