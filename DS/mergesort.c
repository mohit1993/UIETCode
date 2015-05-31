#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

//int b[1000000];
void mergesort(int*,int,int,int,int);
void splitmerge(int*,int,int,int);

int main()
{
	//clock_t start,end;
	//double res;
	//int a[1000000],i,size;
	int size,*a,i;
	printf("\nNo. of Elements in array: ");
	scanf("%d",&size);
	//size = 1000000;
	a = (int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++)
	{
		scanf("%d",a+i);
	}
	printf("\n\nBefore Sorting");
	for(i=0;i<size;i++)
	{
		printf(" %2d",a[i]);
	}
	//start = clock();
	splitmerge(a,0,size - 1,size);
	//end = clock();
	//res = (end-start)*1000/CLOCKS_PER_SEC;
	//printf("%f",res);
	printf("\n\nAfter Sorting");
	for(i=0;i<size;i++)
	{
		printf(" %2d",a[i]);
	}
	return 0;
}

void splitmerge(int *a,int start,int end,int size)
{
	int mid,i;
	if(start == end)
		return;
	mid = (start + end)/2;
	splitmerge(a,start,mid,size);
	splitmerge(a,mid+1,end,size);
	mergesort(a,start,mid,end,size);
}

void mergesort(int *a,int start,int mid,int end,int size)
{
	int i = start,begin = start,m = mid + 1,k,*b;
	b = (int*)malloc(sizeof(int)*size);
	while(start <= mid && m <= end)
	{
		if(a[start] < a[m])
		{
			b[i] = a[start];
			start++;
			i++;
		}
		else
		{
			b[i] = a[m];
			m++;
			i++;
		}
	}
	if(m > end)
	{
		for(k=start;k<=mid;k++)
			b[i++] = a[k];
	}
	else
	{
		for(k = m;k<=end;k++)
			b[i++] = a[k];
	}

	for(i=begin;i<=end;i++)
	{
		a[i] = b[i];
	}
}