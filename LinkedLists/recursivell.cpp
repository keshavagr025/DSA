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

    void helper(int temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }

        if (temp->data == key)
        {
            return 0;
        }

        idx = helper(temp->next, key);

        if (idx == -1)
        {
            return -1;
        }

        return idx + 1;
    }

    void serachRec(int key)
    {
        helper(head,key);
    }

    void PrintNode()
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

    ll.Push_front(5);
    ll.Push_front(4);
    ll.Push_front(3);
    ll.Push_front(2);
    ll.Push_front(1);

   cout << ll.serachRec(2) << endl;
}