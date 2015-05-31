#include "CollegeBranchData.h"
#include "CollegeDataHandler.h"
#include "DisplayText.h"

void handlerCollegeData(void){
	int n,b,no;
	DisplayText text;
	bool changeindata=0;
	char ch = 'y';
	do{
		system(CLEAR);
		text.display("COLLEGES");
		text.display("DATA");
		cout<<"\n1. New College ";
		cout<<"\n2. New Branch ";
		cout<<"\n3. New Semester";
		cout<<"\n4. New Subject";
		cout<<"\n5. Display";
		cout<<"\nEnter Choice: ";
		cin>>n;
		switch(n){
			case 1:
				college.push_back(CollegeData());
				cout<<"\nCollege added Successfully";
				changeindata = 1;
				break;

			case 2: 
				system(CLEAR);
				for(int i=0;i<(int)college.size();i++){
					cout<<"\n"<<i+1<<". ";
					cout<<college[i].showCollegeName();
				}
				cout<<"\nSelect College: ";
				cin>>n;
				college[n-1].newBranch();
				cout<<"\nBranch Inserted successfully";
				changeindata = 1;
				break;
			case 3: 
				system(CLEAR);
				for(int i=0;i<(int)college.size();i++){
					cout<<"\n"<<i+1<<". ";
					cout<<college[i].showCollegeName();
				}
				cout<<"\nSelect College: ";
				cin>>n;
				for(int i=0;i<college[n-1].getNumberOfBranches();i++){
					cout<<"\n"<<i+1<<". ";
					cout<<college[n-1].showBranchName(i);
				}
				cout<<"\nSelect Branch: ";
				cin>>b;
				college[n-1].newSemester(b-1);
				cout<<"\nInsertion of semester successfull";
				changeindata = 1;
				break;

			case 4: 
				system(CLEAR);
				for(int i=0;i<(int)college.size();i++){
					cout<<"\n"<<i+1<<". ";
					cout<<college[i].showCollegeName();
				}
				cout<<"\nSelect College: ";
				cin>>n;
				for(int i=0;i<college[n-1].getNumberOfBranches();i++){
					cout<<"\n"<<i+1<<". ";
					cout<<college[n-1].showBranchName(i);
				}
				cout<<"\nSelect Branch: ";
				cin>>b;
				cout<<"\nEnter Semester Number: ";
				cin>>no;
				college[n-1].newSubject(b-1,no-1);
				cout<<"\nSuccessfully added new subject";
				changeindata = 1;
				break;	

			case 5:{
				system(CLEAR);
				cout<<"\nS.no\tCollegeName\t\tBranchName\t\tSemester_No.\t\tSubjectName\t\t\tSubjectCode\tOptional\n";
				
				for(int i=0;i<(int)college.size();i++){
					cout<<setw(136)<<setfill('-');
					cout<<""<<setfill(' ');
					cout<<std::left;
					cout<<endl<<" "<<i+1;
					cout<<""<<setw(6)<<setfill(' ');
					college[i].display();
				}
				cout<<endl<<setw(136)<<setfill('-')<<"";
				cout<<endl<<endl;
				cout<<setfill(' ');
			}
			break;
			
			default:{ 
				cout<<"\nInvalid option";
				ch = 'y';
				continue;
			}
		}
		cout<<"\nWish to do more: ";
		cin>>ch;
		if(ch =='n' || ch=='N'){
			break;
		}
	}while(ch != 'N' && ch != 'n');

	if(changeindata == 1){
		ofstream file;
		file.open("DataBase.txt",ios::out);
		file<<college.size()<<" ";
		for(int i=0;i<(int)college.size();i++){
			college[i].saveData(file);
		}
		file.close();
	}
	return;
}