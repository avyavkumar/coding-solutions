#include <bits/stdc++.h>

using namespace std;

class Solution
{
public :
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        std::vector<int> result;
        if(nums.empty())
            return result;

        sort(nums.begin(), nums.end());

        int t[nums.size()];
        int index[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            t[i] = 1;
            index[i] = -1;
        }

        int max=0;
        int maxIndex=-1;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]%nums[j]==0 && t[j]+1>t[i])
                {
                    t[i]=t[j]+1;
                    index[i]=j;
                }
            }

            if(max<t[i])
            {
                max=t[i];
                maxIndex=i;
            }
        }

        int i=maxIndex;
        while(i>=0)
        {
            result.push_back(nums[i]);
            i=index[i];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
