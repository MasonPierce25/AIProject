//
// Created by Sam Sidelinger on 2/21/21.
//

#include "ruleStack.h"

ruleStack::ruleStack()
{

};

void ruleStack::push(rule r)
{
    if(top >=maxSize)
        cout<<"stack overflow";
    else
    {
        top++;
        this->stack[top] = r;
    }

};

bool ruleStack::is_empty()
{
    if(top == -1)
        return true;
};

rule ruleStack::peak()
{
    if(top>=0)
        return this-> stack[top];
};

void ruleStack::pop()
{
    if(top<=-1)
        cout<<"stack underflow";
    else
        {
            top--;
        }
}