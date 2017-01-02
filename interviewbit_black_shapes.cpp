#include <bits/stdc++.h>

using namespace std;

int counted = 0;

bool isValid(int i, int j, vector<string> &A)
{
    if (i >= 0 && i < A.size())
    {
        if (j >= 0 && j < A[i].length())
            return true;
    }
    return false;
}

void DFS(vector<string> &A, std::vector<std::vector<int>> &visited, int i, int j)
{
    if (isValid(i,j,A))
    {
        if (visited[i][j] == -1 && A[i][j] == 'X')
        {
            visited[i][j] = counted;
            if (isValid(i-1,j,A))
                DFS(A,visited,i-1,j);
            if (isValid(i,j-1,A))
                DFS(A,visited,i,j-1);
            if (isValid(i+1,j,A))
                DFS(A,visited,i+1,j);
            if (isValid(i,j+1,A))
                DFS(A,visited,i,j+1);
        }
    }
}

int Solution::black(vector<string> &A)
{
    std::vector<std::vector<int>> visited(A.size());
    counted = 0;
    for (int i = 0; i < A.size(); i++)
        visited[i].resize(A[i].length(), -1);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].length(); j++)
        {
            if (A[i][j] == 'X' && visited[i][j] == -1)
            {
                DFS(A,visited,i,j);
                counted++;
            }
        }
    }

    return counted;
}
