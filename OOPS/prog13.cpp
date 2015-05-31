#include <iostream>

using namespace std;

class demo
{
	public:
		demo()
		{
			cout<<"\nConstructor with no arguments called";
			a = 0;
			display();
		}
		demo(demo& x)
		{
			cout<<"\nConstructor with object as argument called";
			a = x.a+1;
			display();
		}

		void display()
		{
			cout<<"\nA = "<<a;
		}
		demo& fun(demo x,demo y)
		{
			a = x.a + y.a;
			return *this;
		}

	private:
		int a;
};

int main()
{
	demo one,two(one);
	demo three;
	three = two;
	demo four;
	four = three.fun(one,two);
	four.display();
	cout<<endl<<endl;
	return 0;
}
