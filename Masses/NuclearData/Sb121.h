Nucleus Sb121()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb121");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(121);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.5721);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.482066);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,2.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
