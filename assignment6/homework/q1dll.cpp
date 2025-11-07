#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }

    ~Node() {
        int value = data;
        cout << "Memory freed for node with value " << value << endl;
    }
};
void insertAtBeg(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if (head == NULL) { 
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPos(Node* &head, Node* &tail, int d, int pos) {
    if (pos == 1) {
        insertAtBeg(head, tail, d);
        return;
    }

    Node* curr = head;
    int cnt = 1;

    while (cnt < pos - 1 && curr->next != NULL) {
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;
}
void deleteAtNode(Node* &head, Node* &tail, int pos) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; 

        delete temp;
        return;
    }

    Node* curr = head;
    int cnt = 1;
    while (cnt < pos && curr != NULL) {
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL) {
        cout << "Invalid position!\n";
        return;
    }
    if (curr->next == NULL)
        tail = curr->prev;
    else
        curr->next->prev = curr->prev;

    curr->prev->next = curr->next;
    delete curr;
}
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void search(Node* head, int val) {
    if (head == NULL) {
        cout << "List is empty!";
        return;
    }

    int pos = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << val << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << val << " not found in the list.\n";
}
int count(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val, pos, data, choice;

    while (true) {
        cout << "\n\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node at Position\n";
        cout << "5. Search a Value\n";
        cout << "6. Count Nodes\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtBeg(head, tail, data);
            break;

            case 2:
           cout << "Enter data to insert at end: ";
            cin >> data;
            insertAtTail(head, tail, data);
            break;

            case 3:
            cout << "Enter position and data: ";
            cin >> pos >> data;
            insertAtPos(head, tail, data, pos);
            break;

            case 4:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteAtNode(head, tail, pos);
            break;

            case 5:
            cout << "Enter value to search: ";
            cin >> val;
            search(head, val);
            break;

            case 6:
            cout << "Total nodes: " << count(head) << endl;
            break;

            case 7:
            cout << "Linked List: ";
            print(head);
            cout << endl;
            break;

            case 8:
            cout << "Exiting program..." << endl;
            return 0;

            default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
