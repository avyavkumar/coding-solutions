#include <bits/stdc++.h>

using namespace std;

bool checkBipartite(std::vector<std::vector<int>> graph, int sourceNode)
{
    std::vector<int> colourNode(graph.size(),-1);           // valid colours are 0 and 1, uninitialised colour is -1
    colourNode[sourceNode] = 0;
    queue<int> nodeList;
    nodeList.push(sourceNode);
    while (nodeList.size() > 0)
    {
        int currentSource = nodeList.front(); nodeList.pop();

        for (int i = 0; i < graph[currentSource].size(); i++)
        {
            if (colourNode[graph[currentSource][i]] == -1)
            {
                colourNode[graph[currentSource][i]] = 1 - colourNode[currentSource];
                nodeList.push(graph[currentSource][i]);
            }
            else if (colourNode[graph[currentSource][i]] == colourNode[currentSource])
                return false;
        }
    }
    return true;
}
