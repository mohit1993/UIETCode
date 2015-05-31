#include <stdio.h>
#include <stdlib.h>
typedef struct node{
		int data;
		struct node* next;
	}Node;

int display(Node*);
Node* insert(Node*,int,int);
Node* delete(Node*,int);
void freenode(Node*);
Node* getnode(void);

int main()
{
	Node *start=NULL;
	int choice=0,value = 0,pos = -1;
	char run = 'y';
	while(run != 'N' && run != 'n'){
		printf("\nEnter Options :");
		printf("\n1. View list");
		printf("\n2. Insert Element");
		printf("\n3. delete Element");
		printf("\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: display(start);
					break;
			
			case 2: printf("\nEnter position to add element in list(1->begining and x>=n is assumed n): ");
					scanf("%d",&pos);
					if(pos < 1)
					{
						printf("\nInvalid Position Entered");
						getchar();
						break;
					}
					printf("\nEnter value:");
					scanf("%d",&value);	
					start = insert(start,pos,value);
					printf("\n New list is :");
					display(start);
					break;
			case 3: printf("\nEnter the value to delete: ");
					scanf("%d",&value);
					if(start == NULL){
						printf("\nList is empty");
						getchar();
						break;
					}
					printf("\nAfter Removing List is ");
					start = delete(start,value);
					display(start);
					break;
			case 4: return 0;

			default: printf("\nInvalid option entered");
					break;
		}
		printf("\n\nDo you want to do more(y/n)");
		scanf("%c",&run);
	}
	return 0;
}

void freenode(Node* p)
{
	free(p);
}

Node* getnode(void)
{
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	return(p);
}

int display(Node* start)
{

	if(start == NULL){
		printf("\nList doesnt exist\n");
		getchar();
		return 1;
	}
	Node* temp = start;
	printf("\n");
	while(temp->next != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
	getchar();
	return 0;
}

Node* insert(Node* l,int pos,int val)
{
	Node *freshnode,*temp=l,*prev=NULL;
	int x = 1;
	freshnode = getnode();
	if(freshnode == NULL){
		printf("\nMemory Allocation Failed");
		getchar();
		return l;
	}

	else
	{
		freshnode->data = val;
		while(x<pos && temp != NULL){
			prev = temp;
			temp = temp->next;
			if(temp == NULL)
				break;
			++x;
		}
		if(prev == NULL){
			freshnode->next = temp;
			l = freshnode;
		}
		else if(temp == NULL){
			prev->next = freshnode;
			freshnode->next = NULL;
		}
		else{
			prev->next = freshnode;
			freshnode->next = temp;
	    }
		
	}
	return l;
}

Node* delete(Node* l,int val)
{
	Node *prev = NULL,*next = l,*temp = l;
	while(temp->data != val)
	{
		prev = temp;
		temp = temp->next;
		if(temp == NULL)
		{
			printf("\nElement doesnt exist in list");
			return l;
		}
	}
	if(prev == NULL){
		l = temp->next;
		freenode(temp);
	}
	else if(temp->next == NULL){
		prev->next = NULL;
		freenode(temp);
	}
	else{
		prev->next = temp->next;
		freenode(temp);
	}
	return l;
}