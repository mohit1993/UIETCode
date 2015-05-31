#include "CollegeBranchData.h"
#include "StudentData.h"
#include "StudentDataHandler.h"
#include "DisplayText.h"

int getCurrentYear(){
	time_t temp;
	struct tm *local;
	time(&temp);
	local = localtime(&temp);
	int year = 0;
	year = local->tm_year + 1900;
	return year;
}
int main()
{
	initialiseData();
	DisplayText text;
	char ans = 'y';
	int choice;
	do{
		system(CLEAR);
		text.display("EXAMINATION");
		text.display("CONTROL");
		text.display("SYSTEM");
		cout<<"\n\n\n";
		cout<<"\n1. College Data";
		cout<<"\n2. Student Data";
		cout<<"\n3. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:{
				system(CLEAR);
				handlerCollegeData();
				ans = 'y';
			}
			break;

			case 2:{	
				system(CLEAR);
				handlerStudentData();
			}		
				break;
			case 3:{
				ans = 'n';
				continue;
			}
			default:{
				cout<<"\nInvalid Option";
				ans = 'y';
				continue;
			}
		}
		cout<<"\nDo You Wish Do More: ";
		cin>>ans;
	}while(ans != 'n' && ans != 'N');
	system(CLEAR);
	cout<<"\nMade By: \n";
	text.display("Mohit");
	text.display("Saisha");
	text.display("Yogesh");
	cout<<"\n\n";
	return 0;
}