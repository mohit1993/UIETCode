#include "CollegeBranchData.h"

vector<CollegeData> college;

Subject::Subject():credits(0),grade(0){}
Subject::Subject(string &sname,string &ssubcode,int cr):name(sname),subcode(ssubcode),credits(cr),grade(0){}

void Subject::gradeCalculator(void){
	if(marks<40)
		grade = 0;
	else if(marks >40 && marks <46)
		grade = 4;
	else
		grade = marks/10 + 1;
}

Semester::Semester():sgpa(0),semesterNumber(0){}
Semester::Semester(int num):sgpa(0.0),semesterNumber(num){}

void Semester::sgpaCalculator(void){
	int totalcredits = 0;
	for(int i=0;i<subjects.size();i++){
		sgpa = sgpa + subjects[i].credits*subjects[i].grade;
		totalcredits = totalcredits + subjects[i].credits;
	}
	sgpa = sgpa/totalcredits;
}

SubjectData::SubjectData():subjectName("\0"),subjectCode("\0"),credits(0),optional(0){}

SubjectData::SubjectData(ifstream &file){
	if(file.bad()){
		cout<<"\nUnable to read file";
		return;
	}
	file>>subjectName;
	file>>subjectCode;
	file>>optional;
	file>>credits;
}

SubjectData::SubjectData(string& name,string& code,int cr,bool opt):subjectName(name),subjectCode(code),credits(cr),optional(opt){}

void SubjectData::display(void){
	cout<<" "<<setw(26)<<subjectName;
	cout<<" "<<setw(5)<<setfill(' ');
	cout<<" "<<setw(5)<<subjectCode;
	cout<<" "<<setw(10)<<setfill(' ');
	cout<<" "<<setw(10)<<((optional>0)?"yes":"no");
}

int SubjectData::getCredits(void){
	return credits;
}

bool SubjectData::getOptionalInfo(void){
	return optional;
}

string SubjectData::getSubjectCode(void){
	return subjectCode;
}

string SubjectData::getSubjectName(void){
	return subjectName;
}

void SubjectData::saveData(ofstream &file){
	if(file.bad()){
		cout<<"\nUnable to write into file";
		return;
	}
	file<<subjectName<<" ";
	file<<subjectCode<<" ";
	file<<optional<<" ";
	file<<credits<<" ";
}

SemesterData::SemesterData():numberOfSubjects(0){}

SemesterData::SemesterData(ifstream &file){
	if(file.bad()){
		cout<<"\nUnable to read file";
		return;
	}
	file>>numberOfSubjects;
	for(int i=0;i<numberOfSubjects;i++){
		subjects.push_back(SubjectData(file));
	}
}

void SemesterData::display(void){
	for(int i=0;i<numberOfSubjects;i++){
		subjects[i].display();
		if(i<numberOfSubjects-1){
			cout<<" "<<setw(80)<<setfill(' ');
		}
		cout<<endl;
	}
}

void SemesterData::insertNewSubject(void){
	string name,code;
	int credit;
	char ch;
	bool opt;
	cout<<"\nEnter Name of the Subject: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\nEnter Subject Code: ";
	cin>>code;
	cout<<"\nCreditS: ";
	cin>>credit;
	cout<<"\nOptional (y/n) : ";
	cin>>ch;
	opt = (ch =='y' || ch == 'Y')?1:0;
	subjects.push_back(SubjectData(name,code,credit,opt));
	numberOfSubjects += 1;
}

void SemesterData::saveData(ofstream &file){
	if(file.bad()){
		cout<<"\nUnable to write into file ";
		return;
	}
	file<<numberOfSubjects<<" ";
	for(int i=0;i<numberOfSubjects;i++){
		subjects[i].saveData(file);
	}
}

BranchData::BranchData(string &name):branchName(name),currentSemester(0){}

BranchData::BranchData(ifstream &file){
	if(file.bad()){
		cout<<"\nUnable to read file";
		return;
	}
	file>>branchName;
	file>>currentSemester;
	for(int i=0;i<currentSemester;i++){
		semesters.push_back(SemesterData(file));
	}
}

void BranchData::display(void){
	cout<<" "<<setw(23)<<branchName;
	for(int i=0;i<currentSemester;i++){
		cout<<" "<<i+1;
		cout<<" "<<setw(22)<<setfill(' ');
		semesters[i].display();
		if(i<(currentSemester-1)){
			cout<<" "<<setw(55)<<setfill(' ');
		}
	}
}

void BranchData::insertNewSubject(int sem){
	semesters[sem].insertNewSubject();
}

