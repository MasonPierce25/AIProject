//
// Created by Sam Sidelinger on 2/21/21.
//

#include "clauseVar.h"

clauseVar:: clauseVar(string val, bool conc)
{
    this->value = val;
    this->is_a_conclusion = conc;
    this->answer= "NULL";
    this->instantiated = false;

}

void clauseVar::set_instantiated()
{
    this->instantiated = true;
}

void clauseVar::set_answer(string &ans)
{
    this->answer = ans;
};
bool clauseVar::conclusion_or_not()
{
    if (this->is_a_conclusion == true)
        return true;
    else
        return false;
};