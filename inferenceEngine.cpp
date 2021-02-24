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
    int ruleNum = r.get_rule_num();
    switch(ruleNum)
    {
        case 1:
            if(r.get_clause(1).get_answer() == "NO")
            {
                r.set_conclusion_value("NO");
                r.is_concluded();
            }
            else if (r.get_clause(1).get_answer() ==  "YES")
            {
                r.set_conclusion_value("YES");
            }
            else
            {
                cout<< "Error";
            }
    };

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


int inferenceEngine::check_clauses(rule currentRule,bool &conclusionReached)
{


    if (currentRule.get_clause(1).conclusion_or_not())
        return 1;
    else if(currentRule.get_clause(2).conclusion_or_not())
        return 2;
    else if ((!currentRule.get_clause(1).conclusion_or_not()) && (!currentRule.get_clause(1).conclusion_or_not()))
    {
        currentRule.user_input(1);
        check_conclusion(currentRule);
        conclusionReached = currentRule.is_concluded();
    };
}