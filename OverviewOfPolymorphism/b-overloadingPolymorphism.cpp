#include <iostream>
using namespace std;

// Ad-Hoc Polymorphism - Overloading

/*
Overloading
Overloading addresses variations in a function's signature. 
Overloading allows binding of function calls with the same 
identifier but different argument types to function definitions 
with correspondingly different parameter types. It is a syntactic 
abbreviation that associates the same function identifier 
with a variety of function definitions by distinguishing 
the bindings based on function signature. The same function name 
can be used with a variety of unrelated argument types. 
Each set of argument types has its own function definition. 
The compiler binds the function call to the matching function 
definition.

Unlike coercion, overloading does not involve any common logic 
shared by the function definitions for functions with 
the same identifier. Uniformity is a coincidence rather 
than a rule. The definitions may contain totally unrelated logic.
Each definition works only on its set of types. The number of 
overloaded functions is limited by the number of definitions 
implemented in the source code.
*/

// Two function definitions:

void display() {
	std::cout << "No argumens"<< endl;
}

void display(int a) {
	std::cout << "One argument (" << a << ')' << endl;
}


/*
Overloading eliminates multiple function definition errors. 
C++ implements overloading at compile time by renaming each 
identically named function as a function with its own distinct
identifier: the language mangles the original identifier with 
the parameter types to generate an unique name. The linker uses 
the mangled name to bind the function call to the appropriate 
function definition.

Note that a procedural language like the C language does not 
admit overloading and requires a unique name for each function 
definition.
*/
int main() {

	display(); // no arguments will be called
	display(10); // one arguments will be called.

	return 0;
}