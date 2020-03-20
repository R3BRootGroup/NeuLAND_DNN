#include "DrawGraphDouma.h"

void DoPlots110()
{
    TFile* f = new TFile("TheCrossSections_110MeV_Experiment.root","read");
    
    TGraphErrors* TDR = (TGraphErrors*) f->Get("NeutronTracks_TradMed_Clusters_CutsMult_CrossSection");
    TGraphErrors* DNN = (TGraphErrors*) f->Get("NeutronTracks_DNNScoringPlus_CrossSection");
    TGraphErrors* Single = (TGraphErrors*) f->Get("NeutronTracks_SingleReconstruction_NeuLAND_CrossSection");
    
    TH1D* TDR_Syst = (TH1D*) f->Get("NeutronTracks_TradMed_Clusters_CutsMult_SystErrors");
    TH1D* DNN_Syst = (TH1D*) f->Get("NeutronTracks_DNNScoringPlus_SystErrors");
    TH1D* Single_Syst = (TH1D*) f->Get("NeutronTracks_SingleReconstruction_NeuLAND_SystErrors");
    
    Int_t Nbins = TDR_Syst->GetNbinsX();
    Double_t TDR_Scale = 0.18;
    Double_t DNN_Scale = 0.10;
    Double_t Single_Scale = 0.32;
    
    for (Int_t k = 1; k<(Nbins+1); ++k)
    {
        TDR_Syst->SetBinContent(k,TDR_Syst->GetBinContent(k)*TDR_Scale);
        TDR_Syst->SetBinError(k,TDR_Syst->GetBinError(k)*TDR_Scale);
        
        DNN_Syst->SetBinContent(k,DNN_Syst->GetBinContent(k)*DNN_Scale);
        DNN_Syst->SetBinError(k,DNN_Syst->GetBinError(k)*DNN_Scale);
        
        Single_Syst->SetBinContent(k,Single_Syst->GetBinContent(k)*Single_Scale);
        Single_Syst->SetBinError(k,Single_Syst->GetBinError(k)*Single_Scale);
    }
        
    
    gROOT->SetBatch(kTRUE);
    TCanvas* c1 = DrawGraphDouma(Single,"7Li(p,n)7Be(gs) Exp Cross Section","Neutron CM Scattering Angle [deg]","Differential Cross Section [Counts/sr]",1,4.0,kTRUE,"AP");
    c1->cd();
    
    Single->SetLineColor(1);
    Single->SetLineWidth(6.0);
    Single->Draw("Psame");
    
    TDR->SetLineColor(4);
    TDR->SetLineWidth(6.0);
    TDR->Draw("Psame");
    
    DNN->SetLineColor(2);
    DNN->SetLineWidth(6.0);
    DNN->Draw("Psame");
    
    Single_Syst->SetLineColor(kGray+2);
    Single_Syst->SetFillColor(kGray+2);
    Single_Syst->Draw("E3same");
    
    TDR_Syst->SetLineColor(kBlue-7);
    TDR_Syst->SetFillColor(kBlue-7);
    TDR_Syst->Draw("E3same");
    
    DNN_Syst->SetLineColor(kRed-7);
    DNN_Syst->SetFillColor(kRed-7);
    DNN_Syst->Draw("E3same");
    
    c1->SaveAs("./TheCrossSection.png");
    c1->Close();
}
