#include <bits/stdc++.h>

using namespace std;

struct node
{
    node *left;
    node *right;
    pair<string, int> value;
    node(pair<string, int> s) : value(s), left(NULL), right(NULL) {}
};

bool comparingFuncForPair(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}

bool comparingFuncForNode(node *a, node *b)
{
    return a->value.second < b->value.second;
}

std::map<string, string> finalResult;

node* getHuffmanTree(std::vector<pair<string,int>> keyValues)
{
    sort(keyValues.begin(), keyValues.end(), comparingFuncForPair);
    std::vector<node*> listNodes;
    for (int i = 0; i < keyValues.size(); i++)
    {
        node *temp = new node(make_pair(keyValues[i].first, keyValues[i].second));
        listNodes.push_back(temp);
    }
    while (listNodes.size() != 1)
    {
        node *firstNode = listNodes[0];
        node *secondNode = listNodes[1];
        listNodes.erase(listNodes.begin()); listNodes.erase(listNodes.begin());
        node *resultNode = new node(make_pair("",firstNode->value.second+secondNode->value.second));
        resultNode->left = firstNode; resultNode->right = secondNode;
        listNodes.push_back(resultNode);
        sort(listNodes.begin(), listNodes.end(), comparingFuncForNode);
    }
    return listNodes[0];
}

void getCodes(node *root, string rootCode)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        finalResult[root->value.first] = rootCode;
        return;
    }
    getCodes(root->left, rootCode + "0");
    getCodes(root->right, rootCode + "1");
}
