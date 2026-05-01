#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Queue { // FIFO 
    stack<int> s1;
    stack<int> s2;

    public:

    void push(int data){  // O(n)
        // stack1 -> stack2 
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while(!s2.empty()){
            // stack2 -> stack1
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main()
{
    // queue using two stack

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
