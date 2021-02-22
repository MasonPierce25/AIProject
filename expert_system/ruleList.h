//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULELIST_H
#define EXPERT_SYSTEM_RULELIST_H
#include "rule.h"
#include <vector>

class ruleList {
private:
    vector<rule> conclusion_list;

public:
    void set_conclusion_list();
    rule get_conclusion();

};


#endif //EXPERT_SYSTEM_RULELIST_H
