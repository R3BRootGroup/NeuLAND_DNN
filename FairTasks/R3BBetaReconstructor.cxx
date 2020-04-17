// Every CXX-file includes its own header file:
#include "R3BBetaReconstructor.h"

// Default constructor definition:
R3BBetaReconstructor::R3BBetaReconstructor() : FairTask("R3BBetaReconstructor")
{
    // Set default verbosity level:
    fVerbose = 1;

    // Create arrays:
    fArrayNeuLANDClusters = new TClonesArray("R3BSignalCluster");
    fArrayNEBULAClusters = new TClonesArray("R3BSignalCluster");
    
    fArrayPrimHits_NeuLAND = new TClonesArray("R3BSignal");
    fArrayPrimHits_NEBULA = new TClonesArray("R3BSignal");
    fArrayPrimHits_Combined = new TClonesArray("R3BSignal");
    
    // Input parameters:
    MaxMultiplicity = 1;
    UseNEBULA = kFALSE;
    Beta_LowerCut = 0.5;
    Beta_UpperCut = 0.9;
    Target_T = 0.0;
    Target_X = 0.0;
    Target_Y = 0.0;
    Target_Z = 0.0;
    ceff = 14.0;
    
    // Other parameters:
    EventCounter = 0;
    nEvents = 1;
    
    // Auxillary classes:
    TheNuclei = new Nuclei();
    TheNuclei->BuildDataBase();
    TheScorers = new AllScorers();
    NEBScorers = new AllScorers();
}

// Destructor definition:
R3BBetaReconstructor::~R3BBetaReconstructor()
{
    if (fArrayNeuLANDClusters) {fArrayNeuLANDClusters->Clear(); delete fArrayNeuLANDClusters;}
    if (fArrayNEBULAClusters) {fArrayNEBULAClusters->Clear(); delete fArrayNEBULAClusters;}
    if (fArrayPrimHits_NeuLAND) {fArrayPrimHits_NeuLAND->Clear(); delete fArrayPrimHits_NeuLAND;}
    if (fArrayPrimHits_NEBULA) {fArrayPrimHits_NEBULA->Clear(); delete fArrayPrimHits_NEBULA;}
    if (fArrayPrimHits_Combined) {fArrayPrimHits_Combined->Clear(); delete fArrayPrimHits_Combined;}
    
    // Delete other objects:
    delete TheNuclei;
    delete TheScorers;
    delete NEBScorers;
}

// FairTask initialization function:
InitStatus R3BBetaReconstructor::Init()
{
    // Obtain the I/O manager:
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
    {
        cout << "I/O-manager FATAL: R3BBetaReconstructor::Init: No FairRootManager\n\n";
        return kFATAL;
    }
    TheOutputFile = ioman->GetOutFile();
    
    // Check if the inputsclass is linked to a file:
    if (Inputs->IsLinked()==kFALSE)
    {
        cout << "I/O-manager FATAL: The inputs class was not linked to a file!\n\n";
        return kFATAL;
    }
    
    // Obtain all required inputs:
    MaxMultiplicity = Inputs->GetInputInteger("ParticleGun_Multiplicity");
    UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    Beta_LowerCut = Inputs->GetInputDouble("BetaReconstruction_Beta_LowerCut","dimless");
    Beta_UpperCut = Inputs->GetInputDouble("BetaReconstruction_Beta_UpperCut","dimless");
    Target_T = Inputs->GetTargetTime();
    Target_X = Inputs->GetInputDouble("TARGET_center_x_position","cm");
    Target_Y = Inputs->GetInputDouble("TARGET_center_y_position","cm");
    Target_Z = Inputs->GetInputDouble("TARGET_center_z_position","cm");
    ceff = Inputs->GetInputDouble("NeuLAND_Digitizer_Effective_LightSpeed","cm/ns");
   
    // Retrieve the clusters:
    if ((TClonesArray*)ioman->GetObject("Clusters") == nullptr)
    {
        cout << "I/O-manager FATAL: R3BBetaReconstructor::Init No R3BSignalClusters!\n\n";
        return kFATAL;
    }
    fArrayNeuLANDClusters = (TClonesArray*)ioman->GetObject("Clusters");
    
    if (UseNEBULA==kTRUE)
    {
        if ((TClonesArray*)ioman->GetObject("NEBULAClusters") == nullptr)
        {
            cout << "I/O-manager FATAL: R3BBetaReconstructor::Init No NEBULA R3BSignalClusters!\n\n";
            return kFATAL;
        }
        fArrayNEBULAClusters = (TClonesArray*)ioman->GetObject("NEBULAClusters");
    }
    
    // Register Output arrays:
    ioman->Register("BetaReconstructed_PrimHits","R3BSignal",fArrayPrimHits_NeuLAND,kTRUE);
    
    if (UseNEBULA==kTRUE)
    {
        ioman->Register("NEBULA_BetaReconstructed_PrimHits","R3BSignal",fArrayPrimHits_NEBULA,kTRUE);
        ioman->Register("Combined_BetaReconstructed_PrimHits","R3BSignal",fArrayPrimHits_Combined,kTRUE);
    }
    
    // Next, initialize the scoring class:
    TheScorers->LinkInputsClass(Inputs);
    TheScorers->SetDetector("NeuLAND");
    Bool_t ScoreTest = TheScorers->Initialize();
    if (TheScorers->ContainsNoErrors()==kFALSE) {TheScorers->PrintAllErrors(); return kFATAL;}
    if (ScoreTest==kFALSE) {std::cout << "\n\nNeuLAND AllScorers Initialization Failed!\n\n"; return kFATAL;}
    TheScorers->ReadScorers();
    
    if (UseNEBULA==kTRUE)
    {
        NEBScorers->LinkInputsClass(Inputs);
        NEBScorers->SetDetector("NEBULA");
        Bool_t NEBScoreTest = NEBScorers->Initialize();
        if (NEBScorers->ContainsNoErrors()==kFALSE) {NEBScorers->PrintAllErrors(); return kFATAL;}
        if (NEBScoreTest==kFALSE) {std::cout << "\n\nNEBULA AllScorers Initialization Failed!\n\n"; return kFATAL;}
        NEBScorers->ReadScorers();
    }
    
    // Then, we can return the succes statement:
    if (Inputs->ContainsNoErrors()==kFALSE) {Inputs->PrintAllErrors(); return kFATAL;}
    EventCounter = 0;
    return kSUCCESS;
}

