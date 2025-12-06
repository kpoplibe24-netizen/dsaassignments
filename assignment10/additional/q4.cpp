#include<iostream>
#include<unordered_set>
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

void insert(Node* &head, int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
Node* getUnion(Node* head1, Node* head2){
    unordered_set<int> s;
    Node* result=NULL;
    Node* temp1=head1;
    while(temp1){
        s.insert(temp1->data);
        temp1=temp1->next;
    }
    Node* temp=head2;
    while(temp){
        s.insert(temp->data);
        temp=temp->next;
    }
    for(auto x:s){
        insert(result,x);
    }
    return result;
}
Node* getIntersection(Node* head1, Node* head2){
    unordered_set<int> s1;
    unordered_set<int> s2;
    Node* result=NULL;
    
    Node* temp1=head1;
    while(temp1){
        s1.insert(temp1->data);
        temp1=temp1->next;
    }
    
    Node* temp=head2;
    while(temp){
        if(s1.find(temp->data)!=s1.end()){
            s2.insert(temp->data);
        }
        temp=temp->next;
    }
    for(auto x:s2){
        insert(result,x);
    }
    return result;
}
int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 10);
    insert(head1, 15);
    insert(head1, 4);
    insert(head1, 20);

    insert(head2, 8);
    insert(head2, 4);
    insert(head2, 2);
    insert(head2, 10);

    cout << "List1: ";
    printList(head1);

    cout << "List2: ";
    printList(head2);

    Node* unionList = getUnion(head1, head2);
    Node* intersectionList = getIntersection(head1, head2);

    cout << "\nUnion: ";
    printList(unionList);

    cout << "Intersection: ";
    printList(intersectionList);

    return 0;
}
