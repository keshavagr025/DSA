#include<iostream>
using namespace std;

void PrintSubarrays(int *arr , int n)
{
    int cnt = 0;
    for (int start = 0; start < n; start++)
    {
        for(int end = start; end < n; end++)
        {
            // First and End Element of subarrays:
            //  cout << "(" << start << "," << end << ")";
            
            // Pairs of subarrays:
           
            for(int i=start; i<=end; i++)
            {
                if(i == 0){
                    cnt++;
                }
                cout << arr[i];
                cout << ",";
            }
             cout << "(," << ")" << "\n";
        }
        cout << endl;
       
    }

    cout << "Count = " << cnt << endl;
}

int main()
{
    int arr[] = {1,2,2};
    int n = sizeof(arr)/sizeof(int);

    PrintSubarrays(arr,n);

}