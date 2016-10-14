#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        long long int catalanNumbers[n+1];
        for (int i = 0; i < n+1; i++)
            catalanNumbers[i] = 0;
        catalanNumbers[0] = 1;
        catalanNumbers[1] = 1;
        catalanNumbers[2] = 2;
        for (int i = 3; i < n+1; i++)
        {
            for (int j = 0; j < i; j++)
                catalanNumbers[i] += catalanNumbers[j]*catalanNumbers[i-1-j];
        }
        return catalanNumbers[n];
    }
};
