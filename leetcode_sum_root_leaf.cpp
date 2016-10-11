#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:

    long long int sumNumbers(TreeNode *root)
    {
      if (root == NULL)
        return 0;
      else
        return sumNumbersHelper(root);
    }

    long long int sumNumbersHelper(TreeNode* root)
    {
      if (root != NULL)
      {
        if (root->left == NULL && root->right == NULL)
          return root->val;

        else
        {
          long long int _left = sumNumbersHelper(root->left);
          long long int _right = sumNumbersHelper(root->right);

          long long int left_num = 0, right_num = 0;

          int order = 0;
          long long int temp = _left;
          if (temp == 0)
            order = 1;
          while(temp > 0)
          {
            order++;
            temp/=10;
          }
          long long int final_val = root->val;
          for (int i = 0; i < order; i++)
            final_val*=10;
          if (_left != -1)
            left_num = final_val + _left;

          order = 0;
          temp = _right;
          if (temp == 0)
            order = 1;
          while(temp > 0)
          {
            order++;
            temp/=10;
          }
          final_val = root->val;
          for (int i = 0; i < order; i++)
            final_val*=10;
          if (_right != -1)
            right_num = final_val + _right;

          return left_num + right_num;
        }
      }
      else
        return -1;
    }
};

// int main()
// {
//   std::cout << stoi("") << std::endl;
//   return 0;
// }
