#include <bits/stdc++.h>

using namespace std;

int Solution::maximumGap(const vector<int> &A)
{
    if (A.size() <= 1)
        return 0;
        
    std::vector<int> lowerElements(A.size());
    std::vector<int> greaterElements(A.size());

    lowerElements[0] = A[0];
    for (int i = 1; i < A.size(); i++)
        lowerElements[i] = min(lowerElements[i-1], A[i]);

    greaterElements[A.size()-1] = A[A.size()-1];
    for (int i = A.size()-2; i >= 0; i--)
        greaterElements[i] = max(greaterElements[i+1],A[i]);

    int i = 0, j = 0, finalResult = INT_MIN;

    while (i < A.size() && j < A.size())
    {
        if (greaterElements[j] >= lowerElements[i])
        {
            finalResult = max(finalResult,j-i);
            j++;
        }
        else
            i++;
    }

    return finalResult;
}
