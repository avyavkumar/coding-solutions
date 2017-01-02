#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode *leftAncestor = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAncestor = lowestCommonAncestor(root->right, p, q);

        if (leftAncestor != NULL && rightAncestor != NULL)
            return root;
        else if (leftAncestor == NULL && rightAncestor == NULL)
            return NULL;
        else
            return leftAncestor == NULL? rightAncestor : leftAncestor;
    }
};
