#include <iostream>
using namespace std;
/*
In C:
ints:
char, short int, int, long int, long long int ==> in accending order

real numbers:
float, double, long double ==> in accending and more precise order.

In C: There was no bool type.However, 0 was false and anything different from 0 is evaluated as true
In C++ , bool type also added these types.
bool takes value ==> true or false.

However in C++, still C style bool evaluation is valid. That means antyhing 0 is false, else is true.

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

	ok = false;
	if (ok) {
		cout << "this will not happen" << endl;
	}

	ok = true;
	if (ok) {
		cout << "this will happen" << endl;
	}


	// However in C++, still C style bool evaluation is valid. That means antyhing 0 is false, else is true.
	// In other words, if you put a non-zero value into a bool, it turns it to 1.
	// Actually, it is casting it. That means, it casts(234 example below) to bool and it makes it 1.
	ok = 234;
	cout << ok << endl;
	
	ok = -2345;
	cout << ok << endl;

	ok = 'A';
	cout << ok << endl;

	ok = '\0';
	cout << ok << endl;

	ok = 0;
	cout << ok << endl;

	return 0;
}