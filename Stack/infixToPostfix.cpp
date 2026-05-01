// Prefix = *+ab-mn
// Infix = (p+q)*(m-n)
// postfix = pq+mn-*



#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int precedor(char c){
    if(c == '^'){
        return 3;
    }else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string ans;

    for(int i = 0; i < s.length(); i++){
        // check if the character is an operand
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            ans += s[i];
        }
        // check if the character is an opening bracket
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // check if the character is a closing bracket
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        // if the character is an operator
        else{
            while(!st.empty() && precedor(st.top()) >= precedor(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // pop all the remaining operators from the stack
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
   
    return ans;
}

int main(){
    string a = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(a);

    return 0;
}
