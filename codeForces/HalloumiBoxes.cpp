#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n, k;
        cin >> n >> k;
        vector<long long> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<long long> copyArr = a;

        sort(copyArr.begin(), copyArr.end());

        if(copyArr == a || k > 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}