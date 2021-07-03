#include "roster.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Roster::Roster() {
	// Nothing to do if default constructor is called. Any record additions will need to be done manually
	// using the Roster::Add() function.
}

Roster::Roster(const string* studentInputData, int numRecords) {
	for (int recordIndex = 0; recordIndex < numRecords; recordIndex++) {
		ParseString(studentInputData[recordIndex]);
	}
}

Roster::~Roster() {
	// Delete every object pointed to in the classRosterArray
	for (unsigned int recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		delete classRosterArray.at(recordIndex);
	}
}

Student* Roster::GetStudentObject(unsigned int studentObjectIndex) {
	if (studentObjectIndex < (classRosterArray.size())) {
		return classRosterArray.at(studentObjectIndex);
	}
	else {
		return nullptr; // Return a nullptr if the index argument is outside of the classRosterArray range
	}
}

size_t Roster::GetNumberStudentRecords() {
	return this->classRosterArray.size();
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age,
				int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	// Create an int array using the three supplied daysInCourse# arguments because the Student class constructor uses
	// an int pointer rather than a set of int parameters
	int daysInCourseArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
	// Add an element to the classRosterArray vector and initialize new Student object using the arguments passed to the function
	classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram));
}

void Roster::Remove(string studentID) {
	unsigned int recordIndex = 0;
	bool recordFound = false;

	// Search classRosterArray for record with student ID matching argument
	for (recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		if ((classRosterArray.at(recordIndex))->GetStudentID() == studentID) {
			recordFound = true;
			break;
		}
	}

	// If record is found then delete the Student object at that vector index and then delete the vector item
	if (recordFound == true) {
		delete classRosterArray.at(recordIndex);
		classRosterArray.erase(classRosterArray.begin() + recordIndex);
	}
	else {
		cout << "Remove: No record found that matches student ID " << studentID << "." << endl;
	}
}

void Roster::PrintAll() {
	// Iterate through each element of classRosterArray and print the record of the Student object it points to
	for (unsigned int recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		classRosterArray.at(recordIndex)->Print();
	}
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	unsigned int recordIndex = 0;
	bool recordFound = false;
	int* daysInCourseArray;
	double sumDaysInCourse = 0.0;
	double avgDaysInCourse = 0.0;
	double numCourses = static_cast<double>(Student::numClasses);

	// Search classRosterArray for record with student ID matching argument
	for (recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		if ((classRosterArray.at(recordIndex))->GetStudentID() == studentID) {
			recordFound = true;
			break;
		}
	}

	// If record is found then calculate and print the average number of days in each course
	if (recordFound == true) {
		daysInCourseArray = classRosterArray.at(recordIndex)->GetNumDaysToComplete();
		
		// Iterate through the daysInCourseArray integer array using public const int Student::numClasses
		// as the upper limit of the for loop, and calculate the total sum of days in course
		for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
			sumDaysInCourse += static_cast<double>(daysInCourseArray[classIndex]);
		}
		
		// Calculate the average number of days in course and output results
		avgDaysInCourse = sumDaysInCourse / numCourses;
		cout << "Average number of days to complete course (student ID " << studentID << "): " << avgDaysInCourse << endl;
	}
	else {
		cout << "PrintAverageDaysInCourse: No record found that matches student ID " << studentID << "." << endl;
	}
}

void Roster::PrintInvalidEmails() {
	string emailToValidate = "";

	for (unsigned int recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		emailToValidate = classRosterArray.at(recordIndex)->GetStudentEmailAddress();

		if (emailToValidate.find("@") == string::npos 
			|| emailToValidate.rfind(".") == string::npos
			|| emailToValidate.rfind(".") < emailToValidate.find("@")	// check if there a '.' exists after the '@'
			|| emailToValidate.find(" ") != string::npos) {
			cout << emailToValidate << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (unsigned int recordIndex = 0; recordIndex < classRosterArray.size(); recordIndex++) {
		// If the degree program returned by the Student object matches the argument then print the Student object record
		if (classRosterArray.at(recordIndex)->GetStudentDegreeProgram() == degreeProgram) {
			classRosterArray.at(recordIndex)->Print();
		}
	}
}

// Roster::ParseString will parse through the comma separated input string, extract the data items, and set
// the variables to the data values accordingly. This function assumes the input string format is valid. Once
// it has parsed through the input string it will call the Roster::Add() function to add a new Student object
// that is constructed with the parsed variables.
void Roster::ParseString(string InputString) {
	size_t cursorPosition = 0;
	size_t subStrLength = 0;
	string degreeProgramString;

	// Initialize temporary variables to prepare for parsing
	string parsedStudentID = "";
	string parsedFirstName = "";
	string parsedLastName = "";
	string parsedEmail = "";
	int parsedAge = 0;
	int parsedDaysInCourse[Student::numClasses]; // Array elements initialized in for-loop below
	DegreeProgram parsedDegreeProgram = UNDEFINED;

	// Iterate through the numDaysToComplete integer array using public const int Student::numClasses
	// as the upper limit of the for loop, and initialize each element to zero.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		parsedDaysInCourse[classIndex] = 0;
	}

	// Parse and set studentID
	subStrLength = InputString.find(',', cursorPosition);
	parsedStudentID = InputString.substr(cursorPosition, subStrLength);

	// Advance cursor past end of previous substring, parse, and set first name
	cursorPosition += subStrLength + 1;
	subStrLength = InputString.find(',', cursorPosition) - cursorPosition;
	parsedFirstName = InputString.substr(cursorPosition, subStrLength);

	// Advance cursor past end of previous substring, parse, and set last name
	cursorPosition += subStrLength + 1;
	subStrLength = InputString.find(',', cursorPosition) - cursorPosition;
	parsedLastName = InputString.substr(cursorPosition, subStrLength);

	// Advance cursor past end of previous substring, parse, and set e-mail
	cursorPosition += subStrLength + 1;
	subStrLength = InputString.find(',', cursorPosition) - cursorPosition;
	parsedEmail = InputString.substr(cursorPosition, subStrLength);

	// Advance cursor past end of previous substring, parse, and set age
	cursorPosition += subStrLength + 1;
	subStrLength = InputString.find(',', cursorPosition) - cursorPosition;
	parsedAge = std::stoi(InputString.substr(cursorPosition, subStrLength));

	// For number of classes defined by Student::numClasses, parse through the string to get the number
	// of days in each course, and set each array element accordingly.
	for (int classIndex = 0; classIndex < Student::numClasses; classIndex++) {
		cursorPosition += subStrLength + 1;
		subStrLength = InputString.find(',', cursorPosition) - cursorPosition;
		parsedDaysInCourse[classIndex] = std::stoi(InputString.substr(cursorPosition, subStrLength));
	}

	// Advance cursor past end of previous substring, parse, and set degree program
	cursorPosition += subStrLength + 1;
	subStrLength = InputString.length() - cursorPosition;
	degreeProgramString = InputString.substr(cursorPosition, subStrLength);

	if (degreeProgramString == "SECURITY") {
		parsedDegreeProgram = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		parsedDegreeProgram = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		parsedDegreeProgram = SOFTWARE;
	}
	else {
		parsedDegreeProgram = UNDEFINED;
	}

	// Call Add() function to add new Student object with parsed variables.
	Add(parsedStudentID, parsedFirstName, parsedLastName, parsedEmail, parsedAge, parsedDaysInCourse[0],
		parsedDaysInCourse[1], parsedDaysInCourse[2], parsedDegreeProgram);
}