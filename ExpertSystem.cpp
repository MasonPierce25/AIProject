/* 
 * File:   RuleBase.cpp
 * Author: Avery Wylin
 * 
 * Created on February 6, 2021, 9:30 PM
 */

#include <cstdio>
#include <string>
#include "ExpertSystem.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>

/*
 * Rule Base Class
 * Contains the Rule Base and all appropriate methods
 */

ExpertSystem::ExpertSystem()
{
    //initialize
    ruleBase = new Rule[256]();
    factBase = new uint8_t[16];
    intializedFlag=0x00000000;
    variableNames = new std::string[64];
    variableStateNames = new std::string[256];
    
    //overwrites garbage data
    clearFactBase();
    clearRuleBase();
    
    
    loadFile();
    
}

ExpertSystem::ExpertSystem(const ExpertSystem& orig) {
}

ExpertSystem::~ExpertSystem() {
    delete[] ruleBase;
    delete[] factBase;
    delete[] variableNames;
    delete[] variableStateNames;
}

void ExpertSystem::loadFile(){
    //wipe ALL file data before a load
    clearAllData();
    
    std::ifstream dataFile("data.txt");
    
    //statistic variables
    int varCount=1;
    int ruleCount=0;
    //a map to speed up the process and make human readable
    std::map<std::string,int> varMap = std::map<std::string,int>();
    varMap.insert(std::pair<std::string,int>("-",0));//inserts a blank character for NULL_VAR in the rules
    variableNames[0]="NULL_VAR";
    
    //temp variables
    std::string names[5];
    for(int i=0;i<5;i++){
        names[i]="";
    }
    char type;
    
    while(!dataFile.eof()){
        type = ' ';
        dataFile>>type;
        switch(type){
            case 'v'://creates a new variable
                if(varCount<64){
                    
                    for(int i=0;i<5;i++){
                        dataFile>>names[i];
                    }
                    
                    
                    varMap.insert(std::pair<std::string,int>(names[0],varCount));
                    variableNames[varCount]=names[0];
                    for(int i=0;i<4;i++){
                        variableStateNames[4*varCount+i]=names[i+1];
                    }
                    varCount++;
                }
            break;
            
            case 'r'://creates a new rule
                if(ruleCount<256){
                    int states[5];
                    
                    for(int i=0;i<5;i++){
                        dataFile>>names[i];
                        if(names[i]=="-"){
                            states[i]=0;
                        }
                        else{//get the value of the current variable, compare each state name to the written on
                            uint8_t currentVar= varMap[names[i]];
                            std::string stateName = "";
                            bool found = false;
                            dataFile>>stateName;
                            
                            int j=0;
                            for(;j<4;j++){
                                if(stateName == variableStateNames[currentVar*4+j]){
                                    found = true;
                                    break;
                                }
                            }
                            if(!found){
                                std::cout<<"Error declaring rule "<<ruleCount<<" for variable state "<<stateName<<std::endl;
                            }
                            else
                                states[i]= j;
                                
                        }
                    }
                    
                    uint64_t antecedents=0;
                    for(int i=0;i<4;i++){
                        antecedents |= varMap[names[i]]<<2;
                        antecedents|=states[i];
                        if(i<3)//last one should not be shifted
                            antecedents<<=8;
                    }
                    uint8_t consequent = states[4];
                    consequent |= (varMap[names[4]])<<2;
                    
                    ruleBase[ruleCount] = Rule(antecedents,consequent);
//                    std::cout<<":"<<std::hex<<(int)ruleBase[ruleCount].antecedents<<" : "<<(int)ruleBase[ruleCount].consequent<<std::endl;
                    ruleCount++;
                }
            break;
            default: break;
        }
        
        //error handling
        if(dataFile.fail()){
            std::cout<<"Encountered Bad Data Input: "<< varCount<<","<<ruleCount<<std::endl;
            dataFile.clear();
            dataFile.ignore(500,'\n');
        }
    }
    
    //remove all undescores frome names
//    int i=0;
//    for(;variableNames[i]!="-";i++){
//        std::replace(variableNames[i].begin(),variableNames[i].end(),'_',' ');
//        for(int j=0;j<4;j++){
//            std::replace(variableStateNames[i*4+j].begin(),variableStateNames[i*4+j].end(),'_',' ');
//        }
//    }
    
    dataFile.close();
}

ExpertSystem::Rule::Rule(uint64_t antecedents, uint8_t consequent){
    this->antecedents = antecedents;
    this->consequent = consequent;
}

ExpertSystem::Rule::Rule(){
    antecedents = NULL_VAR;
    consequent= NULL_VAR;
}

ExpertSystem::Rule::~Rule(){
}

void ExpertSystem::clearFactBase(){
    for(int i=0;i<16;i++){
        factBase[i]=0;
    }
    intializedFlag=0;
}

