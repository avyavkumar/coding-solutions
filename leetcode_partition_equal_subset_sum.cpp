#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        if (nums.empty())
            return true;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum+=nums[i];
        if (totalSum%2 != 0)
            return false;
        bool dp[totalSum/2+1][nums.size()+1];

        for (int i = 0; i < totalSum/2+1; i++)
            dp[i][0] = false;
        for (int j = 0; j < nums.size()+1; j++)
            dp[0][j] = true;

        for (int i = 1; i < totalSum/2+1; i++)
        {
            for (int j = 1; j < nums.size()+1; j++)
            {
                dp[i][j] = dp[i][j-1];
                if (i >= nums[j-1])
                    dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
            }
        }

        return dp[totalSum/2][nums.size()];
    }
};
