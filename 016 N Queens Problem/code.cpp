//Leetcode Problem NO. 51
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int n, int row, int col)
{
    // Vertically
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Horizentally
    for (int j = col; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // Left diagonally
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Right diagonally
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(int n, vector<string> &board, vector<vector<string>> &ans, int row = 0)
{
    if (row == n)
    {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, n, row, j))
        {
            board[row][j] = 'Q';
            nQueens(n, board, ans, row + 1);
            board[row][j] = '.';
        }
    }
}

int main()
{
    int n = 4;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(n, board, ans, 0);

    // add here we can print ans;

    return 0;
}