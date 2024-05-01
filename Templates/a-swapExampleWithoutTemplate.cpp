#include <iostream>
using namespace std;

// Consider the following function that swaps values in two 
// different memory locations. This code is defined using 
// references to two int variables:
void swap(int& a, int& b) {
	cout << "In void swap(int& a, int& b) func:" << endl;
	int c;
	c = a;
	a = b;
	b = c;
}


// Consider the following function that swaps values in two 
// different memory locations. This code is defined using 
// references to two float variables:
void swap(float& a, float& b) {
	cout << "In void swap(float& a, float& b) func:" << endl;
	float c;
	c = a;
	a = b;
	b = c;
}


int main() {
	int a = 10;
	int b = 20;
	cout << "a: " << a << " b: " << b << endl;
	swap(a, b);
	cout << "a: " << a << " b: " << b << endl;

	cout << "=================================" << endl;
	float x = 10.37;
	float y = 20.6;
	cout << "x: " << x << " y: " << y << endl;
	swap(x, y);
	cout << "x: " << x << " y: " << y << endl;


	return 0;
}