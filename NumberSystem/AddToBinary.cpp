#include<iostream>
using namespace std;

void Binary1(int n)
{
    int binary = n;
    int Bin = 0;
    int pow = 1;

    while(n > 0)
    {
        int rem = n%2;
        Bin += rem * pow;
        n = n/2; 
        pow = pow * 10;
    }

    cout << Bin << endl;

}

void Binary2(int m)
{
    int binary = m;
    int Bin2 = 0;
    int pow = 1;

    while(m > 0)
    {
        int rem = m%2;
        Bin2 += rem * pow;
        m = m/2; 
        pow = pow * 10;
    }

    cout << Bin2 << endl;

}

void AddBinary()
{
     
}


int main()
{
    AddBinary();

}