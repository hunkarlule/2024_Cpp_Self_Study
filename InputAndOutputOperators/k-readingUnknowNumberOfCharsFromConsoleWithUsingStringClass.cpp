#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

/* The prototypes for the overloaded insertion and extraction operators for
standard input and output on objects of our own classes
    std::istream& operator>>(std::istream&, Type&);
    std::ostream& operator<<(std::ostream&, const Type&);
*/

// Student.h

#include <iostream> // for std::ostream
const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void read(std::istream& is);
    void display(std::ostream& os) const;
};

std::istream& operator>>(std::istream& is, Student& student);
std::ostream& operator<<(std::ostream& os, const Student& student);

// Student.cpp
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

void Student::read(std::istream& is)
{
    int no;          // will hold the student number
    int ng;          // will hold the number of grades
    float grade[NG]; // will hold the grades

    std::cout << "Student number: ";
    is >> no;
    std::cout << "Number of grades: ";
    is >> ng;

    if (ng > NG) {
        ng = NG;
    }
    for (int i = 0; i < ng; i++) {
        std::cout << "Grade " << i + 1 << ": ";
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(no, grade, ng);
    // if data is valid, the temporary object into the current object
    if (temp.no != 0) {
        *this = temp;
    }


}

void Student::display(std::ostream& os) const {
    if (no > 0) {
        os << no << ":\n";
        os.setf(std::ios::fixed);
        os.precision(2);
        for (int i = 0; i < ng; i++) {
            os.width(6);
            os << grade[i] << std::endl;
        }
        os.unsetf(std::ios::fixed);
        os.precision(6);
    }
    else {
        os << "no data available"
            << std::endl;
    }
}

std::istream& operator>>(std::istream& is, Student& s)
{
    s.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    s.display(os);
    return os;
}

/*
The standard library's string class allocates the required amount of memory 
dynamically during the input process itself. A std::string object can accept 
as many characters as the user enters. The helper function std::getline() 
extracts the characters from the input stream.

The prototype for this helper function is

std::istream& getline(std::istream&, std::string&, char);

The first parameter receives a modifiable reference to the std::istream object, 
the second parameter receives a modifiable reference to the std::string object 
and the third parameter receives the character delimiter for terminating 
extraction (newline by default).

The <string> header file contains the class definition with this prototype. 
The class definition includes two member functions for converting its internal
data into a C-style null-terminated string:

std::string::length(): Returns the number of characters in the string
std::string::c_str(): Returns the address of the C-style null-terminated 
version of the string
*/

/*
The following client code extracts an unknown number of characters 
from the standard input stream, stores them in a C-style null-terminated string 
and displays the character string on the standard output object in 6 steps:

1- Define a string object to accept the input
2- Extract the input using the std::getline() helper function
3- Query the string object for the memory required
4- Allocate dynamic memory for the requisite C-style null-terminated string
5- Copy the data from the string object to the allocated memory
6- Deallocate the allocated memory

*/

int main() {
    char* s;
    std::string str;

    std::cout << "enter a string: ";
    if (std::getline(std::cin, str)) {
        s = new char[str.length() + 1];
        std::strcpy(s, str.c_str());
        std::cout << "the string entered is: >" << s << "<" << std::endl;

        delete[] s;
    }
    return 0;
}


