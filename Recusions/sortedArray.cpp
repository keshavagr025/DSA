#include <iostream>
using namespace std;
 
bool SortedArray(int *arr, int n, int i)
{
    if( i == n-1)
    {
        return 1;
    }

    if(arr[i] > arr[i+1])
    {
        return 0;
    }

    return SortedArray(arr, n, i);
}
int main()
{
    int arr[5] = {5,3,4,2,1};
    cout << SortedArray(arr, 5 , 0) << endl;
}