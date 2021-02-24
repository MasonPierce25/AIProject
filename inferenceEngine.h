//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_INFERENCEENGINE_H
#define EXPERT_SYSTEM_INFERENCEENGINE_H
#include "clauseVar.h"
#include "rule.h"
#include "ruleList.h"
using namespace std;

class inferenceEngine {
private: string conclusion;
public:
    inferenceEngine();
    bool is_conclusion(string, string*);
    int check_clauses(rule,bool&);
    bool check_conclusion(rule);
    bool update();


};


#endif //EXPERT_SYSTEM_INFERENCEENGINE_H
