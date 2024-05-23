// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; //do not use like this in .h files!
const int NC = 30;

class Person {
	char name[NC + 1];
public:
	Person();
	Person(const char*);
	void display(std::ostream& os) const;
};

Person::Person()
{
	name[0] = '\0'; //setting person name to empty by making first char of the name is null character.
}

Person::Person(const char* nm)
{
	strncpy(name, nm, NC); // copyinh NC character from nm to name
	name[NC] = '\n'; // null etminatting the name. making last char of the name is null-character.
}

void Person::display(std::ostream& os) const
{
	os << name << ' ';
}

// Our four-argument constructor forwards the student's name to the single-argument constructor of the base class and then allocates memory
// for the grades. Our destructor deallocates that memory.

class Student : public Person {
	int no;
	float* grade;
	int ng;
public:
	Student();
	Student(int);
	Student(const char*, int, const float*, int);
	~Student();
	void display(std::ostream& os) const;
};



Student::Student()
{
	no = 0;
	ng = 0;
	grade = nullptr;
}

Student::Student(int n)
{
	float g[] = { 0.0f };
	*this = Student("", n, g, 0);
}

Student::Student(const char* nm, int sn, const float* g, int ng_) : Person(nm)
{
	//check validiy of the input
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	if (valid) {
		for (int i = 0; i < ng_ && valid; i++) {
			valid = g[i] >= 0.0f && g[i] <= 100.0f;
		}
	}

	if (valid) {
		// accept the client's data
		no = sn;
		ng = ng_;
		if (ng > 0) {
			grade = new float[ng_];
			for (int i = 0; i < ng; i++) {
				grade[i] = g[i];
			}
		}
		else {
			grade = nullptr;
		}
	}
	else {
		grade = nullptr;
		*this = Student();
	}
}

Student::~Student()
{
	delete[] grade;
}

void Student::display(std::ostream& os) const
{
	if (no > 0) {
		Person::display(os);
		os << no << ":\n";
		os.setf(ios::fixed);
		os.precision(2);
		for (int i = 0; i < ng; i++) {
			os.width(6);
			os << grade[i] << endl;
		}
		os.unsetf(ios::fixed);
		os.precision(6);
	}
	else {
		os << "no data available" << endl;
	}
}

#include <iostream>
//#include "Student.h"

int main() {
	Person jane("Jane");
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry("Harry", 1234, gh, 3);

	harry.display(std::cout);
	std::cout << "============================" << std::endl;
	jane.display(std::cout);

	return 0;
}
