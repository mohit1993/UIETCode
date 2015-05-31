#include <iostream>

using namespace std;

void fibo(int,int,int);

int main()
{
	int n;
	cout<<"\nEnter no. of terms needed ";
	cin>>n;
	fibo(n,0,1);
	return 0;
}

void fibo(int n,int first,int second)
{
	if(n>0)
	{	        
		cout<<first<<" ";
		return fibo(n-1,first + second,first);
	}
}

	
