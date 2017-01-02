#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> finalResult;
        if (numRows == 0)
            return finalResult;
        std::vector<int> temp; temp.push_back(1); finalResult.push_back(temp);
        if (numRows == 1)
            return finalResult;
        temp.clear(); temp.push_back(1); temp.push_back(1); finalResult.push_back(temp);
        if (numRows == 2)
            return finalResult;

        for (int i = 3; i <= numRows; i++)
        {
            temp.clear();
            temp.push_back(1);
            for (int j = 0; j < finalResult.back().size()-1; j++)
                temp.push_back(finalResult.back().at(j)+finalResult.back().at(j+1));
            temp.push_back(1);
            finalResult.push_back(temp);
        }
        
        return finalResult;
    }
};
