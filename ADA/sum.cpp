#include<iostream>

using namespace std;

int sum(int*,int);

int main()
{

	int size = 10,a[10];
	cout<<"\nEnter numbers: ";
	for(int i=0;i<size;i++)
		cin>>a[i];
	int ans;
	ans = sum(a,size);
	cout<<"\nSum is "<<ans;
	return 0;
}

int sum(int *a,int index)
{
	if(index>0)
		return a[index-1] + sum(a,index-1);
	else
	   return 0;
}
