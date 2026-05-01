// A scientist named Arin is experimenting with an automated beverage mixer.

// Initially, a cup is filled so that half of it contains tea and the other half contains milk.

// A control string s
//  of length n
//  is provided, consisting only of the characters H and M. The experiment is performed according to the following procedure.

// For each i=1
//  to n
// , in order:

// exactly half of the liquid currently in the cup is consumed;
// if si=H
// , the cup is refilled completely with tea;
// if si=M
// , the cup is refilled completely with milk;
// the contents of the cup are mixed uniformly.
// After all n
//  operations are finished, the remaining liquid in the cup is discarded.

// Arin wants to know which ingredient he consumed in greater total amount during the entire experiment.

// Your task is to determine whether more tea or more milk was consumed.

// Input
// The first line contains an integer n
//  (1≤n≤100000)
// .

// The second line contains a string s
//  of length n
// , consisting only of the characters H and M.

// Output
// Print:

// H if more tea was consumed;
// M if more milk was consumed;
// HM if equal amounts of tea and milk were consumed.
// Example
// InputCopy
// 5
// HMHHM
// OutputCopy
// H
// Note
// Arin has consumed 13764
//  teacups of tea and 5964
//  teacups of milk in total.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; 
    
    string s = "HMHHM";

    double tea = 0.0, milk = 0.0;
    double curr = 0.5;

    for (char c : s) {
        if (c == 'H') {
            tea += curr;
        } else {
            milk += curr;
        }
        curr /= 2.0;
    }

    if (tea > milk) {
        cout << "H" << endl;
    } else if (milk > tea) {
        cout << "M" << endl;
    } else {
        cout << "HM" << endl;
    }

    return 0;
}