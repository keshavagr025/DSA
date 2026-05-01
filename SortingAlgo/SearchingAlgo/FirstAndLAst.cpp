#include <iostream>
using namespace std;

int BinarySearch(int *arr, int n, int key)
{

    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
       
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid-1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
   
   return ans;
}

int BinarySearch2(int *arr, int n, int key)
{

    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
       
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid+1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
   
   return ans;
}

int main()
{
    int arr[] = {3, 5, 6, 35, 55, 8, 56};
    int n = sizeof(arr) / sizeof(int);


    cout << BinarySearch(arr, n, 6) << endl;
    cout << BinarySearch2(arr, n, 6) << endl;
}