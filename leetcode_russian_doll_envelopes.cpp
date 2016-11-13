#include <bits/stdc++.h>

using namespace std;

bool sortingFunc(pair <int, int> p1, pair <int,int> p2)
{
    if (p1.first < p2.first)
        return true;
    return false;
}

class Solution
{
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes)
    {
        if (envelopes.size() <= 1)
            return envelopes.size();

        std::vector<int> dp(envelopes.size(),1);

        sort(envelopes.begin(), envelopes.end(), sortingFunc);

        int maxValue = 0;

        for (int i = 1; i < envelopes.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[j].first < envelopes[i].first &&
                    envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            maxValue = max(dp[i], maxValue);
        }

        return maxValue;
    }
};
