#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstddef>

using namespace std;

/*
Subtraction
A binary expression with the subtraction operator (-) subtracts the value of rightmost operand from the value of the leftmost operand. 
If the left operand is of pointer type, the right operand must be either of integral or of the same pointer type. 
The result of subtracting an integral type from a pointer type is the address that is the number of pointed-to types before 
the address stored in the left operand. The result of subtracting a pointer type from another pointer type is 
an integer of synonym type ptrdiff_t. The integer holds the number of types between the two addresses. ptrdiff_t is 
defined in the <cstddef> header file. For example,
*/

// note: An expression that subtracts one pointer from another has a defined value if both pointers point to elements 
// of the same array or if one points to an element of the array and the other points to the location that is one element 
// beyond the end of the same array. Otherwise, the expression is ill-defined.

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int i = 2;
	int* p, * r;
    
	ptrdiff_t k;

	p = &a[4];
	r = &a[0];
	k = p - r; //subtracting two pointers. difference between the addresses.
	std::cout << std::hex;
	std::cout << *(p - i) << std::endl; // value at address i types before *p
	std::cout << (p - i) << std::endl; // value at address i types before *p
	std::cout << k <<  std::endl;

	// note: An expression that subtracts one pointer from another has a defined value if both pointers point to elements 
// of the same array or if one points to an element of the array and the other points to the location that is one element 
// beyond the end of the same array. Otherwise, the expression is ill-defined. see example below:
	int x = 34;
	int* ptr = &x;
	ptrdiff_t y;
	y = p - ptr;
	std::cout << y << std::endl;





	return 0;
}