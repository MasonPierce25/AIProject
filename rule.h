//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULE_H
#define EXPERT_SYSTEM_RULE_H
#include <string>
#include "clauseVar.h"
#include<iostream>
using namespace std;

class rule {

private:
    string conclusion;
    string conclusion_value;
    int rule_num;
    clauseVar clause1;
    clauseVar clause2;
    clauseVar clause3;
    clauseVar clause4;
    bool next_rule;
    bool concluded;
    string prompt = "Enter value for:";

public:
    rule();
    rule(clauseVar,clauseVar,clauseVar,clauseVar,string,string,int);
    rule(clauseVar,clauseVar,clauseVar,string,string,int);
    rule(clauseVar, clauseVar,string,string,int);
    rule(clauseVar,string,string,int);
    string get_conclusion();
    bool check_concluded();
    void update_concluded();
    bool update_next_rule();
    clauseVar get_clause(int);
    string get_conclusion_value();
    void set_conclusion_value(string);
    void user_input(int);
    int get_rule_num();
    void user_input_num(int);

};


#endif //EXPERT_SYSTEM_RULE_H
