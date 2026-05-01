#include <iostream>
#include <string>
using namespace std;

void SumOfString( string s)
{
    int n = s.length();
    int st = 0, e = 1;
    int sum = 0;
    for(char i = 0; i<s ;i++)
    {
         sum += st[i] - e[i+1];
    }
    cout << sum;
}

int main()
{
    string s = "hello";

    SumOfString(s);

}