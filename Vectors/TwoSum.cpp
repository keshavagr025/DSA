#include <iostream>
#include <vector>
using namespace std;

vector<int> PairSum( vector<int>arr, int target)
{
      int s = 0, e = arr.size() - 1;
        int currSum = 0;
        vector<int> ans;

        while (s < e) {
            currSum = arr[s] + arr[e];
            if (currSum == target) {
                ans.push_back(s+1);
                ans.push_back(e+1);
                return ans;
            } else if (currSum > target) {
                e--;
            } else {
                s++;
            }
        }
        return ans;
    }


int main()
{
    vector<int> arr = {2,7,5,4,3,1,1};
    int target = 9;

   vector<int> ans =  PairSum(arr, target);

   cout << ans[0] << " " << ans[1];
}