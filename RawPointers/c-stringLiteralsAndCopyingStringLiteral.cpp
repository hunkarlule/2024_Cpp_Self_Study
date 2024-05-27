#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
String Literals
A sequence of characters surrounded by double quotes is called a string literal. A string literal is an lvalue. 
It is a primary expression stored in the segment of memory that holds global variables. 
The lifetime of this segment is the lifetime of the program. String literals have static duration.

Copying a String Literal
The following program defines a string literal, stores its address in a pointer, defines a C-style character string, 
copies the contents of the string literal into that second string, changes the first character to lower case and 
displays the updated string along with the addresses of the pointer and the string:
*/

//Note that the program does not alter the string literal itself. The memory for s is distinct from the memory for 
// the string literal "May be overwritten", which we can change.
int main() {
	const char *p = "May be overwritten";
	char s[19];
	std::strcpy(s, p);
	s[0] = 'm'; // ok
	std::cout << std::hex;
	std::cout << s << std::endl;

	// here we print the address of the strings. Note that we cast it to an int* type. 
	// Without the int* cast, the substring starting at the address would display as shown below:
	std::cout << "s = " << (int*)s << std::endl;
	std::cout << "s = " << (int*)p << std::endl;

	return 0;
}