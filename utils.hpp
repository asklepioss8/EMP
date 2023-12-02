#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>




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