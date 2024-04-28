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

 // passing a Person reference
void show1(const Person& p) {
    p.display(std::cout);
    std::cout << std::endl;
}

// passing a Person pointer
void show2(const Person* p) {
    p->display(std::cout);
    std::cout << std::endl;
}

// passing an Person object itself
    /*
    Note that if we pass the argument to the show()
    function by value instead of by reference, the show()
    function would still call the most derived version of
    display(), but that most derived version would be for
    the Person version, since the copied object would be a
    Person in all cases.
    */
void show3(const Person p) {
    p.display(std::cout);
    std::cout << std::endl;
}

 // To override dynamic dispatch with early binding, 
 // we resolve the scope explicitly:
 // Here in show4 and show5 we called display function on a
 // Person reference and Person pointer. However, we explicityl
 // told that we want to call/use the display function
 // from Person class using :: operator 
 // (like this Person::display(std::cout)

void show4(const Person& p) {
    p.Person::display(std::cout);
    std::cout << std::endl;
}


// o override dynamic dispatch with early binding, 
// we resolve the scope explicitly:
void show5(const Person* p) {
    p->Person::display(std::cout);
    std::cout << std::endl;
}


int main() {

    /*
    We specify the dynamic type of a polymorphic object by 
    allocating memory dynamically using the appropriate 
    constructor from the inheritance hierarchy.
    At below:
    - p initially points to nothing (holds the null address). 
    The object's dynamic type is undefined.
    - After the first allocation, p points to a Person 
    type (dynamic type).
    - After the second allocation, p points to a Student \
    type (the new dynamic type).
    - The static and dynamic types are related to one another 
    through the hierarchy.

    Note that we only need one show() function to display
    both dynamic types.

    p holds the address a polymorphic object throughout 
    its lifetime. That address may change with deallocations 
    and fresh allocations of memory. The dynamic type may be 
    of any type in the Person hierarchy.

    show() is a polymorphic function. Its parameter receives 
    an unmodifiable reference to any type in the Person hierarchy.

    */

    Person* p = nullptr;
    p = new Person("Jane Doe");
    show1(*p);
    delete p;
    std::cout << "===============================" << std::endl;


    float g[] = { 89.4f, 67.8f, 45.5f };
    p = new Student("Harry", 1234, g, 3);
    show1(*p);
    delete p;
    std::cout << "===============================" << std::endl;

}