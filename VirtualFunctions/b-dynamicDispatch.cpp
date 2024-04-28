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
    /*
    C++ provides the keyword virtual for dynamic dispatching. 
    If this keyword is present, the compiler inserts code that 
    binds the call to most derived version of the member function 
    based on the dynamic type.
    */
    virtual void display(std::ostream&) const;
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
The output in the below example omits the details for the 
Student part of harry. To output these details, we need to 
postpone the binding of the call to display() until run-time 
when the executable code is aware of the dynamic type of object p.
We refer to this postponement as dynamic dispatch.

C++ provides the keyword virtual for dynamic dispatching. 
If this keyword is present, the compiler inserts code that 
binds the call to most derived version of the member function 
based on the dynamic type.

For example, the keyword virtual in the following Person class
definition instructs the compiler to postpone calling 
the display() member function definitions until run-time:

Note that the implementation file and the client program 
have not changed. Because the keyword is present, the compiler 
overrides the early binding of display() so that the show() 
function will call the most derived version of display() 
for the type of the argument passed to it.

Each call to show() passes a reference to an object of different dynamic type:

show(harry) passes an unmodifiable reference to a Student
show(jane) passes an unmodifiable reference to a Person
In each case, the executable code binds at run time the 
version of display() that is the most derived version 
for the dynamic type referenced by the parameter in show().
*/

void show(const Person& p) {
    p.display(std::cout);
    std::cout << std::endl;
}

int main() {
    Person jane("Jane Doe");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry("Harry", 1234, gh, 3);

    harry.display(std::cout);
    jane.display(std::cout);
    std::cout << std::endl;

    std::cout << "===============================" << std::endl;
    show(harry);
    show(jane);
}