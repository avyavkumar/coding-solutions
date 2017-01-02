#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        std::vector<int> lowerElements(nums.size(),1);
        std::vector<int> greaterElements(nums.size(),1);
        std::vector<int> finalResult(nums.size());

        for (int i = 0; i < lowerElements.size()-1; i++)
            lowerElements[i+1] = nums[i]*lowerElements[i];

        for (int i = greaterElements.size()-1; i > 0; i--)
            greaterElements[i-1] = nums[i]*greaterElements[i];

        for (int i = 0; i < greaterElements.size(); i++)
            finalResult[i] = greaterElements[i]*lowerElements[i];

        return finalResult;
    }
};
