#include<iostream>

using namespace std;

class Base
{
    public:
        void display()
        {
            cout<<"\nThis is function of base class: ";
            cout<<a;
        }
        void input()
        {
            cout<<"\nTaking input into a for base class: ";
            cin>>a;
        }
    private:
        int a;
};

class Derived : public Base
{
    public:
        void display()
        {
            cout<<"\nThis is function of derived class: ";
            cout<<a;
        }
        void input()
        {
            cout<<"\nThis is input into a for derived class: ";
            cin>>a;
        }
    private:
        int a;
};

int main()
{
    Derived obj;
    obj.input();
    obj.display();
    obj.Base::input();
    obj.Base::display();
    obj.display();
    cout<<endl<<endl;
    return 0;
}
