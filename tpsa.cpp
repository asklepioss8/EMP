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
    readFile("data.txt");
    
    // process the smiles
    processSmiles(kwData, kwDataSplit);

    createFunctionPointers();
}

TPSA::~TPSA()
{
}


void TPSA::readFile(std::string fileName)
{
    // read the data from the file without whitespaces and store it in a string
    std::ifstream file(fileName);
    std::string str;

    std::ostringstream sstr;
    sstr << file.rdbuf();
    str = sstr.str();
    // end the file streams
    file.close();

    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::unique(str.begin(), str.end(), [](char a, char b) {return a == '\n' && b == '\n'; }), str.end());


    size_t currentPos = 0;
    // create an iterator over the string
    for (std::string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (*it == '\0')
        {
            std::string subStr = str.substr(currentPos, str.find('\n', currentPos) - currentPos);
            double d = std::stod(subStr);
            psaData.push_back(d);
        }
        else if (*it == '>')
        {
            std::string subStr = str.substr(currentPos, str.find('>', currentPos) - currentPos);
            kwData.push_back(subStr);
            currentPos = str.find('>', currentPos) + 1;
        }
        else if (*it == '\n')
        {
            std::string subStr = str.substr(currentPos, str.find('\n', currentPos) - currentPos);
            double d = std::stod(subStr);
            psaData.push_back(d);
            currentPos = str.find('\n', currentPos) + 1;
        }
    }
    threadOutputs = new(bool[currentPos]){};
}

void TPSA::groupCheckTypeI(std::vector<std::string>* _groupData, size_t id)
{
    size_t len = _groupData->size();

    size_t* posArr = new(size_t[len]){};
    for (int i = 0; i < len; ++i)
    {
        // if find string in smiles
        size_t pos = smiles.find((*_groupData)[i]);
        if (pos != std::string::npos)
        {
            posArr[i] = pos;
        }
        else
        {
            threadOutputs[id] = false;
            return;
        }
    }

    // create the substrings
    std::string* subStrArr = new(std::string[len]){};
    for (size_t i = 0; i < len - 1; ++i)
    {
        subStrArr[i] = smiles.substr(posArr[i] + (*_groupData)[i].size(), posArr[i + 1] - posArr[i] - 1);
    }
    // + for the last one
    subStrArr[len - 1] = smiles.substr(posArr[len - 1] + (*_groupData)[len - 1].size(), smiles.size() - posArr[len - 1] - 1);


    // check if the substrings are valid
    for (size_t i = 0; i < len; ++i)
    {
        if (!checkParenthesis(subStrArr[i]))
        {
            threadOutputs[id] = false;
            return;
        }
    }
    threadOutputs[id] = true;
}

void TPSA::groupCheckTypeII(std::vector<std::string>* _groupData, size_t id)
{
    size_t len = _groupData->size();

    size_t* posArr = new(size_t[len - 1]){};
    for (int i = 0; i < len; ++i)
    {
        // if find string in smiles
        size_t pos = smiles.find((*_groupData)[i]);
        if (pos != std::string::npos)
        {
            posArr[i] = pos;
        }
        else
        {
            threadOutputs[id] = false;
            return;
        }
    }

    // create the substrings
    std::string* subStrArr = new(std::string[len - 1]){};
    for (size_t i = 0; i < len - 1; ++i)
    {
        subStrArr[i] = smiles.substr(posArr[i] + (*_groupData)[i].size(), posArr[i + 1] - posArr[i] - 1);
    }

    // check if the substrings are valid
    for (size_t i = 0; i < len; ++i)
    {
        if (!checkParenthesis(subStrArr[i]))
        {
            threadOutputs[id] = false;
            return;
        }
    }
    threadOutputs[id] = true;

}

void TPSA::createFunctionPointers()
{
    for (size_t i = 0; i < kwData.size(); ++i)
    {
        if (kwData[i].back() == '*')
        {
            std::thread t(&TPSA::groupCheckTypeI, this, &kwDataSplit[i], i);
            t.detach();
        }
        else
        {
            std::thread t(&TPSA::groupCheckTypeII, this, &kwDataSplit[i]);
            t.detach();
        }


    }
}



int main()
{

    TPSA tpsa("[N](-C)(-C)-C");

    return 0;
}

