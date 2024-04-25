#include <iostream>
#include <fstream>

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

int main() {
    int i;

    /*
    A file object reads from a file under format control using the extraction 
    operator in the same way as the standard input object (cin) reads using 
    the extraction operator.
    */
    std::ifstream fin1("input.txt"); //connects file object fin1 to input.txt for reading.
    
    if (fin1.is_open()) {
        /*
        The file stream class definition overload the bool conversion operator 
        to return false if the object is not ready for further streaming. 
        A stream object is not ready for further streaming if it has encountered 
        an error and has not been cleared.
        */
        while (fin1) {
            fin1 >> i;
            if (fin1) {
                std::cout << i << " ";
            }
            else {
                std::cout << "\n**bad input**\n";
            }
        }
    }
    return 0;
}


