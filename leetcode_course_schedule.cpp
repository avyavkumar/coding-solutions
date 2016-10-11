#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int> > graph;
std::vector<int> visited;
bool finalResult = true;
std::vector<bool> onCall;

class Solution
{
public:

    void DFS(int x)
    {
        if (visited[x] == -1)
        {
            onCall[x] = true;
            visited[x] = 1;
            for (long long int i = 0; i < graph[x].size(); i++)
                DFS(graph[x][i]);
        }
        else
            if (onCall[x] == true)
                finalResult = false;
        onCall[x] = false;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        finalResult = true;
        graph.clear(); visited.clear(); onCall.clear();
        graph.resize(numCourses); visited.resize(numCourses, -1);
        onCall.resize(numCourses, false);
        for (long long int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        for (long long int i = 0; i < graph.size(); i++)
        {
            if(visited[i] == -1)
                DFS(i);
        }
        return finalResult;
    }
};
