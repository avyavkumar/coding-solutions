#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        std::vector<long long int> amounts;
        amounts.resize(amount+1, std::numeric_limits<int>::max());
        amounts[0] = 0;
        for (long long int i = 0; i < coins.size(); i++)
            if (coins[i] < amounts.size())
                amounts[coins[i]] = 1;
        for (long long int i = 1; i < amounts.size(); i++)
        {
            for (long long int j = 0; j < coins.size(); j++)
            {
                if (coins[j] < i)
                {
                    long long int temp = 1 + amounts[i-coins[j]];
                    if (temp < amounts[i])
                        amounts[i] = temp;
                }
            }
        }
        if (amounts[amounts.size()-1] == std::numeric_limits<int>::max())
            return -1;
        return amounts[amounts.size()-1];
    }
};
