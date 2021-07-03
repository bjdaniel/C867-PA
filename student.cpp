#include "student.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// Student class default constructor
Student::Student() {
	// Initialize all class members with empty/zero values
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmailAddress = "";
	this->studentAge = 0;
	this->studentDegreeProgram = UNDEFINED;	
	
	// Iterate through the numDaysToComplete integer array using public const int Student::numClasses
	// as the upper limit of the for loop, and initialize each element to zero.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		this->numDaysToComplete[classIndex] = 0;
	}
}

// Student class constructor
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress,
				int studentAge, int* numDaysToComplete, DegreeProgram studentDegreeProgram) {
	// Initialize all class members based on arguments passed to constructor
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmailAddress = studentEmailAddress;
	this->studentAge = studentAge;
	this->studentDegreeProgram = studentDegreeProgram;

	// Iterate through the numDaysToComplete integer array using public const int Student::numClasses
	// as the upper limit of the for loop, and initialize each element using the numDaysToComplete integer
	// pointer that was passed to the constructor.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		this->numDaysToComplete[classIndex] = numDaysToComplete[classIndex];
	}
}

string Student::GetStudentID() {
	return this->studentID;
}

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

string Student::GetStudentFirstName() {
	return this->studentFirstName;
}

void Student::SetStudentFirstName(string studentFirstName) {
	this->studentFirstName = studentFirstName;
}

string Student::GetStudentLastName() {
	return this->studentLastName;
}

void Student::SetStudentLastName(string studentLastName) {
	this->studentLastName = studentLastName;
}

string Student::GetStudentEmailAddress() {
	return this->studentEmailAddress;
}

void Student::SetStudentEmailAddress(string studentEmailAddress) {
	this->studentEmailAddress = studentEmailAddress;
}

int Student::GetStudentAge() {
	return this->studentAge;
}

void Student::SetStudentAge(int studentAge) {
	this->studentAge = studentAge;
}

int* Student::GetNumDaysToComplete() {
	return this->numDaysToComplete;
}

void Student::SetNumDaysToComplete(int* numDaysToComplete) {
	// Iterate through the numDaysToComplete integer array using public const int Student::numClasses
	// as the upper limit of the for loop, and set each element using the numDaysToComplete integer
	// pointer that was passed to the constructor.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		this->numDaysToComplete[classIndex] = numDaysToComplete[classIndex];
	}
}

DegreeProgram Student::GetStudentDegreeProgram() {
	return this->studentDegreeProgram;
}

void Student::SetStudentDegreeProgram(DegreeProgram studentDegreeProgram) {
	this->studentDegreeProgram = studentDegreeProgram;
}

// Prints a tab-separated list of student data in the prescribed format:
// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::Print() {
	cout << GetStudentID() << '\t'
		<< "First name: " << GetStudentFirstName() << '\t'
		<< "Last name: " << GetStudentLastName() << '\t'
		<< "Age: " << GetStudentAge() << '\t'
		<< "daysInCourse: {";

	// Iterate through the daysToCompleteArray integer array using public const int Student::numClasses
	// as the upper limit of the for loop, and cout each array element value.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		// Follow up each array element, except the last, with a comma.
		if (classIndex < (Student::numClasses - 1)) {
			cout << numDaysToComplete[classIndex] << ", ";
		}
		else {
			cout << numDaysToComplete[classIndex];
		}
	}

	cout << "} " << "Degree Program: ";

	switch (studentDegreeProgram) {
	case SECURITY:
		cout << "Security" << endl;
		break;
	case SOFTWARE:
		cout << "Software" << endl;
		break;
	case NETWORK:
		cout << "Network" << endl;
		break;
	default:
		cout << "Undefined" << endl;
		break;
	}
}