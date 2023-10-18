#include <string>
#include <array>
#include "degree.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
	Student();

	Student(string id, string fName, string lName, string email, int age, int numDays1, int numDays2, int numDays3, Degree degree)
		: studentID{ id }, firstName{ fName }, lastName{ lName }, emailAddress{ email }, age{ age }, numDaysToCompleteCourse{numDays1, numDays2, numDays3}, degreeProgram{ degree } {
	};
	
	~Student();

	string getStudentID();
	void setStudentID(string ID);

	string getFirstName();
	void setFirstName(string fName);

	string getLastName();
	void setLastName(string lName);

	string getEmailAddress();
	void setEmailAddress(string email);

	int getAge();
	void setAge(int studentAge);

	int getNumDaysToCompleteCourse(int i);
	void setNumDaysToCompleteCourse(int numDays1, int numDays2, int numDays3);

	Degree getDegreeProgram();
	void setDegreeProgram(Degree studentDegreeProgram);
	static string degreeProgramToString(Degree studentDegreeProgram);

	//Prints all of a students details, called by the printAll() roster method
	void printStudentInfo();
private:
	string studentID = {};
	string firstName = {};
	string lastName = {};
	string emailAddress = {};
	int age = {};
	int numDaysToCompleteCourse[3] = {};
	Degree degreeProgram = {};
};

#endif