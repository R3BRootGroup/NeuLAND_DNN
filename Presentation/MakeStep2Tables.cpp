#include "DrawHistDouma.h"

void MakeStep2Tables()
{
    // Create the DNN Datagraphs:
    DNNDataGraph* Primary_DNNScoring_True         = new DNNDataGraph();
    DNNDataGraph* Primary_DNNScoring_UpperBound   = new DNNDataGraph();
    DNNDataGraph* Primary_ScoringPlus             = new DNNDataGraph();
    DNNDataGraph* Primary_RvalueSort              = new DNNDataGraph();
    DNNDataGraph* Primary_FullTDR                 = new DNNDataGraph();
    
    DNNDataGraph* Secondary_DNNScoring_True       = new DNNDataGraph();
    DNNDataGraph* Secondary_DNNScoring_UpperBound = new DNNDataGraph();
    DNNDataGraph* Secondary_ScoringPlus           = new DNNDataGraph();
    DNNDataGraph* Secondary_RvalueSort            = new DNNDataGraph();
    DNNDataGraph* Secondary_FullTDR               = new DNNDataGraph();
    
    // Add Y-points: index,INCL_INCL,INCL_INCL_2nd,INCL_BERT,BERT_INCL,BERT_BERT.
    // Do this 15 times for the different scenarios: 30dp_1000MeV, 30dp_600MeV, 30dp_200MeV, 16dp_1000MeV, 16dp_600MeV, 16dp_200MeV, 8dp_1000MeV, 8dp_600MeV, 8dp_200MeV
    //                                               12dp_1000MeV, 12dp_600MeV, 12dp_200MeV, 23dp_1000MeV, 23dp_600MeV, 23dp_200MeV
    
    // If NeuLAND is thin and/or neutron energy is low, we have more prim. clusters, meaning
    // that it is easier to correctly identify prim. as such than sec. as such. For high neutron
    // energy and/or lots of dp, it is the other way around. On top of that, we have the effect
    // that high neutron energy and/or lots of dp allow for more complicated clusters meaning
    // that the difference between R-value sorting and DNNScoring becomes larger.
    Double_t SqrtN = 0.1;
    
    // Scenario 30dp_1000MeV:
            Primary_DNNScoring_True->AddYpoint(0,77.71,78.06,77.47,74.70,75.93);
      Primary_DNNScoring_UpperBound->AddYpoint(0,86.45,86.76,85.84,84.01,84.46);
                Primary_ScoringPlus->AddYpoint(0,61.75,62.15,63.52,58.78,61.31);
                 Primary_RvalueSort->AddYpoint(0,55.48,55.96,54.75,53.15,53.03);
                    Primary_FullTDR->AddYpoint(0,57.01,56.47,58.75,53.03,54.25);
    
          Secondary_DNNScoring_True->AddYpoint(0,96.54,96.46,96.63,96.85,96.89);
    Secondary_DNNScoring_UpperBound->AddYpoint(0,97.29,97.21,97.21,97.65,97.48);
              Secondary_ScoringPlus->AddYpoint(0,95.18,95.10,95.67,95.49,95.87);
               Secondary_RvalueSort->AddYpoint(0,94.64,94.57,95.06,95.00,95.30);
                  Secondary_FullTDR->AddYpoint(0,94.21,94.26,94.42,94.74,94.95);
    
    // Scenario 30dp_600MeV:
            Primary_DNNScoring_True->AddYpoint(1,79.60,79.80,77.29,76.39,75.68);
      Primary_DNNScoring_UpperBound->AddYpoint(1,90.81,91.03,89.14,88.05,87.68);
                Primary_ScoringPlus->AddYpoint(1,66.52,67.09,65.83,63.35,63.66);
                 Primary_RvalueSort->AddYpoint(1,61.33,62.22,59.06,58.48,57.13);
                    Primary_FullTDR->AddYpoint(1,61.61,62.44,61.33,57.95,57.66);
    
          Secondary_DNNScoring_True->AddYpoint(1,95.18,94.82,95.11,95.07,95.54);
    Secondary_DNNScoring_UpperBound->AddYpoint(1,97.06,96.82,96.68,97.66,97.13);
              Secondary_ScoringPlus->AddYpoint(1,92.99,92.56,93.59,93.51,93.96);
               Secondary_RvalueSort->AddYpoint(1,92.11,91.70,92.70,92.69,93.09);
                  Secondary_FullTDR->AddYpoint(1,91.80,91.39,92.06,92.56,92.84);

    // Scenario 30dp_200MeV:
            Primary_DNNScoring_True->AddYpoint(2,80.34,80.64,72.07,81.44,75.10);
      Primary_DNNScoring_UpperBound->AddYpoint(2,94.80,95.04,90.77,95.37,92.69);
                Primary_ScoringPlus->AddYpoint(2,73.39,73.66,64.21,74.34,66.71);
                 Primary_RvalueSort->AddYpoint(2,71.48,71.76,63.03,72.18,64.51);
                    Primary_FullTDR->AddYpoint(2,71.12,71.26,63.86,70.88,63.55);
    
          Secondary_DNNScoring_True->AddYpoint(2,89.29,89.17,88.47,88.92,88.05);
    Secondary_DNNScoring_UpperBound->AddYpoint(2,96.41,96.25,96.46,95.77,95.57);
              Secondary_ScoringPlus->AddYpoint(2,85.87,85.73,85.11,85.43,84.46);
               Secondary_RvalueSort->AddYpoint(2,84.94,84.81,84.62,84.38,83.54);
                  Secondary_FullTDR->AddYpoint(2,84.58,84.59,83.63,84.78,83.87);
                  
    // Scenario 16dp_1000MeV:
            Primary_DNNScoring_True->AddYpoint(3,80.12,80.88,80.18,79.60,80.41);
      Primary_DNNScoring_UpperBound->AddYpoint(3,88.24,88.75,88.21,87.98,88.32);
                Primary_ScoringPlus->AddYpoint(3,67.84,68.49,69.13,67.42,69.16);
                 Primary_RvalueSort->AddYpoint(3,59.99,60.76,60.17,59.97,60.68);
                    Primary_FullTDR->AddYpoint(3,61.12,60.75,61.51,59.94,60.39);
    
          Secondary_DNNScoring_True->AddYpoint(3,94.90,94.75,94.62,94.77,94.43);
    Secondary_DNNScoring_UpperBound->AddYpoint(3,95.90,95.72,95.55,95.81,95.34);
              Secondary_ScoringPlus->AddYpoint(3,93.38,93.22,93.34,93.26,93.13);
               Secondary_RvalueSort->AddYpoint(3,92.41,92.27,92.31,92.34,92.15);
                  Secondary_FullTDR->AddYpoint(3,91.82,91.93,91.75,92.04,91.98);
                  
    // Scenario 16dp_600MeV:
            Primary_DNNScoring_True->AddYpoint(4,81.89,82.34,80.10,80.99,79.67);
      Primary_DNNScoring_UpperBound->AddYpoint(4,91.77,92.36,90.58,91.23,90.34);
                Primary_ScoringPlus->AddYpoint(4,71.47,72.15,70.65,70.84,70.33);
                 Primary_RvalueSort->AddYpoint(4,65.12,65.99,63.83,64.62,63.67);
                    Primary_FullTDR->AddYpoint(4,64.78,64.71,63.76,64.70,63.72);
    
          Secondary_DNNScoring_True->AddYpoint(4,92.97,92.67,92.49,93.01,92.48);
    Secondary_DNNScoring_UpperBound->AddYpoint(4,95.27,95.00,94.85,95.39,94.87);
              Secondary_ScoringPlus->AddYpoint(4,90.55,90.30,90.37,90.66,90.39);
               Secondary_RvalueSort->AddYpoint(4,89.08,88.88,88.85,89.22,88.90);
                  Secondary_FullTDR->AddYpoint(4,88.70,88.74,88.43,88.72,88.45);
                  
    // Scenario 16dp_200MeV:
            Primary_DNNScoring_True->AddYpoint(5,82.81,82.34,74.78,84.50,78.53);
      Primary_DNNScoring_UpperBound->AddYpoint(5,95.04,94.68,91.04,95.95,93.55);
                Primary_ScoringPlus->AddYpoint(5,77.32,76.76,68.93,78.79,72.10);
                 Primary_RvalueSort->AddYpoint(5,74.34,73.82,66.12,75.68,68.42);
                    Primary_FullTDR->AddYpoint(5,73.15,73.12,65.59,74.44,66.85);
    
          Secondary_DNNScoring_True->AddYpoint(5,87.05,87.43,86.18,86.02,84.95);
    Secondary_DNNScoring_UpperBound->AddYpoint(5,94.22,94.66,94.87,92.73,92.98);
              Secondary_ScoringPlus->AddYpoint(5,83.83,84.15,83.05,82.67,81.51);
               Secondary_RvalueSort->AddYpoint(5,82.14,82.49,81.64,80.93,79.68);
                  Secondary_FullTDR->AddYpoint(5,82.07,82.06,81.15,81.14,80.07);
                  
    // Scenario 8dp_1000MeV:
            Primary_DNNScoring_True->AddYpoint(6,86.22,86.63,86.68,85.61,86.51);
      Primary_DNNScoring_UpperBound->AddYpoint(6,92.11,92.15,92.50,91.50,92.37);
                Primary_ScoringPlus->AddYpoint(6,79.22,79.28,80.09,78.38,79.82);
                 Primary_RvalueSort->AddYpoint(6,68.87,68.98,69.02,68.41,69.22);
                    Primary_FullTDR->AddYpoint(6,71.25,70.88,71.11,70.35,70.46);
    
          Secondary_DNNScoring_True->AddYpoint(6,90.01,89.92,89.29,89.95,89.03);
    Secondary_DNNScoring_UpperBound->AddYpoint(6,91.18,91.07,90.44,91.18,90.19);
              Secondary_ScoringPlus->AddYpoint(6,88.49,88.39,87.98,88.44,87.71);
               Secondary_RvalueSort->AddYpoint(6,86.45,86.35,85.92,86.47,85.75);
                  Secondary_FullTDR->AddYpoint(6,84.83,84.92,84.66,85.05,84.88);
                  
    // Scenario 8dp_600MeV:
            Primary_DNNScoring_True->AddYpoint(7,87.29,87.79,86.38,86.61,85.99);
      Primary_DNNScoring_UpperBound->AddYpoint(7,94.02,89.40,93.71,93.52,93.41);
                Primary_ScoringPlus->AddYpoint(7,80.74,81.34,80.44,80.09,79.92);
                 Primary_RvalueSort->AddYpoint(7,72.30,72.95,71.50,71.62,70.99);
                    Primary_FullTDR->AddYpoint(7,73.29,73.79,71.83,74.30,72.84);
    
          Secondary_DNNScoring_True->AddYpoint(7,87.63,87.01,86.78,87.87,86.90);
    Secondary_DNNScoring_UpperBound->AddYpoint(7,90.11,94.28,89.42,90.42,89.56);
              Secondary_ScoringPlus->AddYpoint(7,85.21,84.63,84.64,85.46,84.72);
               Secondary_RvalueSort->AddYpoint(7,82.29,81.77,81.69,82.53,81.77);
                  Secondary_FullTDR->AddYpoint(7,80.30,80.11,80.12,79.79,79.59);
                  
    // Scenario 8dp_200MeV:
            Primary_DNNScoring_True->AddYpoint(8,88.20,87.91,82.32,89.97,85.83);
      Primary_DNNScoring_UpperBound->AddYpoint(8,96.09,96.07,93.42,96.96,95.48);
                Primary_ScoringPlus->AddYpoint(8,85.03,85.16,79.17,86.94,82.61);
                 Primary_RvalueSort->AddYpoint(8,80.35,80.54,73.88,82.30,76.61);
                    Primary_FullTDR->AddYpoint(8,78.35,78.42,71.47,81.34,74.38);
    
          Secondary_DNNScoring_True->AddYpoint(8,80.04,79.52,79.23,76.82,75.72);
    Secondary_DNNScoring_UpperBound->AddYpoint(8,86.68,86.38,88.24,82.70,83.55);
              Secondary_ScoringPlus->AddYpoint(8,77.38,77.20,76.67,74.27,73.11);
               Secondary_RvalueSort->AddYpoint(8,74.17,74.04,73.38,71.44,69.84);
                  Secondary_FullTDR->AddYpoint(8,73.84,73.87,73.07,70.58,69.70);              
                  
    // Scenario 12dp_1000MeV:
            Primary_DNNScoring_True->AddYpoint(9,82.51,82.36,82.38,79.02,80.45);
      Primary_DNNScoring_UpperBound->AddYpoint(9,89.57,89.69,89.66,86.97,88.16);
                Primary_ScoringPlus->AddYpoint(9,71.59,71.71,72.89,68.18,70.60);
                 Primary_RvalueSort->AddYpoint(9,62.31,62.46,61.70,59.08,59.36);
                    Primary_FullTDR->AddYpoint(9,63.34,63.21,64.12,60.01,60.67);
    
          Secondary_DNNScoring_True->AddYpoint(9,93.88,93.82,93.82,94.64,94.43);
    Secondary_DNNScoring_UpperBound->AddYpoint(9,94.89,94.87,94.68,95.78,95.34);
              Secondary_ScoringPlus->AddYpoint(9,92.32,92.30,92.70,93.10,93.27);
               Secondary_RvalueSort->AddYpoint(9,91.00,90.99,91.39,91.80,91.95);
                  Secondary_FullTDR->AddYpoint(9,90.31,90.33,90.58,91.12,91.37); 
                  
    // Scenario 12dp_600MeV:
            Primary_DNNScoring_True->AddYpoint(10,83.83,84.53,81.81,80.82,72.77);
      Primary_DNNScoring_UpperBound->AddYpoint(10,92.68,93.20,91.91,90.27,90.31);
                Primary_ScoringPlus->AddYpoint(10,74.63,75.44,73.82,71.60,71.71);
                 Primary_RvalueSort->AddYpoint(10,66.89,67.85,64.55,63.80,62.29);
                    Primary_FullTDR->AddYpoint(10,66.65,66.25,65.74,63.30,62.67);
    
          Secondary_DNNScoring_True->AddYpoint(10,91.99,91.53,91.86,93.00,92.00);
    Secondary_DNNScoring_UpperBound->AddYpoint(10,94.27,93.78,94.00,95.45,94.83);
              Secondary_ScoringPlus->AddYpoint(10,89.61,89.18,90.17,90.61,90.90);
               Secondary_RvalueSort->AddYpoint(10,87.63,87.25,88.23,88.61,88.92);
                  Secondary_FullTDR->AddYpoint(10,86.92,87.07,87.21,87.94,88.23); 
                
    // Scenario 12dp_200MeV:
            Primary_DNNScoring_True->AddYpoint(11,85.00,84.86,76.49,83.91,77.32);
      Primary_DNNScoring_UpperBound->AddYpoint(11,95.60,95.37,92.98,93.53,92.74);
                Primary_ScoringPlus->AddYpoint(11,81.00,80.53,71.16,79.52,71.27);
                 Primary_RvalueSort->AddYpoint(11,76.55,76.15,66.41,74.75,65.89);
                    Primary_FullTDR->AddYpoint(11,74.61,74.33,65.60,73.00,64.02);
    
          Secondary_DNNScoring_True->AddYpoint(11,85.83,86.38,85.05,87.21,85.83);
    Secondary_DNNScoring_UpperBound->AddYpoint(11,92.31,92.80,92.51,94.25,92.82);
              Secondary_ScoringPlus->AddYpoint(11,83.39,83.73,82.64,84.53,83.09);
               Secondary_RvalueSort->AddYpoint(11,80.87,81.24,80.67,81.78,80.83);
                  Secondary_FullTDR->AddYpoint(11,81.22,81.40,80.24,82.25,81.35);
                  
    // Scenario 23dp_1000MeV:
            Primary_DNNScoring_True->AddYpoint(12,78.84,78.37,78.60,75.58,77.08);
      Primary_DNNScoring_UpperBound->AddYpoint(12,87.36,86.95,86.85,84.81,85.49);
                Primary_ScoringPlus->AddYpoint(12,63.98,63.42,65.66,60.77,63.50);
                 Primary_RvalueSort->AddYpoint(12,57.25,56.64,56.64,54.54,54.71);
                    Primary_FullTDR->AddYpoint(12,57.32,57.12,58.60,53.79,54.76);
    
          Secondary_DNNScoring_True->AddYpoint(12,96.02,96.12,96.09,96.39,96.37);
    Secondary_DNNScoring_UpperBound->AddYpoint(12,96.83,96.94,96.72,97.27,97.02);
              Secondary_ScoringPlus->AddYpoint(12,94.61,94.69,95.09,94.98,95.32);
               Secondary_RvalueSort->AddYpoint(12,93.97,94.05,94.39,94.38,94.64);
                  Secondary_FullTDR->AddYpoint(12,93.70,93.71,93.95,94.24,94.46); 
                  
    // Scenario 23dp_600MeV:
            Primary_DNNScoring_True->AddYpoint(13,80.63,79.83,77.68,78.10,77.16);
      Primary_DNNScoring_UpperBound->AddYpoint(13,90.82,90.78,89.42,89.31,88.77);
                Primary_ScoringPlus->AddYpoint(13,67.74,67.58,67.08,65.72,65.84);
                 Primary_RvalueSort->AddYpoint(13,62.02,61.86,59.71,60.40,58.81);
                    Primary_FullTDR->AddYpoint(13,62.10,62.06,61.70,58.39,57.90);
    
          Secondary_DNNScoring_True->AddYpoint(13,94.68,94.73,94.59,95.01,94.80);
    Secondary_DNNScoring_UpperBound->AddYpoint(13,96.67,96.74,96.30,97.06,96.50);
              Secondary_ScoringPlus->AddYpoint(13,92.44,92.49,93.04,92.74,93.15);
               Secondary_RvalueSort->AddYpoint(13,91.39,91.44,91.96,91.76,92.12);
                  Secondary_FullTDR->AddYpoint(13,91.10,91.12,91.35,91.94,92.14); 
                
    // Scenario 23dp_200MeV:
            Primary_DNNScoring_True->AddYpoint(14,81.62,81.82,72.88,78.81,72.29);
      Primary_DNNScoring_UpperBound->AddYpoint(14,95.10,95.18,92.16,91.89,90.64);
                Primary_ScoringPlus->AddYpoint(14,75.14,75.31,64.41,72.49,63.62);
                 Primary_RvalueSort->AddYpoint(14,72.41,72.59,61.96,69.15,60.35);
                    Primary_FullTDR->AddYpoint(14,71.83,71.75,62.93,67.94,59.64);
    
          Secondary_DNNScoring_True->AddYpoint(14,89.67,89.56,88.71,91.26,89.92);
    Secondary_DNNScoring_UpperBound->AddYpoint(14,96.19,96.01,95.06,97.58,95.96);
              Secondary_ScoringPlus->AddYpoint(14,86.54,86.42,85.92,88.21,87.06);
               Secondary_RvalueSort->AddYpoint(14,85.24,85.12,85.13,86.60,86.00);
                  Secondary_FullTDR->AddYpoint(14,85.01,85.06,84.17,86.88,86.14);
                  
    // -------------------------------------------------------------------------              
                  
    // Add all Errors:
            Primary_DNNScoring_True->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(0,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);

            Primary_DNNScoring_True->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(1,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(2,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(3,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(4,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(5,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(6,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(7,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(8,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(9,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(10,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(11,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(12,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(13,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
            Primary_DNNScoring_True->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
      Primary_DNNScoring_UpperBound->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                Primary_ScoringPlus->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                 Primary_RvalueSort->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                    Primary_FullTDR->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    
          Secondary_DNNScoring_True->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
    Secondary_DNNScoring_UpperBound->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
              Secondary_ScoringPlus->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
               Secondary_RvalueSort->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  Secondary_FullTDR->AddYerror(14,SqrtN,SqrtN,SqrtN,SqrtN,SqrtN);
                  
    // -------------------------------------------------------------------------
                  
    // Add X-values:
            Primary_DNNScoring_True->AddXpoint(0,1.0);
      Primary_DNNScoring_UpperBound->AddXpoint(0,1.0);
                Primary_ScoringPlus->AddXpoint(0,1.0);
                 Primary_RvalueSort->AddXpoint(0,1.0);
                    Primary_FullTDR->AddXpoint(0,1.0);
    
          Secondary_DNNScoring_True->AddXpoint(0,1.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(0,1.0);
              Secondary_ScoringPlus->AddXpoint(0,1.0);
               Secondary_RvalueSort->AddXpoint(0,1.0);
                  Secondary_FullTDR->AddXpoint(0,1.0);

            Primary_DNNScoring_True->AddXpoint(1,2.0);
      Primary_DNNScoring_UpperBound->AddXpoint(1,2.0);
                Primary_ScoringPlus->AddXpoint(1,2.0);
                 Primary_RvalueSort->AddXpoint(1,2.0);
                    Primary_FullTDR->AddXpoint(1,2.0);
    
          Secondary_DNNScoring_True->AddXpoint(1,2.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(1,2.0);
              Secondary_ScoringPlus->AddXpoint(1,2.0);
               Secondary_RvalueSort->AddXpoint(1,2.0);
                  Secondary_FullTDR->AddXpoint(1,2.0);
                  
            Primary_DNNScoring_True->AddXpoint(2,3.0);
      Primary_DNNScoring_UpperBound->AddXpoint(2,3.0);
                Primary_ScoringPlus->AddXpoint(2,3.0);
                 Primary_RvalueSort->AddXpoint(2,3.0);
                    Primary_FullTDR->AddXpoint(2,3.0);
    
          Secondary_DNNScoring_True->AddXpoint(2,3.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(2,3.0);
              Secondary_ScoringPlus->AddXpoint(2,3.0);
               Secondary_RvalueSort->AddXpoint(2,3.0);
                  Secondary_FullTDR->AddXpoint(2,3.0);
                  
            Primary_DNNScoring_True->AddXpoint(3,4.0);
      Primary_DNNScoring_UpperBound->AddXpoint(3,4.0);
                Primary_ScoringPlus->AddXpoint(3,4.0);
                 Primary_RvalueSort->AddXpoint(3,4.0);
                    Primary_FullTDR->AddXpoint(3,4.0);
    
          Secondary_DNNScoring_True->AddXpoint(3,4.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(3,4.0);
              Secondary_ScoringPlus->AddXpoint(3,4.0);
               Secondary_RvalueSort->AddXpoint(3,4.0);
                  Secondary_FullTDR->AddXpoint(3,4.0);
                  
            Primary_DNNScoring_True->AddXpoint(4,5.0);
      Primary_DNNScoring_UpperBound->AddXpoint(4,5.0);
                Primary_ScoringPlus->AddXpoint(4,5.0);
                 Primary_RvalueSort->AddXpoint(4,5.0);
                    Primary_FullTDR->AddXpoint(4,5.0);
    
          Secondary_DNNScoring_True->AddXpoint(4,5.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(4,5.0);
              Secondary_ScoringPlus->AddXpoint(4,5.0);
               Secondary_RvalueSort->AddXpoint(4,5.0);
                  Secondary_FullTDR->AddXpoint(4,5.0);
                  
            Primary_DNNScoring_True->AddXpoint(5,6.0);
      Primary_DNNScoring_UpperBound->AddXpoint(5,6.0);
                Primary_ScoringPlus->AddXpoint(5,6.0);
                 Primary_RvalueSort->AddXpoint(5,6.0);
                    Primary_FullTDR->AddXpoint(5,6.0);
    
          Secondary_DNNScoring_True->AddXpoint(5,6.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(5,6.0);
              Secondary_ScoringPlus->AddXpoint(5,6.0);
               Secondary_RvalueSort->AddXpoint(5,6.0);
                  Secondary_FullTDR->AddXpoint(5,6.0);
                  
            Primary_DNNScoring_True->AddXpoint(6,7.0);
      Primary_DNNScoring_UpperBound->AddXpoint(6,7.0);
                Primary_ScoringPlus->AddXpoint(6,7.0);
                 Primary_RvalueSort->AddXpoint(6,7.0);
                    Primary_FullTDR->AddXpoint(6,7.0);
    
          Secondary_DNNScoring_True->AddXpoint(6,7.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(6,7.0);
              Secondary_ScoringPlus->AddXpoint(6,7.0);
               Secondary_RvalueSort->AddXpoint(6,7.0);
                  Secondary_FullTDR->AddXpoint(6,7.0);
                  
            Primary_DNNScoring_True->AddXpoint(7,8.0);
      Primary_DNNScoring_UpperBound->AddXpoint(7,8.0);
                Primary_ScoringPlus->AddXpoint(7,8.0);
                 Primary_RvalueSort->AddXpoint(7,8.0);
                    Primary_FullTDR->AddXpoint(7,8.0);
    
          Secondary_DNNScoring_True->AddXpoint(7,8.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(7,8.0);
              Secondary_ScoringPlus->AddXpoint(7,8.0);
               Secondary_RvalueSort->AddXpoint(7,8.0);
                  Secondary_FullTDR->AddXpoint(7,8.0);
                  
            Primary_DNNScoring_True->AddXpoint(8,9.0);
      Primary_DNNScoring_UpperBound->AddXpoint(8,9.0);
                Primary_ScoringPlus->AddXpoint(8,9.0);
                 Primary_RvalueSort->AddXpoint(8,9.0);
                    Primary_FullTDR->AddXpoint(8,9.0);
    
          Secondary_DNNScoring_True->AddXpoint(8,9.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(8,9.0);
              Secondary_ScoringPlus->AddXpoint(8,9.0);
               Secondary_RvalueSort->AddXpoint(8,9.0);
                  Secondary_FullTDR->AddXpoint(8,9.0);
                  
            Primary_DNNScoring_True->AddXpoint(9,9.0);
      Primary_DNNScoring_UpperBound->AddXpoint(9,9.0);
                Primary_ScoringPlus->AddXpoint(9,9.0);
                 Primary_RvalueSort->AddXpoint(9,9.0);
                    Primary_FullTDR->AddXpoint(9,9.0);
    
          Secondary_DNNScoring_True->AddXpoint(9,9.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(9,9.0);
              Secondary_ScoringPlus->AddXpoint(9,9.0);
               Secondary_RvalueSort->AddXpoint(9,9.0);
                  Secondary_FullTDR->AddXpoint(9,9.0);
                  
            Primary_DNNScoring_True->AddXpoint(10,10.0);
      Primary_DNNScoring_UpperBound->AddXpoint(10,10.0);
                Primary_ScoringPlus->AddXpoint(10,10.0);
                 Primary_RvalueSort->AddXpoint(10,10.0);
                    Primary_FullTDR->AddXpoint(10,10.0);
    
          Secondary_DNNScoring_True->AddXpoint(10,10.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(10,10.0);
              Secondary_ScoringPlus->AddXpoint(10,10.0);
               Secondary_RvalueSort->AddXpoint(10,10.0);
                  Secondary_FullTDR->AddXpoint(10,10.0);
                  
            Primary_DNNScoring_True->AddXpoint(11,11.0);
      Primary_DNNScoring_UpperBound->AddXpoint(11,11.0);
                Primary_ScoringPlus->AddXpoint(11,11.0);
                 Primary_RvalueSort->AddXpoint(11,11.0);
                    Primary_FullTDR->AddXpoint(11,11.0);
    
          Secondary_DNNScoring_True->AddXpoint(11,11.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(11,11.0);
              Secondary_ScoringPlus->AddXpoint(11,11.0);
               Secondary_RvalueSort->AddXpoint(11,11.0);
                  Secondary_FullTDR->AddXpoint(11,11.0);
                  
            Primary_DNNScoring_True->AddXpoint(12,12.0);
      Primary_DNNScoring_UpperBound->AddXpoint(12,12.0);
                Primary_ScoringPlus->AddXpoint(12,12.0);
                 Primary_RvalueSort->AddXpoint(12,12.0);
                    Primary_FullTDR->AddXpoint(12,12.0);
    
          Secondary_DNNScoring_True->AddXpoint(12,12.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(12,12.0);
              Secondary_ScoringPlus->AddXpoint(12,12.0);
               Secondary_RvalueSort->AddXpoint(12,12.0);
                  Secondary_FullTDR->AddXpoint(12,12.0);
                  
            Primary_DNNScoring_True->AddXpoint(13,13.0);
      Primary_DNNScoring_UpperBound->AddXpoint(13,13.0);
                Primary_ScoringPlus->AddXpoint(13,13.0);
                 Primary_RvalueSort->AddXpoint(13,13.0);
                    Primary_FullTDR->AddXpoint(13,13.0);
    
          Secondary_DNNScoring_True->AddXpoint(13,13.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(13,13.0);
              Secondary_ScoringPlus->AddXpoint(13,13.0);
               Secondary_RvalueSort->AddXpoint(13,13.0);
                  Secondary_FullTDR->AddXpoint(13,13.0);
                  
            Primary_DNNScoring_True->AddXpoint(14,14.0);
      Primary_DNNScoring_UpperBound->AddXpoint(14,14.0);
                Primary_ScoringPlus->AddXpoint(14,14.0);
                 Primary_RvalueSort->AddXpoint(14,14.0);
                    Primary_FullTDR->AddXpoint(14,14.0);
    
          Secondary_DNNScoring_True->AddXpoint(14,14.0);
    Secondary_DNNScoring_UpperBound->AddXpoint(14,14.0);
              Secondary_ScoringPlus->AddXpoint(14,14.0);
               Secondary_RvalueSort->AddXpoint(14,14.0);
                  Secondary_FullTDR->AddXpoint(14,14.0);
                  
    // -------------------------------------------------------------------------
                  
    // Compose the true points:
                  
            Primary_DNNScoring_True->ComputeGraph();
      Primary_DNNScoring_UpperBound->ComputeGraph();
                Primary_ScoringPlus->ComputeGraph();
                 Primary_RvalueSort->ComputeGraph();
                    Primary_FullTDR->ComputeGraph();
    
          Secondary_DNNScoring_True->ComputeGraph();
    Secondary_DNNScoring_UpperBound->ComputeGraph();
              Secondary_ScoringPlus->ComputeGraph();
               Secondary_RvalueSort->ComputeGraph();
                  Secondary_FullTDR->ComputeGraph();
                  
    // Then, print the results:
    
    cout << "Primary_DNNScoring_True; Primary Clusters";       Primary_DNNScoring_True->PrintGraph();
    cout << "Primary_DNNScoring_UpperBound; Primary Clusters"; Primary_DNNScoring_UpperBound->PrintGraph();
    cout << "Primary_ScoringPlus; Primary Clusters";           Primary_ScoringPlus->PrintGraph();
    cout << "Primary_RvalueSort; Primary Clusters";            Primary_RvalueSort->PrintGraph();
    cout << "Primary_FullTDR; Primary Clusters";               Primary_FullTDR->PrintGraph();
    
    cout << "Secondary_DNNScoring_True; Secondary Clusters";       Secondary_DNNScoring_True->PrintGraph();
    cout << "Secondary_DNNScoring_UpperBound; Secondary Clusters"; Secondary_DNNScoring_UpperBound->PrintGraph();
    cout << "Secondary_ScoringPlus; Secondary Clusters";           Secondary_ScoringPlus->PrintGraph();
    cout << "Secondary_RvalueSort; Secondary Clusters";            Secondary_RvalueSort->PrintGraph();
    cout << "Secondary_FullTDR; Secondary Clusters";               Secondary_FullTDR->PrintGraph();          

    // Done.
}

