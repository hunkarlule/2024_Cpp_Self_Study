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
this Keyword
The keyword this returns the address of the current object. That is, this holds 
the address of the region of memory that contains all of the data stored in 
the instance variables of current object. *this refers to the current object 
itself; that is, to the complete set of its instance variables.

We use the this keyword within a member function to refer to the complete 
set of instance variables that that member function is currently accessing 
through its implicit parameters.

The keyword this has no meaning outside a member function.

Assume that we have Student a, b, c;
All these 3 students puts in the memory:
a ==> &a is address of a in memory
b ==> &b is address of b in memory
c ==> &c is address of c in memory

We have also display(); functin in student class.
when we call a.display(); ==> then in display function:
this is equal to &a
*this is eqaul to a

when we call b.display(); ==> then in display function:
this is equal to &b
*this is eqaul to b

when we call c.display(); ==> then in display function:
this is equal to &c
*this is eqaul to c

*/


/*
Reference to the Current Object
We can improve this definition of display() by returning an unmodifiable 
reference to the current object rather than a copy of the object. This would 
improve performance if the object was large, since copying all of its instance 
variables would be compute intensive. Returning a reference only copies 
the object's address, which is typically a 4-byte operation:

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
	//void display() const; // due to const display can not change Student object.
	//Student display() const; // we want to return Student object from display instead of void.

	// The const qualifier on the return type prevents client code 
	// from placing the call to the member function on the left side of 
	// an assignment operator and thereby enabling a change to the instance 
	// variables themselves.
	const Student& display() const; // we want to return const Student&  from display instead of void.
};


//void Student::display() const
//{
//	if (no > 0) {
//		cout << no << ":\n";
//		cout.setf(ios::fixed);
//		cout.precision(2);
//		for (int i = 0; i < ng; i++) {
//			cout.width(6);
//			cout << grade[i] << endl;
//		}
//		cout.unsetf(ios::fixed);
//		cout.precision(6);
//	}
//	else {
//		cout << "no data available" << endl;
//	}
//}

//Student Student::display() const
//{
//	if (no > 0) {
//		cout << no << ":\n";
//		cout.setf(ios::fixed);
//		cout.precision(2);
//		for (int i = 0; i < ng; i++) {
//			cout.width(6);
//			cout << grade[i] << endl;
//		}
//		cout.unsetf(ios::fixed);
//		cout.precision(6);
//	}
//	else {
//		cout << "no data available" << endl;
//	}
//
//	// returns a copy of its host object / current object, we write:
//	// because this is a speacial pointer that points the current object(the object 
//	// that the function are called on). So if we dereference that pointer 
//	// like this: *this ===> then we have the current object in our hands.
//	return *this; 
//}

const Student& Student::display() const
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

	// returns a copy of its host object / current object, we write:
	// because this is a speacial pointer that points the current object(the object 
	// that the function are called on). So if we dereference that pointer 
	// like this: *this ===> then we have the current object in our hands.
	return *this;
}

Student::Student()
{
	cout << "Entering no-argument constructor..." << endl;
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
	Student harry(1234, gh, 3), backup;

	backup = harry.display();
	backup.display();

	return 0;
}