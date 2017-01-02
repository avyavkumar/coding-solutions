#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (head == NULL)
            return NULL;

        ListNode *temp = head;
        std::vector<int> lesserVal, greaterVal;
        while (temp != NULL)
        {
            if (temp->val < x)
                lesserVal.push_back(temp->val);
            else
                greaterVal.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (lesserVal.size() > 0 && temp != NULL)
        {
            temp->val = lesserVal[0];
            lesserVal.erase(lesserVal.begin());
            temp = temp->next;
        }
        while (greaterVal.size() > 0 && temp != NULL)
        {
            temp->val = greaterVal[0];
            greaterVal.erase(greaterVal.begin());
            temp = temp->next;
        }
        temp = head;

        return temp;
    }
};
