#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY];
int top = -1;
void push(int);
int pop();
int isFull();
int isEmpty();
void traverse();
void peek();
void main(){
	int ch, item;
	while(1){
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Peek \n");
		printf("4. Traverse \n");
		printf("5. Quit\n");

		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch){
			case 1 : 	printf("Enter element: ");
					scanf("%d", &item);
					push(item);
					break;
			case 2 : 	item = pop();
					if(item == 0){
						printf("stack is underflow\n");	
					}
					else{
						printf("popped item: %d \n", item);
					}
					break;	
			case 3 :	peek();
					break;
			case 4 : 	traverse();
					break;
			case 5 : 	exit(0);
			default : 	printf("Invalid option selected. \n");
		}	
	}
}

void push(int n){
	if(isFull()){
		printf("stack is overflow.\n");
	}
	else{
		top++;
		stack[top] = n;	
		printf("%d has been pushed successfully.\n", n);
	}
}

int isFull(){
	if(top == CAPACITY-1){
		return 1;	
	}
	else{
		return 0;	
	}
}

int pop(){
	if(isEmpty()){
		printf("stack is already empty.\n");
		return 0;
	}
	else{
		return stack[top--];	
	}
}

int isEmpty(){
	if(top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void peek(){
	if(isEmpty()){
		printf("Stack is empty \n");
	}
	else{
		printf("peek element is: %d \n", stack[top]);
	}
}

void traverse(){
	if(isEmpty()){
		printf("Stack is empty \n");
	}
	else{
		int i;		
		printf("stack elements: \n");
		for(i=0; i<=top; i++){
			printf("%d \n", stack[i]);
		}
	}
}
