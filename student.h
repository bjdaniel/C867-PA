#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using std::string;

class Student {
	public:
		// Constructors
		Student(); // default constructor
		Student(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress, 
				int studentAge, int* numDaysToComplete, DegreeProgram studentDegreeProgram);
		
		// Accessors
		string GetStudentID();		
		string GetStudentFirstName();		
		string GetStudentLastName();		
		string GetStudentEmailAddress();
		int GetStudentAge();		
		int* GetNumDaysToComplete();
		DegreeProgram GetStudentDegreeProgram();
		
		// Mutators
		void SetStudentID(string studentID);
		void SetStudentFirstName(string studentFirstName);
		void SetStudentLastName(string studentLastName);
		void SetStudentEmailAddress(string studentEmailAddress);
		void SetStudentAge(int studentAge);
		void SetNumDaysToComplete(int* numDaysToComplete);
		void SetStudentDegreeProgram(DegreeProgram degreeProgram);

		// Member functions
		void Print();

		// Used to define the number of elements in the Student::numDaysToComplete integer array.
		// Declared as a public static const so it is accessible to functions outside of class
		// that iterate through the Student::numDaysToComplete integer array.
		static const int numClasses = 3;
	
	private:
		string studentID;
		string studentFirstName;
		string studentLastName;
		string studentEmailAddress;
		int studentAge;
		int numDaysToComplete[Student::numClasses];
		DegreeProgram studentDegreeProgram;
};

#endif // !STUDENT_H