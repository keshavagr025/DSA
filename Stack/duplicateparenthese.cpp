#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
 
bool isDupilcate(string str){
    stack<char> s;
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
        // non-closing character
        if(ch != ')'){
            s.push(str[i]);
        }else{
            // find duplicate
            if(s.top() == '('){
                return true;
            }

            while(s.top() != '('){
                s.pop();
            }

            s.pop();
        }
    }

    return false;
    
}
 
int main(){

    string str = "(a+b())";

    cout << isDupilcate(str) << endl;
}