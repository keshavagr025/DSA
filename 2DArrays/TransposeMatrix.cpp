#include<iostream>
using namespace std;

void Rotated(int arr[][3], int temp[][3] ,int n, int m)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            temp[i][j] = arr[j][i];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = m-1; j>=0; j--)
        {
            cout << temp[i][j] << " ,";
        }
    }
}



int main()
{
    int arr[3][3] =  {{1,2,3},{4,5,6},{7,8,9}};
    int temp[3][3];

    Rotated(arr,temp,3,3);

}