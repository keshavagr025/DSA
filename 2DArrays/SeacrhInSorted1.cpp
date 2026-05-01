#include<iostream>
using namespace std;

bool SortedArray(int matrix[][4], int n, int m, int key)
{
    for (int i=0; i<n; i++)
    {
        for (int  j=0; j<m ; j++)
        {
            if(key == matrix[i][j])
            {
                cout << "(" << i << "," << j << ")\n";
            }
        }
    }
    cout << "Key not Found" << endl;
    return false; 
}


int main()
{
    int matrix[4][4] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}};

          SortedArray(matrix,4,4,3);               
}