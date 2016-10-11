#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> pathCount;
        pathCount.resize(m);
        for (int i = 0; i < m; i++)
            pathCount[i].resize(n,0);
        for (int i = 0; i < m; i++)
            pathCount[i][0] = 1;
        for (int i = 0; i < n; i++)
            pathCount[0][i] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                pathCount[i][j] = pathCount[i-1][j] + pathCount[i][j-1];
        }
        return pathCount[m-1][n-1];
    }
};
