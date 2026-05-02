#include <bits/stdc++.h>
using namespace std;

int maxLength(int *arr, int n, int k){
    
    int maxlen = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum <= k){
                maxlen = max(maxlen, j - i + 1);
            }else if(sum > k){
                break;
            }
        }
    }
    
   return maxlen;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int s = sizeof(arr)/sizeof(int);
    int k = 12;
    
    cout << "Answer is = " << maxLength(arr, s, k) << endl;

    return 0;
}