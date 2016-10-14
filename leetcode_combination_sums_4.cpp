#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        std::vector<long long int > dp;
        dp.resize(target+1, 0);
        for (int i = 1; i < target+1; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] > i)
                    break;
                else if (nums[j] == i)
                    dp[i] += 1;
                else
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
