#include <iostream>
using namespace std;

class activity
{
public:
	int *starttime;
	int *endtime;
	int size;
	int *activities;
	int sizen;
	activity()
	{
		cout<<"\nEnter the size of list: ";
		cin>>size;
		starttime = new int[size];
		endtime = new int[size];
	}
	void input()
	{
		cout<<"\nEnter start time of activities: ";
		for(int i=0;i<size;i++)
		{
			cin>>starttime[i];
		}
		cout<<"\nEnter end time of activities: ";
		for(int i=0;i<size;i++)
		{
			cin>>endtime[i];
		}
		sortdata();
	}
	void sortdata()
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=0;j<size-i-1;j++)
			{
				if(endtime[j] > endtime[j+1])
				{
					starttime[j] = starttime[j] + starttime[j+1] - (starttime[j+1] = starttime[j]);
					endtime[j] = endtime[j] + endtime[j+1] - (endtime[j+1] = endtime[j]);
				}
			}
		}
	}
	void selectactivies()
	{
		int temp[size],n=0;
		temp[0] = 0;
		n=1;
		for(int i=1;i<size;i++)
		{
			if(endtime[temp[n-1]] <= starttime[i])
			{
				temp[n] = i;
				n++;
			}
		}
		activities = new int[n];
		sizen = n;
		for(int i=0;i<n;i++)
		{
			activities[i] = temp[i];
		}
	}
	void showresult()
	{
		cout<<"\n";
		for(int i=0;i<size;i++)
		{
			cout<<"\t"<<i+1;
		}
		cout<<"\n\n";
		for(int i=0;i<size;i++)
		{
			cout<<"\t"<<starttime[i];
		}
		cout<<"\n";
		for(int i=0;i<size;i++)
		{
			cout<<"\t"<<endtime[i];
		}
		cout<<"\n\nNo. of activities selected: "<<sizen<<"\n"<<"Selected Activities ";
		
		for(int i=0;i<sizen;i++)
		{
			cout<<activities[i]+1<<" ";
		}
	}
};
int main()
{
	activity x;
	x.input();
	x.selectactivies();
	x.showresult();
	return 0;
}