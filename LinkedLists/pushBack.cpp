#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
void Push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

        void PrintNode(){
        Node* temp = head;
        while( temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};



int main()
{
    List ll;

    ll.Push_back(5);
    ll.Push_back(4);
    ll.Push_back(3);
    ll.Push_back(2);
    ll.Push_back(1);

    ll.PrintNode();
}