#include <iostream>
using namespace std;

int CheckPalindrome(int n)
{
    
    int result = 0;
    for (int i = n-1; i>=0; i--)
    {
        result++;
    }
    
    if(result == 0)
    {
        cout << "Palindrome is not " << result << endl;
    }else
    {
        cout << " Palindrome is " << result << endl;
    }

}

int main()
{
    CheckPalindrome(121);
}