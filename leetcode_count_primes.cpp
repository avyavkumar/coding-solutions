#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        bool sieve[n];
        sieve[0] = false;
        sieve[1] = false;
        for (int i = 2; i < n; i++)
            sieve[i] = true;

        for (int i = 2; i <= sqrt(n-1); i++)
        {
            if (sieve[i])
            {
                for (int j = i + i; j < n; j+=i)
                    sieve[j] = false;
            }

        }
        int finalResult = 0;

        for (int i = 2; i < n; i++)
            if (sieve[i] == true)
                finalResult++;
        return finalResult;
    }
};
