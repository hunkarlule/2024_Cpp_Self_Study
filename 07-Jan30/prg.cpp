#include <iostream>
#include "MyStr.h"

using namespace std;
using namespace seneca;

int main() {

	MyStr Empty; // no-argument constrcutor will be called to initialize Empty.
	Empty.print();

	// asssignment at the moment of creation is not an assignemnt operation.
	// it is an initialization. That means it is a call to constructor.
	// So, it is a call to  one-argument constructor.
	MyStr S = "Hello there!!!";
	
	//MyStr S{ "Hello there!!!" }; // same as above. it makes a call to one-argument constructor to initialize.
	//MyStr S("Hello there!!!"); // same as above. it makes a call to one-argument constructor to initialize.

	S.print();

	// creating T. This will cause a call to two-arguments constructor
	// to create T.
	MyStr T("Hello there!!!", 5);
	T.print();



	return 0;
}
