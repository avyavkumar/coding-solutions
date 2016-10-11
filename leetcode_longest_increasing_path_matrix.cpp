#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int> > graph;

class Solution
{
public:

    int pathHelper(vector<vector<int>>& matrix, int i, int j)
    {
        long long int left = 1, right = 1, top = 1, bottom = 1;
        if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j])
        {
            if (graph[i-1][j] != -1)
                top = graph[i-1][j] + 1;
            else
                top = pathHelper(matrix, i-1, j) + 1;
        }
        if (i+1 < matrix.size() && matrix[i+1][j] > matrix[i][j])
        {
            if (graph[i+1][j] != -1)
                bottom = graph[i+1][j] + 1;
            else
                bottom = pathHelper(matrix, i+1, j) + 1;
        }
        if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j])
        {
            if (graph[i][j-1] != -1)
                left = graph[i][j-1] + 1;
            else
                left = pathHelper(matrix, i, j-1) + 1;
        }
        if (j+1 < matrix[i].size() && matrix[i][j+1] > matrix[i][j])
        {
            if (graph[i][j+1] != -1)
                right = graph[i][j+1] + 1;
            else
                right = pathHelper(matrix, i, j+1) + 1;
        }
        graph[i][j] = max(max(left, right), max(top,bottom));
        return max(max(left, right), max(top,bottom));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < graph.size(); i++)
            graph[i].clear();
        graph.clear();
        graph.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            graph[i].resize(matrix[i].size(), -1);
        for(long long int i = 0; i < graph.size(); i++)
        {
            for (long long int j = 0; j < graph[i].size(); j++)
            {
                if (graph[i][j] == -1)
                    pathHelper(matrix,i,j);
            }
        }
        if(matrix.size() > 0)
        {
            int max = 0;
            for(long long int i = 0; i < graph.size(); i++)
            {
                for (long long int j = 0; j < graph[i].size(); j++)
                    if (graph[i][j] > max)
                        max = graph[i][j];
            }
            return max;
        }
        else
            return 0;
    }
};
