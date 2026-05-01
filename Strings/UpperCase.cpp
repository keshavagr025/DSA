#include<iostream>
#include<cstring>
using namespace std;

void ToUpper(char word[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if(ch >= 'a' && ch <= 'z')
        {
            continue;
        }else
        {
            word[i] = ch + 'a' - 'A';
        }
    }
}

int main()
{
    char word[] = "appLE";
   
       ToUpper(word, strlen(word));
       cout << word << endl;


}