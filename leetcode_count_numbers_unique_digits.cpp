#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        std::vector<int> res(n + 1,0);
        res[0] = 1;
        int sum = 1;
        int k = 9;
        for(int i = 1; i <= n && k > 0; i++)
        {
              if(i == 1) res[i] += res[i - 1] * 9;
              else res[i] += res[i - 1] * k--;
              sum += res[i];
        }
        return sum;
    }
};
