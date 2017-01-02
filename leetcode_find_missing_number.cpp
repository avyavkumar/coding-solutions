#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    int findDuplicate(vector<int>& nums)
    {
        int l = 0, r = nums.size()-1;
        while (l < r)
        {
            int mid = (l+r)/2;
            int count = 0;

            for (int i = 0; i < nums.size(); i++)
                if (nums[i] <= mid)
                    count++;

            if (count > mid)
                r = mid;
            else
                l = mid+1;
        }
        return r;
    }
};
