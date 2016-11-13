#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> finalResult;
        if (nums.size() < 3)
            return finalResult;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++)
        {
            if (i==0 || nums[i] > nums[i-1])
            {
                int j=i+1;
                int k=nums.size()-1;

                while (j<k)
                {
                    if (nums[i]+nums[j]+nums[k]==0)
                    {
                        std::vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        finalResult.push_back(temp);

                        j++;
                        k--;

                        while (j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1])  k--;
                    }
                    else if (nums[i]+nums[j]+nums[k]<0) j++;
                    else k--;
                }
            }
        }

        return finalResult;
    }
};
