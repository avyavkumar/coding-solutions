#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        std::vector<std::vector<bool>> dp;
        dp.resize(s1.length()+1);
        for (int i = 0; i < s1.length()+1; i++)
            dp[i].resize(s2.length()+1,false);

        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                if (i + j == 0)
                    dp[i][j] = true;
                else if (i == 0 && s3[j-1] == s2[j-1])
                    dp[i][j] = dp[i][j-1];
                else if (j == 0 && s3[i-1] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                else if (s3[i+j-1] == s1[i-1] && s1[i-1] != s2[j-1])
                    dp[i][j] = dp[i-1][j];
                else if (s3[i+j-1] == s2[j-1] && s1[i-1] != s2[j-1])
                    dp[i][j] = dp[i][j-1];
                else if (s3[i+j-1] == s2[j-1] && s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }

        return dp[s1.length()][s2.length()];
    }
};
