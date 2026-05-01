#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


// Implementation of this formula

// sum[i,j] = sum[j] - sum[i-1]
//    |
//    |
//    |
//   ***
//    *
//

// sum[i-1] = sum[j] - sum[k];


int subarrayCountWithK(vector<int> arr, int k){  //O(n)

    unordered_map<int, int> m; //sum, count
    m[0] = 1; // this write bcz in some case you have only single element in the arr the have count = 1
    int ans = 0;
    int sum = 0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];  // taking sum of subarrays

        if(m.count(sum-k)){  // sum[j-1] = sum[j] - sum[j-k]
            ans += m[sum-k];
        }

        if(m.count(sum)){  // increasing the counts of finding sum in the subarray
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "Count sum equal to k = " << subarrayCountWithK(arr, k) << endl;

    return 0;
}