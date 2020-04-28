#include "DrawHistDouma2.h"

void Make4nLABAngleHists()
{
    // Collect histograms:
    // NOTE: 600 MeV & 30 dp at 14 m.
    TString ThePath = "/media/christiaan/DATA/Christiaan/ENSAR/Scenario_Summary/30dp_600MeV/2ndINCLXX/LABAngles/";
    
    TFile* f_02deg = new TFile(ThePath + "/Max0.2deg/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_02deg = (TH1D*) f_02deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_02deg = (TH1D*) f_02deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_02deg = (TH1D*) f_02deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_02deg = (TH1D*) f_02deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_02deg = (TH1D*) f_02deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    TFile* f_05deg = new TFile(ThePath + "/Max0.5deg/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_05deg = (TH1D*) f_05deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_05deg = (TH1D*) f_05deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_05deg = (TH1D*) f_05deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_05deg = (TH1D*) f_05deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_05deg = (TH1D*) f_05deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    TFile* f_10deg = new TFile(ThePath + "/Max1.0deg/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_10deg = (TH1D*) f_10deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_10deg = (TH1D*) f_10deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_10deg = (TH1D*) f_10deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_10deg = (TH1D*) f_10deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_10deg = (TH1D*) f_10deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    TFile* f_15deg = new TFile(ThePath + "/Max1.5deg/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_15deg = (TH1D*) f_15deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_15deg = (TH1D*) f_15deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_15deg = (TH1D*) f_15deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_15deg = (TH1D*) f_15deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_15deg = (TH1D*) f_15deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    TFile* f_20deg = new TFile(ThePath + "/Max2.0deg/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_20deg = (TH1D*) f_20deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_20deg = (TH1D*) f_20deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_20deg = (TH1D*) f_20deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_20deg = (TH1D*) f_20deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_20deg = (TH1D*) f_20deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    TFile* f_99deg = new TFile(ThePath + "/NoMaxAngle/Val/" + "TetraNeutron_InvMass.root","read");
    TH1D*  h_Perfect_99deg = (TH1D*) f_99deg->Get("NeutronTracks_PerfectMethod_Signals_MassHistogram");
    TH1D*  h_DNN_99deg = (TH1D*) f_99deg->Get("NeutronTracks_DNNScoringPlus_MassHistogram");
    TH1D*  h_TDR_99deg = (TH1D*) f_99deg->Get("NeutronTracks_TradMed_Clusters_CutsMult_MassHistogram");
    TH1D*  h_Mult_99deg = (TH1D*) f_99deg->Get("NeutronTracks_TradMed_Clusters_DNNMult_MassHistogram");
    TH1D*  h_Scoring_99deg = (TH1D*) f_99deg->Get("NeutronTracks_ScoringPlus_Clusters_DNNMult_MassHistogram");
    
    // --------------------------------------------------------------------------------------
    
    // Make the proper picture:
    Double_t ScaleFactor = 4.0;
    gROOT->SetBatch(kTRUE);
    Double_t TheMax = h_Perfect_99deg->GetMaximum();
    TCanvas* c1 = DrawHistDouma2(h_Perfect_99deg,"4n Invariant Mass Spectrum","Invariant Mass Difference [MeV]","Counts",0,kFALSE,ScaleFactor,TheMax);
    
    // Paint all the different histograms:
    
    // ==================================
    
    h_Perfect_99deg->SetLineWidth(ScaleFactor*2.0);
    h_Perfect_99deg->SetLineColor(1);
    h_Perfect_99deg->Draw("histsame");
    
    h_Perfect_20deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_20deg->SetLineColor(1);
    h_Perfect_20deg->Draw("histsame");
    
    h_Perfect_15deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_15deg->SetLineColor(1);
    h_Perfect_15deg->Draw("histsame");
    
    h_Perfect_10deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_10deg->SetLineColor(1);
    h_Perfect_10deg->Draw("histsame");
    
    h_Perfect_05deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_05deg->SetLineColor(1);
    h_Perfect_05deg->Draw("histsame");
    
    h_Perfect_02deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_02deg->SetLineColor(1);
    h_Perfect_02deg->Draw("histsame");
    
    // ==================================
    
    h_DNN_99deg->SetLineWidth(ScaleFactor*2.0);
    h_DNN_99deg->SetLineColor(2);
    h_DNN_99deg->Draw("histsame");
    
    h_DNN_20deg->SetLineWidth(ScaleFactor*1.2);
    h_DNN_20deg->SetLineColor(2);
    h_DNN_20deg->Draw("histsame");
    
    h_DNN_15deg->SetLineWidth(ScaleFactor*1.2);
    h_DNN_15deg->SetLineColor(2);
    h_DNN_15deg->Draw("histsame");
    
    h_DNN_10deg->SetLineWidth(ScaleFactor*1.2);
    h_DNN_10deg->SetLineColor(2);
    h_DNN_10deg->Draw("histsame");
    
    h_DNN_05deg->SetLineWidth(ScaleFactor*1.2);
    h_DNN_05deg->SetLineColor(2);
    h_DNN_05deg->Draw("histsame");
    
    h_DNN_02deg->SetLineWidth(ScaleFactor*1.2);
    h_DNN_02deg->SetLineColor(2);
    h_DNN_02deg->Draw("histsame");
    
    // ==================================
    
    // Save and Close:
    c1->SaveAs("./30dp_600MeV_4nLABAngleDNNHists.png");
    c1->Close();    
    h_Perfect_99deg->SetMaximum(TheMax);
    
    // --------------------------------------------------------------------------------------
    
    // Make another picture:
    ScaleFactor = 4.0;
    gROOT->SetBatch(kTRUE);
    TheMax = h_Perfect_99deg->GetMaximum();
    TCanvas* c2 = DrawHistDouma2(h_Perfect_99deg,"4n Invariant Mass Spectrum","Invariant Mass Difference [MeV]","Counts",0,kFALSE,ScaleFactor,TheMax);
    
    // Paint all the different histograms:
    
    // ==================================
    
    h_Perfect_99deg->SetLineWidth(ScaleFactor*2.0);
    h_Perfect_99deg->SetLineColor(1);
    h_Perfect_99deg->Draw("histsame");
    
    h_Perfect_20deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_20deg->SetLineColor(1);
    h_Perfect_20deg->Draw("histsame");
    
    h_Perfect_15deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_15deg->SetLineColor(1);
    h_Perfect_15deg->Draw("histsame");
    
    h_Perfect_10deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_10deg->SetLineColor(1);
    h_Perfect_10deg->Draw("histsame");
    
    h_Perfect_05deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_05deg->SetLineColor(1);
    h_Perfect_05deg->Draw("histsame");
    
    h_Perfect_02deg->SetLineWidth(ScaleFactor*1.2);
    h_Perfect_02deg->SetLineColor(1);
    h_Perfect_02deg->Draw("histsame");
    
    // ==================================
    
    h_TDR_99deg->SetLineWidth(ScaleFactor*2.0);
    h_TDR_99deg->SetLineColor(4);
    h_TDR_99deg->Draw("histsame");
    
    h_TDR_20deg->SetLineWidth(ScaleFactor*1.2);
    h_TDR_20deg->SetLineColor(4);
    h_TDR_20deg->Draw("histsame");
    
    h_TDR_15deg->SetLineWidth(ScaleFactor*1.2);
    h_TDR_15deg->SetLineColor(4);
    h_TDR_15deg->Draw("histsame");
    
    h_TDR_10deg->SetLineWidth(ScaleFactor*1.2);
    h_TDR_10deg->SetLineColor(4);
    h_TDR_10deg->Draw("histsame");
    
    h_TDR_05deg->SetLineWidth(ScaleFactor*1.2);
    h_TDR_05deg->SetLineColor(4);
    h_TDR_05deg->Draw("histsame");
    
    h_TDR_02deg->SetLineWidth(ScaleFactor*1.2);
    h_TDR_02deg->SetLineColor(4);
    h_TDR_02deg->Draw("histsame");
    
    // ==================================
    
    // Save and Close:
    c2->SaveAs("./30dp_600MeV_4nLABAngleTDRHists.png");
    c2->Close();    
}

