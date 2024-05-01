#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Universal Polymorphism - Inclusion

/*
Inclusion
Inclusion polymorphism addresses the multiplicity of definitions 
available for a function call. Inclusion polymorphism allows 
the multiplicity of member function definitions by selecting 
the definition from the set of definitions based on the object's 
type. The type is a type that belongs to an inheritance hierarchy. 
The term inclusion refers to the base type including the derived 
types within the hierarchy. All member function definitions share 
the same name throughout the hierarchy.

In the code below, both a HybridCourse and a Course belong to 
the same hierarchy. A HybridCourse uses one mode of delivery 
while a Course uses another mode. That is, a mode() query on 
a Course object reports a different result from a mode() query 
on a HybridCourse object.
*/

/*
Operations that are identical for all types within the 
hierarchy require only one member function definition. 
The assessments() query on a HybridCourse object invokes 
the same function definition as a query on the Course object. 
Defining a query for the HybridCourse class would only duplicate 
existing code and is unnecessary.
*/

/*
Inclusion polymorphism eliminates duplicate logic across 
a hierarchy without generating missing function definition 
errors. C++ implements inclusion polymorphism at run-time 
using virtual tables.
*/
class Course {
	char name[31];

public: 
	Course(const char* cname);
	void assessments() const;
	void mode() const;
};

Course::Course(const char* cname) {
	strcpy(name, cname);
}

void Course::assessments() const
{
	cout << "Assements consists of exams, quizes, attandance and participation." << endl;
}

void Course::mode() const
{
	cout << "Course mode is in-person in class." << endl;
}


class HybridCourse: public Course {

public:
	HybridCourse(const char* cname);
	//void assessments() const;
	void mode() const;
};

HybridCourse::HybridCourse(const char* cname): Course(cname) {}

void HybridCourse::mode() const
{
	cout << "Course mode is online-lab mode" << endl;
}


int main() {

	Course abc123("Intro to OO");
	HybridCourse abc124("Intro to OO*");
	abc123.assessments(); // will call assessments func from Course class
	abc123.mode(); // will call mode func from Course class
	abc124.assessments(); // will call assessments func from Course class
	abc124.mode(); // will call mode func from HybridCourse class

	return 0;
}


