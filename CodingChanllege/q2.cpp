#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    double curT = 0.5, curM = 0.5;
    double consT = 0.0, consM = 0.0;

    for (char c : s) {
        // consume half
        consT += curT * 0.5;
        consM += curM * 0.5;

        curT *= 0.5;
        curM *= 0.5;

        // refill
        if (c == 'H') curT += 1.0;
        else curM += 1.0;
    }

    const double EPS = 1e-9;
    if (fabs(consT - consM) < EPS) cout << "HM\n";
    else if (consT > consM) cout << "H\n";
    else cout << "M\n";

    return 0;
}
