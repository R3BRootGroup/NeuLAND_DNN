// Every CXX-file includes its own header file:
#include "R3BVETO.h"

// Default constructor definition:
R3BVETO::R3BVETO() : FairTask("R3BVETO")
{
    // Set default verbosity level:
    fVerbose = 1;

    // Create arrays:
    fArrayVETOSignals = new TClonesArray("R3BSignal");
    fArrayNeuLANDSignals = new TClonesArray("R3BSignal");
    fArrayNEBULASignals = new TClonesArray("R3BSignal");
    fArrayLorentzTracks = new TClonesArray("TLorentzVector");
    fArrayVETOCondition_Naive = new TClonesArray("ObjBoolian");
    fArrayVETOCondition_TOF = new TClonesArray("ObjBoolian");
    fArrayVETOCondition_Advanced = new TClonesArray("ObjBoolian");
  
    // Control variables:
    EventCounter = 0;
    nEvents = 1;
    BranchName = "TheNeutronTracks";
    
    // Input parameters:
    UseVETO = kFALSE;
    MaxMultiplicity = 0;
    OutputPath = "./";
    ceff = 14.0;
    TargetT = 0.0;
    
    // Auxillary classes:
    TheNuclei = new Nuclei();
    TheNuclei->BuildDataBase();
    TheOutputFile = 0;
}

// Destructor definition:
R3BVETO::~R3BVETO()
{
    // Delete the arrays:
    if(fArrayVETOSignals) {fArrayVETOSignals->Clear(); delete fArrayVETOSignals;}
    if(fArrayNeuLANDSignals) {fArrayNeuLANDSignals->Clear(); delete fArrayNeuLANDSignals;}
    if(fArrayNEBULASignals) {fArrayNEBULASignals->Clear(); delete fArrayNEBULASignals;}
    if(fArrayLorentzTracks) {fArrayLorentzTracks->Clear(); delete fArrayLorentzTracks;}
    if(fArrayVETOCondition_Naive) {fArrayVETOCondition_Naive->Clear(); delete fArrayVETOCondition_Naive;}
    if(fArrayVETOCondition_TOF) {fArrayVETOCondition_TOF->Clear(); delete fArrayVETOCondition_TOF;}
    if(fArrayVETOCondition_Advanced) {fArrayVETOCondition_Advanced->Clear(); delete fArrayVETOCondition_Advanced;}
     
    // Delete other objects:
    delete TheNuclei;
}

