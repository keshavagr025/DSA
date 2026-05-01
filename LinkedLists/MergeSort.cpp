#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
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

public:
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

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

Node *splitMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prv = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prv = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prv != NULL)
    {
        prv->next = NULL; // split
    }

    return slow; // righthead
}

Node *merge(Node *left, Node *right)
{
    List ans;
    Node *i = left;
    Node *j = right;

    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    { // base case:
        return head;
    }

    Node *rightMerge = splitMid(head);

    Node *left = mergeSort(head);
    Node *right = mergeSort(rightMerge);

    return merge(left, right);
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
    }
    
    return prev;    // prev is head of reversed LL
}

// Node* zigZag(Node* head){

//     Node* rightHead = splitMid(head);
//     Node* rightHeadRev = reverse(rightHead);

//     //alternate merging : 1sthead = head; 2nd head = rightHeadRev

//     Node* left = head;
//     Node* right = rightHeadRev;
//     Node* tail = right;

//     while (left != NULL && right != NULL){
//         Node* nextLeft = left->next;
//         Node* nextRight = right->next;
        

//         left->next = right;
//         right->next = nextLeft;

//         tail = right;

//         left = nextLeft;
//         right = nextRight;
//     }

//     if(right != NULL){
//         tail->next = right;
//     }
    
//     return head;
// }

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(1);

    printLL(ll.head);
    ll.head =  mergeSort(ll.head);
    printLL(ll.head);
}
