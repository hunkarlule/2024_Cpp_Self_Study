
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


/*
Construction and Destruction of Arrays

The compiler creates the elements of an array one at a time 
sequentially starting from the first element and ending with 
the last. Each object calls the default constructor at 
creation-time. When the array goes out of scope, 
the last element calls its destructor first and the first element 
calls its destructor last.
For example: Assuem we created this array in our code: 
	Student a[3];

When creating array:

The constructor for element a[0] executes before the constructor
for a[1], which executes before the constructor for a[0].

When array goes out of scope:

The destructor for element a[2] executes before the destructor
for a[1], which executes before the destructor for a[0].
The order of destruction is based on order of
construction and not on order of usage.

*/

const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student(); // no-argument constructor
	~Student(); // destructor prototype decleration
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

Student::~Student()
{
	cout << "In destructor for " << no << endl;
}

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

	// here when creating array, constractor are called on
	// elements from first element to last element.
	// when destryiong array, constractor are called on reverse
	// order  from last element to first element.
	/*
	The destructor for element a[2] executes before the destructor 
	for a[1], which executes before the destructor for a[0]. 
	The order of destruction is based on order of 
	construction and not on order of usage.
	*/
	Student a[3];
	float g0[] = { 89.4f, 67.8f, 45.5f };
	float g1[] = { 83.4f, 77.8f, 55.5f };
	float g2[] = { 77.8f, 83.4f, 55.5f };
	a[0].set(1234, g0, 3);
	a[1].set(1235, g1, 3);
	a[2].set(1236, g2, 3);
	for (int i = 0; i < 3; i++)
		a[i].display();

	return 0;
}