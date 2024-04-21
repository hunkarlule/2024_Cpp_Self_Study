
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
The compiler creates multiple objects defined in a single
declaration in the order specified by the declaration.

For example, the following code generates the output below:
*/

const int NG = 20;
/*
If we don't declare a constructor in the class definition,
the compiler inserts a default no-argument constructor
with an empty body: Note that, we will not see code of this default
constructor(the constructor provided by compliler autamitically)
in our source code.
Also, body of this constructor is emtpy!.
*/
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student(); // no-argument constructor
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

	// here we defined multiple students in a singel decleration.
	// In this case the compiler assembles harry and calls 
	// its constructor first(becuase harry declared first) and 
	// assembles josee and calls its constructor afterwards.

	Student harry, josee;
	float gh[] = { 89.4f, 67.8f, 45.5f };
	float gj[] = { 83.4f, 77.8f, 55.5f };
	harry.set(1234, gh, 3);
	josee.set(1235, gj, 3);
	harry.display();
	josee.display();

	return 0;
}