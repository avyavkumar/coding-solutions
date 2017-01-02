#include <bits/stdc++.h>

using namespace std;

ListNode* Solution::reorderList(ListNode* A)
{
    vector <int> tempStackForward;
    ListNode *temp = A;
    int sizeList = 0;
    while (temp != NULL)
    {
        tempStackForward.push_back(temp->val);
        temp = temp->next;
        sizeList++;
    }
    temp = A;
    std::vector<int> tempStackBackward(tempStackForward);
    reverse(tempStackBackward.begin(),tempStackBackward.end());
    int forw = 0; int back = 0;
    temp = A;
    for (int i = 0; i < sizeList; i++)
    {
        if (i % 2 == 0)
        {
            temp->val = tempStackForward[forw];
            temp = temp->next;
            forw++;
        }
        else
        {
            temp->val = tempStackBackward[back];
            temp = temp->next;
            back++;
        }
    }
    temp  = A;
    tempStackBackward.clear();
    tempStackForward.clear();
    return temp;
}
