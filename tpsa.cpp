#include "tpsa.hpp"


bool checkParenthesis(std::string &str)
{
    int count = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            ++count;
        }
        else if (str[i] == ')')
        {
            --count;
        }
    }

    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// create the constructor list for TPSA
TPSA::TPSA(std::string smiles)
{
    this->smiles = smiles;

    // read the data from the file
    readFile("data.txt", kwData, psaData);
    
    // process the smiles
    processSmiles(kwData, kwDataSplit);
    std::cout << "Done process the data file" << std::endl;
}

TPSA::~TPSA()
{
}

bool TPSA::groupCheckTypeI(std::string* _group)
{
    return true;
}

void TPSA::createFunctionPointers()
{
    for (size_t i = 0; i < kwData.size(); ++i)
    {

    }
}



int main()
{

    TPSA tpsa("[N](-C)(-C)-C");

    return 0;
}

