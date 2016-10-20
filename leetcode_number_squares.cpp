#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int finalResult[n+1];

        for (int i = 0; i < n+1; i++)
            finalResult[i] = 0;

        finalResult[1] = 1;
        finalResult[2] = 2;
        int squareCount = 1;

        for (int i = 1; i < n+1; i++)
        {
            if (i == squareCount*squareCount)
            {
                finalResult[i] = 1;
                squareCount++;
            }
            else
            {
                finalResult[i] = std::numeric_limits<int>::max();
                for (int j = 1; j < squareCount; j++)
                    finalResult[i] = min(finalResult[i], finalResult[i-((squareCount-j)*(squareCount-j))] + 1);
            }
        }

        return finalResult[n];
    }
};
