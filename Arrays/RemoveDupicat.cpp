#include<iostream>
#include<vector>
using namespace std;

int removeElement( int *nums, int val,int n) {

        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i; 
    }




int main()
{
    
}