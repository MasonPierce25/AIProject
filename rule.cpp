//
// Created by Sam Sidelinger on 2/21/21.
//

#include "rule.h"

rule::rule()
{

};

rule::rule(clauseVar cv1,clauseVar cv2,clauseVar cv3,clauseVar cv4,string conc)
{
    this->clause1 = cv1;
    this->clause2 = cv2;
    this->clause3 = cv3;
    this->clause4 = cv4;
    this->conclusion = conc;
    this->concluded = false;
    this->next_rule = false;

};



rule::rule(clauseVar cv1,clauseVar cv2,clauseVar cv3,string conc) {
    this->clause1 = cv1;
    this->clause2 = cv2;
    this->clause3 = cv3;
    this->conclusion = conc;
    this->concluded = false;
    this->next_rule = false;
};

rule::rule(clauseVar cv1, clauseVar cv2,string conc)
{
    this->clause1 = cv1;
    this->clause2 = cv2;
    this->conclusion = conc;
    this->concluded = false;
    this->next_rule = false;
};

rule::rule(clauseVar cv1,string conc)
{
    this->clause1 = cv1;
    this->conclusion = conc;
    this->concluded = false;
    this->next_rule = false;
};

bool rule:: check_concluded()
{
   if(this->concluded)
       return true;
};

void rule::update_concluded() // i have to tweak this to make it work for more than two clauses
{
    if (this->clause1.is_instantiated() && this->clause2.is_instantiated())
        this->concluded = true;

}
bool rule:: update_next_rule()
{
//not sure i need this

};

clauseVar rule::get_clause(int clauseNum)
{

    switch(clauseNum)
    {
        case 1:
            return this->clause1;
        case 2:
            return this->clause2;
        case 3:
            return this->clause3;
        case 4:
            return this->clause4;
    }
}

string rule::get_conclusion()
{
    return this->conclusion;
}