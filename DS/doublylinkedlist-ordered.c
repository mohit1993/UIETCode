#include <stdio.h>
#include <stdlib.h>
typedef struct node{
		int data;
		struct node* next;
		struct node* prev;
	}Node;

int display(Node*);
Node* oinsert(Node*,int);
Node* uinsert(Node*,int);
Node* delete(Node*,int);
void freenode(Node*);
Node* getnode(void);

int main()
{
	Node *ostart=NULL,*ustart=NULL;
	int choice=0,value = 0;
	char run = 'y';
	while(run != 'N' || run != 'n')
	{   main:
		printf("\nWhat to do:");
		printf("\n1. Ordered Doubly Linked List");
		printf("\n2. Unordered Doubly Linked List");
		printf("\n3. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: sub1:
					printf("\nEnter Options :");
					printf("\n1. View list");
					printf("\n2. Insert Element");
					printf("\n3. Delete Element");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: display(ostart);
								break;
				
						case 2: printf("\nEnter value:");
								scanf("%d",&value);	
								ostart = oinsert(ostart,value);
								printf("\n New list is :");	
								display(ostart);
								break;
						case 3: printf("\nEnter the value to delete: ");
								scanf("%d",&value);
								if(ostart == NULL)
								{
									printf("\nList is empty");
									getchar();
									break;
								}
								printf("\nAfter Removing List is ");
								ostart = delete(ostart,value);
								display(ostart);
								break;
						case 4: goto main;

						default: printf("\nInvalid option entered");
								 goto sub1;
		   						break;
		   			}
		   			fflush(stdin);
		   			printf("\n\nDo you want to do more(y/n)");
					scanf("%c",&run);
					if(run != 'n' || run != 'N')
						goto sub1;
					break;

			case 2: sub2:
					printf("\nEnter Options :");
					printf("\n1. View list");
					printf("\n2. Insert Element");
					printf("\n3. Delete Element");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: display(ustart);
								break;
				
						case 2: printf("\nEnter value:");
								scanf("%d",&value);	
								ustart = uinsert(ustart,value);
								printf("\n New list is :");	
								display(ustart);
								break;
						case 3: printf("\nEnter the value to delete: ");
								scanf("%d",&value);
								if(ustart == NULL)
								{
									printf("\nList is empty");
									getchar();
									break;
								}
								printf("\nAfter Removing List is ");
								ustart = delete(ustart,value);
								display(ustart);
								break;
						case 4: goto main;

						default: printf("\nInvalid option entered");
								 goto sub2;
		   						break;
		   			}
		   			fflush(stdin);
		   			printf("\n\nDo you want to do more(y/n)");
					scanf("%c",&run);
					if(run != 'n' || run != 'N')
						goto sub2;
					break;

		case 3: return 0;		

		default: printf("\nInvalid Option entered");
				 getchar();
				 goto main;
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

Node* oinsert(Node* l,int val)
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
		if(temp == NULL)
		{
			l = freshnode;
			l->prev = NULL;
			l->next = NULL;
			return l;
		}
		while(temp != NULL)
		{
			if(temp->next == NULL)
				break;

			else if(temp->data > val)
			{
				freshnode->next = temp;
				freshnode->prev = temp->prev;
				if(temp->prev == NULL)
					l = freshnode;
				else
					(temp->prev)->next = freshnode;
				temp->prev = freshnode;
				return l;
			}
			else
			temp = temp->next;
		}
		if(temp->prev == NULL)
		{   
			if(temp->data > val)
			{
				freshnode->next = temp;
				temp->prev = freshnode;
				freshnode->prev = NULL;
				return freshnode;
			}
			else
			{
				temp->next = freshnode;
				freshnode->prev = temp;
				freshnode->next = NULL;
				return l;
			}
		}
		else
		{
			temp->next = freshnode;
			freshnode->prev = temp;
			freshnode->next = NULL;
			return l;
		}

	}

}

Node* uinsert(Node* start,int val)
{
	Node* newnode,*temp = start;
	newnode = getnode();
	if(newnode == NULL)
	{
		printf("\nMemory Allocation Failed");
		return start;
	}
	newnode->data = val;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(start == NULL)
		return newnode;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
	return start;
}


Node* delete(Node* l,int val)
{
	Node *temp = l;
	while(temp->data != val)
	{
		if(temp->next == NULL)
		{
			printf("\nElement not Found");
			return l;
		}
		else
		{
			temp = temp->next;
		}

	}
	if(temp->prev == NULL)
	{
		if(temp->next == NULL)
			return NULL;
		(temp->next)->prev = NULL;
		l = temp->next;
	}
	else if(temp->next == NULL)
	{
		(temp->prev)->next = NULL;
	}
	else
	{
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
	}
	freenode(temp);
	return l;
}