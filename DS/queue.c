#include <stdio.h>
#include <stdlib.h>

// For array
void display(int *,int,int);
void enqueue(int *,int *,int *);
void dequeue(int *,int *,int *);

// For Linked List
typedef struct node
{
	int data;
	struct node *next;
}Node;

void listdisplay(Node*);
Node* listenqueue(Node*);
Node* listdequeue(Node*);

int main()
{
	int choice = 0,queue[10],start=0,end=0;
	char ch='y';
	Node* head = NULL;
	while(ch !='n' || ch != 'N')
	{
		main:
		system("clear");
		printf("What you want to do: ");
		printf("\n1. Queue using Arrays");
		printf("\n2. Queue using linked list");
		printf("\n3. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					sub1:
					system("clear");
					printf("\n\n1. Display");
					printf("\n2. Enqueue");
					printf("\n3. Dequeue");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: display(queue,start,end);
								getchar();
								break;

						case 2:
						        enqueue(queue,&start,&end);
								getchar();
								break;

						case 3: dequeue(queue,&start,&end);
								getchar();
								break;

						case 4: goto main;

						default: printf("\nEntered Invalid option");
								 getchar();
								 goto sub1;		
					}
					printf("\nDo you want to do more: ");
					fflush(stdin);
					scanf("%c",&ch);
					if(ch != 'n' && ch != 'N')
						goto sub1;
					break;

			case 2: sub2:
					system("clear");
					printf("\n\n1. Display");
					printf("\n2. Enqueue");
					printf("\n3. Dequeue");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: listdisplay(head);
								getchar();
								break;

						case 2:
						        head = listenqueue(head);
								getchar();
								break;

						case 3: head = listdequeue(head);
								getchar();
								break;

						case 4: goto main;

						default: printf("\nEntered Invalid option");
								 getchar();
								 goto sub2;		
					}
					printf("\nDo you want to do more: ");
					fflush(stdin);
					scanf("%c",&ch);
					if(ch != 'n' || ch != 'N')
						goto sub2;
					break;

			case 3: ch = 'n';
					break;

			default: printf("\nEntered Invalid option");
								 getchar();
								 goto main;	 
		}
	}
	return 0;
}

//For Array

void display(int *arr,int start,int end)
{
	if(start == end)
		printf("\nQueue is empty");
	else
		while(start != end)
		{
			printf("%d   ",*(arr+start));
			start++;
		}
}

void enqueue(int *arr,int *start,int *end)
{
	if(*end == 10)
	{
		printf("\nOverflow");
	}
	else
	{
		printf("\nEnter Value ");
		scanf("%d",(arr + *end)); 
		*end = *end + 1;
	}
}

void dequeue(int *arr,int *start,int *end)
{
	if(*start == *end)
		printf("\nUnderflow");
	else
	{	
		printf("\n%d Dequeued",*(arr + *start));
		*start = *start + 1;
	}
}

// For Linked List

void listdisplay(Node *start)
{
	Node* temp = start;
	if(start == NULL)
	{
		printf("\nList doesnt exist");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d  ",temp->data);
			temp = temp->next;
		}
	}
}

Node* listenqueue(Node *start)
{
	Node* newnode,*temp = start;
	newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		printf("\nMemory Allocation Failed");
		return start;
	}
	printf("\nEnter value: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	if(start == NULL)
	{
		return newnode;
	}
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	return start;
}

Node* listdequeue(Node* start)
{
	Node *temp = start;
	if(start == NULL)
	{
		printf("\nUnderflow");
		return NULL;
	}
	else
	{
		printf("\n%d Dequeued",start->data);
		start = start->next;
		free(temp);
		return start;
	}

}