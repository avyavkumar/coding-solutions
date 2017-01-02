#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::plusOne(vector<int> &A)
{
    int carryValue = 1;
    std::vector<int> tempArray(A);
    for (int i = A.size()-1; i >= 0; i--)
    {
        tempArray[i] = tempArray[i] + carryValue;
        carryValue = tempArray[i]/10;
        tempArray[i] = tempArray[i]%10;
    }

    if (carryValue != 0)
        tempArray.insert(tempArray.begin(),carryValue);

    for (int i = 0; i < tempArray.size(); i++)
    {
        if (tempArray.front() == 0)
            tempArray.erase(tempArray.begin());
        else
            break;
    }

    return tempArray;
}
