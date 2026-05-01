#include <iostream>
#include <cmath>
using namespace std;
 
int FuncName(int a, int b)
{
    if( b == 0)
    {
        return 1;
    }

    int halfPow = pow(a,b/2);
    int halfPowSq = halfPow * halfPow;

    if( b % 2 != 0)
    { // odd
        return a * halfPow;
    }

    return halfPowSq;
}
int main()
{
    int ans = FuncName(2,10);
    cout << ans << endl;
}