#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List {
    public:
    Node* head;
    Node* tail;

    public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void Push_back(int val){
        Node* newNode = new Node(val);

        if( head == nullptr){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void printll(){
        Node *temp = head;
        while( temp != nullptr){
            cout << temp ->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos){
        Node *newNode = new Node(val);

        Node* temp = head;

        // we check the position on it:
        for (int i = 0; i < pos-1; i++)
        {
            // corner case:
            if( temp == NULL){
                cout << "Invaild\n";
                return;
            }

            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main(){
    List ll;

    ll.Push_back(4);
    ll.Push_back(3);
    ll.Push_back(2);
    ll.Push_back(1);

    ll.printll();

    ll.insert(100,3);
    ll.printll();
}

