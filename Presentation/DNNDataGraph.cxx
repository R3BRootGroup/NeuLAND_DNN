// Include this class header:
#include "DNNDataGraph.h"

// Default Constructor:
DNNDataGraph::DNNDataGraph()
{
    Xpoints.clear();
    Ypoints.clear();
}
    
// Destructor:
DNNDataGraph::~DNNDataGraph()
{
    Xpoints.clear();
    Ypoints.clear();
}

// Member function definitions:
void DNNDataGraph::AddXpoint(Int_t const Index, Double_t const xx)
{
    // Generate new points if necessary:
    Int_t Size = Xpoints.size();
    
    if (Size>Index)
    {
        Xpoints.at(Index) = xx;
    }
    else
    {
        // Then, create the point:
        Int_t Diff = Index - Size + 1;
        
        for (Int_t k = 0; k<Diff; ++k)
        {
            Xpoints.push_back(xx);
        }
    }
        
    // Done.
}

void DNNDataGraph::AddYpoint(Int_t const Index, Double_t const INCL_INCL, Double_t const INCL_INCL_2nd, Double_t const INCL_BERT, Double_t const BERT_INCL, Double_t const BERT_BERT)
{
    // See if the point already exists:
    Int_t Size = Ypoints.size();
    
    if (Size>Index)
    {
        // Then it exists. So add it straight up:
        Ypoints.at(Index).Set_INCLXX_INCLXX(INCL_INCL,Ypoints.at(Index).Get_INCLXX_INCLXX_Error());
        Ypoints.at(Index).Set_INCLXX_INCLXX_2nd(INCL_INCL_2nd,Ypoints.at(Index).Get_INCLXX_INCLXX_2ndError());
        Ypoints.at(Index).Set_INCLXX_BERT(INCL_BERT,Ypoints.at(Index).Get_INCLXX_BERT_Error());
        Ypoints.at(Index).Set_BERT_INCLXX(BERT_INCL,Ypoints.at(Index).Get_BERT_INCLXX_Error());
        Ypoints.at(Index).Set_BERT_BERT(BERT_BERT,Ypoints.at(Index).Get_BERT_BERT_Error());
    }
    else
    {
        // Then, create it:
        DNNDataPoint NewPoint;
        
        NewPoint.Set_INCLXX_INCLXX(INCL_INCL,0.0);
        NewPoint.Set_INCLXX_INCLXX_2nd(INCL_INCL_2nd,0.0);
        NewPoint.Set_INCLXX_BERT(INCL_BERT,0.0);
        NewPoint.Set_BERT_INCLXX(BERT_INCL,0.0);
        NewPoint.Set_BERT_BERT(BERT_BERT,0.0);
        
        Int_t Diff = Index - Size + 1;
        
        for (Int_t k = 0; k<Diff; ++k)
        {
            Ypoints.push_back(NewPoint);
        }
    }
    
    // Done.
}

void DNNDataGraph::AddYerror(Int_t const Index, Double_t const INCL_INCL, Double_t const INCL_INCL_2nd, Double_t const INCL_BERT, Double_t const BERT_INCL, Double_t const BERT_BERT)
{
    // See if the point already exists:
    Int_t Size = Ypoints.size();
    
    if (Size>Index)
    {
        // Then it exists. So add it straight up:
        Ypoints.at(Index).Set_INCLXX_INCLXX(Ypoints.at(Index).Get_INCLXX_INCLXX_Value(),INCL_INCL);
        Ypoints.at(Index).Set_INCLXX_INCLXX_2nd(Ypoints.at(Index).Get_INCLXX_INCLXX_2ndValue(),INCL_INCL_2nd);
        Ypoints.at(Index).Set_INCLXX_BERT(Ypoints.at(Index).Get_INCLXX_BERT_Value(),INCL_BERT);
        Ypoints.at(Index).Set_BERT_INCLXX(Ypoints.at(Index).Get_BERT_INCLXX_Value(),BERT_INCL);
        Ypoints.at(Index).Set_BERT_BERT(Ypoints.at(Index).Get_BERT_BERT_Value(),BERT_BERT);
    }
    else
    {
        // Then, create it:
        DNNDataPoint NewPoint;
        
        NewPoint.Set_INCLXX_INCLXX(0.0,INCL_INCL);
        NewPoint.Set_INCLXX_INCLXX_2nd(0.0,INCL_INCL_2nd);
        NewPoint.Set_INCLXX_BERT(0.0,INCL_BERT);
        NewPoint.Set_BERT_INCLXX(0.0,BERT_INCL);
        NewPoint.Set_BERT_BERT(0.0,BERT_BERT);
        
        Int_t Diff = Index - Size + 1;
        
        for (Int_t k = 0; k<Diff; ++k)
        {
            Ypoints.push_back(NewPoint);
        }
    }
    
    // Done.
}

