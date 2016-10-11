#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    int climbStairs(int n)
    {
        std::vector<long long int> ways;
        ways.resize(n > 5? n+1 : 10, 0);
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;
        ways[3] = 3;
        ways[4] = 5;
        for (int i = 5; i < n+1; i++)
            ways[i] = ways[i-1] + ways[i-2];
        return ways[n];
    }
};
