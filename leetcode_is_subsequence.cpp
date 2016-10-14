#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        long long int sPointer = 0;
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == s[sPointer])
                sPointer++;
        }
        return sPointer == s.length();
    }
};