void DNNDataGraph::ComputeGraph()
{
    // We will compute the data-graphs:
    if (Xpoints.size()!=Ypoints.size())
    {
        cout << "### FATAL: We need the same number of X & Y points! X = " << Xpoints.size() << " & Y = " << Ypoints.size() << "\n\n";
    }
    else
    {
        // Now, we can work. Begin byh computing the proper points:
        Int_t Size = Xpoints.size();
        
        for (Int_t k = 0; k<Size; ++k)
        {
            Ypoints.at(k).ComputeAvgPoint();
        }
        
        // Generate arrays:
        Double_t* Xval = new Double_t[Size];
        Double_t* Xerr = new Double_t[Size];
        Double_t* Yval = new Double_t[Size];
        Double_t* Yerr = new Double_t[Size];
        Double_t* Yphys = new Double_t[Size];
        Double_t* Yphval = new Double_t[Size];
        
        // Fill Arrays:
        for (Int_t k = 0; k<Size; ++k)
        {
            Xval[k] = Xpoints.at(k);
            Xerr[k] = 0.0;
            Yval[k] = Ypoints.at(k).GetAvgPoint();
            Yerr[k] = Ypoints.at(k).GetStatError();
            Yphys[k] = Ypoints.at(k).GetPhysError();
            Yphval[k] = ErrorHeight;
        }
        
        // Generate the graphs:
        TheData = new TGraphErrors(Size,&Xval[0],&Yval[0],&Xerr[0],&Yerr[0]);
        PhysError = new TGraphErrors(Size,&Xval[0],&Yphval[0],&Xerr[0],&Yphys[0]);
        
        // Done.
    }
}

void DNNDataGraph::PrintGraph()
{
    // Print contents of the graphs:
    Int_t Npoints = TheData->GetN();
    Double_t Xpoint = 0.0;
    Double_t Ypoint = 0.0;
    Double_t Xerror = 0.0;
    Double_t Yerror = 0.0;
    Double_t PhysErr = 0.0;
    cout << "\n\n";
    
    for (Int_t k = 0; k<Npoints; ++k)
    {
        // Retrieve current point:
        TheData->GetPoint(k,Xpoint,Ypoint);
        Xerror = TheData->GetErrorX(k);
        Yerror = TheData->GetErrorY(k);
        PhysErr = PhysError->GetErrorY(k);
        
        // Print:
        cout << Ypoint << " /pm " << Yerror << " /pm " << PhysErr << "\n";
    }
    
    cout << "\n\n";
}

