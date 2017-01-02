#include <bits/stdc++.h>

using namespace std;

int getMinimumDistanceNode(set<int> nodeList, std::vector<int> distanceSource)
{
    set<int>::iterator it;
    int minimumNode, minimumWeight = INT_MAX;
    for (it = nodeList.begin(); it != nodeList.end(); it++)
    {
        if (distanceSource[*it] < minimumWeight)
        {
            minimumWeight = distanceSource[*it];
            minimumNode = *it;
        }
    }
    return minimumNode;
}

std::vector<int> returnShortestPaths(std::vector<std::vector<pair<int,int>>> graph, int sourceNode)
{
    set<int> nodeList;
    std::vector<int> distanceSource(graph.size(),INT_MAX);
    std::vector<int> previousNode(graph.size(),-1);

    for (int i = 0; i < graph.size(); i++)
        nodeList.insert(i);

    distanceSource[sourceNode] = 0;

    while (nodeList.size() > 0)
    {
        int u = getMinimumDistanceNode(nodeList,distanceSource);
        nodeList.erase(nodeList.find(u));

        for (int i = 0; i < graph[u].size(); i++)
        {
            int temp = distanceSource[u] + graph[u][i].second;
            if (temp < distanceSource[graph[u][i].first])
            {
                distanceSource[graph[u][i].first] = temp;
                previousNode[graph[u][i].first] = u;
            }
        }
    }

    return distanceSource;
}
