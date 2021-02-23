//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_CLAUSEVAR_H
#define EXPERT_SYSTEM_CLAUSEVAR_H
#include <string>
using namespace std;

class clauseVar {


private :

    string value;
    bool is_a_conclusion;
    string answer;
    bool instantiated;



public:
    clauseVar();
    clauseVar(string,bool);
    void set_instantiated();
    void set_answer(string&);
    bool is_instantiated();
    bool conclusion_or_not();
    string get_clause();
    string get_answer();
};


#endif //EXPERT_SYSTEM_CLAUSEVAR_H
