 #include <stdio.h>

void display(int*,int,int,int,int);
int enqueue(int*,int*,int*,int*,int);
int dequeue(int*,int*,int*,int*,int);

int main()
{
	int *queue,front = -1,rear = -1,choice=0,tag=0,size;
	char ch = 'y';
	printf("\nEnter size of the array");
	scanf("%d",&size);
	queue = (int*)malloc(size * sizeof(int));
	if(queue == NULL)
	{
		printf("\nMemory Allocation Failed");
		getchar();
		return 0;
	}
	while(ch != 'n' || ch != 'N')
	{
		main:
		printf("\nWhat to do");
		printf("\n1. Display");
		printf("\n2. Enqueue");
		printf("\n3. Dequeue");
		printf("\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: display(queue,front,rear,tag,size);
					getchar();
					break;

			case 2: enqueue(queue,&front,&rear,&tag,size);
					getchar();
					break;

			case 3: dequeue(queue,&front,&rear,&tag,size);
					getchar();
					break;

			case 4: return 0;

			default: printf("\nInvalid option Entered");
					 goto main;
		}
		fflush(stdin);
		printf("\nDo you want to do more ");
		scanf("%c",&ch);
	}
	return 0;
	}

void display(int *arr,int front,int rear,int tag,int size)
{
	if(front == -1)
	{
		printf("\nQueue is empty");
	}
	else
	{	printf("\n");
		while(front != rear)
		{
			printf("%d   ",*(arr + front));
				front = (front + 1)%size;
		}
		printf("%d   ",*(arr + front));
	}
}

int enqueue(int *arr,int *front,int *rear,int *tag,int size)
{
	if(*tag == 1)
	{
		printf("\nOverflow");
		return 0;
	}
	else
	{
		if(*front == -1)
		{
			*front = (*front + 1)%size;
		}
		*rear = (*rear + 1)%size;
		printf("\nEnter value");
		scanf("%d",(arr + *rear));
		if((*rear+1)%size == *front && *tag == 0)
			*tag = 1;
	}
}

int dequeue(int *arr,int *front,int *rear,int *tag,int size)
{
	if(*front == *rear && *tag == 0)
	{
		printf("\nUnderFlow");
		return 0;
	}
	else
	{
		printf("\n%d Dequeued",*(arr + *front));
		*front = (*front + 1)%size;
		if(*tag == 1)
			*tag = 0;
		return 0;
	}
}