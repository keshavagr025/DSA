#include <iostream>
using namespace std;
 
int revserNumber(int n)
{
    if( n == 1)   // Base Case / Smaller problem
    {
        return 1;
    }
    cout << n << endl;  //kaam kiya karanaa hai..
    revserNumber(n-1); // assumptions
}
int main()
{
   int ans =  revserNumber(100);
   cout << ans << ",";
}