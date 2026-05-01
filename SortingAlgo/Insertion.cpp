#include<iostream>
using namespace std;

int Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long int InsertionSort(int *arr, int n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1; // backward ke liye like that 4,5 5 se 4 tak jane ke liye: i-1;

        while(prev >= 0 && arr[prev] > curr)
        {
            swap(arr[prev], arr[prev+1]);
            prev--;
            cnt++;
        }

        arr[prev+1] = curr;
    }

     Print(arr,n);
     cout << "Cnt = " <<  cnt;
    
}
int main()
{
 int arr[] = {5,5,5};
 int n = sizeof(arr)/sizeof(int);

    InsertionSort(arr, n);

}