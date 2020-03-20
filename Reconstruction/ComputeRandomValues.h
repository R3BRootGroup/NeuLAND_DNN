// Generate random values for noise simulation:
Double_t AllScorers::ComputeSignalRandomValue(TString const ScoreName)
{
    // Find proper scoreclass:
    Int_t Index = -1;
    Int_t Counter = 0;
    Int_t Size = SignalScorers.size();
    
    for (Int_t k = 0; k<Size; ++k)
    {
        if (SignalScorers.at(k)->GetName()==ScoreName)
        {
            Index = k;
            Counter = Counter + 1;
        }
    }
    
    // Next, define the naswer:
    Double_t Answer = 0.0;
    
    if ((Counter==1)&&(Index>=0)&&(Index<Size))
    {
        // Extract required information:
        Double_t Xmin = SignalScorers.at(Index)->GetXmin();
        Double_t Xmax = SignalScorers.at(Index)->GetXmax();
        Double_t Length = TMath::Abs(Xmax-Xmin);
        
        // Generate random number:
        Answer = Xmin + TheGenerator->Uniform(Length);
    }
    
    // Return the number:
    return Answer;
}

Double_t AllScorers::ComputeClusterRandomValue(TString const ScoreName)
{
    // Find proper scoreclass:
    Int_t Index = -1;
    Int_t Counter = 0;
    Int_t Size = ClusterScorers.size();
    
    for (Int_t k = 0; k<Size; ++k)
    {
        if (ClusterScorers.at(k)->GetName()==ScoreName)
        {
            Index = k;
            Counter = Counter + 1;
        }
    }
    
    // Next, define the naswer:
    Double_t Answer = 0.0;
    
    if ((Counter==1)&&(Index>=0)&&(Index<Size))
    {
        // Extract required information:
        Double_t Xmin = ClusterScorers.at(Index)->GetXmin();
        Double_t Xmax = ClusterScorers.at(Index)->GetXmax();
        Double_t Length = TMath::Abs(Xmax-Xmin);
        
        // Generate random number:
        Answer = Xmin + TheGenerator->Uniform(Length);
    }
    
    // Return the number:
    return Answer;
}
