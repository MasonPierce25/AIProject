cmake_minimum_required(VERSION 3.12)
project(expert_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(expert_system main.cpp clauseVar.cpp clauseVar.h rule.cpp rule.h ruleList.cpp ruleList.h ruleStack.cpp ruleStack.h ruleBuilder.cpp ruleBuilder.h inferenceEngine.cpp inferenceEngine.h)