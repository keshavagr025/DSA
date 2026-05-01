#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int orgi = n;

    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact*i;
    }
    
    int sum = 0;

    while( fact > 0)
    {
        int lastD = fact %10;
        sum = sum + lastD;
        fact = fact/10;
    }

    if(sum == orgi)
    {
        cout << "1";
    }else
    {
        cout << "@" << endl;
    }


    
}