void ExpertSystem::clearRuleBase(){
    for(int i=0;i<256;i++){
        ruleBase[i] = EMPTY_RULE;
    }
}

void ExpertSystem::clearAllData(){
    for(int i=0;i<64;i++){
        variableNames[i]="";
    }
    for(int i=0;i<256;i++){
        variableStateNames[i]="-";
    }
    clearFactBase();
    clearRuleBase();
}

bool ExpertSystem::Rule::containsAntecedent(uint8_t value){
    return (((antecedents>>24 & 0xff)==value) || ((antecedents>>16 & 0xff)==value)||((antecedents>>8 & 0xff)==value)||((antecedents & 0xff)==value));
    
}

bool ExpertSystem::Rule::containsConsequent(uint8_t value){
    return value == consequent;
}

void ExpertSystem::Rule::setConsequent(uint8_t value){
    consequent == value;
}

void ExpertSystem::Rule::setAntecedent(int index, uint8_t value){
    //clear a position in the antecedents
    antecedents &= ((0xfffffff0)<<(index*8));
    //fill in the position
    antecedents |= (value<<(index*8));
}

void ExpertSystem::Rule::setAntecedents(uint32_t value){
    antecedents = value;
}


bool ExpertSystem::verifyRule(Rule &rule){
    bool r = false;
    uint8_t antecedent = NULL_VAR;
    for(int i=0;i<4;i++){
        antecedent = (rule.antecedents>>(8*i))&0xff;
        if(antecedent!=NULL_VAR && isInitialized(antecedent) && getVariable(antecedent)!=antecedent){
            //if the antecedent exist exist AND is initialized AND the rule does not match the fact base
            return false;
        }
    }
    //all antecedents that exist were found to match the fact base
    return true;
    
}

void ExpertSystem::enactRule(Rule &rule){
    uint8_t antecedent = NULL_VAR;
    for(int i=0;i<4;i++){
        antecedent = (rule.antecedents>>(8*i))&0xff;
        if(antecedent == NULL_VAR)
            continue;
        if(!isInitialized(antecedent) || getVariable(antecedent)!=antecedent){
            //rule can not be enacted due to being unitialized or a false antecedent
            return;
        }
    }
    //all rules passed
    setVariable(rule.consequent);
}

 bool ExpertSystem::Rule::operator==(const ExpertSystem::Rule &rule){
    return (antecedents == rule.antecedents) && (consequent == rule.consequent);
}

//this accepts a variable/value pair, this is useful for consequents
void ExpertSystem::setVariable(uint8_t value){
    int index = value>>4;
    int byteLocation = 2*(0x3&(value>>2));
    //clear position
    factBase[index]&=~(0x03<<byteLocation);
    //fill position
    factBase[index]|=((value&0x3)<<byteLocation);
    setInitialized(value,true);
}

//this accepts a value/variable pair, the variable is dropped
void ExpertSystem::setInitialized(uint8_t variable, bool init){
    uint64_t flipValue = 1;
    flipValue<<=(variable>>2);
    if(init){//set flag to true by OR with select 1
        intializedFlag|=flipValue;
    }
    else{//set flag to false by AND with select 0
        intializedFlag&=(~flipValue);
    }
    
}

bool ExpertSystem::isInitialized(uint8_t variable){
    return (intializedFlag>>(variable>>2))&1==1;
}

//gieve a var/value pair, replaces the value with user input @ var address
uint8_t ExpertSystem::requestVariableFromUser(uint8_t value){
    //removes the value from a Variable/Value pair that makes up Antecdents and Consequents (only need first 6 bits)
    //we must do this so the values in the VariableNames are correct
    value>>=2;
    std::cout<< variableNames[value] <<"?\n";
    for(int i=0;i<4;i++){
        if(variableStateNames[value*4+i]!="-")
            std::cout<<i<<". "<<variableStateNames[value*4+i]<<"   ";
    }
    std::cout<<std::endl;
    unsigned int userInput; //variable of user input 0-3
    std::cin>>userInput;
    while(userInput<0 || userInput>3 || std::cin.fail() || variableStateNames[value*4+userInput]=="-"){
        std::cout<<"Unknown Input. Please answer the question: \""<< variableNames[value] << "\" again using a corresponding number."<<std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin>>userInput;
    }
    std::cout<< variableStateNames[value*4+userInput] <<"\n"<<std::endl;
    //return the value back to the Variable/Value pair
    value<<=2;
    value|=userInput;
    setVariable(value);
    setInitialized(value,true);
    return value;
}


