#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    std::vector<string> listAddresses;

    bool isValid(string s)
    {
        if (s.length() == 0 || (s.length() > 1 && s[0] == '0') || stoi(s) < 0 || stoi(s) > 255)
            return false;
        return true;
    }

    void restoreIpAddressesHelper(std::string &finalResult, string s, int i, int count)
    {
        if (count == 4 && i == s.length())
        {
            finalResult.pop_back();
            listAddresses.push_back(finalResult);
            return;
        }

        if (count == 4 && (i > s.length() || s.length() != i))
            return;

        string tempString = "";
        for (int x = i; x < min(i+3, (int)s.length()); x++)
        {
            tempString += s[x];
            string tempResult = finalResult;
            if (isValid(tempString))
            {
                finalResult += tempString + '.';
                restoreIpAddressesHelper(finalResult,s,x+1,count+1);
            }
            finalResult = tempResult;
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        listAddresses.clear();
        string finalResult;
        restoreIpAddressesHelper(finalResult,s,0,0);
        return listAddresses;
    }
};
