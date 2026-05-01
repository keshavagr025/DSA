#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter n,m" << endl;
    cin >> n;
    cout << "m" << endl;
    cin >> m;

    int ar[n], ar1[m];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    for(int i=0; i<m; i++){
        cin >> ar1[i];
    }

       sort(ar.begin() , ar.end());
       sort(ar1.begin(), ar1.end());

    vector<int> temp;

    int a = 0, b = 0;

    while( a < ar[n] && b < ar1[m]){
        if(ar[a] < ar1[b]){
            a++;
        }else if(ar[a] > ar1[b]){
            b++;
        }else
        {
            temp.push_back(ar[a]);
            a++; b++;
        }
    }

    for(int i=0; i<temp.size(); i++){
        cout << temp[i] << endl;
    }
}
