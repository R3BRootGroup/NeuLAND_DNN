#include "DrawGraphDouma2.h"
#include "DrawGraphDouma3.h"

void MakeObservable_MeanGraphs()
{
    // NOTE: 600 MeV & 30 dp at 14 m.
    
    // Declare Angle Arrays:
    Double_t Angle_Perfect_Mean [6] = {0.4101,0.4148,0.4184,0.4192,0.4195,0.4195};
    Double_t Angle_Perfect_Sigma [6] = {0.1032,0.1114,0.1170,0.1187,0.1190,0.1190};
    Double_t Angle_DNN_Mean [6] = {0.4111,0.4061,0.3988,0.3924,0.3934,0.3906};
    Double_t Angle_DNN_Sigma [6] = {0.1003,0.1215,0.1415,0.1495,0.1529,0.1532};
    Double_t Angle_TDR_Mean [6] = {0.4157,0.4151,0.4267,0.4354,0.4388,0.4406};
    Double_t Angle_TDR_Sigma [6] = {0.0948,0.1130,0.1370,0.1507,0.1548,0.1577};
    
    Double_t Angle_DispX [6] = {1.0,2.0,3.0,4.0,5.0,6.0};
    Double_t Angle_DispX1 [6] = {1.01,2.01,3.01,4.01,5.01,6.01};
    Double_t Angle_DispX2 [6] = {1.02,2.02,3.02,4.02,5.02,6.02};
    Double_t Angle_DispX3 [6] = {1.03,2.03,3.03,4.03,5.03,6.03};
    Double_t Angle_DispX9 [6] = {0.99,1.99,2.99,3.99,4.99,5.99};
    Double_t Angle_DispX8 [6] = {0.98,1.98,2.98,3.98,4.98,5.98};
    Double_t Angle_DispX7 [6] = {0.97,1.97,2.97,3.97,4.97,5.97};
    Double_t Angle_Xvalues [6] = {0.2,0.5,1.0,1.5,2.0,1e99};
    Double_t Angle_XErrors [6] = {0.0,0.0,0.0,0.0,0.0,0.0};
    
    TGraphErrors* PerfectGraph = new TGraphErrors(6,&Angle_DispX[0],&Angle_Perfect_Mean[0],&Angle_XErrors[0],&Angle_Perfect_Sigma[0]);
    TGraphErrors* DNNGraph = new TGraphErrors(6,&Angle_DispX3[0],&Angle_DNN_Mean[0],&Angle_XErrors[0],&Angle_DNN_Sigma[0]);
    TGraphErrors* TDRGraph = new TGraphErrors(6,&Angle_DispX7[0],&Angle_TDR_Mean[0],&Angle_XErrors[0],&Angle_TDR_Sigma[0]);
    
    // Draw a picture:
    Double_t ScaleFactor = 4.0;
    gROOT->SetBatch(kTRUE);
    TCanvas* c1 = DrawGraphDouma2(PerfectGraph,"4n invariant Mass observable","Max. Scattering Angle [deg]","Invariant Mass Difference [MeV]",1,ScaleFactor);
    
    PerfectGraph->SetLineWidth(1.5*ScaleFactor);
    PerfectGraph->SetLineColor(1);
    PerfectGraph->Draw("PL*|>same");
    
    DNNGraph->SetLineWidth(1.5*ScaleFactor);
    DNNGraph->SetLineColor(2);
    DNNGraph->Draw("PL*same|>");
    
    TDRGraph->SetLineWidth(1.5*ScaleFactor);
    TDRGraph->SetLineColor(4);
    TDRGraph->Draw("PL*same|>");
    
    c1->SaveAs("./Observable_RunGraph_Angle.png");
    c1->Close();
    
    // ============================================================================
    
    // Declare DoublePlane Arrays:
    Double_t DP_Perfect_Mean [5] = {0.4142,0.4165,0.4178,0.4197,0.4200};
    Double_t DP_Perfect_Sigma [5] = {0.1160,0.1188,0.1194,0.1199,0.1196};
    Double_t DP_DNN_Mean [5] = {0.4101,0.3967,0.3936,0.3919,0.3886};
    Double_t DP_DNN_Sigma [5] = {0.1602,0.1609,0.1564,0.1597,0.1541};
    Double_t DP_TDR_Mean [5] = {0.4589,0.4503,0.4408,0.4465,0.4457};
    Double_t DP_TDR_Sigma [5] = {0.1692,0.1641,0.1618,0.1751,0.1650};
    
    Double_t DP_Xvalues [5] = {8.0,12.0,16.0,23.0,30.0};
    Double_t DP_XErrors [5] = {0.0,0.0,0.0,0.0,0.0};
    Double_t DP_Xvalues3 [5];
    Double_t DP_Xvalues7 [5];
    
    for (Int_t k = 0; k<5; ++k)
    {
        DP_Xvalues3[k] = DP_Xvalues[k] + 0.03*DP_Xvalues[0];
        DP_Xvalues7[k] = DP_Xvalues[k] - 0.03*DP_Xvalues[0];
    }    
    
    TGraphErrors* DP_PerfectGraph = new TGraphErrors(5,&DP_Xvalues[0],&DP_Perfect_Mean[0],&DP_XErrors[0],&DP_Perfect_Sigma[0]);
    TGraphErrors* DP_DNNGraph = new TGraphErrors(5,&DP_Xvalues3[0],&DP_DNN_Mean[0],&DP_XErrors[0],&DP_DNN_Sigma[0]);
    TGraphErrors* DP_TDRGraph = new TGraphErrors(5,&DP_Xvalues7[0],&DP_TDR_Mean[0],&DP_XErrors[0],&DP_TDR_Sigma[0]);
    
    // Draw a picture:
    ScaleFactor = 4.0;
    gROOT->SetBatch(kTRUE);
    TCanvas* c2 = DrawGraphDouma3(DP_PerfectGraph,"4n invariant Mass observable","Nr. of NeuLAND dp","Invariant Mass Difference [MeV]",1,ScaleFactor);
    
    DP_PerfectGraph->SetLineWidth(1.5*ScaleFactor);
    DP_PerfectGraph->SetLineColor(1);
    DP_PerfectGraph->Draw("PL*|>same");
    
    DP_DNNGraph->SetLineWidth(1.5*ScaleFactor);
    DP_DNNGraph->SetLineColor(2);
    DP_DNNGraph->Draw("PL*same|>");
    
    DP_TDRGraph->SetLineWidth(1.5*ScaleFactor);
    DP_TDRGraph->SetLineColor(4);
    DP_TDRGraph->Draw("PL*same|>");
    
    c2->SaveAs("./Observable_RunGraph_DP.png");
    c2->Close();
    
    
}

