#include <bits/stdc++.h>
using namespace std;

// int longestCommonSub(string str1, string str2) // O(2^n+m)
// {
//     if (str1.size() == 0 || str2.size() == 0)
//     {
//         return 0;
//     }

//     int n = str1.size();
//     int m = str2.size();

//     if (str1[n - 1] == str2[m - 1])
//     {
//         return 1 + longestCommonSub(str1.substr(0, n - 1), str2.substr(0, m - 1));
//     }
//     else
//     {
//         int ans1 = longestCommonSub(str1.substr(0, n - 1), str2);
//         int ans2 = longestCommonSub(str1, str2.substr(0, m - 1));
//         return max(ans1, ans2);
//     }
// }

// int lcsMeo(string str1, string str2, vector<vector<int>>& dp) // O(n+m)
// {
//     if (str1.size() == 0 || str2.size() == 0)
//     {
//         return 0;
//     }

//     int n = str1.size();
//     int m = str2.size();

//     if (dp[n][m] != -1)
//     {
//         return dp[n][m];
//     }

//     if (str1[n - 1] == str2[m - 1])
//     {
//         dp[n][m] = 1 + lcsMeo(str1.substr(0, n - 1), str2.substr(0, m - 1), dp);
//     }
//     else
//     {
//         int ans1 = lcsMeo(str1.substr(0, n - 1), str2, dp);
//         int ans2 = lcsMeo(str1, str2.substr(0, m - 1), dp);
//         dp[n][m] = max(ans1, ans2);
//     }

//     return dp[n][m];
// }

int lcsTab(string str1, string str2) // O(n*m)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string str1 = "abc";
    string str2 = "xyc";

    int n = str1.size();
    int m = str2.size();

    

    cout << lcsTab(str1, str2) << endl;
}



