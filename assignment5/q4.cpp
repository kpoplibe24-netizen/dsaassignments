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
Node* reverselist(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
int main(){
    Node* head = NULL;
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

    head = reverselist(head);

    cout << "Reversed List: ";
    print(head);
    // print()
}
