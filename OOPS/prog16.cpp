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
        friend istream& operator >> (istream&,Complex& );
        friend ostream& operator << (ostream&,Complex);

    private:
        int real,img;
};

istream& operator >> (istream &input,Complex &x)
{
    cout<<"\nReal Part: ";
    input>>x.real;
    cout<<"Imaginary Part: ";
    input>>x.img;
    cout<<"\nInput taken is: "<<x;
    return input;
}

ostream& operator << (ostream& output,Complex x)
{
    if(x.img < 0)
        output<<"("<<x.real<<") - i("<<-1*x.img<<")";
    else
        output<<"("<<x.real<<") + i("<<x.img<<")";
    return output;
}

int main()
{
    Complex one,two;
    cout<<"Overloaded Extraction Operator: ";
    cin>>one>>two;
    cout<<"\nOverloaded Insertion Operator: "<<one<<" and "<<two;
    cout<<endl<<endl;
    return 0;
}