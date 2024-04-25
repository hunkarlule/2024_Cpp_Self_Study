#include <iostream>


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

    int x = 10;
    int y = 20;
    int z = 30;
    /*
    Cascading support enables concatenation of operations 
    where the leftmost operand serves as the left operand for every 
    operation in a compound expression.
    */
    /*
    here how this cascading works:
    -- insertion operator(<<) prints x and returns cout. So, expresion becomes std::cout << y << z << std::endl; 
    -- insertion operator(<<) prints y and returns cout. So, expresion becomes std::cout << z << std::endl;
    -- insertion operator(<<) prints z and returns cout. So, expresion becomes std::cout << std::endl;
    -- insertion operator(<<) prints new line and returns cout.

    Returning a modifiable reference from a function lets the client code
    use the return value as the left operand for the operator on its right.
    */
    std::cout << x << y << z << std::endl; 

    return 0;
}