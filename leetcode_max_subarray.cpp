#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 1)
            return nums[0];

        if (nums.size() == 2)
            return max(nums[0], max(nums[1], nums[0]+nums[1]));

        int maxResult;
        int finalResult[nums.size()];
        finalResult[0] = nums[0];
        maxResult = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            finalResult[i] = max(nums[i], finalResult[i-1] + nums[i]);
            maxResult = max(finalResult[i],maxResult);
        }

        return maxResult;
    }
};
