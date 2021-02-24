//
// Created by Sam Sidelinger on 2/21/21.
//

#include "inferenceEngine.h"
#include "rule.h"
#include "clauseVar.h"
#include "clauseVarList.h"
#include "ruleList.h"
#include "ruleStack.h"

inferenceEngine::inferenceEngine()
{

};

bool inferenceEngine :: check_conclusion(rule r)
{

};
bool inferenceEngine::is_conclusion(string input,string* concl_list)
{
    bool valid = false;
    for(int i=0; i < 6; i++)
    {
        if(concl_list[i] == input)
            valid = true;
    };
    return valid;
};


int inferenceEngine::check_clauses(rule conclusion)
{
    if (conclusion.get_clause(1).conclusion_or_not())
        return 1;
    else if(conclusion.get_clause(2).conclusion_or_not())
        return 2;
    else if ((!conclusion.get_clause(1).conclusion_or_not()) && (!conclusion.get_clause(1).conclusion_or_not()))
    {
        conclusion.get_clause(1).
    };
}