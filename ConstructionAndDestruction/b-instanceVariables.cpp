/*
Object-oriented languages encapsulate the state and logic of
a type using a class. A class describes the structure of the
data that its objects hold and the rules under which its member
functions access and change that data. The implementation of
a well-encapsulated class has all details hidden within itself.
Client code communicates with the objects of the class solely
through its public member functions.
*/

#include <iostream>
using namespace std;

/*
Instance of a Class
Each object or instance of a class occupies its own region
of memory. The data for the object is stored in that region
of memory.

A definition of an object takes the form

Type Identifier;

Type is the name of the class. Identifier is the name of

Consider the following class definition:

Instance Variables
We call the data members in the class definition the object's 
instance variables. Instance variables may be of:

Fundamental type (int, double, char, etc.)
Compound type
Class type (struct or class)
Pointer type (to instances of data types - fundamental or compound)
Reference type (to instances of data types - fundamental or compound)
*/

const int NG = 20;
class Student {
	int no;
	float grade[NG];
	int ng;
public:
	void set(int studentNo, const float* studentGrades, int numOfGrades);
	void display() const; // due to const display can not change Student object.
};

int main() {

	// To create an object of our Student class named harry, we write :
	Student harry; // harry is a instanc of Student class

	//To create five objects of our Student class, we write:
	/*
	The compiler allocates five regions in static memory,
	each of which holds the data for one of the five objects.
	Each region stores the values of three
	data members - no, the array grade and ng.
	The compiler stores the member function instructions
	separately and only once for all objects of the class.
	*/
	Student a, b, c, d, e; // all 5 of them are instances of Student class
	return 0;
}

