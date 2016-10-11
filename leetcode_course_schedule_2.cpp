#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int> > graph;
std::vector<int> visited;
std::vector<int> topSort;
bool noCycle = true;
std::vector<bool> onCall;

class Solution
{
public:

    void DFS(long long int x)
    {
        if (visited[x] == -1)
        {
            onCall[x] = true;
            visited[x] = 1;
            for (long long int i = 0; i < graph[x].size(); i++)
                DFS(graph[x][i]);
            topSort.push_back(x);
        }
        else
            if (onCall[x] == true)
                noCycle = false;
        onCall[x] = false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        noCycle = true;
        graph.clear(); visited.clear(); topSort.clear();
        graph.resize(numCourses); visited.resize(numCourses, -1);
        onCall.clear(); onCall.resize(numCourses, false);
        for (long long int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        for (long long int i = 0; i < graph.size(); i++)
        {
            if(visited[i] == -1)
                DFS(i);
        }
        if (noCycle == false)
            topSort.clear();
        return topSort;
    }
};
