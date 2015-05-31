#include <stdio.h>
#include <stdlib.h>
typedef struct node{
		int data;
		struct node* next;
	}Node;

int display(Node*);
Node* insert(Node*,int);
Node* delete(Node*,int);
void freenode(Node*);
Node* getnode(void);

int main()
{
	Node *start=NULL;
	int choice=0,value = 0;
	char run = 'y';
	while(run != 'N' || run != 'n'){
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
			
			case 2: printf("\nEnter value:");
					scanf("%d",&value);	
					start = insert(start,value);
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
					start = delete(start,value);
					printf("\nAfter Removing List is ");
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
	while(temp->next != start){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
	getchar();
	return 0;
}

Node* insert(Node* l,int val)
{
	Node *freshnode,*temp=l;
	freshnode = getnode();
	if(freshnode == NULL){
		printf("\nMemory Allocation Failed");
		getchar();
		return l;
	}
	else
	{
		freshnode->data = val;
		if(l==NULL)
		{
			l = freshnode;
			l->next = l;
			return l;
		}
		temp = l->next;
		l->next=freshnode;
		freshnode->next = temp;
		
	}
	return freshnode;
}

Node* delete(Node* l,int val)
{
	Node *temp=l,*prev = NULL;
	while(temp->data != val)
	{
		prev = temp;
		temp = temp->next;
		if(temp->next == l && temp->data != val){
			printf("\nElement not found");
			return l;
		}
	}
	if(prev == NULL)
	{
		prev = temp;
		while(prev->next != l)
		{
			prev = prev->next;
		}
	}
	if(prev->next == temp->next)
	{
		freenode(prev);
		return NULL;
	}
	prev->next = temp->next;
	freenode(temp);
	return prev->next;
}