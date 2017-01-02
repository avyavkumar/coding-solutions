#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return NULL;

        int index = start + (end-start)/2;
        TreeNode *root = new TreeNode(nums[index]);
        root->left = sortedArrayToBSTHelper(nums,start,index-1);
        root->right = sortedArrayToBSTHelper(nums, index+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }
};
