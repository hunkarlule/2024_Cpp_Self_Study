#include <iostream>
using namespace std;
/*
In C:
ints:
char, short int, int, long int, long long int ==> in accending order

real numbers:
float, double, long double ==> in accending and more precise order.

In C++ , bool type also added these types.
bool takes value ==> true or false.
*/
int main() {
	// In C++, for bool type false and true values are like a mask.
	// because false  is 0 and true is 1
	// if we print a bool variable it will print 0  it is is false, and print 1 if it true.
	bool ok{}; // {} this initialize/sets ok to default value(0). And for bool zero is false so, its default is false.
	// bool ok = false; // this line is same above one. but above one is better.
	
	cout << ok << endl;

	ok = true;
	cout << ok << endl;
	return 0;
}