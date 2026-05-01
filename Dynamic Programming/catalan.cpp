#include <bits/stdc++.h>
using namespace std;


int catalanNumberRec(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += catalanNumberRec(i) * catalanNumberRec(n-i-1);
    }

    return ans;
}

/************************************************************************************************************************************************/

int catalanNumberMemo(int n, vector<int> &dp){
    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += catalanNumberMemo(i, dp) * catalanNumberMemo(n-i-1, dp);
    }
    
    

    return dp[n] = ans;
}


int catalanTab(int n){
 vector<int> dp(n+1, 0);
    dp[0] =  dp[1] = 1;

    int ans = 0;

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
           dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){
    int n = 4;

    for(int i=0; i<=6; i++){
        cout << catalanTab(i) << " ";
    }

    cout << endl;
   
}