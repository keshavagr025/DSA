#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a numebr" << endl;
    cin >> n;

    int orginalNumer = n;
    int result = 0;
    int lastDigit;
    while(n>0)
    {
        lastDigit = n%10;
        result = result + lastDigit*lastDigit;
        n = n/10;
        n = result;
    }
      
     cout << result;
    return -1;
    // if(result == orginalNumer)
    // {
    //     cout << "Its a Armstrong Number  = " << result << endl;
    // }else
    // {
    //     cout << "Not a Armstrong Number  = " << result << endl;
    // }

}