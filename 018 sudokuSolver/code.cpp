#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int ch)
{
    // Horizantal
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == (ch + '0'))
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == (ch + '0'))
        {
            return false;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == ch + '0')
            {
                return false;
            }
        }
    }

    return true;
}

bool solver(vector<vector<char>> &board, int row = 0, int col = 0)
{

    if (row >= 9)
    {
        return true;
    }

    int nextRow = row, nextCol = col + 1;

    if (nextCol >= 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (board[row][col] != '.')
    {
        return solver(board, nextRow, nextCol);
    }

    for (int ch = 1; ch <= 9; ch++)
    {

        if (isSafe(board, row, col, ch))
        {
            board[row][col] = ch + '0';
            if (solver(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solver(board);

    return 0;
}