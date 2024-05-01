#include <iostream>
using namespace std;

// Template for Array Classes
// Array.h

/*
The syntax for class templates is similar to that for function 
templates.

The following template defines Array classes of specified 
size in static memory. The template parameters are the type (T) 
of each element in the array and the number of elements in 
the array (N):
*/
template<class T, int N>
class Array {
	T a[N];
public:
	T& operator[](int i) { return a[i]; }
};


/*
For the following code, the compiler generates the 
class definition for an array of element type int and 
size 5 from the Array template definition. 
*/
int main() {
	// the compiler generates the 
	// class definition for an array of element type int and
	// size 5 from the Array template definition.
	Array<int, 5> a, b;

	for (int i = 0; i < 5; i++) {
		a[i] = i * i;
	}

	b = a;

	for (int i = 0; i < 5; i++) {
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "===================================" << endl;


	// the compiler generates the 
// class definition for an array of element type float and
// size 8 from the Array template definition.
	Array<float, 8> x, y;

	for (int i = 0; i < 5; i++) {
		x[i] = i * i * 0.33f;
	}

	y = x;

	for (int i = 0; i < 5; i++) {
		std::cout << y[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
}