#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node* insert(Node* root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}

Node* searchR(Node* root,int key){
    if(root==NULL || root->data==key)
        return root;
    if(key<root->data)
        return searchR(root->left,key);
    else
        return searchR(root->right,key);
}

Node* searchI(Node* root,int key){
    while(root!=NULL){
        if(root->data==key)
            return root;
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
}

int main(){
    Node* root=NULL;
    int n,x;
    cout<<"How many numbers to insert?";
    cin>>n;
    cout<<"Enter numbers:";
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }

    int key;
    cout<<"Enter number to search:";
    cin>>key;

    Node* resR=searchR(root,key);
    Node* resI=searchI(root,key);

    if(resR) cout<<"Found recursively:"<<resR->data<<endl;
    else cout<<"Not found recursively"<<endl;

    if(resI) cout<<"Found iteratively:"<<resI->data<<endl;
    else cout<<"Not found iteratively"<<endl;
}
