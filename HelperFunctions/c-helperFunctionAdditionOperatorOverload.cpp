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
};

bool areIdentical(const Student& lhs, const Student& rhs);
bool operator==(const Student& lhs, const Student& rhs);
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
bool operator==(const Student& lhs, const Student& rhs)
{
	bool same = lhs.getStudentNo() == rhs.getStudentNo() &&
		lhs.getNoGrades() == rhs.getNoGrades();
	for (int i = 0; i < lhs.getNoGrades() && same; i++) {
		same = lhs.getGrade(i) == rhs.getGrade(i);
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
	harry = harry + 63.7f;
	harry.display();

	harry.display();
	harry = 99.3f + harry;
	harry.display();

	return 0;
}