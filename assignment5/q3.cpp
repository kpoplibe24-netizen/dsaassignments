#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtEnd(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){   
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;}
}
Node* middle(Node* &head){
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int n,d;
    cout<<"enter number of elements in linked list: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter the value: ";
        cin>>d;
        insertAtEnd(head,tail,d);
    }
    cout << "Original List: "; 
    print(head); 
    Node* mid=middle(head);
    cout<<"the middle element is "<<mid->data<<endl; }
