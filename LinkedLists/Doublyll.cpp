#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;    // 1 <-> 2 <-> 3  

    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList
{
public:
    Node *head;
    Node *tail;

    DoublyList()
    {
        head = tail = nullptr; // Empty Linked list:
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

     void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail->prev = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        temp->next = nullptr;
        delete temp;
    }

     void pop_back()
    {
        Node *temp = head;
        head = head->next;

        if (tail != nullptr)
        {
            tail->prev = nullptr;
        }

        temp->next = nullptr;
        delete temp;
    }

    void printList()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    DoublyList dbll;

    dbll.push_back(5);
    dbll.push_back(4);
    dbll.push_back(3);
    dbll.push_back(2);
    dbll.push_back(1);

    dbll.printList();

    dbll.pop_back();
    dbll.printList();
    return 0;
}