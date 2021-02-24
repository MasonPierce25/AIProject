#include <iostream>
#include "clauseVarList.h"
#include "clauseVarList.h"
#include "inferenceEngine.h"
#include"rule.h"
#include"ruleBuilder.h"
#include"ruleList.h"
#include"ruleStack.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    inferenceEngine * inferenceEngine1 = new inferenceEngine();
    inferenceEngine1->run_inference_engine(1);

    return 0;
}


