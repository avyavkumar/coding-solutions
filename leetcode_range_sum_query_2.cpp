#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int> > sumValues;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        sumValues.clear();
        sumValues.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            sumValues[i].resize(matrix[i].size(), -1);
        for (int i = 0; i < matrix.size(); i++)
            sumValues[i][0] = matrix[i][0];
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 1; j < matrix[i].size(); j++)
                sumValues[i][j] = sumValues[i][j-1] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        long long int finalResult = 0;
        for (int i = row1; i <= row2; i++)
        {
            if (col1 == 0)
                finalResult+= sumValues[i][col2];
            else
                finalResult+=(sumValues[i][col2] - sumValues[i][col1-1]);
        }
        return finalResult;
    }
};
