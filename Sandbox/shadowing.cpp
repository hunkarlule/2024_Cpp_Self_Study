
#include <iostream>
using namespace std;

int main() {
	/*
Shadowing
An identifier declared with an inner scope can shadow an identifier
declared with a broader scope, making the latter temporarily
inaccessible. For example, in the following program
the second declaration shadows the first declaration of i:
*/
	int i = 6; // first-i(i1)
	cout << i << endl; // i1 will be printed.

	for (int j{}; j < 3; j++) {
		// here i1 and i2 has same name(i)
		// i2 declared in inner scope so it will shadow the i1
		// in the for loop.
		int i = j * j; // second-i(i2)
		cout << i << endl; // i2 will be printed.
	} // i2 is out-of-scope after this point.

	cout << i << endl; // i1 will be printed.

	return 0;
}

