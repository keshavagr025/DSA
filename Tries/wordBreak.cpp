#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
    public:
    unordered_map<char, Node*> children;
    bool isEndOfWord; 

    Node(){
        isEndOfWord = false;
    }
};

class Trie {
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;
    
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node(); // Insert new node
            }
            temp = temp->children[key[i]]; // Move temp forward in both cases
        }
    
        temp->isEndOfWord = true;
    }
    

    bool search(string key)

    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }

        return temp->isEndOfWord; 
    }
};


bool helper(Trie & trie, string key){
    if(key.size() == 0){
        return true;
    }

    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

    if(trie.search(first) && helper(trie, second)){
        return true;
    }

}
    return false;
}


bool wordBreak(vector<string> dict, string key){
    Trie trie;

    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}

int main(){
    vector<string> words = {"i", "like", "sam", "samsung", "mobile", "ice"};

    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << wordBreak(words, "ilikesung") << endl;
}