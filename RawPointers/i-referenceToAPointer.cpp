#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstddef>

using namespace std;

/*
Reference to a Pointer
A reference to a pointer lets us change the address that has been stored in a pointer outside a function from within the function 
in the same way that a reference to a variable that holds a value. For example,
*/

// here sawp functions takes reference to pointers at is parameters.
// then inside the function it swaps the value(that is an address) saved/hold in these pointers.
void swap(int*& a, int*& b) {
	int* temp = a;
	a = b;
	b = temp;
}


int main() {
	int x, y;
	int* p = &x;
	int* q = &y;
	std::cout << "=====before swap==== " << p << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;

	swap(p, q);
	std::cout << "=====after swap==== " << p << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;


	return 0;
}