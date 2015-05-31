#include <iostream>

using namespace std;

class datetime
{
    public:
        void input()
        {
            cout<<"\nEnter Hours: ";
            cin>>hr;
            cout<<"\nEnter Minutues: ";
            cin>>minute;
            hr = hr + minute/60;
            minute = minute%60;
            cout<<"\nEnter Seconds: ";
            cin>>sec;
            minute = minute + sec/60;
            hr = hr + minute/60;
            minute = minute%60;
            sec = sec%3600;
        }
        void display()
        {
            cout<<"\nTime is "<<hr<<":"<<minute<<":"<<sec;
        }

        void combine(datetime one,datetime two)
        {
            hr = one.hr + two.hr;
            minute = one.minute + two.minute;
            sec = one.sec + two.sec;
            hr = hr + minute/60 + sec/3600;
            minute = minute%60 + sec/60;
            sec = sec%3600;
        }
    private:
        int hr,minute,sec;

};

int main()
{
    datetime one,two,three;
    one.input();
    two.input();
    three.combine(one,two);
    one.display();
    two.display();
    cout<<"\nCombined time is : ";
    three.display();
    return 0;
}
