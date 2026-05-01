#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int largestSubarryEqualToZero(vector<int> arr, int n){

    unordered_map<int, int> m; // sum, idx

    int ans = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(m.count(sum)){
            int currLen = i - m[sum];
            ans = max(ans, currLen);
        }else{
            m[sum] = i;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {15,-2,2,-8,1,7,10};
    int n = 7;

    cout << largestSubarryEqualToZero(arr,n);

    return 0;
}