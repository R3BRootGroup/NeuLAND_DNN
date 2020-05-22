Nucleus Sn134()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn134");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(134);
    ThisNuc.SetLifeTime("sec",1.050);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.275171);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,1.050,"sec");
    
    return ThisNuc;
}
