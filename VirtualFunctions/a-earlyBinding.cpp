// Early Binding
// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
const int NC = 30;
const int NG = 20;

/*
Note that this hierarchy has two distinct definitions of the
member function named display(). Both Person class and Student class
has a display member function.
*/
class Person {
    char name[NC + 1];
public:
    Person();
    Person(const char*);
    void display(std::ostream&) const;
};

class Student : public Person {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(const char*, int, const float*, int);
    void display(std::ostream&) const;
};

// Student.cpp

#include <cstring>
using namespace std;

Person::Person() {
    name[0] = '\0';
}

Person::Person(const char* nm) {
    strncpy(name, nm, NC);
    name[NC] = '\0';
}

void Person::display(ostream& os) const {
    os << name << ' ';
}

Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int n) {
    float g[] = { 0.0f };
    *this = Student("", n, g, 0);
}

Student::Student(const char* nm, int sn, const float* g, int ng_) : Person(nm) {
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

void Student::display(ostream& os) const {
    if (no > 0) {
        Person::display(os);
        os << no << ":\n";
        os.setf(ios::fixed);
        os.precision(2);
        for (int i = 0; i < ng; i++) {
            os.width(6);
            os << grade[i] << endl;
        }
        os.unsetf(ios::fixed);
        os.precision(6);
    }
    else {
        os << "no data available" << endl;
    }
}

// Function Bindings
// functionBindings.cpp

/*
The below code defines a global function 
named show(). This client code calls that global function twice, 
first for a Student object and second for a Person object. 
The global function show() in turn calls the display member 
function on p. The compiler binds the call to this member 
function to its Person version. C++ applies this convention 
irrespective of the argument type in the call to show(). 
That is, the compiler uses the parameter type in definition 
of show() to determine the kind of binding to implement. 
We call this binding an early binding.

Early binding occurs at compile time and is the most efficient 
binding of a member function call to that function's definition.
Early binding is the default in C++.

Note that shadowing does not occur inside the global function 
show(). show() has no way of knowing which version of display() 
to select aside from the type of its parameter p. The statements 
harry.display() and jane.display() in the main() function 
demonstrate shadowing. The call to display() on harry shadows 
the base version of display().
*/

void show(const Person& p) {
    p.display(std::cout);
    std::cout << std::endl;
}

int main() {
    Person jane("Jane Doe");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry("Harry", 1234, gh, 3);

    harry.display(std::cout); // calls the version defined in Student class. Means it shadows the version from Person class.
    jane.display(std::cout); // calss the version defines in Person class
    std::cout << std::endl;

    std::cout << "===============================" << std::endl;
    show(harry);
    show(jane);


}