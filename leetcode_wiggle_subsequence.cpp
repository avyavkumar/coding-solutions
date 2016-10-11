#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        std::vector<int> wiggleLength;
        wiggleLength.resize(nums.size(), 1);
        if (nums[0] != nums[1])
            wiggleLength[1] = 2;
        else
            wiggleLength[1] = 1;
        int difference = nums[1] - nums[0];
        for (int i = 2; i < wiggleLength.size(); i++)
        {
            if ((nums[i]-nums[i-1]) != 0 && difference == 0)
            {
                wiggleLength[i] = wiggleLength[i-1]+1;
                difference = nums[i] - nums[i-1];
            }
            else if ((nums[i]-nums[i-1])*difference < 0)
            {
                wiggleLength[i] = wiggleLength[i-1]+1;
                difference = nums[i] - nums[i-1];
            }
            else
                wiggleLength[i] = wiggleLength[i-1];
        }
        return wiggleLength[nums.size()-1];
    }
};
