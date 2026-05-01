#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int climbingStairsRecusi(int n){

    if(n == 0 || n == 1){
        return 1;
    }


    return climbingStairsRecusi(n-1) + climbingStairsRecusi(n-2);
}

int  climbingStairsMemo(int n, vector<int> dp){ // O(n)
    
    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = climbingStairsMemo(n-1, dp) +  climbingStairsMemo(n-2, dp);

    return dp[n];
}

int climbTablu(int n){

    vector<int> dp(n+1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    if(n == 0 || n == 1){
        return n;
    }

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}


int main(){
    int n = 9;

    vector<int> dp(n + 1,1);

    //cout <<  climbingStairsMemo(n, dp) << endl;

    cout <<  climbTablu(n) << endl;
    return 0;
}