#include<iostream>
#include<cstring>
using namespace std;
// using arrays
#define MAX 100
class Queue{
    public:
    int arr[MAX],front,rear,size;
    Queue(){
        front=0;
        rear=0;
        size=MAX;
    }
    void enqueue(int data){
        if(rear==size){
            cout<<"queue is full "<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    int dequeue(){
        if(front==rear){
            return -1;
        }
        else{
            arr[front]=-1;
            int ans=arr[front];
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }
    int peek(){
        if(front==rear){
            return -1;
        }
        else{
            int ans=arr[front];
            return ans;
        }
    }
    bool isempty(){
        if(front==rear) return true;
        else return false;
    }
    void display(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
        }
        else{
            // cout<<"Stack elements are: "<<endl;
            // cout<<"top->";
            for(int i=front;i<rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Queue q;
    int choice=-1,element;
    while (choice != 0) {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
            cout<<"enter the element: ";
            cin>>element;
            q.enqueue(element);
            break;
            
            case 2:
            q.dequeue();
            break;
            
            case 3:
            cout<<"the top element is "<<q.peek()<<endl;
            break;
            
            case 4:
            if(q.isempty()){
                cout<<"the queue is empty"<<endl;
            }
            else{
                cout<<"the queue is not empty"<<endl;
            }
            break;
            
            case 5:
            q.display();
            break;
            
            case 0:
            cout<<"exiting.. "<<endl;
            break;
            
            default:
            cout<<"invalid choice.. try again"<<endl;
        }
        
    }
}
