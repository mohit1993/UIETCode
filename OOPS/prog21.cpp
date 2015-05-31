#include <iostream>

using namespace std;

class Base1
{
	public:
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
	Derived obj;
	obj.input();
	obj.display();
	cout<<endl;
	return 0;
}