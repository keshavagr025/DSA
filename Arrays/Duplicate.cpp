#include<iostream>
#include <vector>
using namespace std;

void RemoveDuplicate(int *arr, int n)
{
    int k = 1;
    vector<int> temp;
    for(int i=1; i<n; i++)
    {
        if(arr[n-1] != arr[i])
        {
            arr[k] = arr[i];
            k++;
        }

        temp.push_back(arr[i]);
    }

    for(int i=0; i<temp.size(); i++){
        cout << temp[i] << " ";
    }

    cout << endl;
    
}

int main()
{
    int arr[] = {2,1,2};

    int n = sizeof(arr)/sizeof(int);

    RemoveDuplicate(arr, n);


}