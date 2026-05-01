#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool checkPalindrome(vector<int> nums){
    int n = nums.size();
    stack<int> st(n);

    int s = 0;
    int e = s.size();

    while(s < e){
        if(nums[s] != st.top()){
            return false;
        }else{
            s++; e--;
        }
    }
}
 
int main(){
}