#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    set<ListNode*> hashSet;
    bool hasCycle(ListNode *head)
    {
        hashSet.clear();
        if (head == NULL)
            return false;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (hashSet.find(temp) == hashSet.end())
            {
                hashSet.insert(temp);
                temp = temp->next;
            }
            else
                return true;
        }
        return false;
    }
};
