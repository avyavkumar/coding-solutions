#include <bits/stdc++.h>

using namespace std;

struct node
{
    int numberSteps;
    string currentString;
    node(string s, int n) : currentString(s), numberSteps(n) {}
};

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
    {
        node *root = new node(beginWord,1);
        wordList.insert(endWord);

        queue<node*> listNodes;
        listNodes.push(root);

        while (listNodes.size() > 0)
        {
            node *temp = listNodes.front();
            listNodes.pop();
            int currentStep = temp->numberSteps;
            if (temp->currentString == endWord)
                return temp->numberSteps;

            string firstString = temp->currentString;
            for (int i = 0; i < firstString.length(); i++)
            {
                for (char x = 'a'; x <= 'z'; x++)
                {
                    char temp = firstString[i];
                    if (firstString[i] != x)
                        firstString[i] = x;
                    std::unordered_set<string>::iterator it = wordList.find(firstString);
                    if (it != wordList.end())
                    {
                        listNodes.push(new node(*it, currentStep+1));
                        wordList.erase(it);
                    }
                    firstString[i] = temp;
                }
            }
        }
        return 0;
    }
};
