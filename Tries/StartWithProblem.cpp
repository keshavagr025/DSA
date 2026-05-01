#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEndOfWord;

    Node()
    {
        isEndOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
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

    bool startWith(string prefix)
    { // Returns true if there is any string in the trie that starts with the given prefix.
        // Time complex O(L);
        Node *temp = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children[prefix[i]])
            {
                temp = temp->children[prefix[i]];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie;

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    cout << "Answer = " << trie.startWith("ops") << endl;
}