#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Queue{  // private data members rakh skte h no need to in main function
    Node* head;
    Node* tail;

    public:

    Queue(){
        head = nullptr;
        tail = nullptr;
    }    
    
    // In LL this is a push_back function
    void push(int data){
        Node* newNode = new Node(data);

        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
   
   // In LL this is a pop_front function
    void pop(){
        if(empty()){
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(empty()){
            cout << "Queue is Empty\n";
            return -1;
        }
        return head->data;
    }
    
    bool empty(){
        return head == nullptr;
    }
};

int main()
{
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