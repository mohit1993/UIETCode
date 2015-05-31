#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex()
        {
            real=img=0;
        }
        Complex(int r)
        {
            real=img=r;
        }
        Complex(int r,int i)
        {
            real = r;
            img = i;
        }
        Complex& operator ++()
        {
            ++real;
            return *this;
        }
        Complex operator ++(int)
        {
            Complex temp;
            temp.real = real;
            temp.img = img;
            real++;
            return temp;
        }
        
        friend Complex& operator--(Complex&);
        friend Complex operator--(Complex&,int);

        void display()
        {
            if(img < 0)
                cout<<"("<<real<<") - i("<<-1*img<<")";
            else
                cout<<"("<<real<<") + i("<<img<<")";
        }
    private:
        int real,img;
};

Complex& operator--(Complex &x)
{
    --x.real;
    return x;
}

Complex operator--(Complex &x,int unused)
{
    Complex temp;
    temp.real = x.real;
    temp.img = x.img;
    x.real--;
    return temp;
}

int main()
{
    Complex one,two(2),three(2,3);
    cout<<"\nBefore Pre-Increment: ";
    one.display();
    cout<<"\nAfter Pre-Increment: ";
    ++one;
    one.display();
    cout<<"\nBefore Post-Increment: ";
    two.display();
    Complex temp = two++;
    cout<<"\nAfter Post-Increment: ";
    temp.display();
    cout<<"\nIncremented Value : ";
    two.display();
    cout<<"\nBefore Pre-Decrement: ";
    three.display();
    cout<<"\nAfter Pre-Decrement: ";
    --three;
    three.display();
    cout<<"\nAfter Post-Decrement: ";
    temp = three--;
    temp.display();
    cout<<"\nDecremented Value: ";
    three.display();
    cout<<endl<<endl;
    return 0;
}