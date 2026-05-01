#include <iostream>
#include <vector>

using namespace std;

void PrintBoard(vector<vector<char>> board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> board, int row, int col)
{
    // Horizontal safety
    int n = board.size();

    for (int j = 0; j < n; j++) // rows
    {
        if (board[row][j] == 'K')
        {
            return false;
        }
    }

    // Vertical safety

    for (int i = 0; i < row; i++) // cols
    {
        if (board[i][col] == 'K')
        {
            return false;
        }
    }

    // Horizontal safety left

    for (int i= row, j = col; i>=0 && j >=0; i++,j--) // rows
    {
        if (board[row][j] == 'K')
        {
            return false;
        }
    }

     // Horizontal safety right

    for (int i= row, j = col; i>=0 && j >=0; i--,j++) // rows
    {
        if (board[row][j] == 'K')
        {
            return false;
        }
    }

    return true;
}

void Nknights(vector<vector<char>> board, int row)
{
    int n = board.size();
    if (row == n)
    {
        PrintBoard(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'K';
            Nknights(board, row + 1);
            board[row][j] = '.';
        }
    }
}

int main()
{
    vector<vector<char>> board;
    int n = 2;
    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back('.');
        }

        board.push_back(newRow);
    }

    Nknights(board, 0);
}