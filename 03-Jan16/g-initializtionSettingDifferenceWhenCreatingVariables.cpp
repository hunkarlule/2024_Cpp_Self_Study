#include <iostream>
using namespace std;

void foo(int a) {
	cout << a << endl;
}

int main() {
	// here first we created x without initilization.
	// at this point, when x is created there is garbage value in it.
	// with line x = 34; we set/assign x with value 34 
	int x;
	//cout << x << endl; // most compilers with gives erro for this because x is not initilazed and there is grabage value in it.
	x = 34; // after this point there is no garbage value in x.
	cout << x << endl;

	// here first we created y with initilization.
    // That means, when y is created there is value 34 in it.
    // In other words, y comes to life with value 34 put in it.
	// At no moment in time, there is no garbage value in y.
	// And also note that we have three different ways to initialize
	// variables/object at the time of creation like below.
	int y = 34;
	int t(34);
	int z{ 34 };
	cout << y << " " << t << " " << z << endl;


	return 0;
}

