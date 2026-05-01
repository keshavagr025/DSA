#include <iostream>
#include <vector>
#include <iomanip> // for setw

using namespace std;

int targetSum(vector<int> nums, int target) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Fill the DP table
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    

    // Print the DP table with headers
    cout << "DP Matrix:\n";
    cout << "   ";
    for (int j = 0; j <= target; j++) {
        cout << setw(3) << j;
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            cout << "0 |";
        } else {
            cout << nums[i - 1] << " |";
        }
        for (int j = 0; j <= target; j++) {
            cout << setw(3) << dp[i][j];
        }
        cout << endl;
    }

    if(dp[n][target] == target){
        cnt++;
    }

   cout << "Ans = " << cnt << endl;
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << "Result: " << targetSum(nums, target) << endl;
    return 0;
}
