#include <stdio.h>
#include <math.h>

void radixsort(int*,int,int [][10],int*);
void enqueue(int [][10],int,int,int*);
int dequeue(int [][10],int*,int*);

int main()
{
	int queue[10][10];
	int a[10],head[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		head[i] = 0;
	}
	printf("\nBefore Sorting Array is \n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	radixsort(a,10,queue,head);
	printf("\nAfter Sorting Array is \n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
void radixsort(int *a,int n,int queue[][10],int *head)
{
	int max = a[0],x,k=10,i,temp;
	for(i = 1;i<n;i++)
	{
		if(max < a[i])
			max = a[i];
	}
	temp = max;
	max = 0;
	while(temp)
	{
		max = max + 1;
		temp = temp/10;
	}
	while(max--)
	{
		for(i=0;i<n;i++)
		{
			x = (a[i]*10/k)%10;
			enqueue(queue,x,a[i],head);
		}
		k=k*10;
		dequeue(queue,head,a);
	}
}

void enqueue(int a[][10],int x,int val,int *head)
{
	a[x][head[x]] = val;
	head[x] = head[x] + 1;
}

int dequeue(int queue[][10],int *head,int *a)
{
	int i,k=0,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<head[i];j++)
		{
			a[k] = queue[i][j];
			k++;
		}
		head[i] = 0;
	}
}