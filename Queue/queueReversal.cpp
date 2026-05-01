#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int reversal(queue<int> &q)
{
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        q.pop();
    }
}

int main()
{   
    queue<int>q;
    for(int i=1; i<=10; i++){
        q.push(i);
    }

    reversal(q);
    for(int i=1; i<=10; i++){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

}