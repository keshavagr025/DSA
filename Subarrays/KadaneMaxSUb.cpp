#include <iostream>
#include <cmath>
using namespace std;

void PrintSubarrays(int *arr, int n)
{
    int maxSum = INT16_MIN;
    int Currsum = 0;
    for (int i = 0; i < n; i++)
    {
        Currsum += arr[i];
        maxSum = max(maxSum, Currsum);
        if(Currsum <0)          
        {
            Currsum = 0;
        }
    }
    cout << "Maximum number is = " << maxSum << endl;
}

int main()
{
    int arr[] = {0 ,-2 ,2, -1, 1};
    int n = sizeof(arr) / sizeof(int);

    PrintSubarrays(arr, n);
}

