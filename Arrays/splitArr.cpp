#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, s;
    cout << "Enter the values " << endl;
    cin >> n;
    cout << "Enter the postion" << endl;
    cin >> s;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int pov = 1;
    int neg = -1;

    for(int i=0; i<n; i++){
        pov += arr[i];
        neg -= arr[i];
    }

    int ans = 0;
    ans += min(pov, neg);

    if(ans <= 0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }

}
