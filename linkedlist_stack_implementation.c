#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};
struct node* root = NULL;
void push();
void pop();
void peek();
void traverse();
void main(){
	int ch;
	while(1){
		printf("Operations for a stack implementation using linked list\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Traverse\n");
		printf("5. Quit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1: 	push();
					break;
			case 2: 	pop();
					break;
			case 3: 	peek();
					break;	
			case 4: 	traverse();
					break;
			case 5: 	exit(0);
			default: 	printf("Invalid choice.\n");		
		}
	}
}

void push(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be pushed to stack: ");
	scanf("%d", &temp->data);
	
	temp->link = root;
	root = temp;
}

void pop(){
	struct node* p;
	p = root;

	if(p == NULL){
		printf("Nothing to delete. The stack is empty\n");
	}
	else{
		root = p->link;
		p->link = NULL;
		free(p);	
	}
}

void peek(){
	struct node* p;
	struct node* q;
	p = root;
	if(p == NULL){
		printf("Empty stack. Nothing to peek!\n");
	}
	else{
		printf("The top value in stack is %d", p->data);			
	}
}

void traverse(){
	struct node* p;
	p = root;
	if(p == NULL){
		printf("The stack is empty. Nothing to traverse. \n");		
	}
	else{
		while(p != NULL){
			printf("%d-->", p->data);
			p = p->link;		
		}
		printf("\n");
	}
}
