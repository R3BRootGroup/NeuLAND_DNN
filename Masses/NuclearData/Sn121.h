Nucleus Sn121()
{
    Nucleus ThisNuc;
    ThisNuc.SetName("Sn121");
    ThisNuc.SetZ(50);
    ThisNuc.SetA(121);
    ThisNuc.SetLifeTime("hour",27.03);
    ThisNuc.SetAbundance("Dimless",0.0);
    ThisNuc.SetBindingEnergy("PerN","MeV",8.485201);
    
    // Add the ground state:
    Int_t Key = 0;
    Key=0; ThisNuc.AddEnergyLevel(Key,0.0,"keV"); ThisNuc.AddLevelAngMom(Key,1.5,"+",kTRUE); ThisNuc.SetLevelLifeTime(Key,27.03,"hour");
    
    return ThisNuc;
}