// FairTask initialization function:
InitStatus R3BVETO::Init()
{
    // Obtain the I/O manager:
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
    {
        cout << "I/O-manager FATAL: R3BVETO::Init: No FairRootManager\n\n";
        return kFATAL;
    }
    TheOutputFile = ioman->GetOutFile();
    
    // Obtain inputs:
    if (Inputs->IsLinked()==kFALSE)
    {
        cout << "I/O-manager FATAL: The R3BInputClass is not linked to a file!\n\n";
        return kFATAL;
    }
    
    // Retrieve the required inputs:
    UseVETO = Inputs->GetInputBoolian("VETO_Include_in_SETUP");
    UseNEBULA = Inputs->GetInputBoolian("NEBULA_Include_in_SETUP");
    MaxMultiplicity = Inputs->GetInputInteger("ParticleGun_Multiplicity");
    OutputPath = Inputs->GetInputString("TheOutputPath");
    ceff = Inputs->GetInputDouble("NeuLAND_Digitizer_Effective_LightSpeed","cm/ns");
    TargetT = Inputs->GetTargetTime();
    
    // Check that the VETO is there:
    if (UseVETO==kFALSE)
    {
        cout << "R3BVETO FATAL: You cannot run this algorithm if no VETO is present in the setup!\n\n";
        return kFATAL;
    }
    
    // Obtain VETO Signals:
    if ((TClonesArray*)ioman->GetObject("VETOSignals") == nullptr)
    {
        cout << "I/O-manager FATAL: R3BVETO::Init No VETO R3BSignals!\n\n";
        return kFATAL;
    }
    fArrayVETOSignals = (TClonesArray*)ioman->GetObject("VETOSignals");
    
    // Obtain NeuLAND Signals:
    if ((TClonesArray*)ioman->GetObject("Signals") == nullptr)
    {
        cout << "I/O-manager FATAL: R3BVETO::Init No NeuLAND R3BSignals!\n\n";
        return kFATAL;
    }
    fArrayNeuLANDSignals = (TClonesArray*)ioman->GetObject("Signals");
    
    // Obtain NEBULA Signals:
    if (UseNEBULA==kTRUE)
    {
        if ((TClonesArray*)ioman->GetObject("NEBULASignals") == nullptr)
        {
            cout << "I/O-manager FATAL: R3BVETO::Init No NEBULA R3BSignals!\n\n";
            return kFATAL;
        }
        fArrayNEBULASignals = (TClonesArray*)ioman->GetObject("NEBULASignals");
    }
    
    // Obtain the neutron tracks:    
    if ((TClonesArray*)ioman->GetObject(BranchName.Data()) == nullptr)
    {
        cout << "I/O-manager FATAL: R3BVETO::Init No <" << BranchName << "!\n\n";
        return kFATAL;
    }
    fArrayLorentzTracks = (TClonesArray*)ioman->GetObject(BranchName.Data());
    
    // Register the output:
    ioman->Register(BranchName+"Naive_VETO_Condition","ObjBoolian",fArrayVETOCondition_Naive,kTRUE);
    ioman->Register(BranchName+"TOF_VETO_Condition","ObjBoolian",fArrayVETOCondition_TOF,kTRUE);
    ioman->Register(BranchName+"Advanced_VETO_Condition","ObjBoolian",fArrayVETOCondition_Advanced,kTRUE);
    
    // Then, return the succes statement:
    if (Inputs->ContainsNoErrors()==kFALSE) {Inputs->PrintAllErrors(); return kFATAL;}
    EventCounter = 0;
    return kSUCCESS;
}

