Nucleus Sb129()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb129");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(129);
    ThisNuc.SetLifeTime("hour",4.366);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.41806);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,4.366,"hour");
    
    return ThisNuc;
}
