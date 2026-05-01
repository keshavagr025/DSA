#include <iostream>
using namespace std;
 
int NaturalNumber(int n)
{
    if( n == 1  )
    {
        return 1;

    }

    return n + NaturalNumber( n - 1);
}
int main()
{
    int ans = NaturalNumber(6);

    cout << ans << endl;
}