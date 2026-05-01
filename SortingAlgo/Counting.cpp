#include <iostream>
#include <limits.h>
using namespace std;

int Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int CountingSort(int *arr, int n)
{
    int freq[10000] = {0}; // range
    int minValue = INT_MAX, maxValue = INT_MIN;

        //     1 Step
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
            minValue = min(minValue, arr[i]);
            maxValue = max(maxValue, arr[i]);
        }

        // 2 step

        for (int i = minValue, j = 0; i <= maxValue; i++)
        {
            while (freq[i] > 0)
            {
                arr[j++] = i;
                freq[i]--;
            }
        } 
    
    Print(arr, n);
}

int main()
{
    int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    CountingSort(arr, n);
}