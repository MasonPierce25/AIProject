//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULELIST_H
#define EXPERT_SYSTEM_RULELIST_H
#include "rule.h"


class ruleList {
private:
    rule[30] conclusion_list;

public:
    ruleList();
    ruleList(rule,rule,rule,rule);
    string get_conclusion(int);
    rule get_rule(int);


};


#endif //EXPERT_SYSTEM_RULELIST_H
