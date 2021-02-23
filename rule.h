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
    clauseVar clause1;
    clauseVar clause2;
    clauseVar clause3;
    clauseVar clause4;
    bool next_rule;
    bool concluded;
public:
    rule();
    rule(clauseVar,clauseVar,clauseVar,clauseVar,string);
    rule(clauseVar,clauseVar,clauseVar,string);
    rule(clauseVar, clauseVar,string);
    rule(clauseVar&,string);
    string get_conclusion();
    void update_concluded();
    bool update_next_rule();
    bool check_concluded();
    clauseVar get_clause(int);

};


#endif //EXPERT_SYSTEM_RULE_H
