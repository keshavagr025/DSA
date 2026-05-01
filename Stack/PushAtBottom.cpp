#include <iostream>
#include <stack>
using namespace std;

void pushAtBttm(stack<char>&s, char val){
    if(s.empty()){
        s.push(val);
       return;
    }

    char temp = s.top();
    s.pop();
    pushAtBttm(s, val);
    s.push(temp);
}

int main(){
    stack<char> s;

    s.push('c');
    s.push('b');
    s.push('a');
    cout << "Without adding element "<< " ";
    stack<char> temp = s;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    pushAtBttm(s,'d');
    cout << "Adding by element" << " ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
   
}