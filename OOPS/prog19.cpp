#include<iostream>

using namespace std;

class Base
{
    public:
        void display()
        {
            cout<<"\nThis is function of base class called privately: ";
            cout<<a;
        }
        void input()
        {
            cout<<"\nTaking input into a for base class privately : ";
            cin>>a;
        }
    private:
        int a;
};

class Derived : private Base
{
    public:
        void display()
        {
            cout<<"\nThis is function of derived class: ";
            cout<<a;
            Base::display();
        }
        void input()
        {
            cout<<"\nThis is input into a for derived class: ";
            cin>>a;
            Base::input();
        }
    private:
        int a;
};

int main()
{
    Derived obj;
    obj.input();
    obj.display();
    cout<<endl<<endl;
    return 0;
}
