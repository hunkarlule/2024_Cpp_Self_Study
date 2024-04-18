
#include <iostream>
using namespace std;


/*
FUNCTION OVERLOADING
In object-oriented languages functions may have multiple meanings.
Functions with multiple meanings are called overloaded functions.
C++ refers to functions first and foremost by their identifier and
distinguishes different meanings by differing parameter lists.
For each identifier and parameter list combination, we implement a
separate function definition. C++ compilers determine the definition
to select by matching the argument types in the function call to
the parameters types in the definition.

Function Signature
A function's signature identifies an overloaded function uniquely.
Its signature consists of:

the function identifier
the parameter types (ignoring const qualifiers or address of
operators as described in references below)
the order of the parameter types
	type identifier ( type identifier [, ... , type identifier] )

The square brackets enclose optional information.
The return type and the parameter identifiers are not part of a
function's signature.

C++ compilers preserve identifier uniqueness by renaming
each overloaded function using a combination of its identifier,
its parameter types and the order of its parameter types.
We refer to this renaming as name mangling.
*/

// these are to overlaods of display functions
// C++ compilers generate two one definition of display() for 
// each set of parameters.The linker binds each function call 
// to the appropriate definition based on the argument types in 
// the function call.
void display(int x); // signature of this: display_int
void display(const int* x, int n); // signature of this: display_int*_int

int main() {
	auto x{ 20 };
	int a[] = { 10, 20, 30, 40 };

	display(x);
	display(a, 4);

	return 0;
}

// function definitions
void display(int x) {
	cout << x << endl;
}
void display(const int* x, int n) {
	for (int i{}; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

