
#include <iostream>
using namespace std;


/*
REFERENCES
A reference is an alias for a variable or object. 
Object-oriented languages rely on referencing. \
A reference in a function call passes the variable or object 
rather than a copy. In other words, a reference is an alternative 
to the pass by address mechanism available in the C language. 
Pass-by-reference code is notably more readable than 
pass-by-address code. To enable referencing, the C++ rules on 
function declarations are stricter than those of the C language.

The declaration of a function parameter that is received as a 
reference to the corresponding argument in the function call takes 
the form

 type identifier(type& identifier, ... )

The & identifies the parameter as an alias for,rather than a copy of, 
the corresponding argument. The identifier is the alias for 
the argument within the function definition. 
Any change to the value of a parameter received by 
reference changes the value of the corresponding argument in 
the function call.


*/

/*
Consider a function that swaps the values stored in two different 
memory locations. The programs listed below compare pass-by-address 
and pass-by-reference solutions.
Clearly, reference syntax is simpler. To pass an object by reference, 
we attach the address of operator to the parameter type. 
This operator instructs the compiler to pass by reference. 
The corresponding arguments in the function call and the object names 
within the function definition are not prefixed by the dereferencing 
operator required in passing by address.

Technically, the compiler converts each reference to a pointer with 
an unmodifiable address.
*/

// Swapping values by address
void swapUsingPointers(char* a, char* b); // function decleration

// Swapping values by reference
void swapUsingReferences(char& a, char& b);

int main() {
	
	char left1;
	char right1;

	cout << "left1 is: ";
	cin  >> left1;
	cout << "right1 is: ";
	cin >> right1;

	cout << "left1: " << left1 << ", right1: " << right1 << endl;
	swapUsingPointers(&left1, &right1);
	cout << "left1: " << left1 << ", right1: " << right1 << endl;


	/////////////////////////////////

	char left2;
	char right2;

	cout << "left2 is: ";
	cin >> left2;
	cout << "right2 is: ";
	cin >> right2;

	cout << "left2: " << left2 << ", right2: " << right2 << endl;
	swapUsingReferences(left2, right2);
	cout << "left2: " << left2 << ", right2: " << right2 << endl;


	return 0;
}


// swap1 definition
void swapUsingPointers(char* a, char* b) {
	char c;
	c = *a;
	*a = *b;
	*b = c;
}


// swap2 definition
void swapUsingReferences(char& a, char& b) {
	char c{};

	c = a;
	a = b;
	b = c;
}
