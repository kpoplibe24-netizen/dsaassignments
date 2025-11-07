#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left, data);
    }
    else if(root->right < data){
        root->right=insert(root->right, data);
    }
    return root;
}
Node* searchR(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchR(root->left, key);
    else
        return searchR(root->right, key);
}
Node* searchI(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