void DNNDataGraph::AddDNNGraph(DNNDataGraph* OtherGraph, Double_t const Scale)
{
    // Adds andother graph to this one.
    if ((TheData==0)||(TheData==nullptr)||(PhysError==0)||(PhysError==nullptr))
    {
        cout << "### FATAL: You need to compute the graph of this class before adding something else to it!\n\n";
    }
    else
    {
        if ((OtherGraph->GetDataGraph()==0)||(OtherGraph->GetDataGraph()==nullptr)||(OtherGraph->GetPhysGraph()==0)||(OtherGraph->GetPhysGraph()==nullptr))
        {
            cout << "### FATAL: You need to compute the graph to be added before you can add it to this graph!\n\n";
        }
        else
        {
            if (TheData->GetN()!=OtherGraph->GetDataGraph()->GetN())
            {
                cout << "### FATAL: Graphs that have to be added must have the same number of points!\n\n";
            }
            else
            {
                // Generate arrays:
                Int_t Size = TheData->GetN();
                Double_t* Xval = new Double_t[Size];
                Double_t* Xerr = new Double_t[Size];
                Double_t* Yval = new Double_t[Size];
                Double_t* Yerr = new Double_t[Size];
                Double_t* Yphys = new Double_t[Size];
                Double_t* Yphval = new Double_t[Size];
            
                // Declare what we need:
                Double_t ThisX;
                Double_t ThisY;
                Double_t ErrorX;
                Double_t ErrorY;
                Double_t PhysValY;
                Double_t PhysErrY;
            
                // Fill the arrays with the current graph:
                for (Int_t k = 0; k<Size; ++k)
                {
                    PhysError->GetPoint(k,ThisX,PhysValY);
                    TheData->GetPoint(k,ThisX,ThisY);
                    ErrorX = TheData->GetErrorX(k);
                    ErrorY = TheData->GetErrorY(k);
                    PhysErrY = PhysError->GetErrorY(k);
                    
                    Xval[k] = ThisX;
                    Xerr[k] = ErrorX;
                    Yval[k] = ThisY;
                    Yerr[k] = ErrorY;
                    Yphys[k] = PhysErrY;
                    Yphval[k] = PhysValY;
                }
                
                // Next, retrieve the other values and add them:
                Bool_t Xequal = kTRUE;
                
                for (Int_t k = 0; k<Size; ++k)
                {
                    OtherGraph->GetPhysGraph()->GetPoint(k,ThisX,PhysValY);
                    OtherGraph->GetDataGraph()->GetPoint(k,ThisX,ThisY);
                    ErrorX = OtherGraph->GetDataGraph()->GetErrorX(k);
                    ErrorY = OtherGraph->GetDataGraph()->GetErrorY(k);
                    PhysErrY = OtherGraph->GetPhysGraph()->GetErrorY(k);
                    
                    // Compare x-values:
                    if (TMath::Abs((Xval[k]-ThisX)/(Xval[k]+ThisX))>1e-6) {Xequal = kFALSE;}
                    if (TMath::Abs((Xerr[k]-ErrorX)/(Xerr[k]+ErrorX))>1e-6) {Xequal = kFALSE;}
                    
                    // Add Y-values:
                    Yval[k] = Yval[k] + Scale*ThisY;
                    Yerr[k] = TMath::Sqrt(TMath::Abs(Yerr[k]*Yerr[k] + Scale*Scale*ErrorY*ErrorY));
                    Yphval[k] = (Yphval[k]+TMath::Abs(Scale)*PhysValY)/(1.0+TMath::Abs(Scale));
                    Yphys[k] = TMath::Sqrt(TMath::Abs(Yphys[k]*Yphys[k] + Scale*Scale*PhysErrY*PhysErrY));
                }
                
                // Next, clean the current graphs and rebuild them:
                TheData = new TGraphErrors(Size,&Xval[0],&Yval[0],&Xerr[0],&Yerr[0]);
                PhysError = new TGraphErrors(Size,&Xval[0],&Yphval[0],&Xerr[0],&Yphys[0]);
                
                // Done.
                if (Xequal==kFALSE) {cout << "### FATAL: All X-values need to be the same!\n\n";}
            }
        }
    }
}

