#include<iostream>
using namespace std;

int Print(int *arr, int n )
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
    
}

int BubbleSort(int *arr, int n)
{
    for(int i=0; i<n-1; i++) // last index
    {
        for (int j = 0; j < n-i-1; j++) // second last index
        {
            if(arr[j] > arr[j+1]) // j+1 beacuse to check j's greater than not j's to j's like that 4 > 4 + 1;
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    Print(arr, n);
}


int main()
{
    int arr[] = {5,4,1,3,2,7,9,33,5,6,775,3};
    int n = sizeof(arr)/sizeof(int);
    BubbleSort(arr,n);


}