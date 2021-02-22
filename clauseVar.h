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
    clauseVar(string,bool);
    void set_instantiated();
    void set_answer(string&);
    bool conclusion_or_not();
};


#endif //EXPERT_SYSTEM_CLAUSEVAR_H
