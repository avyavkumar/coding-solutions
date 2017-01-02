#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.size() < 2)
            return 0;
        std::vector<int> frontArray(height.size(),0);
        std::vector<int> backArray(height.size(),0);

        int maxValue = height[0];
        frontArray[0] = maxValue;
        for (int i = 1; i < frontArray.size(); i++)
        {
            if (height[i] > maxValue)
                maxValue = height[i];
            frontArray[i] = maxValue;
        }

        maxValue = height[height.size()-1];
        backArray[height.size()-1] = maxValue;
        for (int i = height.size()-2; i >= 0; i--)
        {
            if (height[i] > maxValue)
                maxValue = height[i];
            backArray[i] = maxValue;
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++)
            result += min(frontArray[i],backArray[i])-height[i];

        return result;
    }
};
