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

    List(){
        head = nullptr;
        tail = nullptr;
    }

  void Push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
           newNode->next = head;
           head = newNode;
        }
    }


   void Insert_Middle(int val, int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            // corner cases
            if(temp == NULL){
                cout << "Position is Invaild\n";
                return;
            }
            temp = temp -> next;   
        }
        
        // temp is now pos-1 i.e prev/left;
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};

int main (){
    List ll;

    ll.Push_front(4);
    ll.Push_front(3);
    ll.Push_front(2);
    ll.Push_front(1);
    ll.print();
    cout << endl;
    ll.Insert_Middle(0,0);
    ll.print();


}