void ExpertSystem::printData(){
    std::cout<<"Complete Fact Base:"<<std::endl;
    for(int i=0;i<16;i++){
        std::cout<<std::dec<<4*i<<":"<<std::hex<<std::setw(8)<<(int)factBase[i]<<std::dec<<std::endl;
    }
    std::cout<<"Variables:"<<std::endl;
    for(int i=0;i<64;i++){
        if(variableNames[i] != ""){
            std::cout<<variableNames[i]<<":"<< (isInitialized(i<<2)?variableStateNames[getVariable(i<<2)]:"-") <<std::endl;
        }
    }
    std::cout<<"Initialized: "<<std::hex<<(int)intializedFlag<<std::endl;
}

//returns a variable/value pair
uint8_t ExpertSystem::getVariable(uint8_t variable){
    uint8_t index = variable>>2;
    return (variable&0xFC)|((factBase[index/4]>>(index%4*2))&0x3);
}

void ExpertSystem::forwardChain(uint8_t startFact){
    std::queue<uint8_t> consequentQueue = std::queue<uint8_t>();
    //request the variable from the user and push it onto the queue
    startFact = requestVariableFromUser(startFact);
    consequentQueue.push(startFact);

    uint8_t currentFact;

    while (!consequentQueue.empty()) {
        //access the queue
        currentFact = consequentQueue.front();
        consequentQueue.pop();

        //search the ruleBase for antecedents that may be updated
        for (int i = 0; i < 256; i++) {
            if (ruleBase[i] == EMPTY_RULE)
                break;

                if (ruleBase[i].containsAntecedent(currentFact) && verifyRule(ruleBase[i])) {
                    //if the rule contains the updated antecedent AND that rule has been verified as possibly true
                    //request unintialized vars to prove if the rule is valid
                    uint8_t currentAntecedent;
                    for (int j = 0; j < 4; j++) {//loop through the antecedents
                        currentAntecedent = 0xff & ((ruleBase[i].antecedents >> (8 * j)));
                        if(currentAntecedent == NULL_VAR)
                            continue;
                        if (isInitialized(currentAntecedent)) {
                            if (currentAntecedent != getVariable(currentAntecedent)) {
                                //invalidates this rule
                                break;
                            }
                        }
                        else {
                            //if the antecedent exist AND it has not yet been initialized, we should ask the user for it
                            currentAntecedent = requestVariableFromUser(currentAntecedent);
                            //we should also put this on the consequentQueue as it may be an antecedent in another tree
                            consequentQueue.push(currentAntecedent);
                            //if the antecedent doesn't match then we should end the process, the user needn't enter more vars
                            if (currentAntecedent != getVariable(currentAntecedent)) {
                                //invalidates this rule
                                break;
                            }
                        }
                        
                    }
                    //reverify if the rule is true
                    if (verifyRule(ruleBase[i])) {
                        //if the rule is true, we can add the consequent to the queue and initialize it
                        //we CAN NOT reinitialize a variable if it is already initialized
                        if(!isInitialized(ruleBase[i].consequent)){
                            setVariable(ruleBase[i].consequent);
                            consequentQueue.push(ruleBase[i].consequent);
                        }
                    }
                }
        }
    }
    //ended because no more valid rules were leading to consequents

}

void ExpertSystem::backwardsChain(uint8_t goalFact) {

    //find rules that match the goal consequent, call recursion if they are found
    //recursion will use the system stack instead of a premade stack on the heap
    //this method is far easier to implement and stores values we normally cant such as picking up in a loop we were in
    //this function ONLY PROVES A FACT, it will NOT search for a general consequent as that is not its goal
    for (uint8_t i = 0; !(ruleBase[i] == EMPTY_RULE); i++) {
        if (ruleBase[i].containsConsequent(goalFact))
            recursiveBackwards(i);
    }
    
}

//simple recursuve helper function for backwards chaining
void ExpertSystem::recursiveBackwards(uint8_t currentRule){
    for(int i=0;i<4;i++){
        uint8_t currentAntecedent = 0xff & (ruleBase[currentRule].antecedents >> (8 * i));
        if(currentAntecedent==NULL_VAR)//In the case that there is no Variable in the current slot
            continue;
        bool found = false;
        for(int j=0;!(ruleBase[j] == EMPTY_RULE);j++){//Iterate through all Rules
            if(ruleBase[j].containsConsequent(currentAntecedent)){//if the Rule contains the current antecdent in its consequent
                recursiveBackwards(j); //we perform this function again and go up a level, thus putting it on the stack
                found = true; //we pass that this variable was found so we do not hit the base case
            }
        }
        if(!found && !isInitialized(currentAntecedent)){ //BASE CASE
            requestVariableFromUser(currentAntecedent); //the Antecedent can not be determined through inference, ask the user
        }
    }
    enactRule(ruleBase[currentRule]); //When all the recursion is done the current rule will have all antecedents initialized, it can thus inference its consequent
}

