# python import commands:
import numpy as np
import os as TheOS
import sys as TheSys

# import Keras and TensorFlow:
import tensorflow as tf
import keras as ks

# import own functions:
from NetworkDefinition import model
from ReadTheArray import ReadArray
import SetParameters

# contains-function definition for substrings:
def contains(s, other):
    return s.__contains__(other)

# Use scoipt inputs:
if __name__ == "__main__":
    # Process input:
    TheEpochStr = "_Final"
    
    if (len(TheSys.argv) > 1):
        TheEpoch = int(TheSys.argv[1])
        TheEpochStr = "_Epoch" + str(TheEpoch)

    # Set parameters:
    SetParameters.Initialize(False)
    
    # Edit the output path:
    ThisOutputPath = SetParameters.OutputPath
    if "/DNN_Training/" in ThisOutputPath:
        ThisOutputPath = ThisOutputPath.replace("/DNN_Training/","")
    if "/DNN_Validation/" in ThisOutputPath:
        ThisOutputPath = ThisOutputPath.replace("/DNN_Validation/","")
    if "/DNN_Experiment/" in ThisOutputPath:
        ThisOutputPath = ThisOutputPath.replace("/DNN_Experiment/","")
    
    # Define training folder:
    TrainingFolder = ThisOutputPath + "/DNN_Training/"
    
    # Check if it exists:
    if (TheOS.path.exists(TrainingFolder)):
        ThisOutputPath = TrainingFolder
    
    # Then, Define the network name:
    TheNetworkName = ThisOutputPath + 'TheMultNetwork' + TheEpochStr + '.h5'

    # Check that this is a Multiplicity Network:
    if ((SetParameters.NetworkType=='IO_Signals_ElenaHoemann') or
        (SetParameters.NetworkType=='IO_Signals_Elena_9002_5') or
        (SetParameters.NetworkType=='IO_Signals_Elena_9004_5') or
        (SetParameters.NetworkType=='IO_Signals_Elena_6004_5') or
        (SetParameters.NetworkType=='IO_Signals_Elena_12004_5') or
        (SetParameters.NetworkType=='IO_Signals_MultNetwork') or
        (SetParameters.NetworkType=='IO_3to6_TradMed_BabyNetwork') or
        (SetParameters.NetworkType=='IO_2to6_TradMed_BabyNetwork')):

        # Load (& auto-compile) the model:
        TheModel=ks.models.load_model(TheNetworkName)

        # Declare variables:
        InitialEventCounter = 0
        FinalEventCounter = 0
        InputFileName = ''
        InputData = np.zeros((SetParameters.BatchSize,SetParameters.nInputNeurons))
        PredictedData = np.zeros((SetParameters.BatchSize,SetParameters.nOutputNeurons))
        nEventsPerBatch = 0
        Maximum_Predicted = 0.0
        MaxIndex_Predicted = -1
        EventMultiplicity = 0
        MaxProb = 0.0
        LowerMaxprob = 0.0
        UpperMaxProb = 0.0
        
        # create the output file:
        f= open(SetParameters.OutputPath+"/PredictedMultiplicities.txt","w+")

        # Loop over all batches:
        for kBatch in range(0,SetParameters.nBatches):
        
            # Define filenames of inputs and outputs:
            InitialEventCounter = kBatch*SetParameters.BatchSize
            FinalEventCounter = InitialEventCounter + SetParameters.BatchSize - 1
            InputFileName = SetParameters.TextFilePath + 'DNN_InputFile_' + str(InitialEventCounter) + 'till' + str(FinalEventCounter) + '.txt'
        
            # Read input and output data:
            InputData = ReadArray(InputFileName)
        
            # Check the dimensions of the matrices:
            if ((InputData.shape[0]<=SetParameters.BatchSize) and 
                (InputData.shape[1]==SetParameters.nInputNeurons)):
        
                # Then, we can safely use the model for a prediction:
                PredictedData = TheModel.predict(InputData)
        
                # Next, process the statistics:
        
                # Update current number of events:
                nEventsPerBatch = InputData.shape[0]
        
                # Find max. output and use that to count. Loop over events in the batch:
                for n in range(0,nEventsPerBatch):
    
                    # Find out maximum & position in prediction. Reset parameters:
                    MaxIndex_Predicted = -1
                    Maximum_Predicted = -100.0
    
                    for k in range(0,SetParameters.nOutputNeurons):
                        if (Maximum_Predicted<PredictedData[n,k]):
                            Maximum_Predicted = PredictedData[n,k]
                            MaxIndex_Predicted = k
            
                    # Right now, the predicted multiplicity is MaxIndex_Predicted+1:
                    EventMultiplicity = MaxIndex_Predicted+1
                    
                    # if the situation asks for it, check if the prediction has sufficient accuracy:
                    if (SetParameters.TradEff_for_Acc==True):
                        
                        # Check if the multiplicity is indeed the one that needs boosted accuracy:
                        if (EventMultiplicity==SetParameters.Acc_Selected_Multiplicity):
                            
                            # Extract the maximum probability:
                            MaxProb = PredictedData[n,MaxIndex_Predicted]
                        
                            # Extract the probability below:
                            if (MaxIndex_Predicted==0):
                                LowerMaxprob = 0.0
                            else:
                                LowerMaxprob = PredictedData[n,MaxIndex_Predicted-1]
                            
                            # Extract the probability above:
                            if (MaxIndex_Predicted==(SetParameters.nOutputNeurons-1)):
                                UpperMaxProb = 0.0
                            else:
                                UpperMaxProb = PredictedData[n,MaxIndex_Predicted+1]
                           
                            # Compare. There are 3 different scenarios here:
                            if (MaxIndex_Predicted==0):
                                
                                # Bottom case: Multiplicity 1:
                                if (MaxProb>(UpperMaxProb + SetParameters.Acc_ProbThreshold)):
                                    EventMultiplicity = 1
                                else:
                                    EventMultiplicity = 2
                                    
                            elif (MaxIndex_Predicted==(SetParameters.nOutputNeurons-1)):
                                
                                # Ceiling case: Max. Multiplicity:
                                if (MaxProb>(LowerMaxprob + SetParameters.Acc_ProbThreshold)):
                                    EventMultiplicity = SetParameters.nOutputNeurons
                                else:
                                    EventMultiplicity = SetParameters.nOutputNeurons - 1
                                 
                            else:
                                
                                # In-between case:
                                if ((MaxProb>(LowerMaxprob + SetParameters.Acc_ProbThreshold)) and (MaxProb>(UpperMaxProb + SetParameters.Acc_ProbThreshold))):
                                    EventMultiplicity = MaxIndex_Predicted+1
                      
                                else:
                                    
                                    # Then, check wich probability is larger:
                                    if (LowerMaxprob>UpperMaxProb):
                                        EventMultiplicity = MaxIndex_Predicted+0
                                       
                                    else:
                                        EventMultiplicity = MaxIndex_Predicted+2
                                
                                # Done. Close all indents:
                    
                    # Write that number to a file:
                    f.write("%d\r\n" % (EventMultiplicity))
                
                    # Done. ------------------
            
                # give update statement:
                print('Executed Netwok prediction from batch '+str(kBatch+1)+'/'+str(SetParameters.nBatches)+'.')
        
            else:
          
                # Give error message:
                print('==> ERROR in batch '+str(kBatch+1)+'/'+str(SetParameters.nBatches)+': MATRIX DIMENSIONS WERE INCORRECT!')
        
        # Done -----------------------------
    
        # Next, Close the file and be done with it.
        f.close()
    
    else:
        print('THIS OUTPUT SCRIPT IS ONLY SUITABLE FOR MULTIPLICITY NETWORKS!')
