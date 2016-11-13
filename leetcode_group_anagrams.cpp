#include <bits/stdc++.h>

using namespace std;

bool compareFunc(pair<string,int> pair1, pair<string,int> pair2)
{
    if (pair2.first.compare(pair1.first) > 0)
        return true;
    return false;
}

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::vector<std::vector<string>> finalResult;

        if (strs.empty() || strs.size() < 1)
            return finalResult;

        if (strs.size() == 1)
        {
            std::vector<string> v;
            v.push_back(strs[0]);
            finalResult.push_back(v);
            return finalResult;
        }

        std::vector<string> tempStrings(strs);
        for (int i = 0; i < tempStrings.size(); i++)
            sort(tempStrings[i].begin(),tempStrings[i].end());
        std::vector<pair<string,int>> sortedStrings;
        for (int i = 0; i < tempStrings.size(); i++)
            sortedStrings.push_back(make_pair(tempStrings[i],i));

        sort(sortedStrings.begin(),sortedStrings.end(),compareFunc);

        std::vector<string> tempResult;
        tempResult.push_back(strs[sortedStrings[0].second]);
        for (int i = 1; i < sortedStrings.size(); i++)
        {
            if (sortedStrings[i].first.compare(sortedStrings[i-1].first) == 0)
                tempResult.push_back(strs[sortedStrings[i].second]);
            else
            {
                finalResult.push_back(tempResult);
                tempResult.clear();
                tempResult.push_back(strs[sortedStrings[i].second]);
            }
        }
        if (!tempResult.empty())
            finalResult.push_back(tempResult);
        return finalResult;
    }
};
