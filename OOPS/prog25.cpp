#include <iostream>

using namespace std;

class Base
{
	private:
		int a;
	public:
		void display()
		{
			cout<<"\nBase Class a = "<<a;
		}

		void input()
		{
			cout<<"\nInput for Base: ";
			cin>>a;
		}
};

class Base1 : virtual public Base
{
	private:
		int a;
	public:
		void display()
		{
			cout<<"\nBase1 Class a = "<<a;
			//Base::display();
		}

		void input()
		{	
			cout<<"\nInput for Base1: ";
			cin>>a;
			//Base::input();
		}

};

class Base2: virtual public Base
{
	private:
		int a;
	public:
		void display()
		{
			cout<<"\nBase2 Class a = "<<a;
		}

		void input()
		{
			cout<<"\nInput for Base2: ";
			cin>>a;
		}
};

class Derive: virtual public Base1,virtual public Base2
{
	private:
		int a;
	public:
		void display()
		{
			cout<<"Derived Class a = "<<a;
			Base1::display();
			Base2::display();
			Base::display();
		}

		void input()
		{
			cout<<"\nInput for Derive Class";
			cin>>a;
			Base1::input();
			Base2::input();
			Base1::Base::input();
		}
};

int main()
{
	Derive obj;
	obj.input();
	obj.display();
	return 0;
}