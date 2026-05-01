#include<iostream>
using namespace std;

void TransposeMat(int mat[][3], int n, int m)
{
    int mat1[3][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat1[j][i] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat1[i][j] << " ";
        }  
    }
    
    
}
int main()
{
    int mat[3][3] = {
                     {2,2,3},
                     {11,4,3},
                     {1,4,9},};


    TransposeMat(mat, 3, 3);

      
}