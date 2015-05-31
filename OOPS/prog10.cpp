#include <iostream>

using namespace std;

class FeetInch;

class Metric
{
	public:
		void input()
		{
			cout<<"\nEnter distance in meter: ";
                        cin>>m;
                        cout<<"\nEnter distance in centimeter: ";
                        cin>>cm;
                        m = m + cm/100;
                        cm = cm%100;
                }

		friend void add(Metric,FeetInch);

        private:
                int m,cm;
};

class FeetInch
{
	public:
		void input()
		{
			cout<<"\nEnter distance in feets: ";
                        cin>>feet;
			cout<<"\nEnter distance in inches: ";
			cin>>inch;
			feet = feet + inch/12;
			inch = inch%12;
		}

		friend void add(Metric,FeetInch);
	private:
		int feet,inch;
};

void add(Metric one,FeetInch two)
{
	int met,cm;
	met = one.m + two.feet/3.28;
	cm = one.cm + two.inch*2.54;
	met = met + cm/100;
	cm = cm%100;
	cout<<"\nTotal Distance is: "<<met<<" m and "<<cm<<" cm";
	cout<<endl<<endl;
}

int main()
{
	Metric met;
	FeetInch fet;
	met.input();
	fet.input();
	add(met,fet);
	return 0;
}
