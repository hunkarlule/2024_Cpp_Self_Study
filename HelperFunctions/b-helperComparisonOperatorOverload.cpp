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
	void display() const;
	int getStudentNo() const { return no; }
	int getNoGrades() const { return ng; }
	float getGrade(int i) const { return i < ng ? grade[i] : 0.0f; }
};

bool areIdentical(const Student& lhs, const Student& rhs);
bool operator==(const Student& lhs, const Student& rhs);

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

int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	float gh3[] = { 89.4f, 67.8f, 46.5f };
	Student harry(1234, gh, 3), harry2(1234, gh, 3), harry3(1234, gh3, 3);


	// we can write this line(if (harry == harry2)) like this:
	// if (operator==(harry, harry2)). However, this(if (harry == harry2)) is 
	// better because more readable and mathematical!.
	if (harry == harry2) { // same as writing if (operator==(harry, harry2))
		cout << "are adentical." << endl;
	}
	else {
		cout << "are different." << endl;
	}

	if (harry == harry3) { // same as writing if (operator==(harry, harry3))
		cout << "are adentical." << endl;
	}
	else {
		cout << "are different." << endl;
	}
}