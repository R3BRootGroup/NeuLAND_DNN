// Every CXX-file includes its own header file:
#include "R3BSingleReconstructor.h"

// Default constructor definition:
R3BSingleReconstructor::R3BSingleReconstructor() : FairTask("R3BSingleReconstructor")
{
    // Set default verbosity level:
    fVerbose = 1;

    // Create arrays:
    fArrayNeuLANDSignals = new TClonesArray("R3BSignal");
    fArrayNEBULASignals = new TClonesArray("R3BSignal");
    
    fArrayPrimHits_NeuLAND = new TClonesArray("R3BSignal");
    fArrayPrimHits_NEBULA = new TClonesArray("R3BSignal");
    fArrayPrimHits_Combined = new TClonesArray("R3BSignal");
    
    // Input parameters:
    MaxMultiplicity = 1;
    UseNEBULA = kFALSE;
    
    // Other parameters:
    EventCounter = 0;
    nEvents = 1;
    
    // Auxillary classes:
    TheNuclei = new Nuclei();
    TheNuclei->BuildDataBase();
}

// Destructor definition:
R3BSingleReconstructor::~R3BSingleReconstructor()
{
    if (fArrayNeuLANDSignals) {fArrayNeuLANDSignals->Clear(); delete fArrayNeuLANDSignals;}
    if (fArrayNEBULASignals) {fArrayNEBULASignals->Clear(); delete fArrayNEBULASignals;}
    if (fArrayPrimHits_NeuLAND) {fArrayPrimHits_NeuLAND->Clear(); delete fArrayPrimHits_NeuLAND;}
    if (fArrayPrimHits_NEBULA) {fArrayPrimHits_NEBULA->Clear(); delete fArrayPrimHits_NEBULA;}
    if (fArrayPrimHits_Combined) {fArrayPrimHits_Combined->Clear(); delete fArrayPrimHits_Combined;}
    
    // Delete other objects:
    delete TheNuclei;
}

