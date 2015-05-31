#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a;
	string name;
	fstream file;
	file.open("temp.txt",ios::out);
	cin>>a;
	cin>>name;
	file<<name<<" "<<a;
	file.close();
	file.open("temp.txt",ios::in);
	file>>name;
	file>>a;
	cout<<a<<" "<<name;
	return 0;
}