Nucleus Sb119()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb119");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(119);
    ThisNuc.SetLifeTime("hour",38.19);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.48791);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,2.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,38.19,"hour");
    
    return ThisNuc;
}
