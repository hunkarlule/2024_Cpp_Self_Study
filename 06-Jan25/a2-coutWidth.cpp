#include <iostream>
using namespace std;

int main() {
	int val1 = 1234;

	// now we first print an asteriks and then set cout's width
	// after that we print val1. So, val1 will be printed in 30 spaces.
	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout << val1 << "*" << endl;


	return 0;
}