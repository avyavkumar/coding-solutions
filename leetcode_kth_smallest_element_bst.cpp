#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    void inOrderTraversal(TreeNode *root, std::vector<int> &traversal)
    {
        if (root == NULL)
            return;
        inOrderTraversal(root->left, traversal);
        traversal.push_back(root->val);
        inOrderTraversal(root->right, traversal);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        std::vector<int> traversal;
        inOrderTraversal(root, traversal);
        return traversal[k-1];
    }
};
