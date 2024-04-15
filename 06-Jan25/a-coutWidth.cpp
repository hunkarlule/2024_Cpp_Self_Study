#include <iostream>
using namespace std;

int main() {
	int val1 = 1234;
	int val2 = 56;

	cout << val1 << endl;

	cout.width(20); // setting cout so next print will be in 20 spaces.
	cout << val1 << endl; // see this one printed in 20 spaces
	cout << val2 << endl; // see this one DIDN'T printed in 20 spaces because setting width() of cout only affect first/next print after setting. 

	return 0;
}