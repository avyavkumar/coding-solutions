#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if (nums.size() == 0 || k > nums.size() || k < 1)
            return -1;

        std::priority_queue<int, std::vector<int>, greater<int>> priorityQueue(nums.begin(), nums.end());

        while (priorityQueue.size() > k)
            priorityQueue.pop();

        return priorityQueue.top();
    }
};
