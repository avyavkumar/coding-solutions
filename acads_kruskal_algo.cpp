#include <bits/stdc++.h>

using namespace std;

std::vector<pair<pair<int, int>, int>> edgeList;
std::vector<int> visited;
bool cyclePresent = false;
std::vector<bool> onCall;

bool contains(int i, int j)
{
    auto it = find_if(edgeList.begin(), edgeList.end(),
                   [&i, &j](const pair<pair<int, int>, int> &element){ if (i == element.first.first && j == element.first.second) return true;
                                                                       if (i == element.first.second && j == element.first.first) return true;
                                                                       return false;} );
    if (it == edgeList.end())
        return false;
    else
        return true;
}

bool sortingFunc(pair<pair<int, int>, int> &element1, pair<pair<int, int>, int> &element2)
{
    if (element2.second > element1.second)
        return true;
    else
        return false;
}

void DFS(std::vector<std::vector<pair<int, int>>> graph, int x)
{
    if (visited[x] == -1)
    {
        onCall[x] = true;
        visited[x] = 1;
        for (long long int i = 0; i < graph[x].size(); i++)
            DFS(graph, graph[x][i].first);
    }
    else
        if (onCall[x] == true)
            cyclePresent = true;
    onCall[x] = false;
}

bool checkCycles(std::vector<std::vector<pair<int, int>>> graph)
{
    visited.clear();
    visited.resize(graph.size(), -1);
    onCall.clear();
    onCall.resize(graph.size(), false);
    cyclePresent = false;
    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == -1)
            DFS(graph, i);
    }
    return cyclePresent;
}

std::vector<std::vector<pair<int, int>>> Kruskal(std::vector<std::vector<pair<int, int>>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!contains(i,j))
                edgeList.push_back(make_pair(make_pair(i,graph[i][j].first),graph[i][j].second));
        }
    }
    sort(edgeList.begin(), edgeList.end(), sortingFunc);
    int edgeListIndex = 0;
    std::vector<std::vector<pair<int, int>>> finalResult; finalResult.resize(graph.size());
    std::vector<std::vector<pair<int, int>>> tempResult; tempResult.resize(graph.size());
    while (edgeListIndex < edgeList.size())
    {
        tempResult[edgeList[edgeListIndex].first.first].push_back(make_pair(edgeList[edgeListIndex].first.second, edgeList[edgeListIndex].second));
        if (!checkCycles(tempResult))
            finalResult[edgeList[edgeListIndex].first.first].push_back(make_pair(edgeList[edgeListIndex].first.second, edgeList[edgeListIndex].second));
        else
            tempResult = finalResult;
        edgeListIndex++;
    }
    return finalResult;
}
