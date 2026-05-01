#include <iostream>
using namespace std;

int diagonalSum(int matrix[][4], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
            else if (j==n-i-1)
            {
                sum += matrix[i][j];
            }
        }
    }

    cout << "Sum = " << sum <<endl;

}

int main()
{
    int matrix[4][4] = {{6,7,8},
                        {4, 6,7},
                        {1,4,6}};

    diagonalSum(matrix,4);
}