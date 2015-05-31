#ifndef _Student_Data_H

#define _Student_Data_H

class Student;
class SemesterInfo;
class Result;

class Student{
	public:
		Student();
		Student(ifstream &file);

		void saveData(ofstream &file);
		void makeChanges(void);
		void displayStudent(int =0);
		string getRollNumber(void);
		string getCollegeName(void);
		string getBranchName(void);
		int getBatch(void);
		bool operator > (Result &t);

	protected:
		string name,contact,registrationNumber,rollNumber,collegeName,branchName,collegeIndex,branchIndex;
		int batch;

	private:
		string address,fatherName,motherName,email;
		bool gender;
		int dateOfBirth,monthOfBirth,yearOfBirth;
};


class SemesterInfo:public Student{
	public:
		SemesterInfo();
		SemesterInfo(ifstream &file);

		void fillForm(void);
		void showForm(void);
		void saveData(ofstream &file0);

	protected:
		vector<Semester> semesters;
		int currentSemester;
};

class Result: public SemesterInfo{
	public:
		Result();
		Result(ifstream &file);
		void cgpaCalculator(void);
		void inputMarks(void);
		void displayResult(void);
		void saveData(ofstream &file);
		int saveInFile(string filename);
		void displayTab(void);
		friend int checkFormValidity(void);
	protected:
		double cgpa;
};

void sortResult(void);
extern vector<Result> students;
int initialiseStudents(string filename);
int checkFormValidity(void);
#endif