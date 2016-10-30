#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        std::vector<int> dp(nums.size(),0);
        std::vector<int> minElements(nums.size(),0);
        dp[0] = nums[0];
        minElements[0] = nums[0];
        int finalResult = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                dp[i] = max(nums[i],dp[i-1]*nums[i]);
                minElements[i] = min(nums[i], minElements[i-1]*nums[i]);
            }
            else
            {
                dp[i] = max(nums[i],minElements[i-1]*nums[i]);
                minElements[i] = min(nums[i], dp[i-1]*nums[i]);
            }
            finalResult = max(finalResult,dp[i]);
        }

        return finalResult;
    }
};
