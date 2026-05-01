#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        } 
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<long long> best(n);
        best[n - 1] = b[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            best[i] = max(b[i], best[i + 1]);
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + best[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << pref[r + 1] - pref[l] << " ";
        }
        cout << "\n";
    }
    return 0;
}
