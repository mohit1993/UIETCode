#include "CollegeBranchData.h"
#include "StudentData.h"

vector<Result> students;

Student::Student(){

	batch = getCurrentYear();
	cout<<"\nRollno: ";
	cin>>rollNumber;
	cout<<"\nRegistration number: ";
	cin>>registrationNumber;
	cout<<"\nStudent's Name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\nFather's Name: ";
	getline(cin,fatherName);
	cout<<"\nMother's Name: ";
	getline(cin,motherName);
	cout<<"\nAddress: ";
	getline(cin,address);
	cout<<"\nContact Number: ";
	cin>>contact;
	cout<<"\nEmail ID: ";
	cin>>email;
	cout<<"\nGender(1 for Male and 0 for Female): ";
	cin>>gender;
	cout<<"\nDate Of Birth:\nDate: ";
	cin>>dateOfBirth;
	cout<<"Month: ";
	cin>>monthOfBirth;
	cout<<"Year: ";
	cin>>yearOfBirth;
	collegeName = showColleges(); 
	branchName = showBranches(collegeName);
}

Student::Student(ifstream &file){
	file>>batch;
	file>>rollNumber;
	file>>registrationNumber;
	int size=0;
	char temp;
	file>>size;
	getline(file,name,'#');
	/*name = name + temp;
	for(int i=0;i<=size;i++){
		file.get(temp);
		name = name + temp;
	}*/
	file>>size;
	getline(file,fatherName,'#');
	file>>size;
	getline(file,motherName,'#');
	file>>size;
	getline(file,address,'#');
	/*while(file.get(temp) == " "){
		continue;
		size--;
	}
	fatherName = fatherName + temp;
	for(int i=0;i<=size;i++){
		file.get(temp);
		fatherName = fatherName + temp;
	}
	file>>size;
	while(file.get(temp) == " "){
		continue;
		size--;
	}
	motherName = motherName + temp;
	for(int i=0;i<=size;i++){
		file.get(temp);
		motherName = motherName + temp;
	}
	file>>size;
	while(file.get(temp) == " "){
		continue;
		size--;
	}
	address = address + temp;
	for(int i = 0;i<=size;i++){
		file.get(temp);
		address = address + temp;
	}*/
	file>>contact;
	file>>email;
	file>>gender;
	file>>dateOfBirth;
	file>>monthOfBirth;
	file>>yearOfBirth;
	file>>collegeName;
	file>>branchName;
}

bool Student::operator > (Result &t){
	if(rollNumber > t.rollNumber)
		return 1;
	else
		return 0;
}
void Student::saveData(ofstream &file){
	int i=0;
	file<<batch<<" ";
	file<<rollNumber<<" ";
	file<<registrationNumber<<" ";
	while(name[i] == ' '){
		i++;
	}
	file<<(name.size() - i)<<" ";
	for(int x=i;x<name.size();x++){
		file<<name[x];
	}
	file<<"# ";
	i=0;
	while(fatherName[i] == ' '){
		i++;
	}
	file<<(fatherName.size() - i)<<" ";
	for(int x=i;x<fatherName.size();x++){
		file<<fatherName[x];
	}
	file<<"# ";
	i=0;
	while(motherName[i] == ' '){
		i++;
	}
	file<<(motherName.size() - i)<<" ";
	for(int x=i;x<motherName.size();x++){
		file<<motherName[x];
	}
	file<<"# ";
	i=0;
	while(address[i] == ' '){
		i++;
	}
	file<<(address.size() - i)<<" ";
	for(int x=i;x<address.size();x++){
		file<<address[x];
	}
	file<<"# ";
	file<<contact<<" ";
	file<<email<<" ";
	file<<gender<<" ";
	file<<dateOfBirth<<" "<<monthOfBirth<<" "<<yearOfBirth<<" ";
	file<<collegeName<<" ";
	file<<branchName<<" ";
}

