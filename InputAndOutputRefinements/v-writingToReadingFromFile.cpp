#include <iostream>
#include <iomanip>


// Student.h

#include <iostream> // for std::ostream, std::istream
#include <fstream>  // for std::ifstream
const int NG = 13;

class StudentFile;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void read(std::istream&);
    void read(std::ifstream&);
    void display(std::ostream& os) const;
    void display(StudentFile& os) const;
};

std::istream& operator>>(std::istream& is, Student& s);
std::ostream& operator<<(std::ostream& os, const Student& s);
std::ifstream& operator>>(std::ifstream& is, Student& s);

class StudentFile {
public:
    std::ofstream f;
    StudentFile(const char*);
    StudentFile& operator<<(char);
    StudentFile& operator<<(int);
    StudentFile& operator<<(float);
    void close();
};

StudentFile& operator<<(StudentFile& os, const Student& s);

// Student.cpp

//#include "Student.h"

Student::Student()
{
    no = 0;
    ng = 0;
}

Student::Student(int n)
{
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

void Student::read(std::istream& is) {
    int no;          // will hold the student number
    int ng;          // will hold the number of grades
    float grade[NG]; // will hold the grades

    std::cout << "Student Number : ";
    is >> no;
    std::cout << "Number of Grades : ";
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        std::cout << "Grade " << i + 1 << " : ";
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(no, grade, ng);
    // if data is valid, copy temporary object into current object
    if (temp.no != 0)
        *this = temp;
}

void Student::read(std::ifstream& is) {
    int no;          // will hold the student number
    int ng;          // will hold the number of grades
    float grade[NG]; // will hold the grades

    is >> no;
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(no, grade, ng);
    // if data is valid, copy temporary object into current object
    if (temp.no != 0)
        *this = temp;
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
        os << "no data available" << std::endl;
    }
}

void Student::display(StudentFile& os) const {
    os << no << '\n';
    os << ng << '\n';
    for (int i = 0; i < ng; i++)
        os << grade[i] << '\n';
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    s.display(os);
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    s.read(is);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Student& s) {
    s.read(is);
    return is;
}

StudentFile& operator<<(StudentFile& f, const Student& s) {
    s.display(f);
    return f;
}

StudentFile::StudentFile(const char* filename) : f(filename) {}

StudentFile& StudentFile::operator<<(char c) {
    f << c;
    return *this;
}

StudentFile& StudentFile::operator<<(int i) {
    f << i;
    return *this;
}

StudentFile& StudentFile::operator<<(float v) {
    f << v;
    return *this;
}

void StudentFile::close() {
    f.close();
}


// Custom File Operators
// customFile.cpp

#include <iostream>
//#include "Student.h"

int main() {
    Student harry;

    std::cin >> harry;
    std::cout << harry;

    StudentFile studentFile("Student.txt");
    studentFile << harry;
    studentFile.close();

    std::ifstream inFile("Student.txt");
    inFile >> harry;
    std::cout << harry;
}

