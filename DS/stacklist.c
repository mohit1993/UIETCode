#include <stdio.h>
#include <stdlib.h>

// For Array
void push(int *,int*,int);
int pop(int*,int*);
void display(int*,int);

// For linked list

typedef struct node{
	int data;
	struct node *next;
}Node;

void listdisplay(Node *);
Node* listpush(Node *,int);
Node* listpop(Node*);

int main()
{
	int choice1,stack[10],top = -1,val;
	Node* start = NULL;
	char ch = 'y';
	while(ch !='n' || ch != 'N')
	{
		main:
		system("clear");
		printf("What to do:");
		printf("\n\n1. Stacks Using Array");
		printf("\n2. Stacks using Linked List");
		printf("\n3. Exit\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			sub1:
			case 1: printf("\n\n1. Push an element");
					printf("\n2. Pop an element");
					printf("\n3. Print the stack");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice1);
					switch(choice1)
					{
						case 1: if(top == 9)
								{
									printf("\nOverflow");
								}
								else
								{
									printf("\nEnter the Value");
									scanf("%d",&val);
									push(stack,&top,val);
								}
								getchar();
								break;
						case 2: if(top == -1)
								{
									printf("\nUnderflow");
								}
								else
								{
									val = pop(stack,&top);
									printf("\n%d Popped Out of stack",val);
								}
								getchar();
								break;

						case 3: display(stack,top);
								getchar();
								break;

						case 4: goto main;

						default: printf("\nInvalid option entered, Please try again");
								getchar();
					}
					fflush(stdin);
					printf("\nDo You want to do more ");
					scanf("%c",&ch);
					if(ch != 'n' && ch != 'N')
						goto sub1;	
						break;
			
			case 2: sub2:
					printf("\n\n1. Push an element");
					printf("\n2. Pop an element");
					printf("\n3. Print the stack");
					printf("\n4. Previous Menu\n");
					scanf("%d",&choice1);
					switch(choice1)
					{
						case 1:	printf("\nEnter the Value");
								scanf("%d",&val);
								start = listpush(start,val);
								getchar();
								break;
						case 2: if(start == NULL)
								{
									printf("\nUnderflow");
								}
								else
								{
									start = listpop(start);
								}
								getchar();
								break;

						case 3: listdisplay(start);
								getchar();
								break;

						case 4: goto main;

						default: printf("\nInvalid option entered, Please try again");
								getchar();
					}
					fflush(stdin);
					printf("\nDo You want to do more ");
					scanf("%c",&ch);
					if(ch != 'n' && ch != 'N')
						goto sub2;	
						break;

			case 3: ch = 'n';
					break;

			default: printf("\nInvalid option entered, Please try again");
					 getchar();
		}
	}

	return 0;
}

// For Array
void display(int *a,int x)
{
	if(x == -1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nStack is ");
		while(x != -1)
		{
			printf("\n\t%d",*(a+x));
			x--;
		}
	}
}

void push(int *a,int *x,int val)
{
	*x = *x + 1;
	*(a + *x) = val;
}

int pop(int *a,int *x)
{
	*x = *x - 1;
	return *(a + *x);
}

// For List

void listdisplay(Node *head)
{
	Node *temp = head;
	if(head == NULL)
		printf("Stack is Empty");
	else
	{
		printf("\nStack is ");
		while(temp != NULL)
		{
			printf("\n\t%d",temp->data);
			temp = temp->next;
		}
	}
}

Node* listpush(Node *head,int val)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	if(temp == NULL)
		printf("Memory Allocation Failed");
	else
	{
		temp->data = val;
		temp->next = head;
		head = temp;
	}
	return head;
}

Node* listpop(Node *head)
{
	Node *temp = head->next;
	printf("\n%d Popped out of Stack",head->data);
	free(head);
	return temp;
}