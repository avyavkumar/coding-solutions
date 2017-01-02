#include <bits/stdc++.h>

using namespace std;

std::vector<bool> visitedNodes;

void DFS(std::vector<std::vector<pair<int,int>>> graph, int source, stack<int> &topSort)
{
    if (visitedNodes[source] == false)
    {
        visitedNodes[source] = true;
        for (int i = 0; i < graph[source].size(); i++)
        {
            if (visitedNodes[graph[source][i].first] == false)
                DFS(graph, graph[source][i].first, topSort);
        }
        topSort.push(source);
    }
}

void topologicalSort(std::vector<std::vector<pair<int,int>>> graph, stack<int> &topSort)
{
    visitedNodes.clear();
    visitedNodes.resize(graph.size(),false);

    for (int i = 0; i < graph.size(); i++)
        if (visitedNodes[i] == false)
            DFS(graph,i,topSort);
}

std::vector<int> getLongestPath(std::vector<std::vector<pair<int,int>>> graph, int source)
{
    std::stack<int> topSort;
    topologicalSort(graph, topSort);
    std::vector<int> maximumDistance(graph.size(),INT_MIN);
    maximumDistance[source] = 0;
    while (topSort.size() > 0)
    {
        int currentSource = topSort.top(); topSort.pop();
        if (maximumDistance[currentSource] != INT_MIN)
        {
            for (int i = 0; i < graph[currentSource].size(); i++)
            {
                if (maximumDistance[graph[currentSource][i].first] < maximumDistance[currentSource] + graph[currentSource][i].second)
                    maximumDistance[graph[currentSource][i].first] = maximumDistance[currentSource] + graph[currentSource][i].second;
            }
        }
    }

    return maximumDistance;
}
