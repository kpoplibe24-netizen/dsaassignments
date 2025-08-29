#include<iostream>
using namespace std;

#define MAX 100

struct stack {
	char arr[MAX];
	int top;
};

stack init() {
	stack S; 
	S.top = -1;
	return S;
}
 
bool isEmpty(stack S) {
	return (S.top==-1);
}

bool isFull(stack S) {
	return (S.top == MAX -1);
}

void push(stack &S, char c) {
	if(isFull(S))  {
		cout<<"\n Stack Overflow! Cannot push " <<c<<endl;
	}
	else {
		S.top++;
		S.arr[S.top]=c;
//		cout<<c<<" pushed into stack."<<endl;
	}
}

char pop(stack &S){
	if(isEmpty(S)) {
		cout<<"\nStack Underflow! Cannot pop"<<endl;
		return '\0';
	}
	else{
		char c = S.arr[S.top];
		S.top--;
		return c;
	}
}

string reversedstring(string str) {
	stack S= init();
	for(int i=0; i<str.length(); i++){
		push(S, str[i]);
	}
	string reversed= "";
	while (!isEmpty(S)) {
		reversed+= pop(S);
	}
	return reversed;
}

int main() {
	string input;
	cout<< "enter a string: ";
	cin>> input;
	string output= reversedstring(input);
	cout<<"reversed string: " <<output<<endl;
	
	return 0;
}
