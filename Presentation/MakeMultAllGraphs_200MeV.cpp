#include "DrawGraphDoumaArray.h"
#include "DrawGraphDoumaArray3.h"

void MakeMultAllGraphs_200MeV()
{
    // NOTE: 1000 MeV:
    
    // Begin by creating the multiplicity graphs:
    DNNDataGraph* DNN_1n = new DNNDataGraph(); DNNDataGraph* DNN_Res_1n = new DNNDataGraph(); DNNDataGraph* TDR_1n = new DNNDataGraph(); DNNDataGraph* TDR_Res_1n = new DNNDataGraph(); DNNDataGraph* Perfect_1n = new DNNDataGraph();
    DNNDataGraph* DNN_2n = new DNNDataGraph(); DNNDataGraph* DNN_Res_2n = new DNNDataGraph(); DNNDataGraph* TDR_2n = new DNNDataGraph(); DNNDataGraph* TDR_Res_2n = new DNNDataGraph(); DNNDataGraph* Perfect_2n = new DNNDataGraph();
    DNNDataGraph* DNN_3n = new DNNDataGraph(); DNNDataGraph* DNN_Res_3n = new DNNDataGraph(); DNNDataGraph* TDR_3n = new DNNDataGraph(); DNNDataGraph* TDR_Res_3n = new DNNDataGraph(); DNNDataGraph* Perfect_3n = new DNNDataGraph();
    DNNDataGraph* DNN_4n = new DNNDataGraph(); DNNDataGraph* DNN_Res_4n = new DNNDataGraph(); DNNDataGraph* TDR_4n = new DNNDataGraph(); DNNDataGraph* TDR_Res_4n = new DNNDataGraph(); DNNDataGraph* Perfect_4n = new DNNDataGraph();
    DNNDataGraph* DNN_5n = new DNNDataGraph(); DNNDataGraph* DNN_Res_5n = new DNNDataGraph(); DNNDataGraph* TDR_5n = new DNNDataGraph(); DNNDataGraph* TDR_Res_5n = new DNNDataGraph(); DNNDataGraph* Perfect_5n = new DNNDataGraph();
    
    Double_t PerfectHeight = 142.0;
    Double_t TDRHeight = 115.0;
    Double_t DNNHeight = 130.0;
    Double_t SqrtN = 0.1;
    
    DNN_1n->SetErrorHeight(DNNHeight); DNN_Res_1n->SetErrorHeight(DNNHeight); TDR_1n->SetErrorHeight(TDRHeight); TDR_Res_1n->SetErrorHeight(TDRHeight); Perfect_1n->SetErrorHeight(PerfectHeight);
    DNN_2n->SetErrorHeight(DNNHeight); DNN_Res_2n->SetErrorHeight(DNNHeight); TDR_2n->SetErrorHeight(TDRHeight); TDR_Res_2n->SetErrorHeight(TDRHeight); Perfect_2n->SetErrorHeight(PerfectHeight);
    DNN_3n->SetErrorHeight(DNNHeight); DNN_Res_3n->SetErrorHeight(DNNHeight); TDR_3n->SetErrorHeight(TDRHeight); TDR_Res_3n->SetErrorHeight(TDRHeight); Perfect_3n->SetErrorHeight(PerfectHeight);
    DNN_4n->SetErrorHeight(DNNHeight); DNN_Res_4n->SetErrorHeight(DNNHeight); TDR_4n->SetErrorHeight(TDRHeight); TDR_Res_4n->SetErrorHeight(TDRHeight); Perfect_4n->SetErrorHeight(PerfectHeight);
    DNN_5n->SetErrorHeight(DNNHeight); DNN_Res_5n->SetErrorHeight(DNNHeight); TDR_5n->SetErrorHeight(TDRHeight); TDR_Res_5n->SetErrorHeight(TDRHeight); Perfect_5n->SetErrorHeight(PerfectHeight);
    
    // ------------------------------------------------------------
    
    // Then, add the 8dp scenario:
    DNN_1n->AddYpoint(0,52.1,52.7,48.8,51.0,47.3); DNN_Res_1n->AddYpoint(0,50.9,51.6,47.4,49.9,45.9); TDR_1n->AddYpoint(0,45.7,45.6,43.1,42.1,39.9); TDR_Res_1n->AddYpoint(0,45.1,45.0,42.3,41.6,39.1); Perfect_1n->AddYpoint(0,58.6,58.6,53.5,58.7,53.5);
    DNN_2n->AddYpoint(0,37.3,36.8,31.3,35.5,31.0); DNN_Res_2n->AddYpoint(0,24.2,24.5,19.2,21.6,17.8); TDR_2n->AddYpoint(0,29.9,30.7,25.5,31.5,27.5); TDR_Res_2n->AddYpoint(0,19.2,19.7,15.2,17.9,14.8); Perfect_2n->AddYpoint(0,34.3,34.5,29.0,34.4,29.4);
    DNN_3n->AddYpoint(0,23.8,21.1,17.6,25.0,20.5); DNN_Res_3n->AddYpoint(0,11.8,10.3,8.3,10.5,7.8);   TDR_3n->AddYpoint(0,21.1,21.0,15.9,22.7,17.5); TDR_Res_3n->AddYpoint(0,9.9,9.9,7.1,8.8,6.6);      Perfect_3n->AddYpoint(0,20.2,20.1,16.0,20.3,15.9);
    DNN_4n->AddYpoint(0,15.5,18.0,10.1,19.5,15.1); DNN_Res_4n->AddYpoint(0,5.9,6.3,3.7,5.6,4.1);      TDR_4n->AddYpoint(0,14.9,13.6,9.8,17.8,12.7);  TDR_Res_4n->AddYpoint(0,5.6,5.0,3.5,5.1,3.5);      Perfect_4n->AddYpoint(0,11.7,11.8,8.6,11.7,8.7);
    DNN_5n->AddYpoint(0,12.1,13.0,6.4,17.2,11.2);  DNN_Res_5n->AddYpoint(0,4.2,4.3,2.1,4.9,2.8);      TDR_5n->AddYpoint(0,10.8,12.3,6.3,16.8,10.6);  TDR_Res_5n->AddYpoint(0,3.8,4.1,2.0,4.8,2.6);      Perfect_5n->AddYpoint(0,6.8,6.8,4.7,6.8,4.7);
    
    DNN_1n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_1n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_1n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_1n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_1n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_2n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_2n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_2n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_2n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_2n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_3n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_3n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_3n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_3n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_3n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_4n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_4n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_4n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_4n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_4n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_5n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_5n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_5n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_5n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_5n->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
    DNN_1n->AddXpoint(0,8.0); DNN_Res_1n->AddXpoint(0,8.0); TDR_1n->AddXpoint(0,8.0); TDR_Res_1n->AddXpoint(0,8.0); Perfect_1n->AddXpoint(0,8.0);
    DNN_2n->AddXpoint(0,8.0); DNN_Res_2n->AddXpoint(0,8.0); TDR_2n->AddXpoint(0,8.0); TDR_Res_2n->AddXpoint(0,8.0); Perfect_2n->AddXpoint(0,8.0);
    DNN_3n->AddXpoint(0,8.0); DNN_Res_3n->AddXpoint(0,8.0); TDR_3n->AddXpoint(0,8.0); TDR_Res_3n->AddXpoint(0,8.0); Perfect_3n->AddXpoint(0,8.0);
    DNN_4n->AddXpoint(0,8.0); DNN_Res_4n->AddXpoint(0,8.0); TDR_4n->AddXpoint(0,8.0); TDR_Res_4n->AddXpoint(0,8.0); Perfect_4n->AddXpoint(0,8.0);
    DNN_5n->AddXpoint(0,8.0); DNN_Res_5n->AddXpoint(0,8.0); TDR_5n->AddXpoint(0,8.0); TDR_Res_5n->AddXpoint(0,8.0); Perfect_5n->AddXpoint(0,8.0);
    
    // ------------------------------------------------------------
    
    // Then, add the 12dp scenario:
    DNN_1n->AddYpoint(1,64.8,66.4,60.5,66.1,62.0); DNN_Res_1n->AddYpoint(1,64.1,65.6,59.5,65.3,61.1); TDR_1n->AddYpoint(1,57.9,57.9,50.8,61.4,55.1); TDR_Res_1n->AddYpoint(1,57.4,57.5,50.3,60.9,54.6); Perfect_1n->AddYpoint(1,72.8,72.7,70.6,72.6,70.6);
    DNN_2n->AddYpoint(1,48.5,45.9,44.4,47.3,43.2); DNN_Res_2n->AddYpoint(1,38.6,37.6,32.2,38.5,32.1); TDR_2n->AddYpoint(1,41.1,41.8,37.8,39.2,35.5); TDR_Res_2n->AddYpoint(1,32.7,33.6,25.9,33.0,26.2); Perfect_2n->AddYpoint(1,53.2,53.4,50.3,53.2,50.3);
    DNN_3n->AddYpoint(1,33.9,33.1,30.5,30.7,29.1); DNN_Res_3n->AddYpoint(1,22.8,22.0,17.9,21.4,17.2); TDR_3n->AddYpoint(1,31.2,30.4,28.8,30.0,28.0); TDR_Res_3n->AddYpoint(1,21.0,20.9,15.9,21.4,16.5); Perfect_3n->AddYpoint(1,38.6,38.7,35.7,38.6,35.6);
    DNN_4n->AddYpoint(1,24.0,28.9,21.4,24.9,24.2); DNN_Res_4n->AddYpoint(1,12.8,15.8,9.7,14.5,11.3);  TDR_4n->AddYpoint(1,23.1,21.7,22.3,20.8,20.2); TDR_Res_4n->AddYpoint(1,13.6,12.8,10.3,13.2,10.2); Perfect_4n->AddYpoint(1,27.9,27.9,25.1,28.0,25.2);
    DNN_5n->AddYpoint(1,30.9,25.1,29.8,22.9,25.9); DNN_Res_5n->AddYpoint(1,15.3,13.6,12.6,12.4,11.5); TDR_5n->AddYpoint(1,21.6,22.3,24.6,18.7,21.0); TDR_Res_5n->AddYpoint(1,12.1,12.4,11.1,10.9,9.9);  Perfect_5n->AddYpoint(1,20.2,20.1,17.6,20.1,17.6);
    
    DNN_1n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_1n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_1n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_1n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_1n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_2n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_2n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_2n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_2n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_2n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_3n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_3n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_3n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_3n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_3n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_4n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_4n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_4n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_4n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_4n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_5n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_5n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_5n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_5n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_5n->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
    DNN_1n->AddXpoint(1,12.0); DNN_Res_1n->AddXpoint(1,12.0); TDR_1n->AddXpoint(1,12.0); TDR_Res_1n->AddXpoint(1,12.0); Perfect_1n->AddXpoint(1,12.0);
    DNN_2n->AddXpoint(1,12.0); DNN_Res_2n->AddXpoint(1,12.0); TDR_2n->AddXpoint(1,12.0); TDR_Res_2n->AddXpoint(1,12.0); Perfect_2n->AddXpoint(1,12.0);
    DNN_3n->AddXpoint(1,12.0); DNN_Res_3n->AddXpoint(1,12.0); TDR_3n->AddXpoint(1,12.0); TDR_Res_3n->AddXpoint(1,12.0); Perfect_3n->AddXpoint(1,12.0);
    DNN_4n->AddXpoint(1,12.0); DNN_Res_4n->AddXpoint(1,12.0); TDR_4n->AddXpoint(1,12.0); TDR_Res_4n->AddXpoint(1,12.0); Perfect_4n->AddXpoint(1,12.0);
    DNN_5n->AddXpoint(1,12.0); DNN_Res_5n->AddXpoint(1,12.0); TDR_5n->AddXpoint(1,12.0); TDR_Res_5n->AddXpoint(1,12.0); Perfect_5n->AddXpoint(1,12.0);
    
    // ------------------------------------------------------------
    
    // Then, add the 16dp scenario:
    DNN_1n->AddYpoint(2,75.2,74.8,72.7,73.2,69.9); DNN_Res_1n->AddYpoint(2,74.7,74.4,72.0,72.8,69.3); TDR_1n->AddYpoint(2,66.4,67.5,64.2,64.5,62.0); TDR_Res_1n->AddYpoint(2,66.1,76.3,63.8,64.3,61.7); Perfect_1n->AddYpoint(2,82.5,82.6,79.1,82.8,79.0);
    DNN_2n->AddYpoint(2,55.9,56.2,49.1,53.8,48.8); DNN_Res_2n->AddYpoint(2,50.2,50.5,43.0,47.0,41.0); TDR_2n->AddYpoint(2,51.6,50.8,46.0,52.7,47.2); TDR_Res_2n->AddYpoint(2,46.1,45.6,39.7,46.5,40.0); Perfect_2n->AddYpoint(2,68.5,68.3,62.9,68.4,62.7);
    DNN_3n->AddYpoint(2,41.3,43.8,34.0,40.2,35.3); DNN_Res_3n->AddYpoint(2,33.1,35.3,26.3,29.8,24.9); TDR_3n->AddYpoint(2,38.9,38.4,32.4,33.1,28.4); TDR_Res_3n->AddYpoint(2,31.7,31.2,25.0,25.8,21.0); Perfect_3n->AddYpoint(2,56.3,56.3,49.6,56.1,49.7);
    DNN_4n->AddYpoint(2,37.0,36.1,28.3,40.5,34.6); DNN_Res_4n->AddYpoint(2,25.8,26.3,19.0,25.8,20.5); TDR_4n->AddYpoint(2,33.4,34.1,26.1,39.4,32.4); TDR_Res_4n->AddYpoint(2,24.8,25.0,18.1,26.6,20.4); Perfect_4n->AddYpoint(2,46.1,46.1,38.9,46.2,38.9);
    DNN_5n->AddYpoint(2,40.1,35.7,26.6,43.6,33.9); DNN_Res_5n->AddYpoint(2,27.2,25.0,17.0,28.0,20.0); TDR_5n->AddYpoint(2,32.3,32.4,23.1,36.5,27.5); TDR_Res_5n->AddYpoint(2,23.1,23.0,15.0,25.0,17.1); Perfect_5n->AddYpoint(2,37.5,37.4,30.3,37.3,30.2);
    
    DNN_1n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_1n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_1n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_1n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_1n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_2n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_2n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_2n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_2n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_2n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_3n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_3n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_3n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_3n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_3n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_4n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_4n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_4n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_4n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_4n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_5n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_5n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_5n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_5n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_5n->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
    DNN_1n->AddXpoint(2,16.0); DNN_Res_1n->AddXpoint(2,16.0); TDR_1n->AddXpoint(2,16.0); TDR_Res_1n->AddXpoint(2,16.0); Perfect_1n->AddXpoint(2,16.0);
    DNN_2n->AddXpoint(2,16.0); DNN_Res_2n->AddXpoint(2,16.0); TDR_2n->AddXpoint(2,16.0); TDR_Res_2n->AddXpoint(2,16.0); Perfect_2n->AddXpoint(2,16.0);
    DNN_3n->AddXpoint(2,16.0); DNN_Res_3n->AddXpoint(2,16.0); TDR_3n->AddXpoint(2,16.0); TDR_Res_3n->AddXpoint(2,16.0); Perfect_3n->AddXpoint(2,16.0);
    DNN_4n->AddXpoint(2,16.0); DNN_Res_4n->AddXpoint(2,16.0); TDR_4n->AddXpoint(2,16.0); TDR_Res_4n->AddXpoint(2,16.0); Perfect_4n->AddXpoint(2,16.0);
    DNN_5n->AddXpoint(2,16.0); DNN_Res_5n->AddXpoint(2,16.0); TDR_5n->AddXpoint(2,16.0); TDR_Res_5n->AddXpoint(2,16.0); Perfect_5n->AddXpoint(2,16.0);
    
    // ------------------------------------------------------------
    
    // Then, add the 23dp scenario:
    DNN_1n->AddYpoint(3,84.2,83.6,78.6,85.4,80.0); DNN_Res_1n->AddYpoint(3,84.0,83.4,78.3,85.2,79.7); TDR_1n->AddYpoint(3,74.5,75.1,62.8,82.0,73.9); TDR_Res_1n->AddYpoint(3,74.4,75.0,62.6,81.9,73.7); Perfect_1n->AddYpoint(3,91.1,91.0,89.9,91.0,89.8);
    DNN_2n->AddYpoint(3,65.8,65.8,56.9,68.1,61.2); DNN_Res_2n->AddYpoint(3,63.3,63.2,52.8,66.1,57.3); TDR_2n->AddYpoint(3,64.9,64.1,53.3,65.8,57.7); TDR_Res_2n->AddYpoint(3,61.8,61.2,47.7,64.2,54.2); Perfect_2n->AddYpoint(3,82.8,82.8,81.2,83.0,80.9);
    DNN_3n->AddYpoint(3,52.1,54.7,44.7,50.7,47.3); DNN_Res_3n->AddYpoint(3,47.3,49.8,37.0,47.7,41.3); TDR_3n->AddYpoint(3,45.4,45.9,37.3,48.6,45.8); TDR_Res_3n->AddYpoint(3,41.5,42.0,29.6,46.4,40.7); Perfect_3n->AddYpoint(3,74.9,74.9,72.4,75.2,72.7);
    DNN_4n->AddYpoint(3,48.5,41.2,43.2,43.0,43.1); DNN_Res_4n->AddYpoint(3,41.0,34.8,32.0,38.6,34.4); TDR_4n->AddYpoint(3,50.3,50.7,45.0,37.5,40.2); TDR_Res_4n->AddYpoint(3,43.1,43.4,32.2,34.7,33.3); Perfect_4n->AddYpoint(3,67.8,67.7,64.5,67.6,64.1);
    DNN_5n->AddYpoint(3,55.2,60.5,60.6,36.7,49.9); DNN_Res_5n->AddYpoint(3,45.4,48.5,44.8,31.9,38.8); TDR_5n->AddYpoint(3,45.2,44.4,59.6,29.2,43.3); TDR_Res_5n->AddYpoint(3,38.4,37.9,44.1,25.9,34.6); Perfect_5n->AddYpoint(3,60.6,60.5,56.5,60.5,56.6);
    
    DNN_1n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_1n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_1n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_1n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_1n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_2n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_2n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_2n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_2n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_2n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_3n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_3n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_3n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_3n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_3n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_4n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_4n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_4n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_4n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_4n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_5n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_5n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_5n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_5n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_5n->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
    DNN_1n->AddXpoint(3,23.0); DNN_Res_1n->AddXpoint(3,23.0); TDR_1n->AddXpoint(3,23.0); TDR_Res_1n->AddXpoint(3,23.0); Perfect_1n->AddXpoint(3,23.0);
    DNN_2n->AddXpoint(3,23.0); DNN_Res_2n->AddXpoint(3,23.0); TDR_2n->AddXpoint(3,23.0); TDR_Res_2n->AddXpoint(3,23.0); Perfect_2n->AddXpoint(3,23.0);
    DNN_3n->AddXpoint(3,23.0); DNN_Res_3n->AddXpoint(3,23.0); TDR_3n->AddXpoint(3,23.0); TDR_Res_3n->AddXpoint(3,23.0); Perfect_3n->AddXpoint(3,23.0);
    DNN_4n->AddXpoint(3,23.0); DNN_Res_4n->AddXpoint(3,23.0); TDR_4n->AddXpoint(3,23.0); TDR_Res_4n->AddXpoint(3,23.0); Perfect_4n->AddXpoint(3,23.0);
    DNN_5n->AddXpoint(3,23.0); DNN_Res_5n->AddXpoint(3,23.0); TDR_5n->AddXpoint(3,23.0); TDR_Res_5n->AddXpoint(3,23.0); Perfect_5n->AddXpoint(3,23.0);
   
    // ------------------------------------------------------------
    
    // Then, add the 30dp scenario:
    DNN_1n->AddYpoint(4,88.8,87.4,87.4,86.8,85.1); DNN_Res_1n->AddYpoint(4,88.6,87.3,87.2,86.7,85.0); TDR_1n->AddYpoint(4,82.8,82.0,81.2,82.6,81.2); TDR_Res_1n->AddYpoint(4,82.8,81.9,81.1,82.5,81.1); Perfect_1n->AddYpoint(4,95.2,95.1,93.4,95.0,93.5);
    DNN_2n->AddYpoint(4,70.5,72.1,64.7,68.8,63.8); DNN_Res_2n->AddYpoint(4,69.2,70.7,63.1,67.4,61.8); TDR_2n->AddYpoint(4,58.4,66.2,53.4,67.6,62.3); TDR_Res_2n->AddYpoint(4,57.2,64.9,51.8,66.3,60.6); Perfect_2n->AddYpoint(4,90.4,90.5,87.6,90.4,87.5);
    DNN_3n->AddYpoint(4,60.2,60.6,53.4,59.1,54.1); DNN_Res_3n->AddYpoint(4,57.1,57.5,49.7,55.6,49.6); TDR_3n->AddYpoint(4,65.1,57.2,60.3,57.9,52.6); TDR_Res_3n->AddYpoint(4,61.1,54.2,54.8,55.1,48.9); Perfect_3n->AddYpoint(4,85.6,85.6,81.2,85.6,81.2);
    DNN_4n->AddYpoint(4,55.2,52.6,47.8,49.7,46.1); DNN_Res_4n->AddYpoint(4,50.3,47.8,42.2,44.6,39.6); TDR_4n->AddYpoint(4,55.4,57.7,50.0,55.0,49.5); TDR_Res_4n->AddYpoint(4,51.3,53.0,44.5,50.8,43.9); Perfect_4n->AddYpoint(4,80.4,80.3,74.8,80.3,74.6);
    DNN_5n->AddYpoint(4,63.3,66.2,49.1,69.3,60.9); DNN_Res_5n->AddYpoint(4,56.2,58.4,41.8,60.3,50.3); TDR_5n->AddYpoint(4,50.7,54.1,45.6,54.2,48.1); TDR_Res_5n->AddYpoint(4,45.9,48.8,39.1,48.8,41.1); Perfect_5n->AddYpoint(4,75.1,75.1,67.9,75.1,68.0);
    
    DNN_1n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_1n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_1n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_1n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_1n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_2n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_2n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_2n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_2n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_2n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_3n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_3n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_3n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_3n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_3n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_4n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_4n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_4n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_4n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_4n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    DNN_5n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); DNN_Res_5n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_5n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); TDR_Res_5n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN); Perfect_5n->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
    DNN_1n->AddXpoint(4,30.0); DNN_Res_1n->AddXpoint(4,30.0); TDR_1n->AddXpoint(4,30.0); TDR_Res_1n->AddXpoint(4,30.0); Perfect_1n->AddXpoint(4,30.0);
    DNN_2n->AddXpoint(4,30.0); DNN_Res_2n->AddXpoint(4,30.0); TDR_2n->AddXpoint(4,30.0); TDR_Res_2n->AddXpoint(4,30.0); Perfect_2n->AddXpoint(4,30.0);
    DNN_3n->AddXpoint(4,30.0); DNN_Res_3n->AddXpoint(4,30.0); TDR_3n->AddXpoint(4,30.0); TDR_Res_3n->AddXpoint(4,30.0); Perfect_3n->AddXpoint(4,30.0);
    DNN_4n->AddXpoint(4,30.0); DNN_Res_4n->AddXpoint(4,30.0); TDR_4n->AddXpoint(4,30.0); TDR_Res_4n->AddXpoint(4,30.0); Perfect_4n->AddXpoint(4,30.0);
    DNN_5n->AddXpoint(4,30.0); DNN_Res_5n->AddXpoint(4,30.0); TDR_5n->AddXpoint(4,30.0); TDR_Res_5n->AddXpoint(4,30.0); Perfect_5n->AddXpoint(4,30.0);
   
    // ------------------------------------------------------------
    
    // Next, start building graphs:
    
    DNN_1n->ComputeGraph(); DNN_Res_1n->ComputeGraph(); TDR_1n->ComputeGraph(); TDR_Res_1n->ComputeGraph(); Perfect_1n->ComputeGraph();
    DNN_2n->ComputeGraph(); DNN_Res_2n->ComputeGraph(); TDR_2n->ComputeGraph(); TDR_Res_2n->ComputeGraph(); Perfect_2n->ComputeGraph();
    DNN_3n->ComputeGraph(); DNN_Res_3n->ComputeGraph(); TDR_3n->ComputeGraph(); TDR_Res_3n->ComputeGraph(); Perfect_3n->ComputeGraph();
    DNN_4n->ComputeGraph(); DNN_Res_4n->ComputeGraph(); TDR_4n->ComputeGraph(); TDR_Res_4n->ComputeGraph(); Perfect_4n->ComputeGraph();
    DNN_5n->ComputeGraph(); DNN_Res_5n->ComputeGraph(); TDR_5n->ComputeGraph(); TDR_Res_5n->ComputeGraph(); Perfect_5n->ComputeGraph();
    
    // ------------------------------------------------------------

    // Plot graphs:
    Double_t ScaleFactor = 4.0;
    gROOT->SetBatch(kTRUE);
    
    TGraphErrors** PerfectGraphs = new TGraphErrors*[5];
    PerfectGraphs[0] = Perfect_1n->GetDataGraph();
    PerfectGraphs[1] = Perfect_2n->GetDataGraph();
    PerfectGraphs[2] = Perfect_3n->GetDataGraph();
    PerfectGraphs[3] = Perfect_4n->GetDataGraph();
    PerfectGraphs[4] = Perfect_5n->GetDataGraph();
    
    TString* Titles = new TString[5];
    Titles[0] = "Particle Gun: n=1";
    Titles[1] = "Particle Gun: n=2";
    Titles[2] = "Particle Gun: n=3";
    Titles[3] = "Particle Gun: n=4";
    Titles[4] = "Particle Gun: n=5";
    
    TCanvas* c1 = DrawGraphDoumaArray(5,3,2,PerfectGraphs,Titles,"Nr. of NeuLAND dp","Efficiency [%]",ScaleFactor,0,"AP");
    // DNN_1n->GetDataGraph()->SetLineStyle(1);
    
    // Draw Perfect graphs:
    Perfect_1n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_1n->GetDataGraph()->SetLineColor(kBlack); c1->cd(1); Perfect_1n->GetDataGraph()->Draw("PLsame");
    Perfect_2n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_2n->GetDataGraph()->SetLineColor(kBlack); c1->cd(2); Perfect_2n->GetDataGraph()->Draw("PLsame");
    Perfect_3n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_3n->GetDataGraph()->SetLineColor(kBlack); c1->cd(3); Perfect_3n->GetDataGraph()->Draw("PLsame");
    Perfect_4n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_4n->GetDataGraph()->SetLineColor(kBlack); c1->cd(4); Perfect_4n->GetDataGraph()->Draw("PLsame");
    Perfect_5n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_5n->GetDataGraph()->SetLineColor(kBlack); c1->cd(5); Perfect_5n->GetDataGraph()->Draw("PLsame");
    
    // Draw DNN graphs:
    DNN_1n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_1n->GetDataGraph()->SetLineColor(kRed);   c1->cd(1); DNN_1n->GetDataGraph()->Draw("PLsame");
    DNN_2n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_2n->GetDataGraph()->SetLineColor(kRed);   c1->cd(2); DNN_2n->GetDataGraph()->Draw("PLsame");
    DNN_3n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_3n->GetDataGraph()->SetLineColor(kRed);   c1->cd(3); DNN_3n->GetDataGraph()->Draw("PLsame");
    DNN_4n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_4n->GetDataGraph()->SetLineColor(kRed);   c1->cd(4); DNN_4n->GetDataGraph()->Draw("PLsame");
    DNN_5n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_5n->GetDataGraph()->SetLineColor(kRed);   c1->cd(5); DNN_5n->GetDataGraph()->Draw("PLsame");

    // Draw TDR graphs:
    TDR_1n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_1n->GetDataGraph()->SetLineColor(kBlue);  c1->cd(1); TDR_1n->GetDataGraph()->Draw("PLsame");
    TDR_2n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_2n->GetDataGraph()->SetLineColor(kBlue);  c1->cd(2); TDR_2n->GetDataGraph()->Draw("PLsame");
    TDR_3n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_3n->GetDataGraph()->SetLineColor(kBlue);  c1->cd(3); TDR_3n->GetDataGraph()->Draw("PLsame");
    TDR_4n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_4n->GetDataGraph()->SetLineColor(kBlue);  c1->cd(4); TDR_4n->GetDataGraph()->Draw("PLsame");
    TDR_5n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_5n->GetDataGraph()->SetLineColor(kBlue);  c1->cd(5); TDR_5n->GetDataGraph()->Draw("PLsame");

    // Draw Perfect Physics Errors:
    Perfect_1n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_1n->GetPhysGraph()->SetLineColor(kBlack); Perfect_1n->GetPhysGraph()->SetFillStyle(3000); Perfect_1n->GetPhysGraph()->SetFillColor(kGray+2); c1->cd(1); Perfect_1n->GetPhysGraph()->Draw("3same");
    Perfect_2n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_2n->GetPhysGraph()->SetLineColor(kBlack); Perfect_2n->GetPhysGraph()->SetFillStyle(3000); Perfect_2n->GetPhysGraph()->SetFillColor(kGray+2); c1->cd(2); Perfect_2n->GetPhysGraph()->Draw("3same");
    Perfect_3n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_3n->GetPhysGraph()->SetLineColor(kBlack); Perfect_3n->GetPhysGraph()->SetFillStyle(3000); Perfect_3n->GetPhysGraph()->SetFillColor(kGray+2); c1->cd(3); Perfect_3n->GetPhysGraph()->Draw("3same");
    Perfect_4n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_4n->GetPhysGraph()->SetLineColor(kBlack); Perfect_4n->GetPhysGraph()->SetFillStyle(3000); Perfect_4n->GetPhysGraph()->SetFillColor(kGray+2); c1->cd(4); Perfect_4n->GetPhysGraph()->Draw("3same");
    Perfect_5n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); Perfect_5n->GetPhysGraph()->SetLineColor(kBlack); Perfect_5n->GetPhysGraph()->SetFillStyle(3000); Perfect_5n->GetPhysGraph()->SetFillColor(kGray+2); c1->cd(5); Perfect_5n->GetPhysGraph()->Draw("3same");
    
    // Draw DNN Physics Errors:
    DNN_1n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_1n->GetPhysGraph()->SetLineColor(kRed);   DNN_1n->GetPhysGraph()->SetFillStyle(3000); DNN_1n->GetPhysGraph()->SetFillColor(kRed-7);   c1->cd(1); DNN_1n->GetPhysGraph()->Draw("3same");
    DNN_2n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_2n->GetPhysGraph()->SetLineColor(kRed);   DNN_2n->GetPhysGraph()->SetFillStyle(3000); DNN_2n->GetPhysGraph()->SetFillColor(kRed-7);   c1->cd(2); DNN_2n->GetPhysGraph()->Draw("3same");
    DNN_3n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_3n->GetPhysGraph()->SetLineColor(kRed);   DNN_3n->GetPhysGraph()->SetFillStyle(3000); DNN_3n->GetPhysGraph()->SetFillColor(kRed-7);   c1->cd(3); DNN_3n->GetPhysGraph()->Draw("3same");
    DNN_4n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_4n->GetPhysGraph()->SetLineColor(kRed);   DNN_4n->GetPhysGraph()->SetFillStyle(3000); DNN_4n->GetPhysGraph()->SetFillColor(kRed-7);   c1->cd(4); DNN_4n->GetPhysGraph()->Draw("3same");
    DNN_5n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_5n->GetPhysGraph()->SetLineColor(kRed);   DNN_5n->GetPhysGraph()->SetFillStyle(3000); DNN_5n->GetPhysGraph()->SetFillColor(kRed-7);   c1->cd(5); DNN_5n->GetPhysGraph()->Draw("3same");

    // Draw TDR Physics Errors:
    TDR_1n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_1n->GetPhysGraph()->SetLineColor(kBlue);  TDR_1n->GetPhysGraph()->SetFillStyle(3000); TDR_1n->GetPhysGraph()->SetFillColor(kAzure-2); c1->cd(1); TDR_1n->GetPhysGraph()->Draw("3same");
    TDR_2n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_2n->GetPhysGraph()->SetLineColor(kBlue);  TDR_2n->GetPhysGraph()->SetFillStyle(3000); TDR_2n->GetPhysGraph()->SetFillColor(kAzure-2); c1->cd(2); TDR_2n->GetPhysGraph()->Draw("3same");
    TDR_3n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_3n->GetPhysGraph()->SetLineColor(kBlue);  TDR_3n->GetPhysGraph()->SetFillStyle(3000); TDR_3n->GetPhysGraph()->SetFillColor(kAzure-2); c1->cd(3); TDR_3n->GetPhysGraph()->Draw("3same");
    TDR_4n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_4n->GetPhysGraph()->SetLineColor(kBlue);  TDR_4n->GetPhysGraph()->SetFillStyle(3000); TDR_4n->GetPhysGraph()->SetFillColor(kAzure-2); c1->cd(4); TDR_4n->GetPhysGraph()->Draw("3same");
    TDR_5n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_5n->GetPhysGraph()->SetLineColor(kBlue);  TDR_5n->GetPhysGraph()->SetFillStyle(3000); TDR_5n->GetPhysGraph()->SetFillColor(kAzure-2); c1->cd(5); TDR_5n->GetPhysGraph()->Draw("3same");
    
    // Draw Restricted DNN graphs:
    //DNN_Res_1n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); DNN_Res_1n->GetDataGraph()->SetLineColor(kRed); DNN_Res_1n->GetDataGraph()->SetLineStyle(2); c1->cd(1); DNN_Res_1n->GetDataGraph()->Draw("PLsame");
    DNN_Res_2n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); DNN_Res_2n->GetDataGraph()->SetLineColor(kRed); DNN_Res_2n->GetDataGraph()->SetLineStyle(2); c1->cd(2); DNN_Res_2n->GetDataGraph()->Draw("PLsame");
    DNN_Res_3n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); DNN_Res_3n->GetDataGraph()->SetLineColor(kRed); DNN_Res_3n->GetDataGraph()->SetLineStyle(2); c1->cd(3); DNN_Res_3n->GetDataGraph()->Draw("PLsame");
    DNN_Res_4n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); DNN_Res_4n->GetDataGraph()->SetLineColor(kRed); DNN_Res_4n->GetDataGraph()->SetLineStyle(2); c1->cd(4); DNN_Res_4n->GetDataGraph()->Draw("PLsame");
    DNN_Res_5n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); DNN_Res_5n->GetDataGraph()->SetLineColor(kRed); DNN_Res_5n->GetDataGraph()->SetLineStyle(2); c1->cd(5); DNN_Res_5n->GetDataGraph()->Draw("PLsame");

    // Draw TDR graphs:
    //TDR_Res_1n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); TDR_Res_1n->GetDataGraph()->SetLineColor(kBlue); TDR_Res_1n->GetDataGraph()->SetLineStyle(2); c1->cd(1); TDR_Res_1n->GetDataGraph()->Draw("PLsame");
    TDR_Res_2n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); TDR_Res_2n->GetDataGraph()->SetLineColor(kBlue); TDR_Res_2n->GetDataGraph()->SetLineStyle(2); c1->cd(2); TDR_Res_2n->GetDataGraph()->Draw("PLsame");
    TDR_Res_3n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); TDR_Res_3n->GetDataGraph()->SetLineColor(kBlue); TDR_Res_3n->GetDataGraph()->SetLineStyle(2); c1->cd(3); TDR_Res_3n->GetDataGraph()->Draw("PLsame");
    TDR_Res_4n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); TDR_Res_4n->GetDataGraph()->SetLineColor(kBlue); TDR_Res_4n->GetDataGraph()->SetLineStyle(2); c1->cd(4); TDR_Res_4n->GetDataGraph()->Draw("PLsame");
    TDR_Res_5n->GetDataGraph()->SetLineWidth(ScaleFactor*0.8); TDR_Res_5n->GetDataGraph()->SetLineColor(kBlue); TDR_Res_5n->GetDataGraph()->SetLineStyle(2); c1->cd(5); TDR_Res_5n->GetDataGraph()->Draw("PLsame");

    // Save & Close:
    c1->SaveAs("./AllMult_200MeV.png");
    c1->Close();
    
    // ----------------------------------------------------------------------
    
    // Generate Relative graphs:
    Double_t DNN_RelPhsheight = 3.0;
    Double_t TDR_RelPhsheight = 2.5;
    
    DNN_1n->GetRelativeGraph(DNN_Res_1n,DNN_RelPhsheight);
    DNN_2n->GetRelativeGraph(DNN_Res_2n,DNN_RelPhsheight);
    DNN_3n->GetRelativeGraph(DNN_Res_3n,DNN_RelPhsheight);
    DNN_4n->GetRelativeGraph(DNN_Res_4n,DNN_RelPhsheight);
    DNN_5n->GetRelativeGraph(DNN_Res_5n,DNN_RelPhsheight);
    
    TDR_1n->GetRelativeGraph(TDR_Res_1n,TDR_RelPhsheight);
    TDR_2n->GetRelativeGraph(TDR_Res_2n,TDR_RelPhsheight);
    TDR_3n->GetRelativeGraph(TDR_Res_3n,TDR_RelPhsheight);
    TDR_4n->GetRelativeGraph(TDR_Res_4n,TDR_RelPhsheight);
    TDR_5n->GetRelativeGraph(TDR_Res_5n,TDR_RelPhsheight);
    
    // Make the next painting:
    TCanvas* c2 = DrawGraphDoumaArray3(5,3,2,PerfectGraphs,Titles,"Nr. of NeuLAND dp","False Pos./True Pos. [dim. less]",ScaleFactor,0,"AP");
    
    // Draw DNN Physics Errors:
    DNN_1n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_1n->GetPhysGraph()->SetLineColor(kRed);   DNN_1n->GetPhysGraph()->SetFillStyle(3000); DNN_1n->GetPhysGraph()->SetFillColor(kRed-7);   c2->cd(1); DNN_1n->GetPhysGraph()->Draw("3same");
    DNN_2n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_2n->GetPhysGraph()->SetLineColor(kRed);   DNN_2n->GetPhysGraph()->SetFillStyle(3000); DNN_2n->GetPhysGraph()->SetFillColor(kRed-7);   c2->cd(2); DNN_2n->GetPhysGraph()->Draw("3same");
    DNN_3n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_3n->GetPhysGraph()->SetLineColor(kRed);   DNN_3n->GetPhysGraph()->SetFillStyle(3000); DNN_3n->GetPhysGraph()->SetFillColor(kRed-7);   c2->cd(3); DNN_3n->GetPhysGraph()->Draw("3same");
    DNN_4n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_4n->GetPhysGraph()->SetLineColor(kRed);   DNN_4n->GetPhysGraph()->SetFillStyle(3000); DNN_4n->GetPhysGraph()->SetFillColor(kRed-7);   c2->cd(4); DNN_4n->GetPhysGraph()->Draw("3same");
    DNN_5n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); DNN_5n->GetPhysGraph()->SetLineColor(kRed);   DNN_5n->GetPhysGraph()->SetFillStyle(3000); DNN_5n->GetPhysGraph()->SetFillColor(kRed-7);   c2->cd(5); DNN_5n->GetPhysGraph()->Draw("3same");

    // Draw TDR Physics Errors:
    TDR_1n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_1n->GetPhysGraph()->SetLineColor(kBlue);  TDR_1n->GetPhysGraph()->SetFillStyle(3000); TDR_1n->GetPhysGraph()->SetFillColor(kAzure-2); c2->cd(1); TDR_1n->GetPhysGraph()->Draw("3same");
    TDR_2n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_2n->GetPhysGraph()->SetLineColor(kBlue);  TDR_2n->GetPhysGraph()->SetFillStyle(3000); TDR_2n->GetPhysGraph()->SetFillColor(kAzure-2); c2->cd(2); TDR_2n->GetPhysGraph()->Draw("3same");
    TDR_3n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_3n->GetPhysGraph()->SetLineColor(kBlue);  TDR_3n->GetPhysGraph()->SetFillStyle(3000); TDR_3n->GetPhysGraph()->SetFillColor(kAzure-2); c2->cd(3); TDR_3n->GetPhysGraph()->Draw("3same");
    TDR_4n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_4n->GetPhysGraph()->SetLineColor(kBlue);  TDR_4n->GetPhysGraph()->SetFillStyle(3000); TDR_4n->GetPhysGraph()->SetFillColor(kAzure-2); c2->cd(4); TDR_4n->GetPhysGraph()->Draw("3same");
    TDR_5n->GetPhysGraph()->SetLineWidth(ScaleFactor*1.5); TDR_5n->GetPhysGraph()->SetLineColor(kBlue);  TDR_5n->GetPhysGraph()->SetFillStyle(3000); TDR_5n->GetPhysGraph()->SetFillColor(kAzure-2); c2->cd(5); TDR_5n->GetPhysGraph()->Draw("3same");
    
    // Draw DNN graphs:
    DNN_1n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_1n->GetDataGraph()->SetLineColor(kRed);   c2->cd(1); DNN_1n->GetDataGraph()->Draw("PLsame");
    DNN_2n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_2n->GetDataGraph()->SetLineColor(kRed);   c2->cd(2); DNN_2n->GetDataGraph()->Draw("PLsame");
    DNN_3n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_3n->GetDataGraph()->SetLineColor(kRed);   c2->cd(3); DNN_3n->GetDataGraph()->Draw("PLsame");
    DNN_4n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_4n->GetDataGraph()->SetLineColor(kRed);   c2->cd(4); DNN_4n->GetDataGraph()->Draw("PLsame");
    DNN_5n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); DNN_5n->GetDataGraph()->SetLineColor(kRed);   c2->cd(5); DNN_5n->GetDataGraph()->Draw("PLsame");

    // Draw TDR graphs:
    TDR_1n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_1n->GetDataGraph()->SetLineColor(kBlue);  c2->cd(1); TDR_1n->GetDataGraph()->Draw("PLsame");
    TDR_2n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_2n->GetDataGraph()->SetLineColor(kBlue);  c2->cd(2); TDR_2n->GetDataGraph()->Draw("PLsame");
    TDR_3n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_3n->GetDataGraph()->SetLineColor(kBlue);  c2->cd(3); TDR_3n->GetDataGraph()->Draw("PLsame");
    TDR_4n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_4n->GetDataGraph()->SetLineColor(kBlue);  c2->cd(4); TDR_4n->GetDataGraph()->Draw("PLsame");
    TDR_5n->GetDataGraph()->SetLineWidth(ScaleFactor*1.5); TDR_5n->GetDataGraph()->SetLineColor(kBlue);  c2->cd(5); TDR_5n->GetDataGraph()->Draw("PLsame");
      
    c2->SaveAs("./Mult_SignalToNoise_200MeV.png");
    c2->Close();
}
