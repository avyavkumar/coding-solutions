#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        std::vector<int> finalResult;
        finalResult.resize(nums.size(),1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    finalResult[i] = max(finalResult[i],finalResult[j]+1);
        }

        return *max_element(finalResult.begin(), finalResult.end());
    }
};
