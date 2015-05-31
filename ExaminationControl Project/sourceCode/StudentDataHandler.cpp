#include "CollegeBranchData.h"
#include "StudentData.h"
#include "StudentDataHandler.h"
#include "DisplayText.h"

void handlerStudentData(void){
	int n;
	char ans = 'y';
	string filename;
	bool changeindata=0;
	char ch = 'y';
	do{
		system(CLEAR);
		DisplayText text;
		text.display("Students");
		cout<<"\n1. Register New Student";
		cout<<"\n2. Show Students(1 or All)";
		cout<<"\n3. Result System";
		cout<<"\n4. Go To Previous Menu\n";;

		cin>>n;
		switch(n){
			case 1:{
				int status;
				Result NewStudent;
				filename = NewStudent.getCollegeName() + NewStudent.getBranchName() + to_string(NewStudent.getBatch()) + to_string(".txt");
				initialiseStudents(filename);
				students.push_back(NewStudent);
				status = NewStudent.saveInFile(filename);
				if(status == 1){
					cout<<"\nStudent Registered Successfully";
				}
				else{
					cout<<"\nUnable to open file";
					cout<<"\nData Not Saved.";
				}
				students.clear();
			}
			break;

			case 2:{
				int status,choice,year;
				string col,branch,rollno;
				col = showColleges();
				branch = showBranches(col);
				cout<<"\nEnter Batch: ";
				cin>>year;
				filename = col + branch + to_string(year) + to_string(".txt");
				status = initialiseStudents(filename);
				if(status == 0){
					cout<<"Unable to open file";
				}
				else{
					int i;
					do{
						system(CLEAR);
						text.display(col.c_str());
						text.display(branch.c_str());
						cout<<"\n1. Show one Student";
						cout<<"\n2. Show All Students";
						cout<<"\n3. Previous Menu\n";
						cin>>choice;
						if(choice == 1){
							cout<<"\nEnter Roll No: ";
							cin>>rollno;
							for(i=0;i<students.size();i++){
								if(rollno == students[i].getRollNumber())
									break;
							}
							if(i>= students.size()){
								cout<<"\nNo Such Student Exists\n";
							}
							else{
								students[i].displayStudent();
								cout<<"\n\n";
								do{
									system(CLEAR);
									text.display("DETAILS");
									cout<<"\n1. Make Changes";
									cout<<"\n2. Fill Form";
									cout<<"\n3. Show Filled Form";
									cout<<"\n4. Show Result";
									cout<<"\n5. Previous Menu\n";
									cin>>choice;
									switch(choice){
										case 1:
											students[i].makeChanges();
											cout<<"\nChanges Successfully Done";
											students[i].saveInFile(filename);
											break;

										case 2:
											students[i].fillForm();
											cout<<"\nForm Filled Successfully";
											students[i].saveInFile(filename);
											break;

										case 3:
											system(CLEAR);
											students[i].showForm();
											break;

										case 4:
											students[i].displayResult();
											break;
										case 5:
											ans = 'n';
											continue;

										default:
											cout<<"\nInvalid Option";
											ans = 'y';
											continue;
									}
									cout<<"\nWish Do More: ";
									cin>>ans;
								}while(ans != 'n' && ans != 'N');
							}
						}
						else if(choice == 2){
							system(CLEAR);
							text.display(col.c_str());
							text.display(branch.c_str());
							cout<<left<<setw(5)<<"S.no"<<setw(23)<<"Name"<<setw(25)<<"Roll Number"<<setw(20)<<"Contact"<<setw(10)<<"CGPA\n";
							for(int i=0;i<students.size();i++){
								cout<<endl;
								cout<<left<<i+1<<setw(3)<<". "<<setw(10);
								students[i].displayTab();
							}
						}
						else if(choice == 3){
							ans = 'n';
							continue;
						}
					cout<<"\nWish Do More: ";
					cin>>ans;
					}while(ans !='n' && ans != 'n');
					students.clear();
					}
				}
				break;

			case 3:{
				string col,branch;
				col = showColleges();
				branch = showBranches(col);
				int batch;
				cout<<"\nEnter Batch year: ";
				cin>>batch;
				filename = col + branch + to_string(batch) + to_string(".txt");
				int status = initialiseStudents(filename);
				if(status == 0){
					cout<<"Unable to open file";
				}
				else{
					int status = checkFormValidity();
					if(status==1){
						for(int i=0;i<students.size();i++){
							cout<<"\nEnter Marks for Student "<<students[i].getRollNumber()<<endl;
							students[i].inputMarks();
							cout<<"\n";
						}
						ofstream file;
						file.open(filename.c_str(),ios::out);
						file<<students.size()<<" ";
						for(int i=0;i<students.size();i++){
							students[i].saveData(file);
						}
						file.close();
						cout<<"\nResult Saved";
					}
				}
					students.clear();
				}
				break;

			case 4:
				{
					ans = 'n';
					continue;
				}
				break;	
			default:{
				cout<<"\nInvalid Option";
				ans = 'y';
				continue;
			}

		}
		cout<<"\nWish Do More: ";
		cin>>ans;
	}while(ans != 'n' && ans != 'N');

}