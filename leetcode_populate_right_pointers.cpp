#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (root == NULL)
            return;

        queue <TreeLinkNode*> listNodes;
        listNodes.push(root);
        root->next = NULL;
        while (listNodes.size() > 0)
        {
            int sizeQueue = listNodes.size();
            for (int i = 0; i < sizeQueue; i++)
            {
                TreeLinkNode *tempNode = listNodes.front();
                listNodes.pop();
                if (tempNode->left)
                    listNodes.push(tempNode->left);
                if (tempNode->right)
                    listNodes.push(tempNode->right);
            }
            if (listNodes.size() > 0)
            {
                queue<TreeLinkNode*> tempList(listNodes);
                TreeLinkNode *leftNode = tempList.front(); tempList.pop();
                sizeQueue = tempList.size();
                for (int i = 0; i < sizeQueue; i++)
                {
                    TreeLinkNode *tempNode = tempList.front();
                    tempList.pop();
                    leftNode->next = tempNode;
                    leftNode = tempNode;
                }
                leftNode->next = NULL;
            }
        }
    }
};
