#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newnode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int value) {
    Node* newnode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

void insertBefore(int key, int value) {
    if (head->data == key) {
        insertAtBeginning(value);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }
    Node* newnode = new Node{value, temp->next};
    temp->next = newnode;
}

void insertAfter(int key, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    Node* newnode = new Node{value, temp->next};
    temp->next = newnode;
}

void deleteBeginning() {
    if (head == nullptr) {
        cout << "list is empty \n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "list is empty \n";
        return;
    }
    else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

void deleteNodevalue(int value) {
    if (head == nullptr) {
        cout << "list is empty\n";
        return;
    }
    Node* temp = head;
    Node* pre = nullptr;
    while (temp != nullptr && temp->data != value) {
        pre = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "element not found\n";
        return;
    }
    if (temp == head) {
        head = head->next;
    }
    else if (temp->next == nullptr) {
        pre->next = nullptr;
    }
    else {
        pre->next = temp->next;
    }
    delete temp;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "node " << key << " not found\n";
}

void displaylist() {
    if (head == nullptr) {
        cout << "list is empty\n";
        return;
    }
    Node* temp = head;
    cout << "linked list: ";
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

int main() {
    int choice, value, key;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display all nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value to insert before " << key << ": ";
                cin >> value;
                insertBefore(key, value);
                break;
            case 4:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value to insert after " << key << ": ";
                cin >> value;
                insertAfter(key, value);
                break;
            case 5:
                deleteBeginning();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                cout << "Enter node value to delete: ";
                cin >> key;
                deleteNodevalue(key); 
                break;
            case 8:
                cout << "Enter node value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 9:
                displaylist(); 
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
