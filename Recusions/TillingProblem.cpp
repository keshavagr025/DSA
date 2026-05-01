#include <iostream>
using namespace std;

int tillingProblem(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return tillingProblem(n - 1) + tillingProblem(n - 2);
}
int main()
{
    cout << tillingProblem(5) << endl;
}