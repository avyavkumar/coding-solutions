#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isUgly(int num)
    {
        if (num == 1)
            return true;
        else
        {
            while (num != 0 && num%2 == 0)
                num/=2;
            if (num == 1)
                return true;
            while (num != 0 && num%3 == 0)
                num/=3;
            if (num == 1)
                return true;
            while (num != 0 && num%5 == 0)
                num/=5;
            if (num == 1)
                return true;
            return false;
        }
    }
};
