#ifndef __COLLEGE_BRANCH_DATA
#define __COLLEGE_BRANCH_DATA

#include "StandardInclusions.h"
#include "CollegeDataHandler.h"

class Subject;
class Semester;
class SubjectData;
class SemesterData;
class BranchData;
class CollegeData;

extern vector<CollegeData> college;
class Subject{
	public:
		Subject();
		Subject(string &sname,string &ssubcode,int cr);
		
		void gradeCalculator(void);

		string name,subcode;
		int credits,marks,grade;
};

class Semester{
	public:
		Semester();
		Semester(int num);

		void sgpaCalculator(void);

		int semesterNumber;
		float sgpa;
		vector<Subject> subjects;
};

class SubjectData{
	public:
		SubjectData();
		SubjectData(ifstream &file);
		SubjectData(string &name,string &code,int cr, bool opt);

		void display(void);
		int getCredits(void);
		bool getOptionalInfo(void);
		string getSubjectCode(void);		
		string getSubjectName(void);
		void saveData(ofstream &file);		

		friend void fillSubjects(vector<Subject> &data,string &col,string &branch,int semNumber);

	private:
		bool optional;
		int credits;
		string subjectName,subjectCode;
};

class SemesterData{
	public:
		SemesterData();
		SemesterData(ifstream &file);

		void display(void);
		void insertNewSubject(void);
		void saveData(ofstream &file);

		friend void fillSubjects(vector<Subject> &data,string &col,string &branch,int semNumber);

	private:
		int numberOfSubjects;
		vector<SubjectData> subjects;
};

class BranchData{
	public:
		BranchData(ifstream &file);
		BranchData(string &name);

		void display(void);
		void insertNewSubject(int sem);
		void insertSemester(void);
		void saveData(ofstream& file);
		string showName(void);

		friend void fillSubjects(vector<Subject> &data,string &col,string &branch,int semNumber);

	private:
		int currentSemester;
		string branchName;
		vector<SemesterData> semesters;
};

class CollegeData{
	public:
		CollegeData();
		CollegeData(string &name);
		CollegeData(ifstream &file);

		void display(void);
		int getNumberOfBranches(void);
		void newBranch(void);
		void newSemester(int i);
		void newSubject(int branch,int sem);
		void saveData(ofstream &file);
		string showBranchName(int i);
		string showCollegeName(void);
		
		friend void fillSubjects(vector<Subject> &data,string &col,string &branch,int semNumber);

	private:
		int numberOfBranches;
		string collegeName;
		vector<BranchData> branches;
};

string showColleges(void);
string showBranches(string &name);
void initialiseData();
void fillSubjects(vector<Subject>& data,string &col,string &branch,int semNumber);

#endif