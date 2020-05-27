Nucleus Sn125()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn125");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(125);
    ThisNuc.SetLifeTime("day",9.64);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.445550);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,5.5,"-",kTRUE); ThisNuc.SetLevelLifeTime(Key,9.64,"day");
    
    return ThisNuc;
}
