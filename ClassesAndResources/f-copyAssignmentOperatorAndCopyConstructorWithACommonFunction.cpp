#include <iostream>
using namespace std;

class Student
{
	int no;
	float* grade;
	int ng;
	void init(const Student& source);
public:
	Student();
	Student(int studentNo);
	Student(int studentNo, const float* studentGrades, int numOfGrades);
	// copy constrcutor. because we provided this one the 
	// complier will not insert the default copy-constructor anymore.
	Student(const Student& srcStudent);
	// copy-assignment-operator. because we provided this one the 
	// compiler will not insert the default copy-assignment-operator
	// anymore.
	Student& operator=(const Student& srcStudent);
	~Student();
	void display();
	void setFirstGrade(float newGrade);
	void displayGrade() const;
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

Student::Student(const Student& src)
{
	init(src);
}

Student& Student::operator=(const Student& source)
{
	// 1. check for self-assignment (and NOTHING else)
	/*
	To trap a self-assignment from the client code (a = a), 
	we compare the address of the current object to the address 
	of the source object. If the addresses match, we skip 
	the assignment logic altogether. If we neglect to check for 
	self-assignment, the deallocation statement would release 
	the memory holding the resource data and we would lose access 
	to the source resource resulting in our logic failing 
	at grade[i] = source.grade[i].
	*/
	if (this != &source) {
		// 2. clean up (deallocate previously allocated dynamic memory) of current object
		delete[] grade;
		grade = nullptr;
		init(source);
	}

	return *this;
}

// because copy-constrcutor and copy-assignment-operator code is almost
//same. so, to simplify things we got/extracted that common code into 
// a private member function and we will call this inside 
// copy-constrcutor and copy-assignment-operator
void Student::init(const Student& source)
{
	no = source.no;
	ng = source.ng;

	if (source.grade != nullptr) {
		grade = new float[ng];
		for (int i = 0; i < ng; i++) {
			grade[i] = source.grade[i];
		}	
	}
	else {
		grade = nullptr;
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

void Student::setFirstGrade(float newGrade)
{
	grade[0] = newGrade;
}

void Student::displayGrade() const {
	cout << grade << endl;
}

int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.display();
	cout << "===============\n";

	Student nancy;
	nancy.display();
	cout << "===============\n";
	// here we assigned harry to nancy. So, 
	// it will cause a call to copy-assignment-operator
	// so, nancy will be created using
	// the copy-assignment-operator that we wrote. 
	// It will make deep copy.
	nancy = harry;
	nancy.display();
	cout << "===============\n";

	// because copy-assignment-operator did a deep copy 
	// changing fist grade of harry  did not changed the 
	// fist grade of nancy. because grade pointer 
	// for each object points to different location.
	harry.setFirstGrade(99.90);
	harry.display();
	nancy.display();
	cout << "===============\n";
	harry.displayGrade();
	nancy.displayGrade();

	return 0;
}
