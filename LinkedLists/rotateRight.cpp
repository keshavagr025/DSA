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

    void Push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void PrintLL() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

Node* findNthNode(Node* temp, int k) {
    int cnt = 1;
    while (temp != nullptr) {
        if (cnt == k) {
            return temp;
        }
        cnt++;
        temp = temp->next;
    }
    return nullptr; // Return nullptr explicitly if not found
}

Node* rotateRight(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    Node* tail = head;
    int len = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    if (k % len == 0) {
        return head;
    }

    k = k % len;
    tail->next = head;

    Node* newTail = findNthNode(head, len - k);
    if (newTail == nullptr) {
        return head; // Safety check
    }

    head = newTail->next;
    newTail->next = nullptr;

    return head;
}

int main() {
    List myList;

    myList.Push_front(5);
    myList.Push_front(4);
    myList.Push_front(3);
    myList.Push_front(2);
    myList.Push_front(1);

    cout << "Original List: ";
    myList.PrintLL();

    myList.head = rotateRight(myList.head, 2);

    cout << "Rotated List: ";
    myList.PrintLL();

    return 0;
}
