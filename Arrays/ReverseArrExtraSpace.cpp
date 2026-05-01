#include <iostream>
using namespace std;
// int ReverseArr(int *arr, int n)
// {
//     for (int i = n-1; i >=0; i--)
//     {
//         cout << arr[i] << ",";
//     }

// }
// int main()
// {
//     int arr[] = {3,4,5,23,2,33,6};
//     int n = sizeof(arr)/sizeof(int);

//     ReverseArr(arr,n);

// }

void PrintArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 4, 6, 4, 33, 56, 35};
    constexpr int n = sizeof(arr) / sizeof(int);

    int copyArr[n]; // Extra Space:

    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1; // j = 6 - 0 - 1 = 5 index: 
        copyArr[i] = arr[j];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = copyArr[i];
    }

    PrintArr(arr, n);
}