void BranchData::insertSemester(void){
	int nos;
	cout<<"\nEnter Number of Subjects: ";
	cin>>nos;
	semesters.push_back(SemesterData());
	currentSemester += 1;
	for(int i=0;i<nos;i++){
		cout<<"\nDetails for Subject "<<i+1;
		semesters[currentSemester-1].insertNewSubject();
		cout<<endl;
	}
}

void BranchData::saveData(ofstream &file){
	if(file.bad()){
		cout<<"\nUnable to write into file";
		return;
	}
	file<<branchName<<" ";
	file<<currentSemester<<" ";
	for(int i=0;i<currentSemester;i++){
		semesters[i].saveData(file);
	}
}

string BranchData::showName(void){
	return branchName;

}

CollegeData::CollegeData(){
	cout<<"\nEnter Name of the College: ";
	cin>>collegeName;
	numberOfBranches = 0;
}

CollegeData::CollegeData(string &name):collegeName(name),numberOfBranches(0){}

CollegeData::CollegeData(ifstream &file){
	if(file.bad()){
		cout<<"\nUnable to read file";
		return;
	}
	file>>collegeName;
	file>>numberOfBranches;
	for(int i=0;i<numberOfBranches;i++){
		branches.push_back(BranchData(file));
	}
}

void CollegeData::display(void){
	cout<<""<<setw(23)<<collegeName;
	for(int i=0;i<numberOfBranches;i++){
		branches[i].display();
		cout<<endl;
		if(i<numberOfBranches-1){
			cout<<" "<<setw(31)<<setfill(' ');
		}
	}
}

int CollegeData::getNumberOfBranches(void){
	return numberOfBranches;
}

void CollegeData::newBranch(void){
	string branchname;
	cout<<"\nEnter Name of the Branch: ";
	cin>>branchname;
	branches.push_back(BranchData(branchname));
	numberOfBranches += 1;
}
void CollegeData::newSemester(int i){
	branches[i].insertSemester();
}

void CollegeData::newSubject(int branch,int sem){
	branches[branch].insertNewSubject(sem);
}

void CollegeData::saveData(ofstream &file){
	if(file.bad()){
		cout<<"\nUnable to write into file";
		return;
	}
	file<<collegeName<<" ";
	file<<numberOfBranches<<" ";
	for(int i=0;i<numberOfBranches;i++){
		branches[i].saveData(file);
	}
}

string CollegeData::showBranchName(int i){
	return branches[i].showName();
}

string CollegeData::showCollegeName(void){
	return collegeName;
}

string showColleges(void){
	int clg;
	for(int i=0;i<college.size();i++){
		cout<<endl<<i+1<<". "<<college[i].showCollegeName();
	}
	cout<<"\nChoose your College: ";
	cin>>clg;
	return college[clg-1].showCollegeName();
}

string showBranches(string &name){
	int i,branch;
	for(i=0;i<college.size();i++){
		if(name == college[i].showCollegeName())
			break;
	}
	for(int j=0;j<college[i].getNumberOfBranches();j++){
		cout<<"\n"<<j+1<<". ";
		cout<<college[i].showBranchName(j);
	}
	cout<<"\nSelect Branch: ";
	cin>>branch;
	return college[i].showBranchName(branch-1);
}

void fillSubjects(vector<Subject> &data,string &col,string &branch,int semNumber){
	int i,j;
	for(i=0;i<college.size();i++){
		if(college[i].showCollegeName() == col)
			break;
	}

	for(j=0;j<college[i].getNumberOfBranches();j++){
		if(college[i].showBranchName(j) == branch)
			break;
	}
	vector<SubjectData> dtemp;
	for(int k=0;k<college[i].branches[j].semesters[semNumber].subjects.size();k++){
		SubjectData temp(college[i].branches[j].semesters[semNumber].subjects[k]);
		if(temp.optional)
			dtemp.push_back(temp);
		else
			data.push_back(Subject(temp.subjectName,temp.subjectCode,temp.credits));
	}
	int choice;
	if(dtemp.size() > 1){
		cout<<"\n\nChoose your Optional Subject: ";
		for(int i=0;i<dtemp.size();i++){
			cout<<"\n"<<i+1<<". "<<dtemp[i].subjectName;
		}
		cout<<endl;
		cin>>choice;
	}
	else if(dtemp.size() == 1)
		choice = 1;
	else return;

	data.push_back(Subject(dtemp[choice-1].subjectName,dtemp[choice-1].subjectCode,dtemp[choice-1].credits));
	return;
}

void initialiseData(void){
	int n,b,no;
	char ch = 'y';
	ifstream data;
	data.open("CollegeDataBase.txt",ios::in);
	int numberOfCollege;
	data>>numberOfCollege;
	for(int i=0;i<numberOfCollege;i++){
		college.push_back(CollegeData(data));
	}
	data.close();
	return;
}