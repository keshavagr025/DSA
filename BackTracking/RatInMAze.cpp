#include <iostream>
#include <vector>

using namespace std;

int RatInMaze(vector<vector<int>> nums, int row, int col, int n, int ans){
    if(nums[row][col] == n-1){
        cout << ans;
    }

    if(row  == n || col == n){
        return 0;
    }

    vector<int> r1 = RatInMaze(   )
}