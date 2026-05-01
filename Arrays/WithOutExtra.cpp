#include<iostream>
#include<cmath>
using namespace std;

int PrintArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }

    cout << endl;
    
}


int main()
{
    int arr[] = {3,4,5,6,7,4,36};
    int n = sizeof(arr)/sizeof(int);

    int start = 0;
    int end = n-1;

    while(start <= end)
    {
        swap(start[arr],end[arr]);
        start++;
        end--;
    }

    PrintArr(arr, n);

}