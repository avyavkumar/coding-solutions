#include <bits/stdc++.h>

using namespace std;

struct heightNode
{
    int value; int distFromRoot;
    heightNode *left; heightNode *right;
    heightNode(int v) : value(v), distFromRoot(0) {}
};

std::vector<int> fetchVerticalOrder(heightNode *root)
{
    std::queue<heightNode*> nodeList;
    std::vector<int> finalResult;
    nodeList.push(root);
    int maxLeft = 0, maxRight = 0;
    finalResult.push_back(root->value);
    root->distFromRoot = 0;
    while (!nodeList.empty())
    {
        heightNode *temp = nodeList.front(); nodeList.pop();
        int currDistance = temp->distFromRoot;
        if (temp->left)
        {
            temp->left->distFromRoot = temp->distFromRoot-1;
            nodeList.push(temp->left);
        }
        if (temp->right)
        {
            temp->right->distFromRoot = temp->distFromRoot+1;
            nodeList.push(temp->right);
        }
        if (currDistance < maxLeft)
        {
            finalResult.push_back(temp->value);
            maxLeft = currDistance;
        }
        if (currDistance > maxRight)
        {
            finalResult.push_back(temp->value);
            maxRight = currDistance;
        }
    }
    return finalResult;
}
