
#include <cstdlib>
#include <iostream>
#include <vector>

#include "ExpertSystem.h"
using namespace std;


int main(int argc, char** argv) {
    int input;
    ExpertSystem systemDiagnosis("diagnosis.txt");
    ExpertSystem systemTreatment("treatment.txt");
    
    cout<<"Beggining Diagnosis:\n"<<endl;
    //runs backwards chaining to prove cancer
    systemDiagnosis.backwardsChain(0x5);
    
    
   
    
    //We need to copy the information from the fact base created while running the diagnosis backwards chaining in systemDiagnosis
    //into the forwards chaining fact base of systemTreatment
    //there are 13 types of cancer from from 2 through 14, we shall move them over manually, they are named the same
    
    //set cancer to true, this has been proven and is used as a base fact to link the trees
    if((systemDiagnosis.getVariable(0x4)&0x3)==0)
        cout<<"No Symptoms of Cancer Were exhibited."<<endl;
    else
        cout<<"Symptoms of the following cancers were found:"<<endl;
                
    systemTreatment.setVariable(0x5);
    for(int i=2;i<15;i++){
        uint8_t transferVar=i<<2;
        //if the variable was not initialized, assume it was false
        if(!systemDiagnosis.isInitialized(transferVar))
            systemTreatment.setVariable(transferVar);
        //otherwise we will check to see if it was true and we shall copy it over
        //extract the last 2 bits and ensure they are not 0
        else if((systemDiagnosis.getVariable(transferVar)&0x3)!=0){
            //the variable is true, print it to the user and transfer it
            cout<<systemDiagnosis.getVariableName(transferVar)<<": "<<systemDiagnosis.getVariableStateName(systemDiagnosis.getVariable(i<<2))<<endl;
            systemTreatment.setVariable(systemDiagnosis.getVariable(transferVar));
        }
    }
    
    
    //runs forward chaining to find the treatment method
    cout<<"Beggining Treatment:\n"<<endl;
    systemTreatment.forwardChain(0x5);
    
    //option to print debug data
//    systemDiagnosis.printData();
//    systemTreatment.printData();
    
    cout<<"Your best options of treatment are:"<<endl;
  //print variable 15-20 from the treatment tree that have the treatment method
    for(int i=15;i<21;i++){
        if(systemTreatment.isInitialized(i<<2) && (systemTreatment.getVariable(i<<2)&0x3)!=0){
            cout<<systemTreatment.getVariableName(i<<2)<<": "<<systemTreatment.getVariableStateName(systemTreatment.getVariable(i<<2))<<endl;
        }
    }
    
    cout<<"Finished, enter any value to continue."<<endl;
    cin>>input;
    return 0;
}

