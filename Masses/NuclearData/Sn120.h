Nucleus Sn120()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn120");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(120);
    ThisNuc.SetLifeTime("year",1e10);
    ThisNuc.SetAbundance("Dimless",0.3258);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.504492);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1e10,"year");
    
    return ThisNuc;
}
