Nucleus Sn133()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn133");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(133);
    ThisNuc.SetLifeTime("sec",1.46);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.310088);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,3.5,"-",kTRUE); ThisNuc.SetLevelLifeTime(Key,1.46,"sec");
    
    return ThisNuc;
}
