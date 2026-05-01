#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        long long n; 
        cin >> n;

        vector<long long> a(n);   // ✅ FIX
        for (long long i = 0; i < n; i++) 
            cin >> a[i];
        
        long long pos = 0, neg = 0;
        for (long long i = 0; i < n; i++) {
            if (a[i] == 1)
                pos++;
            else
                neg++;
        }

        long long operation = 0;
        while (pos < neg || neg % 2 == 1) {
            operation++;
            pos++;
            neg--;
        }

        cout << operation << "\n";
    }
    return 0;
}
