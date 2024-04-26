#define _CRT_SECURE_NO_WARNINGS

// Student.h
#include <iostream>
const int NC = 30;
const int NG = 20;

class Person {   // start of Base Class Definition
	char name[NC + 1];
public:
	void set(const char* n);
protected:
	void displayName(std::ostream& os) const;

}; // end of Base Class Definition

/*
The definition of a derived class takes the form:
class Derived : access Base {
	// ...
};

where Derived is the name of the derived class and Base is the name of 
the base class. access identifies the access that member functions of 
the derived class have to the non-private members of the base class. 
The default access is private. The most common access is public.
*/

// Here Student class inherits from Person class. Access modifer is public.
class Student : public Person {  // start of Derived Class Definition
	int no;
	float grade[NG];
	int ng;
public:
	Student();
	Student(int studentNo);
	Student(int studentNo, const float* studentGrades, int numOfGrades);
	void display(std::ostream& os) const;
}; // end of Derived Class definition

// Student.cpp

#include <cstring>
using namespace std;

void Person::set(const char* n) {
	strncpy(name, n, NC);
	// making last char of name is a null-character(null terminating the name)
	// so, name will be a C-string.
	name[NC] = '\0'; 
}

void Person::displayName(std::ostream& os) const {
	os << name << ' ';
}

Student::Student() {
	no = 0;
	ng = 0;
}

Student::Student(int sn) {
	float g[] = { 0.0f };
	*this = Student(sn, g, 0);
}

Student::Student(int sn, const float* g, int ng_) {
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	if (valid) {
		for (int i = 0; i < ng_ && valid; i++) {
			valid = g[i] >= 0.0f && g[i] <= 100.0f;
		}
	}

	if (valid) {
		// accept the client's data
		no = sn;
		ng = ng_ < NG ? ng_ : NG;
		for (int i = 0; i < ng; i++)
			grade[i] = g[i];
	}
	else {
		*this = Student();
	}		
}

void Student::display(std::ostream& os) const {
	if (no > 0) {
		// We refer to displayName() directly without any scope resolution as 
		// if this function is a member of our Student class.
		displayName(os);
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


int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);

	//
	harry.set("Harry"); // set inherited from Person class

	//  displayName in Person class is marked with Protected access
	// modifier we can not access/reach it directly from clint code like below.
	// however we can call  displayName inside the Student class.
	//harry.displayName(std::cout); // error because displayName is protected.
	harry.display(std::cout); // display NOT inherited from Person class.

	return 0;
}