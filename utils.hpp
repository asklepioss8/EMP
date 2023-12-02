#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include <thread>



// create a print function that prints with given color
void colorPrint(int color, std::string str)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << str << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

// create a progress bar function
void progressBar(int progress)
{
    int barWidth = 70;
    float progressRatio = (float)progress / 100;
    std::cout << "[";
    int pos = barWidth * progressRatio;
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
        {
            std::cout << "=";
        }
        else if (i == pos)
        {
            std::cout << ">";
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << "] " << progress << " %\r\n";
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