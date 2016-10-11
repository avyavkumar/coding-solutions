#include <bits/stdc++.h>

using namespace std;

std::vector<TreeNode *> tree;
std::vector<TreeNode *> sortedTree;

bool sortingFunction(TreeNode *a, TreeNode *b)
{
    return (a->val < b->val) ? true : false;
}

class Solution
{
public:

    void getTree(TreeNode *root)
    {
        if (root)
        {
            if(root->left)
                getTree(root->left);
            tree.push_back(root);
            if (root->right)
                getTree(root->right);
        }
    }

    void sortTree()
    {
        for(long long int i = 0; i < tree.size(); i++)
            sortedTree.push_back(tree[i]);
        long long int leftValue = -1, rightValue = -1;
        sort(sortedTree.begin(), sortedTree.end(), sortingFunction);
        for (long long int i = 0; i < sortedTree.size(); i++)
        {
            if (sortedTree[i]->val != tree[i]->val)
            {
                if (leftValue == -1)
                    leftValue = i;
                else
                    rightValue = i;
            }
        }
        int temp = tree[leftValue]->val;
        tree[leftValue]->val = tree[rightValue]->val;
        tree[rightValue]->val = temp;
    }

    void recoverTree(TreeNode* root)
    {
        tree.clear();
        sortedTree.clear();
        getTree(root);
        if (root != NULL)
            sortTree();
    }
};
