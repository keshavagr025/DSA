#include <bits/stdc++.h>
using namespace std;


// [1,2,1]    a1 + a2 = 3 and a2 + a3 = 3


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i=0; i<n; i++){
            if(a[i] + a[i+1] == a[i+1] + a[i+2]){
                cout << "yes"<< endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}