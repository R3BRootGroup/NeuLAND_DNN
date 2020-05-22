Nucleus In124()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("In124");
    ThisNuc.SetZ(49);
    ThisNuc.SetA(124);
    ThisNuc.SetLifeTime("sec",3.12);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.41434);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,1.0,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,3.12,"sec");
    
    return ThisNuc;
}
