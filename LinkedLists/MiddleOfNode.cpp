#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void Push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "nullptr\n";
    }
};

// 1->2->3->4->5->  middle is 3  Time complexcity is O(n+n/2) Space complexcity is O(1)

Node* middleElement(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    
    int middleIndex = cnt / 2;
    temp = head;

    for (int i = 0; i < middleIndex; ++i) {
        temp = temp->next;
    }

    return temp;
}
 
// tortoise and hare algorithum 
Node* slowFastTrick(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
    
}

int main() {
    List ll;

    ll.Push_back(5);
    ll.Push_back(4);
    ll.Push_back(3);
    ll.Push_back(2);
    ll.Push_back(1);
    ll.printLL();

    Node* middle = slowFastTrick(ll.head);
    if (middle != nullptr) {
        cout << "Middle element is: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

}
