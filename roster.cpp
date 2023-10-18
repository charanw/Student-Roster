#include "roster.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Creates a new student object with the output from parseStudentData() and adds it to to the roster
void studentRoster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, Degree degreeProgram) {
		studentObjArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeProgram);
	return;
};

void studentRoster::parseStudentData(string studentData) {
	size_t right = studentData.find(","); //Finds first comma and sets it to right
	string studentID = studentData.substr(0, right); //Sets all characters to the left of the first comma to studentID

	size_t left = right + 1; //Next character to the right becomes new start
	right = studentData.find(",", left); //Finds the next comma after the new start
	string firstName = studentData.substr(left, right - left); //Sets all characters between new bounds to firstName, this process then repeats for each item in the string

	left = right + 1;
	right = studentData.find(",", left);
	string lastName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string emailAddress = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	int age = stoi(studentData.substr(left, right - left));  //Converts string data to integer for age. Same process for each number of days to go later into an integer array.

	left = right + 1;
	right = studentData.find(",", (left));
	int numDays1 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", (left));
	int numDays2 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", (left));
	int numDays3 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	string stringDegreeProgram = studentData.substr(left, right - left);

	//Convert string into Degree type
	Degree degreeProgram = Degree::SOFTWARE;
	if (stringDegreeProgram == "SECURITY") {
		degreeProgram = Degree::SECURITY;
	}
	else if (stringDegreeProgram == "NETWORK") {
		degreeProgram = Degree::NETWORK;
	};

	add(studentID, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeProgram);
	i++; //Iterates the integer that keeps track of the parse loop's corresponding roster array element
};

Student studentRoster::getStudentFromRoster(string studentID) {
	Student student;
	for (i = 0; i < sizeof(studentObjArray) / sizeof(studentObjArray[0]); i++) {
		if ((studentObjArray[i]->getStudentID()) == studentID) {
			student = *studentObjArray[i];
			return student;
		}
	}
	return student;
};

void studentRoster::remove(string studentID) {
	int i = 0;
	while (i < sizeof(studentObjArray)/sizeof(studentObjArray[0])) {
		if (studentObjArray[i] == nullptr) {
			cout << "The student with the ID " << studentID << " was not found." << endl;
			return;
		}
		else if (studentObjArray[i]->getStudentID() == studentID) {
			cout << "Removing " << studentID << endl << endl;
			studentObjArray[i] = nullptr;
			return;
		}
		else if (i == (sizeof(studentObjArray) / sizeof(studentObjArray[0])) - 1 ){
			cout << "The student with the ID " << studentID << " was not found." << endl;
			return;
		}
		else if (studentObjArray[i]->getStudentID() != studentID) {
			i++;
		};
	};

};

void studentRoster::printAll() {
	cout << "Displaying all students: " << endl << endl;
	cout << setw(2) << "ID" << "\t"
		<< setw(10) << "First Name" << "\t"
		<< setw(10) << "Last Name" << "\t"
		<< setw(22) << "Email Address" << "\t"
		<< setw(4) << "Age" << "\t"
		<< setw(10) << "# of Days" << "\t"
		<< setw(10) << "Degree Program" << endl;
	for (int i = 0; i < sizeof(studentObjArray) / sizeof(studentObjArray[0]); i++) {
		if (studentObjArray[i] != nullptr) {
			studentObjArray[i]->printStudentInfo();
		};
	};
	cout << endl << endl;
	return;
};

void studentRoster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < sizeof(studentObjArray) / sizeof(studentObjArray[0]); i++) {
		if (studentObjArray[i]->getStudentID() == studentID) {
			int numDays[3] = {};
			for (int j = 0; j < 3; j++) {
				numDays[j] = studentObjArray[i]->getNumDaysToCompleteCourse(j);
			}
			double sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += numDays[j];
			}
			double avgNumDays = sum / 3.0;
			cout << "Student ID: " << studentObjArray[i]->getStudentID() << ", average days in course is: " << avgNumDays << endl;	
		}
	}; 
	return;
};

void studentRoster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl << endl;
	for (int i = 0; i < sizeof(studentObjArray) / sizeof(studentObjArray[0]); i++) {
		if ((studentObjArray[i]->getEmailAddress().find(' ') != string::npos) || 
			(studentObjArray[i]->getEmailAddress().find('@') | studentObjArray[i]->getEmailAddress().find('.')) == string::npos) {
			cout << studentObjArray[i]->getEmailAddress() << " - is invalid." << endl;
		};
	};
	cout << endl;
};

void studentRoster::printByDegreeProgram(Degree degreeProgram) {
	cout << "Showing students in degree program " << Student::degreeProgramToString(degreeProgram) << ":" << endl << endl;
	for (int i = 0; i < sizeof(studentObjArray) / sizeof(studentObjArray[0]); i++) {
		if (studentObjArray[i]->getDegreeProgram() == degreeProgram) {
			studentObjArray[i]->printStudentInfo();
		};
	};
	cout << endl;
}

studentRoster::~studentRoster()
{
	return;
}
;