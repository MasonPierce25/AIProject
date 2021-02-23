//
// Created by Sam Sidelinger on 2/21/21.
//

#include "ruleBuilder.h"
#include "rule.h"
#include "clauseVar.h"
#include "ruleList.h"
#include<string>
using namespace std;

ruleBuilder:: ruleBuilder()
{

};

void ruleBuilder::set_conclusion_list()
{
    this->conclusion_list[1] = "position";
    this->conclusion_list[2] = "qualify";
    this->conclusion_list[3] = "position";
    this->conclusion_list[4] = "position";
    this->conclusion_list[5] = "position";
    this->conclusion_list[6] = "position";
};

void ruleBuilder::build_knowledge_base()
{
    string na = "NULL";
    clauseVar degree = clauseVar("degree", false);
    rule rule1 = rule( degree, "position",na);
    rule rule2 = rule( degree, "qualify",na);
    clauseVar discovery = clauseVar("discovery",false );
    rule rule3 = rule(degree,discovery,"position",na);
    clauseVar qualify = clauseVar("qualify", true);
    clauseVar grade = clauseVar("grade", false);
    clauseVar experience = clauseVar("experience", false);
    rule rule4 = rule(qualify, grade, experience,"position", na);
    rule rule5 = rule(qualify,grade,experience,"position",na);
    rule rule6 = rule(qualify, grade,"position",na );
    ruleList r_List = ruleList(rule1,rule2,rule3,rule4,rule5,rule6);
    this->rList = r_List;
};

string* ruleBuilder::get_conclusion_list()
{
    return this->conclusion_list;
};