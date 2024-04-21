
#include <iostream>
using namespace std;

void displayNo(); // prototype decleration of global displayNo function.
const int NG = 20;

class Student {
private: // default is private so we do not need to use private keyword here.
	int no{ 123 };          // student number
	float grade[NG]{ 67.8f, 85.3f }; // grades
	int ng{ 2 };          // number of grades filled in grade array.

	// with public keyword, the members(data and function) under it 
	// became public and CAN be accessed by client code dorectly.
public:
	// const keyword make sure that display function will not change the
	// Student object(its dat members) that operates on.
	// In other words, const makes dipslay a query/getter.
	void display() const; // member function
	void displayNo() const; // member function
	void set(int studentNo, const float* studentGrades, int numberOfGrades);
};

void foo(const Student& student);

// Any attempt by the client code to access a private member 
// generates a complier error:
// here we defined a global foo func and passing it a
// Student reference. Inside the func, we try to reach data 
// member(no) of the student. Compiler gives "inaccessible" error
// becuase data-member no is private in Student class.
// The function foo() can only access the data stored in harry indirectly 
// through public member function display().
void foo(const Student& student) {
	//cout << student.no;  // ERROR - this member is private!
	student.display(); // OK because dislay func in Student class public.

}

// display finction with cout formatting.
void Student::display() const {
	if (no > 0) {

		::displayNo(); //calls global displayNo function.
		cout << no << ": \n";
		cout.setf(ios::fixed);
		cout.precision(2);
		for (int i = 0; i < ng; i++) {
			cout.width(6);
			cout << grade[i] << endl;
		}
		cout.unsetf(ios::fixed);
		cout.precision(6);
	}
	else {
		cout << "no data available";;
	}
}

void Student::displayNo() const {
	cout << no << ": \n";
}

/*
Let us upgrade our set() member function to validate incoming data
only if:

The student number is positive-valued
The grades are between 0 and 100 inclusive
If any incoming data fails to meet one of these conditions,
let us ignore all incoming data and store a value that places the object
in an empty state. For instance, let us use a student number of 0 to
identify an empty state:

This validation logic ensures that either the data stored in
any Student object is valid data or the object is in
an empty state.
*/
void Student::set(int studentNo, const float* studentGrades, int numberOfGrades)
{
	// determine how many grades will be saved in grade array of student.
	int n = numberOfGrades < NG ? numberOfGrades : NG;
	bool valid{ true }; // assume valid input, check for invalid values

	if (studentNo < 1) {
		valid = false;
	}
	else {
		for (size_t i = 0; i < n && valid; i++) {
			valid = studentGrades[i] >= 0.0f && studentGrades[i] <= 100.0f;
		}
	}

	if (valid) {  // accept the client's data
		no = studentNo;
		ng = n;
		for (int i = 0; i < n; i++) {
			grade[i] = studentGrades[i];
		}
	}
	else { // ignore the client's data, set an empty state
		no = 0; // means object is in empty state.
	}

	// store the grades as received within the available space
	for (size_t i = 0; i < ng; i++) {
		grade[i] = studentGrades[i];
	}
}

/*
Note that this definition does not include any scope resolution identifier.
This global function shares the same identifier with one of the member
functions, but does not introduce any conflict, since the client code
calls each function using different syntax.
*/
void displayNo() {
	cout << "Number...\n";
}

int main() {

	Student harry;
	// setting harry's state callin set function of Student class
	float k[] = { 78.9456f, 99.4675f };
	harry.set(999, k, 2);
	harry.display(); // calling display member function for student harry.
	cout << endl;


	//cout << harry.no; // ERROR .no IS PRIVATE!
	return 0;
}

