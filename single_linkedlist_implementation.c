#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};

struct node* root = NULL;
int len;
void append();
void addatbegin();
void addatafter();
int length();
void display();
void delete();
void main(){
	int ch;
	while(1){
		printf("Single Linked List Operations: \n");
		printf("1. Append\n");
		printf("2. Add at Begin\n");
		printf("3. Add at After\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete\n");
		printf("7. Quit\n");

		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch){
			case 1: 	append();
					break;
			case 2: 	addatbegin();
					break;
			case 3: 	addatafter();
					break;
			case 4: 	len = length();
					printf("%d", len);
					break;
			case 5: 	display();
					break;
			case 6: 	delete();
					break;
			case 7: 	exit(0);
			default: 	printf("Invalid choice.\n");		
		}
	}
}

void append() {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	printf("Enter node data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;

	if(root == NULL){
		root = temp;
	}
	else {
		struct node* p;
		p=root;
		
		while(p->link != NULL){
			p = p->link;			
		}
		p->link = temp;	
	}
}

void addatbegin(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	
	temp->link = root;
	root = temp;
}

void addatafter(){
	struct node* temp;
	struct node* p;
	p = root;
	int loc, len, i=1;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &temp->data);

	printf("Enter adding location: ");
	scanf("%d", &loc);
	len = length();
	if(loc > len || loc < 1){
		printf("Invalid input");
		printf("Location is out of bounds");
	}
	else{
		while(i<loc){
			i++;
			p = p->link;		
		}
		temp->link = p->link;
		p->link = temp;	
	}
}	

int length(){
	int count = 0;
	struct node* temp;
	temp = root;
	while(temp != NULL){
		temp = temp->link;
		count++;
	}
	return count;
}

void display(){
	struct node* temp;
	temp = root;
	if(temp == NULL){
		printf("List is empty \n\n");
	}
	else {
		while(temp != NULL){
			printf("%d-->",temp->data);
			temp = temp->link; 	
		}	
		printf("\n\n");
	}
}

void delete(){
	struct node* p;
	struct node* q;
	int loc, len, i=1;
	p = root;
	if(p == NULL){
		printf("List is empty. There is nothing to delete\n");	
	}
	else{
		printf("Enter the location of the node to delete: \n");
		scanf("%d", &loc);
		len = length();
		if(loc > len || len < 1){
			printf("Invalid location to delete.\n");
		}
		else{
			if(loc == 1){
				root = p->link;
				p->link = NULL;
				free(p);
			}
			else{
				while(i<loc-1){
					p = p->link;
					i++;			
				}
				q = p->link;
				p->link = q->link;			
				q->link = NULL;
				free(q);	
			}
		}
	}
}
