Nucleus Sb134()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb134");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(134);
    ThisNuc.SetLifeTime("sec",0.78);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.325950);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0.0,"-",kFALSE); ThisNuc.SetLevelLifeTime(Key,0.78,"sec");
    
    return ThisNuc;
}
