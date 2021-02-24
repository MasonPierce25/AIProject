//
// Created by Sam Sidelinger on 2/22/21.
//

#include "clauseVarList.h"

clauseVarList::clauseVarList()
{

};


clauseVarList::clauseVarList(clauseVar* clausesArray)
{
    for(int i = 0; i < 100; i++)
    {
        this->cV_list[i] = clausesArray[i];
    }
};

clauseVar clauseVarList::get_clause_byIndex(int index)
{
    return this->cV_list[index];
};

string clauseVarList::get_clause_value(string clause_value)
{
    string matching_clause_value = "NULL";

    for(int i = 0; i < 100; i++)
    {
        if(this->cV_list[i].get_clause() == clause_value)
            matching_clause_value = cV_list[i].get_answer();

    }
};

clauseVar clauseVarList::get_clause(string clause_value)
{


    for (int i = 0; i < 100; i++)
    {
        if (this->cV_list[i].get_clause() == clause_value)
        {
            return this->cV_list[i];
        }
    };
};