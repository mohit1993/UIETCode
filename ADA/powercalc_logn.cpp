#include <iostream>
using namespace std;
int findpow(int x,int y)
{
	int t=1;
	if(y>1)
	{
		if(y%2==0)
		{
			t = findpow(x,y/2);
			return t*t;
		}
		else{
		t = findpow(x,(y-1)/2);
		return t*t*x;
		}
	}
	else
		return x;
}

int main()
{
	int x,y;
	cin>>x>>y;
	int t = findpow(x,y);
	cout<<t;
	return 0;
}
