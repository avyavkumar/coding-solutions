#include <bits/stdc++.h>

using namespace std;

std::map< int, UndirectedGraphNode *> labels;

class Solution
{
public:
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node)
    {
        if (node == NULL)
            return NULL;

        UndirectedGraphNode *parent = NULL;

        auto it = labels.find(node->label);

        if ( it == labels.end())
        {
            parent = new UndirectedGraphNode(node->label);
            labels[node->label] = parent;
            for (int i = 0; i < node->neighbors.size(); i++)
            {
                if (node->neighbors[i] == node)
                    parent->neighbors.push_back(parent);
                else
                {
                    UndirectedGraphNode *temp = cloneGraphHelper(node->neighbors[i]);
                    if (temp != NULL)
                        parent->neighbors.push_back(temp);
                }
            }
        }
        else
            return (*it).second;

        return parent;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        labels.clear();
        return cloneGraphHelper(node);
    }
};
