Nucleus Sn117()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn117");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(117);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.0768);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.509611);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
