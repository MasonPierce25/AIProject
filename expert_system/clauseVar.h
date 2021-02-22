//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_CLAUSEVAR_H
#define EXPERT_SYSTEM_CLAUSEVAR_H
#include <string>
using namespace std;

class clauseVar {


private :

    string instantiated;
    string value;
    bool is_a_conclusion;
    string answer;

public:
    clauseVar(string,bool,string)
    void set_instantiated();
    void set_value();
    void conclusion_or_not();
};


#endif //EXPERT_SYSTEM_CLAUSEVAR_H
