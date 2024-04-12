#include <iostream>
using namespace std;

int main() {
	int a{234}; // initialize a with 234
	//int a = 234; // same as above.

	// int& : read as integer-reference.(note that & comes after type and it belongs to type).
	// type of r is: integer-reference
	// now r become an alias/nick-name for a. So there is only one variable.
	// r and a are same thing.
	int& r = a;

	// see both values and addresses of r and a are same.
	// this proves that they are the same variable.
	cout << a << endl;
	cout << r << endl;
	cout << &a << endl;
	cout << &r << endl;

	// see both values and addresses of r and a are same.
	// this proves that they are the same variable.
	r = 432;
	cout << a << endl;
	cout << r << endl;
	cout << &a << endl;
	cout << &r << endl;

	int b = 23;

	// note that writing this not makes r an alis of b. becuase it is alias for 
	// a and we can not change it anymore. this onyl sets value of r(a) to value of b(23).
	r = b;
	// see both values and addresses of r and a are same.
	// this proves that they are the same variable.
	cout << a << endl;
	cout << r << endl;
	cout << b << endl;

	cout << &a << endl;
	cout << &r << endl;
	cout << &b << endl;

	// because reference is only a nick-name/alies 
	// for an existing variable/object we can not create a reference
	// without initializing it.
	//int& r1; // compiler error. it says referecne r1 needs an intializer.


	return 0;
}

