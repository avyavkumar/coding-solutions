#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.empty())
            return 0;
            
        std::vector<std::vector<int>> minSum;
        minSum.resize(grid.size());
        for (int i = 0; i < grid.size(); i++)
            minSum[i].resize(grid[i].size());
        minSum[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
            minSum[i][0] = minSum[i-1][0] + grid[i][0];
        for (int i = 1; i < grid[0].size(); i++)
            minSum[0][i] = minSum[0][i-1] + grid[0][i];
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid[i].size(); j++)
                minSum[i][j] = grid[i][j] + min(minSum[i-1][j], minSum[i][j-1]);

        return minSum[grid.size()-1][grid[0].size()-1];
    }
};
