#include <iostream>
#include <vector>

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

void swapNode(Node* head){
    vector<int> ans;
    Node* temp = head;

    ans.push_back(temp->data);

    return ans;
}

int main() {
    List ll;

    ll.Push_back(5);
    ll.Push_back(4);
    ll.Push_back(3);
    ll.Push_back(2);
    ll.Push_back(1);
    ll.printLL();

    ll.swapNode()
}
