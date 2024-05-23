// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; //do not use like this in .h files!
const int NC = 30;


/*
Direct Call Copy Constructor
The alternative to sharing a private member function is a direct call from the copy constructor to the copy assignment operator 
(as in the chapter entitled Classes and Resources). In a direct call, the assignment operator copies the base class part of 
the object and any call to the base class copy constructor is redundant.
*/

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


// Qur four-argument constructor forwards the student's name to the single-argument constructor of the base class and then allocates memory
// for the grades. Our destructor deallocates that memory.

class Student : public Person {
	int no;
	float* grade;
	int ng;
	void init(int, int, const float*);
public:
	Student();
	Student(int);
	Student(const char*, int, const float*, int);
	Student(const Student& s);
	Student& operator=(const Student& src);
	~Student();
	void display(std::ostream& os) const;
};

//The private init() contains the copying logic shared by the constructors and the assignment operator:
void Student::init(int no_, int ng_, const float* g) 
{
	no = no_;
	ng = ng_;
	if (g != nullptr && ng > 0) {
		grade = new float[ng_];
		for (int i = 0; i < ng; i++)
			grade[i] = g[i];
	}
	else {
		grade = nullptr;
	}
}

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

/*
We implement the copying steps as follows:

1- Shallow copy the Person part of the source object
	a- Allocate static memory for name in the base class part of the newly created object
	b- Copy into name the string at address src.name
2- Copy the Student part of the source object
	a- Allocate static memory for no, *grade and ng in the derived part of the newly created object
	b- Shallow copy src.no into no
	c- Shallow copy src.ng into ng
	d- Allocate dynamic memory for a copy of src.grade
	e- Deep copy the elements at src.grade into grade
The default copy constructor for the base class performs a shallow copy. The copy constructor for the derived class calls 
the base class copy constructor and performs the deep copy itself:

The Student copy constructor executes its logic after the Person copy constructor has executed its logic.
*/

/*
The alternative to sharing a private member function is a direct call from the copy constructor to the copy assignment operator 
(as in the chapter entitled Classes and Resources). In a direct call, the assignment operator copies the base class part of 
the object and any call to the base class copy constructor is redundant.
*/
//Student::Student(const Student& src) : Person(src) {
Student::Student(const Student & src) {
	grade = nullptr;
	*this = src;
}

Student& Student::operator=(const Student& src) {
	if (this != &src) { // check against self copy.
		// Base class assignment
		// 1 - functional expression
		// Person::operator=(src);
		// 2 - assignment expression
		Person& person = *this; // only copies address
		person = src; // call base class assignment operator
		delete[] grade;
		no = src.no;
		ng = src.ng;
		if (src.ng > 0) {
			grade = new float[ng];
			for (int i = 0; i < ng; i++)
				grade[i] = src.grade[i];
		}
		else
			grade = nullptr;
	}
	return *this;
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
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry("Harry", 1234, gh, 3), harrz;
	harrz = harry; // calls copy assignment

	harry.display(std::cout);
	harrz.display(std::cout);

	return 0;
}
