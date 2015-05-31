#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Student
{
	char rollno[9];
	char name[30];
	char contact[11];
	float cgpa;
	char email[50];
};

void insert(Student *,int&);
int search(Student *,int,char *);
void deleterecord(Student *,int&,char *);
void display(Student *,int);

int main()
{
	int choice = 0,index = -1;
	char ans = 'y',checkroll[9];
	Student data[50];
	while(ans != 'n' && ans != 'N')
 	{
		cout<<"\n1. Insert a new record";
		cout<<"\n2. Search a record";
		cout<<"\n3. Delete a record";
		cout<<"\n4. View all records";
		cout<<"\n5. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nInput the details for the record: ";
				insert(data,index);
				break;
			
			case 2: cout<<"\nEnter the roll no. of the student to search: ";
				getchar();
				cin.getline(checkroll,9);
				search(data,index,checkroll);
				break;
			
			case 3: cout<<"\nEnter the roll no. of the student to delete: ";
				getchar();
				cin.getline(checkroll,9);
				deleterecord(data,index,checkroll);
				break;
			
			case 4: display(data,index);
				break;
			
			case 5: ans = 'n';
				break;
			
			default: cout<<"\nInvalid option selected";
		}
		if(ans != 'n')
		{
			cout<<"\nDo you wish to do more: ";
			fflush(stdin);
			cin>>ans;
		}
	}
	return 0;
}

void insert(Student *data,int &limit)
{
	if(limit == 9)
	{
		cout<<"\nMemory Overflow, Unable to insert new data";
		return;
	}
	limit = limit + 1;
	cout<<"\nEnter Roll Number: ";
	getchar();
	cin.getline(data[limit].rollno,9);
	cout<<"\nEnter Name: ";
	//getchar();
	cin.getline(data[limit].name,30);
	cout<<"\nEnter Contact Number: ";
	//getchar();
	cin.getline(data[limit].contact,11);
	cout<<"\nEnter CGPA: ";
	cin>>data[limit].cgpa;
	cout<<"\nEnter Email: ";
	getchar();
	cin.getline(data[limit].email,50);
	
	cout<<"\nInsertion of the record successful";
	return;
}

int search(Student *data,int limit,char *checkroll)
{
	for(int i=0;i<=limit;++i)
	{
		if(strcmp(data[i].rollno,checkroll) == 0)
		{
			cout<<"\nRecord Found: ";
			cout<<"\nName: "<<data[i].name;
			cout<<"\nRoll No: "<<data[i].rollno;
			cout<<"\nCGPA: "<<data[i].cgpa;
			cout<<"\nContact No: "<<data[i].contact;
			cout<<"\nEmail ID: "<<data[i].email;
			return i;
		}
	}
	cout<<"\nNo Record matches the Roll No: "<<checkroll;
	return -1;
}

void deleterecord(Student *data,int &limit,char *checkroll)
{
	if(limit == -1)
	{
		cout<<"\n Records are empty";
		return;
	}
	int start = search(data,limit,checkroll);
	if(start != -1)
	{
		char ans = 'n';
		cout<<"\nDo you want to delete the above record: ";
		cin>>ans;
		if(ans == 'y' || ans == 'Y')
		{
			for(int i = start;i<limit;i++)
			{
				strcpy(data[i].rollno,data[i+1].rollno);
				strcpy(data[i].name,data[i+1].name);
				strcpy(data[i].contact,data[i+1].contact);
				strcpy(data[i].email,data[i+1].email);
				data[i].cgpa = data[i+1].cgpa;
			}
			limit = limit -1;
			cout<<"\nDeletion of record successful";
		}
	}
}

void display(Student *data,int limit)
{	
	system("clear");
	cout<<"S.no\tRoll_No\t\tName\t\tCGPA\tContact_N0\tEmail_ID\n";
	cout<<"---------------------------------------------------------------------------------";
	for(int i = 0;i<=limit;i++)
	{
		cout<<"\n"<<i+1;
		cout<<"\t"<<data[i].rollno;
		cout<<"\t"<<left<<setw(10)<<data[i].name;
		cout<<"\t"<<data[i].cgpa;
		cout<<"\t"<<data[i].contact;
		cout<<"\t"<<data[i].email;
	}
	return;
}	
	
