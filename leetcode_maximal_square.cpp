#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.empty())
            return 0;
        std::vector<std::vector<int>> outputMatrix;
        outputMatrix.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            outputMatrix[i].resize(matrix[i].size(),0);

        for (int i = 0; i < matrix.size(); i++)
            outputMatrix[i][0] = matrix[i][0] - '0';

        for (int i = 0; i < matrix[0].size(); i++)
            outputMatrix[0][i] = matrix[0][i] - '0';

        for (int i = 1; i < outputMatrix.size(); i++)
        {
            for (int j = 1; j < outputMatrix[i].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (outputMatrix[i-1][j] == outputMatrix[i][j-1] && outputMatrix[i-1][j-1] == outputMatrix[i-1][j])
                        outputMatrix[i][j] = outputMatrix[i-1][j-1] + 1;
                    else
                        outputMatrix[i][j] = min(min(outputMatrix[i][j-1],outputMatrix[i-1][j-1]),outputMatrix[i-1][j]) + 1;
                }
                else
                    outputMatrix[i][j] = 0;
            }
        }

        int finalResult = 0;
        for (int i = 0; i < outputMatrix.size(); i++)
        {
            for (int j = 0; j < outputMatrix[i].size(); j++)
            {
                if (outputMatrix[i][j] > finalResult)
                    finalResult = outputMatrix[i][j];
            }
        }
        return finalResult*finalResult;
    }
};
