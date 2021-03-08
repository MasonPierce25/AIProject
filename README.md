# AIProject

Compilation and Running Instructions:
Download and move files into school linux server using filezilla.
Compile using command: "make"
Run using command: "./a.out"
Rerun using command: "./a.out"

Project for AI:
This is a model for an Abstract Expert System.
This system represents information of a maximum of 64 variables of 4 states and a maximum of 256 rules.
The text of these variables is imported from a .txt files and mapped onto their respective variables, this provides English-Readable input.

Forward Chaining:
This Expert System supports Forward Chaining as a method of finding variables to initialize. Variables that are initialized in Forward Chaining are requested from the user in an order needed to fulfill the closest available branch. If the branch can not be deduced, the variables are further requested from the user. If nothing was deduced, the function ends and only the variables requested from the user will remain initialized. This function occurs in an iterative, bottom-up, breadth-first search.

Backward Chaining:
This Expert System supports Backward Chaining as a method of verification and initialization of variables. Variables are initialized in Backward Chaining in order to satisfy the goal variable and all dependencies of that variable. If a path can not be found for a variable to be initialized, it will try all possible other paths. This function performs in a recursive, top-down, depth-first search and completes when no further variables can be deduced.

Data Structures Used:
This system is composed of a Rule Base consisting of an array of 256 Rules (each 5 bytes), and a Fact Base consisting of 16 bytes, each byte represting 4 fact values. This system only supports short and structures meaning all conditional facts in a rule must match the fact base in order to get the resulting consequent. Values in the rule that are not used are denoted by the value NULL_VAR or 0x00. Names of unused variable states are denoted with the string "-". Another structure of 64 bits represents whether or not a value is initialized in the fact base. The fundamental structure of a fact is a single byte consisting of a Variable/Value pair. The upper 6 bits store the Variable index being checked from 0-63, while the lower 2 bits store the Value of the variable to be set or verified from 0-3. Names for these variables are stored in two separate arrays -- one for the variable, one for the variable states.

File System:
This system reads and initializes names and rules from a file using a specialized human-readable syntax. This syntax is parsed by new line and space characters. Variables are automatically initialized by the file system and linked to their readable names.
