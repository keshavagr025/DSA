#include <iostream>
using namespace std;
 
int FuncName(int n)
{
    if( n == 0 || n == 1)
    {
        return n;
    }

    return  FuncName(n-1) + FuncName(n-2);
}
int main()
{
    int ans = FuncName(7);

    cout << ans << " ";
}