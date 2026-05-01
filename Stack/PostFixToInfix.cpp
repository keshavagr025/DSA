#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string PostfixToInfix(string s)
{
    int n = s.length();
    stack<string> st;

    int i = 0;

    for(int i=0; i<n; i++){
        // operand
        if((s[i] >= 'A' && s[i] <= 'Z')||
           (s[i] >= 'a' && s[i] <= 'z')||
           (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1,s[i])); 
           }

           // operator

           else{
            string t1 = st.top(); // t1 is stack is b
            st.pop();
            string t2 = st.top();   // t2 in stack is a
            st.pop();
            
            // s[i] is operator btw two operands
            string con = '(' + t2 + s[i] + t1 + ')';  //  ( a + b) like that
            st.push(con);
           }
          
    }

    return st.top();
}
 
int main(){
    string ans = "ab-de+f*/";

    cout << PostfixToInfix(ans) << endl;
}