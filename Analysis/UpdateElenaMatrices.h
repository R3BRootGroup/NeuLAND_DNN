void R3BMultMatrix::UpdateElenaMatrices()
{
    // Update function for some of the Neutron Separation Matrices.
    Int_t nClusters_NeuLAND = fArrayCluster->GetEntries();
    Int_t nClusters_NEBULA = 0;
    if (UseNEBULA==kTRUE) {nClusters_NEBULA = fArrayNEBULACluster->GetEntries();}
    
    // Elena Efficiency matrix:
    if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NeuLAND>1)))
    {
        if ((NeuLANDMultiplicity==DetectedMultiplicity)&&(DetectedMultiplicity!=0))
        {
            if ((DNNMultiplicity>=0)&&(DNNMultiplicity<=MaxMultiplicity)&&(DetectedMultiplicity>=0)&&(DetectedMultiplicity<=MaxMultiplicity))
            {
                MultMatrix_DNN_ElenaEvents[DNNMultiplicity][DetectedMultiplicity] = MultMatrix_DNN_ElenaEvents[DNNMultiplicity][DetectedMultiplicity] + 1.0;
                MultMatrix_DNN_ElenaEvents[MaxMultiplicity+1][DetectedMultiplicity] = MultMatrix_DNN_ElenaEvents[MaxMultiplicity+1][DetectedMultiplicity] + 1.0;
            }
        }
    }
    
    if (UseNEBULA==kTRUE)
    {
        // NEBULA:
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&(nClusters_NEBULA>1)))
        {
            if ((NEBULAMultiplicity==NEBDetectedMultiplicity)&&(NEBDetectedMultiplicity!=0))
            {
                if ((NEBDNNMultiplicity>=0)&&(NEBDNNMultiplicity<=MaxMultiplicity)&&(NEBDetectedMultiplicity>=0)&&(NEBDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_DNN_NEBULA_ElenaEvents[NEBDNNMultiplicity][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_ElenaEvents[NEBDNNMultiplicity][NEBDetectedMultiplicity] + 1.0;
                    MultMatrix_DNN_NEBULA_ElenaEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] = MultMatrix_DNN_NEBULA_ElenaEvents[MaxMultiplicity+1][NEBDetectedMultiplicity] + 1.0;
                }
            }
        }
        
        // Combined:
        if ((Include_SingleClusterEvents==kTRUE)||((Include_SingleClusterEvents==kFALSE)&&((nClusters_NeuLAND+nClusters_NEBULA)>1)))
        {
            if ((CombinedInteractionMultiplicity==CombinedDetectedMultiplicity)&&(CombinedDetectedMultiplicity!=0))
            {
                if ((CombinedDNNMultiplicity>=0)&&(CombinedDNNMultiplicity<=MaxMultiplicity)&&(CombinedDetectedMultiplicity>=0)&&(CombinedDetectedMultiplicity<=MaxMultiplicity))
                {
                    MultMatrix_DNN_Combined_ElenaEvents[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_ElenaEvents[CombinedDNNMultiplicity][CombinedDetectedMultiplicity] + 1.0;
                    MultMatrix_DNN_Combined_ElenaEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] = MultMatrix_DNN_Combined_ElenaEvents[MaxMultiplicity+1][CombinedDetectedMultiplicity] + 1.0;
                }
            }
        }
    }
}
