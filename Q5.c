#include<stdio.h>
#include<string.h>

void push(char);
char pop();
int precedence(char);
void infix_to_prefix(char []);
char *braces_interchange(char []);

int temp, length=0, index1=0, pos=0, top= -1;
char symbol, infix[30], postfix[30], stack[50];

void main(){
	char infix[25];
	printf("Enter the infix expression:\n");
	gets(infix);

	infix_to_prefix(strrev(braces_interchange(infix)));

	printf("The equivalent prefix expression :\n");
	puts(strrev(postfix));
}

void push(char symbol){
	top=top+1;
	stack[top]= symbol; 
}

char pop(){
	char temp;
	temp=stack[top];
	top=top-1;
	return temp; 
}

int precedence(char symbol){
	int priority;
	switch(symbol){
 		case '#':
 			priority=0;
 			break;
 		case '(':
 		case ')':
 			priority=1;
			break;
 		case '+':
 		case '-':
 			priority=2;
 			break;
 		case '*':
 		case '/':
 			priority=3;
 			break;
 		case '^':
 			priority=4;
 			break;
 
	}
return (priority);
}

void infix_to_prefix(char infix[]){
	length= strlen(infix);
	push('#');
	while(index1<length){
 		symbol= infix[index1];
 		switch(symbol){
			case '(':
				push(symbol);
 				break;
			case ')':
 				temp=pop();
				while(temp!='('){
					postfix[pos]=temp;
					pos++;
					temp=pop();
 				}
 				break;
 			case '+':
 			case '-':
			case '*':
			case '/':
 			case '^':
 				while(precedence(stack[top])>=precedence(symbol)){
 					temp=pop();
 					postfix[pos]=temp;
 					pos++;
 				}
				push(symbol);
				break;
 			default:
 				postfix[pos++]=symbol;
 				break;
 			}
		index1++;
	}

	while(top>0){
		temp=pop();
		postfix[pos++]=temp;
 		postfix[pos]='\0';
	} 
}

char *braces_interchange(char string[]){
	int n=0;
	while(string[n]!='\0'){
		if(string[n]=='(')
			string[n]=')';
		else if(string[n]==')')
			string[n]='(';
		n++;
	}
	return string;
}
