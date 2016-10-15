#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void generateTreesHelper(int m, int n, std::vector<TreeNode*> &finalResult)
    {
        if (m > n)
            finalResult.push_back(NULL);
        else
        {
            for (int i = m; i <= n; i++)
            {
                std::vector<TreeNode*> leftChildren;
                generateTreesHelper(m,i-1, leftChildren);
                std::vector<TreeNode*> rightChildren;
                generateTreesHelper(i+1,n, rightChildren);
                for (int x = 0; x < leftChildren.size(); x++)
                {
                    for (int y = 0; y < rightChildren.size(); y++)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftChildren[x];
                        root->right = rightChildren[y];
                        finalResult.push_back(root);
                    }
                }
            }
        }
    }

    vector<TreeNode*> generateTrees(int n)
    {
        std::vector<TreeNode*> finalResult;
        if (n == 0)
            return finalResult;
        else
            generateTreesHelper(1,n, finalResult);
        return finalResult;
    }
};
