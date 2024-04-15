#include <iostream>
using namespace std;

int main() {
	int val1 = 1234;
	cout.width(30); // setting cout so next print will be in 30 spaces.

	// here we tried to print val1 in 30 spaces.
    // however, we print first '*' and it will be printed in 30
	// spaces. Be careful!.
	cout <<  "*" << val1 << "*" << endl;

	return 0;
}