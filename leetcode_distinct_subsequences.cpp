#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        std::vector<std::vector<int>> dp;
        dp.resize(s.length()+1);
        for (int i = 0; i < dp.size(); i++)
            dp[i].resize(t.length()+1,0);

        for (int i = 0; i < s.length(); i++)
            dp[i][0] = 1;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                if (s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[s.length()][t.length()];
    }
};
