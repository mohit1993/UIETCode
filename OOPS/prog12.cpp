#include <iostream>

using namespace std;

class demo
{
	public:
	demo()
	{
		cout<<"\n\nConstructor with no arguments called";
		a = 0;
		b = 0;
		c = 0;
		display();
	}
	demo(int x)
	{
		cout<<"\n\nConstructor with 1 argument called";
		a = b = c = x;
		display();
	}
	demo(int x,int y)
	{
		cout<<"\n\nContructor with 2 arguments called";
		a = x;
		b = y;
		c = 0;
		display();
	}
	demo(int x,int y, int z)
	{
		cout<<"\n\nContructor with 3 arguments called";
		a = x;
		b = y;
		c = z;
		display();
	}

	void display()
	{
		cout<<"\na = "<<a;
		cout<<" b = "<<b;
		cout<<" c = "<<c;
	}

	~demo()
	{
		cout<<"\nObject: ";
		display();
		cout<<"\nDestroyed\n\n";
	}
	private:
		int a,b,c;
};

int main()
{
	demo one,two(1),three(1,2),four(1,2,3);
	cout<<endl;
	one.display();
	two.display();
	three.display();
	four.display();
	cout<<endl<<endl;
	return 0;
}
