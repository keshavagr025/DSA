#include <iostream>
#include <cmath>
#include <malloc.h>
#include <vector>
using namespace std;

int SecLargest(int *arr, int n)
{ 
    int largest = arr[0];
    int secLar = -1;

    for(int i = 1; i<n; i++)
    {
        if(arr[i] > largest)
        {
            secLar = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > secLar) // not neccsary to add it condition as well as:
        {
            secLar = arr[i];
        }
    }

    cout << "The Second Largest Array is = " << secLar << endl;
}

void pushZerosToEnd(vector<int>& arr, int n){

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            arr.push_back(i);
        }
    }

    cout << arr;
}

int main()
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr)/sizeof(int);

    pushZerosToEnd(arr, n)

}