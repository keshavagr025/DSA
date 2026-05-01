#include <iostream>
using namespace std;

int BinarySearch(int *arr, int n, int key)
{

    int start = 0, end = n - 1;

    while (start <= end)
    {
       int mid =  (end + start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
   
   return -1;
}

int main()
{
    int arr[] = {3, 5, 6, 35, 55, 8, 56};
    int n = sizeof(arr) / sizeof(int);


    cout << BinarySearch(arr, n, 6) << endl;
}