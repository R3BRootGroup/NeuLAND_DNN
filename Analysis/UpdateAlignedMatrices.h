void R3BMultMatrix::UpdateAlignedMatrices()
{
    // Update function for some of the Neutron Separation Matrices.
    Int_t nClusters_NeuLAND = fArrayCluster->GetEntries();
    Int_t nClusters_NEBULA = 0;
    if (UseNEBULA==kTRUE) {nClusters_NEBULA = fArrayNEBULACluster->GetEntries();}
    
    // Deal with Aligned matrices:
    
    // And the matrices without misaligned events:
    if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NeuLAND>1)))
    {
        if ((GunMultiplicity==DetectedMultiplicity)&&(DetectedMultiplicity!=0))
        {
            // NeuLAND TDR:
            if ((TDRMultiplicity>=0)&&(TDRMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_TDR_AlignedEvents[TDRMultiplicity][DetectedMultiplicity] = MultMatrix_TDR_AlignedEvents[TDRMultiplicity][DetectedMultiplicity] + 1.0;
                MultMatrix_TDR_AlignedEvents[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_TDR_AlignedEvents[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
            }
    
            // NeuLAND DNN:
            if ((DNNMultiplicity>=0)&&(DNNMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_DNN_AlignedEvents[DNNMultiplicity][DetectedMultiplicity] = MultMatrix_DNN_AlignedEvents[DNNMultiplicity][DetectedMultiplicity] + 1.0;
                MultMatrix_DNN_AlignedEvents[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_DNN_AlignedEvents[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
            }
        
            // NeuLAND Beta:
            if ((BetaNeuLANDMultiplicity>=0)&&(BetaNeuLANDMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Beta_Aligned[BetaNeuLANDMultiplicity][DetectedMultiplicity] = MultMatrix_Beta_Aligned[BetaNeuLANDMultiplicity][DetectedMultiplicity] + 1.0;
                MultMatrix_Beta_Aligned[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_Beta_Aligned[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
            }
        
            // NeuLAND Single:
            if ((SingleNeuLANDMultiplicity>=0)&&(SingleNeuLANDMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_Single_Aligned[SingleNeuLANDMultiplicity][DetectedMultiplicity] = MultMatrix_Single_Aligned[SingleNeuLANDMultiplicity][DetectedMultiplicity] + 1.0;
                MultMatrix_Single_Aligned[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_Single_Aligned[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
            }
        }
    }
    
    if (UseNEBULA==kTRUE)
    {
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NEBULA>1)))
        {
            // NEBULA TDR:
            if ((GunMultiplicity==NEBDetectedMultiplicity)&&(NEBDetectedMultiplicity!=0))
            {        
                if ((NEBTDRMultiplicity>=0)&&(NEBTDRMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_TDR_NEBULA_AlignedEvents[NEBTDRMultiplicity][NEBDetectedMultiplicity] = MultMatrix_TDR_NEBULA_AlignedEvents[NEBTDRMultiplicity][NEBDetectedMultiplicity] + 1.0;
                    MultMatrix_TDR_NEBULA_AlignedEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_TDR_NEBULA_AlignedEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
                }
            }
            
            // NEBULA DNN:
            if ((GunMultiplicity==NEBDetectedMultiplicity)&&(NEBDetectedMultiplicity!=0))
            {        
                if ((NEBDNNMultiplicity>=0)&&(NEBDNNMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_DNN_NEBULA_AlignedEvents[NEBDNNMultiplicity][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_AlignedEvents[NEBDNNMultiplicity][NEBDetectedMultiplicity] + 1.0;
                    MultMatrix_DNN_NEBULA_AlignedEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_AlignedEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
                }
            }
            
            // NEBULA Beta:
            if ((GunMultiplicity==NEBDetectedMultiplicity)&&(NEBDetectedMultiplicity!=0))
            {        
                if ((BetaNEBULAMultiplicity>=0)&&(BetaNEBULAMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_Beta_Aligned_NEBULA[BetaNEBULAMultiplicity][NEBDetectedMultiplicity] = MultMatrix_Beta_Aligned_NEBULA[BetaNEBULAMultiplicity][NEBDetectedMultiplicity] + 1.0;
                    MultMatrix_Beta_Aligned_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_Beta_Aligned_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
                }
            }
            
            // NEBULA Single:        
            if ((GunMultiplicity==NEBDetectedMultiplicity)&&(NEBDetectedMultiplicity!=0))
            {        
                if ((SingleNEBULAMultiplicity>=0)&&(SingleNEBULAMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_Single_Aligned_NEBULA[SingleNEBULAMultiplicity][NEBDetectedMultiplicity] = MultMatrix_Single_Aligned_NEBULA[SingleNEBULAMultiplicity][NEBDetectedMultiplicity] + 1.0;
                    MultMatrix_Single_Aligned_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_Single_Aligned_NEBULA[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
                }
            }
        }
        
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&((nClusters_NeuLAND+nClusters_NEBULA)>1)))
        {
            // Combined TDR:
            if ((GunMultiplicity==CombinedDetectedMultiplicity)&&(CombinedDetectedMultiplicity!=0))
            {        
                if ((CombinedTDRMultiplicity>=0)&&(CombinedTDRMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_TDR_Combined_AlignedEvents[CombinedTDRMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_TDR_Combined_AlignedEvents[CombinedTDRMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                    MultMatrix_TDR_Combined_AlignedEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_TDR_Combined_AlignedEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
                }
            }
            
            // Combined DNN:
            if ((GunMultiplicity==CombinedDetectedMultiplicity)&&(CombinedDetectedMultiplicity!=0))
            {        
                if ((CombinedDNNMultiplicity>=0)&&(CombinedDNNMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_DNN_Combined_AlignedEvents[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_AlignedEvents[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                    MultMatrix_DNN_Combined_AlignedEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_AlignedEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
                }
            }
            
            // Combined Beta:
            if ((GunMultiplicity==CombinedDetectedMultiplicity)&&(CombinedDetectedMultiplicity!=0))
            {        
                if ((BetaCombinedMultiplicity>=0)&&(BetaCombinedMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_Beta_Aligned_Combined[BetaCombinedMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_Beta_Aligned_Combined[BetaCombinedMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                    MultMatrix_Beta_Aligned_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_Beta_Aligned_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
                }
            }
        
            // Combined Single:
            if ((GunMultiplicity==CombinedDetectedMultiplicity)&&(CombinedDetectedMultiplicity!=0))
            {        
                if ((SingleCombinedMultiplicity>=0)&&(SingleCombinedMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_Single_Aligned_Combined[SingleCombinedMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_Single_Aligned_Combined[SingleCombinedMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                    MultMatrix_Single_Aligned_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_Single_Aligned_Combined[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
                }
            }
        }
    }
}
