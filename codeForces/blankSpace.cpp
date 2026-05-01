#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    while(n--){
        
        long long x;
        cin >> x;
        
        vector<long long> arr(x);
        
        for(long long i = 0; i < x; i++) cin >> arr[i];
        
        
        long long maximum_length = 0;
        long long cnt0 = 0;
        
        for(long long i=0; i<x; i++){
            
            if(arr[i] == 0){
                cnt0++;
            }else{
                cnt0 = 0;  
            }
            
             maximum_length = max(maximum_length, cnt0);
        }
        
        cout << maximum_length << endl;
    }
}