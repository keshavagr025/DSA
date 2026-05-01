#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int ThreeSum(int *arr, int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int  j = i+1; j < n; j++)
        {
            for (int k = j+1; k<n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp (arr[i] , arr[j] , arr[k] );
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans ;
    
}


int main()
{
    int arr[] = {-1,0,1,2,-1,-4};
    int n = sizeof(arr)/sizeof(int);

    ThreeSum(arr, n);
}