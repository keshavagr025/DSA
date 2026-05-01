#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string key;
    int val;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable
{
    int totSize;
    int currSize;
    Node **table;

    int hashFunction(string key){
        int idx = 0;

        for(int i=0; i<key.size(); i++){
            idx = idx + (key[i] * key[i])% totSize;
        }

        return idx%totSize; 
    }

    void rehash(){ //O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        currSize = 0; // this use becz the oldsize the lambda funtion is work and rehashing take more time
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }

        //copy old values

        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            // delete old values of tables head
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        } 

        delete [] oldTable;
    }


public:
    hashTable(int size = 5)
    {
        totSize = size;
        currSize = 0;

        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }
    }

    // they all are in O(1)complexity

    void insert(string key, int val)
    { 
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

       newNode->next =table[idx];
       table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;

        if(lambda > 1){
            rehash();
        }
     }

    bool exists(string key){
        int idx = hashFunction(key);
        
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int search(string key)
    {
        int idx = hashFunction(key);
        
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return temp->val;
            }

            temp = temp->next;
        }

        return -1;   
    }

    void print(){
        
        for(int i=0; i<totSize; i++){
            cout << "idx" << i <<"->";
            Node* temp = table[i];
            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ") ->";
                temp = temp->next;
            }
            cout << endl; 
        }
    }
};

int main()
{
    HashTable th;

    th.insert("india", 150);
    th.insert("china", 200);
    th.insert("nepal", 900);
    th.insert("Bhutan", 700);
    th.insert("uk", 600);
    th.print();

    // if(th.exists("Bhutan")){
    //     cout << "Bhutan population " << th.search("Bhutan") << endl;
    // }


    return 0;
}