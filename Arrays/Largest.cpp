#include <iostream>
#include <string>
using namespace std;
int main()
{
    int arr[] = {3,5,6,7,8,9,22};
    int n = sizeof(arr)/sizeof(int);

    int max = arr[0];

    for(int i = 0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << max << endl;
}