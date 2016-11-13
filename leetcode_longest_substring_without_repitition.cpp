#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty() || s.length() <= 1)
            return s.length();

        std::set<char> hashSet;

        int maxLength = 0;
        int i = 0;
        int start = 0;

        while (i < s.length())
        {
            if (hashSet.find(s[i]) == hashSet.end())
                hashSet.insert(s[i]);
            else
            {
                maxLength = max(maxLength, (int)hashSet.size());
                while (start < i && s[start] != s[i])
                {
                    hashSet.erase(hashSet.find(s[start]));
                    start++;
                }
                start++;
            }
            i++;
        }

        maxLength = max(maxLength, (int)hashSet.size());
        return maxLength;
    }
};
