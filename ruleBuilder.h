//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULEBUILDER_H
#define EXPERT_SYSTEM_RULEBUILDER_H
#include "clauseVar.h"
#include "rule.h"
#include "ruleList.h"
using namespace std;

class ruleBuilder {
public:
    ruleBuilder();
    void build_knowledge_base();
    string * get_conclusion_list();

};

//must modify to read in data
#endif //EXPERT_SYSTEM_RULEBUILDER_H
