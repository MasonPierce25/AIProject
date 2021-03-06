
#include <cstdlib>
#include <iostream>

#include "ExpertSystem.h"
using namespace std;

void diagnose(ExpertSystem system){
    /* In order to diagnose, the system must perform multiple backwards chains upon a list of variables.
     * This is because a single backwards chain only proves the value of a single variable
     * while "cancer" is listed as a variety of possible variables. We can naturally perform
     * a single backwards chain to prove a single value of "cancer" and solve through all other backwards chains
     * only if they are an intermediate step of a variable "cancer". This is entirely due to the nature of backwards chaining
     * as a way to prove a variable rather than dynamically solve results such as that in forward chaining. The chain will ONLY seek to
     * initialize the bare minimum of variables needed to prove the given fact.
    */
//    system.backwardsChain(/* Cancer Fact True*/ );
    //analyze data and report all variables that have been initialized AND of a deemed "Abnormal Value" (state>0)
}    

void treat(ExpertSystem system){
    
}

int main(int argc, char** argv) {
    int input;
    ExpertSystem system;
 //   system.forwardChain(0x0004);
    //test proving variable 2 = 3
    system.backwardsChain(0x000b);
    system.printData();
    cout<<"Finished, press any key to continue."<<endl;
    cin>>input;
    return 0;
}

