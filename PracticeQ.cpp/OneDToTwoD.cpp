#include <iostream>
using namespace std;

void OneD(int *arr[][3], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i];
        }
    }
}

int main()
{
    int arr[][3] = {{2,2,4},{4,5,6},{1,3,4}};
    int n = sizeof(arr)/sizeof(int);


}