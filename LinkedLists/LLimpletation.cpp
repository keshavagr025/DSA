#include <iostream>
using namespace std;

// Collection of node are linked list.

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

    ~Node(){
        cout << "Node  " << data << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
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

    ~List(){
        cout << "The List destructor Called" << endl;  
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void Push_front(int val)
    {

        Node* newNode = new Node(val); // dynamically the memory was not deleted  

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode -> next = head;
            head = newNode;
        }
    }

    // void Push_back(int val){
    //     Node* newNode = new Node(val);

    //     if(head == NULL){
    //         head = tail = newNode;
    //     }else{
    //         tail -> next = newNode;
    //         tail = newNode;
    //     }
    // }

    // void Insert_Middle(int val, int pos){
    //     Node* newNode = new Node(val);
    //     Node* temp = head;
    //     for (int i = 0; i < pos-1; i++)
    //     {
    //         // corner cases
    //         if(temp == NULL){
    //             cout << "Position is Invaild\n";
    //             return;
    //         }
    //         temp = temp -> next;   
    //     }
        
    //     // temp is now pos-1 i.e prev/left;
    //     newNode -> next = temp -> next;
    //     temp -> next = newNode;
    // }

    // void Pop_front(){
    //     cout << "To delete the First element of Head " << endl;
        
    //     if(head == NULL){
    //         cout << "LL is empty" << endl;
    //     }

    //     Node* temp = head;

    //     head = head -> next;

    //     // to remove the node of head
    //     temp -> next = NULL;

    //     delete temp;
    // }

    // void Pop_back(){
    //     Node* temp = head;

    //     while(temp -> next -> next != NULL){
    //         temp = temp -> next;
    //     }

    //     temp -> next = NULL;
    //     delete tail;
    //     tail = temp;
    // }

    // int helper(Node* temp , int key){
    //     if(temp == NULL){
    //         return -1;
    //     }

    //     if(temp -> data == key){
    //         return 0;
    //     }

    //     int idx = helper(temp -> next,  key);
    //     if (idx == -1)
    //     {
    //         return -1;
    //     }
        
    //     return idx + 1;
    // }

    // int searchRec(int key){
    //     return helper(head, key);
    // }

    void PrintNode(){
        Node* temp = head;
        while( temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL)
        {
            Node* next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }
        
        head = prev;
    }

    // int getSize(){
    //     int sz = 0;
    //     Node* temp = head;

    //     while (temp != NULL){
    //         temp = temp->next;
    //         sz++;
    //     }
        
    //     return sz;
    // }
    // void removeNth(int n){
    //     int size = getSize();
    //     Node* prev = head;
    //     for (int i = 1; i < (size - n); i++)
    //     {
    //         prev = prev->next;
    //     }
        
    //     Node* toDel = prev->next;
    //     cout << "Going to delete " << toDel->data << endl;
    //     prev->next = prev->next->next;
    // }
};

int main()
{
    List ll;
    ll.Push_front(5);
    ll.Push_front(4);
    ll.Push_front(3);
    ll.Push_front(2);
    ll.Push_front(1);
    ll.PrintNode();
  
//   ll.removeNth(2);
    ll.reverse();
    ll.PrintNode();
    return 0;
}