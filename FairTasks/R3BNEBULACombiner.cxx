// Every CXX-file includes its own header file:
#include "R3BNEBULACombiner.h"

// Default constructor definition:
R3BNEBULACombiner::R3BNEBULACombiner() : FairTask("R3BNEBULACombiner")
{
    // Set default verbosity level:
    fVerbose = 1;

    // Create arrays:
    fArrayNeuLANDSignals = new TClonesArray("R3BSignal");
    fArrayNEBULASignals = new TClonesArray("R3BSignal");
    fArrayCOMBINEDSignals = new TClonesArray("R3BSignal");
        
    fArrayNeuLANDClusters = new TClonesArray("R3BSignalCluster");
    fArrayNEBULAClusters = new TClonesArray("R3BSignalCluster");
    fArrayCOMBINEDClusters = new TClonesArray("R3BSignalCluster");
    
    // Input parameters:
    MaxMultiplicity = 1;
    UseNEBULA = kFALSE;
    TheObjects = "Signals";
    BranchName = "Signals";
    Limit_to_Multiplicity = kTRUE;
    
    // Other parameters:
    EventCounter = 0;
    nEvents = 1;
    
    // Auxillary classes:
    TheNuclei = new Nuclei();
    TheNuclei->BuildDataBase();
}

// Destructor definition:
R3BNEBULACombiner::~R3BNEBULACombiner()
{
    if (fArrayNeuLANDSignals) {fArrayNeuLANDSignals->Clear(); delete fArrayNeuLANDSignals;}
    if (fArrayNEBULASignals) {fArrayNEBULASignals->Clear(); delete fArrayNEBULASignals;}
    if (fArrayCOMBINEDSignals) {fArrayCOMBINEDSignals->Clear(); delete fArrayCOMBINEDSignals;}
    
    if (fArrayNeuLANDClusters) {fArrayNeuLANDClusters->Clear(); delete fArrayNeuLANDClusters;}
    if (fArrayNEBULAClusters) {fArrayNEBULAClusters->Clear(); delete fArrayNEBULAClusters;}
    if (fArrayCOMBINEDClusters) {fArrayCOMBINEDClusters->Clear(); delete fArrayCOMBINEDClusters;}
    
    // Delete other objects:
    delete TheNuclei;
}

