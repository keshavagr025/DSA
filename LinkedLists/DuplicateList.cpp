#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
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

    void printList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
Node *removeDuplicate(Node *head)
{
    if (!head)
    {
        return head;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;

            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}
int main()
{
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printList();
    Node *result = removeDuplicate(ll.head);
    while (result != nullptr)
    {
        cout << result->data << "->";
        result = result->next;
    }
    cout << "nullptr\n";
}