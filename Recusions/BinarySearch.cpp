#include <iostream>
using namespace std;
 
int BinarySearch(int *arr ,int s , int e, int key)
{
    // Base Case 
    if ( s  >chrome e)
    {
        return -1;
    }

    int mid = s + (s - e)/2;

        if(arr[mid] == key)
        {
            return mid;
        }else if( arr[mid] > key)
        {
            BinarySearch(arr, s, mid - 1, key);
        }else
        {
            BinarySearch(arr, e, mid + 1, key);
        }
}
int main()
{
    int arr[] = {1,0,1,1,1};

    cout << BinarySearch(arr,0,1,0) << endl;

}