#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        std::vector<int> listNumbers(nums.size(),-1);
        for (int i = 0; i < nums.size(); i++)
            listNumbers[nums[i]] = nums[i];

        for (int i = 0; i < listNumbers.size(); i++)
            if (listNumbers[i] == -1)
                return i;

        return nums.size();
    }
};
