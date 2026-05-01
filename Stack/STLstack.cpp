#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main()
{
    stack<string> s;

    s.push("abc");
    // s.push("");
    // s.push("");

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}