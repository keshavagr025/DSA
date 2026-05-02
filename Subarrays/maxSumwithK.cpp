#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int maxSumWithK(int *arr, int n, int k)
{
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int sum = 0;
            for (int i = start; i <= end; i++)
            {
                sum = sum + arr[i];
            }
            if (sum <= k)
            {
                maxSum = max(maxSum, sum);
            }
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {2,5,1,7,10};
    int n = sizeof(arr) / sizeof(int);
    int k = 14;

    cout << "Maximum sum of subarray with sum less than or equal to " << k << " is: " << maxSumWithK(arr, n, k) << endl;
}