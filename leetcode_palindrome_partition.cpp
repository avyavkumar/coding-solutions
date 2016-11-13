#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        if (s.length() == 0 || s.empty())
            return 0;

        std::vector<std::vector<bool>> isPal(s.length());
        std::vector<int> dp(s.length());

        for (int i = 0; i < s.length(); i++)
            isPal[i].resize(s.length(), false);

        for (int j = 0; j < s.length(); j++)
        {
            dp[j] = j;
            for (int i = 0; i <= j; i++)
            {
                if (s[i] == s[j] && (j-i <= 1 || isPal[i+1][j-1] == true))
                {
                    isPal[i][j]= true;
                    if ( i > 0)
                        dp[j] = min(dp[j], dp[i-1]+1);
                    else
                        dp[j] = 0;
                }
            }
        }

        return dp[s.length()-1];
    }
};
