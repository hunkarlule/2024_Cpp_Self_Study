#include <iostream>
using namespace std;

void foo(int& a) { // here we do not get error although a an int reference because it is not created yet!.
	cout << a << endl;
	a = 12345;
}

int main() {
	int x = 34; // initialize x with 34.
	int y (34); // initialize y with 34.
	int z{ 34 }; // initialize z with 34.
	cout << x << endl;

	// when foo is called like below: This actually happens: foo(int& a = x)
	// That means, at the time of call, a is created and assigned to x. So, a become a alias for x.
	foo(x);
	// see that we changed value of a to 12345. But value of x also changed
	// because a is only an alias to x
	cout << x << endl;
	return 0;
}

