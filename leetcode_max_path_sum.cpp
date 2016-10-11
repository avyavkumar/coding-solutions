#include <bits/stdc++.h>

using namespace std;

long long int maxResult;

class Solution
{
public:
    long long int maxPathSumHelper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long int zero = 0;
        long long int leftSum = max(zero,maxPathSumHelper(root->left));
        long long int rightSum = max(zero,maxPathSumHelper(root->right));

        maxResult = max(maxResult, leftSum + rightSum + root->val);

        return max(leftSum, rightSum) + root->val;
    }

    long long int maxPathSum(TreeNode* root)
    {
        maxResult = numeric_limits<long long int>::min();
        long long int sum = maxPathSumHelper(root);
        return maxResult;
    }
};
