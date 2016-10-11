#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        std::vector<std::vector<int>> pathCount;
        pathCount.resize(obstacleGrid.size());
        for (int i = 0; i < obstacleGrid.size(); i++)
            pathCount[i].resize(obstacleGrid[i].size(),0);
        bool isZero = false;
        for (int i = 0; i < obstacleGrid.size() && isZero == false; i++)
        {
            if (obstacleGrid[i][0] == 1)
                isZero = true;
            if (obstacleGrid[i][0] == 0)
                pathCount[i][0] = 1;
        }
        isZero = false;
        for (int i = 0; i < obstacleGrid[0].size() && isZero == false; i++)
        {
            if (obstacleGrid[0][i] == 1)
                isZero = true;
            if (obstacleGrid[0][i] == 0)
                pathCount[0][i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid[i].size(); j++)
            {
                if (obstacleGrid[i][j] == 0)
                    pathCount[i][j] = pathCount[i-1][j] + pathCount[i][j-1];
                else
                    pathCount[i][j] = 0;
            }
        }
        return pathCount[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
