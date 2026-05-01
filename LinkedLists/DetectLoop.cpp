#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void Push_front(int val)
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

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Cycle of Flyod's

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // this condition for both even & odd:
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // +1
        fast = fast->next->next; // +2
        if (slow == fast)
        {
            cout << "cycle is exist\n";
            return true;
        }
    }

    cout << "Cycle is not exist\n";
    return false;
}

int main()
{
    List ll;

    ll.Push_front(4);
    ll.Push_front(3);
    ll.Push_front(2);
    ll.Push_front(1);

    ll.tail->next = ll.head;

    isCycle(ll.head);
}