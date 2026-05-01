#include <iostream>
#include <string>
using namespace std;
 
int CountSubStr(string str, int i, int j, int n)
{
    if( n == 1)
    {
        return 1;
    }
    if( n <=0)
    {
        return 0;
    }

   int res = CountSubStr(str, i + 1, j, n - 1) + 
     CountSubStr(str, i, j - 1, n - 1) -
     CountSubStr(str, i + 1, j - 1, n - 2);

    if(str[i] == str[j])
    {
        res++;
    }

    return res;
}
int main()
{
    string str = "abcab";
    int n = str.size();

    cout << CountSubStr(str, 0, n-1, n) << endl;
}