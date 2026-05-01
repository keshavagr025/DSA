#include <iostream>
#include <cstring>
using namespace std;

// o(n/2);
bool ValidPalindrome(char word[], int n)
{
    int str = 0;
    int end = n - 1;
    while (str < end)
    {
        if (word[str++] != word[end--])
        {
            cout << "Not" << endl;
            return false;
        }
    }
    return true;
    cout << "its Palindrome" << endl;
}

int main()
{
    char word[] = "aabbaa";
    ValidPalindrome(word, strlen(word));
    cout << word;
}