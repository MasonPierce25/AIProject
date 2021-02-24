//
// Created by Sam Sidelinger on 2/21/21.
//

#include "inferenceEngine.h"


inferenceEngine::inferenceEngine()
{

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

int inferenceEngine::check_clauses(rule conclusion)
{

}