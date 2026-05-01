#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter n number" << endl;
    cin >> n;

    int sum = 0;
    int result = 0;

    while(n>0)
    {
        int lastdig = n%10;
        result = result * 10 + lastdig;
        n /= 10;
    }

    cout << result << endl;
}