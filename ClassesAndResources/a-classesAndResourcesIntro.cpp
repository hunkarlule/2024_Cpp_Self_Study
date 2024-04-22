#include <iostream>
using namespace std;

class Student
{
	int no;
	float* grade;
	int ng;
public:
	Student();
	Student(int studentNo);
	Student(int studentNo, const float* studentGrades, int numOfGrades);
	~Student();
	void display();



};

Student::Student()
{
	no = 0;
	ng = 0;
	grade = nullptr;
}

Student::Student(int sn) 
{
	float g[] = { 0.0f };
	grade = nullptr;
	*this = Student(sn, g, 0);
}

Student::Student(int sn, const float* g, int ng_)
{
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	if (valid) {
		for (int i = 0; i < ng_ && valid; i++) {
			valid = g[i] >= 0.0f && g[i] <= 100.0f;
		}
	}

	if (valid) {
		// accept the client's data
		no = sn;
		ng = ng_;
		// allocate dynamic memory
		if (ng > 0) {
			grade = new float[ng];
			for (int i = 0; i < ng; i++) {
				grade[i] = g[i];
			}
		}
		else {
			grade = nullptr;
		}
	}
	else {
		grade = nullptr;
		*this = Student();
	}
}

Student::~Student()
{
	delete[] grade;
	grade = nullptr;
}

void Student::display()
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

int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.display();

	Student josee(1235);

	Student nancy;

	return 0;
}
