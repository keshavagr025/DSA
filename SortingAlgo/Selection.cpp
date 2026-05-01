#include<iostream>
using namespace std;

int Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int SelectionSort(int *arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n-1; i++)
    {
        // minimum value:
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
          swap(arr[i], arr[minIndex]);
          cnt++;
        
    }
    Print( arr, n);
    cout << "Cnt = " <<  cnt;
}


int main()
{
    int arr[] = {2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr, n);

}