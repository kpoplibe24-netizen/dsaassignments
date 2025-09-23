#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        while(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free of node with data "<<value<<endl;
    }
};
void insertAtEnd(Node* &head,Node* &tail, int d){
    Node* temp=new Node(d);
    if(head==NULL){   
        head=temp;
        tail=temp;
    }
    else{
      Node* temp=new Node(d);
      tail->next=temp;
      tail=temp;}
}
void deleteoccur(Node* &head, int key){
    while(head!=NULL && head->data==key){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        if(curr->data==key){
            prev->next=curr->next;
            Node* toDelete=curr;
            curr=curr->next;
            toDelete->next=NULL;
            delete toDelete;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
}
void count(Node* head, int key){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(temp->data==key){
            cnt++;
            // delete temp->data;
        }
        temp=temp->next;
    }
    cout<<cnt;
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
    int key;
    cout<<"enter key: ";
    cin>>key;
    count(head,key);
    cout<<endl;
    deleteoccur(head,key);
    print(head);

}
