#include <iostream>
using namespace std;

void foo(int a) {
	cout << a << endl;
}

int main() {
	int x{ 35 }; // initialize x with 35.
	// at line 13, when foo is called. It is called like
	// this: foo(int a = 40). That means argument of the function
	// it is a in this case is initialized(this word is important) with the value you passedto it.
	foo(40); //foo(int a = 40). Note here argument(a) is Initialized with value 40.
	foo(x); //foo(int a = x).  Note here argument(a) is Initialized with value of x.
	
	cout << x << endl;

	return 0;
}

