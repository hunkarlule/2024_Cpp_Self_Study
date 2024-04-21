#include <iostream>
using namespace std;

/*
The Current Object

Once client code calls a member function on an object of its class 
and before that function returns control to the client code, 
that member function may need to refer to its host object. 
We refer to the host object from within a member function as 
the current object for that function. In other words, 
the current object is the region of memory that contains the data 
on which a member function currently operates.
*/

/*
Member Function Parameters
Member functions receive information through parameters and 
return information through a return value and possibly some of 
their parameters. The parameters of any member function are of 
two distinct kinds:

Explicit: Access the client code
Implicit: Access the instance variables

Explicit parameters receive information from the client code and 
return information to the client code. We define them explicitly 
in the header of a member function. Their lifetime extends from 
entry to the function to exit from the function. They have 
function scope.

Implicit parameters tie the member function to the current object.

The syntax of a normal member function call reflects this two-part 
mechanism. The name of the object on which the client code invokes 
the function identifies the implicit parameters, while the 
arguments that the client code passes to the function initialize 
the explicit parameters.
For Example: 
Student a;
// here we called display on object a. So, a is implicit
parameter and x and y are explicit parameters.
a.display(x, y);
*/



const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student();
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

Student::Student()
{
	cout << "in constructor..." << endl;
	no = 0;
	ng = 0;
}

Student::Student(int studentNo, const float* studentGrades, int numOfGrades)
{
	cout << "Entering 3-arg constructor\n";
	set(studentNo, studentGrades, numOfGrades);
}

Student::~Student()
{
	cout << "In destructor for " << no << endl;
}

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

	float gh[] = { 89.4f, 67.8f, 45.5f };
	float gj[] = { 83.4f, 77.8f, 55.5f };

	/*
	The constructor for harry receives data in its explicit 
	parameters and copies that data to the arguments in the call 
	to the set() member function on the current object, which 
	consists of the instance variables for harry. The constructor 
	for josee receives data in its explicit parameters and copies 
	that data to the arguments in the call to the set() member 
	function on the current object, which consists of the instance 
	variables for josee.
	*/
	Student harry(1234, gh, 3);
	Student josee(1235, gj, 3);

	/*
	The first client call to the display() member function accesses 
	harry through its implicit parameters. The second client call 
	accesses josee through its implicit parameters.
	*/
	harry.display();
	josee.display();

	return 0;
}