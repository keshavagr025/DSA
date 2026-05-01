#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List{
    public:
    Node* head;

    List(){
        head = nullptr;
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head =  newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "nullptr\n";
    }
};

Node* addTwoNode(Node* l1, Node* l2){
    Node* temp1 = l1;
    Node* temp2 = l2;

    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
        
    }

    if(carry){
        Node* newNode2 = new Node(carry);
        curr->next = newNode2 ;
    }

    return dummyNode->next;
    

}

int main(){
    List ll1, ll2;

    ll1.push_back(5);
    ll1.push_back(4);
    ll1.push_back(1);
    cout << "First List\n";
    ll1.printLL();

    ll2.push_back(7);
    ll2.push_back(6);
    ll2.push_back(12);
    cout << "First List\n";
    ll2.printLL();

    Node* result = addTwoNode(ll1.head, ll2.head);
    cout << "Add the heads of Linked Lists\n";

    while (result != nullptr)
    {
        cout << result->data << "->";
        result = result->next;
    }

    cout << "nullptr\n";
}


