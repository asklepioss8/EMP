
/*
smiles	name
CC(=O)OCC[N+](C)(C)C	    Acetylcholine
CC(C[N+](C)(C)C)OC(=O)C	    Metacholine
O=C1CCCN1CC#CC[N+](C)(C)C	OxotremorineM
NC(=O)OCC[N+](C)(C)C	    Carbachol
CC(C[N+](C)(C)C)OC(=O)N	    Bethanechol
Cc1ccc(o1)C[N+](C)(C)C      Methylfurmethide
COC(=O)C1=CCCN(C1)C         Arecoline
O=C1CCCN1CC#CCN1CCCC1	    Oxotremorine
CON=CC1=CCCN(C1)C	        Milameline
CN1CC(=CCC1)C(=O)OCC#C	    Arecaidine-propargyl-ester
CCC1C(=O)OCC1Cc1cncn1C	    Pilocarpine
CC(=O)OC1C[NH+]2CCC1CC2	    Aceclidine
*/

// Below the list is possible groups for the TPSA calculation
// The first column is the SMILES code for the group
// The second column is the TPSA value for the group
// We are going to create check for each group and add the TPSA value to the total TPSA value
// Each group has to be checked by different function that return true or false
// If the function return true, the TPSA value is added to the total TPSA value
// So we can make these operations in multiple threads later
/*
* 
* 
[N](-*)(-*)-*       3.24 
[N](-*)=*           12.36
[N]#*               23.709
[N](-*)(=*)=*       11.68
[N](=*)#*           13.60
[N]1(-*)-*-*-1      3.01
[NH](-*)-*          12.03
[NH]1-*-*-1         21.94
[NH]=*              23.85
[NH2]-*             26.02
[N+](-*)(-*)(-*)-*  0.00
[N+](-*)(-*)=*      3.01
[N+](-*)#*          4.36
[NH+](-*)(-*)-*     4.44
[NH+](-*)=*         13.97
[NH2+](-*)-*        16.61
[NH2+]=*            25.59
[NH3+]-*            27.64

[nH](:*):*          15.79
[n+](:*)(:*):*      4.10
[n+](-*)(:*):*      3.88
[nH+](:*):*         14.14
[n](:*):*           12.89
[n](:*)(:*):*       4.41
[n](-*)(:*):*       4.93
[n](=*)(:*):*       8.39

[O](-*)-*           9.23
[O]1-*-*-1          12.53
[O]=*               17.07
[OH]-*              20.23
[O-]-*              23.06

[o](:*):*           13.14

[S](-*)-*           25.30
[S]=*               32.09
[S](-*)(-*)=*       19.21
[S](-*)(-*)(=*)=*   8.38
[SH]-*              38.80

[s](:*):*           28.24
[s](=*)(:*):*       21.70

[P](-*)(-*)-*       13.59
[P](-*)=*           34.14
[P](-*)(-*)(-*)=*   9.81
[PH](-*)(-*)=*      23.47
*/


#include <iostream>
#include <string>
#include <vector>


bool checkGroupN1(std::string smiles);
bool checkGroupN2(std::string smiles);
bool checkGroupN3(std::string smiles);
bool checkGroupN4(std::string smiles);
bool checkGroupN5(std::string smiles);
bool checkGroupN6(std::string smiles);
bool checkGroupN7(std::string smiles);
bool checkGroupN8(std::string smiles);
bool checkGroupN9(std::string smiles);
bool checkGroupN10(std::string smiles);
bool checkGroupN11(std::string smiles);
bool checkGroupN12(std::string smiles);
bool checkGroupN13(std::string smiles);
bool checkGroupN14(std::string smiles);
bool checkGroupN15(std::string smiles);
bool checkGroupN16(std::string smiles);
bool checkGroupN17(std::string smiles);
bool checkGroupN18(std::string smiles);

bool checkGroupn1(std::string smiles);
bool checkGroupn2(std::string smiles);
bool checkGroupn3(std::string smiles);
bool checkGroupn4(std::string smiles);
bool checkGroupn5(std::string smiles);
bool checkGroupn6(std::string smiles);
bool checkGroupn7(std::string smiles);
bool checkGroupn8(std::string smiles);

bool checkGroupO1(std::string smiles);

class TPSA
{
public:
    // create default constructor and destructor
    TPSA();
    ~TPSA();

    // make the class uncopyable and unmovable
    TPSA(const TPSA&) = delete;
    TPSA& operator=(const TPSA&) = delete;
    TPSA(TPSA&&) = delete;
    TPSA& operator=(TPSA&&) = delete;

private:
    // total TPSA value
    double total_tpsa = 0.0;

    // Functions
    // - check starting with "[N"
    // - check starting with "[n"
    // - check starting with "[O"
    // - check starting with "[o"
    // - check starting with "[S"
    // - check starting with "[s"
    // - check starting with "[P"



};













