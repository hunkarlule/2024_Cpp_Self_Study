
#include <iostream>
using namespace std;


/*
Encapsulation:
The primary concept of object-oriented programming is class encapsulation.
Encapsulation incorporates within a class the structure of data
that its objects store and the logic that operates on that data.
In other words, encapsulation creates a clean interface
between the class and its clients while hiding the implementation details
from its clients. The C++ language describes this logic in the form of
functions that are members of the class. The data members of a class hold
the information about the state of its objects, while the member functions
define the operations that query, modify and manage that state.
*/

/*
Member Functions
The member functions of a class provide the communication links between
client code and objects of the class. Client code calls the member
functions to access an object's data and possibly to change that data.

Every member function has direct access to the members of its class.
Each member function receives information from the client code through
its parameters and passes information to the client code through
its return value and possibly its parameters.
*/

/*
To declare a member function to a class, we insert its prototype
into the class definition.

For example, to add display() as a member to our Student type, we write:
*/

const int NG = 20;

struct Student {
    int no;          // student number
    float grade[NG]; // grades
    int ng;          // number of grades filled in grade array.

    /*
    const keyword make sure that display function will not change the
    // Student object(its dat members) that operates on.
    // In other words, const makes dipslay a query/getter.
    The const qualifier identifies the member function as a query.
    A query does not change the state of its object.
    That is, this query cannot change the value of no or any grade or ng.

    As a member function, display() has direct access to the data
    members (no and grade, ng). There is no need to pass their values as
    arguments to the function.
    */
    void display() const; // member function
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
    cout << no << ": \n";
    for (int i = 0; i < ng; i++) {
        cout << grade[i] << endl;
    }
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
    Student harry = { 975, {78.9f, 69.4f}, 2 };
    harry.display(); // calling display member function for student harry.
    cout << endl;
    return 0;
}