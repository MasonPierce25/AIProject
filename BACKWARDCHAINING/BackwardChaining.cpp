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
    varlt[1] = "Urinary Freq";
    varlt[2] = "Urinary Bloody";
    varlt[3] = "Discomfort in Back";
    varlt[4] = "Lump on Back or Abdomen";
    varlt[5] = "Waxy Blemish";
    varlt[6] = "Red Crusty Blemish";
    varlt[7] = "Mishapen Blemish";
    varlt[8] = "Breast Abnormal";
    varlt[9] = "Gender";
    varlt[10] = "Family History";
    varlt[11] = "Bowel Movements";
    varlt[12] = "Colon Polyps";
    varlt[13] = "Appetite or Nausea";
    varlt[14] = "Discomfort in Stomach";
    varlt[15] = "Jaundice";
    varlt[16] = "Weight Loss";
    varlt[17] = "Trouble Swallowing";
    varlt[18] = "Lump on Neck";
    varlt[19] = "Persistent Cough";
    varlt[20] = "Cough Blood";
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
    clvarlt[1] = "Urinary Freq";
    clvarlt[2] = "Urinary Bloody";
    // RULE 2
    clvarlt[5] = "Urinary Bloody";
    clvarlt[6] = "Discomfort in Back";
    // RULE 3
    clvarlt[9] = "Urinary Bloody";
    clvarlt[10] = "Lump on Back or Abdomen";
    // RULE 4
    clvarlt[13] = "Lump on Back or Abdomen";
    clvarlt[14] = "Discomfort in Back";
    // RULE 5
    clvarlt[17] = "Waxy Blemish";
    clvarlt[18] = "Red Crusty Blemish";
    // RULE 6
    clvarlt[21] = "Mishapen Blemish";
    clvarlt[22] = "Breast Abnormal";
    // RULE 7
    clvarlt[25] = "Gender";
    clvarlt[26] = "Breast Abnormal";
    // RULE 8
    clvarlt[29] = "Gender";
    clvarlt[30] = "Family History";
    // RULE 9
    clvarlt[33] = "Bowel Movements";
    clvarlt[34] = "Bowel Movements";
    // RULE 10
    clvarlt[37] = "Colon Polyps";
    // RULE 11
    clvarlt[41] = "Appetite or Nausea";
    // RULE 12
    clvarlt[45] = "Discomfort in Stomach";
    clvarlt[46] = "Jaundice";
    // RULE 13
    clvarlt[49] = "Appetite or Nausea";
    clvarlt[50] = "Weight Loss";
    clvarlt[51] = "Trouble Swallowing";
    // RULE 14
    clvarlt[53] = "Lump on Neck";
    clvarlt[54] = "Persistent Cough";
    clvarlt[55] = "Cough Blood";
    // RULE 15
    clvarlt[57] = "Gender";
    clvarlt[58] = "Discomfort in Pelvic Area";
    clvarlt[59] = "Urinary Freq";
    // RULE 16
    clvarlt[61] = "General";
    clvarlt[62] = "Fever";
    clvarlt[63] = "Lump on Node";
    // RULE 17
    clvarlt[65] = "Lump on Node";
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
                        if(Urination_freq == "YES" && Urination_bloody == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 2 */
                        /***** comment 1510 ******/
                    case 2:
                        if(Urintation_bloody == "YES" && Discomfort_in_back == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 3 */
                    case 3:
                        if(Urintation_bloody == "YES" && Sex == "Male" && Lump_on_back_or_abdomen == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 4 */
                        /******** comment 1560 ******/
                    case 4:
                        if(Lump_on_back_or_abdomen == "YES" && Discomfort_in_back == "YES"){
                            s = 1;
                        }
                        break;
                        /******** comment 1570 ********/
                        /* if part of statement 5 */
                    case 5:
                        if(Waxy_blemish == "YES"){
                            s = 1;
                        }
                        break;
                        /* if part of statement 6 */
                    case 6:
                        if(Red_crusty_blemish == "YES"){
                            s = 1;
                        }
                        break;
                    case 7:
                        if(Mishapen_blemish == "YES"){
                            s = 1;
                        }
                        break;
                    case 8:
                        if(Breast_abnormal == "YES" && Gender == "NO"){
                            s = 1;
                        }
                        break;
                    case 9:
                        if(Breast_abnormal == "YES" && Gender == "NO" && Family_history == "YES"){
                            s = 1;
                        }
                        break;
                    case 10:
                        if(Bowel_movements == "YES"){
                            s = 1;
                        }
                        break;
                    case 11:
                        if(Bowel_movements == "YES" && Colon_polyps == "YES"){
                            s = 1;
                        }
                        break;
                    case 12:
                        if(Appetite_or_nausea == "YES" && Discomfort_in_stomach == "YES" && Jaundice == "YES"){
                            s = 1;
                        }
                        break;
                    case 13:
                        if(Appetite_or_nausea == "YES" && Weight_Loss == "YES" && Trouble_Swallowing == "YES"){
                            s = 1;
                        }
                        break;
                    case 14:
                        if(Lump_on_neck == "YES" && Persistent_cough == "YES"){
                            s = 1;
                        }
                        break;
                    case 15:
                        if((Cough_blood == "YES"){
                            s = 1;
                        }
                        break;
                    case 16:
                        if((Gender == "YES" && Discomfort_in_pelvic_area == "YES"){
                            s = 1;
                        }
                        break;
                    case 17:
                        if(Gender == "NO" && Discomfort_in_pelvic_area == "YES"){
                            s = 1;
                        }
                        break;
                    case 18:
                        if(Fever == "YES" && Appetite_or_nausea == "YES"){
                            s = 1;
                        }
                        break;
                    case 19:
                        if(Appetite_less_nauseated == "YES" && Trouble_swallowing == "YES" && Weight_Loss == "YES"){
                            s = 1;
                        }
                        break;
                    case 20:
                        if(Male == "YES" && Discomfort_in_the_bottom_or_pelvic_area == "YES" && Frequent_urge == "YES"){
                            s = 1;
                        }
                        break;
                    case 21:
                        if(Lump_in_neck == "YES" && Throat/Lungs == A_persistent_cough){
                            s = 1;
                        }
                        break;
                    case 22:
                        if(Appetite == Less_and/or_nauseated){
                            s = 1;
                        }
                        break;
                    case 23:
                        if(Chills/Fever == "YES"){
                            s = 1;
                        }
                        break;
                    case 24:
                        if(Fatigue == "YES"){
                            s = 1;
                        }
                        break;
                    case 25:
                        if(Weight_Loss == "YES"){
                            s = 1;
                        }
                        break;
                    case 26:
                        if(Lump == Neck){
                            s = 1;
                        }
                        break;
                    case 27:
                        if((Discomfort == In_the_bottom_or_pelvic_area && Urination == Frequent_urge){
                            s = 1;
                        }
                        break;
                    case  28:
                        if(Breast_Abnormal == "YES"){
                            s = 1;
                        }
                        break;
                    case 29:
                        if(Blemish != No){
                            s = 1;
                        }
                        break;
                    case 30:
                        if(Urination == Bloody){
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
                        problem = "Bladder Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 2 */
                        /****** comment 1510 ******/
                    case 2 ... 4:
                        problem = "Kidney Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 3 */
                    case 5:
                        problem = "Basal Carcinoma";
                        std::cout << "PROBLEM: " << problem;
                        break;
                        /* then part of statement 6 */
                    case 6:
                        securitySoftware = "Squamous Carcinoma";
                        std::cout << "SECURITY SOFTWARE: " << securitySoftware;
                        break;
                    case 7:
                        problem = "Melanoma";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 8:
                        problem = "Breast Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 9:
                        problem = "Breast Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 10:
                        problem = "Colon Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 11:
                        problem = "Colon Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 12:
                        problem = "Liver or Pancreatic Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 13:
                        problem = "Esophageal Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 14:
                        problem = "Thyroid Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 15:
                        problem = "Lung Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 16:
                        problem = "Prostate Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 17:
                        problem = "Endometrial Cancer";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 18:
                        problem = "Lymphoma";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 19:
                        problem = "Lymphoma";
                        std::cout << "PROBLEM: " << problem;
                        break;
                    case 20:
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
            case 1: std::cout << "Is your Urination Frequent?INPUT YES OR NO... \n";
                Urination_freq = yesOrNoValidation();
                break;
            case 2: std::cout << "Is your Urination Bloody?INPUT YES OR NO... \n";
                Urination_bloody = yesOrNoValidation();
                break;
            case 3: std::cout << "Do you have discomfort in your back? INPUT YES OR NO... \n";
                Discomfort_in_back = yesOrNoValidation();
                break;
            case 4: std::cout << "Do you have a lump on your abdomen or back? INPUT YES OR NO... \n";
                Lump_on_back_or_abdomen = yesOrNoValidation();
                break;
            case 5: std::cout << "Do you have a waxy and recurring bump on your skin? INPUT YES OR NO... \n";
                Waxy_blemish = yesOrNoValidation();
                break;
            case 6: std::cout << "Do you have a red and crusty bump on your skin? INPUT YES OR NO... \n";
                Red_crusty_blemish = yesOrNoValidation();
                break;
            case 7: std::cout << "Do you have a mishapen or discolored bump on your skin? INPUT YES OR NO... \n";
                Mishapen_blemish = yesOrNoValidation();
                break;
            case 8: std::cout << "Do you notice anything abnormal about your breast? INPUT YES OR NO... \n";
                Breast_abnormal = yesOrNoValidation();
                break;
            case 9: std::cout << "Are you male or femail? INPUT YES FOR MALE OR NO FOR FEMALE... \n";
                Gender = yesOrNoValidation();
                break;
            case 10: std::cout << "Do you have a family history of breast cancer? INPUT YES OR NO... \n";
                Family_history = yesOrNoValidation();
                break;
            case 11: std::cout << "Do you have abnormal or bloody bowel movements? INPUT YES OR NO... \n";
                Bowel_movements = yesOrNoValidation();
                break;
            case 12: std::cout << "Do you have colon polyps?";
                Colon_polyps = realNumberValidation();
                break;
            case 13: std::cout << "Do you have a loss of appetite or feel nauseated? input YES or NO) \n";
                Appetite_or_nausea = yesOrNoValidation();
                break;
            case 14: std::cout << "Do you have discomfort in the stomach? enter YES or NO... \n";
                Discomfort_in_stomach = yesOrNoValidation();
                break;
            case 15: std::cout << "Are you experiencing any jaundice? INPUT YES OR NO... \n";
                Jaundice = yesOrNoValidation();
                break;
            case   16: std::cout << "Are you experiencing any unintentional weight loss? INPUT YES OR NO... \n";
                Weight_loss = yesOrNoValidation();
                break;
            case 17: std::cout << "Are you having trouble swallowing? INPUT YES OR NO... \n";
                Trouble_swallowing = yesOrNoValidation();
                break;
            case 18: std::cout << "Do you have a persistent cough? INPUT YES OR NO... \n";
                Persistent_cough = yesOrNoValidation();
                break;
            case 19: std::cout << "Do you have a lump on your lymph node? INPUT YES OR NO... \n";
                Lump_on_lymph_node = yesOrNoValidation();
                break;
            case 20: std::cout << "Are you coughing blood? INPUT YES OR NO... \n";
                Cough_blood = yesOrNoValidation();
                break;
            case 21: std::cout << "Do you have discomfort in the bottom or pelvic area? INPUT YES OR NO... \n";
                Discomfort_in_pelvic_area = yesOrNoValidation();
                break;
            case 22: std::cout << "Do you night sweats or chills and a fever throughout the day? INPUT YES OR NO... \n";
                Fever = yesOrNoValidation();
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
