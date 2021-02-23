//
// Created by Sam Sidelinger on 2/22/21.
//

#ifndef EXPERT_SYSTEM_CLAUSEVARLIST_H
#define EXPERT_SYSTEM_CLAUSEVARLIST_H
#include "clauseVar.h"
#include <string>
using namespace std;


class clauseVarList {

private:
    clauseVar cV_list[100];

public:

    clauseVarList();
    clauseVarList(string*);
    clauseVar get_clause_byIndex(int);
    string get_clause_value(string);
    clauseVar get_clause(string);



};


#endif //EXPERT_SYSTEM_CLAUSEVARLIST_H