// FairTask initialization function:
InitStatus R3BNEBULACombiner::Init()
{
    // Obtain the I/O manager:
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
    {
        cout << "I/O-manager FATAL: R3BNEBULACombiner::Init: No FairRootManager\n\n";
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
    if (UseNEBULA==kFALSE)
    {
        cout << "I/O-manager FATAL: R3BNEBULACombiner cannot be used if NEBULA does not exist!\n\n";
        return kFATAL;
    }
   
    // Retrieve the arrays:
    TString Detector_Prefix = "";    
    if ((TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data()) == nullptr)
    {
        cout << "I/O-manager FATAL: R3BNEBULACombiner::Init No " + Detector_Prefix + BranchName + "!\n\n";
        return kFATAL;
    }
    if (TheObjects=="Clusters") {fArrayNeuLANDClusters = (TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data());}
    else                        {fArrayNeuLANDSignals = (TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data());}
    
    Detector_Prefix = "NEBULA_";    
    if ((BranchName=="Signals")||(BranchName=="Clusters")) {Detector_Prefix = "NEBULA";}
    if ((TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data()) == nullptr)
    {
        cout << "I/O-manager FATAL: R3BNEBULACombiner::Init No " + Detector_Prefix + BranchName + "!\n\n";
        return kFATAL;
    }
    if (TheObjects=="Clusters") {fArrayNEBULAClusters = (TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data());}
    else                        {fArrayNEBULASignals = (TClonesArray*)ioman->GetObject((Detector_Prefix+BranchName).Data());}
    
    // Register Output arrays:
    Detector_Prefix = "Combined_"; 
    if (TheObjects=="Clusters") {ioman->Register((Detector_Prefix+BranchName).Data(),"R3BSignalCluster",fArrayCOMBINEDClusters,kTRUE);}
    else                        {ioman->Register((Detector_Prefix+BranchName).Data(),"R3BSignalCluster",fArrayCOMBINEDSignals,kTRUE);}
    
    // Then, we can return the succes statement:
    if (Inputs->ContainsNoErrors()==kFALSE) {Inputs->PrintAllErrors(); return kFATAL;}
    EventCounter = 0;
    return kSUCCESS;
}

// FairTask Execute function:
void R3BNEBULACombiner::Exec(Option_t *option)
{
    // Clean output arrays. Inputs will be handled automatically.
    fArrayCOMBINEDClusters->Clear();
    fArrayCOMBINEDSignals->Clear();
   
    // Deal with Clusters/Signals:
    if (TheObjects=="Clusters")
    {
        // Declare what we need:
        Int_t nClusters = fArrayNeuLANDClusters->GetEntries();
        R3BSignalCluster* ThisCluster;
        Int_t CreationIndex = 0;
        
        // Pass NeuLAND objects:
        for (Int_t k = 0; k<nClusters; ++k)
        {
            ThisCluster = (R3BSignalCluster*) fArrayNeuLANDClusters->At(k);
            
            if ((Limit_to_Multiplicity==kFALSE)||((Limit_to_Multiplicity==kTRUE)&&((CreationIndex+0)<MaxMultiplicity)))
            {
                new ((*fArrayCOMBINEDClusters)[CreationIndex]) R3BSignalCluster(ThisCluster);
                CreationIndex = CreationIndex + 1;
            }
        }
        
        // Pass NEBULA objects:
        nClusters = fArrayNEBULAClusters->GetEntries();
        
        for (Int_t k = 0; k<nClusters; ++k)
        {
            ThisCluster = (R3BSignalCluster*) fArrayNEBULAClusters->At(k);
            
            if ((Limit_to_Multiplicity==kFALSE)||((Limit_to_Multiplicity==kTRUE)&&((CreationIndex+0)<MaxMultiplicity)))
            {
                new ((*fArrayCOMBINEDClusters)[CreationIndex]) R3BSignalCluster(ThisCluster);
                CreationIndex = CreationIndex + 1;
            }
        }
    }
    else
    {
        // Declare what we need:
        Int_t nSignals = fArrayNeuLANDSignals->GetEntries();
        R3BSignal* ThisSignal;
        Int_t CreationIndex = 0;
        
        // Pass NeuLAND objects:
        for (Int_t k = 0; k<nSignals; ++k)
        {
            ThisSignal = (R3BSignal*) fArrayNeuLANDSignals->At(k);
            
            if ((Limit_to_Multiplicity==kFALSE)||((Limit_to_Multiplicity==kTRUE)&&((CreationIndex+0)<MaxMultiplicity)))
            {
                new ((*fArrayCOMBINEDSignals)[CreationIndex]) R3BSignal(ThisSignal);
                CreationIndex = CreationIndex + 1;
            }
        }
        
        // Pass NEBULA objects:
        nSignals = fArrayNEBULASignals->GetEntries();
        
        for (Int_t k = 0; k<nSignals; ++k)
        {
            ThisSignal = (R3BSignal*) fArrayNEBULASignals->At(k);
            
            if ((Limit_to_Multiplicity==kFALSE)||((Limit_to_Multiplicity==kTRUE)&&((CreationIndex+0)<MaxMultiplicity)))
            {
                new ((*fArrayCOMBINEDSignals)[CreationIndex]) R3BSignal(ThisSignal);
                CreationIndex = CreationIndex + 1;
            }
        }
    }
                
    // Log progress:
    EventCounter = EventCounter + 1;
    if ((EventCounter%1000==0)&&(TheObjects=="Signals")&&(BranchName=="Signals")) {cout << "R3BNEBULACombiner Log: We processed " << EventCounter << " events.\n";}
}
        
// FairTask Finish function:
void R3BNEBULACombiner::Finish()
{
    // Select proper output file:
    TheOutputFile->cd();
}

// Generate ROOT dictionary:
ClassImp(R3BNEBULACombiner);
