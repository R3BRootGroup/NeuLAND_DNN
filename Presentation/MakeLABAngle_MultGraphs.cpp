#include "DrawGraphDoumaArray4.h"

void MakeLABAngle_MultGraphs()
{
    // NOTE: 600 MeV & 30 dp at 14 m.
    
    // Begin by declaring the proper Arrays: 
        
    // First, Full DNN (Folded):
    Double_t DNN_1n [6] = {89.4,88.8,88.7,88.5,88.0,88.4};
    Double_t DNN_2n [6] = {72.0,71.8,71.4,72.4,72.5,73.0};
    Double_t DNN_3n [6] = {53.1,56.0,56.8,57.0,56.4,57.5};
    Double_t DNN_4n [6] = {56.4,55.0,55.5,54.7,55.0,55.5};
    Double_t DNN_5n [6] = {59.5,62.1,62.5,63.6,64.1,62.6};
        
    // Then, Restricted DNN (Folded):
    Double_t DNN_Res_1n [6] = {72.1,80.0,84.4,85.8,86.2,88.1};
    Double_t DNN_Res_2n [6] = {47.3,58.6,65.2,68.5,69.7,71.8};
    Double_t DNN_Res_3n [6] = {26.5,39.8,48.2,51.3,52.0,54.9};
    Double_t DNN_Res_4n [6] = {20.0,33.1,42.9,45.7,47.5,50.5};
    Double_t DNN_Res_5n [6] = {15.7,33.0,45.8,50.8,53.0,54.8};
        
    // Then, Restricted TDR (Folded):
    Double_t TDR_Res_1n [6] = {59.8,71.1,77.5,78.1,78.0,75.8};
    Double_t TDR_Res_2n [6] = {37.7,50.9,61.2,62.0,63.4,65.6};
    Double_t TDR_Res_3n [6] = {24.1,36.8,48.0,48.8,51.2,55.5};
    Double_t TDR_Res_4n [6] = {15.3,27.0,37.8,40.2,42.3,46.0};
    Double_t TDR_Res_5n [6] = {12.3,28.7,37.9,46.1,47.5,50.6};
        
    // Then, Full TDR (Folded):
    Double_t TDR_1n [6] = {72.2,77.6,81.1,80.1,79.5,76.0};
    Double_t TDR_2n [6] = {56.4,61.7,67.3,65.7,66.3,67.0};
    Double_t TDR_3n [6] = {47.3,51.0,56.4,54.4,55.7,58.2};
    Double_t TDR_4n [6] = {41.2,43.9,47.9,47.7,48.5,50.1};
    Double_t TDR_5n [6] = {49.1,56.4,53.1,58.9,58.2,57.8};
        
    // And Perfect Tracking:
    Double_t Perfect_1n [6] = {78.2,87.3,92.2,94.0,94.9,96.5};
    Double_t Perfect_2n [6] = {59.6,74.9,84.3,87.8,89.6,92.7};
    Double_t Perfect_3n [6] = {43.6,63.3,76.5,81.4,83.8,88.1};
    Double_t Perfect_4n [6] = {31.1,53.0,68.9,74.9,77.8,83.0};
    Double_t Perfect_5n [6] = {21.3,43.8,61.5,68.2,71.3,77.3};
    
    /*
    Double_t PercentScale = 50.0;
    for (Int_t k = 0; k<6; ++k)
    {
        TDR_Res_1n[k] = PercentScale*TDR_Res_1n[k]/Perfect_1n[k];
        TDR_Res_2n[k] = PercentScale*TDR_Res_2n[k]/Perfect_2n[k];
        TDR_Res_3n[k] = PercentScale*TDR_Res_3n[k]/Perfect_3n[k];
        TDR_Res_4n[k] = PercentScale*TDR_Res_4n[k]/Perfect_4n[k];
        TDR_Res_5n[k] = PercentScale*TDR_Res_5n[k]/Perfect_5n[k];
        
        DNN_Res_1n[k] = PercentScale*DNN_Res_1n[k]/Perfect_1n[k];
        DNN_Res_2n[k] = PercentScale*DNN_Res_2n[k]/Perfect_2n[k];
        DNN_Res_3n[k] = PercentScale*DNN_Res_3n[k]/Perfect_3n[k];
        DNN_Res_4n[k] = PercentScale*DNN_Res_4n[k]/Perfect_4n[k];
        DNN_Res_5n[k] = PercentScale*DNN_Res_5n[k]/Perfect_5n[k];
    }
    */
    
    // Finally, other values:
    Double_t Xvalues [6] = {0.2,0.5,1.0,1.5,2.0,1e99};
    Double_t DispX [6] = {1.0,2.0,3.0,4.0,5.0,6.0};
    
    Double_t SqrtX = 0.0;
    Double_t SqrtY = 0.1;
    Double_t XError [10] = {SqrtX,SqrtX,SqrtX,SqrtX,SqrtX,SqrtX,SqrtX,SqrtX,SqrtX,SqrtX};
    Double_t YError [10] = {SqrtY,SqrtY,SqrtY,SqrtY,SqrtY,SqrtY,SqrtY,SqrtY,SqrtY,SqrtY};
    
    // Next, define the TGraphErrors:
    TGraphErrors** PerfectGraphs = new TGraphErrors*[5];
    PerfectGraphs[0] = new TGraphErrors(6,&DispX[0],&Perfect_1n[0],&XError[0],&YError[0]);
    PerfectGraphs[1] = new TGraphErrors(6,&DispX[0],&Perfect_2n[0],&XError[0],&YError[0]);
    PerfectGraphs[2] = new TGraphErrors(6,&DispX[0],&Perfect_3n[0],&XError[0],&YError[0]);
    PerfectGraphs[3] = new TGraphErrors(6,&DispX[0],&Perfect_4n[0],&XError[0],&YError[0]);
    PerfectGraphs[4] = new TGraphErrors(6,&DispX[0],&Perfect_5n[0],&XError[0],&YError[0]);
    
    TGraphErrors** DNNGraphs = new TGraphErrors*[5];
    DNNGraphs[0] = new TGraphErrors(6,&DispX[0],&DNN_1n[0],&XError[0],&YError[0]);
    DNNGraphs[1] = new TGraphErrors(6,&DispX[0],&DNN_2n[0],&XError[0],&YError[0]);
    DNNGraphs[2] = new TGraphErrors(6,&DispX[0],&DNN_3n[0],&XError[0],&YError[0]);
    DNNGraphs[3] = new TGraphErrors(6,&DispX[0],&DNN_4n[0],&XError[0],&YError[0]);
    DNNGraphs[4] = new TGraphErrors(6,&DispX[0],&DNN_5n[0],&XError[0],&YError[0]);
    
    TGraphErrors** DNNResGraphs = new TGraphErrors*[5];
    DNNResGraphs[0] = new TGraphErrors(6,&DispX[0],&DNN_Res_1n[0],&XError[0],&YError[0]);
    DNNResGraphs[1] = new TGraphErrors(6,&DispX[0],&DNN_Res_2n[0],&XError[0],&YError[0]);
    DNNResGraphs[2] = new TGraphErrors(6,&DispX[0],&DNN_Res_3n[0],&XError[0],&YError[0]);
    DNNResGraphs[3] = new TGraphErrors(6,&DispX[0],&DNN_Res_4n[0],&XError[0],&YError[0]);
    DNNResGraphs[4] = new TGraphErrors(6,&DispX[0],&DNN_Res_5n[0],&XError[0],&YError[0]);
    
    TGraphErrors** TDRGraphs = new TGraphErrors*[5];
    TDRGraphs[0] = new TGraphErrors(6,&DispX[0],&TDR_1n[0],&XError[0],&YError[0]);
    TDRGraphs[1] = new TGraphErrors(6,&DispX[0],&TDR_2n[0],&XError[0],&YError[0]);
    TDRGraphs[2] = new TGraphErrors(6,&DispX[0],&TDR_3n[0],&XError[0],&YError[0]);
    TDRGraphs[3] = new TGraphErrors(6,&DispX[0],&TDR_4n[0],&XError[0],&YError[0]);
    TDRGraphs[4] = new TGraphErrors(6,&DispX[0],&TDR_5n[0],&XError[0],&YError[0]);
    
    TGraphErrors** TDRResGraphs = new TGraphErrors*[5];
    TDRResGraphs[0] = new TGraphErrors(6,&DispX[0],&TDR_Res_1n[0],&XError[0],&YError[0]);
    TDRResGraphs[1] = new TGraphErrors(6,&DispX[0],&TDR_Res_2n[0],&XError[0],&YError[0]);
    TDRResGraphs[2] = new TGraphErrors(6,&DispX[0],&TDR_Res_3n[0],&XError[0],&YError[0]);
    TDRResGraphs[3] = new TGraphErrors(6,&DispX[0],&TDR_Res_4n[0],&XError[0],&YError[0]);
    TDRResGraphs[4] = new TGraphErrors(6,&DispX[0],&TDR_Res_5n[0],&XError[0],&YError[0]);
    
    // Then, make the plots:
    TString* Titles = new TString[5];
    Titles[0] = "Particle Gun: n=1";
    Titles[1] = "Particle Gun: n=2";
    Titles[2] = "Particle Gun: n=3";
    Titles[3] = "Particle Gun: n=4";
    Titles[4] = "Particle Gun: n=5";
    
    gROOT->SetBatch(kTRUE);
    Double_t ScaleFactor = 4.0;
    TCanvas* c1 = DrawGraphDoumaArray4(5,3,2,PerfectGraphs,Titles,"Max. Scattering Angle [deg]","Efficiency [%]",ScaleFactor,1,"APL*");
    
    // Add the other graphs:
    for (Int_t k = 0; k<5; ++k)
    {
        PerfectGraphs[k]->SetLineWidth(ScaleFactor*1.5);
        PerfectGraphs[k]->SetLineColor(kBlack);
        PerfectGraphs[k]->SetMarkerColor(kBlack);
        PerfectGraphs[k]->SetLineStyle(1);
        c1->cd(k+1);
        PerfectGraphs[k]->Draw("PL*same");
        
        DNNGraphs[k]->SetLineWidth(ScaleFactor*1.5);
        DNNGraphs[k]->SetLineColor(kRed);
        DNNGraphs[k]->SetMarkerColor(kRed);
        DNNGraphs[k]->SetLineStyle(1);
        c1->cd(k+1);
        DNNGraphs[k]->Draw("PL*same");
        
        DNNResGraphs[k]->SetLineWidth(ScaleFactor*1.0);
        DNNResGraphs[k]->SetLineColor(kRed);
        DNNResGraphs[k]->SetMarkerColor(kRed);
        DNNResGraphs[k]->SetLineStyle(7);
        c1->cd(k+1);
        DNNResGraphs[k]->Draw("PL*same");
        
        TDRGraphs[k]->SetLineWidth(ScaleFactor*1.5);
        TDRGraphs[k]->SetLineColor(kBlue);
        TDRGraphs[k]->SetMarkerColor(kBlue);
        TDRGraphs[k]->SetLineStyle(1);
        c1->cd(k+1);
        TDRGraphs[k]->Draw("PL*same");
        
        TDRResGraphs[k]->SetLineWidth(ScaleFactor*1.0);
        TDRResGraphs[k]->SetLineColor(kBlue);
        TDRResGraphs[k]->SetMarkerColor(kBlue);
        TDRResGraphs[k]->SetLineStyle(7);
        c1->cd(k+1);
        TDRResGraphs[k]->Draw("PL*same");
    }
    
    // Save & Close:
    c1->SaveAs("./LABAngleGraph_600MeV30dp.png");
    c1->Close();
}

