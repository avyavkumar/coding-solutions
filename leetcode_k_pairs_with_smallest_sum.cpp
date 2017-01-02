#include <bits/stdc++.h>

using namespace std;

bool sortingFunc (pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    if (b.second > a.second)
        return true;

    return false;
}

class Solution
{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        std::vector<pair<int,int>> finalResult;
        if (k == 0 || nums1.size() == 0 || nums2.size() == 0)
            return finalResult;

        std::vector<pair<pair<int,int>,int>> tempResult;

        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)
                tempResult.push_back(make_pair(make_pair(i,j),nums1[i]+nums2[j]));

        sort(tempResult.begin(), tempResult.end(), sortingFunc);

        for (int i = 0; i < min(k,(int)nums1.size() * (int)nums2.size()); i++)
            finalResult.push_back(make_pair(nums1[tempResult[i].first.first], nums2[tempResult[i].first.second]));

        return finalResult;
    }
};
