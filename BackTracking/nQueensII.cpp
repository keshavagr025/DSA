#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> board, int row, int col)
{
    // Horizontal safety
    int n = board.size();

    for (int j = 0; j < n; j++) // rows
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // Vertical safety

    for (int i = 0; i < row; i++) // cols
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Diagonals left

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Diagonals rigth

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

int nQueens(vector<vector<char>> board, int row)
{
    int n = board.size();
    if (row == n) { return 1; }
    
    int count = 0;
    for (int j = 0; j < n; j++) // col
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
           count += nQueens(board, row + 1);
            board[row][j] = '.';
        }
    }
    
    return count;
}

int main()
{
    vector<vector<char>> board;
    int n = 1;
    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back('.');
        }

        board.push_back(newRow);
    }

   int count = nQueens(board, 0);

   cout <<  count;

    return 0;
}