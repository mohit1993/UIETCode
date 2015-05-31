#include<iostream>

using namespace std;

class Base
{
    protected:
        int a;
};

class Derived : protected Base
{
    public:
        void display()
        {
            cout<<"\nThis is function of derived class: ";
            cout<<a;
            cout<<"\nThis is value of a inherited protectedly: ";
            cout<<Base::a;
        }
        void input()
        {
            cout<<"\nThis is input into a for derived class: ";
            cin>>a;
            cout<<"\nThis is input into a for base class inherited protectedly: ";
            cin>>Base::a;
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
