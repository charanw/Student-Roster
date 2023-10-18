#include <iostream>
#include "roster.h"

using namespace std;

int main() {
	bool quit = false;

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jane Doe,janedoe123@gmail.com,25,20,30,17,SOFTWARE"
	};

	cout << "Student Roster CLI App" << endl;

	studentRoster roster;

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++) {
		roster.parseStudentData(studentData[i]);
	};

	cout << "Student roster created." << endl << endl;

	do {
		cout << "What would you like to do?" << endl;
		cout << "1. Print all Students in roster" << endl;
		cout << "2. Print specifc Student in roster" << endl;
		cout << "3. Print students by degree program" << endl;
		cout << "4. Print invalid emails in roster" << endl;
		cout << "5. Find average number of days in course for a student" << endl;
		cout << "6. Remove a student from the roster" << endl;
		cout << "0. Quit program" << endl;
		int input;
		cin >> input;
		if (input == 0) {
			quit = true;
		}
		else if (input == 1) {
			roster.printAll();
		}
		else if (input == 2) {
			cout << "Please enter a student ID: " << endl;
			cin.get();
			string studentID;
			getline(cin, studentID);
			roster.getStudentFromRoster(studentID).printStudentInfo();

		}
		else if (input == 3) {
			cout << "Please enter degree type SECURITY, NETWORK, OR SOFTWARE:" << endl;
			cin.get();
			string studentDegreeProgram;
			getline(cin, studentDegreeProgram);
			Degree degreeProgram = {};
			if (studentDegreeProgram == "SECURITY") {
				degreeProgram = Degree::SECURITY;
				roster.printByDegreeProgram(degreeProgram);
			}
			else if (studentDegreeProgram == "NETWORK") {
				degreeProgram = Degree::NETWORK;
				roster.printByDegreeProgram(degreeProgram);
			}
			else if (studentDegreeProgram == "SOFTWARE") {
				degreeProgram = Degree::SOFTWARE;
				roster.printByDegreeProgram(degreeProgram);
			}
			else {
				cout << "Invalid degree type entered. Please enter degree type of SECURITY, NETWORK, OR SOFTWARE as a single word in all-caps" << endl;
			}
		}
		else if (input == 4) {
			roster.printInvalidEmails();
		}
		else if (input == 5) {
			cout << "Please enter a student ID: " << endl;
			cin.get();
			string studentID;
			getline(cin, studentID);
			roster.printAverageDaysInCourse(studentID);
		}
		else if (input == 6) {
			cout << "Please enter a student ID: " << endl;
			cin.get();
			string studentID;
			getline(cin, studentID);
			roster.remove(studentID);
		}
		else {
			cout << "Invalid entry. Please enter a single number from the choices listed: " << endl << endl;
			cout << "What would you like to do?" << endl;
			cout << "1. Print all Students in roster" << endl;
			cout << "2. Print specifc Student in roster" << endl;
			cout << "3. Print students by degree program" << endl;
			cout << "4. Print invalid emails in roster" << endl;
			cout << "5. Find average number of days in course for a student" << endl;
			cout << "6. Remove a student from the roster" << endl;
			cout << "0. Quit program" << endl;
			cin.get();
			cin >> input;
			break;
		};
	} while (quit == false);
	roster.~studentRoster();
	return 0;
}