#include <bits/stdc++.h>

using namespace std;

bool comparingFunc(int a, int b)
{
    if ((to_string(a)+to_string(b)).compare(to_string(b) + to_string(a)) > 0)
        return true;
    return false;
}

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        if (nums.size() == 0)
            return "";

        int zeroCount = 0;
        sort(nums.begin(), nums.end(), comparingFunc);
        string finalResult = "";
        for (int i : nums)
        {
            if (i == 0)
                zeroCount++;
            finalResult += to_string(i);
        }

        if (zeroCount == nums.size())
            return "0";

        return finalResult;
    }
};
