#include<iostream>
#include<cmath>
using namespace std;

void PrintSubarrays(int *arr , int n,int key)
{
    int maxSum  = INT16_MIN;
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for(int end = start; end < n; end++)
        {
            sum += arr[end];
            if(sum == key)
            {
               cout << arr[end] << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {10, 5, 2, 7, 1, -10};
    int n = sizeof(arr)/sizeof(int);

    PrintSubarrays(arr,n,15);

}  