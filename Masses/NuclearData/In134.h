Nucleus In134()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("In134");
    ThisNuc.SetZ(49);
    ThisNuc.SetA(134);
    ThisNuc.SetLifeTime("ms",140.0);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.1710);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,4.0,"-",kFALSE); ThisNuc.SetLevelLifeTime(Key,140.0,"ms");
    
    return ThisNuc;
}
