#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this -> data = data;
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
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            newNode = head;
        }
    }
};

void Printll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void removeCycle(Node *head)
{
    // detect cycle
    Node *slow = head;
    Node *fast = head;

    bool isCycle = false;
    
    // same as both Even and Odd conditions:
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
        {
            cout << "The cycle exit\n";
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        cout << "Cycle doesn't exist\n";
        return;
    }

    slow = head;
    if (slow == fast)
    { // special case : tail -> head
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL; // remove cycle
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL; // remove cycle
    }
}

int main()
{
    List ll;

    ll.Push_Front(4);
    ll.Push_Front(3);
    ll.Push_Front(2);
    ll.Push_Front(1);

    ll.tail->next = ll.head;

    removeCycle(ll.head);
    Printll(ll.head);
}