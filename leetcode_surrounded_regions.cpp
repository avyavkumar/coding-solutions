#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if ((i == 0 || i == board.size()-1 || j == 0 || j == board[i].size()-1) && (board[i][j] == 'O'))
                {
                    board[i][j] = 'M';
                    connected(i, j, board);
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'M')
                    board[i][j] = 'O';
            }
        }
    }

    void connected(int i, int j, vector<vector<char>>& board)
    {
        if (i-1 > 0 && board[i-1][j] == 'O')
        {
            board[i-1][j] = 'M';
            connected(i-1, j, board);
        }
        if (i+1 < board.size()-1 && board[i+1][j] == 'O')
        {
            board[i+1][j] = 'M';
            connected(i+1, j, board);
        }
        if (j-1 > 0 && board[i][j-1] == 'O')
        {
            board[i][j-1] = 'M';
            connected(i, j-1, board);
        }
        if (j+1 < board[i].size()-1 && board[i][j+1] == 'O')
        {
            board[i][j+1] = 'M';
            connected(i, j+1, board);
        }
    }
};
