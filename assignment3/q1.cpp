#include<iostream>
using namespace std;

#define MAXLEN 5

struct stack {
	int arr[MAXLEN];
	int top;
};

stack init() {
	stack S; 
	S.top = -1;
	return S;
}
 
int isEmpty(stack S) {
	return (S.top==-1);
}

int isFull(stack S) {
	return (S.top == MAXLEN -1);
}

stack push(stack S, int value) {
	if(isFull(S))  {
		cout<<"\n Stack Overflow! Cannot push " <<value<<endl;
	}
	else {
		S.top++;
		S.arr[S.top=value];
		cout<<value<<" pushed into stack."<<endl;
	}
	return S;
}

stack pop(stack S){
	if(isEmpty(S)) {
		cout<<"\nStack Underflow! Cannot pop"<<endl;
	}
	else{
		cout<<S.arr[S.top]<<"popped from stack."<<endl;
		S.top--;
	}
	return S;
}

void peek(stack S) {
	if(isEmpty(S)){
		cout<<"\n Stack is empty"<<endl;
	}
	else {
		cout<<"top element is: "<<S.arr[S.top]<<endl;
	}
}

void display(stack S) {
	if(isEmpty(S)) {
		cout<<"\nStack is empty."<<endl;
	}
	else{
		cout<<"\nStack elements are: ";
		for(int i=S.top;i>=0;i--){
			cout<<S.arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	stack S= init();
	int choice, value;
	
	while(1) {
		cout<< "\n----Stack Menu----\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Peek\n";
		cout<<"4. isEmpty\n";
		cout<<"5. isFull\n";
		cout<<"6. Display\n";
		cout<<"7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		
	switch(choice) {
		case 1:
			cout<<"enter value to push: ";
			cin>>value;
			S=push(S,value);
			break;
		case 2:
			S=pop(S);
			break;
		case 3:
			peek(S);
			break;
		case 4:
			cout<<(isEmpty(S) ? "Stack is empty\n": "Stack is not empty\n");
			break;
		case 5:
			cout<<(isFull(S) ? "Stack is full\n" : "Stack is not full\n");
			break;
		case 6:
			display(S);
			break;
		case 7:
			cout<<"Exiting...\n";
			return 0;
		default:
			cout<<"Invalid choice! Try again";
		}
	}
}
