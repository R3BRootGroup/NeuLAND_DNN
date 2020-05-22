Nucleus Sb133()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb133");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(133);
    ThisNuc.SetLifeTime("min",2.34);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.364729);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kFALSE); ThisNuc.SetLevelLifeTime(Key,2.34,"min");
    
    return ThisNuc;
}
