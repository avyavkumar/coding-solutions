#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    TreeNode *previousNode;

    void flatten(TreeNode* root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);
        root->right = previousNode;
        root->left = NULL;
        previousNode = root;
    }
};
