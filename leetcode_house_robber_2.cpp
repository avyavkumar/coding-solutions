#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];

        std::vector<int> dp1(nums.size()-1,0);
        std::vector<int> dp2(nums.size()-1,0);

        std::vector<int> nums1(nums);
        std::vector<int> nums2(nums);
        nums1.erase(nums1.end()-1);
        nums2.erase(nums2.begin());

        dp1[0] = nums1[0]; dp1[1] = max(nums1[1],dp1[0]);
        dp2[0] = nums2[0]; dp2[1] = max(nums2[1],dp2[0]);

        for (int i = 2; i < nums1.size(); i++)
            dp1[i] = max(nums1[i] + dp1[i-2], dp1[i-1]);

        for (int i = 2; i < nums2.size(); i++)
            dp2[i] = max(nums2[i] + dp2[i-2], dp2[i-1]);

        return max(dp1[dp1.size()-1], dp2[dp2.size()-1]);
    }
};
