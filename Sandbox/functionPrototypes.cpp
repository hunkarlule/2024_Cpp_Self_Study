
#include <iostream>
using namespace std;


/*
Prototypes
A function prototype completes the function's signature by 
specifying the return type. However, the parameter identifiers are 
also optional in the prototype. The prototype provides sufficient 
information to validate a function call.

A prototype without parameter types identifies 
an empty parameter list. The keyword void, which the C language 
uses to identify no parameters is redundant in C++. 
We omit this keyword in C++.

Prototypes Required
A programming language may require a function declaration 
before any function call for type safety. The declaration may be 
either a prototype or the function definition itself. 
The compiler uses the declaration to check the argument types 
in the call against the parameter types in 
the prototype or definition. 
The type safety features of C++ require a preceding declaration.

For example, the following program will generate a compiler error
(note that the absence of any printf declaration):
To fix this error, we need to add the printf(this is a standar C funnction)
decleration before the call:
After adding this(#include <cstdio>), compiler will see the
prototype of printf before the call at line-38.
*/

#include <cstdio>  // the prototype of printf is in this header file

int main() {
	printf("Hello C++\n");

	return 0;
}


