
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
No-argument constructor is not always implemented
If the class definition includes the prototype for a constructor 
with some parameters but does not include the prototype for a 
no-argument default constructor, the compiler DOES NOT insert 
an empty-body, no-argument default constructor. The compiler 
only inserts an empty-body, no-argument default constructor 
if the class definition does not declare ANY constructor.

If we define a constructor with some parameters, we typically 
also define a no-argument default constructor. This is important '
in the creation of arrays of objects. The creation of each element 
in the array requires a no-argument default constructor.
*/

const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	/*
	Normally, compiler insert a no-argument default constructor with
	empty body to our class itself. However, if we write a constroctur 
	ourselves then compiler will NOT insert/add no-argument 
	default constructor. Therefore we need to add  that no-argument
	constructor manually.
	*/
	 

	// Here we added a constrcutor into the class. So, we need to
	// add a no-argument constructor manually.
	Student(int studentNo, const float* studentGrades, int numOfGrades); // 3-argument constrcutor.
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


/*
This new constructor includes the validation logic by 
calling set(). The compiler calls only one constructor at 
creation-time. In this example, the compiler does not call the default constructor.
*/
Student::Student(int studentNo, const float* studentGrades, int numOfGrades)
{
	cout << "In 3-arg constructor" << endl;
	set(studentNo, studentGrades, numOfGrades);
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
	/*
 The compiler calls only one constructor at
 creation-time. In this example, the compiler does not 
 call the default constructor.
*/
	float gh[] = {89.4f, 67.8f, 45.5f};
	float gj[] = {83.4f, 77.8f, 55.5f};
	Student harry(1234, gh, 3);
	Student josee(1235, gj, 3);

	harry.display();
	josee.display();

	return 0;
}