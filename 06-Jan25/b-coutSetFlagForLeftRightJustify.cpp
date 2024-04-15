#include <iostream>
using namespace std;

int main() {
	int val1 = 1234;

	// now we first print an asteriks and then set cout's width
	// after that we print val1. So, val1 will be printed in 30 spaces.
	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout << val1 << "*" << endl;


	// setting cout flags(cout.setf(ios::left)) to make prints left of right justified.
	// unlike width(), setting flags are permenant. That means
	// it will affect all prints after setting. Therefore, it is important
	// to unset them after we finish our job.
	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout.setf(ios::left); // set the flag of cout to make prints left-justified. This will affect all prints coming after this line until we unset the flag.
	cout << val1 << "*" << endl;

	// see val2 also printed as left-justified. Because, 
	// above we set the flag to left.
	int val2 = 25;
	cout << "*";
	cout.width(15); // setting cout so next print will be in 30 spaces.
	cout << val2 << "*" << endl;
	
	return 0;
}