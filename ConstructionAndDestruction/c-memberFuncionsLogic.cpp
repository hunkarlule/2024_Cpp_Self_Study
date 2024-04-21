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
using namespace std;

/*
Instance of a Class
Each object or instance of a class occupies its own region
of memory. The data for the object is stored in that region
of memory.

A definition of an object takes the form

Type Identifier;

Type is the name of the class. Identifier is the name of

Consider the following class definition:

*/

const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
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

int main() {

	// To create an object of our Student class named harry, we write :
	Student harry; // harry is a instanc of Student class

	//To create five objects of our Student class, we write:

	/*
	Logic
	The member function instructions apply to all objects of 
	the class and there is no need to allocate separate logic 
	memory for each object. At run-time each call to a member 
	function on an object accesses the same code, but different 
	instance variables - those of the object on which the client 
	code has called the member function.

	Consider the following client code. This code calls the same 
	member function (display()) on five different Student objects 
	and displays five different sets of information in the same 
	format:
	*/
	Student a, b, c, d, e; // all 5 of them are instances of Student class
	
	// different data for each object - same logic
	a.display();  // displays the data stored in a
	cout << endl;
	b.display();  // displays the data stored in b
	cout << endl;
	c.display();  // displays the data stored in c
	cout << endl;
	d.display();  // displays the data stored in d
	cout << endl;
	e.display();  // displays the data stored in e
	cout << endl;
	
	return 0;
}

