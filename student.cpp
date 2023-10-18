#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student()
{
};

Student::~Student() {
};

string Student::getStudentID() {
	return studentID;
};

void  Student::setStudentID(string ID) {
	studentID = ID;
	return;
}

string Student::getFirstName() {
	return firstName;
};

void  Student::setFirstName(string fName) {
	firstName = fName;
	return;
}

string Student::getLastName() {
	return lastName;
};

void  Student::setLastName(string lName) {
	lastName = lName;
	return;
}

string Student::getEmailAddress() {
	return emailAddress;
};

void  Student::setEmailAddress(string email) {
	emailAddress = email;
	return;
}

int Student::getAge() {
	return age;
}

void Student::setAge(int studentAge) {
	age = studentAge;
	return;
}

int Student::getNumDaysToCompleteCourse(int i) {
	return numDaysToCompleteCourse[i];
};

void Student::setNumDaysToCompleteCourse(int numDays1, int numDays2, int numDays3) {
	numDaysToCompleteCourse[0] = numDays1;
	numDaysToCompleteCourse[1] = numDays2;
	numDaysToCompleteCourse[2] = numDays3;
	return;
};

Degree Student::getDegreeProgram() {
	return degreeProgram;
};
void Student::setDegreeProgram(Degree studentDegreeProgram) {
	degreeProgram = studentDegreeProgram;
	return;
};
static string degreeProgramToString(Degree studentDegreeProgram);

//Converts the enumerated degree type into a string
string Student::degreeProgramToString(Degree studentDegreeProgram) {
	string degreeString[3] = { "SECURITY", "NETWORK", "SOFTWARE" };
	string degreeProgram = degreeString[2];
	if (studentDegreeProgram == Degree::SECURITY) {
		degreeProgram = degreeString[0];
		return degreeProgram;
	}
	else if (studentDegreeProgram == Degree::NETWORK) {
		degreeProgram = degreeString[1];
		return degreeProgram;
	}
	else {
		return degreeProgram;
	}
};

void Student::printStudentInfo() {
		cout << setw(2) << studentID << "\t"
			<< setw(10) << firstName << "\t"
			<< setw(10) << lastName << "\t"
			<< setw(22) << emailAddress << "\t"
			<< setw(4) << age << "\t"
			<< setw(2) << "{" << numDaysToCompleteCourse[0] << "," << numDaysToCompleteCourse[1] << "," << numDaysToCompleteCourse[2] << "}" << "\t"
			<< setw(10) << degreeProgramToString(degreeProgram) << endl;
		return;
};