// FairTask initialization function:
InitStatus R3BSingleReconstructor::Init()
{
    // Obtain the I/O manager:
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
    {
        cout << "I/O-manager FATAL: R3BSingleReconstructor::Init: No FairRootManager\n\n";
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

    // Retrieve the clusters:
    if ((TClonesArray*)ioman->GetObject("Signals") == nullptr)
    {
        cout << "I/O-manager FATAL: R3BSingleReconstructor::Init No R3BSignalClusters!\n\n";
        return kFATAL;
    }
    fArrayNeuLANDSignals = (TClonesArray*)ioman->GetObject("Signals");
    
    if (UseNEBULA==kTRUE)
    {
        if ((TClonesArray*)ioman->GetObject("NEBULASignals") == nullptr)
        {
            cout << "I/O-manager FATAL: R3BSingleReconstructor::Init No NEBULA R3BSignalClusters!\n\n";
            return kFATAL;
        }
        fArrayNEBULASignals = (TClonesArray*)ioman->GetObject("NEBULASignals");
    }
    
    // Register Output arrays:
    ioman->Register("SingleReconstructed_PrimHits","R3BSignal",fArrayPrimHits_NeuLAND,kTRUE);
    
    if (UseNEBULA==kTRUE)
    {
        ioman->Register("NEBULA_SingleReconstructed_PrimHits","R3BSignal",fArrayPrimHits_NEBULA,kTRUE);
        ioman->Register("Combined_SingleReconstructed_PrimHits","R3BSignal",fArrayPrimHits_Combined,kTRUE);
    }
    
    // Then, we can return the succes statement:
    if (Inputs->ContainsNoErrors()==kFALSE) {Inputs->PrintAllErrors(); return kFATAL;}
    EventCounter = 0;
    return kSUCCESS;
}

// FairTask Execute function:
void R3BSingleReconstructor::Exec(Option_t *option)
{
    // Clean output arrays. Inputs will be handled automatically.
    fArrayPrimHits_NeuLAND->Clear("C");
    fArrayPrimHits_NEBULA->Clear("C");
    fArrayPrimHits_Combined->Clear("C");
    
    // Next, find the minimum signal for each of the detectors:
    R3BSignal* NeuLANDMinSignal = new R3BSignal(); NeuLANDMinSignal->SetTime(1e99);
    R3BSignal* NEBULAMinSignal = new R3BSignal(); NEBULAMinSignal->SetTime(1e99);
    R3BSignal* ThisSignal;

    // NeuLAND:
    for (Int_t k = 0; k<fArrayNeuLANDSignals->GetEntries(); ++k)
    {
        ThisSignal = (R3BSignal*) fArrayNeuLANDSignals->At(k);
        
        if (ThisSignal->GetTime()<NeuLANDMinSignal->GetTime())
        {
            NeuLANDMinSignal->Duplicate(ThisSignal);
        }
    }
    
    // NEBULA:
    if (UseNEBULA==kTRUE)
    {
        for (Int_t k = 0; k<fArrayNEBULASignals->GetEntries(); ++k)
        {
            ThisSignal = (R3BSignal*) fArrayNEBULASignals->At(k);
        
            if (ThisSignal->GetTime()<NEBULAMinSignal->GetTime())
            {
                NEBULAMinSignal->Duplicate(ThisSignal);
            }
        }
    }
    
    // Then, do the reconstruction for NeuLAND:
    if (fArrayNeuLANDSignals->GetEntries()>0) {new ((*fArrayPrimHits_NeuLAND)[0]) R3BSignal(NeuLANDMinSignal);}
    
    // Then, do NEBULA:
    if (UseNEBULA==kTRUE)
    {
        if (fArrayNEBULASignals->GetEntries()>0) {new ((*fArrayPrimHits_NEBULA)[0]) R3BSignal(NEBULAMinSignal);}
    }
    
    // And combine the two:
    if (UseNEBULA==kTRUE)
    {
        if ((fArrayPrimHits_NeuLAND->GetEntries()==1)&&(fArrayPrimHits_NEBULA->GetEntries()==0))
        {   
            ThisSignal = (R3BSignal*) fArrayPrimHits_NeuLAND->At(0);
            new ((*fArrayPrimHits_Combined)[0]) R3BSignal(ThisSignal);
        }
        
        if ((fArrayPrimHits_NeuLAND->GetEntries()==0)&&(fArrayPrimHits_NEBULA->GetEntries()==1))
        {   
            ThisSignal = (R3BSignal*) fArrayPrimHits_NEBULA->At(0);
            new ((*fArrayPrimHits_Combined)[0]) R3BSignal(ThisSignal);
        }
        
        if ((fArrayPrimHits_NeuLAND->GetEntries()==1)&&(fArrayPrimHits_NEBULA->GetEntries()==1))
        {   
            if ((((R3BSignal*) fArrayPrimHits_NeuLAND->At(0))->GetTime())<(((R3BSignal*) fArrayPrimHits_NEBULA->At(0))->GetTime()))
            {
                ThisSignal = (R3BSignal*) fArrayPrimHits_NeuLAND->At(0);
                new ((*fArrayPrimHits_Combined)[0]) R3BSignal(ThisSignal);
            }
            else
            {
                ThisSignal = (R3BSignal*) fArrayPrimHits_NEBULA->At(0);
                new ((*fArrayPrimHits_Combined)[0]) R3BSignal(ThisSignal);
            }
        }
    }
                
    // Log progress:
    EventCounter = EventCounter + 1;
    if (EventCounter%1000==0) {cout << "R3BSingleReconstructor Log: We processed " << EventCounter << " events.\n";}
    
    // delete all objects:
    delete NeuLANDMinSignal;
    delete NEBULAMinSignal;
}
        
// FairTask Finish function:
void R3BSingleReconstructor::Finish()
{
    // Select proper output file:
    TheOutputFile->cd();
}

// Generate ROOT dictionary:
ClassImp(R3BSingleReconstructor);
