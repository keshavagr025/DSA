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

    void Push_Front(int val)
    {
        // to create a newNode
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void PrintLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    List ll;

    ll.Push_Front(5);
    ll.Push_Front(4);
    ll.Push_Front(3);
    ll.Push_Front(2);
    ll.Push_Front(1);
     ll.Push_Front(3);
    ll.Push_Front(2);
    ll.Push_Front(1);   
    ll.PrintLL();
}