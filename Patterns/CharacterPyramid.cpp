#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    char str = 'A';

    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            cout << str++;
        }
        cout << endl;
    }

    return 0;
}