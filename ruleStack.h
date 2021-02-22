//
// Created by Sam Sidelinger on 2/21/21.
//

#ifndef EXPERT_SYSTEM_RULESTACK_H
#define EXPERT_SYSTEM_RULESTACK_H
#include "rule.h"
#include <vector>
using namespace std;

class ruleStack {

private:
    vector<rule> stack;
    int top;

public:

    ruleStack();
    void push(rule);
    void pop();
    rule peak();
    bool is_empty();
    bool is_full();
};


#endif //EXPERT_SYSTEM_RULESTACK_H