// FairTask Execute function:
void R3BBetaReconstructor::Exec(Option_t *option)
{
    // Clean output arrays. Inputs will be handled automatically.
    fArrayPrimHits_NeuLAND->Clear();
    fArrayPrimHits_NEBULA->Clear();
    fArrayPrimHits_Combined->Clear();
    
    // Declare what we need:
    Int_t nClusters_NeuLAND = fArrayNeuLANDClusters->GetEntries();
    Int_t nClusters_NEBULA = 0;
    if (UseNEBULA==kTRUE) {nClusters_NEBULA = fArrayNEBULAClusters->GetEntries();}
    R3BSignalCluster* ThisCluster;
    R3BSignal* ThisSignal;
    Double_t ThisBeta;
    Int_t PrimHitIndex_NeuLAND = 0;
    Int_t PrimHitIndex_NEBULA = 0;
    Int_t PrimHitIndex_Combined = 0;
    
    // Loop over the clusters from NeuLAND to actually create the primary neutron hits:
    for (Int_t kclus = 0; kclus<nClusters_NeuLAND; ++kclus)
    {
        // Retrieve the current cluster:
        ThisCluster = (R3BSignalCluster*) fArrayNeuLANDClusters->At(kclus);
        
        // Extract the beta of this cluster:
        ThisBeta = TheScorers->ComputeClusterScoreValue_Beta(ThisCluster);
        
        // Extract cluster head:
        ThisSignal = TheScorers->GetPrimaryClusterHit(ThisCluster);
        
        // Check that it is in the allowed window:
        if ((ThisBeta>Beta_LowerCut)&&(ThisBeta<Beta_UpperCut))
        {
            // Then, we can create the primary hit:
            new ((*fArrayPrimHits_NeuLAND)[PrimHitIndex_NeuLAND]) R3BSignal(ThisSignal);
            PrimHitIndex_NeuLAND = PrimHitIndex_NeuLAND + 1;
        }
    }
    
    if (UseNEBULA==kTRUE)
    {
        // Do the same for NEBULA:
        for (Int_t kclus = 0; kclus<nClusters_NEBULA; ++kclus)
        {
            // Retrieve the current cluster:
            ThisCluster = (R3BSignalCluster*) fArrayNEBULAClusters->At(kclus);
        
            // Extract the beta of this cluster:
            ThisBeta = NEBScorers->ComputeClusterScoreValue_Beta(ThisCluster);
        
            // Extract cluster head:
            ThisSignal = NEBScorers->GetPrimaryClusterHit(ThisCluster);
        
            // Check that it is in the allowed window:
            if ((ThisBeta>Beta_LowerCut)&&(ThisBeta<Beta_UpperCut))
            {
                // Then, we can create the primary hit:
                new ((*fArrayPrimHits_NEBULA)[PrimHitIndex_NEBULA]) R3BSignal(ThisSignal);
                PrimHitIndex_NEBULA = PrimHitIndex_NEBULA + 1;
            }
        }
    
        // Then, do the combination of the two:
        for (Int_t k = 0; k<PrimHitIndex_NeuLAND; ++k)
        {
            // Make sure that we do not get too many combined hits:
            if ((PrimHitIndex_Combined>=0)&&(PrimHitIndex_Combined<(MaxMultiplicity-1)))
            {
                ThisSignal = (R3BSignal*) fArrayPrimHits_NeuLAND->At(k);
                new ((*fArrayPrimHits_Combined)[PrimHitIndex_Combined]) R3BSignal(ThisSignal);
                PrimHitIndex_Combined = PrimHitIndex_Combined + 1;
            }
        }  
    
        for (Int_t k = 0; k<PrimHitIndex_NEBULA; ++k)
        {
            // Make sure that we do not get too many combined hits:
            if ((PrimHitIndex_Combined>=0)&&(PrimHitIndex_Combined<(MaxMultiplicity-1)))
            {
                ThisSignal = (R3BSignal*) fArrayPrimHits_NEBULA->At(k);
                new ((*fArrayPrimHits_Combined)[PrimHitIndex_Combined]) R3BSignal(ThisSignal);
                PrimHitIndex_Combined = PrimHitIndex_Combined + 1;
            }
        }
    }
                
    // Log progress:
    EventCounter = EventCounter + 1;
    if (EventCounter%1000==0) {cout << "R3BBetaReconstructor Log: We processed " << EventCounter << " events.\n";}
}
        
// FairTask Finish function:
void R3BBetaReconstructor::Finish()
{
    // Select proper output file:
    TheOutputFile->cd();
}

// Generate ROOT dictionary:
ClassImp(R3BBetaReconstructor);
