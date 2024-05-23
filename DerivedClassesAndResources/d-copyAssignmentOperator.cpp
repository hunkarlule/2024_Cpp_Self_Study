// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; //do not use like this in .h files!
const int NC = 30;


/*
Copy Assignment Operator
The default copy assignment operator of a derived class calls the copy assignment operator of its base class. However, 
any custom copy assignment operator of a derived class DOES NOT by default call the copy assignment operator of its base class. 
Accordingly, a custom copy assignment operator of a derived class with a resource requires an explicit call to 
the base class copy assignment operator.

We call the base class copy assignment operator from within the body of the definition of the derived class assignment operator. 
The call takes one of the following forms:

The functional form
The cast assignment form

The functional expression takes the form
Base::operator=(identifier);

The assignment expression takes the form
(Base&)*this = identifier;

Base is the name of the base class and identifier is the name of the right operand, which is the source object for the assignment. 
Note that the address of the derived object is the same as the address of the base class part of that object. 
The compiler distinguishes the call to the base class operator from a call to the derived class operator by the type of the left operand.
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

// Our four-argument constructor forwards the student's name to the single-argument constructor of the base class and then allocates memory
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

Student::Student(const Student& src) : Person(src) {
	//no = src.no;
	//ng = src.ng;
	//if (src.grade != nullptr && ng > 0) {
	//	grade = new float[ng];
	//	for (int i = 0; i < ng; i++) {
	//		grade[i] = src.grade[i];
	//	}
	//}
	//else {
	//	grade = nullptr;
	//}
	init(src.no, src.ng, src.grade);
}

Student& Student::operator=(const Student& src) {
	if (this != &src) { // check against self copy.
		// Base class assignment
		// 1 - functional expression
		// Person::operator=(src);
		// 2 - assignment expression
		(Person&)*this = src; // call base class assignment operator
		delete[] grade;
		init(src.no, src.ng, src.grade);
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
