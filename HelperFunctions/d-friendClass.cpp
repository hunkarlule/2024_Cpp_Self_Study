#include <iostream>
using namespace std;

// Student.h

const int NG = 20;

class Student {
	int no;
	float grade[NG];
	int ng;
public:
	Student();
	Student(int);
	Student(int, const float*, int);
	const Student& operator+=(float grade);
	void display() const;
	int getStudentNo() const { return no; }
	int getNoGrades() const { return ng; }
	float getGrade(int i) const { return i < ng ? grade[i] : 0.0f; }
	// we declared operator== function as a friend of Student class.
	// so this way operator== will have access to all members(even private) of Studetn class.
	// Note that declating a function as a friend of class(like below) does not make that function a member of the class
	// But that function have access to all members in the class.
	// friend deceration is like giving your house key to your friend. Giving key does not make him/her a member of family.
	// But that person can access everything in the house.
	friend bool operator==(const Student& lhs, const Student& rhs);

	/*
	Administrator class needs access to all information held within 
	each Student object.To grant this access, we simply include a class friendship 
	declaration within the Student class definition.
	So, with this declaration. Administrator class can access all members(even private ones)
	of Student class in itself.
	*/ 
	friend class Administrator;
};

// here
class Administrator {
	int adminNo;
public:
	Administrator(int no) {
		adminNo = no;
	}

	// Here in this member function of Administrator class we access and update
	// no of a Student. no is a private member and normally  it is inaccessible outside
	// of Student class. however, Administrator is a friend of Student class. Therefore,
	// it can access the all members (event private ones) of the Student class.
	void changeStudentNo(Student& s, int sNo) {
		s.no = sNo;
	}
};

bool areIdentical(const Student& lhs, const Student& rhs);
//bool operator==(const Student& lhs, const Student& rhs); // we declared this as a friend in the class!
Student operator+(const Student& student, float grade);
Student operator+(float grade, const Student& student);

Student::Student() {
	no = 0;
	ng = 0;
}

Student::Student(int n) {
	*this = Student(n, nullptr, 0);
}

Student::Student(int sn, const float* g, int ng_) {
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	if (valid)
		for (int i = 0; i < ng_ && valid; i++)
			valid = g[i] >= 0.0f && g[i] <= 100.0f;

	if (valid) {
		// accept the client's data
		no = sn;
		ng = ng_ < NG ? ng_ : NG;
		for (int i = 0; i < ng; i++)
			grade[i] = g[i];
	}
	else {
		*this = Student();
	}
}

const Student& Student::operator+=(float g)
{
	if (no != 0 && ng < NG && g >= 0.0f && g <= 100.0f) {
		grade[ng++] = g;
	}

	return *this;

}

void Student::display() const {
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

bool areIdentical(const Student& lhs, const Student& rhs) {
	bool same = lhs.getStudentNo() == rhs.getStudentNo() &&
		lhs.getNoGrades() == rhs.getNoGrades();
	for (int i = 0; i < lhs.getNoGrades() && same; i++) {
		same = lhs.getGrade(i) == rhs.getGrade(i);
	}

	return same;
}

// helper operator== overload. This gets two student object and
// returns whether 2 students equal/same  or not. So using
// this operator overload we  can compare two students like this:
// student1 == student2. This is like comparing two integer int1==int2.
// Using this operator is better then using areIndetical function.

/* version before friendship.
bool operator==(const Student& lhs, const Student& rhs)
{
	bool same = lhs.getStudentNo() == rhs.getStudentNo() &&
		lhs.getNoGrades() == rhs.getNoGrades();
	for (int i = 0; i < lhs.getNoGrades() && same; i++) {
		same = lhs.getGrade(i) == rhs.getGrade(i);
	}

	return same;
}
*/
// becuase operator== is friend of Student class we can access data member directly.
bool operator==(const Student& lhs, const Student& rhs)
{
	bool same = lhs.no == rhs.no &&
		lhs.ng == rhs.ng;
	for (int i = 0; i < lhs.ng && same; i++) {
		same = lhs.grade[i] == rhs.grade[i];
	}

	return same;
}

Student operator+(const Student& student, float grade)
{
	Student copy = student; // makes a copy of the student.
	copy += grade; // calls the member += operator overload on copy
	return copy; // return updated copy.
}

Student operator+(float grade, const Student& student)
{
	return student + grade; // calls operator+(const Student&, float)
}

int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.display();

	Administrator adm { 1235 };

	adm.changeStudentNo(harry, 1236);
	harry.display();
	

}