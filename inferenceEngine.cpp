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
    bool concluded = false;
    int ruleNum = r.get_rule_num();
    switch(ruleNum)
    {
        case 1:
        {
            if (r.get_clause(1).get_answer() == "NO")
            {
                r.set_conclusion_value("NO");
                r.is_concluded();
                concluded = true;
            }
            else if (r.get_clause(1).get_answer() == "YES")
            {
                r.set_conclusion_value("YES");
            }
            else
                cout << "Error";
            break;
        };
        case 2:
        {
            if(r.get_clause(1).get_answer() == "NO")
            {
                r.set_conclusion_value("NO");
                r.is_concluded();
                concluded = true;
            }
            else if (r.get_clause(1).get_answer() == "YES")
            {
                r.set_conclusion_value("YES");
                r.is_concluded();
                concluded = true;
            }
            else
                cout<<"error";
            break;
        };
        case 3:
        {
            if(r.get_clause(1).get_answer() == "YES" && r.get_clause(2).get_answer()=="YES")
            {
                r.set_conclusion_value("RESEARCH");
                r.is_concluded();
                concluded = true;
            }
            else if ( r.get_clause(2).get_answer() == "NO")
                r.set_conclusion_value("NA");
            else
                cout<< "error";
            break;
        };
        case 4:
        {
            if ((r.get_clause(1).get_answer() == "YES") && (r.get_clause(2).get_num_answer() < 3.5) && (r.get_clause(3).get_num_answer() >=2 ))
            {
                r.set_conclusion_value("SERVICE ENGINEER");
                r.is_concluded();
                concluded = true;
            }
            break;
        };

        case 5:
        {
            if ((r.get_clause(1).get_answer() == "YES") && (r.get_clause(2).get_num_answer() < 3.5) &&
                (r.get_clause(3).get_num_answer() < 2))
            {
                r.set_conclusion_value("NO");
                r.is_concluded();
                concluded = true;
            }
            else
            {
                cout << "error";
            }
            break;
        };

        case 6:
        {
            if((r.get_clause(1).get_answer() == "YES") && (r.get_clause(2).get_num_answer() >= 3.5))
            {
                r.set_conclusion_value("PRODUCT ENGINEER");
                r.is_concluded();
                concluded = true;
            }
            else
            {
                cout << "error";
            }
            break;
        };
    };

    return concluded;

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
    else if ((!currentRule.get_clause(1).conclusion_or_not()) && (!currentRule.get_clause(1).is_instantiated()))//switch this up for cancer stuff
    {
        currentRule.user_input(1);
        if(!currentRule.get_clause(2).is_instantiated())
        {
            if(currentRule.get_rule_num() == 1 ||currentRule.get_rule_num() == 2 || currentRule.get_rule_num() == 3 )
                currentRule.user_input(2);
                check_conclusion(currentRule);
                conclusionReached = currentRule.is_concluded();
        }
        else if(currentRule.get_rule_num() == 4 ||currentRule.get_rule_num() == 5 || currentRule.get_rule_num() == 6 )
        {
            currentRule.user_input_num(2);
            if(!currentRule.get_clause(3).is_instantiated())
                currentRule.user_input_num(3);
            check_conclusion(currentRule);
            conclusionReached = currentRule.is_concluded();
        }
        return 3;
    }
    else if((!currentRule.get_clause(1).conclusion_or_not()) && (currentRule.get_clause(1).is_instantiated()) &&
            (!currentRule.get_clause(2).conclusion_or_not())&& (currentRule.get_clause(2).is_instantiated()))
    {
        currentRule.check_concluded();
        conclusionReached= currentRule.is_concluded();
        return 4;
    }
    else if((!currentRule.get_clause(1).conclusion_or_not()) && (currentRule.get_clause(1).is_instantiated()) &&
            (!currentRule.get_clause(2).conclusion_or_not())&& (currentRule.get_clause(2).is_instantiated())
            && (!currentRule.get_clause(3).conclusion_or_not()) && (currentRule.get_clause(3).is_instantiated()))
    {
        {
            currentRule.check_concluded();
            conclusionReached= currentRule.is_concluded();
            return 5;
        }
    }
    else
        cout<< "some kind of error";//debug spot 

};