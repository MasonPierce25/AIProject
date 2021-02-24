//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULELIST_H
#define EXPERT_SYSTEM_RULELIST_H
#include "rule.h"


class ruleList {
private:
    rule conclusion_list[30];

public:
    ruleList();
    ruleList(rule,rule,rule,rule,rule,rule);//must modify for thirty
    string get_conclusion(int);
    rule get_rule(int);



};


#endif //EXPERT_SYSTEM_RULELIST_H
