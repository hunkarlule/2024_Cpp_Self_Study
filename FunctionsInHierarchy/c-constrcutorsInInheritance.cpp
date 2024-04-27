// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int NC = 30;
const int NG = 20;

class Person {
    char name[NC + 1];
public:
    Person();
    void set(const char* n);
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
    Student(int, const float*, int);
    void display(std::ostream&) const;
    using Person::display;
};

// Student.cpp

#include <cstring>

using namespace std;

Person::Person()
{
    std::cout << "Person()" << std::endl;
    name[0] = '\0';
}

void Person::set(const char* n) {
    strncpy(name, n, NC);
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
    *this = Student(n, g, 0);
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
In this example, the compiler constructs the two objects as follows:

Allocates memory for jane
Allocates memory for person
The base class constructor initializes person to an empty string
Allocates memory for harry 1. Allocates memory for name 2. 
The base class constructor initializes name to an empty string allocates
memory for no, grade and ng 3. The derived class constructor initializes:
- no to 1234 - grade to {89.40f, 67.80f, 45.50f} - ng to 3

*/

int main() {
    Person jane;
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);

    harry.set("Harry");
    harry.display(std::cout);

    jane.set("Jane Doe");
    jane.display(std::cout);
    std::cout << std::endl;


    return 0;
}