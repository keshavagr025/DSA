#include<iostream>
#include<string>
using namespace std;

bool Parentheses(string s)
{
    if(s == "{}" || s == "[]" || s == "()")
    {
       return true;
    }else if(s == "()[]{}" || s == "[](){}" || s == "[]{}()" || s == "{}[]()" || s == "{}()[]" || s == "[](){}")
    {
        return true;
    }else 
    {
        return false;
    }
}

int main()
{
    string s = "{}";

    Parentheses(s);
    
}