void Student::makeChanges(void){
	int choice;
	char ans = 'y';
	do{
		system("clear");
		displayStudent(1);
		cin.ignore();
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				cout<<"\nEnter New Roll No: ";
				cin>>rollNumber;
				break;
			
			case 2: 
				cout<<"\nEnter New Registration No: ";
				cin>>registrationNumber;
				break;

			case 3:
				cout<<"\nEnter New Name : ";
				getline(cin,name);
				break;

			case 4: 
				cout<<"\nEnter New Father's Name: ";
				getline(cin,fatherName);
				break;	
				
			case 5: 
			cout<<"\nEnter New Mother's Name: ";
				getline(cin,motherName);
				break;
				
			case 6: 
				cout<<"\nEnter New Contact No: ";
				cin.ignore();
				cin>>contact;
				break;
			
			case 7:
				cout<<"\nEnter New Address: ";
				getline(cin,address);	
				break;
				
			case 8: 
				cout<<"\nEnter New Date Of Birth:\nDate: ";
				cin>>dateOfBirth;
				cout<<"Month: ";
				cin>>monthOfBirth;
				cout<<"Year: ";
				cin>>yearOfBirth;
				break;
				
			case 9: 
				cout<<"\nEnter New Gender(1 for male and 0 for female): ";
				cin>>gender;
				break;
				
			case 10:
				cout<<"\nEnter New Email ID: ";
				cin>>email;
				break;
				
			case 11: 
				cout<<"\nEnter New College: ";
				collegeName = showColleges();
				break;
				
			case 12: 
				cout<<"\nEnter New Branch: ";
				branchName = showBranches(collegeName);
				break;
				
			default:
				cout<<"\nInvalid Option Entered: ";
				break;
		}
		cout<<"\nDo you want to make more changes: ";
		cin>>ans;

	}while(ans != 'N' && ans != 'n');
}

void Student::displayStudent(int x){
	if(x==0){
		cout<<"\nBatch: "<<batch;
		cout<<"\nRoll Number: "<<rollNumber;
		cout<<"\nRegistration Number: "<<registrationNumber;
		cout<<"\nStudents Name: "<<name;
		cout<<"\nFathers Name: "<<fatherName;
		cout<<"\nMothers Name: "<<motherName;
		cout<<"\nContact Number: "<<contact;
		cout<<"\nAddress: "<<address;
		cout<<"\nDate of Birth: "<<dateOfBirth<<"/"<<monthOfBirth<<"/"<<yearOfBirth;
		cout<<"\nGender: "<<((gender>0)?"Male":"Female");
		cout<<"\nEmail ID: "<<email;
		cout<<"\nCollege: "<<collegeName;
		cout<<"\nBranch: "<<branchName;		
	}

	else{
		cout<<"\n1. Roll Number: "<<rollNumber;
		cout<<"\n2. Registration Number: "<<registrationNumber;
		cout<<"\n3. Students Name: "<<name;
		cout<<"\n4. Fathers Name: "<<fatherName;
		cout<<"\n5. Mothers Name: "<<motherName;
		cout<<"\n6. Contact Number: "<<contact;
		cout<<"\n7. Address: "<<address;
		cout<<"\n8. Date of Birth: "<<dateOfBirth<<"/"<<monthOfBirth<<"/"<<yearOfBirth;
		cout<<"\n9. Gender: "<<((gender>0)?"Male":"Female");
		cout<<"\n10. Email ID: "<<email;
		cout<<"\n11. College: "<<collegeName;
		cout<<"\n12. Branch: "<<branchName;
	}
}

string Student::getRollNumber(void){
	return rollNumber;
}

string Student::getCollegeName(void){
	return collegeName;
}

string Student::getBranchName(void){
	return branchName;
}

int Student::getBatch(void){
	return batch;
}

SemesterInfo::SemesterInfo():Student(),currentSemester(0){}

SemesterInfo::SemesterInfo(ifstream &file):Student(file){
	file>>currentSemester;
	int size;
	for(int i=0;i<currentSemester;i++){
		Semester temp;
		file>>temp.semesterNumber;
		file>>temp.sgpa;
		file>>size;
		for(int j=0;j<size;j++){
			Subject dtemp;
			file>>dtemp.name;
			file>>dtemp.subcode;
			file>>dtemp.credits;
			file>>dtemp.marks;
			file>>dtemp.grade;
			temp.subjects.push_back(dtemp);
		}
		semesters.push_back(temp);
	}
}

void SemesterInfo::fillForm(){
	currentSemester += 1;
	semesters.push_back(Semester(currentSemester));
	fillSubjects(semesters[currentSemester-1].subjects,collegeName,branchName,currentSemester-1);
	//cout<<"\nForm Filled Successfully\n";
}

void SemesterInfo::showForm(){
	cout<<endl;
	displayStudent();
	cout<<"\nSubjects Filled: ";
	cout<<"\n\n";
	cout<<"S.no"<<right<<setw(9)<<"Name"<<setw(8)<<"Code"<<setw(11)<<"Credits\n";
	for(int i=0;i<semesters[currentSemester-1].subjects.size();i++){
		cout<<endl<<i+1<<". "<<setw(10)<<semesters[currentSemester-1].subjects[i].name<<"\t"<<semesters[currentSemester-1].subjects[i].subcode<<setw(10)<<semesters[currentSemester-1].subjects[i].credits;
	}
}

