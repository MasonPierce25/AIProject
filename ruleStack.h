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
    rule stack[6];
    int maxSize = 6;
    int top = -1;

public:

    ruleStack();
    void push(rule);
    void pop();
    rule peak();
    bool is_empty();
};


#endif //EXPERT_SYSTEM_RULESTACK_H
