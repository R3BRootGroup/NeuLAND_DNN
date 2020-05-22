Nucleus Sb117()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb117");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(117);
    ThisNuc.SetLifeTime("hour",2.8);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.48790);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,2.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,2.8,"hour");
    
    // Return the final answer:
    return ThisNuc;
}
