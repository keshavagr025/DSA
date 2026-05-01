#include<iostream>
#include<cmath>
using namespace std;

void PrintSubarrays(int *arr , int n)
{
    // int maxSum = INT_MIN;
    for (int start = 0; start < n; start++)
    {
        for(int end = start; end < n; end++)
        {
            int sum = 0;
            for(int i=start; i<=end; i++)
            {
                sum = sum + arr[i];
            }
             cout << sum <<",";
        }
        cout << endl;
       
    }
}

int main()
{
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    PrintSubarrays(arr,n);

}