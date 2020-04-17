void R3BMultMatrix::UpdateUnFoldedMatrices()
{
    // Update function for some of the Neutron Separation Matrices.
    Int_t nClusters_NeuLAND = fArrayCluster->GetEntries();
    Int_t nClusters_NEBULA = 0;
    if (UseNEBULA==kTRUE) {nClusters_NEBULA = fArrayNEBULACluster->GetEntries();}
    
    // Deal with UnFolded matrices:
    if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NeuLAND>1)))
    {
        // NeuLAND TDR:
        if ((TDRMultiplicity>=0)&&(TDRMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
        {
            MultMatrix_TDR_UnFolded[TDRMultiplicity][DetectedMultiplicity] = MultMatrix_TDR_UnFolded[TDRMultiplicity][DetectedMultiplicity] + 1.0;
            MultMatrix_TDR_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_TDR_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
        }
    
        // NeuLAND DNN:
        if ((DNNMultiplicity>=0)&&(DNNMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
        {
            MultMatrix_DNN_UnFolded[DNNMultiplicity][DetectedMultiplicity] = MultMatrix_DNN_UnFolded[DNNMultiplicity][DetectedMultiplicity] + 1.0;
            MultMatrix_DNN_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_DNN_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
        }
    
        // NeuLAND Beta:
        if ((BetaNeuLANDMultiplicity>=0)&&(BetaNeuLANDMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
        {
            MultMatrix_Beta_UnFolded[BetaNeuLANDMultiplicity][DetectedMultiplicity] = MultMatrix_Beta_UnFolded[BetaNeuLANDMultiplicity][DetectedMultiplicity] + 1.0;
            MultMatrix_Beta_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_Beta_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
        }
        
        // NeuLAND Single:
        if ((SingleNeuLANDMultiplicity>=0)&&(SingleNeuLANDMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
        {
            MultMatrix_Single_UnFolded[SingleNeuLANDMultiplicity][DetectedMultiplicity] = MultMatrix_Single_UnFolded[SingleNeuLANDMultiplicity][DetectedMultiplicity] + 1.0;
            MultMatrix_Single_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_Single_UnFolded[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
        }
    }
    
    if (UseNEBULA==kTRUE)
    {
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NEBULA>1)))
        {
            // NEBULA TDR:
            if ((NEBTDRMultiplicity>=0)&&(NEBTDRMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_TDR_NEBULA_UnFolded[NEBTDRMultiplicity][NEBDetectedMultiplicity] = MultMatrix_TDR_NEBULA_UnFolded[NEBTDRMultiplicity][NEBDetectedMultiplicity] + 1.0;
                MultMatrix_TDR_NEBULA_UnFolded[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_TDR_NEBULA_UnFolded[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
            }
            
            // NEBULA DNN:
            if ((NEBDNNMultiplicity>=0)&&(NEBDNNMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_DNN_NEBULA_UnFolded[NEBDNNMultiplicity][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_UnFolded[NEBDNNMultiplicity][NEBDetectedMultiplicity] + 1.0;
                MultMatrix_DNN_NEBULA_UnFolded[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_UnFolded[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
            }
            
            // NEBULA Beta:
            if ((BetaNEBULAMultiplicity>=0)&&(BetaNEBULAMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Beta_UnFolded_NEBULA[BetaNEBULAMultiplicity][NEBDetectedMultiplicity] = MultMatrix_Beta_UnFolded_NEBULA[BetaNEBULAMultiplicity][NEBDetectedMultiplicity] + 1.0;
                MultMatrix_Beta_UnFolded_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_Beta_UnFolded_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
            }
            
            // NEBULA Single:
            if ((SingleNEBULAMultiplicity>=0)&&(SingleNEBULAMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Single_UnFolded_NEBULA[SingleNEBULAMultiplicity][NEBDetectedMultiplicity] = MultMatrix_Single_UnFolded_NEBULA[SingleNEBULAMultiplicity][NEBDetectedMultiplicity] + 1.0;
                MultMatrix_Single_UnFolded_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_Single_UnFolded_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
            }
        }
        
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&((nClusters_NeuLAND+nClusters_NEBULA)>1)))
        {
            // Combined TDR:
            if ((CombinedTDRMultiplicity>=0)&&(CombinedTDRMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_TDR_Combined_UnFolded[CombinedTDRMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_TDR_Combined_UnFolded[CombinedTDRMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                MultMatrix_TDR_Combined_UnFolded[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_TDR_Combined_UnFolded[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
            }
            
            // Combined DNN:
            if ((CombinedDNNMultiplicity>=0)&&(CombinedDNNMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_DNN_Combined_UnFolded[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_UnFolded[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                MultMatrix_DNN_Combined_UnFolded[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_UnFolded[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
            }
            
            // Combined Beta:
            if ((BetaCombinedMultiplicity>=0)&&(BetaCombinedMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Beta_UnFolded_Combined[BetaCombinedMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_Beta_UnFolded_Combined[BetaCombinedMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                MultMatrix_Beta_UnFolded_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_Beta_UnFolded_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
            }
        
            // Combined Single:
            if ((SingleCombinedMultiplicity>=0)&&(SingleCombinedMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Single_UnFolded_Combined[SingleCombinedMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_Single_UnFolded_Combined[SingleCombinedMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                MultMatrix_Single_UnFolded_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_Single_UnFolded_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
            }
        }
    }
}
