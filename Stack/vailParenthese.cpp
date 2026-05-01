#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isvalid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        // opening brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        { // closing
            if (s.empty())
            {
                return false;
            }

            // matching condition
            int top = s.top();
            if ((top == '(' && ch == ')') ||
                (top == '[' && ch == ']') ||
                (top == '{' && ch == '}'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string str1 = "([{}])";

    cout << isvalid(str1) << endl;

    return 0;
}