// Student.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int NC = 30;
const int NG = 20;

class Person {
    char name[NC + 1];
public:
    void set(const char* n);
    void display(std::ostream&) const;
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
};

// Student.cpp

#include <cstring>

using namespace std;

void Person::set(const char* n) {
    strncpy(name, n, NC);
    name[NC] = '\0';
}

void Person::display(std::ostream& os) const {
    os << "display function from Person class: " << std::endl;
    os << name << ' ';
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
        os << "display function from Student class: " << std::endl;
        
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


int main() {
    Person jane;
    
    jane.set("Jane Doe");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);

    /*
    harry.display(std::cout) calls Student::display(), which calls 
    the shadowed Person::display(), while jane.display() calls 
    Person::display() directly. The derived version shadows the base 
    version when called on harry.
    */
    harry.set("Harry"); // set inherited from Person class
    /*
     Student class inherited display function from Person class
     als Student class defined a display function itself. Therefore,
     Below call in harry calls the one from Student class. So, we say 
     that the one from the Student class shadows the one from Person class.
    */
    harry.display(std::cout);  // The one in Student class is called here.
    jane.display(std::cout); 
    std::cout << std::endl;
    /*
    Using Person class with :: operator like this(Person::display(std::cout))
    we explicitly called the display function that is inherited from
    Person class. So, we handled/overcome the shawoding.
    */
    harry.Person::display(std::cout); // The one in Person class is called here


    return 0;
}