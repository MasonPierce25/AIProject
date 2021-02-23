//
// Created by Sam Sidelinger on 2/21/21.
//

#include "ruleStack.h"

ruleStack::ruleStack()
{

};

void ruleStack::push(rule r)
{
    this->stack.push_back(r);
};

bool ruleStack::is_empty()
{
    return this->stack.empty();
};

rule ruleStack::peak()
{
    this->stack.back();
};

void ruleStack::pop()
{
    this->stack.pop_back();
}