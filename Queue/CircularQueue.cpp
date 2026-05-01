#include <iostream>
using namespace std;

class Queue {
    public:
    int *arr;

    int capacity;
    int currSize;

    int front, rear;

    public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;

        front = 0;
        rear = -1;
    }

    void push(int data){
        if(currSize == capacity){
            cout << "Queue is Full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data; // updation of elements
        currSize++;
    }

    ~Queue(){
        cout << "Destructor called" << endl;
        delete[] arr;
    }

    void pop(){
        if(empty()){
            cout << "Queue is EMPTY\n";
            return;
        }
        front = (front + 1)% capacity;
        currSize--;
    }

    int frontElement(){
        if(empty()){
            cout << "Queue is EMPTY\n";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        return currSize == 0;
    }

    // Checked it is true or not 
    void checkRear(){
        cout << arr[rear] << endl;
    }
};


int main()
{
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); 

    cout << q.frontElement() << endl;
    q.pop();
    cout << q.frontElement() << endl;
    q.push(5);
    cout << q.frontElement() << endl;

    q.checkRear();

    return 0;
}