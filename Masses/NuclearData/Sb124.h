Nucleus Sb124()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb124");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(124);
    ThisNuc.SetLifeTime("day",60.2);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.456160);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.0,"-",kTRUE); ThisNuc.SetLevelLifeTime(Key,60.2,"day");
    
    return ThisNuc;
}
