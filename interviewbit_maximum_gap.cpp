#include <bits/stdc++.h>

using namespace std;

int Solution::maximumGap(const vector<int> &A)
{
    // trivial solution
    if (A.size() < 2)
        return 0;
    std::vector<int> tempResult(A);
    std::sort(tempResult.begin(), tempResult.end());
    int maxInterval = tempResult[1] - tempResult[0];
    for (int i = 2; i < A.size(); i++)
    {
        if (tempResult[i]-tempResult[i-1] > maxInterval)
            maxInterval = tempResult[i]-tempResult[i-1];
    }
    return maxInterval;
}
