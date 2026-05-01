#include <iostream>
#include <vector>
using namespace std;


void printSudoko(int sudoko[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoko[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoko[9][9], int row, int col, int dig)
{
    // Vertical
    for (int i = 0; i <= 8; i++)
    {
        if(sudoko[i][col] == dig)
        {
            return false;
        }
    }

    //  Horizontally
    for (int j = 0; j <= 8; j++)
    {
        if (sudoko[row][j] == dig)
        {
            return false;
        }
    }

    // for small Box code;

    int strRow = (row/3)*3;
    int strCol = (col/3)*3;

    for (int i = strRow; i <= strRow + 2; i++)
    {
        for (int j = strCol; j <= strCol + 2; j++)
        {
            if(sudoko[i][j] == dig)
            {
                return false;
            }
        }
    }
    
    return true;    
}

bool sudokoSolver(int sudoko[][9], int row, int col)
{

    if(row == 9)
    {
        printSudoko(sudoko);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if(sudoko[row][col] != 0)
    {
        return sudokoSolver(sudoko, nextRow, nextCol);
    }

    for (int  dig = 1; dig <= 9; dig++)
    {
        if(isSafe(sudoko, row, col, dig))
        {
            sudoko[row][col] = dig;
            if(sudokoSolver(sudoko, row, col))
            {
                return true;
            }
            sudoko[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int sudoko[9][9] = { {0,0,8,0,0,0,0,0,0},
                         {4,9,0,1,5,7,0,0,2},
                         {0,0,3,0,0,4,1,9,0},
                         {1,8,5,0,6,0,0,2,0},
                         {0,0,0,0,2,0,0,6,0},
                         {9,6,0,4,0,5,3,0,0},
                         {0,3,0,0,7,2,0,0,4},
                         {0,4,9,0,3,0,0,5,7},
                         {8,2,7,0,0,9,0,1,3}};

    cout << sudokoSolver(sudoko, 0, 0);
    
}