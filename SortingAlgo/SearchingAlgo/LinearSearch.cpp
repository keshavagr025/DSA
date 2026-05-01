#include<iostream>
using namespace std;

int LinearSearch(int *arr, int n, int key)
{
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Its Linear Search = " << i << endl; 
        }
    }

    cout << "No Search" << endl;

}

int main()
{
    int arr[] = {3,45,64,3,56,7,54,44};
    int n = sizeof(arr)/sizeof(int);
    
    int key;
    cout << "Enter your Key Value" << endl;
    cin >> key;

    LinearSearch(arr , n, key);

    return 0;
}