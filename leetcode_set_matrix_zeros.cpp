#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool firstRowContainsZero = false, firstColumnContainsZero = false;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0)
                firstColumnContainsZero = true;

        for (int i = 0; i < matrix[0].size(); i++)
            if (matrix[0][i] == 0)
                firstRowContainsZero = true;

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (firstRowContainsZero)
        {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

        if (firstColumnContainsZero)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};
