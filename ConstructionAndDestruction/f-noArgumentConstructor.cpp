
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
Constructor Definition
The special member function that any object invokes at
creation-time is called its class' constructor. We use
the default constructor to execute any preliminary logic and
set the object to an empty state.

The default constructor takes its name from the class itself.
The prototype for this no-argument constructor takes the form

Type();

Type is the name of the class. Its declaration DOES NOT include
a return type.

*/

const int NG = 20;
/*
To define a default constructor/no-argument for our Student class,
we declare its prototype explicitly in the class definition:
*/
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student(); // prototype decleration for no-argument constructor.
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

// no argument constructor definition.	
Student::Student()
{
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

	/*
	Initially harry's student number, grades and their number are
	undefined. If the value stored in ng is negative,
	the first call to display() outputs an unrecognizable
	student number and no grades. After the call to set(),
	the data values are defined and the subsequent call to
	display() produces recognizable results.

	To avoid undefined behavior or broken objects,
	we need to initialize each object to an empty state
	at creation-time.
	*/

	// compiler does not give any warning anymore because we
	// defined a no-argument constructor for Student class and set
	// the data members. So, below line cause a call to no-argument
	// constructor while cresting harry.
	Student harry; 
	harry.display(); 
	float grade[] = { 78.9f, 67.5f, 45.55f };
	harry.set(975, grade, 3);
	harry.display();



	return 0;
}



