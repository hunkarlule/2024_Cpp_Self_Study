// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int NC = 30;
const int NG = 20;

class Person {
    char name[NC + 1];
public:
    Person();
    //void set(const char* n);
    Person(const char* name);
    void display(std::ostream&) const;
    void display(std::ostream& os, const char* msg) const;
};

class Student : public Person {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    //Student(int stundetNo, const float* stundetGrades, int noOfGrades);
    Student(const char* studentName,int stundetNo, const float* stundetGrades, int noOfGrades);
    void display(std::ostream&) const;
    using Person::display;
};


/*
C++11 introduced syntax for inheriting a base class constructor 
in cases where the derived class constructor does not execute 
any logic on the instance variables of the derived class and 
only passes to the base class constructor values received 
from the client. In such cases, the derived class may 
inherit the base class constructors.

The declaration for inheriting a base class constructor takes 
the form:

using Base::Base;

where Base is the name of the base class.

Instructor class from the Person base class and inherit all 
of the constructors of the base class. The header file overrides 
the no-inheritance default:
*/
class Instructor : public Person {
public:
    // with this one we inherited the base class(Person)'s
    //constructors in  Instructor class.
    using Person::Person;
};

// Student.cpp

#include <cstring>

using namespace std;

Person::Person()
{
    std::cout << "Person()" << std::endl;
    name[0] = '\0';
}

//void Person::set(const char* n) {
//    strncpy(name, n, NC);
//    name[NC] = '\0';
//}

Person::Person(const char* nm)
{
    strncpy(name, nm, NC);
    name[NC] = '\0';
}

void Person::display(std::ostream& os) const {
    os << "display function with 1-arguments from Person class: " << std::endl;
    os << name << ' ';
}

void Person::display(std::ostream& os, const char* msg) const
{
    os << "display function with 2-arguments from Person class: " << std::endl;
    os << msg << name << ' ';
}

Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int n) {
    float g[] = { 0.0f };
    *this = Student("", n, g, 0);
}

/*
Each constructor forwards the values for the base class part of 
the object to the base class constructor. The base class constructor uses 
the values received to build the base class part of the object. 
The derived class constructor uses the values received to complete 
building the derived class part of the object.

A call to the base class constructor from a derived class constructor 
that forwards values takes the form

Derived( parameters ) : Base( arguments )

where Derived is the name of the derived class and Base is the name of 
the base class. The single colon separates the header of the \
derived-class constructor from its call to the base class constructor. 
If we omit this call, the compiler inserts a call to the default 
base class constructor.
*/

/*
this part(: Person(nm)) making a call to base/parent class 
constrcutor and initizalize the base part of the Student object
The importan thing is that: If we do nor provide this(this part(: Person(nm)))
then compiler will insert a similar code there for us during 
compilation. The compiler will put a call for no-argument
constrcutor. So, compiler's call will be like this(: Person())
*/
Student::Student(const char* nm, int sn, const float* g, int ng_) : Person(nm) 
{
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

//Student::Student(int sn, const float* g, int ng_) {
//    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
//    if (valid)
//        for (int i = 0; i < ng_ && valid; i++)
//            valid = g[i] >= 0.0f && g[i] <= 100.0f;
//
//    if (valid) {
//        // accept the client's data
//        no = sn;
//        ng = ng_ < NG ? ng_ : NG;
//        for (int i = 0; i < ng; i++)
//            grade[i] = g[i];
//    }
//    else {
//        *this = Student();
//    }
//}

void Student::display(ostream& os) const {
    if (no > 0) {
        os << "display function with 1-arguments from Student class: " << std::endl;
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

/*

*/

int main() {
    Instructor john("John");
    Person jane("Jane");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry("Harry", 1234, gh, 3);

    john.display(std::cout);
    std::cout << std::endl;
    harry.display(std::cout);
    jane.display(std::cout);

    return 0;
}