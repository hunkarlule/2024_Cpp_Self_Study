#include <iostream>
using namespace std;

const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
    void set(int studentNo, const float* studentGrades, int numOfGrades);
public:
    Student();
    Student(int studentNo, const float* studentGrades, int numOfGrades);
    void display() const;
    /*
    overloading the += operator for a float as the right operand,
    in order to add a single grade to a Student object
    */
    Student& operator+=(float g);

    /*
    overloading the pre-fix increment operator for our Student 
    class so that a pre-fix expression increases all of 
    the Student's grades by one mark, if possible:
    */
    Student& operator++();

    /*
    overloading the incrementing post-fix operator for our Student 
    class so that a post-fix expression increases all of 
    the Student's grades by one mark, if possible:
    */
    
    // here the paramater int is not an actual parameter. It is only \
    // a placeholder/a distinguishing mark the compiler 
    // can distinguish  prefix version from prostfix version.
    Student operator++(int);
};


Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int sn, const float* g, int ng_) {
    set(sn, g, ng_);
}

void Student::set(int sn, const float* g, int ng_) {
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
        no = 0;
        ng = 0;
    }
}

void Student::display() const {
    if (no > 0) {
        cout << no << ":\n";
        cout.setf(ios::fixed);
        cout.precision(2);
        for (int i = 0; i < ng; i++) {
            cout.width(6);
            cout << grade[i] << endl;
        }
        cout.unsetf(ios::fixed);
        cout.precision(6);
    }
    else {
        cout << "no data available" << endl;
    }
}

/*
overloading the += operator for a float as the right operand,
in order to add a single grade to a Student object
*/
Student& Student::operator+=(float g) {
    if (no != 0 && ng < NG && g >= 0.0f && g <= 100.0f) {
        grade[ng++] = g;
    }

    return *this;
}

/*
overloading the pre-fix increment operator for our Student
class so that a pre-fix expression increases all of
the Student's grades by one mark, if possible:
*/
Student& Student::operator++() {
    for (size_t i = 0; i < ng; i++) {
        if (grade[i] < 99.0f) {
            grade[i] += 1.f;
        }
    }

    return *this;
}

/*
overloading the incrementing post-fix operator for our Student
class so that a post-fix expression increases all of
the Student's grades by one mark, if possible:
*/

/* 
here the paramater int is not an actual parameter.It is only \
a placeholder/a distinguishing mark the compiler 
can distinguish  prefix version from prostfix version.
/*
post-fix increment/decrement operators return the original value(the value
before increment/decrement) and then increment and decrement the value.
*/
Student Student::operator++(int) {
    Student s = *this;  // save the original value before increment/decrement. we will be returning this.
    ++(*this); // call the prefix increment operator to increment.
    return s; // return the original value
}

int main() {
    float gh[] = {89.4f, 67.8f, 45.5f};
    Student harry(1234, gh, 3), backup;
    harry.display();

    // here passed 0 as argument/parameter value. but it is 
    // meaningles becuase we do not use it anywhere in the function
    // body. passing 0 only tells the compiler that "we want to call
    // post-fix version of the increment(++) operator.
    backup = harry.operator++(0);
    harry.display();
    backup.display();


    // this is eqaul to writing harry.operator++(0); 
    // Like the above one. However this is better because we use ++
    // in a way that we use it with fundamantal types(like int).
     backup = harry++; // this is eqaul to writing ==> backup = harry.operator++(0);
     harry.display();
     backup.display();
}

