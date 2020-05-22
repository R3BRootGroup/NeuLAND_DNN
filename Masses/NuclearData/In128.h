Nucleus In128()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("In128");
    ThisNuc.SetZ(49);
    ThisNuc.SetA(128);
    ThisNuc.SetLifeTime("sec",0.84);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.3511);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.0,"+",kFALSE); ThisNuc.SetLevelLifeTime(Key,0.84,"sec");
    
    return ThisNuc;
}
