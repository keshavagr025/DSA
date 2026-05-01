#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int rodCutting(vector<int> price, vector<int>len, int rodLength){
    int n = len.size();
    vector<vector<int>> dp(n+1, vector<int> (rodLength+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<rodLength+1; j++){
            int itmPrice = price[i-1];
            int itmLen = len[i-1];
            if(itmLen <= j){
                dp[i][j] = max(itmPrice + dp[i][j-itmLen] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<rodLength; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;
    cout << "Max profit is = ";
    return dp[n][rodLength];
}

int main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};

    int rodlength = 8;

    cout << rodCutting(price, len, rodlength) << endl;
}