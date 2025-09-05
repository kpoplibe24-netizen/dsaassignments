#include <iostream>
using namespace std;

#define MAX 5  

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};
void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;}

bool isEmpty(Queue &q) {
    return (q.front == -1 && q.rear == -1);}

bool isFull(Queue &q) {
    return (q.rear == MAX - 1);}

void enqueue(Queue &q, int x) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot insert " << x << endl;
        return;}
    if (isEmpty(q)) {
        q.front = q.rear = 0;} 
        else {
        q.rear++;}
    q.arr[q.rear] = x;
    cout << x << " inserted into queue." << endl;}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! Cannot remove." << endl;
        return;
    }
    cout << q.arr[q.front] << " removed from queue." << endl;
    if (q.front == q.rear) {
        q.front = q.rear = -1; // Reset after last element
    } else {
        q.front++;
    }
}

void peek(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << q.arr[q.front] << endl;
    }}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue q;
    initQueue(q);
    int choice = -1, value;

    while (choice != 0) {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            display(q);
            break;
        case 5:
            if (isEmpty(q))
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 6:
            if (isFull(q))
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
