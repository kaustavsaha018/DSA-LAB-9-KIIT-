//Insert a element in a sorted stack to its proper position by using basic stack operations like push() and pop().
#include<stdio.h>

int top=-1;
int stack[10];
void push(int);
int pop();
void insert_sort(int);
void display();

void main(){
	push(1);
	push(2);
	push(4);
	insert_sort(3);
	display();

}
void push(int n){
	if(top==10){
		printf("\nStack Overflow!");
		return;
	}
	else{
		top++;
		stack[top]=n;	
	}
}
int pop(){
	if(top==-1){
		printf("\nStack Underflow!");
		return;	
	}	
	else
		top--;
		return stack[top+1];		
}

void insert_sort(int element){
	int x;
	if(top==-1 || stack[top]<element){
		push(element);
		return;
	}
	else{
		x=pop();
		insert_sort(element);
		push(x);
	}
}

void display(){
	int x;
	if(top==-1){
		return;
	}	
	else{
		x=pop();
		display();
		printf(" %d", x);
		push(x);
	}
}
