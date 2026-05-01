#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, -1); // Initialize the answer vector with n elements, all set to -1
//         stack<int> s;

//         for (int i = 2 * n - 1; i >= 0; --i) { // Loop for simulating circular array
//             while (!s.empty() && nums[i % n] >= s.top()) {
//                 s.pop();
//             }
//             if (!s.empty()) {
//                 ans[i % n] = s.top();
//             }
//             s.push(nums[i % n]);
//         }

//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> nums = {1, 2, 1};
//     vector<int> result = sol.nextGreaterElements(nums);

//     cout << "Next greater elements: ";
//     for (int i : result) {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }


void nextGreaterElement(vector<int>arr, vector<int>ans){

    stack<int>s;
    int idx = arr.size() - 1;
    ans[idx] = -1; // last value ko -1 kardiya
    s.push(arr[idx]);

    for (idx = idx - 1; idx >= 0; idx--)
    {
        int curr = arr[idx];
        while (!s.empty() && curr >= s.top())
        {
           s.pop();
        }

        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }

        s.push(curr);
    }


    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans = {0,0,0,0,0};

    nextGreaterElement(arr, ans);
}