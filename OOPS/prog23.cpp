#include <iostream>
#include <string>

using namespace std;

class Employee
{
	public:
		Employee(string ename,int esalary,int bonusrate,int incentiverate)
		{
			name = ename;
			salary = esalary;
			bonus = bonusrate;
			healthincentive = incentiverate;
		}
		void saveBonus(int x)
		{
			bonus = x;
		}
		void saveHealthIncentive(int x)
		{
			healthincentive = x;
		}
		void calculateSalary()
		{
			salary = salary + salary*(bonus + healthincentive)/10;
		}
		int getSalary()
		{
			return salary;
		}
		string name;
	private:
		int salary;
		int bonus;
		int healthincentive;
};

class MedLab:public Employee
{
	public:
		MedLab(string name,int salary,int bonusrate,int incentiverate):Employee(name,salary,bonusrate,incentiverate){}
		void getSales()
		{
			cout<<"\nInput Sale: ";
			cin>>sales;
			if(sales > 1000000)
				processSales();
		}
		void processSales()
		{
			int rate;
			rate = 1*sales/200000;
			saveBonus(rate);
			saveHealthIncentive(rate);
			calculateSalary();
		}

	private:
		int sales;
};

int main()
{
	MedLab one("Mohit",1000,5,10);
	one.getSales();
	one.calculateSalary();
	int x = one.getSalary();
	cout<<"\nSalary of "<<one.name<<" is "<<x;
	cout<<endl<<endl;
	return 0;
}
