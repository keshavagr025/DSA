#include <iostream>
#include <vector>
#include <string>
#include <list> //Lists are sequence containers that allow non-contiguous memory allocation.
using namespace std;
// With STL list
// template <class T>
// class Stack
// { 
//     list<T> ll;
//    public:
//     void push(T val)
//     {
//         ll.push_front(val);
//     }

//     void pop()
//     {
//         ll.pop_front();
//     }

//     T top()
//     {
//         return ll.front();
//     }
 
//     bool isEmpty(){
//         return ll.size() == 0;
//     }
// };

// Without STL list class
 
template<class T>

class Node {
    public:
    T data; 
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T >
class Stack { 
    Node<T>* head;
  public: 
    Stack(){
        head = NULL;
    }
    void push(T val){
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top(){
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};
int main()
{
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
}