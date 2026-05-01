#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int n = 11;
// Right most bit login 

    if(!(n & 1)){
        cout << "The number " << n << " is even" << endl;
    } else {
        cout << "The number " << n << " is odd" << endl;
    }
}