#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        std::vector<int> finalResult;
        finalResult.resize(num+1,0);
        finalResult[1] = 1;
        int power = 2;
        for (int i = 2; i < num+1; i++)
        {
            if (i == power)
            {
                power+=power;
                finalResult[i] = 1;
            }
            else
                finalResult[i] = 1 + finalResult[i-power/2];
        }
        return finalResult;
    }
};
