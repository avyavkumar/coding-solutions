#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        std::vector<long long int> finalResult;
        finalResult.resize(triangle[triangle.size()-1].size(),0);

        for (int i = 0; i < finalResult.size(); i++)
            finalResult[i] = triangle[triangle.size()-1][i];

        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i+1].size() - 1; j++)
                finalResult[j] = triangle[i][j] + min(finalResult[j],finalResult[j+1]);

        return finalResult[0];
    }
};
