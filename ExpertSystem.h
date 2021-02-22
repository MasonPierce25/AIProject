/* 
 * File:   RuleBase.h
 * Author: Avery Wylin
 *
 * Created on February 6, 2021, 9:30 PM
 */

#ifndef EXPERTSYSTEM_H
#define EXPERTSYSTEM_H
#include <stdint.h>
#include <string>


class ExpertSystem {
public:
    ExpertSystem();
    ExpertSystem(const ExpertSystem& orig);
    virtual ~ExpertSystem();
    
private:
    //Internal Rule Structure 
    struct Rule{
        //4 antecedents stored as 32 bits, each antecedents being 8 bits
        //The First 6 bits are the Variable ID 0-63
        //The last 2 bits are the Variabele State 0-3
        uint32_t antecedents;
        //The consequent byte, same format as an antecedent byte
        uint8_t consequent;
        
        Rule(uint64_t antecedents, uint8_t consequent);
        virtual ~Rule();
        Rule();
        
        /*
         * Rule Access Methods
         */
        bool containsAntecedent(uint8_t value);
        bool containsConsequent(uint8_t value);
        void setConsequent(uint8_t value);
        void setAntecedent(int index, uint8_t value);
        void setAntecedents(uint32_t value);
        bool operator==(const Rule &rule);
    };

    /*
     * Constant Variables
     */
    
    const Rule EMPTY_RULE = Rule();
    //used as a way to know if no variable is being accessed 
    const static uint8_t NULL_VAR = 0x0000;
    
    /*
     * Knowledge Base Variables
     */
    
    //An array of Rules to comprise the Rule Base, 64 long
    Rule *ruleBase;
    //An array of 16 bytes to comprise the FactBase
    //Each byte holds the value of 4 variables
    // 16 * 4 = 64, A maximum of 64 variables can be made
    //The Rule Structure only reserves 6 bytes for a variable ID
    uint8_t *factBase;
    //A flag for the Fact Base to determine whether or not it has been initialized, bit location corresponds to variable
    uint64_t intializedFlag;
    
    
    /*
     * Name Variables
     */
    
    //Array of 64 variable names, index of the fact base ID stores variable name
    std::string *variableNames;
    //Array of 256 variable state names, each variable has 4 possible states
    std::string *variableStateNames;
    //Array of 256 Rule Names, usually phrased as questions with up to 4 answers
    std::string *ruleNames;
    
    /*
     * Private Methods
     */
    //returns if initialized
    bool isInitialized(uint8_t variable);
    //sets a variable to initialized
    void setInitialized(uint8_t variable,bool init);
    
    
public:
    //removes all facts from the fact base
    void clearFactBase();
    //removes all rules from the rule base
    void clearRuleBase();
    //sets a fact given a var/val
    void setVariable(uint8_t value);
    //returns a var/val pair given a var/null pair
    uint8_t getVariable(uint8_t variable);
    //returns the index of the rule that contains the antecedent, NEEDS MODIFIED
    uint8_t getRuleIndexFromAntecedent(uint8_t antecedent);
    //performs forward chaining interacting with the user
    void forwardChain(uint8_t startFact);
    //performs backwards chaining interacting with the user
    void backwardsChain(uint8_t goalFact);
    //prompts the user to input a variable, recieves a var/null, returns a var/val and updates the fact base
    uint8_t requestVariableFromUser(uint8_t variable);
    //print debug information
    void printData();
    //verifies if a rule is true
    bool verifyRule(Rule &rule);
    //load data from file
    void loadFile();
    //a helper function for backwards chaining
    void recursiveBackwards(uint8_t ruleIndex);
    //uses a rule to make an inference
    void enactRule(Rule &rule);

};

#endif /* EXPERTSYSTEM_H */

