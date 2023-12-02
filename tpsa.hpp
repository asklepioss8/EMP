
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


#include "utils.hpp"


class TPSA
{
public:
    TPSA(std::string smiles);
    ~TPSA();

    TPSA(const TPSA&) = delete;
    TPSA& operator=(const TPSA&) = delete;
    TPSA(TPSA&&) = delete;
    TPSA& operator=(TPSA&&) = delete;

    std::string smiles;

private:
    double total_tpsa = 0.0;

    // group structure data and its size
    std::vector<std::string> kwData{};
    std::vector<std::vector<std::string>> kwDataSplit{};
    std::vector<double> psaData{};

    // boolean thread outputs 
    bool* threadOutputs{};


    void readFile(std::string fileName);


    // The main two template for group type I and II
    // -The groups that end with non hydrogen group (asteriks) # the kwCount = subStrCount
    void groupCheckTypeI(std::vector<std::string>* _groupData, size_t id);
    // -The groups that end with defined group (non-asteriks) # the kwCount = subStrCount + 1
    void groupCheckTypeII(std::vector<std::string>* _groupData, size_t id);

    void createFunctionPointers();



};













