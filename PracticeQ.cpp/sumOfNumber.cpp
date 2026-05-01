#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter a number n" << endl;

    cin >> n;
    int sum = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        if (lastdigit % 2 != 0)
        {
            sum = sum + lastdigit;
        }
        n = n / 10;
    }

    cout << "Sum of Odd Ones = " << sum << endl;
}