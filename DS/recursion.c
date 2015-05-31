#include <stdio.h>

int fact(int);
int binary(int*,int,int,int);
int linear(int*,int,int);
int sum(int*,int);
int permut(int,int);

int main()
{
	int a,b,val,choice,res,i,pos,*arr;
	char ch = 'y';
	while(ch != 'N' && ch != 'n')
	{
		printf("Enter your choice :\n");
		printf("1. Factorial of a no.\n");
		printf("2. Binary Search on an array\n");
		printf("3. Linear Search on an array\n");
		printf("4. Summation of Elements of an array\n");
		printf("5. Permutation\n");
		scanf("%d",&choice);	
		switch(choice)
		{
			case 1: printf("\n\nEnter the no. ");
					scanf("%d",&a);		
					res = fact(a);
					printf("\nFactorial of the number is %d",res);
					break;
		
			case 2: printf("\n\nEnter size of the array ");
					scanf("%d",&a);
					arr = (int*)malloc(a*sizeof(int));
					printf("\nEnter elements in to the array (Ascending Order): ");
					for(i=0;i<a;i++)
					{
						scanf("%d",&arr[i]);
					}
					printf("\nEnter value search ");
					scanf("%d",&val);
					pos = binary(arr,0,a-1,val);
					if(pos != -1)
						printf("\nElement Found at position %d",pos+1);
					else
						printf("\nElement Not Found");

					break;
			case 3: printf("\n\nEnter size of the array");
					scanf("%d",&a);
					arr = (int*)malloc(a*sizeof(int));
					printf("\nEnter elements in to the array :");
					for(i=0;i<a;i++)
					{
						scanf("%d",&arr[i]);
					}
					printf("\nEnter value search ");
					scanf("%d",&val);
					pos = linear(arr,a,val);
					if(pos != -1)
						printf("\nElement Found at position %d",pos+1);
					else
						printf("\nElement Not Found");

					break;

			case 4: printf("\n\nEnter size of the array ");
					scanf("%d",&a);
					arr = (int*)malloc(a*sizeof(int));
					printf("\nEnter elements in to the array :");
					for(i=0;i<a;i++)
					{
						scanf("%d",&arr[i]);
					}
					a = sum(arr,a);
					printf("\nSum of the Elements is %d",a);
					break;

			case 5: printf("\nEnter n and r for nPr: ");
					scanf("%d %d",&a,&b);
					res = permut(a,b);
					printf("\nPermutation %dP%d is %d",a,b,res);
					break;
			default: printf("\nInvalid Option Entered,Please try again");
					getchar();
					continue;

		}
		getchar();
		printf("\nDo you want to do more ");
		fflush(stdin);
		scanf("%c",&ch);
	}	

		return 0;
}

int fact(int n)
{
	if(n<3)
		return n;
	return n*fact(n-1);
}

int binary(int*a,int start,int end,int val)
{
	int mid;
	mid = (start + end)/2;
	if(start == end)
	{
		if(a[mid] == val)
			return mid;
		else
			return -1;
	}
	else if(a[mid] == val)
	{
		return mid;
	}
	else if(a[mid] > val)
	{
		end = mid - 1;
		binary(a,start,end,val);
	}
	else if(a[mid] < val)
	{
		start = mid + 1;
		binary(a,start,end,val);
	}
}

int linear(int*a,int end,int val)
{

	if(a[end] == val)
		return end;
	else if(end == -1)
		return end;
	else
		linear(a,end-1,val);
}

int sum(int*a,int end)
{
	if(end == 1)
		return a[0];

	return a[end-1] + sum(a,end-1);
}

int permut(int n,int r)
{
	if(n == r + 1 )
		return n;
	return n*permut(n-1,r);
}