void SemesterInfo::saveData(ofstream &file){
	Student::saveData(file);
	file<<currentSemester<<" ";
	for(int i=0;i<currentSemester;i++){
		file<<semesters[i].semesterNumber<<" ";
		file<<semesters[i].sgpa<<" ";
		int subsize = semesters[i].subjects.size();
		file<<subsize<<" ";
		for(int j=0;j<subsize;j++){
			file<<semesters[i].subjects[j].name<<" ";
			file<<semesters[i].subjects[j].subcode<<" ";
			file<<semesters[i].subjects[j].credits<<" ";
			file<<semesters[i].subjects[j].marks<<" ";
			file<<semesters[i].subjects[j].grade<<" ";
		}
	}
}

Result::Result():SemesterInfo(),cgpa(0.0){}

Result::Result(ifstream &file):SemesterInfo(file){
	file>>cgpa;
}

void Result::cgpaCalculator(void){
	double total = 0.0;
	for(int i=0;i<currentSemester;i++){
		total = total + semesters[i].sgpa;
	}
	cgpa = total/currentSemester;
}

void Result::inputMarks(void){
	for(int i=0;i<semesters[currentSemester-1].subjects.size()	;i++){
		cout<<"Enter Marks for "<<semesters[currentSemester-1].subjects[i].name<<": ";
		cin>>semesters[currentSemester-1].subjects[i].marks;
		semesters[currentSemester-1].subjects[i].gradeCalculator();
	}
	semesters[currentSemester-1].sgpaCalculator();
	cgpaCalculator();
}

void Result::displayResult(void){
	int semesterNo = 0;
	bool done = 0;
	do{
		//system("clear");
		cout<<"\nEnter Semester No. :";
		cin>>semesterNo;
		if(semesterNo>0 && semesterNo<= semesters.size()){
			cout<<"\n\n";
			cout<<setw(5)<<"S.no"<<setw(10)<<"Name"<<setw(10)<<"Grade\n";
			for(int i=0;i<semesters[semesterNo-1].subjects.size();i++){
				cout<<i+1<<". "<<right<<setw(11)<<semesters[semesterNo-1].subjects[i].name;
				cout<<setw(6)<<semesters[semesterNo-1].subjects[i].grade;
				cout<<endl;
			}
			cout<<"\n"<<setw(10)<<"SGPA = "<<semesters[semesterNo-1].sgpa;
			cout<<"\n"<<setw(10)<<"CGPA = "<<setprecision(2)<<cgpa<<"\n";
			done = 1;
		}
		else{
			cout<<"\nPlease enter a valid semester Number ";
			done = 0;
		}
	}while(done==0);
}

void Result::saveData(ofstream &file){
	SemesterInfo::saveData(file);
	file<<cgpa<<" ";
}

int Result::saveInFile(string filename){
	sortResult();
	ofstream file;
	file.open(filename.c_str(),ios::out);
	if(file.good() != 1){
		return 0;
	}
	file<<students.size()<<" ";
	for(int i=0;i<students.size();i++){
		students[i].saveData(file);
	}
	file.close();
	return 1;
}

void Result::displayTab(void){
	cout<<setw(24)<<name<<setw(25)<<rollNumber<<setw(20)<<contact<<setw(10)<<cgpa;
}

int initialiseStudents(string filename){
	ifstream file;
	file.open(filename.c_str(),ios::in);
	if(file.good() != 1){
		return 0;
	}
	int size;
	file>>size;
	for(int i=0;i<size;i++){
		students.push_back(Result(file));
	}
	file.close();
	return 1;
}

void sortResult(void){
	int size = students.size();
	int i=0;
	Result temp(students[size-1]);
	for(i=size-1;i>0;i--){
		if(students[i-1] > students[i]){
			students[i] = students[i-1];
		}
		else
			break;
	}
	students[i] = temp;
	return;
}

int checkFormValidity(void){
	int maxsem=0;
	string ans;
	for(int i=0;i<students.size();i++){
		if(students[i].currentSemester > maxsem)
			maxsem = students[i].currentSemester;
	}
	for(int i=0;i<students.size();i++){
		if(students[i].currentSemester < maxsem){
			ans = ans + students[i].getRollNumber() + " ";
		}
	}
	if(ans.size() == 0){
		return 1;
	}
	else{
		cout<<"\nFollowing Students haven't filled the form\n";
		cout<<ans;
		return 0;
	}
}