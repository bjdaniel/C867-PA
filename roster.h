#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "degree.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Roster {
	public:
		// Constructors / destructor
		Roster(); // default constructor
		Roster(const string* studentInputData, int numRecords);
		~Roster(); // destructor
		
		// Accessors
		Student* GetStudentObject(unsigned int studentObjectIndex);
		size_t GetNumberStudentRecords();

		// Member functions
		void Add(string studentID, string firstName, string lastName, string emailAddress, int age,
				int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void Remove(string studentID);
		void PrintAll();
		void PrintAverageDaysInCourse(string studentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram degreeProgram);

	private:
		// Class helper function for parsing student record string into Student class variables
		void ParseString(string InputString);
		
		// An array of Student object pointers
		vector<Student*> classRosterArray; 
};

#endif // !ROSTER_H