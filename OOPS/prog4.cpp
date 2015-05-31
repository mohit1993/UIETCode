#include <iostream>
#include <string>

using namespace std;

class FirstName
{
    public:
        char GetStringChar(int index);
        void getName()
        {
            cout<<firstName;
        }
        FirstName(string name)
        {
                    firstName = name;
                    int i=0;
                    while(name[i] != '\0')
                    {
                        //firstName[i] = name[i];
                        i++;
                    }
                    length = i;
        }
    private:
        string firstName;
        int length;
};

class LastName
{
    public:
        char GetStringChar(int index);
        void getName()
        {
            cout<<lastName;

        }
        LastName(string name)
        {
                    int i=0;
                    lastName = name;
                    while(name[i] != '\0')
                    {
                        //lastName[i] = name[i];
                        i++;
                    }
                    length = i;
        }

    private:
        string lastName;
        int length;

};

class FullName
{
    public:
        string getName()
        {
            cout<<fullName;
        }
        /*void add(char x,int i)
        {
            fullName[i] = x;
        }*/
        void cpy(string name)
        {
            fullName = name;
        }

    private:
        string fullName;
};

char FirstName::GetStringChar(int index)
{
    if(index < length)
    {
        return firstName[index];
    }
    else
    return '\0';
}

char LastName::GetStringChar(int index)
{
    if(index < length)
    {
        return lastName[index];
    }
    else
    return '\0';
}

int main()
{   string firstname = "Mohit",lastname = "Goyal",name,temp;
    temp[0] = 'c';
    cout<<"Enter first name: ";
    cin>>firstname;
    cout<<"\nEnter last name: ";
    cin>>lastname;
    FirstName first(firstname);
    LastName last(lastname);
    FullName fullname;
    for(int i=0;i<11;i++)
    {
        if(first.GetStringChar(i) != '\0')
        {
            //name.add(first.GetStringChar(i),i);
            name = name + first.GetStringChar(i);
            if(first.GetStringChar(i+1) == '\0')
            {
                name = name + " ";
                continue;
            }

        }
        else if(last.GetStringChar(i-5) != '\0')
            //name.add(last.GetStringChar(i-6),i);
            name = name + last.GetStringChar(i-5);
        else
        {
            //name.add('\0',i);
            name = name + '\0';
            fullname.cpy(name);
            break;
        }
    }
    //first.getName();
    //last.getName();
    fullname.getName();
    return 0;
}
