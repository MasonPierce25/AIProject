//
// Created by Sam Sidelinger on 2/21/21.
//

#include "clauseVar.h"

clauseVar:: clauseVar()
{

};

clauseVar:: clauseVar(string val, bool conc)
{
    this->value = val;
    this->is_a_conclusion = conc;
    this->answer= "NULL";
    this->instantiated = false;

};

void clauseVar::set_instantiated()
{
    this->instantiated = true;
};

void clauseVar::set_answer(string &ans)
{
    this->answer = ans;
};
bool clauseVar::conclusion_or_not()
{
    if (this->is_a_conclusion)
        return true;
};

bool clauseVar::is_instantiated()
{
    if (this->instantiated)
        return true;
};

string clauseVar::get_clause()
{
    return this->value;
};

string clauseVar::get_answer()
{
    return this->answer;
}

