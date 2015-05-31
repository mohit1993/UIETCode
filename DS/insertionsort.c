#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*,int);

int main()
{
	int *a,n,i;
	printf("Enter Size of the array ");
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);
	printf("\nEnter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	insertionSort(a,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

void insertionSort(int *a,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=i;
		while(a[j] < a[j-1] && j>0)
		{
			a[j] = a[j] + a[j-1] - (a[j-1]=a[j]);
			j--;
		}
	}
}