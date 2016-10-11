#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<long long int >> graph;
std::vector<int> visited;

class Solution
{
public:
    void DFS(long long int s, long long int counted)
    {
      stack<long long int> c_stack;

      visited[s] = counted;
      c_stack.push(s);

      while (!c_stack.empty())
      {
          long long int temp = c_stack.top();
          c_stack.pop();

          for (long long int i = 0; i < graph[temp].size(); ++i)
          {
              if (visited[graph[temp][i]] == -1)
              {
                  visited[graph[temp][i]] = counted;
                  c_stack.push(graph[temp][i]);
              }
          }
      }
    }

    int numIslands(vector<vector<char>>& grid)
    {
      if (grid.size() == 0)
        return 0;

      int height = grid.size();
      int width = grid[0].size();

      graph.resize(height*width);
      for (int i = 0; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[i].size(); j++)
        {
          if (grid[i][j] == '1')
          {
            if (i-1 >= 0)
              if (grid[i-1][j] == '1')
                graph[width*i + j].push_back((i-1)*width + j);

            if (i+1 < height)
              if (grid[i+1][j] == '1')
                graph[width*i + j].push_back((i+1)*width + j);

            if (j-1 >= 0)
              if (grid[i][j-1] == '1')
                graph[width*i + j].push_back(i*width + (j-1));

            if (j+1 < width)
              if (grid[i][j+1] == '1')
                graph[width*i + j].push_back(i*width + (j+1));
          }
        }
      }

      visited.resize(graph.size(), -1);

      long long int counted = 0;

      for (long long int i = 0; i < graph.size(); i++)
      {
        if (graph[i].size() > 0)
        {
          if (visited[i] == -1)
          {
            DFS(i, counted);
            counted++;
          }
        }
        else if (graph[i].size() == 0 && grid[i/width][i%width] == '1')
          counted++;
      }

      visited.clear();
      graph.clear();
      return counted;
    }
};
