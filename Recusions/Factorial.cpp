#include <iostream>
using namespace std;

int Fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * Fact(n - 1);
}
int main()
{
    int ans = Fact(10);

    cout << ans << endl;
}