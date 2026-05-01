
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(root->data > val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
}

class info {
    public:
    bool isBst;
    int min;
    int max;
    int sz;

    info(bool isBst, int min, int max, int sz){
        this->isBst = isBst;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxSize;

info* largestBst(Node* root){
    
    // Base case 1
    // if(root == NULL){
    //     return  new info(true, INT16_MAX, INT16_MIN, 0);
    // }

    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right){
         return new info(true, root->data, root->data, 1);
    }

   info* leftInfo = largestBst(root->left);
   info* rightInfo = largestBst(root->right);
   

   int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
   int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
   int currSz = leftInfo->sz + rightInfo->sz + 1;

   if(leftInfo->isBst && rightInfo->isBst
      && root->data > leftInfo-> max 
      && root->data < rightInfo->min ){
        maxSize = max(maxSize, currSz);
       return new info(true, currMin, currMax, currSz);
      }

       return new info(false, currMin, currMax, currSz);
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){

        root = insert(root, arr[i]);
    }

    return root;
}


int main(){  
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBst(root);
    cout << "max Size" << maxSize << endl;
    return 0;
}