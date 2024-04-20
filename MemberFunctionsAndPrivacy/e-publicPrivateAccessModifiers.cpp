
#include <iostream>
using namespace std;

/*
Privacy
Data privacy is central to encapsulation. Data members defined using
the struct keyword are exposed to client code.
Any client code can change the value of a data member.
To limit accessibility to any member, the C++ language lets us hide
that member within the class by identifying it as private.

Well-designed object-oriented solutions expose to client code only
those members that are the class's communication links. In a good design,
the client code should not require direct access to any data
that describes an object's state or any member function that performs
internally directed operations.

In a struct, all members( data members and member functions) are default
public. So, they can be accessed directly by the client code. This is not
a good design!

Accessibility Labels:
To prohibit external access to any member (data or function),
we insert the label private into the definition of our class:

private:
private identifies all subsequent members listed in the class
definition as inaccessible.

To enable external access, we insert the label public:

public:
public identifies all subsequent members listed in the class
definition as accessible.

For example, in order to:

-- Hide the data members of each Student object
-- Expose the member function(s) of the Student type
We insert the accessibility keywords as follows
*/


void displayNo(); // prototype decleration of global displayNo function.
const int NG = 20;

struct Student {
    // with private keyword, the members(data and function) under it 
    // became private and  CANNOT be accessed by client code dorectly.
private:
    int no{123};          // student number
    float grade[NG]{67.8, 85.3}; // grades
    int ng{ 2 };          // number of grades filled in grade array.

    // with public keyword, the members(data and function) under it 
    // became public and CAN be accessed by client code dorectly.
public:
    // const keyword make sure that display function will not change the
    // Student object(its dat members) that operates on.
    // In other words, const makes dipslay a query/getter.
    void display() const; // member function
    void displayNo() const; // member function
};


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
Note that this definition does not include any scope resolution identifier.
This global function shares the same identifier with one of the member
functions, but does not introduce any conflict, since the client code
calls each function using different syntax.
*/
void displayNo() {
    cout << "Number...\n";
}

int main() {

    Student harry;
    harry.display(); // calling display member function for student harry.
    cout << endl;

    // because we made data mebers of the Student struct private
    // clien code can not access them directly. So, compiler
    // gives error telling this.
         /* harry.no = -999;
            harry.grade[0] = -35.4f;*/

    harry.display(); // calling display member function for student harry.
    cout << endl;
    return 0;
}

