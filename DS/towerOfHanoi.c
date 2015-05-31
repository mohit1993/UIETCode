#include <stdio.h>

void towerOfHanoi(int,char,char,char);

int main()
{
	int n;
	printf("Enter no. of elements in Tower Of Hanoi");
	scanf("%d",&n);
	printf("\n");
	towerOfHanoi(n,'A','B','C');
	return 0;
}

void towerOfHanoi(int n,char From,char Use,char To)
{
	if(n==1)
	{	printf("\nMove Disc 1 from %c to %c",From,To);
		return;
	}
	towerOfHanoi(n-1,From,To,Use);
	printf("\nMove Disc %d from %c to %c",n,From,To);
	towerOfHanoi(n-1,Use,From,To);
}