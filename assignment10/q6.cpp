#include<iostream>
using namespace std;
#define MAX 1000
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
class Solution {
    bool hashTable[MAX]; 

    public:
    Solution() {
        for (int i = 0; i < MAX; i++)
            hashTable[i] = false;
    }
    bool hasDuplicateHash(Node* root){
        if(root==NULL) return false;

        if(hashTable[root->data]){
            return true;
        }
        hashTable[root->data]=true;

        return hasDuplicateHash(root->left) || hasDuplicateHash(root->right);
    }

};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(2);  // duplicate value

    // Create solution object and check for duplicates
    Solution sol;

    if (sol.hasDuplicateHash(root))
        cout << "Duplicates Found" << endl;
    else
        cout << "No Duplicates" << endl;

    return 0;
}
