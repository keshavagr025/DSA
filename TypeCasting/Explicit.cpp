#include<iostream>
using namespace std;
int main()
{
    // in explicitly
    cout << (int) ('A' - 1) << endl;
    cout << (char)('A'+ 5) << endl;

    // bool gives a value 0,1
    cout << ((bool)3 + 2) << endl;

    cout << (23.5 + 2 + 'A') << endl;  // inplicitly:
}