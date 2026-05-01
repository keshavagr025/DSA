#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// opening to closing 
// closing to opening

int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    int n = s.length();

    stack<char> st;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i]) >= '0' && s[i] <= '9')
        {
            ans += s[i];
        }

        else if (s[i] == ')')
        {
            st.push(s[i]);
        }

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main()
{
    string a = "(a-b/c)*(a/k-l)";
    cout << InfixToPrefix(a);
    return 0; 
}