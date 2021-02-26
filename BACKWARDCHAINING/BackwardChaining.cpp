//
// Created by Sam Sidelinger on 2/26/21.
//

#include "BackwardChaining.h"
#include "BackwardChaining.h"


//-----------------------------------------------------------------------------
BackwardChaining::BackwardChaining(){

}



BackwardChaining::~BackwardChaining(){

}

std::string BackwardChaining::run(){
    /***** initialization section ******/
    /* stack space is 30 we initially place stack space at 30+1 */
    sp=31;
    for (i=1; i<31; i++)
    {
        conclt[i] = "PROBLEM";
    }
    conclt[6] = "SECURITY SOFTWARE";

    for (int a; a < 32; a++) {
        instlt[a] = 0;
    }
    for (int a; a < 31; a++) {
        statsk[a] = 0;
        clausk[a] = 0;
    }

    /* enter variables which are in the if part, 1 at a time in the
exact
    order that they occur, up to 3 variables per if statement.  do not
    duplicate any variable names.  any name is used only once.  if no
    more variables left just hit return key. */
    std::cout << "*** VARIABLE LIST *\n";
    /**** comment 367 *****/

    //MARK: variables
    varlt[1] = "WON'T START";
    varlt[2] = "POWER CORD";
    varlt[3] = "HARDWARE OLD";z
            varlt[4] = "COMPUTER CRASHING";
    varlt[5] = "SOFTWARE UPDATED";
    varlt[6] = "ANTIVIRUS";
    varlt[7] = "FIREWALL";
    varlt[8] = "RUNNING HOT";
    varlt[9] = "LOCKED OUT";
    varlt[10] = "LOST CONTROL";
    varlt[11] = "RANSOM MESSAGE";
    varlt[12] = "SERVER VOLUME";
    varlt[13] = "SLOW CPU";
    varlt[14] = "SLOW INTERNET";
    varlt[15] = "POPUP VOLUME";
    varlt[16] = "UNKNOWN ACTIVITIES";
    varlt[17] = "VALID USER";
    varlt[18] = "PUBLIC USAGE";
    varlt[19] = "SUSPICIOUS LINK";
    varlt[20] = "SUSPICIOUS EMAIL";
    varlt[21] = "CREDIBLE LINK";
    varlt[22] = "ONLINE PURCHASE";
    varlt[23] = "POPUP LINK";
    varlt[24] = "ROGUE EMAIL";
    varlt[25] = "UNAUTH TEXT";
    varlt[26] = "ENCRYPTION SOFTWARE";
    varlt[27] = "STOLEN DATA";
    varlt[28] = "INCONSISTENT DOC";
    varlt[29] = "EDITED DOCUMENTS";
    varlt[30] = "DATABASE CHANGES";
    varlt[31] = "STRONG PASSWORD";

    for (i = 1; i < 32; i++) printf("VARIABLE %d %s\n", i, varlt[i].c_str());

    /* enter variables as they appear in the if clauses.  a maximum
of 3
    variables per if statement.  if no more variables hit return
key. */
    std::cout << "*** CLAUSE VARIABLE LIST ***\n";
    /***** comment 407 through 409 ***/

    //MARK: Clauses
    // RULE 1
    clvarlt[1] = "WON'T START";
    clvarlt[2] = "POWER CORD";
    // RULE 2
    clvarlt[5] = "WON'T START";
    clvarlt[6] = "HARDWARE OLD";
    // RULE 3
    clvarlt[9] = "COMPUTER CRASHING";
    clvarlt[10] = "HARDWARE OLD";
    // RULE 4
    clvarlt[13] = "COMPUTER CRASHING";
    clvarlt[14] = "SOFTWARE UPDATED";
    // RULE 5
    clvarlt[17] = "COMPUTER CRASHING";
    clvarlt[18] = "ANTIVIRUS";
    // RULE 6
    clvarlt[21] = "ANTIVIRUS";
    clvarlt[22] = "FIREWALL";
    // RULE 7
    clvarlt[25] = "ANTIVIRUS";
    clvarlt[26] = "RUNNING HOT";
    // RULE 8
    clvarlt[29] = "ANTIVIRUS";
    clvarlt[30] = "LOCKED OUT";
    // RULE 9
    clvarlt[33] = "ANTIVIRUS";
    clvarlt[34] = "LOST CONTROL";
    // RULE 10
    clvarlt[37] = "RANSOM MESSAGE";
    // RULE 11
    clvarlt[41] = "SERVER VOLUME";
    // RULE 12
    clvarlt[45] = "ANTIVIRUS";
    clvarlt[46] = "SLOW CPU";
    // RULE 13
    clvarlt[49] = "ANTIVIRUS";
    clvarlt[50] = "FIREWALL";
    clvarlt[51] = "SLOW INTERNET";
    // RULE 14
    clvarlt[53] = "SLOW CPU";
    clvarlt[54] = "SLOW INTERNET";
    clvarlt[55] = "SERVER VOLUME";
    // RULE 15
    clvarlt[57] = "SLOW CPU";
    clvarlt[58] = "SLOW INTERNET";
    clvarlt[59] = "POPUP VOLUME";
    // RULE 16
    clvarlt[61] = "SLOW CPU";
    clvarlt[62] = "SLOW INTERNET";
    clvarlt[63] = "UNKNOWN ACTIVITIES";
    // RULE 17
    clvarlt[65] = "SECURITY SOFTWARE";
    clvarlt[66] = "VALID USER";
    // RULE 18
    clvarlt[69] = "SECURITY SOFTWARE";
    clvarlt[70] = "PUBLIC USAGE";
    // RULE 19
    clvarlt[73] = "SECURITY SOFTWARE";
    clvarlt[74] = "SUSPICIOUS LINK";
    // RULE 20
    clvarlt[77] = "SECURITY SOFTWARE";
    clvarlt[79] = "SUSPICIOUS EMAIL";
    // RULE 21
    clvarlt[81] = "SECURITY SOFTWARE";
    clvarlt[82] = "CREDIBLE LINK";
    // RULE 22
    clvarlt[85] = "SECURITY SOFTWARE";
    clvarlt[86] = "ONLINE PURCHASE";
    // RULE 23
    clvarlt[89] = "SECURITY SOFTWARE";
    clvarlt[90] = "POPUP LINK";
    // RULE 24
    clvarlt[93] = "SECURITY SOFTWARE";
    clvarlt[94] = "ROGUE EMAIL";
    // RULE 25
    clvarlt[97] = "SECURITY SOFTWARE";
    clvarlt[98] = "UNAUTH TEXT";
    // RULE 26
    clvarlt[101] = "ENCRYPTION SOFTWARE";
    clvarlt[102] = "STOLEN DATA";
    // RULE 27
    clvarlt[105] = "VALID USER";
    clvarlt[106] = "ENCRYPTION SOFTWARE";
    clvarlt[107] = "DATABASE CHANGES";
    // RULE 28
    clvarlt[109] = "ENCRYPTION SOFTWARE";
    clvarlt[110] = "INCONSISTENT DOC";
    // RULE 29
    clvarlt[113] = "STOLEN DATA";
    clvarlt[114] = "STRONG PASSWORD";
    // RULE 30
    clvarlt[117] = "DATABASE CHANGES";
    clvarlt[118] = "STRONG PASSWORD";


    for(i=1; i<31; i++)
    {
        std::cout << "** CLAUSE " << i << std::endl;
        for(j=1; j<5; j++)
        { k = 4 * (i-1) + j;
            std::cout << "VARIABLE " << j << " " << clvarlt[k] << std::endl;
        }
    }
    varble = "PROBLEM";
    // end of func
    //MARK: inference section
    /* get conclusion statement number (sn) from the conclusion list
       (conclt) */
    /* first statement starts search */
    f=1;
    determine_member_concl_list();
    do {
        if (sn != 0 || b545) {
            /* if sn = 0 then no conclusion of that name */ do
                /* push statement number (sn) and clause number=1 on
    goal
                   stack which is composed of the statement stack
    (statsk)
                   and clause stack (clausk) */
            {
                if(!b545) {
                    push_on_stack();
                }
                b545 = false;
                do {
                    /* calculate clause location in clause-variable
                       list */
                    b545:
                    i = (statsk[sp] - 1) * 4 + clausk[sp];
                    /* clause variable */
                    varble = clvarlt[i];
                    if (!varble.empty()) {
                        /*is this clause variable a conclusion? */
                        f = 1;
                        determine_member_concl_list();
                        if (sn != 0) {
                            /* it is a conclusion push it */
                            //goto b520;
                            f = 1;
                            determine_member_concl_list();
                            if (sn == 0) {
                                std::cout << "PROGRAM END";
                                return 0;
                            } else {
                                push_on_stack();
                            }
                        } else {
                            /* check instantiation of this clause */
                            instantiate();
                            clausk[sp] = clausk[sp] + 1;
                        }
                    }
                } while (!varble.empty());
                //MARK: do-while
                /*no more clauses check if part of statement */
                sn = statsk[sp];
                s = 0;
                /**** if then statements ****/
                /* sample if parts of if then statements from
                   the position knowledge base */
                switch (sn) {
                    //MARK: if part of statement 1 */
                    /****** comment 1500 ****/
                    case 1:
                        if(wontStart == "YES" && powerCord == "NO"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 2 */
                        /***** comment 1510 ******/
                    case 2:
                        if(wontStart == "YES" && hardwareAge == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 3 */
                    case 3:
                        if(computerCrashing == "YES" && hardwareAge == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 4 */
                        /******** comment 1560 ******/
                    case 4:
                        if(computerCrashing == "YES" && softwareUpToDate == "NO"){
                            s = 1;
                        }
                        break;
                        /******** comment 1570 ********/
                        /* if part of statement 5 */
                    case 5:
                        if(computerCrashing == "YES" && antiVirus == "NO"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 6 */
                    case 6:
                        if(antiVirus == "NO" || firewall == "NO"){
                            s = 1;
                        }
                        break;
                    case 7:
                        if(antiVirus == "NO" && runningHot == "YES"){
                            s = 1;
                        }
                        break;
                    case 8:
                        if(antiVirus == "NO" && lockedOut == "YES"){
                            s = 1;
                        }
                        break;
                    case 9:
                        if(antiVirus == "NO" && lostControl == "YES"){
                            s = 1;
                        }
                        break;
                    case 10:
                        if(ransomMessage == "YES"){
                            s = 1;
                        }
                        break;
                    case 11:
                        if(serverVolume >= 4){
                            s = 1;
                        }
                        break;
                    case 12:
                        if(antiVirus == "NO" && computerSpeed == "YES"){
                            s = 1;
                        }
                        break;
                    case 13:
                        if(securitySoftware ==  "NO" && internetSpeed == "YES"){
                            s = 1;
                        }
                        break;
                    case 14:
                        if(computerSpeed == "YES" && internetSpeed == "YES" && serverVolume >=3){
                            s = 1;
                        }
                        break;
                    case 15:
                        if((computerSpeed == "YES" || internetSpeed == "YES") && popupVolume == "YES"){
                            s = 1;
                        }
                        break;
                    case 16:
                        if((computerSpeed == "YES" || internetSpeed == "YES") && unknownActivitiesRunning == "YES"){
                            s = 1;
                        }
                        break;
                    case 17:
                        if(securitySoftware == "NO" && validUserActivities == "NO"){
                            s = 1;
                        }
                        break;
                    case 18:
                        if(securitySoftware == "NO" && publicUsage == "YES"){
                            s = 1;
                        }
                        break;
                    case 19:
                        if(securitySoftware == "NO" && suspiciousLink == "YES"){
                            s = 1;
                        }
                        break;
                    case 20:
                        if(securitySoftware == "NO" && suspiciousEmail == "YES"){
                            s = 1;
                        }
                        break;
                    case 21:
                        if(securitySoftware == "NO" && credibleLink == "YES"){
                            s = 1;
                        }
                        break;
                    case 22:
                        if(securitySoftware == "NO" && onlinePurchase == "YES"){
                            s = 1;
                        }
                        break;
                    case 23:
                        if(securitySoftware == "NO" && popupLink == "YES"){
                            s = 1;
                        }
                        break;
                    case 24:
                        if(securitySoftware == "NO" && rogueEmail == "YES"){
                            s = 1;
                        }
                        break;
                    case 25:
                        if(securitySoftware == "NO" && unauthorizedText == "YES"){
                            s = 1;
                        }
                        break;
                    case 26:
                        if(encryptionSoftware == "NO" && stolenData == "YES"){
                            s = 1;
                        }
                        break;
                    case 27:
                        if((validUserActivities == "NO" || encryptionSoftware == "NO") && databaseChanged == "YES"){
                            s = 1;
                        }
                        break;
                    case  28:
                        if(encryptionSoftware == "NO" && inconsistentDocument == "YES"){
                            s = 1;
                        }
                        break;
                    case 29:
                        if(stolenData == "YES" && password == "NO"){
                            s = 1;
                        }
                        break;
                    case 30:
                        if(editedDocuments == "YES" && password == "NO"){
                            s = 1;
                        }
                        break;




                        //MARK: end of first switch
                }
                /* see if the then part should be invoked */
                if (s != 1) {
                    /* failed..search rest of statements for
                       same conclusion */
                    /* get conclusion */
                    i = statsk[sp];
                    varble = conclt[i];
                    /* search for conclusion starting at the
                       next statement number */
                    f = statsk[sp] + 1;
                    determine_member_concl_list();
                    sp = sp + 1;
                }
                /* pop old conclusion and put on new one */
            } while ((s != 1) && (sn != 0));  /* outer do-while loop */
            if (sn != 0) {
                /* if part true invoke then part */
                /* then part of if-then statements from the
                   position knowledge base */
                switch (sn) {
                    /* then part of statement 1 */
                    /******* comment 1500 *******/
                    case 1:
                        problem = "CNP";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 2 */
                        /****** comment 1510 ******/
                    case 2 ... 4:
                        problem = "HSI";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 3 */
                    case 5:
                        problem = "MAL";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 6 */
                    case 6:
                        securitySoftware = "NO";
                        std::cout << "SECURITY SOFTWARE: " << securitySoftware;
                        break;
                    case 7 ... 10:
                        problem = "MAL";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 11:
                        problem = "DOS";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 12:
                        problem = "MAL";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 13 ... 14:
                        problem = "DOS";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 15 ... 16:
                        problem = "MAL";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 17 ... 18:
                        problem = "ITG";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 19 ... 25:
                        problem = "MAL";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 26:
                        problem = "CON";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 27:
                        problem = "ITG";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 28 ... 30:
                        problem = "CON";
                        std::cout << "PROBLEM: " << problem;
                        break;
//MARK: end of second switch statements
                }
                /* pop the stack */
                sp = sp + 1;
                if (sp >= 31) {
                    /* finished */
                    std::cout << "*** SUCCESS\n";
                }
                else {
                    /* stack is not empty */
                    /* get next clause then continue */
                    clausk[sp] = clausk[sp] + 1;
                    //goto b545;
                    b545 = true;
                }
            }
        }
    } while (b545);
    //MARK: end of loop
    return problem;
}

void BackwardChaining::determine_member_concl_list() {
/* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
    /* initially set to not a member */
    sn = 0;
    /* member of conclusion list to be searched is f */
    i = f;
    while((varble != conclt[i]) && (i<31))
        /* test for membership */
        i=i+1;
    if (varble == conclt[i]) sn = i;  /* a member */
}

void BackwardChaining::push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
    sp=sp-1;
    statsk[sp] = sn;
    clausk[sp] = 1;
}

void BackwardChaining::instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
    i=1;
    /* find variable in the list */
    while((varble != varlt[i]) && (i<32)) i=i+1;
    if((varble == varlt[i]) && (instlt[i] != 1))
        /*found variable and not already instantiated */
    {
        instlt[i]=1; /*mark instantiated */
        /* the designer of the
       knowledge base places the input statements to
       instantiate the variables below in the case statement */
        switch (i)
        {
            /***** input statement *****/
            /* input statements for sample position knowledge
               base */
            /***** comment 1700 ******/
            case 1: std::cout << "Is your machine failing to power on? INPUT YES OR NO... \n";
                wontStart = yesOrNoValidation();
                break;
            case 2: std::cout << "IS THE POWER CABLE PLUGGED IN? INPUT YES OR NO... \n";
                powerCord = yesOrNoValidation();
                break;
            case 3: std::cout << "Is your hardware old? INPUT YES OR NO... \n";
                hardwareAge = yesOrNoValidation();
                break;
            case 4: std::cout << "Does your computer keep crashing? INPUT YES OR NO... \n";
                computerCrashing = yesOrNoValidation();
                break;
            case 5: std::cout << "Is your software up-to-date? INPUT YES OR NO... \n";
                softwareUpToDate = yesOrNoValidation();
                break;
            case 6: std::cout << "Do you have any antivirus software installed? INPUT YES OR NO... \n";
                antiVirus = yesOrNoValidation();
                break;
            case 7: std::cout << "Do you have an active firewall? INPUT YES OR NO... \n";
                firewall = yesOrNoValidation();
                break;
            case 8: std::cout << "Is your computer running hot when it should be asleep? INPUT YES OR NO... \n";
                runningHot = yesOrNoValidation();
                break;
            case 9: std::cout << "Are you locked out of your computer? INPUT YES OR NO... \n";
                lockedOut = yesOrNoValidation();
                break;
            case 10: std::cout << "Have you lost control of your computer? INPUT YES OR NO... \n";
                lostControl = yesOrNoValidation();
                break;
            case 11: std::cout << "Have you received a message asking for money to unlock your computer? INPUT YES OR NO... \n";
                ransomMessage = yesOrNoValidation();
                break;
            case 12: std::cout << "How is your server traffic. 0-5 (0low, 2.5 medium, 5 high) \n ";
                serverVolume = std::stof(realNumberValidation());
                break;
            case 13: std::cout << "Is your computer running unusually slow? input YES or NO) \n";
                computerSpeed = yesOrNoValidation();
                break;
            case 14: std::cout << "Is your internet connection slow? enter YES or NO... \n";
                internetSpeed = yesOrNoValidation();
                break;
            case 15: std::cout << "Do you have a high volume of pop-ups? INPUT YES OR NO... \n";
                popupVolume = yesOrNoValidation();
                break;
            case   16: std::cout << "Do you have any unknown activities running in the background? INPUT YES OR NO... \n";
                unknownActivitiesRunning = yesOrNoValidation();
                break;
            case 17: std::cout << "Can you account for all the users who have access to your computer? INPUT YES OR NO... \n";
                validUserActivities = yesOrNoValidation();
                break;
            case 18: std::cout << "Is your computer open for public use? INPUT YES OR NO... \n";
                publicUsage = yesOrNoValidation();
                break;
            case 19: std::cout << "Have you clicked on any suspicious links attached to an email? INPUT YES OR NO... \n";
                suspiciousEmail = yesOrNoValidation();
                break;
            case 20: std::cout << "Have you clicked on any suspicious links sent from known contacts? INPUT YES OR NO... \n";
                suspiciousLink = yesOrNoValidation();
                break;
            case 21: std::cout << "Have you clicked on any links or downloads from a user posted on a credible site? INPUT YES OR NO... \n";
                credibleLink = yesOrNoValidation();
                break;
            case 22: std::cout << "Have you made any purchases online from an insecure website? INPUT YES OR NO... \n";
                onlinePurchase = yesOrNoValidation();
                break;
            case 23: std::cout << "Have you clicked on any pop-up links? INPUT YES OR NO... \n";
                popupLink = yesOrNoValidation();
                break;
            case 24: std::cout << "Is your email sending mail without your knowledge? INPUT YES OR NO... \n";
                rogueEmail = yesOrNoValidation();
                break;
            case 25: std::cout << "Is your device sending unauthorized text messages? INPUT YES OR NO... \n";
                unauthorizedText = yesOrNoValidation();
                break;
            case 26: std::cout << "Do you use encryption software like a virtual private network (vpn)? INPUT YES OR NO... \n";
                encryptionSoftware = yesOrNoValidation();
                break;
            case 27: std::cout << "Has your data been stolen? INPUT YES OR NO... \n";
                stolenData = yesOrNoValidation();
                break;
            case 28: std::cout << "Have you noticed that documents  you send do not look the same to the person you sent it to? INPUT YES OR NO... \n";
                inconsistentDocument = yesOrNoValidation();
                break;
            case 29: std::cout << "Have you noticed any changes to your documents? INPUT YES OR NO... \n";
                editedDocuments = yesOrNoValidation();
                break;
            case 30: std::cout << "Have you noticed any unauthorized changes to your data base? INPUT YES OR NO... \n";
                databaseChanged = yesOrNoValidation();
                break;
            case 31: std::cout << "Is your password strong? *More than 13 characters including numbers and capitals.  also not an easily guessed word. INPUT YES OR NO... \n";
                password = yesOrNoValidation();
                break;
                /***** comment 1715 ****/
        }
        /* end of inputs statements for sample position knowledge
           base */
    }
}

std::string BackwardChaining::yesOrNoValidation() {
    std::string input;
    while(input != "YES" && input != "NO") {
        std::cin >> input;
        if (input != "YES" && input != "NO") std::cout << R"(INVALID INPUT - ENTER "YES" OR "NO": )";
        else return input;
    }
}

std::string BackwardChaining::realNumberValidation() {
    std::string input;
    while(!isRealNumber(input)) {
        std::cin >> input;
        if (!isRealNumber(input)) std::cout << "INVALID INPUT - ENTER A POSITIVE REAL NUMBER: ";
        else return input;
    }
}

bool BackwardChaining::isRealNumber(std::string input) {
    int decimal = 0;
    bool valid = true;
    int i = 0;
    if (input.empty()) valid = false;
    while(valid && i < input.length()) {
        if (input[i] == '.') decimal++;
        else if (!isdigit(input[i]) || decimal > 1) valid = false;
    }
    return valid;
}


// end of file
