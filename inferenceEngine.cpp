//
// Created by Sam Sidelinger on 2/21/21.
//

#include "inferenceEngine.h"
#include "rule.h"
#include "clauseVar.h"
#include "clauseVarList.h"
#include "ruleList.h"
#include "ruleStack.h"
#include "ruleBuilder.h"
#include <iostream>
using namespace std;

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
                r.check_concluded();
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
                r.check_concluded();
                concluded = true;
            }
            else if (r.get_clause(1).get_answer() == "YES")
            {
                r.set_conclusion_value("YES");
                r.check_concluded();
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
                r.check_concluded();
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
                r.check_concluded();
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
                r.check_concluded();
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
                r.check_concluded();
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
                conclusionReached = currentRule.check_concluded();
        }
        else if(currentRule.get_rule_num() == 4 ||currentRule.get_rule_num() == 5 || currentRule.get_rule_num() == 6 )
        {
            currentRule.user_input_num(2);
            if(!currentRule.get_clause(3).is_instantiated())
                currentRule.user_input_num(3);
            check_conclusion(currentRule);
            conclusionReached = currentRule.check_concluded();
        }
        return 3;
    }
    else if((!currentRule.get_clause(1).conclusion_or_not()) && (currentRule.get_clause(1).is_instantiated()) &&
            (!currentRule.get_clause(2).conclusion_or_not())&& (currentRule.get_clause(2).is_instantiated()))
    {
        currentRule.check_concluded();
        conclusionReached= currentRule.check_concluded();
        return 4;
    }
    else if((!currentRule.get_clause(1).conclusion_or_not()) && (currentRule.get_clause(1).is_instantiated()) &&
            (!currentRule.get_clause(2).conclusion_or_not())&& (currentRule.get_clause(2).is_instantiated())
            && (!currentRule.get_clause(3).conclusion_or_not()) && (currentRule.get_clause(3).is_instantiated()))
    {
        {
            currentRule.check_concluded();
            conclusionReached= currentRule.check_concluded();
            return 5;
        }
    }
    else
        {
            cout << "some kind of error";//debug spot
            return 6;
        }
};

void inferenceEngine::run_inference_engine(int scenario)
{
    string *conc_list;
    string input;
    rule currentRule;
    ruleList* rlist;
    bool initially_found;
    int scenario_num;
    bool is_concluded;
    int conc_list_placeholder = 0;
    string new_conclusion= "NA";
    string final_conclusion ="NA";

    ruleBuilder ruleBuilder1 = ruleBuilder();
    ruleBuilder1.build_knowledge_base();
    ruleBuilder1.set_conclusion_list();
    conc_list = ruleBuilder1.get_conclusion_list();
    rlist = ruleBuilder1.get_r_list();
    ruleStack ruleStack1 = ruleStack();
    cout<< "Enter a conclusion";
    cin>> input;

    for(int i = 0; i < 6; i++)
    {

        if(conc_list[i]== input)
        {
            if(conc_list[i] == rlist->get_rule(i).get_conclusion())
            {
                currentRule = rlist->get_rule(i);
                initially_found = true;
            }
            conc_list_placeholder = i;
        }
    }
    if(!initially_found)
        cout<< "no conclusion witht that name value";
    else
        ruleStack1.push(currentRule);
    while(!ruleStack1.is_empty())
    {
        scenario_num = check_clauses(ruleStack1.peak(), is_concluded);

        switch(scenario_num)
        {
            case 1:
            {
                for(int i = 0; i < 6; i++)
                {
                    if(ruleStack1.peak().get_clause(1).get_clause() == rlist->get_rule(i).get_conclusion())
                        ruleStack1.push(rlist->get_rule(i));
                };
                break;
            };

            case 2:
            {
                for(int i = 0; i < 6; i++)
                {
                    if(ruleStack1.peak().get_clause(2).get_clause() == rlist->get_rule(i).get_conclusion())
                        ruleStack1.push(rlist->get_rule(i));
                };
                break;
            };

            case 3:
            {
                is_concluded = check_conclusion(ruleStack1.peak());
                if(!is_concluded)
                {
                    int j = ++conc_list_placeholder;
                    for(int i = j; i < 6; i++)
                    {
                        if(ruleStack1.peak().get_conclusion() == conc_list[i])
                        {
                            if(conc_list[i] == rlist->get_rule(i).get_conclusion())
                            {
                                currentRule = rlist->get_rule(i);
                                ruleStack1.push(currentRule);
                            }
                        }

                    };
                }
                else if(is_concluded)
                {
                    new_conclusion = ruleStack1.peak().get_conclusion();
                }
            };
            break;

            case 4:
            {
                is_concluded = check_conclusion(ruleStack1.peak());
                if(!is_concluded)
                {
                    int j = ++conc_list_placeholder;
                    for(int i = j; i < 6; i++)
                    {
                        if(ruleStack1.peak().get_conclusion() == conc_list[i])
                        {
                            if(conc_list[i] == rlist->get_rule(i).get_conclusion())
                            {
                                currentRule = rlist->get_rule(i);
                                ruleStack1.push(currentRule);
                            }
                        }

                    };
                }
                else if(is_concluded)
                {
                    new_conclusion = ruleStack1.peak().get_conclusion();
                }
            };
                break;


        };
        if(is_concluded)
        {
            cout<< ruleStack1.peak().get_conclusion();
            ruleStack1.pop();
            if(ruleStack1.is_empty())
            {
                final_conclusion = new_conclusion;//not needed
                cout<< final_conclusion;
            }

        }


    }



};