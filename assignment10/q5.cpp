#include<iostream>
using namespace std;
#define MAX 1000
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
 
};

bool detectloop(Node* head){
    Node* hash[MAX]={NULL};
    Node* temp=head;
    int index;
    while(temp!=NULL){
        index=((unsigned long long)temp%MAX);
        if(hash[index]==temp) return true;
        hash[index]=temp;
        temp=temp->next;
    }
    return false;
}
int main() {
   Node* head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);
//    head->next->next->next->next = head->next; // create loop
   if(detectloop(head)){
    cout<<"detected";
   }
   else cout<<"no";
}
