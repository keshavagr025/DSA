#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;   
    }
};

int static idx = -1;

void buildTree(Node*& root, vector<int>& nodes) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return;
    }

    root = new Node(nodes[idx]);
    buildTree(root->left, nodes);
    buildTree(root->right, nodes);
}


bool isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}

void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) {
            temp.push_back(curr->data);
        }
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    if (!isLeaf(root)) {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = NULL;
    buildTree(root, nodes);

    vector<int> boundary = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}