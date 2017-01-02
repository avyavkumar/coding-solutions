#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    bool isSymmetricHelper(TreeNode* left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
            return left == right;

        if (left->val != right->val)
            return false;

        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(right->left, left->right);
    }

    bool isSymmetric(TreeNode* root)
    {
        return root == NULL || isSymmetricHelper(root->left, root->right);
    }
};
