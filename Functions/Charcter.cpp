#include<iostream>
using namespace std;

char Alphabet(char ch)
{
    if(ch == 'z')
    {
        return 'a';
    }else 
    {
        return ch + 1;
    }
}

int main()
{
    Alphabet('b');

}