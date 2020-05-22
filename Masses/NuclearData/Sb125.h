Nucleus Sb125()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb125");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(125);
    ThisNuc.SetLifeTime("year",2.75856);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.458170);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,2.75856,"year");
    
    return ThisNuc;
}