// FairTask Execute function:
void R3BVETO::Exec(Option_t *option)
{
    // NOTE: FairTask will automatically load the inputs into the TClonesArrays.
    // Clear the output arrays:
    fArrayVETOCondition_Naive->Clear();
    fArrayVETOCondition_TOF->Clear();
    fArrayVETOCondition_Advanced->Clear();
    
    // Generate output arrays:
    Int_t ArraySize = fArrayLorentzTracks->GetEntries();
    
    for (Int_t k = 0; k<ArraySize; ++k)
    {
        new ((*fArrayVETOCondition_Naive)[k]) ObjBoolian("Naive_VETO_Condition",kFALSE);
        new ((*fArrayVETOCondition_TOF)[k]) ObjBoolian("TOF_VETO_Condition",kFALSE);
        new ((*fArrayVETOCondition_Advanced)[k]) ObjBoolian("Advanced_VETO_Condition",kFALSE);
    }
    
    // ================ Next, apply the VETO conditions one-by-one. Naive First:
    ObjBoolian* ThisBoolian;
    
    if (fArrayVETOSignals->GetEntries()>0)
    {
        for (Int_t k = 0; k<ArraySize; ++k)
        {
            ThisBoolian = (ObjBoolian*) fArrayVETOCondition_Naive->At(k);
            ThisBoolian->SetContent(kTRUE);
        }
    }
    
    // ================ Next, do TOF:
    
    // Obtain Detector TOF:
    Double_t Detector_TOF = 1e99;
    Double_t VETO_TOF = 1e99;
    R3BSignal* ThisSignal;
    
    for (Int_t k = 0; k<fArrayNeuLANDSignals->GetEntries(); ++k)
    {
        ThisSignal = (R3BSignal*) fArrayNeuLANDSignals->At(k);
        if (ThisSignal->GetTime()<Detector_TOF) {Detector_TOF = ThisSignal->GetTime();}
    }
    
    if (UseNEBULA==kTRUE)
    {
        for (Int_t k = 0; k<fArrayNEBULASignals->GetEntries(); ++k)
        {
            ThisSignal = (R3BSignal*) fArrayNEBULASignals->At(k);
            if (ThisSignal->GetTime()<Detector_TOF) {Detector_TOF = ThisSignal->GetTime();}
        }
    }
    
    // Obtain VETO TOF:
    for (Int_t k = 0; k<fArrayVETOSignals->GetEntries(); ++k)
    {
        ThisSignal = (R3BSignal*) fArrayVETOSignals->At(k);
        if (ThisSignal->GetTime()<VETO_TOF) {VETO_TOF = ThisSignal->GetTime();}
    }
    
    // Then, apply the condition:
    if ((fArrayVETOSignals->GetEntries()>0)&&(VETO_TOF<=Detector_TOF))
    {
        for (Int_t k = 0; k<ArraySize; ++k)
        {
            ThisBoolian = (ObjBoolian*) fArrayVETOCondition_TOF->At(k);
            ThisBoolian->SetContent(kTRUE);
        }
    }
    
    // ================ Finally, do the Advanced condition:
    TLorentzVector* ThisTrack;
    Double_t cvac = 29.9792458;
    Double_t px, py, pz, pt, predt;
    Double_t aa, bb, cc, tt;
    Double_t tmin;
    Double_t ThisDistance;
    Double_t MinDistance;
    Double_t Mass;
    Double_t Gamma;
    Double_t Beta;
    Double_t Velocity;
    Double_t TrackDistance;
    Int_t MinDist_Index;
    
    Double_t sa, sb, sc, st;
    Double_t stmin;
    Double_t ThisSD;
    Double_t MinSD;
    Double_t SignalTime;
    Int_t SignalIndex;
    Int_t nSignals;
    R3BSignal* PrimSignal;
    
    Double_t* ThisTrack_PrimTimes = new Double_t[ArraySize];
    
    // Loop over all VETO signals:
    Int_t nVETOs = fArrayVETOSignals->GetEntries();
    
    for (Int_t kv = 0; kv<nVETOs; ++kv)
    {
        // Retrieve current VETO signal:
        ThisSignal = (R3BSignal*) fArrayVETOSignals->At(kv);
        
        // Retrieve current position and time:
        aa = ThisSignal->GetPositionX();
        bb = ThisSignal->GetPositionY();
        cc = ThisSignal->GetPositionZ();
        tt = ThisSignal->GetTime();
        
        // Reset index:
        MinDist_Index = -1;
        MinDistance = 1e99;
        
        // Next, loop over the neutron tracks:
        for (Int_t kn = 0; kn<ArraySize; ++kn)
        {
            // Retrieve the current VETO decision:
            ThisBoolian = (ObjBoolian*) fArrayVETOCondition_Advanced->At(kn);
            
            // And the current Track:
            ThisTrack = (TLorentzVector*) fArrayLorentzTracks->At(kn);
            
            // Only process tracks that are not yet VETOed:
            if (ThisBoolian->GetContent()==kFALSE)
            {
                // Then, retrieve the track information:
                pt = ThisTrack->T();
                px = ThisTrack->X();
                py = ThisTrack->Y();
                pz = ThisTrack->Z();
                
                // Parameter distance point:
                tmin = (aa*px + bb*py + cc*pz)/(px*px + py*py + pz*pz);
                
                // Hence, the distance between the track and the VETO signal is:
                ThisDistance = TMath::Sqrt((px*tmin - aa)*(px*tmin - aa) + (py*tmin - bb)*(py*tmin - bb) + (pz*tmin - cc)*(pz*tmin - cc));
                
                // Predict the time:
                Mass = TMath::Sqrt(pt*pt - px*px - py*py - pz*pz);
                Gamma = pt/Mass;
                Beta = TMath::Sqrt(1.0 - 1.0/(Gamma*Gamma));
                Velocity = Beta*cvac;
                TrackDistance = TMath::Sqrt(px*px*tmin*tmin + py*py*tmin*tmin + pz*pz*tmin*tmin);
                predt = TrackDistance/Velocity + TargetT;
                
                // Add time difference to the distance:
                ThisDistance = ThisDistance*ThisDistance + ceff*ceff*(predt-tt)*(predt-tt);
                ThisDistance = TMath::Sqrt(ThisDistance);
                
                // Next, search for the minimum:
                if (ThisDistance<MinDistance)
                {
                    MinDistance = ThisDistance;
                    MinDist_Index = kn;
                }
                
                // Also find the corresponding NeuLAND/NEBULA signal:
                nSignals = fArrayNeuLANDSignals->GetEntries();
                if (UseNEBULA==kTRUE) {nSignals = nSignals + fArrayNEBULASignals->GetEntries();}
                MinSD = 1e99;
                SignalIndex = -1;
                
                for (Int_t ks = 0; ks<nSignals; ++ks)
                {
                    if (ks<fArrayNeuLANDSignals->GetEntries()) {PrimSignal = (R3BSignal*) fArrayNeuLANDSignals->At(ks);}
                    else                                       {PrimSignal = (R3BSignal*) fArrayNEBULASignals->At(ks-fArrayNeuLANDSignals->GetEntries());}
                    
                    // Extract singal properties:
                    sa = PrimSignal->GetPositionX();
                    sb = PrimSignal->GetPositionY();
                    sc = PrimSignal->GetPositionZ();
                    st = PrimSignal->GetTime();
                    
                    // Find distance to the track:
                    stmin = (sa*px + sb*py + sc*pz)/(px*px + py*py + pz*pz);
                    ThisSD = TMath::Sqrt((px*stmin - sa)*(px*stmin - sa) + (py*stmin - sb)*(py*stmin - sb) + (pz*stmin - sc)*(pz*stmin - sc));
                    
                    // Search for minimum:
                    if (ThisSD<MinSD)
                    {
                        SignalIndex = ks;
                        MinSD = ThisSD;
                    }
                }
                
                // Now, obtain the track SignalTime:
                SignalTime = -1.0;
                if (SignalIndex>=0)
                {
                    if (SignalIndex<fArrayNeuLANDSignals->GetEntries())
                    {
                        PrimSignal = (R3BSignal*) fArrayNeuLANDSignals->At(SignalIndex);
                        SignalTime = PrimSignal->GetTime();
                    }
                    else
                    {
                        PrimSignal = (R3BSignal*) fArrayNeuLANDSignals->At(SignalIndex-fArrayNeuLANDSignals->GetEntries());
                        SignalTime = PrimSignal->GetTime();
                    }
                }
                
                // And store that time:
                ThisTrack_PrimTimes[kn] = SignalTime;
                
                // Close loop over neutron tracks:
            }
        }
        
        // Now, VETO the corresponding track, if there is something left to VETO and if
        // it matches the TOF-criterium of the Advanced VETO condition:
        if (MinDist_Index>=0)
        {
            if (tt<=ThisTrack_PrimTimes[MinDist_Index])
            {
                ThisBoolian->SetContent(kTRUE);
            }
        }
        
        // Done.
    }
    
    // Log progress:
    EventCounter = EventCounter + 1;    
    if (EventCounter%1000==0) {cout << "R3BVETO Log: We processed " << EventCounter << " events.\n";}
}
        
// FairTask Finish function:
void R3BVETO::Finish()
{
    // Set output file:
    TheOutputFile->cd();
}

// Generate ROOT dictionary:
ClassImp(R3BVETO);
