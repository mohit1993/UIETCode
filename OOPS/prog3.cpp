#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Employee
{
public:
    void input();
    string get_id();
    void display();
    void recpy(Employee);
    void tabdisplay();

private:
    string emp_id;
    string name;
    string department;
    string company;
    int salary;
    string contact;
};

void Employee::input()
{
    cout<<"\nEnter the employee ID: ";
    cin>>emp_id;
    cout<<"\nEnter Name: ";
    cin>>name;
    cout<<"\nEnter Deparment: ";
    cin>>department;
    cout<<"\nEnter Company: ";
    cin>>company;
    cout<<"\nEnter Salary: ";
    cin>>salary;
    cout<<"\nEnter Contact No: ";
    cin>>contact;
}

string Employee::get_id()
{
    return emp_id;
}

void Employee::display()
{
    cout<<"\nEmployee ID: "<<emp_id;
    cout<<"\nEmployee Name: "<<name;
    cout<<"\nSalary: "<<salary<<"\tDepartment: "<<department;
    cout<<"\nCompany :"<<company<<"\tContact: "<<contact;
}

void Employee::tabdisplay()
{
    cout<<"\t"<<emp_id;
    cout<<"\t"<<name;
    cout<<"\t"<<contact;
    cout<<"\t"<<salary;
    cout<<"\t"<<department;
    cout<<"\t\t"<<company;
}

void Employee::recpy(Employee x)
{
    name = x.name;
    emp_id = x.emp_id;
    contact = x.contact;
    company = x.company;
    department = x.department;
    salary = x.salary;
}

void display(Employee *rec,int &index)
{
    cout<<"S.no\tID\tName\tContact\t\tSalary\tDepartment\tCompany";
    for(int i=0;i<=index;i++)
    {
        cout<<"\n"<<i+1;
        rec[i].tabdisplay();
    }
}
int main()
{
    int choice,index = -1;
    Employee record[50];
    char ans = 'y';
    string search_id;

    while(ans != 'n' && ans != 'N')
    {
    cout<<"\n1.Insert a new record";
    cout<<"\n2.Search a record";
    cout<<"\n3.Delete a record";
    cout<<"\n4.View all records";
    cout<<"\n5.Exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1: if(index == 50)
                {
                    cout<<"\nMemory Overflow";
                    break;
                }
                else
                {
                    index++;
                    record[index].input();
                    cout<<"\nInserted into the records";
                    break;
                }

        case 2: cout<<"\nEnter Employee ID to search";
                cin>>search_id;
                for(int i = 0;i<=index;i++)
                {
                    if(search_id == record[i].get_id())
                    {
                        cout<<"\nRecord Found: ";
                        record[i].display();
                        break;
                    }
                }
                break;

        case 3: cout<<"\nEnter Employee ID to delete";
                cin>>search_id;
                for(int i = 0;i<=index;i++)
                {
                    if(search_id == record[i].get_id())
                    {
                        cout<<"\nRecord Found: ";
                        record[i].display();
                        cout<<"\nDo you want to delete: ";
                        char reply = 'n';
                        fflush(stdin);
                        cin>>reply;
                        if(reply =='y' || reply == 'Y')
                        {
                            for(int x = i;x<index;x++)
                            {
                                record[x].recpy(record[x+1]);
                            }
                            index--;
                            cout<<"\nDeletion Successful";
                        }
                        break;
                    }
                }
                break;

        case 4: display(record,index);
                break;

        case 5: ans = 'n';
                break;
        default : cout<<"Invalid choice entered";
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
