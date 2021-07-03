#include "student.h"
#include "degree.h"
#include "roster.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
	// Data for Roster object classRoster
	const int numStudentRecords = 5;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Billy,Daniel,bdani93@wgu.edu,36,30,35,40,SOFTWARE"
	};

	Roster classRoster(studentData, numStudentRecords);

	// Required program header output
	cout << "Course: C867 - Scripting and Programming Applications" << endl
		<< "Language used: C++ (Visual Studio)" << endl
		<< "Student ID: xxxxxxxxx" << endl
		<< "Name: Billy Daniel" << endl << endl;

	// Assignment required functions
	// Print all records in classRoster
	cout << "Printing entire student roster:" << endl;
	classRoster.PrintAll();
	cout << endl;
	
	cout << "Printing invalid e-mails from roster:" << endl;
	// Print all invalid e-mails found in classRoster
	classRoster.PrintInvalidEmails();
	cout << endl;

	cout << "Printing average number of days in every course for each student in roster:" << endl;
	// Iterate through each classRoster item and print the average number of days in course for each record
	for (int recordIndex = 0; recordIndex < classRoster.GetNumberStudentRecords(); recordIndex++) {
		// Check that the loop isn't attempting an out of bounds access
		if (classRoster.GetStudentObject(recordIndex) != nullptr) {
			classRoster.PrintAverageDaysInCourse(classRoster.GetStudentObject(recordIndex)->GetStudentID());
		}
		else {
			cout << "Error accessing Student object. Possible out of bounds access attempt." << endl;
		}
		
	}
	cout << endl;

	cout << "Printing all stduents in SOFTWARE degree program:" << endl;
	// Print all records from classRoster where degree program is SOFTWARE
	classRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;
	
	cout << "Printing student roster after removing student A3:" << endl;
	classRoster.Remove("A3");
	classRoster.PrintAll();
	cout << endl;

	cout << "Attempting to remove student A3 again:" << endl;
	classRoster.Remove("A3"); // should print an error

	return 0;
}