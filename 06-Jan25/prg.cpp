#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;


// here we created a Utils object/instance ut
// to use the functions/mehtods from Utils class/struct.
// However we want Utils methods to be available to everyone that
// includes "Utils.h" without creating a Utils object!
// In order to succeed this: we need to create/declare Utils ut; instance
// in Utils.cpp file and also we need to make a prototype decleration for
// ut in Utils.h file like this(extern Utils ut;). So, eeveryone that
// includes Utils.h will know and access the ut object/instance nad then do not need to
// create a seperate Utils object. In this way, ut becomes like a cout/cin objects.
// When we include(#include <iostream>) cout and cin object becomes availbale to us and we can use them
// without creating them.
int main() {
	
	//Utils ut;
	char name[81]{};

	cout << "Enter a name\n>";
	ut.getCstr(name, 5);
	cout << "*" << name << "*" << endl;

	cout << "Enter a name\n>";
	ut.getCstr(name, 80);
	cout << "*" << name << "*" << endl;

	return 0;
}
