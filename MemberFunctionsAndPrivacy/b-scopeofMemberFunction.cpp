
#include <iostream>
using namespace std;


/*
Scope of a Member Function
The scope of a member function lies within the scope of its class.
That is, a member function can access any other member within its class'
scope. For example, a member function can access another member
function directly:
*/

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

// Definition of display member function:
/*
The Student:: prefix on the function name identifies it as a member of
our Student type. :: is scope resolution operator.

The empty parameter list: This function does not receive any values
from the client code or return any values through the parameter list
to the client code

The const qualifier: identifies this function as a query - this function
cannot change any of the values of the object's data members

The data members: The function accesses no and grade nad ng are defined
outside the function's scope but within the class' scope,
which encompasses the function's scope. So, function access to data members.
*/
void Student::display() const {
    //cout << no << ": \n";
    displayNo(); // calls the member function  displayNo()
    for (int i = 0; i < ng; i++) {
        cout << grade[i] << endl;
    }
}

void Student::displayNo() const {
    cout << no << ": \n";
}

int main() {
    /*
    Calling a Member Function
    Client code calls a member function in the same way that an
    instance of a struct refers to one of its data members. The call
    consists of the object's identifier, followed by the . operator
    and then followed by the member function's identifier.

    For example, if harry is a Student object, we display its data
    by calling display() on harry:
    The object part of the function call (the part before the member
    selection operator) identifies the data that the function accesses.
    */
    Student harry = { 975, {78.9f, 68.4f}, 2 };
    harry.display(); // calling display member function for student harry.
    cout << endl;
    return 0;
}
