
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
*/


void displayNo(); // prototype decleration of global displayNo function.
const int NG = 20;

struct Student {
    int no;          // student number
    float grade[NG]; // grades
    int ng;          // number of grades filled in grade array.

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

    Student harry = { 975, {78.9f, 68.4f}, 2 };
    harry.display(); // calling display member function for student harry.
    cout << endl;

    // because struct members are default public can change the
    // object's data(state) like this directly. It can set them
    // meaningless values. This is not a good design. We need to
    // restrict the access of client to objetc's data. To do that,
    // we need access modifiers when defining struct.
    harry.no = -999;
    harry.grade[0] = -35.4f;

    harry.display(); // calling display member function for student harry.
    cout << endl;
    return 0;
}