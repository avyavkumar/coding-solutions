#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;
        std::vector<int> minValues;
        minValues.resize(prices.size());
        int minValue = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minValue)
                minValue = prices[i];
            minValues[i] = minValue;
        }
        std::vector<int> finalResult;
        finalResult.resize(prices.size());
        finalResult[0] = 0;
        for (int i = 1; i < finalResult.size(); i++)
            finalResult[i] = max(finalResult[i-1], prices[i]-minValues[i]);
        return finalResult[finalResult.size()-1];
    }
};
