#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inorderStart, int inorderEnd, vector<int>& postorder,
                        int postorderStart, int postorderEnd)
    {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd)
            return NULL;

        int rootElement = postorder[postorderEnd];
        TreeNode *temp = new TreeNode(rootElement);
        int rootIndex = distance(inorder.begin(), find(inorder.begin()+inorderStart, inorder.begin()+inorderEnd, rootElement));
        temp->left = buildTreeHelper(inorder, inorderStart, rootIndex-1, postorder, postorderStart, postorderStart + rootIndex - inorderStart-1);
        temp->right = buildTreeHelper(inorder, rootIndex+1, inorderEnd, postorder, postorderStart + rootIndex - inorderStart, postorderEnd-1);

        return temp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
