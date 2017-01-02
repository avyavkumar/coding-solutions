#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> finalResult;

        if (root == NULL)
            return finalResult;
            
        std::queue<TreeNode*> levelNodes;
        levelNodes.push(root);

        while (levelNodes.size() > 0)
        {
            int sizeQueue = levelNodes.size();

            for (int i = 0; i < sizeQueue; i++)
            {
                TreeNode *temp = levelNodes.front();
                levelNodes.pop();

                if (i == 0)
                    finalResult.push_back(temp->val);

                if (temp->right != NULL)
                    levelNodes.push(temp->right);

                if (temp->left != NULL)
                    levelNodes.push(temp->left);
            }
        }

        return finalResult;
    }
};
