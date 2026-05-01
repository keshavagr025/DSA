#include <iostream>
using namespace std;

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    cout << endl;
}
int Search(int arr[], int si, int ei, int target)
{
    if (si > ei)
    {
        return -1;
    }

    int mid = si + (ei - si) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[si] <= arr[mid])
    {
        if (arr[si] <= target && target < arr[mid])
        {
            // rigth half
            return Search(arr, si, mid - 1,target);
        }
        else
        {
           return Search(arr, mid + 1, ei, target);
        }
    }
    else
    {
        if (arr[mid] < target && target <= arr[ei])
        {
            // left half
           return Search(arr, mid + 1, ei, target);
        }
        else
        {
           return Search(arr, si, mid - 1, target);
        }
    }
}
int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "idx:" << Search(arr, 0, n - 1, 1) << endl;
}