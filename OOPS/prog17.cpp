#include <iostream>
#include <cmath>
using namespace std;
class ComplexRectangular;
class ComplexSphercial;

class ComplexSpherical
{
    public:
        ComplexSpherical()
        {
            r=theta=0;
        }
        ComplexSpherical(float x)
        {
            r = x;
            theta = 0;
        }
        ComplexSpherical(float x,float i)
        {
            r = x;
            theta = i;
        }
        
        void display()
        {
            cout<<r<<"("<<cos(theta)<<" + i"<<sin(theta)<<")";
        }

    private:
        float r,theta;
};

class ComplexRectangular
{
    public:
        ComplexRectangular()
        {
            real=img=0;
        }
        ComplexRectangular(int r)
        {
            real=img=r;
        }
        ComplexRectangular(int r,int i)
        {
            real = r;
            img = i;
        }

        operator ComplexSpherical()
        {
            float r = sqrt(real*real + img*img);
            float theta = atan(img/real);
            ComplexSpherical temp(r,theta);
            return temp;
        }

        ComplexRectangular operator + (int x)
        {
            ComplexRectangular temp;
            temp.real = real + x;
            temp.img = img;
            return temp;
        }

        friend ComplexRectangular operator + (int,ComplexRectangular t);

        void display()
        {
            if(img < 0)
                cout<<"("<<real<<") - i("<<-1*img<<")";
            else
                cout<<"("<<real<<") + i("<<img<<")";
        }

        operator int()
        {
            return sqrt(real*real + img*img);
        }

        void operator = (int x)
        {
            real = x;
            img = 0;
        }
    
    private:
        int real,img;
};

ComplexRectangular operator + (int x,ComplexRectangular t)
{
    ComplexRectangular temp;
    temp.real = t.real + x;
    temp.img = t.img;
    return temp;
}

int main()
{
    ComplexRectangular one(1,1);
    ComplexSpherical two;
    two = one;
    cout<<"Rectangular System: ";
    one.display();
    cout<<"\nSpherical System: ";
    two.display();
    int x = one;
    cout<<"\nTypcasting object to integer: x = "<<x;
    int y = 5;
    one = 5;
    cout<<"\nTypcasting integer to object: one = ";
    one.display();
    cout<<endl;
    one.display();
    one = one + 5;
    cout<<" + 5 = ";
    one.display();
    cout<<"\n5 + ";
    one.display();
    cout<<" = ";
    one = 5 + one;
    one.display();
    cout<<endl<<endl;
    return 0;
}