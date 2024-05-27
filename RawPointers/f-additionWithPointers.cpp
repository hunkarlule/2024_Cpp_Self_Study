#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
Addition
A binary expression with the addition operator (+) adds the values of its operands. If one of the operands is of pointer type, 
the other must be of integral or unscoped enumeration type. The expression evaluates to the address that is the number of types 
beyond the address stored in the pointer operand. That is, the integral operand gives the offset in types (not bytes). For example,
*/


int main() {
	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int i = 2;
	double* p;
	p = &a[1];
	std::cout << std::hex;
	
	// An addition expression with a pointer operand evaluates to a defined value as long as the result of the addition points 
	// to an element of the array or to the location that is one element beyond the end of the array. 
	// Otherwise, the expression is ill-defined.

	// Note that the difference between 000000EBD98FFBC0 and 000000EBD98FFBA8 is 18 hexadecimal or 24 decimal; that is, 3 doubles.
	std::cout << a[0] << ": " << a << std::endl;
	std::cout << *(p + i) << ": " << p + i << std::endl;
	std::cout << p[i] << ": " << &p[i] << std::endl;

	return 0;
}