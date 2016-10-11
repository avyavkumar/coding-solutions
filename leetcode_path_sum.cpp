#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    bool hasPathSum(TreeNode* root, int sum)
    {
      if (root != NULL)
      {
        if (root->left == NULL && root->right == NULL && (sum - root->val == 0))
          return true;
        else if (root->left)
        {
          if (root->right)
          {
            bool leftSide = hasPathSum(root->left, sum - root->val);
            if (leftSide == true)
              return true;
            else
              return hasPathSum(root->right, sum - root->val);
          }
          else
            return hasPathSum(root->left, sum - root->val);
        }
        else
          return hasPathSum(root->right, sum - root->val);
      }
      else
        return false;
    }
};
