#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout << "memory freed for node with data " << data << endl;
    }
};
void print(Node* tail){
    if(tail == NULL){
        cout << "list is empty\n";
        return;
    }

    Node* temp = tail->next;
    cout << "list: ";
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail->next);
    cout << endl;
}
void insertAtBeg(Node* &tail, int d){
    Node* n = new Node(d);
    if(tail == NULL){
        tail = n;
        n->next = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
    }
}
void insertAtEnd(Node* &tail, int d){
    Node* n = new Node(d);
    if(tail == NULL){
        tail = n;
        n->next = n;
    } else {
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}
void insertAfter(Node* &tail, int element, int d){
    if(tail == NULL){
        cout << "list empty\n";
        return;
    }

    Node* curr = tail->next;
    do{
        if(curr->data == element){
            Node* n = new Node(d);
            n->next = curr->next;
            curr->next = n;
            if(curr == tail) tail = n;
            return;
        }
        curr = curr->next;
    }while(curr != tail->next);

    cout << "element " << element << " not found\n";
}
void insertBefore(Node* &tail, int element, int d){
    if(tail == NULL){
        cout << "list empty\n";
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;
    do{
        if(curr->data == element){
            Node* n = new Node(d);
            n->next = curr;
            prev->next = n;
            if(curr == tail->next){
                tail->next = n;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }while(curr != tail->next);

    cout << "element " << element << " not found\n";
}
void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout << "list empty\n";
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;

    while(curr->data != value){
        if(curr == tail){
            cout << "value " << value << " not found\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == prev){
        tail = NULL;
    }
    else if(curr == tail){
        tail = prev;
    }

    delete curr;
    cout << "node " << value << " deleted\n";
}
void search(Node* tail, int value){
    if(tail == NULL){
        cout << "list empty\n";
        return;
    }

    Node* temp = tail->next;
    int pos = 1;
    do{
        if(temp->data == value){
            cout << "value " << value << " found at pos " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != tail->next);

    cout << "value " << value << " not found\n";
}

int main(){
    Node* tail = NULL;
    int ch, data, element;

    do{
        cout << "\nMenu\n";
        cout << "1. insert at beginning\n";
        cout << "2. insert at end\n";
        cout << "3. insert after a node\n";
        cout << "4. insert before a node\n";
        cout << "5. delete a node\n";
        cout << "6. search a node\n";
        cout << "7. display list\n";
        cout << "8. exit\n";
        cout << "enter choice: ";
        cin >> ch;

        switch(ch){
            case 1:
                cout << "enter data: ";
                cin >> data;
                insertAtBeg(tail, data);
                break;

            case 2:
                cout << "enter data: ";
                cin >> data;
                insertAtEnd(tail, data);
                break;

            case 3:
                cout << "enter element after which to insert: ";
                cin >> element;
                cout << "enter data: ";
                cin >> data;
                insertAfter(tail, element, data);
                break;

            case 4:
                cout << "enter element before which to insert: ";
                cin >> element;
                cout << "enter data: ";
                cin >> data;
                insertBefore(tail, element, data);
                break;

            case 5:
                cout << "enter value to delete: ";
                cin >> data;
                deleteNode(tail, data);
                break;

            case 6:
                cout << "enter value to search: ";
                cin >> data;
                search(tail, data);
                break;

            case 7:
                print(tail);
                break;

            case 8:
                cout << "exiting...\n";
                break;

            default:
                cout << "invalid choice\n";
        }

    }while(ch != 8);

    return 0;
}
