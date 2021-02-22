
#include <cstdlib>
#include <iostream>

#include "ExpertSystem.h"
using namespace std;

        
int main(int argc, char** argv) {
    int input;
    ExpertSystem system;
    system.forwardChain(0x0004);
//    system.backwardsChain(0x000b);
    system.printData();
    cout<<"Finished, press any key to continue."<<endl;
    cin>>input;
    return 0;
}

