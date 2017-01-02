#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        std::vector<std::vector<int>> dp;
        dp.resize(dungeon.size());

        for (int i = 0; i < dp.size(); i++)
            dp[i].resize(dungeon[i].size(),0);

        if (dungeon[m-1][n-1] > 0)
            dp[dungeon.size()-1][dungeon[0].size()-1] = 1;
        else
            dp[dungeon.size()-1][dungeon[0].size()-1] = abs(dungeon[m-1][n-1]) + 1;

        for (int i = m-2; i >= 0; i--)
            dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 1);

        for (int j = n-2; j >= 0; j--)
            dp[m-1][j] = max(dp[m-1][j+1] - dungeon[m-1][j], 1);

        for (int i = m-2; i >= 0; i--)
            for (int j = n-2; j >= 0; j--)
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],1);

        return dp[0][0];
    }
};
