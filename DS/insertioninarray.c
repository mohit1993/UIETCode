#include<stdio.h>

void display(int *,int);
int binarysearch(int,int*,int);

int main()
{
	int choice=0,oi=0,uoi=0,i=0,data,oarray[20],uarray[20];
	start:
	printf("Type of Array ");
	printf("\n1. Ordered");
	printf("\n2. Unordered");
	printf("\n\nPress any other key to exit\n");
	scanf("%d",&choice);
	if(choice == 1)
	{
		sub1: 
		printf("\n\n\n1. Display array ");
		printf("\n2. Add value");
		printf("\n3. Remove value");
		printf("\n4. Search value");
		printf("\n5. Return to main menu\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if(oi > 0)
						display(oarray,oi);						
					else{
						printf("\nArray is empty\n");
						getchar();
					}
					break;

			case 2: printf("\n\nEnter the value ");
					scanf("%d",&oarray[oi++]);
					for(i= oi-1 ; i>0 ; i--)
					{
						if(oarray[i] < oarray[i-1])	
							oarray[i-1] = oarray[i] + oarray[i-1] - (oarray[i] = oarray[i-1]);
					}
					display(oarray,oi);
					break;

			case 3: printf("\n\n\nEnter the value ");
					scanf("%d",&data);
					i = binarysearch(data,oarray,oi);
					if(i >= 0)
					{
						oi--;
						while(i<=oi)
						{
							oarray[i] = oarray[i+1];
							i++;
						}
					}
					else
						printf("\nElement not Found");
					display(oarray,oi);
					getchar();
					break;

			case 4: printf("\n\n\nEnter the value ");
					scanf("%d",&data);
					i = binarysearch(data,oarray,oi);
					if(i>=0)
						printf("\nElement Found at position %d",i+1);
					else
						printf("\nElement not Found");
					getchar();
					break;

			case 5: printf("\n\n\n\n");
					goto start;

			default: printf("\n\nYour entered invalid option");
					getchar();
					break;
	  	}
	  	goto sub1;
	}
	else if(choice == 2)
	{
		sub2:
		printf("\n\n\n1. Display array");
		printf("\n2. Add value");
		printf("\n3. Remove value");
		printf("\n4. Search value");
		printf("\n5. Return to main menu\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if(uoi > 0)
						display(uarray,uoi);
					else
						printf("\nArray is empty\n");
					break;

			case 2: printf("\n\nEnter the value ");
					scanf("%d",&uarray[uoi++]);
					display(uarray,uoi);
					break;

			case 3: printf("\n\n\nEnter the value ");
					scanf("%d",&data);
					for(i=0;i<uoi;i++)
					{
						if(data == uarray[i])
							break;
						else if(uoi - i == 1){
							printf("\nElement not found");
							i = -1;
							getchar();
						}
					}
					if(i>=0)
					{
						uarray[i] = uarray[--uoi];
						display(uarray,uoi);	
					}
					break;

			case 4: printf("\n\n\nEnter the value ");
					scanf("%d",&data);
					for(i=0;i<uoi;i++)
					{
						if(data == uarray[i]){
							printf("\nElement found at position %d",i+1);
							break;
						}
						else if(uoi-i == 1)
							printf("\nElement not found");
					}
					getchar();
					break;

			case 5: printf("\n\n\n\n");
					goto start;

			default: printf("\n\nYour entered invalid option");
					getchar();
					break;
	  	}
	  	goto sub2;
	}
	return 0;	
}

void display(int *x,int a)
{
	int i = 0;
	printf("\n\n");
	for(i = 0;i < a;i++)
			printf("%d  ",*(x+i));
	printf("\n");
	getchar();
}

int binarysearch(int data,int *x,int a)
{
	int start = 0,end = a - 1,mid;
	mid = (start + end)/2;
	while(1)
	{
		if(start == end)
		{
			if(*(x + start) == data)
				return start;
			else return -1;
		}
		else if(*(x+mid) == data)
			return mid;

		else if(*(x+mid) > data)
		{
			end = mid - 1;
			mid = (start + end)/2;
		}
		else if(*(x+mid) < data)
		{
			start = mid + 1;
			mid = (start + end)/2;
		}
	}
}