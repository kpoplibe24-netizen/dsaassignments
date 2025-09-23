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
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"the memory is free of node with data "<<value<<endl;
    }
};
void insertAtBeginning(Node* &head,Node* &tail, int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
        }
    }
void insertAtEnd(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){   // if list is empty
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;}
}
void insertAtPosition(Node* &head,Node* &tail,int d, int position){
    if(position==1){
        insertAtBeginning(head, tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void deleteAtNode(Node* &head,int position, Node* &tail){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        if(curr->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void deleteAtValue(Node* &head, Node* &tail, int value){
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL && curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL){
            cout<<"value not found\n";
        }
        prev->next=curr->next;
        if(curr->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void searchnode(int key, Node* head){
    Node* temp=head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"Node with value "<<key<<" found at "<<pos<<endl;
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Node not found\n";
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
    int choice,value,key;
    Node* head=NULL;
    Node* tail=NULL;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at postion\n";
        cout << "4. Delete a specific node\n";
        cout<<  "5. Delete a specific value\n";
        cout << "6. Search for a node\n";
        cout << "7. Display all nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
    
        switch(choice){
            case 1:
            cout<<"enter value: ";
            cin>>value;
            insertAtBeginning(head,tail,value);
            break;
            
            case 2:
            cout<<"enter value: ";
            cin>>value;
            insertAtEnd(head,tail,value);
            break;
            
            case 3:
            cout<<"enter the value:";
            cin>>value;
            cout<<"enter position: ";
            cin>>key;
            insertAtPosition(head,tail,value,key);
            break;
            
            case 4:
            cout<<"enter the position to delete : ";
            cin>>key;
            deleteAtNode(head,key,tail);
            break;
            
            case 5:
            cout<<"enter the value to delete: ";
            cin>>value;
            deleteAtValue(head,tail,value);
            break;
            
            case 6:
            cout<<"enter the value to search: ";
            cin>>value;
            searchnode(value, head);
            break;
            
            case 7:
            cout<<"displaying list: \n";
            print(head);
            break;
            
            case 0:
            cout<<"Exiting..";
            return 0;
            
            default:
            cout<<"Invalid choice.. try again";
            
        }
    }
}
