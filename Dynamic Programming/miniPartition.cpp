#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int getMiniPartition(vector<int> nums) {
    int totSum = 0;
    for(int el : nums) {
        totSum += el; // Corrected sum calculation
    }

    int n = nums.size();
    int w = totSum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for(int i = 1; i <= n; i++) { // Corrected loop boundary
        for(int j = 1; j <= w; j++) {
            if(nums[i - 1] <= j) {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int grp1 = dp[n][w];
    int grp2 = totSum - grp1;
    return abs(grp1 - grp2); // Changed to return the result
}

int main() {
    vector<int> nums = {1, 6, 11, 5};
    
    cout << getMiniPartition(nums) << endl; // Updated to handle return value
}