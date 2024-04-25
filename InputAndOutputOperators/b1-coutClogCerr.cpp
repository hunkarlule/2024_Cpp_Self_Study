#include <iostream>


// Student.h
#include <iostream> // for std::ostream
// in .h files do not use "using" keyword like this: "using namespace std"
//If you need to use anything/an identifier from a name space in .h file then resolve
// that identifier only(like we did in decleration of display:  void display(std::ostream& os) const;)

const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void display(std::ostream& os) const;
};

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

int main() {
    float gh[] = { 89.4f, 55.3f, 68.6f };
    Student harry(1234, gh, 3);
    harry.display(std::cout);
    harry.display(std::clog);
    harry.display(std::cerr);

    return 0;
}