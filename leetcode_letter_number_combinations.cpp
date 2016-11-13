#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    void helper(string digits, std::vector<string> &finalResult, string tempResult, std::vector<std::vector<char>> refTable)
    {
        if (digits.length() == 0)
        {
            string temp = tempResult;
            finalResult.push_back(temp);
            return;
        }
        else
        {
            int current = digits[0]-'0';
            for (int i = 0; i < refTable[current].size(); i++)
            {
                tempResult += refTable[current][i];
                helper(digits.substr(1,digits.size()-1), finalResult, tempResult, refTable);
                tempResult.erase(tempResult.size()-1);
            }
        }
    }

    std::vector<string> letterCombinations(string digits)
    {
        std::vector<string> finalResult;
        if (digits.empty() || digits.size() < 1)
            return finalResult;

        std::vector<std::vector<char>> refTable(10);
        char current = 'a';
        int indexLetter = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i == 0 || i == 1) continue;
            else if (i == 7 || i == 9)
            {
                refTable[i].resize(4);
                for (int p = 0; p < 4; p++)
                {
                    refTable[i][p] = static_cast<char>(current+indexLetter);
                    indexLetter++;
                }
            }
            else
            {
                refTable[i].resize(3);
                for (int p = 0; p < 3; p++)
                {
                    refTable[i][p] = static_cast<char>(current+indexLetter);
                    indexLetter++;
                }
            }
        }

        string tempResult = "";
        helper(digits, finalResult, tempResult, refTable);
        return finalResult;
    }
};
