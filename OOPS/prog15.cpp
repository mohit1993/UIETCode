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
        Complex operator + (Complex x)
        {
            Complex temp;
            temp.real = real + x.real;
            temp.img = img + x.img;
            return temp;
        }

        friend Complex operator - (Complex x, Complex y);

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

Complex operator - (Complex x, Complex y)
{
    Complex temp;
    temp.real = x.real - y.real;
    temp.img = x.img - y.img;
    return temp;
}

int main()
{
    Complex one,two(2),three(2,3);
    one = two + three;
    cout<<endl<<endl;
    two.display();
    cout<<" + ";
    three.display();
    cout<<" = ";
    one.display();
    cout<<endl;
    one = two - three;
    two.display();
    cout<<" - ";
    three.display();
    cout<<" = ";
    one.display();
    cout<<endl<<endl;
    return 0;
}