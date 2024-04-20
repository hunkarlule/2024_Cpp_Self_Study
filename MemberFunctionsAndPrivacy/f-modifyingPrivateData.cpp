
#include <iostream>
using namespace std;

void displayNo(); // prototype decleration of global displayNo function.
const int NG = 20;


/*
Modifying Private Data
If the data members of a class are private, client code cannot initialize 
their values directly. We use a separate member function for this 
specific task.

For example, to store data in Student objects, let us introduce 
a public modifier named set():
*/
class Student {
private: // default is private so we do not need to use private keyword here.
    int no{123};          // student number
    float grade[NG]{67.8f, 85.3f}; // grades
    int ng{ 2 };          // number of grades filled in grade array.
    
    // with public keyword, the members(data and function) under it 
    // became public and CAN be accessed by client code dorectly.
public:
    // const keyword make sure that display function will not change the
    // Student object(its dat members) that operates on.
    // In other words, const makes dipslay a query/getter.
    void display() const; // member function
    void displayNo() const; // member function
    void set(int studentNo, const float* studentGrades, int numberOfGrades);
};

void foo(const Student& student);

// Any attempt by the client code to access a private member 
// generates a complier error:
// here we defined a global foo func and passing it a
// Student reference. Inside the func, we try to reach data 
// member(no) of the student. Compiler gives "inaccessible" error
// becuase data-member no is private in Student class.
// The function foo() can only access the data stored in harry indirectly 
// through public member function display().
void foo(const Student& student) {
    //cout << student.no;  // ERROR - this member is private!
    student.display(); // OK because dislay func in Student class public.

}


void Student::display() const {
    // we can also call global functions from member functions. see we have 
    // to displayNo functions. One ie member function and other is global fuynction.

    // To access the global function from within the member function we 
    // apply the scope resolution operator:
    ::displayNo(); //calls global displayNo function.
    //cout << no << ": \n";
    displayNo(); // calls the member function  displayNo()
    for (int i = 0; i < ng; i++) {
        cout << grade[i] << endl;
    }
}

void Student::displayNo() const {
    cout << no << ": \n";
}

/*
set() receives a student number, the address of an unmodifiable array 
of grades and the number of grades in that array from the client 
code and stores this information in the data members of the Student 
object:
*/
void Student::set(int studentNo, const float* studentGrades, int numberOfGrades)
{
    // determine how many grades will be saved in grade array of student.
    ng = numberOfGrades < NG ? numberOfGrades : NG;
    no = studentNo; // store the Student number as received
    
    // store the grades as received within the available space
    for (size_t i = 0; i < ng; i++) {
        grade[i] = studentGrades[i];
    }
}

/*
Note that this definition does not include any scope resolution identifier.
This global function shares the same identifier with one of the member
functions, but does not introduce any conflict, since the client code
calls each function using different syntax.
*/
void displayNo() {
    cout << "Number...\n";
}

int main() {
    /*
    The set() and display() member functions are the only communication 
    links to client code. Clients can call set() or display() on any 
    Student object, but no client code can access the data stored within 
    any Student object directly.

        For example, the compiler traps this: cout << harry.no; due to privacy breach:
    */
    Student harry;
    float g[] = { 78.9f, 69.4f };
    harry.display(); // calling display member function for student harry.
    cout << endl;

    // setting harry's state callin set function of Student class
    harry.set(975, g, 2);

    harry.display(); // calling display member function for student harry.
    cout << endl;


    //cout << harry.no; // ERROR .no IS PRIVATE!
    return 0;
}

