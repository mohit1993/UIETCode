#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	ofstream output("destination.txt");
	ifstream input("source.txt");
	if(output.bad() || input.bad())
	{
		cout<<"\nError in opening files";
		return 1;
	}
	while(!input.eof())
	{
		cin.getline(str);
		output<<str;
	}
	output.close();
	input.close();
	return 0;
}