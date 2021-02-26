//
// Created by Sam Sidelinger on 2/26/21.
//
#ifndef BACKWARDCHAINING_H
#define BACKWARDCHAINING_H
//------------------------------------------------------------------------
//
//  Name:   BackwardChaining.h
//
//  Desc:   A class defining a Backward chaining program.
//
//  Authors AI Group
//
//------------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include "string.h"
#include <cassert>

class BackwardChaining
{
private:
    /*  conclusion list */
    std::string conclt[31];
    /*  variable list */
    std::string varlt[32];
    /*  clause vairable list */
    std::string clvarlt[121];
    std::string varble;
    std::string wontStart, powerCord, hardwareAge, computerCrashing, softwareUpToDate, lockedOut, lostControl, runningHot, validUserActivities;
    std::string antiVirus, firewall, unknownActivitiesRunning, suspiciousLink,  ransomMessage, suspiciousEmail,  onlinePurchase, popupLink, databaseChanged, inconsistentDocument,  rogueEmail, unauthorizedText, stolenData, credibleLink, encryptionSoftware, securitySoftware, editedDocuments;
    std::string internetSpeed, popupVolume, password, publicUsage,  computerSpeed;
    std::string problem;

    float serverVolume;

    char buff[128];

    /* instantiated list */
    int instlt[32];
    /* statement stack */
    int statsk[31];
    int /* clause stack */ clausk[31], sn, f, i, j, s, k, /*stack pointer */ sp;
    bool b545 = false;


    void determine_member_concl_list(void);
    void push_on_stack(void);
    void instantiate(void);

public:
    BackwardChaining();
    ~BackwardChaining ();
    static std::string yesOrNoValidation();
    static std::string realNumberValidation();
    static bool isRealNumber(std::string);

    std::string run();
};





#endif


