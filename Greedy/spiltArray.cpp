#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main(){
    int arr[5] = {7, 2, 5, 10, 8};
    int n = 5;

    int k = 2;

    int mid = n/k;
    int ans1 = 0, ans2 = 0;
    
    for(int i=0; i<mid+1; i++){
        ans1 += arr[i];
    }

    for(int i=mid+1; i<n; i++){
        ans2 += arr[i];
    }

cout << ans1 << " " << ans2 << endl;
}