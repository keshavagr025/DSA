#include<iostream>
using namespace std;

void BinaryTODecimal(int n)
{
    int binNum = n; // To store the original number:
    int decNum = 0;
    int pow = 1;

    while(n>0)
    {
        // I know to find last digit:
        int lastD = n%10;
        decNum += lastD * pow;
        pow = pow * 2; // Update Power 
        n /= 10;
    }
    
    cout << decNum << endl;
}

void DecimalToBinary(int n)
{
    int BinaryNum = n;
    int Binary = 0;
    int pow = 1;

    while(n > 0)
    {
        int rem = n % 2;
        Binary += rem * pow;
        n = n/2;
        pow = pow * 10;
    }

    cout << Binary << endl;
}



int main()
{
    BinaryTODecimal(10100);
    DecimalToBinary(4);
}