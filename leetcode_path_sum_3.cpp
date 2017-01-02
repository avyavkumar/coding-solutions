#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    int pathSumHelper(TreeNode *root, int sum)
    {
        if (root != NULL)
        {
            int tempResult = 0;
            if (sum - root->val == 0)
                tempResult++;
            tempResult += pathSumHelper(root->left, sum-root->val);
            tempResult += pathSumHelper(root->right, sum-root->val);
            return tempResult;
        }
        else
            return 0;
    }

    int pathSum(TreeNode* root, int sum)
    {
        if (root == NULL)
            return 0;
        return pathSumHelper(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
};
