#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return;

        int firstIndex = 0, secondIndex = 0;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                firstIndex = i;
                break;
            }
        }
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (nums[i] > nums[firstIndex])
            {
                secondIndex = i;
                break;
            }
        }

        if (firstIndex == 0 && secondIndex == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int temp = nums[firstIndex];
        nums[firstIndex] = nums[secondIndex];
        nums[secondIndex] = temp;

        reverse(nums.begin()+firstIndex+1, nums.end());
    }
};
