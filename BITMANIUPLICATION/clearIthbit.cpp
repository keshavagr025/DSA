#include <iostream>
using namespace std;

int main(){
    int n = 6;
    int i = 1;
    int bitMask = ~(1 << i);

    cout << (n & bitMask) << endl;

    
    // int n = 15;
    // int i = 2;
    // int bitMask = ((~0) << i);
    // cout << (n & bitMask)  << endl;

} 