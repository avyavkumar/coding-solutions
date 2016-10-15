#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 0)
            return 0;
        std::vector<long long int> finalResult;
        finalResult.resize(n+1,0);
        finalResult[1] = 1;
        for (long long int i = 2; i < n+1; i++)
        {
            for (long long int j = 1; j <= i/2; j++)
            {
                long long int temp = max(finalResult[i-j],i-j)*max(finalResult[j],j);
                if (temp > finalResult[i])
                    finalResult[i] = temp;
            }
        }
        return finalResult[finalResult.size()-1];
    }
};
