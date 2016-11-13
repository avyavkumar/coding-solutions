#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.length() == 0 || word2.length() == 0)
        {
            if (word1.length() == 0)
                return word2.length();
            else if (word2.length() == 0)
                return word1.length();
        }
        int dp[word1.length()+1][word2.length()+1];

        for (int i = 0; i < word1.length()+1; i++)
            for (int j = 0; j < word2.length()+1; j++)
                dp[i][j] = 0;

        for (int i = 0; i < word1.length()+1; i++)
            dp[i][0] = i;
        for (int j = 0; j < word2.length()+1; j++)
            dp[0][j] = j;

        for (int i = 0; i < word1.length(); i++)
        {
            for (int j = 0; j < word2.length(); j++)
            {
                if (word1[i] == word2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = 1 + min(dp[i][j], min(dp[i][j+1], dp[i+1][j]));
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
