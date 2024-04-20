
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


/*
class Keyword:
The keyword class identifies a class that is private by default.
We defined Student as struct. However we can change struct keyword
to class and our code will still work. The differnce is this:
==> In struct, everthing is public and accesible by client code by default. 
So, to make members private we need to do them private explicitly using
private midifier.
==> In class, everthing is private and accesible by client code by default.
So, to make members private we need to do them prublic explicitly using
public modifier.
*/
//struct Student {
class Student {
private: // default is private so we do not need to use private keyword here.
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
    //because we made display() public in Student class
    //client code can call display without any issue..
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

