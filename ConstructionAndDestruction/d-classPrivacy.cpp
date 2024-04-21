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
Class Privacy
C++ compilers apply privacy at the class level. Any member 
function can access any private member of its class, 
including any data member of any instance of its class. 
In other words, privacy is not implemented at the individual 
object level.

In the following example, we refer to private data members of 
a Student object within a member function called on a different 
Student object:

*/

const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
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

	Student harry, backup;
	float grade[] = { 78.9f, 67.5f, 45.5f, 64.35f };
	harry.set(975, grade, 4);
	harry.display();
	backup.copyFrom(harry);
	backup.display();
	
	
	return 0;
}

