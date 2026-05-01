#include <iostream>
#include <vector>
using namespace std;

int merge(int arr[], int si, int mid, int ei)
{
    vector<int> temp;

    int i = si;
    int j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    // copy array

    for (int idx = si, x = 0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }
}

void  mergeSort(int arr[], int si, int ei)
{
    // Base case

    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);     // Left part of Divided array
    mergeSort(arr, mid + 1, ei); // Rigtht part of Divided array

    merge(arr, si, mid, ei);
}

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
int main()
{
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    PrintArr(arr, n);
}