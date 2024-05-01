#include <iostream>
using namespace std;

/*
Instead of defining a different/seperate swap function
for each type, we can define a single tempate function.
So, complier will create the versions needed when compiling
our code using template for needed types.
*/

template<typename T>
//template<class T> // same as above line
void swap1(T& a, T& b) {
	cout << "In template swap1 func:" << endl;
	T c;
	c = a;
	a = b;
	b = c;
}

int main() {
	double a = 2.3;
	double b = 4.5;
	long   d = 78;
	long   e = 567;

	cout << "a: " << a << " b: " << b << endl;
	//compiler generates swap1(double, double) version using template
	// when it sees the following call during compilation
	swap1(a, b);
	cout << "a: " << a << " b: " << b << endl;

	cout << "=================================" << endl;

	cout << "d: " << d << " e: " << e << endl;

	//compiler generates swap1(long, long) version using template
	// when it sees the following call during compilation
	swap1(d, e);
	cout << "d: " << d << " e: " << e << endl;


	return 0;
}