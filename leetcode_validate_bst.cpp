#include <bits/stdc++.h>

using namespace std;

long long int minValue = numeric_limits<long long int>::min();
int flag = 0;

class Solution
{
public:

  void isValidBSTHelper(TreeNode* root)
  {
    if (root != NULL)
    {
      if (root->left)
        isValidBSTHelper(root->left);

      if (root->val > minValue)
        minValue = root->val;
      else
        flag = -1;

      if (root->right)
        isValidBSTHelper(root->right);
    }
  }

  bool isValidBST(TreeNode *root)
  {
    if (root == NULL)
      return true;

    isValidBSTHelper(root);

    if (flag == 0)
    {
      minValue = numeric_limits<long long int>::min();
      return true;
    }
    else
    {
      flag = 0;
      minValue = numeric_limits<long long int>::min();
      return false;
    }
  }
};
