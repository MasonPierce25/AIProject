//
// Created by Sam Sidelinger on 2/21/21.
//

#include "ruleList.h"
#include <string>
ruleList::ruleList()
{

}

ruleList::ruleList(rule r1, rule r2, rule r3, rule r4,rule r5, rule r6) //must fix for 30
{
    this->conclusion_list[1] = r1;
    this->conclusion_list[2] = r2;
    this->conclusion_list[3] = r3;
    this->conclusion_list[4] = r4;
    this->conclusion_list[5] = r5;
    this->conclusion_list[6] = r6;
};

string ruleList ::get_conclusion(int rule_num)
{
    return this->conclusion_list[rule_num].get_conclusion();
};

rule ruleList::get_rule(int rule_num)
{
    return this->conclusion_list[rule_num];
}