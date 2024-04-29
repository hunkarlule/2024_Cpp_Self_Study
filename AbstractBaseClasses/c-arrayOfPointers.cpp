

// Abstract Base Class for the Person Hierarchy
// iPerson.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// abstract class
class iPerson {
public:
    // pure virtual function.
    virtual void display(std::ostream&) const = 0;
};

// prototype for a global function that creates the object:
iPerson* CreatePerson();

// Late Binding
// Student.h

#include <iostream>
const int NC = 30;
const int NG = 20;

class Person : public iPerson {
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

//Person::~Person()
//{
//    std::cout << "Leaving " << name << std::endl;
//}

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

//Student::~Student()
//{
//    std::cout << "\nLeaving " << no << std::endl;
//}

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


iPerson* CreatePerson() {

    iPerson* p = nullptr;
    int type, no, ng;
    float grade[NG];
    char name[NC + 1];
    bool repeat;

    do {
        std::cout << "Type (0,1,2): ";
        std::cin >> type;
        std::cin.ignore();
        repeat = false;

        switch (type) {
        case 0:
            break;
        case 1:
            std::cout << "Name: ";
            std::cin.getline(name, NC + 1);
            p = new Person(name);
            break;
        case 2:
            std::cout << "Name: ";
            std::cin.getline(name, NC + 1);
            std::cout << "Student number: ";
            std::cin >> no;
            std::cout << "Number of grades: ";
            std::cin >> ng;
            if (ng > NG) {
                ng = NG;
            }

            for (int i = 0; i < ng; i++) {
                std::cout << " Grade " << i + 1 << ": ";
                std::cin >> grade[i];
                std::cin.ignore();
            }

            p = new Student(name, no, grade, ng);
            break;
        default:
            repeat = true;
            std::cout << "Invalid type. Try again\n";
        }
    } while (repeat);

    return p;
}

const int NP = 5;

int main() {
    // because iPerson is an abstract class
    // we can not crete an instanc of it
    //iPerson();

    iPerson* p[NP];

    for (int i = 0; i < NP; i++) {
        p[i] = nullptr;
    }

    int n = 0;
    bool quit = false;

    do {
        iPerson* ptemp = CreatePerson();

        if (ptemp != nullptr) {
            p[n++] = ptemp;
        }
        else {
            quit = true;
        } 
    } while (n < NP && !quit);

    for (int j = 0; j < n; j++) {
        p[j]->display(std::cout);
        std::cout << std::endl;
    }

    for (int j = 0; j < n; j++) {
        delete p[j];
    }

    return 0;
}