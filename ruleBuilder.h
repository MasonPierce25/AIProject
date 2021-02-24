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
    string conclusion_list[6];
    ruleList* rList[30];
public:
    ruleBuilder();
    void build_knowledge_base();
    void set_conclusion_list();
    string * get_conclusion_list();
    ruleList*  get_r_list();


};

//must modify to read in data
#endif //EXPERT_SYSTEM_RULEBUILDER_H
