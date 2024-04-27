// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int NC = 30;
const int NG = 20;

class Person {
    char name[NC + 1];
public:
    Person();
    Person(const char*);
    ~Person();
    void display(std::ostream&) const;
};

std::istream& operator>>(std::istream& is, Person& person);
std::ostream& operator<<(std::ostream& os, const Person& person);

class Student : public Person {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(const char*, int, const float*, int);
    ~Student();
    void read(std::istream&);
    void display(std::ostream&) const;
};

std::istream& operator>>(std::istream& is, Student& student);
std::ostream& operator<<(std::ostream& os, const Student& student);

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

Person::~Person()
{
    std::cout << "Leaving " << name << std::endl;
}

void Person::display(ostream& os) const {
    os << name << ' ';
}

std::istream& operator>>(std::istream& is, Person& p)
{
    char name[NC + 1];
    cout << "Name: ";
    is.getline(name, NC + 1);
    p = Person(name);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    p.display(os);
    return os;
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

Student::~Student()
{
    std::cout << "\nLeaving " << no << std::endl;
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

void Student::read(istream& is) {
    char name[NC + 1]; // will hold the student's name
    int no;            // will hold the student's number
    int ng;            // will hold the number of grades
    float grade[NG];   // will hold the grades

    std::cout << "Name: ";
    is.getline(name, NC + 1);
    cout << "Student Number : ";
    is >> no;
    cout << "Number of Grades : ";
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        cout << "Grade " << i + 1 << " : ";
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(name, no, grade, ng);
    // if data is valid, the temporary object into the current object
    if (temp.no != 0)
        *this = temp;
}

istream& operator>>(istream& is, Student& s) {
    s.read(is);
    return is;
}


ostream& operator<<(ostream& os, const Student& s) {
    s.display(os);
    return os;
}



int main() {
    Person jane;
    Student harry;

    std::cin >> jane;
    std::cin >> harry;
    std::cout << jane << std::endl;
    std::cout << harry << std::endl;
}