void DNNDataGraph::GetRelativeGraph(DNNDataGraph* OtherGraph, Double_t const NewPhysVal)
{
    // Adds andother graph to this one.
    if ((TheData==0)||(TheData==nullptr)||(PhysError==0)||(PhysError==nullptr))
    {
        cout << "### FATAL: You need to compute the graph of this class before adding something else to it!\n\n";
    }
    else
    {
        if ((OtherGraph->GetDataGraph()==0)||(OtherGraph->GetDataGraph()==nullptr)||(OtherGraph->GetPhysGraph()==0)||(OtherGraph->GetPhysGraph()==nullptr))
        {
            cout << "### FATAL: You need to compute the graph to be added before you can add it to this graph!\n\n";
        }
        else
        {
            if (TheData->GetN()!=OtherGraph->GetDataGraph()->GetN())
            {
                cout << "### FATAL: Graphs that have to be added must have the same number of points!\n\n";
            }
            else
            {
                // Generate arrays:
                Int_t Size = TheData->GetN();
                Double_t* Xval = new Double_t[Size];
                Double_t* Xerr = new Double_t[Size];
                Double_t* Yval = new Double_t[Size];
                Double_t* Yerr = new Double_t[Size];
                Double_t* Yphys = new Double_t[Size];
                Double_t* Yphval = new Double_t[Size];
            
                // Declare what we need:
                Double_t ThisX;
                Double_t ThisY;
                Double_t ErrorX;
                Double_t ErrorY;
                Double_t PhysValY;
                Double_t PhysErrY;
            
                // Fill the arrays with the current graph:
                for (Int_t k = 0; k<Size; ++k)
                {
                    PhysError->GetPoint(k,ThisX,PhysValY);
                    TheData->GetPoint(k,ThisX,ThisY);
                    ErrorX = TheData->GetErrorX(k);
                    ErrorY = TheData->GetErrorY(k);
                    PhysErrY = PhysError->GetErrorY(k);
                    
                    Xval[k] = ThisX;
                    Xerr[k] = ErrorX;
                    Yval[k] = ThisY;
                    Yerr[k] = ErrorY;
                    Yphys[k] = PhysErrY;
                    Yphval[k] = PhysValY;
                }
                
                // Next, retrieve the other values and process them.
                // This=Total; Other=Restricted. hence: do (This-Other)/Other
                Bool_t Xequal = kTRUE;
                
                for (Int_t k = 0; k<Size; ++k)
                {
                    OtherGraph->GetPhysGraph()->GetPoint(k,ThisX,PhysValY);
                    OtherGraph->GetDataGraph()->GetPoint(k,ThisX,ThisY);
                    ErrorX = OtherGraph->GetDataGraph()->GetErrorX(k);
                    ErrorY = OtherGraph->GetDataGraph()->GetErrorY(k);
                    PhysErrY = OtherGraph->GetPhysGraph()->GetErrorY(k);
                    
                    // Compare x-values:
                    if (TMath::Abs((Xval[k]-ThisX)/(Xval[k]+ThisX))>1e-6) {Xequal = kFALSE;}
                    if (TMath::Abs((Xerr[k]-ErrorX)/(Xerr[k]+ErrorX))>1e-6) {Xequal = kFALSE;}
                    
                    // Process Y-values:
                    Yval[k] = (Yval[k] - ThisY)/ThisY;
                    Yerr[k] = TMath::Sqrt(TMath::Abs((Yerr[k]*Yerr[k])/(ThisY*ThisY) + (Yval[k]*Yval[k]*ErrorY*ErrorY)/(ThisY*ThisY*ThisY*ThisY)));
                    Yphval[k] = NewPhysVal;
                    Yphys[k] = TMath::Sqrt(TMath::Abs((Yphys[k]*Yphys[k])/(ThisY*ThisY) + (Yval[k]*Yval[k]*PhysErrY*PhysErrY)/(ThisY*ThisY*ThisY*ThisY)));
                }
                
                // Next, clean the current graphs and rebuild them:
                TheData = new TGraphErrors(Size,&Xval[0],&Yval[0],&Xerr[0],&Yerr[0]);
                PhysError = new TGraphErrors(Size,&Xval[0],&Yphval[0],&Xerr[0],&Yphys[0]);
                
                // Done.
                if (Xequal==kFALSE) {cout << "### FATAL: All X-values need to be the same!\n\n";}
            }
        }
    }
}

// Generate ROOT dictionary:
ClassImp(DNNDataGraph);
