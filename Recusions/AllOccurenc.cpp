#include <iostream>
#include <vector>
using namespace std;

void allOccure(int arr[], int key, int i, int n)
{
    // means pura array tak i itrate karna chaiye i > n hoga tab nhi chalega
    if( i == n)
    {
        return;
    }
    
    if (arr[i] == key)
    {
     
        cout << i << ",";
    }

    allOccure(arr,key, i+1, n);

}
int main()
{
   int arr[] = {1, 2, 3, 3, 4, 5, 6, 3, 5, 3};

  allOccure(arr, 3, 0, 10);
}