//
// Created by Sam Sidelinger on 2/21/21.
//

#include "clauseVar.h"

clauseVar:: clauseVar(string val, bool conc)
{
    this->value = val;
    this->is_a_conclusion = conc;
    this->answer= "NULL";
    this->instantiated = False;

}

void clauseVar::set_instantiated()
{
    this->instantiated = True;
}
void clauseVar::set_value()
{

};
void clauseVar::set_answer()
{

};
void clauseVar::conclusion_or_not()
{

};