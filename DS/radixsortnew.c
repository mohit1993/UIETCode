#include <stdio.h>
#include <stdlib.h>

void radixsort(int*,int);

int main()
{
	int size,*a,i;
	printf("Enter Size of array");
	scanf("%d",&size);
	a = (int*)malloc(sizeof(int)*size);
	printf("\nEnter Values\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nBefore Sorting Array is \n");
	for(i=0;i<size;i++)
	{
		printf("%d  ",a[i]);
	}
	radixsort(a,size);
	printf("\nAfter Sorting Array is \n");
	for(i=0;i<size;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}

void radixsort(int *a,int size)
{
	int *b,max,i,t=1,j,index=0;
	b = (int*)malloc(sizeof(int)*size);
	max = a[0];
	for(i=1;i<size;i++)
	{
		if(max < a[i])
			max = a[i];
	}
	while(max/t > 0)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<size;j++)
			{
				if((a[j]/t)%10 == i)
					b[index++] = a[j];
			}
		}
		for(i=0;i<size;i++)
			a[i] = b[i];
		index = 0;
		t=t*10;
	}
}