#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int>> graph;
std::vector<int> nodeList;
std::vector<int> topSort;
std::vector<int> visited;
int counted = 0;

void DFS(std::vector<std::vector<int>> graph, int i, int op)
{
    if (visited[i] == -1)
    {
        visited[i] = 1;
        for (int j = 0; j < graph[i].size(); j++)
            DFS(graph, graph[i][j], op);
        if (op == 0)
            topSort.push_back(i);
        else
            nodeList[i] = counted;
    }
}

void stronglyConnectedComponents()
{
    std::vector<std::vector<int>> reverseGraph;
    reverseGraph.resize(graph.size());
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            reverseGraph[graph[i][j]].push_back(i);
    nodeList.resize(reverseGraph.size());
    visited.resize(reverseGraph.size(), -1);
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == -1)
            DFS(reverseGraph, i, 0);
    }
    visited.clear();
    visited.resize(graph.size(), -1);
    reverse(topSort.begin(), topSort.end());
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[topSort[i]] == -1)
            DFS(graph, topSort[i], 1);
        counted++;
    }
}
