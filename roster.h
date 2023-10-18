#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

using namespace std;

class studentRoster {
public:
    //Parses string const data which then calls add() to create a roster object with an array of pointers to student objects
    void parseStudentData(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, Degree degreeProgram);

    Student getStudentFromRoster(string studentID);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(Degree degreeProgram);

    ~studentRoster();

private:
    //Integer to keep track of the parse loop's corresponding roster array element
    int i = 0;
    //Defines an array of pointers to student objects
    Student* studentObjArray[5] = {};
};

#endif