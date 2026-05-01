#include <iostream>
#include <vector>

using namespace std;

int fibo(int n){  // O(2^n)
    if(n == 0 || n == 1){
        return n;
    }


    return fibo(n-1) + fibo(n-2) + fibo(n-3);
}


int fiboDp(int n, vector<int> dp){ // O(n)
    
    if(n == 0 || n == 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fiboDp(n-1, dp) + fiboDp(n-2, dp);

    return dp[n];
}


int fibTab(int n){
    vector<int> fibo(n + 1, 0);

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    } 

    return fibo[n];
}

int main(){
    int n = 6;
    cout << "Enter the numbers" << endl;
    vector<int> dp(n+1, -1);

    cout << fibo(n) << endl;
}