#include <iostream>

using namespace std;

class Base1
{
	public:
		Base1(int x):a(x)
		{
			cout<<"\nSingle Argument Constructor for Base1";
		}
		Base1()
		{
			cout<<"\nDefault Constructor for Base1";
			a=0;
		}
		void display()
		{
			cout<<"\nThis is display of Base1: "<<a;
		}
		void input()
		{
			cout<<"\nInput of Base1: ";
			cin>>a;
		}

	private:
		int a;
};

class Base2
{
	public:
		Base2()
		{
			a=0;
			cout<<"\nDefault Constructor for Base2";
		}
		Base2(int x):a(x)
		{
			cout<<"\nSingle Argument Constructor for Base2";
		}
		void display()
		{
			cout<<"\nThis is display of Base2: "<<a;
		}
		void input()
		{
			cout<<"\nInput of Base2: ";
			cin>>a;
		}

	private:
		int a;
};

class Derived:public Base1,public Base2
{
	public:
		Derived():Base1(),Base2()
		{
			cout<<"\nDefault Constructor for Derived";
			a=0;		
		}
		
		Derived(int x,int y,int z):Base1(x),Base2(y)
		{
			cout<<"\nThree Argument Constructor for Derived";
			a = z;
		}
		
		void display()
		{
			cout<<"\nThis is display of derived class: "<<a;
			Base1::display();
			Base2::display();
		}

		void input()
		{
			cout<<"\nInput of Derived: ";
			cin>>a;
			Base1::input();
			Base2::input();
		}

	private:
		int a;
};

int main()
{
	Derived obj,ob(1,2,3);
	cout<<"\nObject with no Arguements: ";	
	obj.display();
	cout<<"\nObject with Argument: ";
	ob.display();
	cout<<endl;
	return 0;
}
