#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){data=d; left=right=NULL;}
};
Node* insert(Node* root,int data){
    if(root==NULL) return new Node(data);
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root;
}
int max(Node* root){
    if(root==NULL) return -1;
    else{
        while(root->right!=NULL){
            root=root->right;
            return root->data;
        }
    }
}
int min(Node* root){
    if(root==NULL) return -1;
    else{
        while(root->left!=NULL){
            root=root->left;
            return root->data;
        }
    }
}

int main(){
    Node* root=NULL;
    int n,x;
    cout<<"how many numbers to insert:";
    cin>>n;
    cout<<"enter numbers";
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }
    cout<<"maximum element: "<<max(root);
    cout<<"\n minimum element: "<<min(root);
}
