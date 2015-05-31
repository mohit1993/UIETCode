#include <iostream>

using namespace std;

class sample
{
    public:
        sample()
        {
            a = 0;
        }
        void input()
        {
            cout<<"Enter no. ";
            cin>>a;
            if(a > 0)
                pos++;
            else if(a<0)
                neg++;
            else
                zero++;
        }
        void display()
        {
            cout<<"No of positives = "<<pos<<"\nNo. of Negatives = "<<neg<<"\nNo. of Zeroes = "<<zero;

        }
    private:
        int a;
        static int pos;
        static int neg;
        static int zero;
};

int sample::pos = 0;
int sample::neg = 0;
int sample::zero = 0;


int main()
{
    int i;
    sample one;
    char ans = 'y';
    while(ans != 'n' && ans != 'N')
    {
        one.input();
        cout<<"\nDo you wish to do more: ";
        cin>>ans;
    }
    one.display();
    return 0;
}
