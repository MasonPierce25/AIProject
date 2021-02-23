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

void ruleBuilder::build_knowledge_base()
{
    clauseVar degree = clauseVar("degree", false);
    rule rule1 = rule( degree, "position");



};
