#include <bits/stdc++.h>

using namespace std;

std::vector<std::string> finalResult;

class Solution
{
public:
    void generateStrings(string str, int left, int right)
    {
        if (left > right)
            return;
        if (left == 0 && right == 0)
        {
            string newStr;
            newStr = str.c_str();
            finalResult.push_back(newStr);
            return;
        }
        if (left > 0)
            generateStrings(str + "(", left-1, right);
        if (right > 0)
            generateStrings(str + ")", left, right-1);
    }
    vector<string> generateParenthesis(int n)
    {
        finalResult.clear();
        string str = "";
        generateStrings(str, n, n);
        return finalResult;
    }
};
