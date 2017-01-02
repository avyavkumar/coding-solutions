#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";

        int minIndex = 0;
        int minLength = strs[0].length();
        for (int i = 0; i < strs.size(); i++)
        {
            if (minLength > strs[i].length())
            {
                minLength = strs[i].length();
                minIndex = i;
            }
        }
        string minString = strs[minIndex];
        for (int i = 0; i < strs.size(); i++)
        {
            int p;
            for (p = 0; p < minString.length(); p++)
                if (minString[p] != strs[i][p])
                    break;
            minString = minString.substr(0,(p >= minString.length()) ? minString.length() : p);
        }

        return minString;
    }
};
