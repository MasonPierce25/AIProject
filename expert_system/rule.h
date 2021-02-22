//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULE_H
#define EXPERT_SYSTEM_RULE_H
#include <string>
#include "clauseVar.h"
using namespace std;

class rule {

private:
    string conclusion;
    clauseVar clauses[5];
    bool next_rule;
    bool concluded;
public:
    rule(clauseVar,clauseVar,clauseVar,clauseVar);
    void add_clause();
    void add_conclusion();
    bool check_conclusion();
    bool update_next_rule();

};


#endif //EXPERT_SYSTEM_RULE_H
