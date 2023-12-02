#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>


void readFile(std::string fileName, std::vector<std::string>& smiles, std::vector<double>& psa)
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
            psa.push_back(d);
        }
        else if (*it == '>')
        {
            std::string subStr = str.substr(currentPos, str.find('>', currentPos) - currentPos);
            smiles.push_back(subStr);
            currentPos = str.find('>', currentPos) + 1;
        }
        else if (*it == '\n' )
        {
            std::string subStr = str.substr(currentPos, str.find('\n', currentPos) - currentPos);
            double d = std::stod(subStr);
            psa.push_back(d);
            currentPos = str.find('\n', currentPos) + 1;
        }
    }
}

void processSmiles(std::vector<std::string>& smiles, std::vector<std::vector<std::string>>& output)
{
    for (std::string str : smiles)
    {
        // split the string into substrings from "*" based on the regex
        std::regex re("\\*");
        std::sregex_token_iterator it{ str.begin(), str.end(), re, -1 }, reg_end;

        std::vector<std::string> vec;
        for (; it != reg_end; ++it)
        {
            vec.push_back(*it);
        }
        vec.shrink_to_fit();
        output.push_back(vec);
    }


    output.shrink_to_fit();
}