#include <iostream>
#include <algorithm>
using namespace std;
 
int Major(int arr[], int n)
{
    sort(arr, arr + n);

    return arr[n/2]; 
}
int main()
{
    int arr[] = {3,2,3};
    int n =sizeof(arr)/sizeof(int)

    cout << Major(arr, n) << endl;
}