#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preorderStart, int preorderEnd,
                              vector<int>& inorder, int inorderStart, int inorderEnd)
    {
        if (preorderStart > preorderEnd || inorderStart > inorderEnd)
            return NULL;

        int rootElement = preorder[preorderStart];
        int rootIndex = distance(inorder.begin(), find(inorder.begin()+inorderStart, inorder.begin()+inorderEnd, rootElement));

        TreeNode *temp = new TreeNode(rootElement);

        temp->left = buildTreeHelper(preorder, preorderStart+1, preorderStart+(rootIndex-inorderStart),
                                     inorder, inorderStart, rootIndex-1);

        temp->right = buildTreeHelper(preorder, preorderStart+(rootIndex-inorderStart)+1, preorderEnd,
                                     inorder, rootIndex+1, inorderEnd);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
