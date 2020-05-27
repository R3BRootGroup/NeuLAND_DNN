Nucleus Sb114()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb114");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(114);
    ThisNuc.SetLifeTime("min",3.49);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.46252);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,3.49,"min");
    
    // Return the final answer:
    return ThisNuc;
}
