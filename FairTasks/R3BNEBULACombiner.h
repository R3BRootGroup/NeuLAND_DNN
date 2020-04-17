// FairTask that will combine first hits from NeuLAND and NEBULA.
#ifndef R3BNEBULACOMBINER_H
#define R3BNEBULACOMBINER_H

// Inclusion of C++ headers:
#include <iostream>

// Inclusion of ROOT headers:
#include "TClonesArray.h"
#include "TMath.h"
#include "TString.h"
#include "TFile.h"
#include "TSystem.h"
#include "TROOT.h"

// Inclusion of R3BRoot headers:
#include "FairRootManager.h"
#include "FairTask.h"
#include "R3BSignal.h"
#include "R3BSignalCluster.h"
#include "R3BInputClass.h"
#include "Nuclei.h"

using namespace std;

class R3BNEBULACombiner : public FairTask 
{
    public:
        // Default constructor:
        R3BNEBULACombiner();

        // Destructor:
        virtual ~R3BNEBULACombiner();

        // Task initialization:
        virtual InitStatus Init();

        // Process a single event:
        virtual void Exec(Option_t *option);

        // Finishing the task:
        virtual void Finish();
        
        // Parameter Member functions:
        void LinkInputClass(R3BInputClass* inp) {Inputs = inp;}
        void SetNevents(Int_t const nn) {nEvents = nn;}
        void SetObjects(TString const obj) {TheObjects = obj;}
        void SetBranchName(TString const Name) {BranchName = Name;}
        void SetMultiplicityLimit() {Limit_to_Multiplicity = kTRUE;}
        void ReleaseMultiplicityLimit() {Limit_to_Multiplicity = kFALSE;}
        
    private:
        // Class content:
        TClonesArray* fArrayNeuLANDSignals;
        TClonesArray* fArrayNEBULASignals;
        TClonesArray* fArrayCOMBINEDSignals;
        
        TClonesArray* fArrayNeuLANDClusters;
        TClonesArray* fArrayNEBULAClusters;
        TClonesArray* fArrayCOMBINEDClusters;
        
        // Input parameters:
        Int_t MaxMultiplicity;
        Bool_t UseNEBULA;
        TString TheObjects;
        TString BranchName;
        Bool_t Limit_to_Multiplicity;
        
        // Other parameters:
        Int_t EventCounter;
        Int_t nEvents;
        
        // Auxillary classes:
        R3BInputClass* Inputs;
        Nuclei* TheNuclei;
        TFile* TheOutputFile;
    
    public:
        // Generation of ROOT dictionary:
        ClassDef(R3BNEBULACombiner, 1);
};

#endif
