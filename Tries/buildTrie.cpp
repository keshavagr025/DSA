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
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie;

}