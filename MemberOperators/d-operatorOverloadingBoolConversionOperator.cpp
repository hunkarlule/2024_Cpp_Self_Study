#include <iostream>
using namespace std;

const int NG = 20;

class Student {
	int no;
	float grade[NG];
	int ng;
	void set(int studentNo, const float* studentGrades, int numOfGrades);
public:
	Student();
	Student(int studentNo, const float* studentGrades, int numOfGrades);
	void display() const;
	/*
	overloading the += operator for a float as the right operand,
	in order to add a single grade to a Student object
	*/
	Student& operator+=(float g);

	/*
	overloading the pre-fix increment operator for our Student
	class so that a pre-fix expression increases all of
	the Student's grades by one mark, if possible:
	*/
	Student& operator++();

	/*
	overloading the incrementing post-fix operator for our Student
	class so that a post-fix expression increases all of
	the Student's grades by one mark, if possible:
	*/

	// here the paramater int is not an actual parameter. It is only \
    // a placeholder/a distinguishing mark the compiler 
	// can distinguish  prefix version from prostfix version.
	Student operator++(int);


	/*
	overloading the pre-fix decrement operator for our Student
	class so that a pre-fix expression decreases all of
	the Student's grades by one mark, if possible:
	*/
	Student& operator--();


	/*
	overloading the post-fix decrement operator for our Student
	class so that a post-fix expression decreases all of
	the Student's grades by one mark, if possible:
	*/

	// here the paramater int is not an actual parameter. It is only \
    // a placeholder/a distinguishing mark the compiler 
	// can distinguish prefix version from prostfix version.
	Student operator--(int);

	/*
	conversion operator that returns true if the Student object
	has valid data and false if the object is in a safe empty state.

	here we do not need any return type because name
	operator bool already shows what this operator will do,

	we make it also const because it will not
	make any change on current object.
	*/
	operator bool() const;

};

Student::Student() {
	no = 0;
	ng = 0;
}

Student::Student(int sn, const float* g, int ng_) {
	set(sn, g, ng_);
}

void Student::set(int sn, const float* g, int ng_) {
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
		no = 0;
		ng = 0;
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

/*
overloading the += operator for a float as the right operand,
in order to add a single grade to a Student object
*/
Student& Student::operator+=(float g) {
	if (no != 0 && ng < NG && g >= 0.0f && g <= 100.0f) {
		grade[ng++] = g;
	}

	return *this;
}

/*
overloading the pre-fix increment operator for our Student
class so that a pre-fix expression increases all of
the Student's grades by one mark, if possible:
*/
Student& Student::operator++() {
	for (size_t i = 0; i < ng; i++) {
		if (grade[i] < 99.0f) {
			grade[i] += 1.f;
		}
	}

	return *this;
}

/*
overloading the incrementing post-fix operator for our Student
class so that a post-fix expression increases all of
the Student's grades by one mark, if possible:
*/

/*
here the paramater int is not an actual parameter.It is only \
a placeholder/a distinguishing mark the compiler
can distinguish  prefix version from prostfix version.
/*
post-fix increment/decrement operators return the original value(the value
before increment/decrement) and then increment and decrement the value.
*/
Student Student::operator++(int) {
	Student s = *this;  // save the original value before increment/decrement. we will be returning this.
	++(*this); // call the prefix increment operator to increment.
	return s; // return the original value
}

/*
overloading the pre-fix decrement operator for our Student
class so that a pre-fix expression decreases all of
the Student's grades by one mark, if possible:
*/
Student& Student::operator--() {
	for (size_t i = 0; i < ng; i++) {
		if (grade[i] > 1.0f) {
			grade[i] -= 1.0;
		}
		else {
			grade[i] = 0.0f;
		}
	}

	return *this;
}


/*
overloading the post-fix decrement operator for our Student
class so that a post-fix expression decreases all of
the Student's grades by one mark, if possible:
*/

/*
here the paramater int is not an actual parameter.It is only \
a placeholder/a distinguishing mark the compiler
can distinguish prefix version from prostfix version.

post-fix increment/decrement operators return the original value(the value
before increment/decrement) and then increment and decrement the value.
*/

Student Student::operator--(int) {
	Student s = *this; // save the original value before increment/decrement. we will be returning this.
	--(*this); // call the prefix decrement operator to decrement.
	return s; // return the orginal value.
}

/*
conversion operator that returns true if the Student object
has valid data and false if the object is in a safe empty state.

here we do not need any return type because name
operator bool already shows what this operator will do,

we make it also const because it will not
make any change on current object.
*/

Student::operator bool() const {
	return no != 0; // according to out business logic if student no is not zero then that student has valid data.
}

int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);

	// we can write this line like this: if(harry). And it will be better
	// in terms of readablity. See the below example.
	if (harry.operator bool()) { 
		harry.display();
	}
	else {
		cout << "evaluation result is false!";
	}


	// For the following code to compile, the compiler needs 
	// information on how to convert a Student object to a bool value:
	if (harry) {  // same as writing: if (harry.operator bool()) 
		harry.display();
	}
	else {
		cout << "evaluation result is false!";
	}

	Student josee;
	// For the following code to compile, the compiler needs 
	// information on how to convert a Student object to a bool value:
	if (josee) {
		josee.display();
	}
	else {
		cout << "evaluation result is false!";
	}


}

