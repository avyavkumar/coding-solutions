#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int rob (TreeNode* root)
    {
      if (root != NULL)
      {
        if (root->left == NULL && root->right == NULL)
        {
          return root->val;
        }
        else
        {
          if (root->left != NULL)
          {
            if (root->right != NULL)
            {
              return max(root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right),
                         rob(root->left) + rob(root->right));
            }
            else
            return max(root->val + rob(root->left->left) + rob(root->left->right),
                       rob(root->left));
          }
          else
          {
            return max(root->val + rob(root->right->left) + rob(root->right->right),
                       rob(root->right));
          }
        }
      }
      else
        return 0;
    }
};
