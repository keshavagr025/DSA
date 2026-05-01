#include <iostream>
#include <stack>
#include <string>
using namespace std;

void pushAtBtm(stack<int>&s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

  int temp = s.top();
  s.pop();
  pushAtBtm(s, val);
  s.push(temp);
    
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
        int temp = s.top();
        s.pop();
        reverseStack(s);
        pushAtBtm(s, temp);
}

void printRev(stack<int> s){
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    cout << endl;
}

int main(){
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printRev(s);

    reverseStack(s);
    printRev(s);
}