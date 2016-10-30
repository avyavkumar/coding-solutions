#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;

        std::vector<int> finalResult;
        finalResult.push_back(1);

        int i = 0, j = 0, k = 0;

        while(finalResult.size() < n+1)
        {
            int twoResult = finalResult[i]*2;
            int threeResult = finalResult[j]*3;
            int fiveResult = finalResult[k]*5;

            int minElement = min(twoResult, min(threeResult, fiveResult));
            finalResult.push_back(minElement);

            if (minElement == twoResult) i++;
            if (minElement == threeResult) j++;
            if (minElement == fiveResult) k++;
        }

        return finalResult[n-1];
    }
};
