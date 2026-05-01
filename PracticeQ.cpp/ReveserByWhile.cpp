#include<iostream>
using namespace std;

int main()
{
    int n = 123;

    int dig = 0;

    while(n>0)
    {
        int lastDigit = n%10;
        dig = dig + lastDigit; 
        cout << dig;
        break;
    }

    return 0;
}