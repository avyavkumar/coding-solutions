#include <bits/stdc++.h>

using namespace std;

ListNode *root;

class Solution
{
public:

    long long int getLength(ListNode *head)
    {
      ListNode *temp = head;
      long long int length = 0;
      while (head != NULL)
      {
        length++;
        head = head->next;
      }
      return length;
    }

    TreeNode* sortedListToBST(long long int low, long long int high)
    {
      if (high < low)
        return NULL;

      long long int mid = (low + high)/2;

      TreeNode *leftChild = sortedListToBST(low, mid - 1);
      TreeNode *parent = new TreeNode(root->val);
      if (root->next != NULL)
        root = root->next;
      TreeNode *rightChild = sortedListToBST(mid + 1, high);


      parent->left = leftChild;
      parent->right = rightChild;

      return parent;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
      if (head == NULL)
        return NULL;
      else
      {
        long long int length = getLength(head);
        root = head;
        return sortedListToBST(0, length-1);
      }
    }
};
