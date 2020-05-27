Nucleus Sb115()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sb115");
    ThisNuc.SetZ(51);
    ThisNuc.SetA(115);
    ThisNuc.SetLifeTime("min",32.1);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.48092);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,2.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,32.1,"min");
    
    // Return the final answer:
    return ThisNuc;
}
