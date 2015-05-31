#include <iostream>
#include <string>
using namespace std;

class demo
{
    public:
        void input()
        {
            cout<<"\nEnter Name: ";
            cin>>name;
            count++;
        }
        void display()
        {
            cout<<"\nName is "<<name;
        }
        static void staticdisplay();


    private:
        string name;
        static int count;
};

int demo::count = 0;
void demo::staticdisplay()
{
            cout<<"\nNo. of objects made = "<<count;
}

int main()
{
    demo *two,one;
    one.input();
    one.display();
    char ans = 'y';
    while(ans != 'n' && ans != 'N')
    {
        two = new demo;
        two->input();
        two->display();
        cout<<"\nDo you want to do more: ";
        cin>>ans;
    }
    one.staticdisplay();
    cout<<endl<<endl;
    return 0;
}
