#include <bits/stdc++.h>

using namespace std;

std::vector<long long int> sumValues;
bool nullArray;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        if (nums.empty())
            nullArray = true;
        else
            nullArray = false;
        sumValues.clear();
        sumValues.resize(nums.size(), 0);
        if (!nums.empty())
            sumValues[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sumValues[i] = sumValues[i-1] + nums[i];
    }

    int sumRange(int i, int j)
    {
        if (nullArray == true)
            return 0;
        if (i == 0 && j == sumValues.size() - 1)
            return sumValues[j];
        if (i == 0)
            return sumValues[j];
        else
            return sumValues[j] - sumValues[i-1];
    }
};
