#include <iostream>
using namespace std;

int Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
void changeArr(int arr[], int n, int i)
{
    if(i == n)
    {
        Print(arr,n);
        return;
    }
      
    arr[i] = i + 1;
    changeArr(arr, n, i+1);
   
    arr[i] -= 2;
}
int main()
{
    int arr[5] = {};
    int n = 5;

    changeArr(arr, n, 0);
    Print(arr, n);
  
}