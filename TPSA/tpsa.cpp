#include "tpsa.hpp"

/*
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
*/

bool checkParenthesis(std::string subStr)
{
    int count = 0;
    for (int i = 0; i < subStr.size(); i++)
    {
        if (subStr[i] == '(')
        {
            count++;
        }
        else if (subStr[i] == ')')
        {
            count--;
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

int findSubStr(std::string str, std::string subStr)
{
    // q: what does std::string::find() return if it doesn't find the subStr?
    // a: std::string::npos
    // q: what is std::string::npos?

    int pos = str.find(subStr);
    if (pos != std::string::npos)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

// There is asterisk count of substring to check and other substring to check is it in smiles

// [N](- * )(- * )- *       3.24 
bool checkGroup1(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;


    temp1 = smiles.find("[N](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find(")-");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// [N](-*)=*           12.36
bool checkGroup2(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[N](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")=");
        if (temp2 != std::string::npos)
        {
            temp1 += 5;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}
        

// [N]#*               23.709
bool checkGroup3(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[N]#");
    if (temp1 != std::string::npos)
    {
        temp1 += 4;

        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}

// [N](-*)(=*)=*       11.68
bool checkGroup4(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[N](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(=");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find(")=");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [N](=*)#*           13.60
bool checkGroup5(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[N](=");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")#");
        if (temp2 != std::string::npos)
        {
            temp1 += 5;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [N]1(-*)-*-*-1      3.01
bool checkGroup6(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;
    int temp4;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;
    std::string subStr4;

    temp1 = smiles.find("[N]1(-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("-");
            if (temp3 != std::string::npos)
            {
                temp4 = smiles.find("-1");
                if (temp4 != std::string::npos)
                {
                    temp1 += 6;

                    subStr1 = smiles.substr(temp1, temp2 - temp1);
                    subStr2 = smiles.substr(temp2 + 2, temp3 - temp2 - 2);
                    subStr3 = smiles.substr(temp3 + 1, temp4 - temp3 - 1);
                    subStr4 = smiles.substr(temp4 + 2, smiles.size() - temp4 - 2);
                    
                    if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3) && checkParenthesis(subStr4))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false; 
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH](-*)-*          12.03
bool checkGroup7(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[NH](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")-");
        if (temp2 != std::string::npos)
        {
            temp1 += 6;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH]1-*-*-1         21.94
bool checkGroup8(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[NH]1-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find("-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("-1");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 1, temp3 - temp2 - 1);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH]=*              23.85
bool checkGroup9(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[NH]=");
    if (temp1 != std::string::npos)
    {
        temp1 += 5;

        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}

// [NH2]-*             26.02
bool checkGroup10(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[NH2]-");
    if (temp1 != std::string::npos)
    {
        temp1 += 6;

        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}

// [N+](-*)(-*)(-*)-*  0.00
bool checkGroup11(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;
    int temp4;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;
    std::string subStr4;

    temp1 = smiles.find("[N+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find(")(-");
            if (temp3 != std::string::npos)
            {
                temp4 = smiles.find(")-");
                if (temp4 != std::string::npos)
                {
                    temp1 += 5;

                    subStr1 = smiles.substr(temp1, temp2 - temp1);
                    subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                    subStr3 = smiles.substr(temp3 + 3, temp4 - temp3 - 3);
                    subStr4 = smiles.substr(temp4 + 2, smiles.size() - temp4 - 2);
                    
                    if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3) && checkParenthesis(subStr4))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false; 
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [N+](-*)(-*)=*      3.01
bool checkGroup12(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[N+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find(")=");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [N+](-*)#*          4.36
bool checkGroup13(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[N+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")#");
        if (temp2 != std::string::npos)
        {
            temp1 += 5;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH+](-*)(-*)-*     4.44
bool checkGroup14(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[NH+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find(")-");
            if (temp3 != std::string::npos)
            {
                temp1 += 6;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; 
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH+](-*)=*         13.97
bool checkGroup15(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[NH+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")=");
        if (temp2 != std::string::npos)
        {
            temp1 += 6;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH2+](-*)-*        16.61
bool checkGroup16(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[NH2+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")-");
        if (temp2 != std::string::npos)
        {
            temp1 += 7;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false; 
    }
}

// [NH2+]=*            25.59
bool checkGroup17(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[NH2+]=");
    if (temp1 != std::string::npos)
    {
        temp1 += 6;

        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}

// [NH3+]-*            27.64
bool checkGroup18(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[NH3+]-");
    if (temp1 != std::string::npos)
    {
        temp1 += 6;

        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}



/*
[nH](:*):*          15.79
[n+](:*)(:*):*      4.10
[n+](-*)(:*):*      3.88
[nH+](:*):*         14.14
[n](:*):*           12.89
[n](:*)(:*):*       4.41
[n](-*)(:*):*       4.93
[n](=*)(:*):*       8.39
*/

// [nH](:*):*          15.79
bool checkGroup19(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[nH](:");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find("):");
        if (temp2 != std::string::npos)
        {
            temp1 += 5;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n+](:*)(:*):*      4.10
bool checkGroup20(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[n+](:");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(:");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("):");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }
            else
            {
                return false; 
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n+](-*)(:*):*      3.88
bool checkGroup21(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[n+](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(:");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("):");
            if (temp3 != std::string::npos)
            {
                temp1 += 5;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }
            else
            {
                return false; 
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [nH+](:*):*         14.14
bool checkGroup22(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[nH+](:");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find("):");
        if (temp2 != std::string::npos)
        {
            temp1 += 6;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n](:*):*           12.89
bool checkGroup23(std::string smiles)
{
    int temp1;
    int temp2;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[n](:");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find("):");
        if (temp2 != std::string::npos)
        {
            temp1 += 4;

            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n](:*)(:*):*       4.41
bool checkGroup24(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[n](:");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(:");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("):");
            if (temp3 != std::string::npos)
            {
                temp1 += 4;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }
            else
            {
                return false; 
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n](-*)(:*):*       4.93
bool checkGroup25(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[n](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(:");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("):");
            if (temp3 != std::string::npos)
            {
                temp1 += 4;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }
            else
            {
                return false; 
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

// [n](=*)(:*):*       8.39
bool checkGroup26(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;
    std::string subStr3;

    temp1 = smiles.find("[n](=");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")(:");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("):");
            if (temp3 != std::string::npos)
            {
                temp1 += 4;

                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 3, temp3 - temp2 - 3);
                subStr3 = smiles.substr(temp3 + 2, smiles.size() - temp3 - 2);
                
                if (checkParenthesis(subStr1) && checkParenthesis(subStr2) && checkParenthesis(subStr3))
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }
            else
            {
                return false; 
            } 
        }
        else
        {
            return false; 
        } 
    }
    else
    {
        return false; 
    }
}

/*
[O](-*)-*           9.23
[O]1-*-*-1          12.53
[O]=*               17.07
[OH]-*              20.23
[O-]-*              23.06
*/

// [O](-*)-*           9.23
bool checkGroup27(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;

    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[O](-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find(")-");
        if (temp2 != std::string::npos)
        {
            temp1 += 4;
            subStr1 = smiles.substr(temp1, temp2 - temp1);
            subStr2 = smiles.substr(temp2 + 2, smiles.size() - temp2 - 2);

            if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// [O]1-*-*-1          12.53
bool checkGroup28(std::string smiles)
{
    int temp1;
    int temp2;
    int temp3;
    
    std::string subStr1;
    std::string subStr2;

    temp1 = smiles.find("[O]1-");
    if (temp1 != std::string::npos)
    {
        temp2 = smiles.find("-");
        if (temp2 != std::string::npos)
        {
            temp3 = smiles.find("-1");
            if (temp3 != std::string::npos)
            {
                temp1 += 4;
                subStr1 = smiles.substr(temp1, temp2 - temp1);
                subStr2 = smiles.substr(temp2 + 1, temp3 - temp2 - 1);

                if (checkParenthesis(subStr1) && checkParenthesis(subStr2))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        } 
    }
    else
    {
        return false;
    }
}

// [O]=*               17.07
bool checkGroup29(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[O]=");
    if (temp1 != std::string::npos)
    {
        temp1 += 4;
        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
    else
    {
        return false;
    }
}

// [OH]-*              20.23
bool checkGroup30(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[OH]-");
    if (temp1 != std::string::npos)
    {
        temp1 += 5;
        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
    else
    {
        return false;
    }
}

// [O-]-*              23.06
bool checkGroup31(std::string smiles)
{
    int temp1;
    
    std::string subStr1;

    temp1 = smiles.find("[O-]-");
    if (temp1 != std::string::npos)
    {
        temp1 += 5;
        subStr1 = smiles.substr(temp1, smiles.size() - temp1);

        if (checkParenthesis(subStr1))
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
    else
    {
        return false;
    }
}



int main()
{
    if (checkGroup1("[N](-C)(-O)-C"))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}