#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Stack {
    public:
    vector< T > vec;

    public:
    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    T top(){

        // if(isEmpty()){
        //     cout << "Stack is empty\n";
        // return;
        // }
        int lasIdx = vec.size() - 1;
        return vec[lasIdx]; 
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack<string> s;
    
    s.push("with me");
    s.push("cpp");
    s.push("learn");
    
    
  

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}