#include <iostream>

using namespace std;

class dist
{
	public:
           void input()
	   {
                cout<<"Enter distance in metres: ";
                cin>>dis;
           }
           void display()
           {
                cout<<"Distance is "<<dis;
           }
           friend dist& add(dist one,dist two);

        private:
           int dis;
};

dist& add(dist one,dist two)
{
	dist temp;
	temp.dis = one.dis + two.dis;
        return temp;
}

int main()
{
	dist one,two,three;
        cout<<"\nObject 1: ";
        one.input();
        cout<<"\nObject 2: ";
        two.input();
        three = add(one,two);
        cout<<"\nObject 3: Total ";
        three.display();
        cout<<"\n\n";
        return 0;
}
