
/*
Object-oriented languages encapsulate the state and logic of
a type using a class. A class describes the structure of the
data that its objects hold and the rules under which its member
functions access and change that data. The implementation of
a well-encapsulated class has all details hidden within itself.
Client code communicates with the objects of the class solely
through its public member functions.
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
Destructor
Complete encapsulation also requires a mechanism for tidying up
at the end of an object's lifetime. An object with dynamically
allocated memory needs to deallocate that memory before going
out of scope. An object that has written data to a file needs
to flush the file's buffer and close the file before going
out of scope.

Definition
The special member function that every object invokes before
going out of scope is called its class' destructor. We code
all of the terminal logic in this special member function.

The destructor takes its name from the class itself,
prefixing it with the tilde symbol (~). The prototype for
a destructor takes the form

~Type();

Type is the name of the class. Destructors have no parameters
or return values.

An object's destructor:

-- is called automatically.
-- cannot be overloaded.
-- should not be called explicitly.
*/

const int NG = 20;
/*
Default Behaviour
If we don't declare a destructor in the class definition, 
the compiler inserts a destructor with an empty body:

Student::~Student() {
}

We will not see the destrcutor in our source code but it will be 
when our code is compliled.
*/
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student(); // no-argument constructor
	//~Student(); // destructor prototype decleration
	void copyFrom(const Student& src);
	void set(int studentNo, const float* studentGrades, int numOfGrades);
	void display() const; // due to const display can not change Student object.
};


void Student::display() const
{
	if (no > 0) {
		cout << no << ":\n";
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
		cout << "no data available" << endl;
	}
}



Student::Student()
{
	cout << "In constructor..." << endl;
	no = 0;
	ng = 0;
}

//Student::~Student()
//{
//	cout << "Destructing object" << endl;
//}

// The copyFrom(const Student& src) member function copies 
// the values of the private data members of harry to 
// the private data members of backup.
void Student::copyFrom(const Student& src)
{
	no = src.no; // copy data from one object to another
	ng = src.ng; // copy data from one object to another
	for (int i = 0; i < NG; i++) {
		grade[i] = src.grade[i]; // copy from one object to another
	}
}

void Student::set(int studentNo, const float* studentGrades, int numberOfGrades)
{
	bool valid = studentNo > 0 && studentGrades != nullptr && numberOfGrades >= 0;

	if (valid) {
		for (int i = 0; i < numberOfGrades && valid; i++) {
			valid = studentGrades[i] >= 0.0f && studentGrades[i] <= 100.0f;
		}
	}

	if (valid) { // accept the client's data
		no = studentNo;
		ng = numberOfGrades < NG ? numberOfGrades : NG;
		for (int i = 0; i < ng; i++) {
			grade[i] = studentGrades[i];
		}
	}
	else {
		no = 0;
		ng = 0;
	}
}

int main() {

	// we set objects to a safe-empty-state in no-argument
	// constrcutor when we call the display on them we do not see
	// any weird/undefined behaviour etc. This is a good design practice!S
	Student harry, josee;
	harry.display();
	josee.display();

	float gh[] = { 89.4f, 67.8f, 45.5f };
	float gj[] = { 83.4f, 77.8f, 55.5f };
	harry.set(1234, gh, 3);
	josee.set(1235, gj, 3);
	harry.display();
	josee.display();

	return 0;
}