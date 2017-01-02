#include <bits/stdc++.h>

using namespace std;

struct trieNode
{
    std::map<string, trieNode*> listNodes;
    bool isLeaf;
    trieNode() : isLeaf(false) {}
};

bool insertNode(int stringIndex, string inputString, trieNode *root)
{
    if (root != NULL)
    {
        if (stringIndex == inputString.length())
        {
            root->isLeaf = true;
            return true;
        }
        else if (root->listNodes.find(to_string(inputString[stringIndex])) == root->listNodes.end())
            root->listNodes[to_string(inputString[stringIndex])] = new trieNode();

        return insertNode(stringIndex+1, inputString, root->listNodes[to_string(inputString[stringIndex])]);
    }
    else
        return false;
}

bool searchNode(int stringIndex, string inputString, trieNode *root)
{
    if (root != NULL)
    {
        if (stringIndex == inputString.length())
            return root->isLeaf;
        if (root->listNodes.find(to_string(inputString[stringIndex])) == root->listNodes.end())
            return false;
        return searchNode(stringIndex+1, inputString, root->listNodes[to_string(inputString[stringIndex])]);
    }
    else
        return false;
}

bool deleteNode(int stringIndex, string inputString, trieNode *root)
{
    if (stringIndex == inputString.length())
    {
        if (!root->isLeaf)
            return false;
        root->isLeaf = false;
        return root->listNodes.size() == 0;
    }
    else
    {
        if (root->listNodes.find(to_string(inputString[stringIndex])) == root->listNodes.end())
            return false;
        bool shouldDeleteNode = deleteNode(stringIndex+1,inputString,root->listNodes[to_string(inputString[stringIndex])]);
        if (shouldDeleteNode)
        {
            root->listNodes.erase(root->listNodes.find(to_string(inputString[stringIndex])));
            if (root->listNodes.size() == 0)
                return true;
        }
        return false;
    }
}
