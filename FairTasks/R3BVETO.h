// FairTask that obtains the relative energy spectrum of 
// the neutrons from the data. This specific task uses the
// simulation data to obtain the perfect spectrum; the
// theoretical maximum of what one should be able to
// obtain in case of perfect reconstruction. 
#ifndef R3BVETO_H
#define R3BVETO_H

// Inclusion of C++ headers:
#include <iostream>
#include <vector>

// Inclusion of ROOT headers:
#include "TClonesArray.h"
#include "TMath.h"
#include "TString.h"
#include "TFile.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TH1D.h"
#include "TLorentzVector.h"

// Inclusion of R3BRoot headers:
#include "FairRootManager.h"
#include "FairTask.h"
#include "R3BSignal.h"
#include "R3BInputClass.h"
#include "Nuclei.h"
#include "ObjBoolian.h"

using namespace std;

class R3BVETO : public FairTask 
{
    public:
        // Default constructor:
        R3BVETO();

        // Destructor:
        virtual ~R3BVETO();

        // Task initialization:
        virtual InitStatus Init();

        // Process a single event:
        virtual void Exec(Option_t *option);

        // Finishing the task:
        virtual void Finish();
        
        // Member functions to pass parameters:
        void LinkInputClass(R3BInputClass* inp) {Inputs = inp;}
        void SetNevents(Int_t const nn) {nEvents = nn;}
        
        // Other member functions:
        void SetBranchName(TString const str) {BranchName = str;}

    private:
        // Class content:
        TClonesArray* fArrayLorentzTracks;          // Contains the neutron tracks for which we apply the VETO condition.
        TClonesArray* fArrayVETOSignals;            // Contains the Signals Measured by the NeuLAND VETO.
        TClonesArray* fArrayNeuLANDSignals;         // Contains the Signals Measured by NeuLAND.
        TClonesArray* fArrayNEBULASignals;          // Contains the Signals Measured by NeuLAND.
        TClonesArray* fArrayVETOCondition_Naive;    // Contains the VETO desicion: Naive.
        TClonesArray* fArrayVETOCondition_TOF;      // Contains the VETO desicion: TOF.
        TClonesArray* fArrayVETOCondition_Advanced; // Contains the VETO desicion: Advanced.
        
        // Control variables:
        Int_t EventCounter;                      
        Int_t nEvents;     
        TString BranchName;
        Double_t ceff;
        Double_t TargetT;
        
        // Input parameters:
        Bool_t UseVETO;
        Bool_t UseNEBULA;
        Int_t MaxMultiplicity;                                          
        TString OutputPath;
        
        // Auxillary classes:
        Nuclei* TheNuclei;
        R3BInputClass* Inputs;
        TFile* TheOutputFile;
    
    public:
        // Generation of ROOT dictionary:
        ClassDef(R3BVETO, 1);
};

#endif
