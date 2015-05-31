#include <iostream>
#include <stdlib.h>

using namespace std;

void insert(int*,int*,int,int);
void del(int*,int*,int);
int search(int*,int,int);
void display(int*,int);
void quicksort(int*,int,int);
int partition(int*,int,int);

int main()
{
	int choice=0,val=0,pos=0,data[50],index = -1;
	char ans = 'y';
	while(ans != 'n' && ans != 'N')
	{	system("clear");
		cout<<"\n1. Add an element";
		cout<<"\n2. Delete an element";
		cout<<"\n3. Search an element";
		cout<<"\n4. View the list";
		cout<<"\n5. Sort the list";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: cout<<"\n\nEnter the value: ";
					cin>>val;
					cout<<"\nEnter the position(0-n)";
					cin>>pos;
					insert(data,&index,val,pos);
					break;

			case 2:	cout<<"\nEnter the value: ";
					cin>>val;
					del(data,&index,val);
					break;

			case 3: cout<<"\nEnter the value: ";
					cin>>val;
					pos = search(data,index,val);
					if(pos != -1)
						cout<<"Element "<<val<<" found at position "<<pos;
					else
						cout<<"ELement "<<val<<" not found";
					break;

			case 4: display(data,index);
					break;

			case 5:	quicksort(data,0,index);
					break;

			case 6: ans = 'n';
					break;

			default:cout<<"\nInvalid option entered";
					break;
		}

		if(ans != 'n')
		{
			cout<<"\nDo you wish to do more? ";
			cin>>ans;
		}
	}
	return 0;
}

void insert(int *a,int *index,int val,int pos)
{
	if(*index == 50)
	{
		cout<<"\nInsufficient memory";
		return;
	}
	int temp = -1;
	(*index == -1)?(temp = 0):temp = *index+1;
	while(temp > pos && temp>=0)
	{
		a[temp] = a[temp-1];
		temp--;
	}
	a[temp] = val;
	*index = *index + 1;
	cout<<"\nElement "<<val<<" inserted";
	return;
}

int search(int *a,int index,int val)
{
	while(index >= 0)
	{
		if(a[index] == val)
		{
			return index;
		}
		index--;
	}
	return -1;
}

void del(int *a,int *index,int val)
{
	int pos = -1;
	pos = search(a,*index,val);
	if(pos != -1)
	{
		a[pos] = a[*index];
		*index = *index - 1;
		cout<<"\nElement "<<val<<" deleted";
	}
	else
		cout<<"Element "<<val<<" not found";
	return;
}

void display(int *a,int index)
{
	cout<<"\n";
	for(int i= 0 ;i<=index;i++)
		cout<<a[i]<<" ";
	return;
}

void quicksort(int *a,int start,int end)
{
	if(start < end)
	{
		int p = partition(a,start,end);
		quicksort(a,start,p-1);
		quicksort(a,p+1,end);
	}
	return;
}

int partition(int *a,int start,int end)
{
	int pivot = start,select = start+1,i = start+1;
	for(;i<=end;i++)
	{
		if(a[i] < a[pivot])
		{
			a[select] = a[i] + a[select] - (a[i] = a[select]);
			select++;
		}
	}
	a[pivot] = a[select-1] + a[pivot] - (a[select-1] = a[pivot]);
	return select-1;
}