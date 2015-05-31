#include <iostream>

using namespace std;

class demo;
class demo1;
class demo2;


class demo
{
	public:
	   friend void input(demo&,demo1&,demo2&);
       friend void display(demo,demo1,demo2);

	private:
       int a;
};

class demo1
{
	public:
	   friend void input(demo&,demo1&,demo2&);
       friend void display(demo,demo1,demo2);

	private:
	   int a;
};


class demo2
{
	public:
	   friend void input(demo&,demo1&,demo2&);
	   friend void display(demo,demo1,demo2);

    private:
       int a;
};

void input(demo &zero,demo1 &one,demo2 &two)
{
        cout<<"\nInput for demo: ";
        cin>>zero.a;
        cout<<"\nInput for demo1: ";
        cin>>one.a;
        cout<<"\nInput for demo2: ";
        cin>>two.a;
}

void display(demo zero,demo1 one, demo2 two)
{
	    cout<<"\nValue of demo: "<<zero.a;
            cout<<"\nValue of demo1: "<<one.a;
	    cout<<"\nValue of demo2: "<<two.a;
	    cout<<endl;
	    cout<<endl;
}

int main()
{
	demo zero;
	demo1 one;
	demo2 two;
	input(zero,one,two);
	display(zero,one,two);
        return 0;
}


