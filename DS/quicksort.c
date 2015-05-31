#include <stdio.h>
#include <time.h>
void quicksort(int*,int,int);
int partition(int*,int,int);
int main()
{	
	clock_t start,end;
	double res;
	int arr[1000000],size,i;
	//printf("\nEnter Size of tha array ");
	size = 1000000;
	//printf("\nEnter values : ");
	for(i=0;i<size;i++)
	{
		//printf("\n%d : ",i+1);
		scanf("%d",arr+i);
	}
	/*printf("\nBefore Sorting List is\n");
	for(i=0;i<size;i++)
	{
		printf(" %d ",*(arr+i));
	}*/
	start = clock();
	quicksort(arr,0,size-1);
	end = clock();
	res = (end - start)*1000/CLOCKS_PER_SEC;
	printf("%f",res);
	/*printf("\nAfter Sorting List is");
	for(i=0;i<size;i++)
	{
		printf(" %d ",*(arr + i));
	}*/
	return 0;
}

void quicksort(int *a,int start,int end)
{
	int pos;
	if(start < end)
	{
		pos = partition(a,start,end);
		quicksort(a,start,pos-1);
		quicksort(a,pos+1,end);
	}
}

int partition(int*a,int start,int end)
{
	int pivot,select = start,i = start;
	pivot = rand();
	select = end - start;
	pivot = pivot % select;
	pivot = pivot + start;
	select = (pivot == start)?start+1:start;
	while(i<=end)
	{
		if(a[i] < a[pivot])
		{
			a[i] = a[select] + a[i] - (a[select] = a[i]);
			select++;
			if(select == pivot)
				select++;
		}
		i++;
	}
	a[pivot] = a[pivot] + a[select-1] - (a[select - 1] = a[pivot]);	 
	return (select - 1);
}
