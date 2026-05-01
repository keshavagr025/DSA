#include <iostream>
using namespace std;

int main() {
    int n = 5; // Example number to check
    
    int mns = n - 1;
    if (n > 0 && (n & mns) == 0) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0; 
}